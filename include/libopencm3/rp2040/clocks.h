/** @defgroup clocks_defines Clocks Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 Clocks</b>
 *
 * @version 1.0.0
 * 
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 * 
 * @date 13 May 2021
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

#ifndef RP2040_CLOCKS_H
#define RP2040_CLOCKS_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

#define KHZ 1000
#define MHZ 1000000

/* =============================================================================
 * Clocks registers
 * ---------------------------------------------------------------------------*/

#define CLOCKS_CLK_GPOUT0               0
#define CLOCKS_CLK_GPOUT1               1
#define CLOCKS_CLK_GPOUT2               2
#define CLOCKS_CLK_GPOUT3               3
#define CLOCKS_CLK_REF                  4
#define CLOCKS_CLK_SYS                  5
#define CLOCKS_CLK_PERI                 6
#define CLOCKS_CLK_USB                  7
#define CLOCKS_CLK_ADC                  8
#define CLOCKS_CLK_RTC                  9
#define CLOCKS_CLK_COUNT                10

#define CLOCKS_CLK_CTRL(id)             MMIO32((CLOCKS_BASE) + ((id) * 0x0c) + 0x00)
#define CLOCKS_CLK_DIV(id)              MMIO32((CLOCKS_BASE) + ((id) * 0x0c) + 0x04)
#define CLOCKS_CLK_SELECTED(id)         MMIO32((CLOCKS_BASE) + ((id) * 0x0c) + 0x08)

#define CLOCKS_CLK_GPOUT0_CTRL          MMIO32((CLOCKS_BASE) + 0x00)
#define CLOCKS_CLK_GPOUT0_DIV           MMIO32((CLOCKS_BASE) + 0x04)
#define CLOCKS_CLK_GPOUT0_SELECTED      MMIO32((CLOCKS_BASE) + 0x08)
#define CLOCKS_CLK_GPOUT1_CTRL          MMIO32((CLOCKS_BASE) + 0x0c)
#define CLOCKS_CLK_GPOUT1_DIV           MMIO32((CLOCKS_BASE) + 0x10)
#define CLOCKS_CLK_GPOUT1_SELECTED      MMIO32((CLOCKS_BASE) + 0x14)
#define CLOCKS_CLK_GPOUT2_CTRL          MMIO32((CLOCKS_BASE) + 0x18)
#define CLOCKS_CLK_GPOUT2_DIV           MMIO32((CLOCKS_BASE) + 0x1c)
#define CLOCKS_CLK_GPOUT2_SELECTED      MMIO32((CLOCKS_BASE) + 0x20)
#define CLOCKS_CLK_GPOUT3_CTRL          MMIO32((CLOCKS_BASE) + 0x24)
#define CLOCKS_CLK_GPOUT3_DIV           MMIO32((CLOCKS_BASE) + 0x28)
#define CLOCKS_CLK_GPOUT3_SELECTED      MMIO32((CLOCKS_BASE) + 0x2c)
#define CLOCKS_CLK_REF_CTRL             MMIO32((CLOCKS_BASE) + 0x30)
#define CLOCKS_CLK_REF_DIV              MMIO32((CLOCKS_BASE) + 0x34)
#define CLOCKS_CLK_REF_SELECTED         MMIO32((CLOCKS_BASE) + 0x38)
#define CLOCKS_CLK_SYS_CTRL             MMIO32((CLOCKS_BASE) + 0x3c)
#define CLOCKS_CLK_SYS_DIV              MMIO32((CLOCKS_BASE) + 0x40)
#define CLOCKS_CLK_SYS_SELECTED         MMIO32((CLOCKS_BASE) + 0x44)
#define CLOCKS_CLK_PERI_CTRL            MMIO32((CLOCKS_BASE) + 0x48)
#define CLOCKS_CLK_PERI_SELECTED        MMIO32((CLOCKS_BASE) + 0x50)
#define CLOCKS_CLK_USB_CTRL             MMIO32((CLOCKS_BASE) + 0x54)
#define CLOCKS_CLK_USB_DIV              MMIO32((CLOCKS_BASE) + 0x58)
#define CLOCKS_CLK_USB_SELECTED         MMIO32((CLOCKS_BASE) + 0x5c)
#define CLOCKS_CLK_ADC_CTRL             MMIO32((CLOCKS_BASE) + 0x60)
#define CLOCKS_CLK_ADC_DIV              MMIO32((CLOCKS_BASE) + 0x64)
#define CLOCKS_CLK_ADC_SELECTED         MMIO32((CLOCKS_BASE) + 0x68)
#define CLOCKS_CLK_RTC_CTRL             MMIO32((CLOCKS_BASE) + 0x6c)
#define CLOCKS_CLK_RTC_DIV              MMIO32((CLOCKS_BASE) + 0x70)
#define CLOCKS_CLK_RTC_SELECTED         MMIO32((CLOCKS_BASE) + 0x74)
#define CLOCKS_CLK_SYS_RESUS_CTRL       MMIO32((CLOCKS_BASE) + 0x78)
#define CLOCKS_CLK_SYS_RESUS_STATUS     MMIO32((CLOCKS_BASE) + 0x7c)
#define CLOCKS_FC0_REF_KHZ              MMIO32((CLOCKS_BASE) + 0x80)
#define CLOCKS_FC0_MIN_KHZ              MMIO32((CLOCKS_BASE) + 0x84)
#define CLOCKS_FC0_MAX_KHZ              MMIO32((CLOCKS_BASE) + 0x88)
#define CLOCKS_FC0_DELAY                MMIO32((CLOCKS_BASE) + 0x8c)
#define CLOCKS_FC0_INTERVAL             MMIO32((CLOCKS_BASE) + 0x90)
#define CLOCKS_FC0_SRC                  MMIO32((CLOCKS_BASE) + 0x94)
#define CLOCKS_FC0_STATUS               MMIO32((CLOCKS_BASE) + 0x98)
#define CLOCKS_FC0_RESULT               MMIO32((CLOCKS_BASE) + 0x9c)
#define CLOCKS_WAKE_EN0                 MMIO32((CLOCKS_BASE) + 0xa0)
#define CLOCKS_WAKE_EN1                 MMIO32((CLOCKS_BASE) + 0xa4)
#define CLOCKS_SLEEP_EN0                MMIO32((CLOCKS_BASE) + 0xa8)
#define CLOCKS_SLEEP_EN1                MMIO32((CLOCKS_BASE) + 0xac)
#define CLOCKS_ENABLED0                 MMIO32((CLOCKS_BASE) + 0xb0)
#define CLOCKS_ENABLED1                 MMIO32((CLOCKS_BASE) + 0xb4)
#define CLOCKS_INTR                     MMIO32((CLOCKS_BASE) + 0xb8)
#define CLOCKS_INTE                     MMIO32((CLOCKS_BASE) + 0xbc)
#define CLOCKS_INTF                     MMIO32((CLOCKS_BASE) + 0xc0)
#define CLOCKS_INTS                     MMIO32((CLOCKS_BASE) + 0xc4)

