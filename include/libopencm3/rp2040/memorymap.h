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

#ifndef RP2040_MEMORYMAP_H
#define RP2040_MEMORYMAP_H

#include <libopencm3/cm3/common.h>

#define ROM_BASE                    (0x00000000U)
#define XIP_BASE                    (0x10000000U)
#define XIP_MAIN_BASE               (0x10000000U)
#define XIP_NOALLOC_BASE            (0x11000000U)
#define XIP_NOCACHE_BASE            (0x12000000U)
#define XIP_NOCACHE_NOALLOC_BASE    (0x13000000U)
#define XIP_CTRL_BASE               (0x14000000U)
#define XIP_SRAM_BASE               (0x15000000U)
#define XIP_SRAM_END                (0x15004000U)
#define XIP_SSI_BASE                (0x18000000U)
#define SRAM_BASE                   (0x20000000U)
#define SRAM_STRIPED_BASE           (0x20000000U)
#define SRAM_STRIPED_END            (0x20040000U)
#define SRAM4_BASE                  (0x20040000U)
#define SRAM5_BASE                  (0x20041000U)
#define SRAM_END                    (0x20042000U)
#define SRAM0_BASE                  (0x21000000U)
#define SRAM1_BASE                  (0x21010000U)
#define SRAM2_BASE                  (0x21020000U)
#define SRAM3_BASE                  (0x21030000U)
#define SYSINFO_BASE                (0x40000000U)
#define SYSCFG_BASE                 (0x40004000U)
#define CLOCKS_BASE                 (0x40008000U)
#define RESETS_BASE                 (0x4000c000U)
#define PSM_BASE                    (0x40010000U)
#define IO_BANK0_BASE               (0x40014000U)
#define IO_QSPI_BASE                (0x40018000U)
#define PADS_BANK0_BASE             (0x4001c000U)
#define PADS_QSPI_BASE              (0x40020000U)
#define XOSC_BASE                   (0x40024000U)
#define PLL_SYS_BASE                (0x40028000U)
#define PLL_USB_BASE                (0x4002c000U)
#define BUSCTRL_BASE                (0x40030000U)
#define UART0_BASE                  (0x40034000U)
#define UART1_BASE                  (0x40038000U)
#define SPI0_BASE                   (0x4003c000U)
#define SPI1_BASE                   (0x40040000U)
#define I2C0_BASE                   (0x40044000U)
#define I2C1_BASE                   (0x40048000U)
#define ADC_BASE                    (0x4004c000U)
#define PWM_BASE                    (0x40050000U)
#define TIMER_BASE                  (0x40054000U)
#define WATCHDOG_BASE               (0x40058000U)
#define RTC_BASE                    (0x4005c000U)
#define ROSC_BASE                   (0x40060000U)
#define VREG_AND_CHIP_RESET_BASE    (0x40064000U)
#define TBMAN_BASE                  (0x4006c000U)
#define DMA_BASE                    (0x50000000U)
#define USBCTRL_DPRAM_BASE          (0x50100000U)
#define USBCTRL_BASE                (0x50100000U)
#define USBCTRL_REGS_BASE           (0x50110000U)
#define PIO0_BASE                   (0x50200000U)
#define PIO1_BASE                   (0x50300000U)
#define XIP_AUX_BASE                (0x50400000U)
#define SIO_BASE                    (0xd0000000U)
#define PPB_BASE                    (0xe0000000U)

#endif
