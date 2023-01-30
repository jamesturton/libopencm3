/** @defgroup io_defines I/O Bank 0 Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 I/O Bank 0</b>
 *
 * @version 1.0.0
 * 
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 * 
 * @date 6 May 2021
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

#ifndef RP2040_IO_H
#define RP2040_IO_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

/* =============================================================================
 * IO registers
 * ---------------------------------------------------------------------------*/

#define IO_GPIO_STATUS(pin)     MMIO32((IO_BANK0_BASE) + (pin * 0x008))
#define IO_GPIO_CTRL(pin)       MMIO32((IO_BANK0_BASE) + (pin * 0x008) + 0x004)

#define IO_GPIO0_STATUS         IO_GPIO_STATUS(0)
#define IO_GPIO0_CTRL           IO_GPIO_CTRL(0)
#define IO_GPIO1_STATUS         IO_GPIO_STATUS(1)
#define IO_GPIO1_CTRL           IO_GPIO_CTRL(1)
#define IO_GPIO2_STATUS         IO_GPIO_STATUS(2)
#define IO_GPIO2_CTRL           IO_GPIO_CTRL(2)
#define IO_GPIO3_STATUS         IO_GPIO_STATUS(3)
#define IO_GPIO3_CTRL           IO_GPIO_CTRL(3)
#define IO_GPIO4_STATUS         IO_GPIO_STATUS(4)
#define IO_GPIO4_CTRL           IO_GPIO_CTRL(4)
#define IO_GPIO5_STATUS         IO_GPIO_STATUS(5)
#define IO_GPIO5_CTRL           IO_GPIO_CTRL(5)
#define IO_GPIO6_STATUS         IO_GPIO_STATUS(6)
#define IO_GPIO6_CTRL           IO_GPIO_CTRL(6)
#define IO_GPIO7_STATUS         IO_GPIO_STATUS(7)
#define IO_GPIO7_CTRL           IO_GPIO_CTRL(7)
#define IO_GPIO8_STATUS         IO_GPIO_STATUS(8)
#define IO_GPIO8_CTRL           IO_GPIO_CTRL(8)
#define IO_GPIO9_STATUS         IO_GPIO_STATUS(9)
#define IO_GPIO9_CTRL           IO_GPIO_CTRL(9)
#define IO_GPIO10_STATUS        IO_GPIO_STATUS(10)
#define IO_GPIO10_CTRL          IO_GPIO_CTRL(10)
#define IO_GPIO11_STATUS        IO_GPIO_STATUS(11)
#define IO_GPIO11_CTRL          IO_GPIO_CTRL(11)
#define IO_GPIO12_STATUS        IO_GPIO_STATUS(12)
#define IO_GPIO12_CTRL          IO_GPIO_CTRL(12)
#define IO_GPIO13_STATUS        IO_GPIO_STATUS(13)
#define IO_GPIO13_CTRL          IO_GPIO_CTRL(13)
#define IO_GPIO14_STATUS        IO_GPIO_STATUS(14)
#define IO_GPIO14_CTRL          IO_GPIO_CTRL(14)
#define IO_GPIO15_STATUS        IO_GPIO_STATUS(15)
#define IO_GPIO15_CTRL          IO_GPIO_CTRL(15)
#define IO_GPIO16_STATUS        IO_GPIO_STATUS(16)
#define IO_GPIO16_CTRL          IO_GPIO_CTRL(16)
#define IO_GPIO17_STATUS        IO_GPIO_STATUS(17)
#define IO_GPIO17_CTRL          IO_GPIO_CTRL(17)
#define IO_GPIO18_STATUS        IO_GPIO_STATUS(18)
#define IO_GPIO18_CTRL          IO_GPIO_CTRL(18)
#define IO_GPIO19_STATUS        IO_GPIO_STATUS(19)
#define IO_GPIO19_CTRL          IO_GPIO_CTRL(19)
#define IO_GPIO20_STATUS        IO_GPIO_STATUS(20)
#define IO_GPIO20_CTRL          IO_GPIO_CTRL(20)
#define IO_GPIO21_STATUS        IO_GPIO_STATUS(21)
#define IO_GPIO21_CTRL          IO_GPIO_CTRL(21)
#define IO_GPIO22_STATUS        IO_GPIO_STATUS(22)
#define IO_GPIO22_CTRL          IO_GPIO_CTRL(22)
#define IO_GPIO23_STATUS        IO_GPIO_STATUS(23)
#define IO_GPIO23_CTRL          IO_GPIO_CTRL(23)
#define IO_GPIO24_STATUS        IO_GPIO_STATUS(24)
#define IO_GPIO24_CTRL          IO_GPIO_CTRL(24)
#define IO_GPIO25_STATUS        IO_GPIO_STATUS(25)
#define IO_GPIO25_CTRL          IO_GPIO_CTRL(25)
#define IO_GPIO26_STATUS        IO_GPIO_STATUS(26)
#define IO_GPIO26_CTRL          IO_GPIO_CTRL(26)
#define IO_GPIO27_STATUS        IO_GPIO_STATUS(27)
#define IO_GPIO27_CTRL          IO_GPIO_CTRL(27)
#define IO_GPIO28_STATUS        IO_GPIO_STATUS(28)
#define IO_GPIO28_CTRL          IO_GPIO_CTRL(28)
#define IO_GPIO29_STATUS        IO_GPIO_STATUS(29)
#define IO_GPIO29_CTRL          IO_GPIO_CTRL(29)
#define IO_INTR0                MMIO32((IO_BANK0_BASE) + 0x0f0)
#define IO_INTR1                MMIO32((IO_BANK0_BASE) + 0x0f4)
#define IO_INTR2                MMIO32((IO_BANK0_BASE) + 0x0f8)
#define IO_INTR3                MMIO32((IO_BANK0_BASE) + 0x0fc)
#define IO_PROC0_INTE0          MMIO32((IO_BANK0_BASE) + 0x100)
#define IO_PROC0_INTE1          MMIO32((IO_BANK0_BASE) + 0x104)
#define IO_PROC0_INTE2          MMIO32((IO_BANK0_BASE) + 0x108)
#define IO_PROC0_INTE3          MMIO32((IO_BANK0_BASE) + 0x10c)
#define IO_PROC0_INTF0          MMIO32((IO_BANK0_BASE) + 0x110)
#define IO_PROC0_INTF1          MMIO32((IO_BANK0_BASE) + 0x114)
#define IO_PROC0_INTF2          MMIO32((IO_BANK0_BASE) + 0x118)
#define IO_PROC0_INTF3          MMIO32((IO_BANK0_BASE) + 0x11c)
#define IO_PROC0_INTS0          MMIO32((IO_BANK0_BASE) + 0x120)
#define IO_PROC0_INTS1          MMIO32((IO_BANK0_BASE) + 0x124)
#define IO_PROC0_INTS2          MMIO32((IO_BANK0_BASE) + 0x128)
#define IO_PROC0_INTS3          MMIO32((IO_BANK0_BASE) + 0x12c)
#define IO_PROC1_INTE0          MMIO32((IO_BANK0_BASE) + 0x130)
#define IO_PROC1_INTE1          MMIO32((IO_BANK0_BASE) + 0x134)
#define IO_PROC1_INTE2          MMIO32((IO_BANK0_BASE) + 0x138)
#define IO_PROC1_INTE3          MMIO32((IO_BANK0_BASE) + 0x13c)
#define IO_PROC1_INTF0          MMIO32((IO_BANK0_BASE) + 0x140)
#define IO_PROC1_INTF1          MMIO32((IO_BANK0_BASE) + 0x144)
#define IO_PROC1_INTF2          MMIO32((IO_BANK0_BASE) + 0x148)
#define IO_PROC1_INTF3          MMIO32((IO_BANK0_BASE) + 0x14c)
#define IO_PROC1_INTS0          MMIO32((IO_BANK0_BASE) + 0x150)
#define IO_PROC1_INTS1          MMIO32((IO_BANK0_BASE) + 0x154)
#define IO_PROC1_INTS2          MMIO32((IO_BANK0_BASE) + 0x158)
#define IO_PROC1_INTS3          MMIO32((IO_BANK0_BASE) + 0x15c)
#define IO_DORMANT_WAKE_INTE0   MMIO32((IO_BANK0_BASE) + 0x160)
#define IO_DORMANT_WAKE_INTE1   MMIO32((IO_BANK0_BASE) + 0x164)
#define IO_DORMANT_WAKE_INTE2   MMIO32((IO_BANK0_BASE) + 0x168)
#define IO_DORMANT_WAKE_INTE3   MMIO32((IO_BANK0_BASE) + 0x16c)
#define IO_DORMANT_WAKE_INTF0   MMIO32((IO_BANK0_BASE) + 0x170)
#define IO_DORMANT_WAKE_INTF1   MMIO32((IO_BANK0_BASE) + 0x174)
#define IO_DORMANT_WAKE_INTF2   MMIO32((IO_BANK0_BASE) + 0x178)
#define IO_DORMANT_WAKE_INTF3   MMIO32((IO_BANK0_BASE) + 0x17c)
#define IO_DORMANT_WAKE_INTS0   MMIO32((IO_BANK0_BASE) + 0x180)
#define IO_DORMANT_WAKE_INTS1   MMIO32((IO_BANK0_BASE) + 0x184)
#define IO_DORMANT_WAKE_INTS2   MMIO32((IO_BANK0_BASE) + 0x188)
#define IO_DORMANT_WAKE_INTS3   MMIO32((IO_BANK0_BASE) + 0x18c)

