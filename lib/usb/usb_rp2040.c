/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2021 James Turton <james.turton@gmx.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @defgroup usb_file USB
 *
 * @ingroup RP2040
 *
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 *
 * \brief <b>libopencm3 RP2040 Universal Serial Bus controller </b>
 *
 * The RP2040 USB driver is integrated with the libopencm3 USB stack. You should
 * use the generic stack.
 *
 * To use this driver, tell the linker to look for it:
 * @code{.c}
 *	extern usbd_driver rp2040_usb_driver;
 * @endcode
 *
 * And pass this driver as an argument when initializing the USB stack:
 * @code{.c}
 * usbd_device *usbd_dev;
 * usbd_dev = usbd_init(&rp2040_usb_driver, ...);
 * @endcode
 *
 * <b>Polling or interrupt-driven? </b>
 *
 * The RP2040 USB driver will work fine regardless of whether it is called from an
 * interrupt service routine, or from the main program loop.
 *
 * Polling USB from the main loop requires calling @ref usbd_poll() from the
 * main program loop.
 * For example:
 * @code{.c}
 *	// Main program loop
 *	while(1) {
 *		usbd_poll(usb_dev);
 *		do_other_stuff();
 *		...
 * @endcode
 *
 * Running @ref usbd_poll() from an interrupt has the advantage that it is only
 * called when needed, saving CPU cycles for the main program.
 *
 * RESET, DISCON, RESUME, and SUSPEND interrupts must be enabled, along with the
 * interrupts for any endpoint that is used. The EP0_TX interrupt must be
 * enabled for the control endpoint to function correctly.
 * For example, if EP1IN and EP2OUT are used, then the EP0_TX, EP1_TX, and
 * EP2_RX interrupts should be enabled:
 * @code{.c}
 *	// Enable USB interrupts for EP0, EP1IN, and EP2OUT
 *	ints = USB_INT_RESET | USB_INT_DISCON | USB_INT_RESUME |
 *		 USB_INT_SUSPEND;
 *	usb_enable_interrupts(ints, USB_EP2_INT, USB_EP0_INT | USB_EP1_INT);
 *	// Route the interrupts through the NVIC
 *	nvic_enable_irq(NVIC_USB0_IRQ);
 * @endcode
 *
 * The USB ISR only has to call @ref usbd_poll().
 *
 * @code{.c}
 *	void usb0_isr(void)
 *	{
 *		usbd_poll(usb_dev);
 *	}
 * @endcode
 * @{
 */

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/resets.h>
#include <libopencm3/rp2040/usb.h>
#include <libopencm3/usb/usbd.h>
#include "../../lib/usb/usb_private.h"

#include <stdbool.h>
#include <string.h>

const struct _usbd_driver rp2040_usb_driver;

typedef struct
{
	int					in_pid;
	volatile uint8_t *	in_buf;
	int					out_pid;
	volatile uint8_t *	out_buf;
	uint8_t *			out_data;
} usb_ep_t;

static usb_ep_t usb_ep[USB_DPRAM_EP_NUM];

/**
 * @cond private
 */
static inline void rp2040_usb_soft_disconnect(void)
{
	USB_SIE_CTRL &= ~USB_SIE_CTRL_PULLUP_EN;
}

static inline void rp2040_usb_soft_connect(void)
{
	USB_SIE_CTRL |= USB_SIE_CTRL_PULLUP_EN;
}

static void rp2040_set_address(usbd_device *usbd_dev, uint8_t addr)
{
	(void)usbd_dev;

	USB_ADDR_ENDP(0) = USB_ADDR_ENDP_ADDRESS(addr) & USB_ADDR_ENDP_ADDRESS_MASK;
}

static void rp2040_ep_setup(usbd_device *usbd_dev, uint8_t addr, uint8_t type,
			  uint16_t max_size,
			  void (*callback) (usbd_device *usbd_dev, uint8_t ep))
{
	const bool dir_tx = addr & 0x80;
	const uint8_t ep = addr & 0x7f;

	/*
	 * We do not mess with the maximum packet size, but we can only allocate
	 * the FIFO in power-of-two increments.
	 */
	uint16_t fifo_size;
	if (max_size > 1024)
		fifo_size = 2048;
	else if (max_size > 512)
		fifo_size = 1024;
	else if (max_size > 256)
		fifo_size = 512;
	else if (max_size > 128)
		fifo_size = 256;
	else if (max_size > 64)
		fifo_size = 128;
	else if (max_size > 32)
		fifo_size = 64;
	else if (max_size > 16)
		fifo_size = 32;
	else if (max_size > 8)
		fifo_size = 16;
	else
		fifo_size = 8;

	/* Are we out of FIFO space? */
	if (usbd_dev->fifo_mem_top + fifo_size > USB_DPRAM_SIZE)
		return;

	if (dir_tx) {
		if (callback)
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_IN] = (void *)callback;

		usb_ep[ep].in_buf = (volatile uint8_t *)(USBCTRL_DPRAM_BASE + usbd_dev->fifo_mem_top);

		USB_DPRAM_EP_IN_CTRL(ep) = USB_DPRAM_EP_CTRL_ENABLE |
			USB_DPRAM_EP_CTRL_INTERRUPT_PER_BUFF |
			USB_DPRAM_EP_CTRL_ENDPOINT_TYPE(type) |
			USB_DPRAM_EP_CTRL_BUFFER_ADDRESS(usbd_dev->fifo_mem_top);
	} else {
		if (callback)
			usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_OUT] = (void *)callback;

		usb_ep[ep].out_buf = (volatile uint8_t *)(USBCTRL_DPRAM_BASE + usbd_dev->fifo_mem_top);

		USB_DPRAM_EP_OUT_CTRL(ep) = USB_DPRAM_EP_CTRL_ENABLE |
			USB_DPRAM_EP_CTRL_INTERRUPT_PER_BUFF |
			USB_DPRAM_EP_CTRL_ENDPOINT_TYPE(type) |
			USB_DPRAM_EP_CTRL_BUFFER_ADDRESS(usbd_dev->fifo_mem_top);
	}

	usbd_dev->fifo_mem_top += fifo_size;
}

