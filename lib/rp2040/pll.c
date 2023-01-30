/** @defgroup pll_file PLL
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
 * @brief <b>libopencm3 RP2040 Phase Lock Loop</b>
 *
 * The RP2040 PLL API provides functionality for pll of the RP2040.
 *
 * Please see the individual pll modules for more details. To use pll, the
 * pll.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/rp2040/pll.h>
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

#include <libopencm3/rp2040/pll.h>
#include <libopencm3/rp2040/xosc.h>
#include <libopencm3/rp2040/clocks.h>

void pll_sys_init(uint8_t refdiv, uint32_t vco_freq, uint8_t post_div1, uint8_t post_div2)
{
    // Turn off PLL in case it is already running
    PLL_SYS_PWR = 0xffffffff;
    PLL_SYS_FBDIV_INT = 0;
    PLL_SYS_CS = refdiv;

    // What are we multiplying the reference clock by to get the vco freq
    // (The regs are called div, because you divide the vco output and compare it to the refclk)
    // Put calculated value into feedback divider
    PLL_SYS_FBDIV_INT = vco_freq / ((XOSC_MHZ / refdiv) * MHZ);

    // Turn on PLL
    PLL_SYS_PWR &= ~(PLL_PWR_PD | PLL_PWR_VCOPD);

    // Wait for PLL to lock
    while (!(PLL_SYS_CS & PLL_CS_LOCK))
        __asm__("nop");

    // Set up post dividers - div1 feeds into div2 so if div1 is 5 and div2 is 2 then you get a divide by 10
    PLL_SYS_PRIM = PLL_PRIM_POSTDIV1(post_div1) | PLL_PRIM_POSTDIV2(post_div2);

    // Turn on post divider
    PLL_SYS_PWR &= ~PLL_PWR_POSTDIVPD;
}

void pll_sys_deinit(void)
{
    PLL_SYS_PWR = PLL_PWR_PD | PLL_PWR_DSMPD | PLL_PWR_POSTDIVPD | PLL_PWR_VCOPD;
}

void pll_usb_init(uint8_t refdiv, uint32_t vco_freq, uint8_t post_div1, uint8_t post_div2)
{
    // Turn off PLL in case it is already running
    PLL_USB_PWR = 0xffffffff;
    PLL_USB_FBDIV_INT = 0;
    PLL_USB_CS = refdiv;

    // What are we multiplying the reference clock by to get the vco freq
    // (The regs are called div, because you divide the vco output and compare it to the refclk)
    // Put calculated value into feedback divider
    PLL_USB_FBDIV_INT = vco_freq / ((XOSC_MHZ / refdiv) * MHZ);

    // Turn on PLL
    PLL_USB_PWR &= ~(PLL_PWR_PD | PLL_PWR_VCOPD);

    // Wait for PLL to lock
    while (!(PLL_USB_CS & PLL_CS_LOCK))
        __asm__("nop");

    // Set up post dividers - div1 feeds into div2 so if div1 is 5 and div2 is 2 then you get a divide by 10
    PLL_USB_PRIM = PLL_PRIM_POSTDIV1(post_div1) | PLL_PRIM_POSTDIV2(post_div2);

    // Turn on post divider
    PLL_USB_PWR &= ~PLL_PWR_POSTDIVPD;
}

void pll_usb_deinit(void)
{
    PLL_USB_PWR = PLL_PWR_PD | PLL_PWR_DSMPD | PLL_PWR_POSTDIVPD | PLL_PWR_VCOPD;
}


/**@}*/

