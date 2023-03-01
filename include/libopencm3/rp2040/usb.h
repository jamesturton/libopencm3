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

/** @defgroup usb_defines USB Controller
 *
 * @brief <b>Defined Constants and Types for the RP2040 USB Controller</b>
 *
 * @ingroup RP2040_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly James Turton <james.turton@gmx.com>
 *
 * @date 16 May 2021
 *
 * LGPL License Terms @ref lgpl_license
 */


#ifndef LIBOPENCM3_RP2040_USB_H
#define LIBOPENCM3_RP2040_USB_H

/**@{*/

#include <libopencm3/rp2040/memorymap.h>
#include <libopencm3/cm3/common.h>

/* ============================================================================
 * USB DPRAM registers
 * --------------------------------------------------------------------------*/

#define USB_DPRAM_SIZE                  0x1000
#define USB_DPRAM_EP_NUM                16
#define USB_DPRAM_EP0_BUF_SIZE          0x40
#define USB_DPRAM_BUFFER_OFFSET         0x180
#define USB_DPRAM_BUFFER_SIZE           (USB_DPRAM_SIZE - USB_DPRAM_BUFFER_OFFSET)

#define USB_DPRAM_SETUP                 MMIO8((USBCTRL_DPRAM_BASE) + 0x00)
#define USB_DPRAM_EP_IN_CTRL(ep)        MMIO32((USBCTRL_DPRAM_BASE) + 0x00 + (0x04 * (ep)))
#define USB_DPRAM_EP_OUT_CTRL(ep)       MMIO32((USBCTRL_DPRAM_BASE) + 0x04 + (0x04 * (ep)))
#define USB_DPRAM_EP_IN_BUFF_CTRL(ep)   MMIO32((USBCTRL_DPRAM_BASE) + 0x80 + (0x04 * (ep)))
#define USB_DPRAM_EP_OUT_BUFF_CTRL(ep)  MMIO32((USBCTRL_DPRAM_BASE) + 0x84 + (0x04 * (ep)))
#define USB_DPRAM_EP0_BUFF              MMIO8((USBCTRL_DPRAM_BASE) + 0x100)
#define USB_DPRAM_EP0_BUFF_OPT          MMIO8((USBCTRL_DPRAM_BASE) + 0x140)
#define USB_DPRAM_BUFFER                MMIO8((USBCTRL_DPRAM_BASE) + USB_DPRAM_BUFFER_OFFSET)

/* --- USB_DPRAM_EP_CTRL values --------------------------------------------- */

#define USB_DPRAM_EP_CTRL_ENABLE                    (0x1 << 31)

#define USB_DPRAM_EP_CTRL_DOUBLE_BUFFERED           (0x1 << 30)

#define USB_DPRAM_EP_CTRL_INTERRUPT_PER_BUFF        (0x1 << 29)

#define USB_DPRAM_EP_CTRL_INTERRUPT_PER_DOUBLE_BUFF (0x1 << 28)

#define USB_DPRAM_EP_CTRL_ENDPOINT_TYPE(type)       ((type) << 26)
#define USB_DPRAM_EP_CTRL_ENDPOINT_TYPE_MASK        (0x3 << 26)
#define USB_DPRAM_EP_CTRL_ENDPOINT_TYPE_CONTROL     (0x0)
#define USB_DPRAM_EP_CTRL_ENDPOINT_TYPE_ISO         (0x1)
#define USB_DPRAM_EP_CTRL_ENDPOINT_TYPE_BULK        (0x2)
#define USB_DPRAM_EP_CTRL_ENDPOINT_TYPE_INTERRUPT   (0x3)

#define USB_DPRAM_EP_CTRL_INTERRUPT_ON_STALL        (0x1 << 17)

#define USB_DPRAM_EP_CTRL_INTERRUPT_ON_NAK          (0x1 << 16)

#define USB_DPRAM_EP_CTRL_BUFFER_ADDRESS(addr)      ((addr) << 0)
#define USB_DPRAM_EP_CTRL_BUFFER_ADDRESS_MASK       (0xffff << 0)

/* --- USB_DPRAM_EP_x_BUFF_CTRL values -------------------------------------- */

#define USB_DPRAM_EP_BUFF_CTRL_FULL_1                           (0x1 << 31)

#define USB_DPRAM_EP_BUFF_CTRL_LAST_1                           (0x1 << 30)

#define USB_DPRAM_EP_BUFF_CTRL_PID_1                            (0x1 << 29)