/* --- CLOCKS_CLK_GPOUTx_CTRL_AUXSRC values --------------------------------- */

#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC(src)               (voltage)
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_MASK	            (0xf << 5)
/** @defgroup clocks_clk_gpout_ctrl_auxsrc Selects the auxiliary clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLKSRC_PLL_SYS      0x0
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLKSRC_GPIN0        0x1
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLKSRC_GPIN1        0x2
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLKSRC_PLL_USB      0x3
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_ROSC_CLKSRC         0x4
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_XOSC_CLKSRC         0x5
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLK_SYS             0x6
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLK_USB             0x7
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLK_ADC             0x8
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLK_RTC             0x9
#define CLOCKS_CLK_GPOUT_CTRL_AUXSRC_CLK_REF             0xa
/**@}*/

/* --- CLOCKS_CLK_GPOUTx_CTRL_KILL values ----------------------------------- */

#define CLOCKS_CLK_GPOUT_CTRL_KILL                      (0x1 << 10)

/* --- CLOCKS_CLK_GPOUTx_CTRL_ENABLE values --------------------------------- */

#define CLOCKS_CLK_GPOUT_CTRL_ENABLE                    (0x1 << 11)

/* --- CLOCKS_CLK_GPOUTx_CTRL_DC50 values ----------------------------------- */

#define CLOCKS_CLK_GPOUT_CTRL_DC50                      (0x1 << 12)

/* --- CLOCKS_CLK_GPOUTx_CTRL_PHASE values ---------------------------------- */

#define CLOCKS_CLK_GPOUT_CTRL_PHASE(phase)              (phase)
#define CLOCKS_CLK_GPOUT_CTRL_PHASE_MASK                (0x3 << 16)

/* --- CLOCKS_CLK_GPOUTx_CTRL_NUDGE values ---------------------------------- */

#define CLOCKS_CLK_GPOUT_CTRL_NUDGE                     (0x1 << 20)

/* --- CLOCKS_CLK_GPOUTx_DIV_FRAC values ------------------------------------ */

#define CLOCKS_CLK_GPOUT_DIV_FRAC(frac)                 (frac)
#define CLOCKS_CLK_GPOUT_DIV_FRAC_MASK                  0xff

/* --- CLOCKS_CLK_GPOUTx_DIV_INT values ------------------------------------- */

#define CLOCKS_CLK_GPOUT_DIV_INT(int)                   ((int) << 8)
#define CLOCKS_CLK_GPOUT_DIV_INT_MASK                   (0xffffff << 8)

/* --- CLOCKS_CLK_GPOUTx_SELECTED values ------------------------------------ */

#define CLOCKS_CLK_GPOUT_SELECTED_MASK                  0xffffffff

/* --- CLOCKS_CLK_REF_CTRL_SRC values --------------------------------------- */

#define CLOCKS_CLK_REF_CTRL_SRC(src)                    (src)
#define CLOCKS_CLK_REF_CTRL_SRC_MASK                    (0x3 << 0)
/** @defgroup clocks_clk_ref_ctrl_src Selects the clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_REF_CTRL_SRC_ROSC_CLKSRC_PH          0x0
#define CLOCKS_CLK_REF_CTRL_SRC_CLKSRC_CLK_REF_AUX      0x1
#define CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC             0x2
/**@}*/