static void rp2040_endpoints_reset(usbd_device *usbd_dev)
{
	// Don't reset ep0
	for (int i = 1; i < USB_DPRAM_EP_NUM; i++)
	{
		USB_DPRAM_EP_IN_CTRL(i)  = 0;
		USB_DPRAM_EP_OUT_CTRL(i)  = 0;
	}

	memset(&usb_ep, 0, sizeof(usb_ep));

	usbd_dev->fifo_mem_top = USB_DPRAM_BUFFER_OFFSET;
}

static void rp2040_ep_stall_set(usbd_device *usbd_dev, uint8_t addr,
			      uint8_t stall)
{
	(void)usbd_dev;

	const uint8_t ep = addr & 0x0f;
	const bool dir_tx = addr & 0x80;

	if (dir_tx) {
		if (stall) {
			if (ep == 0)
				USB_EP_STALL_ARM = USB_EP_STALL_ARM_EP0_IN;
			USB_DPRAM_EP_IN_BUFF_CTRL(ep) |= USB_DPRAM_EP_BUFF_CTRL_STALL;
		} else {
			USB_DPRAM_EP_IN_BUFF_CTRL(ep) &= ~USB_DPRAM_EP_BUFF_CTRL_STALL;
		}
	} else {
		if (stall) {
			if (ep == 0)
				USB_EP_STALL_ARM = USB_EP_STALL_ARM_EP0_OUT;
			USB_DPRAM_EP_OUT_BUFF_CTRL(ep) |= USB_DPRAM_EP_BUFF_CTRL_STALL;
		} else {
			USB_DPRAM_EP_OUT_BUFF_CTRL(ep) &= ~USB_DPRAM_EP_BUFF_CTRL_STALL;
		}
	}
}

static uint8_t rp2040_ep_stall_get(usbd_device *usbd_dev, uint8_t addr)
{
	(void)usbd_dev;

	const uint8_t ep = addr & 0x0f;
	const bool dir_tx = addr & 0x80;

	if (dir_tx) {
		usb_ep[ep].in_pid = 0;
		return (USB_DPRAM_EP_IN_BUFF_CTRL(ep) & USB_DPRAM_EP_BUFF_CTRL_STALL) ? 1 : 0;
	} else {
		usb_ep[ep].out_pid = 0;
		return (USB_DPRAM_EP_OUT_BUFF_CTRL(ep) & USB_DPRAM_EP_BUFF_CTRL_STALL) ? 1 : 0;
	}
}

