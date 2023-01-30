/** @defgroup pad_defines Pad Bank 0 Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 Pad Bank 0</b>
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

#ifndef RP2040_PAD_H
#define RP2040_PAD_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

/* =============================================================================
 * Pad registers
 * ---------------------------------------------------------------------------*/

#define PAD_VOLTAGE_SEL     MMIO32((PADS_BANK0_BASE) + 0x00)

#define PAD_GPIO(pin)       MMIO32((PADS_BANK0_BASE) + ((pin + 1) * 0x04))

#define PAD_GPIO0           PAD_GPIO(0)
#define PAD_GPIO1           PAD_GPIO(1)
#define PAD_GPIO2           PAD_GPIO(2)
#define PAD_GPIO3           PAD_GPIO(3)
#define PAD_GPIO4           PAD_GPIO(4)
#define PAD_GPIO5           PAD_GPIO(5)
#define PAD_GPIO6           PAD_GPIO(6)
#define PAD_GPIO7           PAD_GPIO(7)
#define PAD_GPIO8           PAD_GPIO(8)
#define PAD_GPIO9           PAD_GPIO(9)
#define PAD_GPIO10          PAD_GPIO(10)
#define PAD_GPIO11          PAD_GPIO(11)
#define PAD_GPIO12          PAD_GPIO(12)
#define PAD_GPIO13          PAD_GPIO(13)
#define PAD_GPIO14          PAD_GPIO(14)
#define PAD_GPIO15          PAD_GPIO(15)
#define PAD_GPIO16          PAD_GPIO(16)
#define PAD_GPIO17          PAD_GPIO(17)
#define PAD_GPIO18          PAD_GPIO(18)
#define PAD_GPIO19          PAD_GPIO(19)
#define PAD_GPIO20          PAD_GPIO(20)
#define PAD_GPIO21          PAD_GPIO(21)
#define PAD_GPIO22          PAD_GPIO(22)
#define PAD_GPIO23          PAD_GPIO(23)
#define PAD_GPIO24          PAD_GPIO(24)
#define PAD_GPIO25          PAD_GPIO(25)
#define PAD_GPIO26          PAD_GPIO(26)
#define PAD_GPIO27          PAD_GPIO(27)
#define PAD_GPIO28          PAD_GPIO(28)
#define PAD_GPIO29          PAD_GPIO(29)

#define PAD_SWCLK           MMIO32((PADS_BANK0_BASE) + 0x7c)
#define PAD_SWD             MMIO32((PADS_BANK0_BASE) + 0x80)

/* --- PAD_VOLTAGE_SELECT values -------------------------------------------- */

#define PAD_VOLTAGE_SELECT(voltage)		(voltage)
#define PAD_VOLTAGE_SELECT_MASK		    (0x1)
/** @defgroup pad_voltage_select Pad Voltage Select
@ingroup pad_defines
@{*/
#define PAD_VOLTAGE_SELECT_3V3  0x0
#define PAD_VOLTAGE_SELECT_1V8  0x1
/**@}*/

/* --- PAD_SLEW values ------------------------------------------------------ */

#define PAD_SLEW(slew)		(slew)
#define PAD_SLEW_MASK		(0x1)
/** @defgroup pad_slew Slew rate control
@ingroup pad_defines
@{*/
#define PAD_SLEW_SLOW   0x0
#define PAD_SLEW_FAST   0x1
/**@}*/

/* --- PAD_SCHMITT values --------------------------------------------------- */

#define PAD_SCHMITT(schmitt)    ((schmitt) << 1)
#define PAD_SCHMITT_MASK		(0x1 << 1)
/** @defgroup pad_schmitt Enable schmitt trigger
@ingroup pad_defines
@{*/
#define PAD_SCHMITT_ENABLE  0x0
#define PAD_SCHMITT_DISABLE 0x1
/**@}*/

/* --- PAD_PUPD values ------------------------------------------------------ */

#define PAD_PUPD(pupd)  ((pupd) << 2)
#define PAD_PUPD_MASK	(0x3 << 2)
/** @defgroup pad_pup Pullup pulldown
@ingroup pad_defines
@{*/
#define PAD_PUPD_NONE		0x0
#define PAD_PUPD_PULLDOWN	0x1
#define PAD_PUPD_PULLUP		0x2
#define PAD_PUPD_KEEP		0x3
/**@}*/

/* --- PAD_DRIVE values ----------------------------------------------------- */

#define PAD_DRIVE(drive)    ((pupd) << 4)
#define PAD_DRIVE_MASK	    (0x3 << 4)
/** @defgroup pad_drive Drive strength
@ingroup pad_defines
@{*/
#define PAD_DRIVE_2MA	0x0
#define PAD_DRIVE_4MA	0x1
#define PAD_DRIVE_8MA	0x2
#define PAD_DRIVE_12MA	0x3
/**@}*/

/* --- PAD_IE values -------------------------------------------------------- */

#define PAD_IE(ie)  ((ie) << 6)
#define PAD_IE_MASK (0x1 << 6)
/** @defgroup pad_ie Input enable
@ingroup pad_defines
@{*/
#define PAD_INPUT_DISABLE   0x0
#define PAD_INPUT_ENABLE    0x1
/**@}*/

/* --- PAD_OD values -------------------------------------------------------- */

#define PAD_OD(ie)  ((ie) << 7)
#define PAD_OD_MASK (0x1 << 7)
/** @defgroup pad_od Output disable
@ingroup pad_defines
@{*/
#define PAD_OUTPUT_ENABLE   0x0
#define PAD_OUTPUT_DISABLE  0x1
/**@}*/

#endif

/**@}*/

