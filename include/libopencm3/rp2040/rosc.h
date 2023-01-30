/** @defgroup rosc_defines ROSC Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 Ring Oscillator</b>
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

#ifndef RP2040_ROSC_H
#define RP2040_ROSC_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

/* =============================================================================
 * ROSC registers
 * ---------------------------------------------------------------------------*/

#define ROSC_CTRL       MMIO32((ROSC_BASE) + 0x00)
#define ROSC_FREQA      MMIO32((ROSC_BASE) + 0x04)
#define ROSC_FREQB      MMIO32((ROSC_BASE) + 0x08)
#define ROSC_DORMANT    MMIO32((ROSC_BASE) + 0x0c)
#define ROSC_DIV        MMIO32((ROSC_BASE) + 0x10)
#define ROSC_PHASE      MMIO32((ROSC_BASE) + 0x14)
#define ROSC_STATUS     MMIO32((ROSC_BASE) + 0x18)
#define ROSC_RANDOMBIT  MMIO32((ROSC_BASE) + 0x1c)
#define ROSC_COUNT      MMIO32((ROSC_BASE) + 0x20)

/* --- ROSC_CTRL_FREQ_RANGE values ------------------------------------------ */

#define ROSC_CTRL_FREQ_RANGE(range)                     (range)
#define ROSC_CTRL_FREQ_RANGE_MASK	                    (0xfff << 0)
/** @defgroup rosc_ctrl_freq_range Frequency range
@ingroup rosc_defines
@{*/
#define ROSC_CTRL_FREQ_RANGE_LOW                        0xfa4
#define ROSC_CTRL_FREQ_RANGE_MEDIUM                     0xfa5
#define ROSC_CTRL_FREQ_RANGE_HIGH                       0xfa7
#define ROSC_CTRL_FREQ_RANGE_TOOHIGH                    0xfa6
/**@}*/

/* --- ROSC_FREQA_DS0 values ------------------------------------------------ */

#define ROSC_FREQA_DS0(ds)                              ((ds) << 0)
#define ROSC_FREQA_DS0_MASK	                            (0x7 << 0)

/* --- ROSC_FREQA_DS1 values ------------------------------------------------ */

#define ROSC_FREQA_DS1(ds)                              ((ds) << 4)
#define ROSC_FREQA_DS1_MASK	                            (0x7 << 4)

/* --- ROSC_FREQA_DS2 values ------------------------------------------------ */

#define ROSC_FREQA_DS2(ds)                              ((ds) << 8)
#define ROSC_FREQA_DS2_MASK	                            (0x7 << 8)

/* --- ROSC_FREQA_DS3 values ------------------------------------------------ */

#define ROSC_FREQA_DS3(ds)                              ((ds) << 12)
#define ROSC_FREQA_DS3_MASK	                            (0x7 << 12)

/* --- ROSC_FREQA_PASSWD values --------------------------------------------- */

#define ROSC_FREQA_PASSWD(pass)                         ((ds) << 16)
#define ROSC_FREQA_PASSWD_MASK	                        (0xffff << 16)
#define ROSC_FREQA_PASSWD_PASS                          0x9696

/* --- ROSC_FREQA_DS4 values ------------------------------------------------ */

#define ROSC_FREQA_DS4(ds)                              ((ds) << 0)
#define ROSC_FREQA_DS4_MASK	                            (0x7 << 0)

/* --- ROSC_FREQA_DS5 values ------------------------------------------------ */

#define ROSC_FREQA_DS5(ds)                              ((ds) << 4)
#define ROSC_FREQA_DS5_MASK	                            (0x7 << 4)

/* --- ROSC_FREQA_DS6 values ------------------------------------------------ */

#define ROSC_FREQA_DS6(ds)                              ((ds) << 8)
#define ROSC_FREQA_DS6_MASK	                            (0x7 << 8)

/* --- ROSC_FREQA_DS7 values ------------------------------------------------ */

#define ROSC_FREQA_DS7(ds)                              ((ds) << 12)
#define ROSC_FREQA_DS7_MASK	                            (0x7 << 12)

/* --- ROSC_FREQA_PASSWD values --------------------------------------------- */

#define ROSC_FREQA_PASSWD(pass)                         ((pass) << 16)
#define ROSC_FREQA_PASSWD_MASK	                        (0xffff << 16)
#define ROSC_FREQA_PASSWD_PASS                          0x9696

/* --- ROSC_DORMANT values -------------------------------------------------- */

#define ROSC_DORMANT_WAKE                               0x77616b65
#define ROSC_DORMANT_DORMANT                            0x636f6d61

/* --- ROSC_DIV values ------------------------------------------------------ */

#define ROSC_DIV(div)                                   ((div) << 0)
#define ROSC_DIV_MASK	                                (0xfff << 0)

/* --- ROSC_PHASE_SHIFT values ---------------------------------------------- */

#define ROSC_PHASE_SHIFT(shift)                         ((shift) << 0)
#define ROSC_PHASE_SHIFT_MASK	                        (0x3 << 0)

/* --- ROSC_PHASE_FLIP values ----------------------------------------------- */

#define ROSC_PHASE_FLIP                                 (0x1 << 2)

/* --- ROSC_PHASE_ENABLE values --------------------------------------------- */

#define ROSC_PHASE_ENABLE                               (0x1 << 3)

/* --- ROSC_PHASE_PASSWD values --------------------------------------------- */

#define ROSC_PHASE_PASSWD(pass)                         ((pass) << 4)
#define ROSC_PHASE_PASSWD_MASK	                        (0xff << 4)
#define ROSC_PHASE_PASSWD_PASS                          0xaa

/* --- ROSC_STATUS_ENABLED values ------------------------------------------- */

#define ROSC_STATUS_ENABLED                             (0x1 << 12)

/* --- ROSC_STATUS_DIV_RUNNING values --------------------------------------- */

#define ROSC_STATUS_DIV_RUNNING                         (0x1 << 24)

/* --- ROSC_STATUS_BADWRITE values ------------------------------------------ */

#define ROSC_STATUS_BADWRITE                            (0x1 << 24)

/* --- ROSC_STATUS_STABLE values -------------------------------------------- */

#define ROSC_STATUS_STABLE                              (0x1 << 31)

/* --- ROSC_RANDOMBIT values -------------------------------------------- */

#define ROSC_RANDOMBIT_MASK                             (0x1 << 0)

/* --- ROSC_COUNT values ---------------------------------------------------- */

#define ROSC_COUNT(count)                               (count)
#define ROSC_COUNT_MASK	                                (0xff << 0)

#endif

/**@}*/

