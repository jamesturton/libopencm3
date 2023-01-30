/** @defgroup resets_file Resets
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
 * @brief <b>libopencm3 RP2040 Subsystem Resets</b>
 *
 * The RP2040 Resets API provides functionality for reseting subsytems of the
 * RP2040.
 *
 * Please see the individual resets modules for more details. To use resets, the
 * resets.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/rp2040/resets.h>
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

#include <libopencm3/rp2040/resets.h>

void reset_block(uint32_t bits)
{
    RESETS_RESET |= bits;
}

void unreset_block(uint32_t bits)
{
    RESETS_RESET &= ~bits;
}

void unreset_block_wait(uint32_t bits)
{
    RESETS_RESET &= ~bits;
    while (~RESETS_RESET_DONE & bits)
        __asm__("nop");
}

/**@}*/