#define USB_DPRAM_EP_BUFF_CTRL_DOUBLE_BUFFER_ISO(mode)          ((mode) << 27)
#define USB_DPRAM_EP_BUFF_CTRL_DOUBLE_BUFFER_ISO_MASK           (0x3 << 27)
#define USB_DPRAM_EP_BUFF_CTRL_DOUBLE_BUFFER_ISO_128            (0x0)
#define USB_DPRAM_EP_BUFF_CTRL_DOUBLE_BUFFER_ISO_256            (0x1)
#define USB_DPRAM_EP_BUFF_CTRL_DOUBLE_BUFFER_ISO_512            (0x2)
#define USB_DPRAM_EP_BUFF_CTRL_DOUBLE_BUFFER_ISO_1024           (0x3)

#define USB_DPRAM_EP_BUFF_CTRL_AVAILABLE_1                      (0x1 << 26)

#define USB_DPRAM_EP_BUFF_CTRL_LENGTH_1(len)                    ((len) << 16)
#define USB_DPRAM_EP_BUFF_CTRL_LENGTH_1_MASK                    (0x3ff << 16)

#define USB_DPRAM_EP_BUFF_CTRL_FULL_0                           (0x1 << 15)

#define USB_DPRAM_EP_BUFF_CTRL_LAST_0                           (0x1 << 14)

#define USB_DPRAM_EP_BUFF_CTRL_PID_0                            (0x1 << 13)

#define USB_DPRAM_EP_BUFF_CTRL_RESET                            (0x1 << 12)

#define USB_DPRAM_EP_BUFF_CTRL_STALL                            (0x1 << 11)

#define USB_DPRAM_EP_BUFF_CTRL_AVAILABLE_0                      (0x1 << 10)

#define USB_DPRAM_EP_BUFF_CTRL_LENGTH_0(len)                    ((len) << 0)
#define USB_DPRAM_EP_BUFF_CTRL_LENGTH_0_MASK                    (0x3ff << 0)


/* ============================================================================
 * USB registers
 * --------------------------------------------------------------------------*/

#define USB_ADDR_ENDP(ep)           MMIO32((USBCTRL_REGS_BASE) + (0x04 * (ep)))
#define USB_MAIN_CTRL               MMIO32((USBCTRL_REGS_BASE) + 0x40)
#define USB_SOF_WR                  MMIO32((USBCTRL_REGS_BASE) + 0x44)
#define USB_SOF_RD                  MMIO32((USBCTRL_REGS_BASE) + 0x48)
#define USB_SIE_CTRL                MMIO32((USBCTRL_REGS_BASE) + 0x4c)
#define USB_SIE_STATUS              MMIO32((USBCTRL_REGS_BASE) + 0x50)
#define USB_INT_EP_CTRL             MMIO32((USBCTRL_REGS_BASE) + 0x54)
#define USB_BUFF_STATUS             MMIO32((USBCTRL_REGS_BASE) + 0x58)
#define USB_BUFF_CPU_SHOULD_HANDLE  MMIO32((USBCTRL_REGS_BASE) + 0x5c)
#define USB_EP_ABORT                MMIO32((USBCTRL_REGS_BASE) + 0x60)
#define USB_EP_ABORT_DONE           MMIO32((USBCTRL_REGS_BASE) + 0x64)
#define USB_EP_STALL_ARM            MMIO32((USBCTRL_REGS_BASE) + 0x68)
#define USB_NAK_POLL                MMIO32((USBCTRL_REGS_BASE) + 0x6c)
#define USB_EP_STATUS_STALL_NAK     MMIO32((USBCTRL_REGS_BASE) + 0x70)
#define USB_USB_MUXING              MMIO32((USBCTRL_REGS_BASE) + 0x74)
#define USB_USB_PWR                 MMIO32((USBCTRL_REGS_BASE) + 0x78)
#define USB_USBPHY_DIRECT           MMIO32((USBCTRL_REGS_BASE) + 0x7c)
#define USB_USBPHY_DIRECT_OVERRIDE  MMIO32((USBCTRL_REGS_BASE) + 0x80)
#define USB_USBPHY_TRIM             MMIO32((USBCTRL_REGS_BASE) + 0x84)
#define USB_INTR                    MMIO32((USBCTRL_REGS_BASE) + 0x8c)
#define USB_INTE                    MMIO32((USBCTRL_REGS_BASE) + 0x90)
#define USB_INTF                    MMIO32((USBCTRL_REGS_BASE) + 0x94)
#define USB_INTS                    MMIO32((USBCTRL_REGS_BASE) + 0x98)

