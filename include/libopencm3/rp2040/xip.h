/** @defgroup xip_defines XIP SSI Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 Synchronous Serial Interface</b>
 *
 * @version 1.0.0
 * 
 * @author @htmlonly &copy; @endhtmlonly 2023
 * James Turton <james.turton@gmx.com>
 * 
 * @date 26 April 2023
 *
 * LGPL License Terms @ref lgpl_license
 *  */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2023 James Turton <james.turton@gmx.com>
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

#ifndef RP2040_XIP_H
#define RP2040_XIP_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

/* =============================================================================
 * XIP SSI registers
 * ---------------------------------------------------------------------------*/

#define XIP_SSI_CTRLR0          MMIO32((XIP_SSI_BASE) + 0x00)
#define XIP_SSI_CTRLR1          MMIO32((XIP_SSI_BASE) + 0x04)
#define XIP_SSI_SSIENR          MMIO32((XIP_SSI_BASE) + 0x08)
#define XIP_SSI_MWCR            MMIO32((XIP_SSI_BASE) + 0x0c)
#define XIP_SSI_SER             MMIO32((XIP_SSI_BASE) + 0x10)
#define XIP_SSI_BAUDR           MMIO32((XIP_SSI_BASE) + 0x14)
#define XIP_SSI_TXFTLR          MMIO32((XIP_SSI_BASE) + 0x18)
#define XIP_SSI_RXFTLR          MMIO32((XIP_SSI_BASE) + 0x1c)
#define XIP_SSI_TXFLR           MMIO32((XIP_SSI_BASE) + 0x20)
#define XIP_SSI_RXFLR           MMIO32((XIP_SSI_BASE) + 0x24)
#define XIP_SSI_SR              MMIO32((XIP_SSI_BASE) + 0x28)
#define XIP_SSI_IMR             MMIO32((XIP_SSI_BASE) + 0x2c)
#define XIP_SSI_ISR             MMIO32((XIP_SSI_BASE) + 0x30)
#define XIP_SSI_RISR            MMIO32((XIP_SSI_BASE) + 0x34)
#define XIP_SSI_TXOICR          MMIO32((XIP_SSI_BASE) + 0x38)
#define XIP_SSI_RXOICR          MMIO32((XIP_SSI_BASE) + 0x3c)
#define XIP_SSI_RXUICR          MMIO32((XIP_SSI_BASE) + 0x40)
#define XIP_SSI_MSTICR          MMIO32((XIP_SSI_BASE) + 0x44)
#define XIP_SSI_ICR             MMIO32((XIP_SSI_BASE) + 0x48)
#define XIP_SSI_DMACR           MMIO32((XIP_SSI_BASE) + 0x4c)
#define XIP_SSI_DMATDLR         MMIO32((XIP_SSI_BASE) + 0x50)
#define XIP_SSI_DMARDLR         MMIO32((XIP_SSI_BASE) + 0x54)
#define XIP_SSI_IDR             MMIO32((XIP_SSI_BASE) + 0x58)
#define XIP_SSI_SSI_VERSION_ID  MMIO32((XIP_SSI_BASE) + 0x5c)
#define XIP_SSI_DR0             MMIO32((XIP_SSI_BASE) + 0x60)
#define XIP_SSI_RX_SAMPLE_DLY   MMIO32((XIP_SSI_BASE) + 0xf0)
#define XIP_SSI_SPI_CTRLR0      MMIO32((XIP_SSI_BASE) + 0xf4)
#define XIP_SSI_TXD_DRIVE_EDGE  MMIO32((XIP_SSI_BASE) + 0xf8)


/* --- XIP_SSI_CTRLR0 values ------------------------------------------------ */

#define XIP_SSI_CTRLR0_SSTE                             (0x1 << 24)
#define XIP_SSI_CTRLR0_SPI_FRF(format)                  ((format) << 21)
#define XIP_SSI_CTRLR0_SPI_FRF_MASK                     (0x3 << 21)
#define XIP_SSI_CTRLR0_SPI_FRF_SINGLE                   0x0
#define XIP_SSI_CTRLR0_SPI_FRF_DUAL                     0x1
#define XIP_SSI_CTRLR0_SPI_FRF_QUAD                     0x2
#define XIP_SSI_CTRLR0_DFS_32(size)                     ((size) << 16)
#define XIP_SSI_CTRLR0_DFS_32_MASK                      (0x1f << 16)
#define XIP_SSI_CTRLR0_CFS(size)                        ((size) << 12)
#define XIP_SSI_CTRLR0_CFS_MASK                         (0x1f << 12)
#define XIP_SSI_CTRLR0_SRL                              (0x1 << 11)
#define XIP_SSI_CTRLR0_SLV_OE                           (0x1 << 10)
#define XIP_SSI_CTRLR0_TMOD(mode)                       ((mode) << 8)
#define XIP_SSI_CTRLR0_TMOD_MASK                        (0x3 << 8)
#define XIP_SSI_CTRLR0_TMOD_TX_RX                       0x0
#define XIP_SSI_CTRLR0_TMOD_TX_ONLY                     0x1
#define XIP_SSI_CTRLR0_TMOD_RX_ONLY                     0x2
#define XIP_SSI_CTRLR0_TMOD_EEPROM                      0x3
#define XIP_SSI_CTRLR0_SCPOL                            (0x1 << 7)
#define XIP_SSI_CTRLR0_SCPH                             (0x1 << 6)
#define XIP_SSI_CTRLR0_FRF(size)                        ((size) << 4)
#define XIP_SSI_CTRLR0_FRF_MASK                         (0x3 << 4)
#define XIP_SSI_CTRLR0_DFS(size)                        ((size) << 0)
#define XIP_SSI_CTRLR0_DFS_MASK                         (0xf << 0)