/* --- CLOCKS_CLK_REF_CTRL_AUXSRC values ------------------------------------ */

#define CLOCKS_CLK_REF_CTRL_AUXSRC(src)                 ((src) << 5)
#define CLOCKS_CLK_REF_CTRL_AUXSRC_MASK                 (0x3 << 5)
/** @defgroup clocks_clk_ref_ctrl_auxsrc Selects the auxiliary clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_PLL_USB       0x0
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_GPIN0         0x1
#define CLOCKS_CLK_REF_CTRL_AUXSRC_CLKSRC_GPIN1         0x2
/**@}*/

/* --- CLOCKS_CLK_REF_DIV_INT values ------------------------------------- */

#define CLOCKS_CLK_REF_DIV_INT(int)                     ((int) << 8)
#define CLOCKS_CLK_REF_DIV_INT_MASK                     (0x3 << 8)

/* --- CLOCKS_CLK_REF_SELECTED values ------------------------------------ */

#define CLOCKS_CLK_REF_SELECTED_MASK                    0xffffffff

/* --- CLOCKS_CLK_SYS_CTRL_SRC values --------------------------------------- */

#define CLOCKS_CLK_SYS_CTRL_SRC(src)                    (src)
#define CLOCKS_CLK_SYS_CTRL_SRC_MASK                    (0x1 << 0)
/** @defgroup clocks_clk_sys_ctrl_src Selects the clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_SYS_CTRL_SRC_CLK_REF                 0x0
#define CLOCKS_CLK_SYS_CTRL_SRC_CLKSRC_CLK_SYS_AUX      0x1
/**@}*/

/* --- CLOCKS_CLK_SYS_CTRL_AUXSRC values ------------------------------------ */

#define CLOCKS_CLK_SYS_CTRL_AUXSRC(src)                 ((src) << 5)
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_MASK                 (0x7 << 5)
/** @defgroup clocks_clk_sys_ctrl_auxsrc Selects the auxiliary clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_SYS       0x0
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_PLL_USB       0x1
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_ROSC_CLKSRC          0x2
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_XOSC_CLKSRC          0x3
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_GPIN0         0x4
#define CLOCKS_CLK_SYS_CTRL_AUXSRC_CLKSRC_GPIN1         0x5
/**@}*/

/* --- CLOCKS_CLK_SYS_DIV_FRAC values --------------------------------------- */

#define CLOCKS_CLK_SYS_DIV_FRAC(frac)                   (frac)
#define CLOCKS_CLK_SYS_DIV_FRAC_MASK                    0xff

/* --- CLOCKS_CLK_SYS_DIV_INT values ---------------------------------------- */

#define CLOCKS_CLK_SYS_DIV_INT(int)                     ((int) << 8)
#define CLOCKS_CLK_SYS_DIV_INT_MASK                     (0xffffff << 8)

/* --- CLOCKS_CLK_SYS_SELECTED values --------------------------------------- */

#define CLOCKS_CLK_SYS_SELECTED_MASK                    0xffffffff

/* --- CLOCKS_CLK_PERI_CTRL_AUXSRC values ----------------------------------- */

#define CLOCKS_CLK_PERI_CTRL_AUXSRC(src)                ((src) << 5)
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_MASK                (0x7 << 5)
/** @defgroup clocks_clk_peri_ctrl_auxsrc Selects the auxiliary clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLK_SYS             0x0
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_SYS      0x1
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_PLL_USB      0x2
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_ROSC_CLKSRC_PH      0x3
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_XOSC_CLKSRC         0x4
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_GPIN0        0x5
#define CLOCKS_CLK_PERI_CTRL_AUXSRC_CLKSRC_GPIN1        0x6
/**@}*/

/* --- CLOCKS_CLK_PERI_CTRL_KILL values ------------------------------------- */

#define CLOCKS_CLK_PERI_CTRL_KILL                       (0x1 << 10)

/* --- CLOCKS_CLK_PERI_CTRL_ENABLE values ----------------------------------- */

#define CLOCKS_CLK_PERI_CTRL_ENABLE                     (0x1 << 11)

/* --- CLOCKS_CLK_PERI_SELECTED values -------------------------------------- */

#define CLOCKS_CLK_PERI_SELECTED_MASK                   0xffffffff

/* --- CLOCKS_CLK_USB_CTRL_AUXSRC values ------------------------------------ */

#define CLOCKS_CLK_USB_CTRL_AUXSRC(src)                 ((src) << 5)
#define CLOCKS_CLK_USB_CTRL_AUXSRC_MASK                 (0x7 << 5)
/** @defgroup clocks_clk_usb_ctrl_auxsrc Selects the auxiliary clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_USB       0x0
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_PLL_SYS       0x1
#define CLOCKS_CLK_USB_CTRL_AUXSRC_ROSC_CLKSRC_PH       0x2
#define CLOCKS_CLK_USB_CTRL_AUXSRC_XOSC_CLKSRC          0x3
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_GPIN0         0x4
#define CLOCKS_CLK_USB_CTRL_AUXSRC_CLKSRC_GPIN1         0x5
/**@}*/