/* --- USB_ADDR_ENDPx values ------------------------------------------------ */

#define USB_ADDR_ENDP_ADDRESS(addr)                 ((addr) << 0)
#define USB_ADDR_ENDP_ADDRESS_MASK                  (0x7f << 0)

#define USB_ADDR_ENDP_ENDPOINT(ep)                  ((ep) << 16)
#define USB_ADDR_ENDP_ENDPOINT_MASK                 (0xf << 16)

#define USB_ADDR_ENDP_INTEP_DIR                     (0x1 << 25)

#define USB_ADDR_ENDP_INTEP_PREAMBLE                (0x1 << 26)

/* --- USB_MAIN_CTRL values ------------------------------------------------- */

#define USB_MAIN_CTRL_CONTROLLER_EN                 (0x1 << 0)

#define USB_MAIN_CTRL_HOST_NDEVICE                  (0x1 << 1)

#define USB_MAIN_CTRL_SIM_TIMING                    (0x1 << 31)

/* --- USB_SOF_WR values ---------------------------------------------------- */

#define USB_SOF_WR_COUNT(num)                       ((num) << 0)
#define USB_SOF_WR_COUNT_MASK                       (0x7ff << 0)

/* --- USB_SOF_RD values ---------------------------------------------------- */

#define USB_SOF_RD_COUNT(num)                       ((num) << 0)
#define USB_SOF_RD_COUNT_MASK                       (0x7ff << 0)

/* --- USB_SIE_CTRL values -------------------------------------------------- */

#define USB_SIE_CTRL_START_TRANS                    (0x1 << 0)

#define USB_SIE_CTRL_SEND_SETUP                     (0x1 << 1)

#define USB_SIE_CTRL_SEND_DATA                      (0x1 << 2)

#define USB_SIE_CTRL_RECEIVE_DATA                   (0x1 << 3)

#define USB_SIE_CTRL_STOP_TRANS                     (0x1 << 4)

#define USB_SIE_CTRL_PREAMBLE_EN                    (0x1 << 6)

#define USB_SIE_CTRL_SOF_SYNC                       (0x1 << 8)

#define USB_SIE_CTRL_SOF_EN                         (0x1 << 9)

#define USB_SIE_CTRL_KEEP_ALIVE_EN                  (0x1 << 10)

#define USB_SIE_CTRL_VBUS_EN                        (0x1 << 11)

#define USB_SIE_CTRL_RESUME                         (0x1 << 12)

#define USB_SIE_CTRL_RESET_BUS                      (0x1 << 13)

#define USB_SIE_CTRL_PULLDOWN_EN                    (0x1 << 15)

#define USB_SIE_CTRL_PULLUP_EN                      (0x1 << 16)

#define USB_SIE_CTRL_RPU_OPT                        (0x1 << 17)

#define USB_SIE_CTRL_TRANSCEIVER_PD                 (0x1 << 18)

#define USB_SIE_CTRL_DIRECT_DM                      (0x1 << 24)

#define USB_SIE_CTRL_DIRECT_DP                      (0x1 << 25)

#define USB_SIE_CTRL_DIRECT_EN                      (0x1 << 26)

#define USB_SIE_CTRL_EP0_INT_NAK                    (0x1 << 27)

#define USB_SIE_CTRL_EP0_INT_2BUF                   (0x1 << 28)

#define USB_SIE_CTRL_EP0_INT_1BUF                   (0x1 << 29)

#define USB_SIE_CTRL_EP0_DOUBLE_BUF                 (0x1 << 30)

#define USB_SIE_CTRL_EP0_INT_STALL                  (0x1 << 31)

/* --- USB_SIE_STATUS values ------------------------------------------------ */

#define USB_SIE_STATUS_VBUS_DETECTED                (0x1 << 0)

#define USB_SIE_STATUS_LINE_STATE(state)            ((state) << 2)
#define USB_SIE_STATUS_LINE_STATE_MASK              (0x3 << 2)

#define USB_SIE_STATUS_SUSPENDED                    (0x1 << 4)

#define USB_SIE_STATUS_SPEED(speed)                 ((speed) << 8)
#define USB_SIE_STATUS_SPEED_MASK                   (0x3 << 8)
#define USB_SIE_STATUS_SPEED_DISCONNECTED           (0x0)
#define USB_SIE_STATUS_SPEED_LS                     (0x1)
#define USB_SIE_STATUS_SPEED_HS                     (0x2)