/* --- IO_GPIOx_STATUS values ----------------------------------------------- */

#define IO_GPIO_STATUS_OUTFROMPERI  (0x1 << 8)
#define IO_GPIO_STATUS_OUTTOPAD     (0x1 << 9)
#define IO_GPIO_STATUS_OEFROMPERI   (0x1 << 12)
#define IO_GPIO_STATUS_OETOPAD      (0x1 << 13)
#define IO_GPIO_STATUS_INFROMPAD    (0x1 << 17)
#define IO_GPIO_STATUS_INTOPERI     (0x1 << 19)
#define IO_GPIO_STATUS_IRQFROMPAD   (0x1 << 24)
#define IO_GPIO_STATUS_IRQTOPROC    (0x1 << 26)

/* --- IO_GPIOx_CTRL_FUNCSEL values ----------------------------------------- */

#define IO_GPIO_CTRL_FUNCSEL(func)  (func)
#define IO_GPIO_CTRL_FUNCSEL_MASK   (0x1f)
/** @defgroup io_gpio_ctrl_funcsel Function select
@ingroup io_defines
@{*/
#define IO_GPIO_CTRL_FUNCSEL_XIP    (0x0)
#define IO_GPIO_CTRL_FUNCSEL_SPI    (0x1)
#define IO_GPIO_CTRL_FUNCSEL_UART   (0x2)
#define IO_GPIO_CTRL_FUNCSEL_I2C    (0x3)
#define IO_GPIO_CTRL_FUNCSEL_PWM    (0x4)
#define IO_GPIO_CTRL_FUNCSEL_SIO    (0x5)
#define IO_GPIO_CTRL_FUNCSEL_PIO0   (0x6)
#define IO_GPIO_CTRL_FUNCSEL_PIO1   (0x7)
#define IO_GPIO_CTRL_FUNCSEL_GPCK   (0x8)
#define IO_GPIO_CTRL_FUNCSEL_USB    (0x9)
#define IO_GPIO_CTRL_FUNCSEL_NULL   (0xf)
/**@}*/

