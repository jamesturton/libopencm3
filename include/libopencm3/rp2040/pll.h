/** @defgroup pll_defines PLL Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 Phase Lock Loop</b>
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

#ifndef RP2040_PLL_H
#define RP2040_PLL_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

/* =============================================================================
 * PLL registers
 * ---------------------------------------------------------------------------*/

#define PLL_SYS_CS          MMIO32((PLL_SYS_BASE) + 0x00)
#define PLL_SYS_PWR         MMIO32((PLL_SYS_BASE) + 0x04)
#define PLL_SYS_FBDIV_INT   MMIO32((PLL_SYS_BASE) + 0x08)
#define PLL_SYS_PRIM        MMIO32((PLL_SYS_BASE) + 0x0c)

#define PLL_USB_CS          MMIO32((PLL_USB_BASE) + 0x00)
#define PLL_USB_PWR         MMIO32((PLL_USB_BASE) + 0x04)
#define PLL_USB_FBDIV_INT   MMIO32((PLL_USB_BASE) + 0x08)
#define PLL_USB_PRIM        MMIO32((PLL_USB_BASE) + 0x0c)

/* --- PLL_CS_REFDIV values ------------------------------------------------- */

#define PLL_CS_REFDIV(div)                              ((div) << 0)
#define PLL_CS_REFDIV_MASK	                            (0x3f << 0)

/* --- PLL_CS_BYPASS values ------------------------------------------------- */

#define PLL_CS_BYPASS                                   (0x1 << 8)

/* --- PLL_CS_LOCK values --------------------------------------------------- */

#define PLL_CS_LOCK                                     (0x1 << 31)

/* --- PLL_PWR_PD values ---------------------------------------------------- */

#define PLL_PWR_PD                                      (0x1 << 0)

/* --- PLL_PWR_DSMPD values ------------------------------------------------- */

#define PLL_PWR_DSMPD                                   (0x1 << 2)

/* --- PLL_PWR_POSTDIVPD values --------------------------------------------- */

#define PLL_PWR_POSTDIVPD                               (0x1 << 3)

/* --- PLL_PWR_VCOPD values ------------------------------------------------- */

#define PLL_PWR_VCOPD                                   (0x1 << 5)

/* --- PLL_FBDIV_INT values ------------------------------------------------- */

#define PLL_FBDIV_INT(int)                              ((int) << 0)
#define PLL_FBDIV_INT_MASK	                            (0xfff << 0)

/* --- PLL_PRIM_POSTDIV2 values --------------------------------------------- */

#define PLL_PRIM_POSTDIV2(div)                          ((div) << 12)
#define PLL_PRIM_POSTDIV2_MASK	                        (0x7 << 12)

/* --- PLL_PRIM_POSTDIV1 values --------------------------------------------- */

#define PLL_PRIM_POSTDIV1(div)                          ((div) << 16)
#define PLL_PRIM_POSTDIV1_MASK	                        (0x7 << 16)

/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void pll_sys_init(uint8_t refdiv, uint32_t vco_freq, uint8_t post_div1, uint8_t post_div2);
void pll_sys_deinit(void);

void pll_usb_init(uint8_t refdiv, uint32_t vco_freq, uint8_t post_div1, uint8_t post_div2);
void pll_usb_deinit(void);

/** @} */
END_DECLS

#endif

/**@}*/