static void rp2040_ep_nak_set(usbd_device *usbd_dev, uint8_t addr, uint8_t nak)
{
	(void)usbd_dev;
	(void)addr;
	(void)nak;

	/* NAK's are handled automatically by hardware. Move along. */
}

static uint16_t rp2040_ep_write_packet(usbd_device *usbd_dev, uint8_t addr,
			      const void *buf, uint16_t len)
{
	(void)usbd_dev;
	const uint8_t ep = addr & 0xf;
	uint16_t i;

	for (i = 0; i < len; i++)
		usb_ep[ep].in_buf[i] = *((uint8_t *)(buf + i));

	uint32_t v = len | USB_DPRAM_EP_BUFF_CTRL_FULL_0 |
		(usb_ep[ep].in_pid ? USB_DPRAM_EP_BUFF_CTRL_PID_0 : 0);
	usb_ep[ep].in_pid ^= 1;

	USB_DPRAM_EP_IN_BUFF_CTRL(ep) = v;
	__asm__("nop");
	__asm__("nop");
	__asm__("nop");
	__asm__("nop");
	USB_DPRAM_EP_IN_BUFF_CTRL(ep) = v | USB_DPRAM_EP_BUFF_CTRL_AVAILABLE_0;

	return i;
}

static uint16_t rp2040_ep_read_packet(usbd_device *usbd_dev, uint8_t addr,
				    void *buf, uint16_t len)
{
	(void)usbd_dev;
	const uint8_t ep = addr & 0xf;

	usb_ep[ep].out_data = (uint8_t *)(buf);

	uint32_t v = len | (usb_ep[ep].out_pid ? USB_DPRAM_EP_BUFF_CTRL_PID_0 : 0);
	usb_ep[ep].out_pid ^= 1;

	USB_DPRAM_EP_OUT_BUFF_CTRL(ep) = v;
	__asm__("nop");
	__asm__("nop");
	__asm__("nop");
	__asm__("nop");
	USB_DPRAM_EP_OUT_BUFF_CTRL(ep) = v | USB_DPRAM_EP_BUFF_CTRL_AVAILABLE_0;

	return len;
}

static void rp2040_poll(usbd_device *usbd_dev)
{
	void (*tx_cb)(usbd_device *usbd_dev, uint8_t ea);
	void (*rx_cb)(usbd_device *usbd_dev, uint8_t ea);

	/*
	 * The initial state of these registers might change, as we process the
	 * interrupt, but we need the initial state in order to decide how to
	 * handle events.
	 */
	const uint32_t status = USB_INTS;

	if ((status & USB_INT_DEV_SUSPEND) && (usbd_dev->user_callback_suspend)) {
		USB_SIE_STATUS &= ~USB_INT_DEV_SUSPEND;

		usbd_dev->user_callback_suspend();
	}

	if ((status & USB_INT_DEV_RESUME_FROM_HOST) && (usbd_dev->user_callback_resume)) {
		USB_SIE_STATUS &= ~USB_INT_DEV_RESUME_FROM_HOST;

		usbd_dev->user_callback_resume();
	}

	if (status & USB_INT_SETUP_REQ)
	{
		USB_SIE_STATUS &= ~USB_INT_SETUP_REQ;

		usb_ep[0].in_pid  = 1;
		usb_ep[0].out_pid = 1;

		rp2040_ep_read_packet(usbd_dev, 0, &usbd_dev->control_state.req, 8);
		if (usbd_dev->user_callback_ctr[0][USB_TRANSACTION_SETUP])
			usbd_dev->user_callback_ctr[0][USB_TRANSACTION_SETUP](usbd_dev, 0);
	}

	if (status & USB_INT_BUS_RESET) {
		USB_SIE_STATUS &= ~USB_SIE_STATUS_BUS_RESET;

		_usbd_reset(usbd_dev);

		usb_ep[0].in_buf = &USB_DPRAM_EP0_BUFF;
		usb_ep[0].out_buf = &USB_DPRAM_EP0_BUFF;
	}

	if ((status & USB_INT_DEV_SOF) && (usbd_dev->user_callback_sof)) {
		USB_SIE_STATUS &= ~USB_INT_DEV_SOF;

		usbd_dev->user_callback_sof();
	}

	if (status & USB_INT_BUFF_STATUS)
	{
		const uint32_t buff_status = USB_BUFF_STATUS;

		uint32_t flags = buff_status;

		for (int ep = 1; ep < USB_DPRAM_EP_NUM && flags > 0; ep++) {
			tx_cb = usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_IN];
			rx_cb = usbd_dev->user_callback_ctr[ep][USB_TRANSACTION_OUT];

			if ((flags & 1) && tx_cb) // IN
				tx_cb(usbd_dev, ep);

			if (flags & 2) { // OUT
				int size = USB_DPRAM_EP_OUT_BUFF_CTRL(ep) & USB_DPRAM_EP_BUFF_CTRL_LENGTH_0_MASK;

				for (int i = 0; i < size; i++)
					usb_ep[ep].out_data[i] = usb_ep[ep].out_buf[i];

				if (rx_cb)
					rx_cb(usbd_dev, ep);
			}

			flags >>= 2;
		}

		// Write back to registers to clear
		USB_BUFF_STATUS = buff_status;
	}
}

