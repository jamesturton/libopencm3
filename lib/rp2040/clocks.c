/** @defgroup clocks_file Clocks
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
 * @brief <b>libopencm3 RP2040 Clocks</b>
 *
 * The RP2040 Clocks API provides functionality for clocks of the RP2040.
 *
 * Please see the individual clocks modules for more details. To use clocks, the
 * clocks.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/rp2040/clocks.h>
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

#include <libopencm3/rp2040/clocks.h>
#include <libopencm3/rp2040/watchdog.h>
#include <libopencm3/rp2040/xosc.h>
#include <libopencm3/rp2040/resets.h>
#include <libopencm3/rp2040/pll.h>

static uint32_t configured_freq[CLOCKS_CLK_COUNT];

bool clock_configure(uint8_t clk_index, uint32_t src, uint32_t auxsrc, uint32_t src_freq, uint32_t freq)
{
    if (freq > src_freq)
        return false;

    // Div register is 24.8 int.frac divider so multiply by 2^8 (left shift by 8)
    uint32_t div = (uint32_t) (((uint64_t) src_freq << 8) / freq);

    // If increasing divisor, set divisor before source. Otherwise set source
    // before divisor. This avoids a momentary overspeed when e.g. switching
    // to a faster source and increasing divisor to compensate.
    if (div > CLOCKS_CLK_DIV(clk_index))
        CLOCKS_CLK_DIV(clk_index) = div;

    // Set aux mux first, and then glitchless mux if this clock has one
    CLOCKS_CLK_CTRL(clk_index) &= ~CLOCKS_CLK_REF_CTRL_AUXSRC_MASK;
    CLOCKS_CLK_CTRL(clk_index) |= CLOCKS_CLK_REF_CTRL_AUXSRC(auxsrc);

    if (clk_index == CLOCKS_CLK_SYS || clk_index == CLOCKS_CLK_REF)
    {
        CLOCKS_CLK_CTRL(clk_index) &= ~CLOCKS_CLK_REF_CTRL_SRC_MASK;
        CLOCKS_CLK_CTRL(clk_index) |= CLOCKS_CLK_REF_CTRL_SRC(src);

        while (!(CLOCKS_CLK_SELECTED(clk_index) & (1 << src)))
            __asm__("nop");
    }

    CLOCKS_CLK_CTRL(clk_index) |= CLOCKS_CLK_GPOUT_CTRL_ENABLE;

    // Now that the source is configured, we can trust that the user-supplied
    // divisor is a safe value.
    CLOCKS_CLK_DIV(clk_index) = div;

    // Store the configured frequency
    configured_freq[clk_index] = freq;

    return true;
}

void clocks_init(void)
{
    // Start tick in watchdog
    watchdog_start_tick(XOSC_MHZ);

    // Disable resus that may be enabled from previous software
    CLOCKS_CLK_SYS_RESUS_CTRL = 0;

    // Enable the xosc
    xosc_init();

    // Before we touch PLLs, switch sys and ref cleanly away from their aux sources.
    CLOCKS_CLK_SYS_CTRL &= ~CLOCKS_CLK_SYS_CTRL_SRC_MASK;
    while (CLOCKS_CLK_SYS_SELECTED != 0x1)
        __asm__("nop");
    CLOCKS_CLK_REF_CTRL &= ~CLOCKS_CLK_REF_CTRL_SRC_MASK;
    while (CLOCKS_CLK_REF_SELECTED != 0x1)
        __asm__("nop");

    // Configure PLLs
    //                   REF     FBDIV VCO            POSTDIV
    // PLL SYS: 12 / 1 = 12MHz * 125 = 1500MHZ / 6 / 2 = 125MHz
    // PLL USB: 12 / 1 = 12MHz * 40  = 480 MHz / 5 / 2 =  48MHz

    reset_block(RESETS_RESET_PLL_SYS | RESETS_RESET_PLL_USB);
    unreset_block_wait(RESETS_RESET_PLL_SYS | RESETS_RESET_PLL_USB);

    pll_sys_init(1, 1500 * MHZ, 6, 2);
    pll_usb_init(1, 480 * MHZ, 5, 2);

    // Configure clocks
    // CLK_REF = XOSC (12MHz) / 1 = 12MHz
    clock_configure(CLOCKS_CLK_REF,
                    CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC,
                    0, // No aux mux
                    12 * MHZ,
                    12 * MHZ);

    // CLK SYS = PLL SYS (125MHz) / 1 = 125MHz
    clock_configure(CLOCKS_CLK_SYS,
                    CLOCKS_CLK_SYS_CTRL_SRC_CLKSRC_CLK_SYS_AUX,
                    CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_SYS,
                    125 * MHZ,
                    125 * MHZ);

    // CLK USB = PLL USB (48MHz) / 1 = 48MHz
    clock_configure(CLOCKS_CLK_USB,
                    0, // No GLMUX
                    CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_USB,
                    48 * MHZ,
                    48 * MHZ);

    // CLK ADC = PLL USB (48MHZ) / 1 = 48MHz
    clock_configure(CLOCKS_CLK_ADC,
                    0, // No GLMUX
                    CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_USB,
                    48 * MHZ,
                    48 * MHZ);

    // CLK RTC = PLL USB (48MHz) / 1024 = 46875Hz
    clock_configure(CLOCKS_CLK_RTC,
                    0, // No GLMUX
                    CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_PLL_USB,
                    48 * MHZ,
                    46875);

    // CLK PERI = clk_sys. Used as reference clock for Peripherals. No dividers so just select and enable
    // Normally choose clk_sys or clk_usb
    clock_configure(CLOCKS_CLK_PERI,
                    0,
                    CLOCKS_CLK_PERI_CTRL_AUXSRC_CLK_SYS,
                    125 * MHZ,
                    125 * MHZ);
}

uint32_t clock_get_hz(uint8_t clk_index) {
    return configured_freq[clk_index];
}

/**@}*/