/* --- CLOCKS_CLK_USB_CTRL_KILL values -------------------------------------- */

#define CLOCKS_CLK_USB_CTRL_KILL                        (0x1 << 10)

/* --- CLOCKS_CLK_USB_CTRL_ENABLE values ------------------------------------ */

#define CLOCKS_CLK_USB_CTRL_ENABLE                      (0x1 << 11)

/* --- CLOCKS_CLK_USB_CTRL_PHASE values ------------------------------------- */

#define CLOCKS_CLK_USB_CTRL_PHASE(phase)                (phase)
#define CLOCKS_CLK_USB_CTRL_PHASE_MASK                  (0x3 << 16)

/* --- CLOCKS_CLK_USB_CTRL_NUDGE values ------------------------------------- */

#define CLOCKS_CLK_USB_CTRL_NUDGE                       (0x1 << 20)

/* --- CLOCKS_CLK_USB_DIV_INT values ---------------------------------------- */

#define CLOCKS_CLK_USB_DIV_INT(int)                     ((int) << 8)
#define CLOCKS_CLK_USB_DIV_INT_MASK                     (0x3 << 8)

/* --- CLOCKS_CLK_USB_SELECTED values --------------------------------------- */

#define CLOCKS_CLK_USB_SELECTED_MASK                    0xffffffff

/* --- CLOCKS_CLK_ADC_CTRL_AUXSRC values ------------------------------------ */

#define CLOCKS_CLK_ADC_CTRL_AUXSRC(src)                 ((src) << 5)
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_MASK                 (0x7 << 5)
/** @defgroup clocks_clk_adc_ctrl_auxsrc Selects the auxiliary clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_USB       0x0
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_PLL_SYS       0x1
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_ROSC_CLKSRC_PH       0x2
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_XOSC_CLKSRC          0x3
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_GPIN0         0x4
#define CLOCKS_CLK_ADC_CTRL_AUXSRC_CLKSRC_GPIN1         0x5
/**@}*/

/* --- CLOCKS_CLK_ADC_CTRL_KILL values -------------------------------------- */

#define CLOCKS_CLK_ADC_CTRL_KILL                        (0x1 << 10)

/* --- CLOCKS_CLK_ADC_CTRL_ENABLE values ------------------------------------ */

#define CLOCKS_CLK_ADC_CTRL_ENABLE                      (0x1 << 11)

/* --- CLOCKS_CLK_ADC_CTRL_PHASE values ------------------------------------- */

#define CLOCKS_CLK_ADC_CTRL_PHASE(phase)                (phase)
#define CLOCKS_CLK_ADC_CTRL_PHASE_MASK                  (0x3 << 16)

/* --- CLOCKS_CLK_ADC_CTRL_NUDGE values ------------------------------------- */

#define CLOCKS_CLK_ADC_CTRL_NUDGE                       (0x1 << 20)

/* --- CLOCKS_CLK_ADC_DIV_INT values ---------------------------------------- */

#define CLOCKS_CLK_ADC_DIV_INT(int)                     ((int) << 8)
#define CLOCKS_CLK_ADC_DIV_INT_MASK                     (0x3 << 8)

/* --- CLOCKS_CLK_ADC_SELECTED values --------------------------------------- */

#define CLOCKS_CLK_ADC_SELECTED_MASK                    0xffffffff

/* --- CLOCKS_CLK_RTC_CTRL_AUXSRC values ------------------------------------ */

#define CLOCKS_CLK_RTC_CTRL_AUXSRC(src)                 ((src) << 5)
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_MASK                 (0x7 << 5)
/** @defgroup clocks_clk_rtc_ctrl_auxsrc Selects the auxiliary clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_PLL_USB       0x0
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_PLL_SYS       0x1
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_ROSC_CLKSRC_PH       0x2
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_XOSC_CLKSRC          0x3
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_GPIN0         0x4
#define CLOCKS_CLK_RTC_CTRL_AUXSRC_CLKSRC_GPIN1         0x5
/**@}*/

/* --- CLOCKS_CLK_RTC_CTRL_KILL values -------------------------------------- */

#define CLOCKS_CLK_RTC_CTRL_KILL                        (0x1 << 10)

/* --- CLOCKS_CLK_RTC_CTRL_ENABLE values ------------------------------------ */

#define CLOCKS_CLK_RTC_CTRL_ENABLE                      (0x1 << 11)

/* --- CLOCKS_CLK_RTC_CTRL_PHASE values ------------------------------------- */

#define CLOCKS_CLK_RTC_CTRL_PHASE(phase)                (phase)
#define CLOCKS_CLK_RTC_CTRL_PHASE_MASK                  (0x3 << 16)

/* --- CLOCKS_CLK_RTC_CTRL_NUDGE values ------------------------------------- */

#define CLOCKS_CLK_RTC_CTRL_NUDGE                       (0x1 << 20)

/* --- CLOCKS_CLK_RTC_DIV_FRAC values --------------------------------------- */

#define CLOCKS_CLK_RTC_DIV_FRAC(frac)                   (frac)
#define CLOCKS_CLK_RTC_DIV_FRAC_MASK                    0xff