#define USB_SIE_STATUS_VBUS_OVER_CURR               (0x1 << 10)

#define USB_SIE_STATUS_RESUME                       (0x1 << 11)

#define USB_SIE_STATUS_CONNECTED                    (0x1 << 16)

#define USB_SIE_STATUS_SETUP_REC                    (0x1 << 17)

#define USB_SIE_STATUS_TRANS_COMPLETE               (0x1 << 18)

#define USB_SIE_STATUS_BUS_RESET                    (0x1 << 19)

#define USB_SIE_STATUS_CRC_ERROR                    (0x1 << 24)

#define USB_SIE_STATUS_BIT_STUFF_ERROR              (0x1 << 25)

#define USB_SIE_STATUS_RX_OVERFLOW                  (0x1 << 26)

#define USB_SIE_STATUS_RX_TIMEOUT                   (0x1 << 27)

#define USB_SIE_STATUS_NAK_REC                      (0x1 << 28)

#define USB_SIE_STATUS_STALL_REC                    (0x1 << 29)

#define USB_SIE_STATUS_ACK_REC                      (0x1 << 30)

#define USB_SIE_STATUS_DATA_SEQ_ERROR               (0x1 << 31)

/* --- USB_INT_EP_CTRL values ----------------------------------------------- */

#define USB_INT_EP_CTRL_INT_EP_ACTIVE(ep)           ((ep) << 1)
#define USB_INT_EP_CTRL_INT_EP_ACTIVE_MASK          (0x7fff << 1)

/* --- USB_BUFF_STATUS values ----------------------------------------------- */

#define USB_BUFF_STATUS_EP0_IN                      (0x1 << 0)
#define USB_BUFF_STATUS_EP0_OUT                     (0x1 << 1)
#define USB_BUFF_STATUS_EP1_IN                      (0x1 << 2)
#define USB_BUFF_STATUS_EP1_OUT                     (0x1 << 3)
#define USB_BUFF_STATUS_EP2_IN                      (0x1 << 4)
#define USB_BUFF_STATUS_EP2_OUT                     (0x1 << 5)
#define USB_BUFF_STATUS_EP3_IN                      (0x1 << 6)
#define USB_BUFF_STATUS_EP3_OUT                     (0x1 << 7)
#define USB_BUFF_STATUS_EP4_IN                      (0x1 << 8)
#define USB_BUFF_STATUS_EP4_OUT                     (0x1 << 9)
#define USB_BUFF_STATUS_EP5_IN                      (0x1 << 10)
#define USB_BUFF_STATUS_EP5_OUT                     (0x1 << 11)
#define USB_BUFF_STATUS_EP6_IN                      (0x1 << 12)
#define USB_BUFF_STATUS_EP6_OUT                     (0x1 << 13)
#define USB_BUFF_STATUS_EP7_IN                      (0x1 << 14)
#define USB_BUFF_STATUS_EP7_OUT                     (0x1 << 15)
#define USB_BUFF_STATUS_EP8_IN                      (0x1 << 16)
#define USB_BUFF_STATUS_EP8_OUT                     (0x1 << 17)
#define USB_BUFF_STATUS_EP9_IN                      (0x1 << 18)
#define USB_BUFF_STATUS_EP9_OUT                     (0x1 << 19)
#define USB_BUFF_STATUS_EP10_IN                     (0x1 << 20)
#define USB_BUFF_STATUS_EP10_OUT                    (0x1 << 21)
#define USB_BUFF_STATUS_EP11_IN                     (0x1 << 22)
#define USB_BUFF_STATUS_EP11_OUT                    (0x1 << 23)
#define USB_BUFF_STATUS_EP12_IN                     (0x1 << 24)
#define USB_BUFF_STATUS_EP12_OUT                    (0x1 << 25)
#define USB_BUFF_STATUS_EP13_IN                     (0x1 << 26)
#define USB_BUFF_STATUS_EP13_OUT                    (0x1 << 27)
#define USB_BUFF_STATUS_EP14_IN                     (0x1 << 28)
#define USB_BUFF_STATUS_EP14_OUT                    (0x1 << 29)
#define USB_BUFF_STATUS_EP15_IN                     (0x1 << 30)
#define USB_BUFF_STATUS_EP15_OUT                    (0x1 << 31)

/* --- USB_BUFF_CPU_SHOULD_HANDLE values ------------------------------------ */

