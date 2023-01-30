/** @defgroup xosc_file XOSC
 *
 *
 * @ingroup RP2040
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 *
 * @date 14 May 2021
 *
 * LGPL License Terms @ref lgpl_license
 *
 * @brief <b>libopencm3 RP2040 Crystal Oscilator</b>
 *
 * The RP2040 XOSC API provides functionality for the crystal oscilator for the
 * RP2040.
 *
 * Please see the individual xosc modules for more details. To use xosc, the
 * xosc.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/rp2040/xosc.h>
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

#include <libopencm3/rp2040/xosc.h>
#include <libopencm3/rp2040/clocks.h>

void xosc_init(void)
{
    XOSC_CTRL = XOSC_CTRL_FREQ_RANGE_1_15MHZ;

    // Set xosc startup delay
    XOSC_STARTUP = (((12 * MHZ) / 1000) + 128) / 256;

    // Set the enable bit now that we have set freq range and startup delay
    XOSC_CTRL |= XOSC_CTRL_ENABLE(XOSC_CTRL_ENABLE_ENABLE);

    // Wait for XOSC to be stable
    while (!(XOSC_STATUS & XOSC_STATUS_STABLE))
        __asm__("nop");
}

void xosc_disable(void)
{
    uint32_t tmp = XOSC_CTRL;
    tmp &= ~XOSC_CTRL_ENABLE_MASK;
    tmp |= XOSC_CTRL_ENABLE(XOSC_CTRL_ENABLE_DISABLE);
    XOSC_CTRL = tmp;

    // Wait for stable to go away
    while ((XOSC_STATUS & XOSC_STATUS_STABLE))
        __asm__("nop");
}

void xosc_dormant(void)
{
    // WARNING: This stops the xosc until woken up by an irq
    XOSC_DORMANT = XOSC_DORMANT_DORMANT;

    // Wait for it to become stable once woken up
    while (!(XOSC_STATUS & XOSC_STATUS_STABLE))
        __asm__("nop");
}

/**@}*/