/* --- CLOCKS_CLK_RTC_DIV_INT values ---------------------------------------- */

#define CLOCKS_CLK_RTC_DIV_INT(int)                     ((int) << 8)
#define CLOCKS_CLK_RTC_DIV_INT_MASK                     (0xffffff << 8)

/* --- CLOCKS_CLK_RTC_SELECTED values --------------------------------------- */

#define CLOCKS_CLK_RTC_SELECTED_MASK                    0xffffffff

/* --- CLOCKS_CLK_RESUS_CTRL_TIMEOUT values --------------------------------- */

#define CLOCKS_CLK_RESUS_CTRL_TIMEOUT(timeout)          (timeout)
#define CLOCKS_CLK_RESUS_CTRL_TIMEOUT_MASK              (0xff << 0)

/* --- CLOCKS_CLK_RESUS_CTRL_ENABLE values ---------------------------------- */

#define CLOCKS_CLK_RESUS_CTRL_ENABLE                    (0x1 << 8)

/* --- CLOCKS_CLK_RESUS_CTRL_FRCE values ------------------------------------ */

#define CLOCKS_CLK_RESUS_CTRL_FRCE                      (0x1 << 12)

/* --- CLOCKS_CLK_RESUS_CTRL_CLEAR values ----------------------------------- */

#define CLOCKS_CLK_RESUS_CTRL_CLEAR                     (0x1 << 16)

/* --- CLOCKS_CLK_RESUS_STATUS values --------------------------------------- */

#define CLOCKS_CLK_RESUS_STATUS_RESUSSED                (0x1 << 0)

/* --- CLOCKS_FC0_REF_KHZ values -------------------------------------------- */

#define CLOCKS_FC0_REF_KHZ_MASK                         0xfffff

/* --- CLOCKS_FC0_MIN_KHZ values -------------------------------------------- */

#define CLOCKS_FC0_MIN_KHZ_MASK                         0x1ffffff

/* --- CLOCKS_FC0_MAX_KHZ values -------------------------------------------- */

#define CLOCKS_FC0_MAX_KHZ_MASK                         0x1ffffff

/* --- CLOCKS_FC0_INTERVAL values ------------------------------------------- */

#define CLOCKS_FC0_INTERVAL_MASK                        0x7

/* --- CLOCKS_FC0_SRC values ------------------------------------------------ */

#define CLOCKS_FC0_SRC_MASK                             (0xff << 0)
/** @defgroup clocks_fc0_src Selects the auxiliary clock source
@ingroup clocks_defines
@{*/
#define CLOCKS_FC0_SRC_NULL                             0x00
#define CLOCKS_FC0_SRC_PLL_SYS_CLKSRC_PRIMARY           0x01
#define CLOCKS_FC0_SRC_PLL_USB_CLKSRC_PRIMARY           0x02
#define CLOCKS_FC0_SRC_ROSC_CLKSRC                      0x03
#define CLOCKS_FC0_SRC_ROSC_CLKSRC_PH                   0x04
#define CLOCKS_FC0_SRC_XOSC_CLKSRC                      0x05
#define CLOCKS_FC0_SRC_CLKSRC_GPIN0                     0x06
#define CLOCKS_FC0_SRC_CLKSRC_GPIN1                     0x07
#define CLOCKS_FC0_SRC_CLK_REF                          0x08
#define CLOCKS_FC0_SRC_CLK_SYS                          0x09
#define CLOCKS_FC0_SRC_CLK_PERI                         0x0a
#define CLOCKS_FC0_SRC_CLK_USB                          0x0b
#define CLOCKS_FC0_SRC_CLK_ADC                          0x0c
#define CLOCKS_FC0_SRC_CLK_RTC                          0x0d
/**@}*/

/* --- CLOCKS_FC0_STATUS values --------------------------------------------- */

#define CLOCKS_FC0_STATUS_PASS                          (0x1 << 0)
#define CLOCKS_FC0_STATUS_DONE                          (0x1 << 4)
#define CLOCKS_FC0_STATUS_RUNNING                       (0x1 << 8)
#define CLOCKS_FC0_STATUS_WAITING                       (0x1 << 12)
#define CLOCKS_FC0_STATUS_FAIL                          (0x1 << 16)
#define CLOCKS_FC0_STATUS_SLOW                          (0x1 << 20)
#define CLOCKS_FC0_STATUS_FAST                          (0x1 << 24)
#define CLOCKS_FC0_STATUS_DIED                          (0x1 << 28)

/* --- CLOCKS_FC0_RESULT values --------------------------------------------- */

#define CLOCKS_FC0_RESULT_FRAC                          (0x1f << 0)
#define CLOCKS_FC0_RESULT_KHZ                           (0x1ffffff << 5)

/* --- CLOCKS_WAKE_EN0 values ----------------------------------------------- */