#define USB_BUFF_CPU_SHOULD_HANDLE_EP0_IN           (0x1 << 0)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP0_OUT          (0x1 << 1)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP1_IN           (0x1 << 2)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP1_OUT          (0x1 << 3)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP2_IN           (0x1 << 4)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP2_OUT          (0x1 << 5)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP3_IN           (0x1 << 6)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP3_OUT          (0x1 << 7)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP4_IN           (0x1 << 8)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP4_OUT          (0x1 << 9)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP5_IN           (0x1 << 10)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP5_OUT          (0x1 << 11)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP6_IN           (0x1 << 12)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP6_OUT          (0x1 << 13)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP7_IN           (0x1 << 14)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP7_OUT          (0x1 << 15)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP8_IN           (0x1 << 16)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP8_OUT          (0x1 << 17)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP9_IN           (0x1 << 18)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP9_OUT          (0x1 << 19)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP10_IN          (0x1 << 20)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP10_OUT         (0x1 << 21)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP11_IN          (0x1 << 22)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP11_OUT         (0x1 << 23)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP12_IN          (0x1 << 24)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP12_OUT         (0x1 << 25)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP13_IN          (0x1 << 26)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP13_OUT         (0x1 << 27)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP14_IN          (0x1 << 28)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP14_OUT         (0x1 << 29)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP15_IN          (0x1 << 30)
#define USB_BUFF_CPU_SHOULD_HANDLE_EP15_OUT         (0x1 << 31)

/* --- USB_BUFF_ABORT values ------------------------------------------------ */

#define USB_BUFF_ABORT_EP0_IN                       (0x1 << 0)
#define USB_BUFF_ABORT_EP0_OUT                      (0x1 << 1)
#define USB_BUFF_ABORT_EP1_IN                       (0x1 << 2)
#define USB_BUFF_ABORT_EP1_OUT                      (0x1 << 3)
#define USB_BUFF_ABORT_EP2_IN                       (0x1 << 4)
#define USB_BUFF_ABORT_EP2_OUT                      (0x1 << 5)
#define USB_BUFF_ABORT_EP3_IN                       (0x1 << 6)
#define USB_BUFF_ABORT_EP3_OUT                      (0x1 << 7)
#define USB_BUFF_ABORT_EP4_IN                       (0x1 << 8)
#define USB_BUFF_ABORT_EP4_OUT                      (0x1 << 9)
#define USB_BUFF_ABORT_EP5_IN                       (0x1 << 10)
#define USB_BUFF_ABORT_EP5_OUT                      (0x1 << 11)
#define USB_BUFF_ABORT_EP6_IN                       (0x1 << 12)
#define USB_BUFF_ABORT_EP6_OUT                      (0x1 << 13)
#define USB_BUFF_ABORT_EP7_IN                       (0x1 << 14)
#define USB_BUFF_ABORT_EP7_OUT                      (0x1 << 15)
#define USB_BUFF_ABORT_EP8_IN                       (0x1 << 16)
#define USB_BUFF_ABORT_EP8_OUT                      (0x1 << 17)
#define USB_BUFF_ABORT_EP9_IN                       (0x1 << 18)
#define USB_BUFF_ABORT_EP9_OUT                      (0x1 << 19)
#define USB_BUFF_ABORT_EP10_IN                      (0x1 << 20)
#define USB_BUFF_ABORT_EP10_OUT                     (0x1 << 21)
#define USB_BUFF_ABORT_EP11_IN                      (0x1 << 22)
#define USB_BUFF_ABORT_EP11_OUT                     (0x1 << 23)
#define USB_BUFF_ABORT_EP12_IN                      (0x1 << 24)
#define USB_BUFF_ABORT_EP12_OUT                     (0x1 << 25)
#define USB_BUFF_ABORT_EP13_IN                      (0x1 << 26)
#define USB_BUFF_ABORT_EP13_OUT                     (0x1 << 27)
#define USB_BUFF_ABORT_EP14_IN                      (0x1 << 28)
#define USB_BUFF_ABORT_EP14_OUT                     (0x1 << 29)
#define USB_BUFF_ABORT_EP15_IN                      (0x1 << 30)
#define USB_BUFF_ABORT_EP15_OUT                     (0x1 << 31)

/* --- USB_BUFF_ABORT_DONE values ------------------------------------------- */