static void rp2040_disconnect(usbd_device *usbd_dev, bool disconnected)
{
	(void)usbd_dev;

	if (disconnected)
		rp2040_usb_soft_disconnect();
	else
		rp2040_usb_soft_connect();
}

/*
 * A static struct works as long as we have only one USB peripheral. If we
 * meet RP2040s with more than one USB, then we need to rework this approach.
 */
static struct _usbd_device usbd_dev;

/** Initialize the USB device controller hardware of the RP2040. */
static usbd_device *rp2040_usbd_init(void)
{
	// Should we be clearing dpram??
	memset((void *)USBCTRL_DPRAM_BASE, 0, USB_DPRAM_SIZE);

    // Mux the controller to the onboard usb phy
    USB_USB_MUXING = USB_USB_MUXING_TO_PHY | USB_USB_MUXING_SOFTCON;

    // Force VBUS detect so the device thinks it is plugged into a host
    USB_USB_PWR = USB_USB_PWR_VBUS_DETECT | USB_USB_PWR_VBUS_DETECT_OVERRIDE_EN;

    // Initializes the USB peripheral for device mode and enables it.
    // Don't need to enable the pull up here. Force VBUS
    USB_MAIN_CTRL = USB_MAIN_CTRL_CONTROLLER_EN;

    // Enable individual controller IRQS here. Processor interrupt enable will be used
    // for the global interrupt enable...
    USB_SIE_CTRL = USB_SIE_CTRL_EP0_INT_1BUF; 
    USB_INTE = USB_INT_BUFF_STATUS | USB_INT_BUS_RESET | USB_INT_SETUP_REQ;

	// Clear endpoint address
	rp2040_set_address(&usbd_dev, 0);

	rp2040_endpoints_reset(&usbd_dev);

	rp2040_usb_soft_connect();

	return &usbd_dev;
}

/* What is this thing even good for */
#define RX_FIFO_SIZE 512

const struct _usbd_driver rp2040_usb_driver = {
	.init = rp2040_usbd_init,
	.set_address = rp2040_set_address,
	.ep_setup = rp2040_ep_setup,
	.ep_reset = rp2040_endpoints_reset,
	.ep_stall_set = rp2040_ep_stall_set,
	.ep_stall_get = rp2040_ep_stall_get,
	.ep_nak_set = rp2040_ep_nak_set,
	.ep_write_packet = rp2040_ep_write_packet,
	.ep_read_packet = rp2040_ep_read_packet,
	.poll = rp2040_poll,
	.disconnect = rp2040_disconnect,
	.base_address = USBCTRL_REGS_BASE,
	.set_address_before_status = false,
	.rx_fifo_size = RX_FIFO_SIZE,
};

/**
 * @endcond
 */

/**
 * @}
 */