#define CLOCKS_WAKE_EN0_CLK_SYS_CLOCKS                  (0x1 << 0)
#define CLOCKS_WAKE_EN0_CLK_ADC_ADC                     (0x1 << 1)
#define CLOCKS_WAKE_EN0_CLK_SYS_ADC                     (0x1 << 2)
#define CLOCKS_WAKE_EN0_CLK_SYS_BUSCTRL                 (0x1 << 3)
#define CLOCKS_WAKE_EN0_CLK_SYS_BUSFABRIC               (0x1 << 4)
#define CLOCKS_WAKE_EN0_CLK_SYS_DMA                     (0x1 << 5)
#define CLOCKS_WAKE_EN0_CLK_SYS_I2C0                    (0x1 << 6)
#define CLOCKS_WAKE_EN0_CLK_SYS_I2C1                    (0x1 << 7)
#define CLOCKS_WAKE_EN0_CLK_SYS_IO                      (0x1 << 8)
#define CLOCKS_WAKE_EN0_CLK_SYS_JTAG                    (0x1 << 9)
#define CLOCKS_WAKE_EN0_CLK_SYS_VREG_AND_CHIP_RESET     (0x1 << 10)
#define CLOCKS_WAKE_EN0_CLK_SYS_PADS                    (0x1 << 11)
#define CLOCKS_WAKE_EN0_CLK_SYS_PIO0                    (0x1 << 12)
#define CLOCKS_WAKE_EN0_CLK_SYS_PIO1                    (0x1 << 13)
#define CLOCKS_WAKE_EN0_CLK_SYS_PLL_SYS                 (0x1 << 14)
#define CLOCKS_WAKE_EN0_CLK_SYS_PLL_USB                 (0x1 << 15)
#define CLOCKS_WAKE_EN0_CLK_SYS_PSM                     (0x1 << 16)
#define CLOCKS_WAKE_EN0_CLK_SYS_PWM                     (0x1 << 17)
#define CLOCKS_WAKE_EN0_CLK_SYS_RESETS                  (0x1 << 18)
#define CLOCKS_WAKE_EN0_CLK_SYS_ROM                     (0x1 << 19)
#define CLOCKS_WAKE_EN0_CLK_SYS_ROSC                    (0x1 << 20)
#define CLOCKS_WAKE_EN0_CLK_RTC_RTC                     (0x1 << 21)
#define CLOCKS_WAKE_EN0_CLK_SYS_RTC                     (0x1 << 22)
#define CLOCKS_WAKE_EN0_CLK_SYS_SIO                     (0x1 << 23)
#define CLOCKS_WAKE_EN0_CLK_PERI_SPI0                   (0x1 << 24)
#define CLOCKS_WAKE_EN0_CLK_SYS_SPI0                    (0x1 << 25)
#define CLOCKS_WAKE_EN0_CLK_PERI_SPI1                   (0x1 << 26)
#define CLOCKS_WAKE_EN0_CLK_SYS_SPI1                    (0x1 << 27)
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM0                   (0x1 << 28)
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM1                   (0x1 << 29)
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM2                   (0x1 << 30)
#define CLOCKS_WAKE_EN0_CLK_SYS_SRAM3                   (0x1 << 31)

/* --- CLOCKS_WAKE_EN1 values ----------------------------------------------- */

#define CLOCKS_WAKE_EN1_CLK_SYS_SRAM4                   (0x1 << 0)
#define CLOCKS_WAKE_EN1_CLK_SYS_SRAM5                   (0x1 << 1)
#define CLOCKS_WAKE_EN1_CLK_SYS_SYSCFG                  (0x1 << 2)
#define CLOCKS_WAKE_EN1_CLK_SYS_SYSINFO                 (0x1 << 3)
#define CLOCKS_WAKE_EN1_CLK_SYS_TBMAN                   (0x1 << 4)
#define CLOCKS_WAKE_EN1_CLK_SYS_TIMER                   (0x1 << 5)
#define CLOCKS_WAKE_EN1_CLK_PERI_UART0                  (0x1 << 6)
#define CLOCKS_WAKE_EN1_CLK_SYS_UART0                   (0x1 << 7)
#define CLOCKS_WAKE_EN1_CLK_PERI_UART1                  (0x1 << 8)
#define CLOCKS_WAKE_EN1_CLK_SYS_UART1                   (0x1 << 9)
#define CLOCKS_WAKE_EN1_CLK_SYS_USBCTRL                 (0x1 << 10)
#define CLOCKS_WAKE_EN1_CLK_USB_USBCTRL                 (0x1 << 11)
#define CLOCKS_WAKE_EN1_CLK_SYS_WATCHDOG                (0x1 << 12)
#define CLOCKS_WAKE_EN1_CLK_SYS_XIP                     (0x1 << 13)
#define CLOCKS_WAKE_EN1_CLK_SYS_XOSC                    (0x1 << 14)

/* --- CLOCKS_SLEEP_EN0 values ---------------------------------------------- */