/* --- XIP_SSI_CTRLR1 values ------------------------------------------------ */

#define XIP_SSI_CTRLR1_NDF(num)                         ((num) << 0)
#define XIP_SSI_CTRLR1_NDF_MASK                         (0xffff << 0)

/* --- XIP_SSI_SSIENR values ------------------------------------------------ */

#define XIP_SSI_SSIENR_EN                               (0x1 << 0)

/* --- XIP_SSI_MWCR values -------------------------------------------------- */

#define XIP_SSI_MWCR_MHS                                (0x1 << 2)
#define XIP_SSI_MWCR_MDD                                (0x1 << 1)
#define XIP_SSI_MWCR_MWMOD                              (0x1 << 0)

/* --- XIP_SSI_SER values --------------------------------------------------- */

#define XIP_SSI_SER_SEL                                 (0x1 << 0)

/* --- XIP_SSI_BAUDR values ------------------------------------------------- */

#define XIP_SSI_BAUDR_SCKDV(div)                        ((div) << 0)
#define XIP_SSI_BAUDR_SCKDV_MASK                        (0xffff << 0)

/* --- XIP_SSI_TXFTLR values ------------------------------------------------ */

#define XIP_SSI_TXFTLR_TFT(threshold)                   ((threshold) << 0)
#define XIP_SSI_TXFTLR_TFT_MASK                         (0xff << 0)

/* --- XIP_SSI_RXFTLR values ------------------------------------------------ */

#define XIP_SSI_RXFTLR_RFT(threshold)                   ((threshold) << 0)
#define XIP_SSI_RXFTLR_RFT_MASK                         (0xff << 0)

/* --- XIP_SSI_TXFLR values ------------------------------------------------- */

#define XIP_SSI_TXFLR_TFTFL(level)                      ((level) << 0)
#define XIP_SSI_TXFLR_TFTFL_MASK                        (0xff << 0)

/* --- XIP_SSI_RXFLR values ------------------------------------------------- */

#define XIP_SSI_RXFLR_RXTFL(level)                      ((level) << 0)
#define XIP_SSI_RXFLR_RXTFL_MASK                        (0xff << 0)

/* --- XIP_SSI_SR values ---------------------------------------------------- */

#define XIP_SSI_SR_DCOL                                 (0x1 << 6)
#define XIP_SSI_SR_TXE                                  (0x1 << 5)
#define XIP_SSI_SR_RFF                                  (0x1 << 4)
#define XIP_SSI_SR_RFNE                                 (0x1 << 3)
#define XIP_SSI_SR_TFE                                  (0x1 << 2)
#define XIP_SSI_SR_TFNF                                 (0x1 << 1)
#define XIP_SSI_SR_BUSY                                 (0x1 << 0)

/* --- XIP_SSI_IMR values --------------------------------------------------- */

#define XIP_SSI_IMR_MSTIM                               (0x1 << 5)
#define XIP_SSI_IMR_RXFIM                               (0x1 << 4)
#define XIP_SSI_IMR_RXOIM                               (0x1 << 3)
#define XIP_SSI_IMR_RXUIM                               (0x1 << 2)
#define XIP_SSI_IMR_TXOIM                               (0x1 << 1)
#define XIP_SSI_IMR_TXEIM                               (0x1 << 0)

/* --- XIP_SSI_ISR values --------------------------------------------------- */

#define XIP_SSI_ISR_MSTIS                               (0x1 << 5)
#define XIP_SSI_ISR_RXFIS                               (0x1 << 4)
#define XIP_SSI_ISR_RXOIS                               (0x1 << 3)
#define XIP_SSI_ISR_RXUIS                               (0x1 << 2)
#define XIP_SSI_ISR_TXOIS                               (0x1 << 1)
#define XIP_SSI_ISR_TXEIS                               (0x1 << 0)

/* --- XIP_SSI_RISR values -------------------------------------------------- */

#define XIP_SSI_RISR_MSTIR                              (0x1 << 5)
#define XIP_SSI_RISR_RXFIR                              (0x1 << 4)
#define XIP_SSI_RISR_RXOIR                              (0x1 << 3)
#define XIP_SSI_RISR_RXUIR                              (0x1 << 2)
#define XIP_SSI_RISR_TXOIR                              (0x1 << 1)
#define XIP_SSI_RISR_TXEIR                              (0x1 << 0)