#define USB_BUFF_ABORT_DONE_EP0_IN                  (0x1 << 0)
#define USB_BUFF_ABORT_DONE_EP0_OUT                 (0x1 << 1)
#define USB_BUFF_ABORT_DONE_EP1_IN                  (0x1 << 2)
#define USB_BUFF_ABORT_DONE_EP1_OUT                 (0x1 << 3)
#define USB_BUFF_ABORT_DONE_EP2_IN                  (0x1 << 4)
#define USB_BUFF_ABORT_DONE_EP2_OUT                 (0x1 << 5)
#define USB_BUFF_ABORT_DONE_EP3_IN                  (0x1 << 6)
#define USB_BUFF_ABORT_DONE_EP3_OUT                 (0x1 << 7)
#define USB_BUFF_ABORT_DONE_EP4_IN                  (0x1 << 8)
#define USB_BUFF_ABORT_DONE_EP4_OUT                 (0x1 << 9)
#define USB_BUFF_ABORT_DONE_EP5_IN                  (0x1 << 10)
#define USB_BUFF_ABORT_DONE_EP5_OUT                 (0x1 << 11)
#define USB_BUFF_ABORT_DONE_EP6_IN                  (0x1 << 12)
#define USB_BUFF_ABORT_DONE_EP6_OUT                 (0x1 << 13)
#define USB_BUFF_ABORT_DONE_EP7_IN                  (0x1 << 14)
#define USB_BUFF_ABORT_DONE_EP7_OUT                 (0x1 << 15)
#define USB_BUFF_ABORT_DONE_EP8_IN                  (0x1 << 16)
#define USB_BUFF_ABORT_DONE_EP8_OUT                 (0x1 << 17)
#define USB_BUFF_ABORT_DONE_EP9_IN                  (0x1 << 18)
#define USB_BUFF_ABORT_DONE_EP9_OUT                 (0x1 << 19)
#define USB_BUFF_ABORT_DONE_EP10_IN                 (0x1 << 20)
#define USB_BUFF_ABORT_DONE_EP10_OUT                (0x1 << 21)
#define USB_BUFF_ABORT_DONE_EP11_IN                 (0x1 << 22)
#define USB_BUFF_ABORT_DONE_EP11_OUT                (0x1 << 23)
#define USB_BUFF_ABORT_DONE_EP12_IN                 (0x1 << 24)
#define USB_BUFF_ABORT_DONE_EP12_OUT                (0x1 << 25)
#define USB_BUFF_ABORT_DONE_EP13_IN                 (0x1 << 26)
#define USB_BUFF_ABORT_DONE_EP13_OUT                (0x1 << 27)
#define USB_BUFF_ABORT_DONE_EP14_IN                 (0x1 << 28)
#define USB_BUFF_ABORT_DONE_EP14_OUT                (0x1 << 29)
#define USB_BUFF_ABORT_DONE_EP15_IN                 (0x1 << 30)
#define USB_BUFF_ABORT_DONE_EP15_OUT                (0x1 << 31)

/* --- USB_EP_STALL_ARM values ---------------------------------------------- */

#define USB_EP_STALL_ARM_EP0_IN                     (0x1 << 0)
#define USB_EP_STALL_ARM_EP0_OUT                    (0x1 << 1)

/* --- USB_NAK_POLL values -------------------------------------------------- */

#define USB_NAK_POLL_DELAY_LS(us)                   ((us) << 0)
#define USB_NAK_POLL_DELAY_LS_MASK                  (0x3ff << 0)

#define USB_NAK_POLL_DELAY_FS(us)                   ((us) << 16)
#define USB_NAK_POLL_DELAY_FS_MASK                  (0x3ff << 16)

/* --- USB_EP_STATUS_STALL_NAK values --------------------------------------- */

