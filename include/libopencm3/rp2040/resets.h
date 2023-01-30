/** @defgroup resets_defines Resets Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 Subsystem Resets</b>
 *
 * @version 1.0.0
 * 
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 * 
 * @date 13 May 2021
 *
 * LGPL License Terms @ref lgpl_license
 *  */
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

#ifndef RP2040_RESETS_H
#define RP2040_RESETS_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

/* =============================================================================
 * Resets registers
 * ---------------------------------------------------------------------------*/

#define RESETS_RESET        MMIO32((RESETS_BASE) + 0x00)
#define RESETS_WDSEL        MMIO32((RESETS_BASE) + 0x04)
#define RESETS_RESET_DONE   MMIO32((RESETS_BASE) + 0x08)

/* --- RESETS_RESET values -------------------------------------------------- */

#define RESETS_RESET_MASK       (0x01ffffff)
/** @defgroup resets_reset Subsystem reset control
@ingroup resets_defines
@{*/
#define RESETS_RESET_ADC        (1 << 0)
#define RESETS_RESET_BUSCTRL    (1 << 1)
#define RESETS_RESET_DMA        (1 << 2)
#define RESETS_RESET_I2C0       (1 << 3)
#define RESETS_RESET_I2C1       (1 << 4)
#define RESETS_RESET_IO_BANK0   (1 << 5)
#define RESETS_RESET_IO_QSPI    (1 << 6)
#define RESETS_RESET_JTAG       (1 << 7)
#define RESETS_RESET_PADS_BANK0 (1 << 8)
#define RESETS_RESET_PADS_QSPI  (1 << 9)
#define RESETS_RESET_PIO0       (1 << 10)
#define RESETS_RESET_PIO1       (1 << 11)
#define RESETS_RESET_PLL_SYS    (1 << 12)
#define RESETS_RESET_PLL_USB    (1 << 13)
#define RESETS_RESET_PWM        (1 << 14)
#define RESETS_RESET_RTC        (1 << 15)
#define RESETS_RESET_SPI0       (1 << 16)
#define RESETS_RESET_SPI1       (1 << 17)
#define RESETS_RESET_SYSCFG     (1 << 18)
#define RESETS_RESET_SYSINFO    (1 << 19)
#define RESETS_RESET_TBMAN      (1 << 20)
#define RESETS_RESET_TIMER      (1 << 21)
#define RESETS_RESET_UART0      (1 << 22)
#define RESETS_RESET_UART1      (1 << 23)
#define RESETS_RESET_USBCTRL    (1 << 24)
/** @} */

/* --- RESETS_WDSEL values -------------------------------------------------- */

#define RESETS_WDSEL_MASK       (0x01ffffff)
/** @defgroup resets_wdsel Subsystem watchdog select
@ingroup resets_defines
@{*/
#define RESETS_WDSEL_ADC        (1 << 0)
#define RESETS_WDSEL_BUSCTRL    (1 << 1)
#define RESETS_WDSEL_DMA        (1 << 2)
#define RESETS_WDSEL_I2C0       (1 << 3)
#define RESETS_WDSEL_I2C1       (1 << 4)
#define RESETS_WDSEL_IO_BANK0   (1 << 5)
#define RESETS_WDSEL_IO_QSPI    (1 << 6)
#define RESETS_WDSEL_JTAG       (1 << 7)
#define RESETS_WDSEL_PADS_BANK0 (1 << 8)
#define RESETS_WDSEL_PADS_QSPI  (1 << 9)
#define RESETS_WDSEL_PIO0       (1 << 10)
#define RESETS_WDSEL_PIO1       (1 << 11)
#define RESETS_WDSEL_PLL_SYS    (1 << 12)
#define RESETS_WDSEL_PLL_USB    (1 << 13)
#define RESETS_WDSEL_PWM        (1 << 14)
#define RESETS_WDSEL_RTC        (1 << 15)
#define RESETS_WDSEL_SPI0       (1 << 16)
#define RESETS_WDSEL_SPI1       (1 << 17)
#define RESETS_WDSEL_SYSCFG     (1 << 18)
#define RESETS_WDSEL_SYSINFO    (1 << 19)
#define RESETS_WDSEL_TBMAN      (1 << 20)
#define RESETS_WDSEL_TIMER      (1 << 21)
#define RESETS_WDSEL_UART0      (1 << 22)
#define RESETS_WDSEL_UART1      (1 << 23)
#define RESETS_WDSEL_USBCTRL    (1 << 24)
/** @} */

/* --- RESETS_RESET_DONE values --------------------------------------------- */

#define RESETS_RESET_DONE_MASK          (0x01ffffff)
/** @defgroup resets_reset_done Subsystem reset done
@ingroup resets_defines
@{*/
#define RESETS_RESET_DONE_ADC           (1 << 0)
#define RESETS_RESET_DONE_BUSCTRL       (1 << 1)
#define RESETS_RESET_DONE_DMA           (1 << 2)
#define RESETS_RESET_DONE_I2C0          (1 << 3)
#define RESETS_RESET_DONE_I2C1          (1 << 4)
#define RESETS_RESET_DONE_IO_BANK0      (1 << 5)
#define RESETS_RESET_DONE_IO_QSPI       (1 << 6)
#define RESETS_RESET_DONE_JTAG          (1 << 7)
#define RESETS_RESET_DONE_PADS_BANK0    (1 << 8)
#define RESETS_RESET_DONE_PADS_QSPI     (1 << 9)
#define RESETS_RESET_DONE_PIO0          (1 << 10)
#define RESETS_RESET_DONE_PIO1          (1 << 11)
#define RESETS_RESET_DONE_PLL_SYS       (1 << 12)
#define RESETS_RESET_DONE_PLL_USB       (1 << 13)
#define RESETS_RESET_DONE_PWM           (1 << 14)
#define RESETS_RESET_DONE_RTC           (1 << 15)
#define RESETS_RESET_DONE_SPI0          (1 << 16)
#define RESETS_RESET_DONE_SPI1          (1 << 17)
#define RESETS_RESET_DONE_SYSCFG        (1 << 18)
#define RESETS_RESET_DONE_SYSINFO       (1 << 19)
#define RESETS_RESET_DONE_TBMAN         (1 << 20)
#define RESETS_RESET_DONE_TIMER         (1 << 21)
#define RESETS_RESET_DONE_UART0         (1 << 22)
#define RESETS_RESET_DONE_UART1         (1 << 23)
#define RESETS_RESET_DONE_USBCTRL       (1 << 24)
/** @} */

/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void reset_block(uint32_t bits);
void unreset_block(uint32_t bits);
void unreset_block_wait(uint32_t bits);

/** @} */
END_DECLS

#endif

/**@}*/

