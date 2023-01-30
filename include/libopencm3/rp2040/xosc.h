/** @defgroup xosc_defines XOSC Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 Crystal Oscillator</b>
 *
 * @version 1.0.0
 * 
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 * 
 * @date 14 May 2021
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

#ifndef RP2040_XOSC_H
#define RP2040_XOSC_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

#define XOSC_MHZ                                        12

/* =============================================================================
 * XOSC registers
 * ---------------------------------------------------------------------------*/

#define XOSC_CTRL       MMIO32((XOSC_BASE) + 0x00)
#define XOSC_STATUS     MMIO32((XOSC_BASE) + 0x04)
#define XOSC_DORMANT    MMIO32((XOSC_BASE) + 0x08)
#define XOSC_STARTUP    MMIO32((XOSC_BASE) + 0x0c)
#define XOSC_COUNT      MMIO32((XOSC_BASE) + 0x1c)

/* --- XOSC_CTRL_FREQ_RANGE values ------------------------------------------ */

#define XOSC_CTRL_FREQ_RANGE(range)                     ((range) << 0)
#define XOSC_CTRL_FREQ_RANGE_MASK	                    (0xfff << 0)
/** @defgroup xosc_ctrl_freq_range Frequency range
@ingroup xosc_defines
@{*/
#define XOSC_CTRL_FREQ_RANGE_1_15MHZ                    0xaa0
#define XOSC_CTRL_FREQ_RANGE_RESERVED_1                 0xaa1
#define XOSC_CTRL_FREQ_RANGE_RESERVED_2                 0xaa2
#define XOSC_CTRL_FREQ_RANGE_RESERVED_3                 0xaa3
/**@}*/

/* --- XOSC_CTRL_ENABLE values ---------------------------------------------- */

#define XOSC_CTRL_ENABLE(en)                            ((en) << 12)
#define XOSC_CTRL_ENABLE_MASK	                        (0xfff << 12)
/** @defgroup xosc_ctrl_enable Enable crystal oscilator
@ingroup xosc_defines
@{*/
#define XOSC_CTRL_ENABLE_ENABLE                         0xfab
#define XOSC_CTRL_ENABLE_DISABLE                        0xd1e
/**@}*/

/* --- XOSC_STATUS_FREQ_RANGE values ---------------------------------------- */

#define XOSC_STATUS_FREQ_RANGE(range)                   (range)
#define XOSC_STATUS_FREQ_RANGE_MASK	                    (0x3 << 0)
/** @defgroup xosc_status_freq_range Frequency range
@ingroup xosc_defines
@{*/
#define XOSC_STATUS_FREQ_RANGE_1_15MHZ                  0x0
#define XOSC_STATUS_FREQ_RANGE_RESERVED_1               0x1
#define XOSC_STATUS_FREQ_RANGE_RESERVED_2               0x2
#define XOSC_STATUS_FREQ_RANGE_RESERVED_3               0x3
/**@}*/

/* --- XOSC_STATUS_ENABLED values ------------------------------------------- */

#define XOSC_STATUS_ENABLED                             (0x1 << 12)

/* --- XOSC_STATUS_BADWRITE values ------------------------------------------ */

#define XOSC_STATUS_BADWRITE                            (0x1 << 24)

/* --- XOSC_STATUS_STABLE values -------------------------------------------- */

#define XOSC_STATUS_STABLE                              (0x1 << 31)

/* --- XOSC_DORMANT values -------------------------------------------------- */

#define XOSC_DORMANT_WAKE                               0x77616b65
#define XOSC_DORMANT_DORMANT                            0x636f6d61

/* --- XOSC_STARTUP_DELAY values -------------------------------------------- */

#define XOSC_STARTUP_DELAY(delay)                       (delay)
#define XOSC_STARTUP_DELAY_MASK	                        (0x3fff << 0)

/* --- XOSC_STARTUP_X4 values ----------------------------------------------- */

#define XOSC_STARTUP_X4                                 (0x1 << 20)

/* --- XOSC_COUNT values ---------------------------------------------------- */

#define XOSC_COUNT_MASK	                                (0xff << 0)

/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void xosc_init(void);
void xosc_disable(void);
void xosc_dormant(void);

/** @} */
END_DECLS

#endif

/**@}*/