#define USB_EP_STATUS_STALL_NAK_EP0_IN              (0x1 << 0)
#define USB_EP_STATUS_STALL_NAK_EP0_OUT             (0x1 << 1)
#define USB_EP_STATUS_STALL_NAK_EP1_IN              (0x1 << 2)
#define USB_EP_STATUS_STALL_NAK_EP1_OUT             (0x1 << 3)
#define USB_EP_STATUS_STALL_NAK_EP2_IN              (0x1 << 4)
#define USB_EP_STATUS_STALL_NAK_EP2_OUT             (0x1 << 5)
#define USB_EP_STATUS_STALL_NAK_EP3_IN              (0x1 << 6)
#define USB_EP_STATUS_STALL_NAK_EP3_OUT             (0x1 << 7)
#define USB_EP_STATUS_STALL_NAK_EP4_IN              (0x1 << 8)
#define USB_EP_STATUS_STALL_NAK_EP4_OUT             (0x1 << 9)
#define USB_EP_STATUS_STALL_NAK_EP5_IN              (0x1 << 10)
#define USB_EP_STATUS_STALL_NAK_EP5_OUT             (0x1 << 11)
#define USB_EP_STATUS_STALL_NAK_EP6_IN              (0x1 << 12)
#define USB_EP_STATUS_STALL_NAK_EP6_OUT             (0x1 << 13)
#define USB_EP_STATUS_STALL_NAK_EP7_IN              (0x1 << 14)
#define USB_EP_STATUS_STALL_NAK_EP7_OUT             (0x1 << 15)
#define USB_EP_STATUS_STALL_NAK_EP8_IN              (0x1 << 16)
#define USB_EP_STATUS_STALL_NAK_EP8_OUT             (0x1 << 17)
#define USB_EP_STATUS_STALL_NAK_EP9_IN              (0x1 << 18)
#define USB_EP_STATUS_STALL_NAK_EP9_OUT             (0x1 << 19)
#define USB_EP_STATUS_STALL_NAK_EP10_IN             (0x1 << 20)
#define USB_EP_STATUS_STALL_NAK_EP10_OUT            (0x1 << 21)
#define USB_EP_STATUS_STALL_NAK_EP11_IN             (0x1 << 22)
#define USB_EP_STATUS_STALL_NAK_EP11_OUT            (0x1 << 23)
#define USB_EP_STATUS_STALL_NAK_EP12_IN             (0x1 << 24)
#define USB_EP_STATUS_STALL_NAK_EP12_OUT            (0x1 << 25)
#define USB_EP_STATUS_STALL_NAK_EP13_IN             (0x1 << 26)
#define USB_EP_STATUS_STALL_NAK_EP13_OUT            (0x1 << 27)
#define USB_EP_STATUS_STALL_NAK_EP14_IN             (0x1 << 28)
#define USB_EP_STATUS_STALL_NAK_EP14_OUT            (0x1 << 29)
#define USB_EP_STATUS_STALL_NAK_EP15_IN             (0x1 << 30)
#define USB_EP_STATUS_STALL_NAK_EP15_OUT            (0x1 << 31)

/* --- USB_USB_MUXING values ------------------------------------------------ */

#define USB_USB_MUXING_TO_PHY                       (0x1 << 0)

#define USB_USB_MUXING_TO_EXTPHY                    (0x1 << 1)

#define USB_USB_MUXING_TO_DIGITAL_PAD               (0x1 << 2)

#define USB_USB_MUXING_SOFTCON                      (0x1 << 3)

/* --- USB_USB_PWR values --------------------------------------------------- */

#define USB_USB_PWR_VBUS_EN                         (0x1 << 0)

#define USB_USB_PWR_VBUS_EN_OVERRIDE_EN             (0x1 << 1)

#define USB_USB_PWR_VBUS_DETECT                     (0x1 << 2)

#define USB_USB_PWR_VBUS_DETECT_OVERRIDE_EN         (0x1 << 3)

#define USB_USB_PWR_OVERCURR_DETECT                 (0x1 << 4)

#define USB_USB_PWR_OVERCURR_DETECT_EN              (0x1 << 5)

/* --- USB_USBPHY_DIRECT values --------------------------------------------- */

#define USB_USBPHY_DIRECT_DP_PULLUP_HISEL           (0x1 << 0)

#define USB_USBPHY_DIRECT_DP_PULLUP_EN              (0x1 << 1)

#define USB_USBPHY_DIRECT_DP_PULLDN_EN              (0x1 << 2)

#define USB_USBPHY_DIRECT_DM_PULLUP_HISEL           (0x1 << 4)

#define USB_USBPHY_DIRECT_DM_PULLUP_EN              (0x1 << 5)

#define USB_USBPHY_DIRECT_DM_PULLDN_EN              (0x1 << 6)

#define USB_USBPHY_DIRECT_TX_DP_OE                  (0x1 << 8)

#define USB_USBPHY_DIRECT_TX_DM_OE                  (0x1 << 9)

#define USB_USBPHY_DIRECT_TX_DP                     (0x1 << 10)

#define USB_USBPHY_DIRECT_TX_DM                     (0x1 << 11)

#define USB_USBPHY_DIRECT_RX_PD                     (0x1 << 12)

#define USB_USBPHY_DIRECT_TX_PD                     (0x1 << 13)

#define USB_USBPHY_DIRECT_TX_FSSLEW                 (0x1 << 14)

