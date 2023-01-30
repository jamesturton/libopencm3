/** @defgroup watchdog_defines Watchdog Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 Watchdog</b>
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

#ifndef RP2040_WATCHDOG_H
#define RP2040_WATCHDOG_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

/* =============================================================================
 * Watchdog registers
 * ---------------------------------------------------------------------------*/

#define WATCHDOG_CTRL       MMIO32((RESETS_BASE) + 0x00)
#define WATCHDOG_LOAD       MMIO32((RESETS_BASE) + 0x04)
#define WATCHDOG_REASON     MMIO32((RESETS_BASE) + 0x08)
#define WATCHDOG_SCRATCH0   MMIO32((RESETS_BASE) + 0x0c)
#define WATCHDOG_SCRATCH1   MMIO32((RESETS_BASE) + 0x10)
#define WATCHDOG_SCRATCH2   MMIO32((RESETS_BASE) + 0x14)
#define WATCHDOG_SCRATCH3   MMIO32((RESETS_BASE) + 0x18)
#define WATCHDOG_SCRATCH4   MMIO32((RESETS_BASE) + 0x1c)
#define WATCHDOG_SCRATCH5   MMIO32((RESETS_BASE) + 0x20)
#define WATCHDOG_SCRATCH6   MMIO32((RESETS_BASE) + 0x24)
#define WATCHDOG_SCRATCH7   MMIO32((RESETS_BASE) + 0x28)
#define WATCHDOG_TICK       MMIO32((RESETS_BASE) + 0x2c)

/* --- WATCHDOG_CTRL_TIME values -------------------------------------------- */

#define WATCHDOG_CTRL_TIME(time)                        ((time) << 0)
#define WATCHDOG_CTRL_TIME_MASK	                        (0xffffff << 0)

/* --- WATCHDOG_CTRL_PAUSE_JTAG values -------------------------------------- */

#define WATCHDOG_CTRL_PAUSE_JTAG                        (0x1 << 24)

/* --- WATCHDOG_CTRL_PAUSE_DBG0 values -------------------------------------- */

#define WATCHDOG_CTRL_PAUSE_DBG0                        (0x1 << 25)

/* --- WATCHDOG_CTRL_PAUSE_DBG1 values -------------------------------------- */

#define WATCHDOG_CTRL_PAUSE_DBG1                        (0x1 << 26)

/* --- WATCHDOG_CTRL_ENABLE values ------------------------------------------ */

#define WATCHDOG_CTRL_ENABLE                            (0x1 << 30)

/* --- WATCHDOG_CTRL_TRIGGER values ----------------------------------------- */

#define WATCHDOG_CTRL_TRIGGER                           (0x1 << 31)

/* --- WATCHDOG_LOAD values ------------------------------------------------- */

#define WATCHDOG_LOAD_MASK	                            (0xffffff << 0)

/* --- WATCHDOG_REASON_TIMER values ----------------------------------------- */

#define WATCHDOG_REASON_TIMER                           (0x1 << 0)

/* --- WATCHDOG_REASON_FORCE values ----------------------------------------- */

#define WATCHDOG_REASON_FORCE                           (0x1 << 1)

/* --- WATCHDOG_TICK_CYCLES values ------------------------------------------ */

#define WATCHDOG_TICK_CYCLES(time)                      ((time) << 0)
#define WATCHDOG_TICK_CYCLES_MASK	                    (0x1ff << 0)

/* --- WATCHDOG_TICK_ENABLE values ------------------------------------------ */

#define WATCHDOG_TICK_ENABLE                            (0x1 << 9)

/* --- WATCHDOG_TICK_RUNNING values ----------------------------------------- */

#define WATCHDOG_TICK_RUNNING                           (0x1 << 10)

/* --- WATCHDOG_TICK_COUNT values ------------------------------------------- */

#define WATCHDOG_TICK_COUNT(time)                       ((time) << 11)
#define WATCHDOG_TICK_COUNT_MASK	                    (0x1ff << 11)

/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void watchdog_start_tick(uint32_t cycles);

/** @} */
END_DECLS

#endif

/**@}*/

