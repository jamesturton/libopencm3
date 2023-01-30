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

#include <string.h>
#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/resets.h>
#include <libopencm3/usb/usbd.h>
#include <libopencm3/usb/dwc/otg_fs.h>
#include "usb_private.h"
#include "usb_dwc_common.h"

/* Receive FIFO size in 32-bit words. */
#define RX_FIFO_SIZE 128

static usbd_device *rp2040_usbd_init(void);

static struct _usbd_device usbd_dev;

const struct _usbd_driver rp2040_usb_driver = {
	.init = rp2040_usbd_init,
	.set_address = dwc_set_address,
	.ep_setup = dwc_ep_setup,
	.ep_reset = dwc_endpoints_reset,
	.ep_stall_set = dwc_ep_stall_set,
	.ep_stall_get = dwc_ep_stall_get,
	.ep_nak_set = dwc_ep_nak_set,
	.ep_write_packet = dwc_ep_write_packet,
	.ep_read_packet = dwc_ep_read_packet,
	.poll = dwc_poll,
	.disconnect = dwc_disconnect,
	.base_address = USB_OTG_FS_BASE,
	.set_address_before_status = 1,
	.rx_fifo_size = RX_FIFO_SIZE,
};

/** Initialize the USB device controller hardware of the RP2040. */
static usbd_device *rp2040_usbd_init(void)
{
    // Reset usb controller
    reset_block(RESETS_RESET_USBCTRL);
    unreset_block_wait(RESETS_RESET_USBCTRL);

    // Clear any previous state in dpram just in case
    memset(usb_dpram, 0, sizeof(*usb_dpram)); // <1>

    // Enable USB interrupt at processor
    irq_set_enabled(USBCTRL_IRQ, true);

    // Mux the controller to the onboard usb phy
    USB_USB_MUXING = USB_USB_MUXING_TO_PHY | USB_USB_MUXING_SOFTCON;

    // Force VBUS detect so the device thinks it is plugged into a host
    USB_USB_PWR = USB_USB_PWR_VBUS_DETECT | USB_USB_PWR_VBUS_DETECT_OVERRIDE_EN;

    // Enable the USB controller in device mode.
    USB_MAIN_CTRL = USB_MAIN_CTRL_CONTROLLER_EN;

    // Enable an interrupt per EP0 transaction
    USB_SIE_CTRL = USB_SIE_CTRL_EP0_INT_1BUF;

    // Enable interrupts for when a buffer is done, when the bus is reset,
    // and when a setup packet is received
    USB_INTE = USB_INT_BUFF_STATUS |
               USB_INT_BUS_RESET |
               USB_INT_SETUP_REQ;

    // Set up endpoints (endpoint control registers)
    // described by device configuration
    usb_setup_endpoints();

    // Present full speed device by enabling pull up on DP
    USB_SIE_CTRL = USB_SIE_CTRL_PULLUP_EN;















	rcc_periph_clock_enable(RCC_OTGFS);
	OTG_FS_GUSBCFG |= OTG_GUSBCFG_PHYSEL;

	/* Wait for AHB idle. */
	while (!(OTG_FS_GRSTCTL & OTG_GRSTCTL_AHBIDL));
	/* Do core soft reset. */
	OTG_FS_GRSTCTL |= OTG_GRSTCTL_CSRST;
	while (OTG_FS_GRSTCTL & OTG_GRSTCTL_CSRST);

	if (OTG_FS_CID >= OTG_CID_HAS_VBDEN) {
		/* Enable VBUS detection in device mode and power up the PHY. */
		OTG_FS_GCCFG |= OTG_GCCFG_VBDEN | OTG_GCCFG_PWRDWN;
	} else {
		/* Enable VBUS sensing in device mode and power up the PHY. */
		OTG_FS_GCCFG |= OTG_GCCFG_VBUSBSEN | OTG_GCCFG_PWRDWN;
	}
	/* Explicitly enable DP pullup (not all cores do this by default) */
	OTG_FS_DCTL &= ~OTG_DCTL_SDIS;

	/* Force peripheral only mode. */
	OTG_FS_GUSBCFG |= OTG_GUSBCFG_FDMOD | OTG_GUSBCFG_TRDT_MASK;

	OTG_FS_GINTSTS = OTG_GINTSTS_MMIS;

	/* Full speed device. */
	OTG_FS_DCFG |= OTG_DCFG_DSPD;

	/* Restart the PHY clock. */
	OTG_FS_PCGCCTL = 0;

	OTG_FS_GRXFSIZ = rp2040_usb_driver.rx_fifo_size;
	usbd_dev.fifo_mem_top = rp2040_usb_driver.rx_fifo_size;

	/* Unmask interrupts for TX and RX. */
	OTG_FS_GAHBCFG |= OTG_GAHBCFG_GINT;
	OTG_FS_GINTMSK = OTG_GINTMSK_ENUMDNEM |
			 OTG_GINTMSK_RXFLVLM |
			 OTG_GINTMSK_IEPINT |
			 OTG_GINTMSK_USBSUSPM |
			 OTG_GINTMSK_WUIM;
	OTG_FS_DAINTMSK = 0xF;
	OTG_FS_DIEPMSK = OTG_DIEPMSK_XFRCM;

	return &usbd_dev;
}