#define CLOCKS_SLEEP_EN0_CLK_SYS_CLOCKS                 (0x1 << 0)
#define CLOCKS_SLEEP_EN0_CLK_ADC_ADC                    (0x1 << 1)
#define CLOCKS_SLEEP_EN0_CLK_SYS_ADC                    (0x1 << 2)
#define CLOCKS_SLEEP_EN0_CLK_SYS_BUSCTRL                (0x1 << 3)
#define CLOCKS_SLEEP_EN0_CLK_SYS_BUSFABRIC              (0x1 << 4)
#define CLOCKS_SLEEP_EN0_CLK_SYS_DMA                    (0x1 << 5)
#define CLOCKS_SLEEP_EN0_CLK_SYS_I2C0                   (0x1 << 6)
#define CLOCKS_SLEEP_EN0_CLK_SYS_I2C1                   (0x1 << 7)
#define CLOCKS_SLEEP_EN0_CLK_SYS_IO                     (0x1 << 8)
#define CLOCKS_SLEEP_EN0_CLK_SYS_JTAG                   (0x1 << 9)
#define CLOCKS_SLEEP_EN0_CLK_SYS_VREG_AND_CHIP_RESET    (0x1 << 10)
#define CLOCKS_SLEEP_EN0_CLK_SYS_PADS                   (0x1 << 11)
#define CLOCKS_SLEEP_EN0_CLK_SYS_PIO0                   (0x1 << 12)
#define CLOCKS_SLEEP_EN0_CLK_SYS_PIO1                   (0x1 << 13)
#define CLOCKS_SLEEP_EN0_CLK_SYS_PLL_SYS                (0x1 << 14)
#define CLOCKS_SLEEP_EN0_CLK_SYS_PLL_USB                (0x1 << 15)
#define CLOCKS_SLEEP_EN0_CLK_SYS_PSM                    (0x1 << 16)
#define CLOCKS_SLEEP_EN0_CLK_SYS_PWM                    (0x1 << 17)
#define CLOCKS_SLEEP_EN0_CLK_SYS_RESETS                 (0x1 << 18)
#define CLOCKS_SLEEP_EN0_CLK_SYS_ROM                    (0x1 << 19)
#define CLOCKS_SLEEP_EN0_CLK_SYS_ROSC                   (0x1 << 20)
#define CLOCKS_SLEEP_EN0_CLK_RTC_RTC                    (0x1 << 21)
#define CLOCKS_SLEEP_EN0_CLK_SYS_RTC                    (0x1 << 22)
#define CLOCKS_SLEEP_EN0_CLK_SYS_SIO                    (0x1 << 23)
#define CLOCKS_SLEEP_EN0_CLK_PERI_SPI0                  (0x1 << 24)
#define CLOCKS_SLEEP_EN0_CLK_SYS_SPI0                   (0x1 << 25)
#define CLOCKS_SLEEP_EN0_CLK_PERI_SPI1                  (0x1 << 26)
#define CLOCKS_SLEEP_EN0_CLK_SYS_SPI1                   (0x1 << 27)
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM0                  (0x1 << 28)
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM1                  (0x1 << 29)
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM2                  (0x1 << 30)
#define CLOCKS_SLEEP_EN0_CLK_SYS_SRAM3                  (0x1 << 31)

/* --- CLOCKS_SLEEP_EN1 values ---------------------------------------------- */

#define CLOCKS_SLEEP_EN1_CLK_SYS_SRAM4                  (0x1 << 0)
#define CLOCKS_SLEEP_EN1_CLK_SYS_SRAM5                  (0x1 << 1)
#define CLOCKS_SLEEP_EN1_CLK_SYS_SYSCFG                 (0x1 << 2)
#define CLOCKS_SLEEP_EN1_CLK_SYS_SYSINFO                (0x1 << 3)
#define CLOCKS_SLEEP_EN1_CLK_SYS_TBMAN                  (0x1 << 4)
#define CLOCKS_SLEEP_EN1_CLK_SYS_TIMER                  (0x1 << 5)
#define CLOCKS_SLEEP_EN1_CLK_PERI_UART0                 (0x1 << 6)
#define CLOCKS_SLEEP_EN1_CLK_SYS_UART0                  (0x1 << 7)
#define CLOCKS_SLEEP_EN1_CLK_PERI_UART1                 (0x1 << 8)
#define CLOCKS_SLEEP_EN1_CLK_SYS_UART1                  (0x1 << 9)
#define CLOCKS_SLEEP_EN1_CLK_SYS_USBCTRL                (0x1 << 10)
#define CLOCKS_SLEEP_EN1_CLK_USB_USBCTRL                (0x1 << 11)
#define CLOCKS_SLEEP_EN1_CLK_SYS_WATCHDOG               (0x1 << 12)
#define CLOCKS_SLEEP_EN1_CLK_SYS_XIP                    (0x1 << 13)
#define CLOCKS_SLEEP_EN1_CLK_SYS_XOSC                   (0x1 << 14)

/* --- CLOCKS_ENABLED0 values ----------------------------------------------- */

