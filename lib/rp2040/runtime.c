/** @defgroup runtime_file Runtime
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
 * @brief <b>libopencm3 RP2040 Runtime</b>
 *
 * The RP2040 Runtime API provides functionality for runtime of the RP2040.
 *
 * Please see the individual runtime modules for more details. To use runtime, the
 * runtime.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/rp2040/runtime.h>
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

#include <libopencm3/rp2040/runtime.h>
#include <libopencm3/rp2040/resets.h>
#include <libopencm3/rp2040/clocks.h>

void runtime_init(void)
{
    // Reset all peripherals to put system into a known state,
    // - except for QSPI pads and the XIP IO bank, as this is fatal if running from flash
    // - and the PLLs, as this is fatal if clock muxing has not been reset on this boot
    reset_block(~(RESETS_RESET_IO_QSPI |
        RESETS_RESET_PADS_QSPI |
        RESETS_RESET_PLL_USB |
        RESETS_RESET_PLL_SYS));

    // Remove reset from peripherals which are clocked only by clk_sys and
    // clk_ref. Other peripherals stay in reset until we've configured clocks.
    unreset_block_wait(RESETS_RESET_MASK &
        ~(RESETS_RESET_ADC |
        RESETS_RESET_RTC |
        RESETS_RESET_SPI0 |
        RESETS_RESET_SPI1 |
        RESETS_RESET_UART0 |
        RESETS_RESET_UART1 |
        RESETS_RESET_USBCTRL));

    // After calling preinit we have enough runtime to do the exciting maths
    // in clocks_init
    clocks_init();

    // Peripheral clocks should now all be running
    unreset_block_wait(RESETS_RESET_MASK);
}

/**@}*/