/* --- XIP_SSI_TXOICR values ------------------------------------------------ */

#define XIP_SSI_TXOICR_OI                               (0x1 << 0)

/* --- XIP_SSI_RXOICR values ------------------------------------------------ */

#define XIP_SSI_RXOICR_OI                               (0x1 << 0)

/* --- XIP_SSI_RXUICR values ------------------------------------------------ */

#define XIP_SSI_RXUICR_UI                               (0x1 << 0)

/* --- XIP_SSI_MSTICR values ------------------------------------------------ */

#define XIP_SSI_MSTICR_IC                               (0x1 << 0)

/* --- XIP_SSI_ICR values --------------------------------------------------- */

#define XIP_SSI_ICR_IC                                  (0x1 << 0)

/* --- XIP_SSI_DMACR values ------------------------------------------------- */

#define XIP_SSI_DMACR_TDMAE                             (0x1 << 1)
#define XIP_SSI_DMACR_RDMAE                             (0x1 << 0)

/* --- XIP_SSI_DMATDLR values ----------------------------------------------- */

#define XIP_SSI_DMATDLR_DMATDL(level)                   ((level) << 0)
#define XIP_SSI_DMATDLR_DMATDL_MASK                     (0xff << 0)

/* --- XIP_SSI_DMARDLR values ----------------------------------------------- */

#define XIP_SSI_DMARDLR_DMARDL(level)                   ((level) << 0)
#define XIP_SSI_DMARDLR_DMARDL_MASK                     (0xff << 0)

/* --- XIP_SSI_IDR values --------------------------------------------------- */

#define XIP_SSI_IDR_IDCODE                              0x51535049

/* --- XIP_SSI_SSI_VERSION_ID values ---------------------------------------- */

#define XIP_SSI_SSI_VERSION_ID_SSI_COMP_VERSION         0x3430312a

/* --- XIP_SSE_RX_SAMPLE_DLY values ----------------------------------------- */

#define XIP_SSE_RX_SAMPLE_DLY_RSD(level)                ((level) << 0)
#define XIP_SSE_RX_SAMPLE_DLY_RSD_MASK                  (0xff << 0)

/* --- XIP_SSE_SPI_CTRLR0 values -------------------------------------------- */

#define XIP_SSE_SPI_CTRLR0_XIP_CMD(cmd)                 ((cmd) << 24)
#define XIP_SSE_SPI_CTRLR0_XIP_CMD_MASK                 (0xff << 24)
#define XIP_SSE_SPI_CTRLR0_SPI_RXDS_EN                  (0x1 << 18)
#define XIP_SSE_SPI_CTRLR0_INST_DDR_EN                  (0x1 << 17)
#define XIP_SSE_SPI_CTRLR0_SPI_DDR_EN                   (0x1 << 16)
#define XIP_SSE_SPI_CTRLR0_WAIT_CYCLES(cmd)             ((cmd) << 11)
#define XIP_SSE_SPI_CTRLR0_WAIT_CYCLES_MASK             (0x1f << 11)
#define XIP_SSE_SPI_CTRLR0_INST_L(cmd)                  ((cmd) << 8)
#define XIP_SSE_SPI_CTRLR0_INST_L_MASK                  (0x3 << 8)
#define XIP_SSE_SPI_CTRLR0_INST_L_NO_INST               0x0
#define XIP_SSE_SPI_CTRLR0_INST_L_4_BIT                 0x1
#define XIP_SSE_SPI_CTRLR0_INST_L_8_BIT                 0x2
#define XIP_SSE_SPI_CTRLR0_INST_L_16_BIT                0x3
#define XIP_SSE_SPI_CTRLR0_ADDR_L(cmd)                  ((cmd) << 2)
#define XIP_SSE_SPI_CTRLR0_ADDR_L_MASK                  (0xf << 2)
#define XIP_SSE_SPI_CTRLR0_TRANS_TYPE(cmd)              ((cmd) << 0)
#define XIP_SSE_SPI_CTRLR0_TRANS_TYPE_MASK              (0x3 << 0)
#define XIP_SSE_SPI_CTRLR0_TRANS_TYPE_STD               0x0
#define XIP_SSE_SPI_CTRLR0_TRANS_TYPE_ADDR_FRF          0x1
#define XIP_SSE_SPI_CTRLR0_TRANS_TYPE_BOTH_FRF          0x2

/* --- XIP_SSE_TXD_DRIVE_EDGE values ---------------------------------------- */

#define XIP_SSE_TXD_DRIVE_EDGE_TDE(level)               ((level) << 0)
#define XIP_SSE_TXD_DRIVE_EDGE_TDE_MASK                 (0xff << 0)


/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void xosc_init(void);
void xosc_disable(void);
void xosc_dormant(void);

/** @} */
END_DECLS

#endif

/**@}*/