#define CLOCKS_ENABLED0_CLK_SYS_CLOCKS                  (0x1 << 0)
#define CLOCKS_ENABLED0_CLK_ADC_ADC                     (0x1 << 1)
#define CLOCKS_ENABLED0_CLK_SYS_ADC                     (0x1 << 2)
#define CLOCKS_ENABLED0_CLK_SYS_BUSCTRL                 (0x1 << 3)
#define CLOCKS_ENABLED0_CLK_SYS_BUSFABRIC               (0x1 << 4)
#define CLOCKS_ENABLED0_CLK_SYS_DMA                     (0x1 << 5)
#define CLOCKS_ENABLED0_CLK_SYS_I2C0                    (0x1 << 6)
#define CLOCKS_ENABLED0_CLK_SYS_I2C1                    (0x1 << 7)
#define CLOCKS_ENABLED0_CLK_SYS_IO                      (0x1 << 8)
#define CLOCKS_ENABLED0_CLK_SYS_JTAG                    (0x1 << 9)
#define CLOCKS_ENABLED0_CLK_SYS_VREG_AND_CHIP_RESET     (0x1 << 10)
#define CLOCKS_ENABLED0_CLK_SYS_PADS                    (0x1 << 11)
#define CLOCKS_ENABLED0_CLK_SYS_PIO0                    (0x1 << 12)
#define CLOCKS_ENABLED0_CLK_SYS_PIO1                    (0x1 << 13)
#define CLOCKS_ENABLED0_CLK_SYS_PLL_SYS                 (0x1 << 14)
#define CLOCKS_ENABLED0_CLK_SYS_PLL_USB                 (0x1 << 15)
#define CLOCKS_ENABLED0_CLK_SYS_PSM                     (0x1 << 16)
#define CLOCKS_ENABLED0_CLK_SYS_PWM                     (0x1 << 17)
#define CLOCKS_ENABLED0_CLK_SYS_RESETS                  (0x1 << 18)
#define CLOCKS_ENABLED0_CLK_SYS_ROM                     (0x1 << 19)
#define CLOCKS_ENABLED0_CLK_SYS_ROSC                    (0x1 << 20)
#define CLOCKS_ENABLED0_CLK_RTC_RTC                     (0x1 << 21)
#define CLOCKS_ENABLED0_CLK_SYS_RTC                     (0x1 << 22)
#define CLOCKS_ENABLED0_CLK_SYS_SIO                     (0x1 << 23)
#define CLOCKS_ENABLED0_CLK_PERI_SPI0                   (0x1 << 24)
#define CLOCKS_ENABLED0_CLK_SYS_SPI0                    (0x1 << 25)
#define CLOCKS_ENABLED0_CLK_PERI_SPI1                   (0x1 << 26)
#define CLOCKS_ENABLED0_CLK_SYS_SPI1                    (0x1 << 27)
#define CLOCKS_ENABLED0_CLK_SYS_SRAM0                   (0x1 << 28)
#define CLOCKS_ENABLED0_CLK_SYS_SRAM1                   (0x1 << 29)
#define CLOCKS_ENABLED0_CLK_SYS_SRAM2                   (0x1 << 30)
#define CLOCKS_ENABLED0_CLK_SYS_SRAM3                   (0x1 << 31)

/* --- CLOCKS_ENABLED1 values ----------------------------------------------- */

#define CLOCKS_ENABLED1_CLK_SYS_SRAM4                   (0x1 << 0)
#define CLOCKS_ENABLED1_CLK_SYS_SRAM5                   (0x1 << 1)
#define CLOCKS_ENABLED1_CLK_SYS_SYSCFG                  (0x1 << 2)
#define CLOCKS_ENABLED1_CLK_SYS_SYSINFO                 (0x1 << 3)
#define CLOCKS_ENABLED1_CLK_SYS_TBMAN                   (0x1 << 4)
#define CLOCKS_ENABLED1_CLK_SYS_TIMER                   (0x1 << 5)
#define CLOCKS_ENABLED1_CLK_PERI_UART0                  (0x1 << 6)
#define CLOCKS_ENABLED1_CLK_SYS_UART0                   (0x1 << 7)
#define CLOCKS_ENABLED1_CLK_PERI_UART1                  (0x1 << 8)
#define CLOCKS_ENABLED1_CLK_SYS_UART1                   (0x1 << 9)
#define CLOCKS_ENABLED1_CLK_SYS_USBCTRL                 (0x1 << 10)
#define CLOCKS_ENABLED1_CLK_USB_USBCTRL                 (0x1 << 11)
#define CLOCKS_ENABLED1_CLK_SYS_WATCHDOG                (0x1 << 12)
#define CLOCKS_ENABLED1_CLK_SYS_XIP                     (0x1 << 13)
#define CLOCKS_ENABLED1_CLK_SYS_XOSC                    (0x1 << 14)

/* --- CLOCKS_INTR values --------------------------------------------------- */

#define CLOCKS_INTR_CLK_SYS_RESUS                       (0x1 << 0)

/* --- CLOCKS_INTE values --------------------------------------------------- */

#define CLOCKS_INTE_CLK_SYS_RESUS                       (0x1 << 0)

/* --- CLOCKS_INTF values --------------------------------------------------- */

#define CLOCKS_INTF_CLK_SYS_RESUS                       (0x1 << 0)

/* --- CLOCKS_INTS values --------------------------------------------------- */

#define CLOCKS_INTS_CLK_SYS_RESUS                       (0x1 << 0)

/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

bool clock_configure(uint8_t clk_index, uint32_t src, uint32_t auxsrc, uint32_t src_freq, uint32_t freq);
void clocks_init(void);

/** @} */
END_DECLS

#endif

/**@}*/

