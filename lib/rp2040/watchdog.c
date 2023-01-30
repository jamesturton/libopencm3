/** @defgroup watchdog_file Watchdog
 *
 *
 * @ingroup RP2040
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 *
 * @date 13 May 2021
 *
 * LGPL License Terms @ref lgpl_license
 *
 * @brief <b>libopencm3 RP2040 Watchdog</b>
 *
 * The RP2040 Watchdog API provides functionality for watchdog of the RP2040.
 *
 * Please see the individual watchdog modules for more details. To use watchdog, the
 * watchdog.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/rp2040/watchdog.h>
 * @endcode
 */

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

/**@{*/

#include <libopencm3/rp2040/watchdog.h>

void watchdog_start_tick(uint32_t cycles)
{
    // Important: This function also provides a tick reference to the timer
    WATCHDOG_TICK = cycles | WATCHDOG_TICK_ENABLE;
}

/**@}*/