#define USB_USBPHY_DIRECT_TX_DIFFMODE               (0x1 << 15)

#define USB_USBPHY_DIRECT_RX_DD                     (0x1 << 16)

#define USB_USBPHY_DIRECT_RX_DP                     (0x1 << 17)

#define USB_USBPHY_DIRECT_RX_DM                     (0x1 << 18)

#define USB_USBPHY_DIRECT_DP_OVCN                   (0x1 << 19)

#define USB_USBPHY_DIRECT_DM_OVCN                   (0x1 << 20)

#define USB_USBPHY_DIRECT_DP_OVV                    (0x1 << 21)

#define USB_USBPHY_DIRECT_DM_OVV                    (0x1 << 22)

/* --- USB_USBPHY_DIRECT_OVERRIDE values ------------------------------------ */

#define USB_USBPHY_DIRECT_OVERRIDE_DP_PULLUP_HISEL  (0x1 << 0)

#define USB_USBPHY_DIRECT_OVERRIDE_DM_PULLUP_HISEL  (0x1 << 1)

#define USB_USBPHY_DIRECT_OVERRIDE_DP_PULLUP_EN     (0x1 << 2)

#define USB_USBPHY_DIRECT_OVERRIDE_DP_PULLDN_EN     (0x1 << 3)

#define USB_USBPHY_DIRECT_OVERRIDE_DM_PULLDN_EN     (0x1 << 4)

#define USB_USBPHY_DIRECT_OVERRIDE_TX_DP_OE         (0x1 << 5)

#define USB_USBPHY_DIRECT_OVERRIDE_TX_DM_OE         (0x1 << 6)

#define USB_USBPHY_DIRECT_OVERRIDE_TX_DP            (0x1 << 7)

#define USB_USBPHY_DIRECT_OVERRIDE_TX_DM            (0x1 << 8)

#define USB_USBPHY_DIRECT_OVERRIDE_RX_PD            (0x1 << 9)

#define USB_USBPHY_DIRECT_OVERRIDE_TX_PD            (0x1 << 10)

#define USB_USBPHY_DIRECT_OVERRIDE_TX_FSSLEW        (0x1 << 11)

#define USB_USBPHY_DIRECT_OVERRIDE_DM_PULLUP        (0x1 << 12)

#define USB_USBPHY_DIRECT_OVERRIDE_TX_DIFFMODE      (0x1 << 15)

/* --- USB_USBPHY_TRIM values ----------------------------------------------- */

#define USB_USBPHY_TRIM_DP_PULLDN_TRIM(trim)        ((trim) << 0)
#define USB_USBPHY_TRIM_DP_PULLDN_TRIM_MASK         (0x1f << 0)

#define USB_USBPHY_TRIM_DM_PULLDN_TRIM(trim)        ((trim) << 8)
#define USB_USBPHY_TRIM_DM_PULLDN_TRIM_MASK         (0x1f << 8)

/* --- USB_INTx values ------------------------------------------------------ */

#define USB_INT_HOST_CONN_DIS                       (0x1 << 0)

#define USB_INT_HOST_RESUME                         (0x1 << 1)

#define USB_INT_HOST_SOF                            (0x1 << 2)

#define USB_INT_TRANS_COMPLETE                      (0x1 << 3)

#define USB_INT_BUFF_STATUS                         (0x1 << 4)

#define USB_INT_ERROR_DATA_SEQ                      (0x1 << 5)

#define USB_INT_ERROR_RX_TIMEOUT                    (0x1 << 6)

#define USB_INT_ERROR_RX_OVERFLOW                   (0x1 << 7)

#define USB_INT_ERROR_BIT_STUFF                     (0x1 << 8)

#define USB_INT_ERROR_CRC                           (0x1 << 9)

#define USB_INT_STALL                               (0x1 << 10)

#define USB_INT_VBUS_DETECT                         (0x1 << 11)

#define USB_INT_BUS_RESET                           (0x1 << 12)

#define USB_INT_DEV_CONN_DIS                        (0x1 << 13)

#define USB_INT_DEV_SUSPEND                         (0x1 << 14)

#define USB_INT_DEV_RESUME_FROM_HOST                (0x1 << 15)

#define USB_INT_SETUP_REQ                           (0x1 << 16)

#define USB_INT_DEV_SOF                             (0x1 << 17)

#define USB_INT_ABORT_DONE                          (0x1 << 18)

#define USB_INT_EP_STALL_NAK                        (0x1 << 19)

/**@}*/

#endif