/* --- IO_GPIOx_CTRL_OUTOVER values ----------------------------------------- */

#define IO_GPIO_CTRL_OUTOVER(over)  ((over) << 8)
#define IO_GPIO_CTRL_OUTOVER_MASK   (0x3 << 8)
/** @defgroup io_gpio_ctrl_outover Output override
@ingroup io_defines
@{*/
#define IO_GPIO_CTRL_OUTOVER_NORMAL (0x0)
#define IO_GPIO_CTRL_OUTOVER_INVERT (0x1)
#define IO_GPIO_CTRL_OUTOVER_LOW    (0x2)
#define IO_GPIO_CTRL_OUTOVER_HIGH   (0x3)
/**@}*/

/* --- IO_GPIOx_CTRL_OEOVER values ------------------------------------------ */

#define IO_GPIO_CTRL_OEOVER(over)   ((over) << 12)
#define IO_GPIO_CTRL_OEOVER_MASK    (0x3 << 12)
/** @defgroup io_gpio_ctrl_oeover Output enable override
@ingroup io_defines
@{*/
#define IO_GPIO_CTRL_OEOVER_NORMAL  (0x0)
#define IO_GPIO_CTRL_OEOVER_INVERT  (0x1)
#define IO_GPIO_CTRL_OEOVER_DISABLE (0x2)
#define IO_GPIO_CTRL_OEOVER_ENABLE  (0x3)
/**@}*/

/* --- IO_GPIOx_CTRL_INOVER values ------------------------------------------ */

#define IO_GPIO_CTRL_INOVER(over)   ((over) << 16)
#define IO_GPIO_CTRL_INOVER_MASK    (0x3 << 16)
/** @defgroup io_gpio_ctrl_inover Input override
@ingroup io_defines
@{*/
#define IO_GPIO_CTRL_INOVER_NORMAL  (0x0)
#define IO_GPIO_CTRL_INOVER_INVERT  (0x1)
#define IO_GPIO_CTRL_INOVER_LOW     (0x2)
#define IO_GPIO_CTRL_INOVER_HIGH    (0x3)
/**@}*/

/* --- IO_GPIOx_CTRL_IRQOVER values ----------------------------------------- */

#define IO_GPIO_CTRL_IRQOVER(over)  ((over) << 28)
#define IO_GPIO_CTRL_IRQOVER_MASK   (0x3 << 28)
/** @defgroup io_gpio_ctrl_irqover Interrupt override
@ingroup io_defines
@{*/
#define IO_GPIO_CTRL_IRQOVER_NORMAL (0x0)
#define IO_GPIO_CTRL_IRQOVER_INVERT (0x1)
#define IO_GPIO_CTRL_IRQOVER_LOW    (0x2)
#define IO_GPIO_CTRL_IRQOVER_HIGH   (0x3)
/**@}*/

#endif

/**@}*/

