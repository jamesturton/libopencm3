/** @defgroup uart_defines UART Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 UART Module</b>
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2023
 * James Turton <james.turton@gmx.com>
 *
 * @date 24 Febuary 2023
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

#ifndef RP2040_UART_H
#define RP2040_UART_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

/* =============================================================================
 * Convenience macros
 * ---------------------------------------------------------------------------*/
/** @defgroup uart_reg_base UART register base addresses
@ingroup uart_defines

@{*/
#define UART0				UART0_BASE
#define UART1				UART1_BASE

/* =============================================================================
 * UART registers
 * ---------------------------------------------------------------------------*/

/* UART data register */
#define UART_DR(uart_base)		MMIO32((uart_base) + 0x00)

/* UART Receive Status/Error Clear register */
#define UART_RSR(uart_base)		MMIO32((uart_base) + 0x04)

/* UART Flag register */
#define UART_FR(uart_base)		MMIO32((uart_base) + 0x18)

/* UART IrDA Low-Power register */
#define UART_ILPR(uart_base)		MMIO32((uart_base) + 0x20)

/* UART Integer baudrate divisor */
#define UART_IBRD(uart_base)		MMIO32((uart_base) + 0x24)

/* UART Fractional baudrate divisor */
#define UART_FBRD(uart_base)		MMIO32((uart_base) + 0x28)

/* UART Line control */
#define UART_LCRH(uart_base)		MMIO32((uart_base) + 0x2C)

/* UART Control */
#define UART_CTL(uart_base)		MMIO32((uart_base) + 0x30)

/* UART Interrupt FIFO level select */
#define UART_IFLS(uart_base)		MMIO32((uart_base) + 0x34)

/* UART Interrupt mask */
#define UART_IM(uart_base)		MMIO32((uart_base) + 0x38)

/* UART Raw interrupt status */
#define UART_RIS(uart_base)		MMIO32((uart_base) + 0x3C)

/* UART Masked Interrupt status */
#define UART_MIS(uart_base)		MMIO32((uart_base) + 0x40)

/* UART Interrupt Clear */
#define UART_ICR(uart_base)		MMIO32((uart_base) + 0x44)

/* UART DMA control */
#define UART_DMACTL(uart_base)		MMIO32((uart_base) + 0x48)

/* UART Peripheral Identification 0 */
#define UART_PERIPH_ID0(uart_base)	MMIO32((uart_base) + 0xFE0)

/* UART Peripheral Identification 1 */
#define UART_PERIPH_ID1(uart_base)	MMIO32((uart_base) + 0xFE4)

/* UART Peripheral Identification 2 */
#define UART_PERIPH_ID2(uart_base)	MMIO32((uart_base) + 0xFE8)

/* UART Peripheral Identification 3 */
#define UART_PERIPH_ID3(uart_base)	MMIO32((uart_base) + 0xFEC)

/* UART PrimeCell Identification 0 */
#define UART_PCELL_ID0(uart_base)	MMIO32((uart_base) + 0xFF0)

/* UART PrimeCell Identification 1 */
#define UART_PCELL_ID1(uart_base)	MMIO32((uart_base) + 0xFF4)

/* UART PrimeCell Identification 2 */
#define UART_PCELL_ID2(uart_base)	MMIO32((uart_base) + 0xFF8)

/* UART PrimeCell Identification 3 */
#define UART_PCELL_ID3(uart_base)	MMIO32((uart_base) + 0xFFC)


/* =============================================================================
 * UART_DR values
 * ---------------------------------------------------------------------------*/
/** Overrun Error */
#define UART_DR_OE			(1 << 11)
/** Break Error */
#define UART_DR_BE			(1 << 10)
/** Parity Error */
#define UART_DR_PE			(1 << 9)
/** Framing Error */
#define UART_DR_FE			(1 << 8)
/** Data transmitted or received */
#define UART_DR_DATA_MASK		(0xFF << 0)

/* =============================================================================
 * Readonly UART_RSR values
 * ---------------------------------------------------------------------------*/
/** Overrun Error */
#define UART_RSR_OE			(1 << 3)
/** Break Error */
#define UART_RSR_BE			(1 << 2)
/** Parity Error */
#define UART_RSR_PE			(1 << 1)
/** Framing Error */
#define UART_RSR_FE			(1 << 0)

/* =============================================================================
 * UART_FR values
 * ---------------------------------------------------------------------------*/
/** Ring indicator */
#define UART_FR_RI			(1 << 8)
/** Tx FIFO empty */
#define UART_FR_TXFE			(1 << 7)
/** Rx FIFO full */
#define UART_FR_RXFF			(1 << 6)
/** Tx FIFO full */
#define UART_FR_TXFF			(1 << 5)
/** Rx FIFO empty */
#define UART_FR_RXFE			(1 << 4)
/** UART Busy */
#define UART_FR_BUSY			(1 << 3)
/** Data Carrier Detect */
#define UART_FR_DCD			(1 << 2)
/** Data Set Ready */
#define UART_FR_DSR			(1 << 1)
/** Clear To Send */
#define UART_FR_CTS			(1 << 0)

/* =============================================================================
 * UART_LCRH values
 * ---------------------------------------------------------------------------*/
/** Stick parity select */
#define UART_LCRH_SPS			(1 << 7)
/** Word length */
#define UART_LCRH_WLEN_MASK		(3 << 5)
#define UART_LCRH_WLEN_5		(0 << 5)
#define UART_LCRH_WLEN_6		(1 << 5)
#define UART_LCRH_WLEN_7		(2 << 5)
#define UART_LCRH_WLEN_8		(3 << 5)
/** Enable FIFOs */
#define UART_LCRH_FEN			(1 << 4)
/** Two stop bits select */
#define UART_LCRH_STP2			(1 << 3)
/** Even parity select */
#define UART_LCRH_EPS			(1 << 2)
/** Parity enable */
#define UART_LCRH_PEN			(1 << 1)
/** Send break */
#define UART_LCRH_BRK			(1 << 0)

/* =============================================================================
 * UART_CTL values
 * ---------------------------------------------------------------------------*/
/** Enable Clear To Send */
#define UART_CTL_CTSEN			(1 << 15)
/** Enable Request To Send */
#define UART_CTL_RTSEN			(1 << 14)
/** UART Out2 modem status output */
#define UART_CTL_OUT2			(1 << 13)
/** UART Out1 modem status output */
#define UART_CTL_OUT1			(1 << 12)
/** Request To Send */
#define UART_CTL_RTS			(1 << 11)
/** Data terminal ready */
#define UART_CTL_DTR			(1 << 10)
/** Rx Enable */
#define UART_CTL_RXE			(1 << 9)
/** Tx Enable */
#define UART_CTL_TXE			(1 << 8)
/** Loop back enable */
#define UART_CTL_LBE			(1 << 7)
/** SIR low-power mode */
#define UART_CTL_SIRLIP			(1 << 2)
/** SIR enable */
#define UART_CTL_SIREN			(1 << 1)
/** UART enable */
#define UART_CTL_UARTEN			(1 << 0)

/* =============================================================================
 * UART_IFLS values
 * ---------------------------------------------------------------------------*/
/** UART Rx interrupt FIFO level select */
#define UART_IFLS_RXIFLSEL_MASK		(7 << 3)
#define UART_IFLS_RXIFLSEL_1_8		(0 << 3)
#define UART_IFLS_RXIFLSEL_1_4		(1 << 3)
#define UART_IFLS_RXIFLSEL_1_2		(2 << 3)
#define UART_IFLS_RXIFLSEL_3_4		(3 << 3)
#define UART_IFLS_RXIFLSEL_7_8		(4 << 3)
/** UART Tx interrupt FIFO level select */
#define UART_IFLS_TXIFLSEL_MASK		(7 << 0)
#define UART_IFLS_TXIFLSEL_1_8		(0 << 0)
#define UART_IFLS_TXIFLSEL_1_4		(1 << 0)
#define UART_IFLS_TXIFLSEL_1_2		(2 << 0)
#define UART_IFLS_TXIFLSEL_3_4		(3 << 0)
#define UART_IFLS_TXIFLSEL_7_8		(4 << 0)

/* =============================================================================
 * UART interrupt mask values
 *
 * These are interchangeable across UART_IM, UART_RIS, UART_MIS, and UART_ICR
 * registers.
 * ---------------------------------------------------------------------------*/
/** Overrun error interrupt mask */
#define UART_IM_OEIM			(1 << 10)
/** Break error interrupt mask */
#define UART_IM_BEIM			(1 << 9)
/** Parity error interrupt mask */
#define UART_IM_PEIM			(1 << 8)
/** Framing error interrupt mask */
#define UART_IM_FEIM			(1 << 7)
/** Receive time-out interrupt mask */
#define UART_IM_RTIM			(1 << 6)
/** Transmit interrupt mask */
#define UART_IM_TXIM			(1 << 5)
/** Receive interrupt mask */
#define UART_IM_RXIM			(1 << 4)
/** Data Set Ready modem interrupt mask */
#define UART_IM_DSRIM			(1 << 3)
/** Data Carrier Detect modem interrupt mask */
#define UART_IM_DCDIM			(1 << 2)
/** Clear To Send modem interrupt mask */
#define UART_IM_CTSIM			(1 << 1)
/** Ring Indicator modem interrupt mask */
#define UART_IM_RIIM			(1 << 0)

/* =============================================================================
 * UART_DMACTL values
 * ---------------------------------------------------------------------------*/
/** DMA on error */
#define UART_DMACTL_DMAERR		(1 << 2)
/** Transmit DMA enable */
#define UART_DMACTL_TXDMAE		(1 << 1)
/** Receive DMA enable */
#define UART_DMACTL_RXDMAE		(1 << 0)


/* =============================================================================
 * Convenience enums
 * ---------------------------------------------------------------------------*/
enum uart_parity {
	UART_PARITY_NONE,
	UART_PARITY_ODD,
	UART_PARITY_EVEN,
	UART_PARITY_STICK_0,
	UART_PARITY_STICK_1,
};

enum uart_flowctl {
	UART_FLOWCTL_NONE,
	UART_FLOWCTL_RTS,
	UART_FLOWCTL_CTS,
	UART_FLOWCTL_RTS_CTS,
};

/**
 * \brief UART interrupt masks
 *
 * These masks can be OR'ed together to specify more than one interrupt. For
 * example, (UART_INT_TXIM | UART_INT_TXIM) specifies both Rx and Tx Interrupt.
 */
enum uart_interrupt_flag {
	UART_INT_OE	= UART_IM_OEIM,
	UART_INT_BE	= UART_IM_BEIM,
	UART_INT_PE	= UART_IM_PEIM,
	UART_INT_FE	= UART_IM_FEIM,
	UART_INT_RT	= UART_IM_RTIM,
	UART_INT_TX	= UART_IM_TXIM,
	UART_INT_RX	= UART_IM_RXIM,
	UART_INT_DSR	= UART_IM_DSRIM,
	UART_INT_DCD	= UART_IM_DCDIM,
	UART_INT_CTS	= UART_IM_CTSIM,
	UART_INT_RI	= UART_IM_RIIM,
};

/**
 * \brief UART RX FIFO interrupt trigger levels
 *
 * The levels indicate how full the FIFO should be before an interrupt is
 * generated.  UART_FIFO_RX_TRIG_3_4 means that an interrupt is triggered when
 * the FIFO is 3/4 full. As the FIFO is 8 elements deep, 1/8 is equal to being
 * triggered by a single character.
 */
enum uart_fifo_rx_trigger_level {
	UART_FIFO_RX_TRIG_1_8	= UART_IFLS_RXIFLSEL_1_8,
	UART_FIFO_RX_TRIG_1_4	= UART_IFLS_RXIFLSEL_1_4,
	UART_FIFO_RX_TRIG_1_2	= UART_IFLS_RXIFLSEL_1_2,
	UART_FIFO_RX_TRIG_3_4	= UART_IFLS_RXIFLSEL_3_4,
	UART_FIFO_RX_TRIG_7_8	= UART_IFLS_RXIFLSEL_7_8
};

/**
 * \brief UART TX FIFO interrupt trigger levels
 *
 * The levels indicate how empty the FIFO should be before an interrupt is
 * generated. UART_FIFO_TX_TRIG_3_4 means that an interrupt is triggered when
 * the FIFO is 3/4 full. As the FIFO is 8 elements deep, 1/8 is equal to being
 * triggered by a single character.
 */
enum uart_fifo_tx_trigger_level {
	UART_FIFO_TX_TRIG_1_8	= UART_IFLS_TXIFLSEL_1_8,
	UART_FIFO_TX_TRIG_1_4	= UART_IFLS_TXIFLSEL_1_4,
	UART_FIFO_TX_TRIG_1_2	= UART_IFLS_TXIFLSEL_1_2,
	UART_FIFO_TX_TRIG_3_4	= UART_IFLS_TXIFLSEL_3_4,
	UART_FIFO_TX_TRIG_7_8	= UART_IFLS_TXIFLSEL_7_8
};

/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void uart_enable(uint32_t uart);
void uart_disable(uint32_t uart);
void uart_set_baudrate(uint32_t uart, uint32_t baud);
void uart_set_databits(uint32_t uart, uint8_t databits);
void uart_set_stopbits(uint32_t uart, uint8_t stopbits);
void uart_set_parity(uint32_t uart, enum uart_parity parity);
void uart_set_flow_control(uint32_t uart, enum uart_flowctl flow);

void uart_send(uint32_t uart, uint16_t data);
uint16_t uart_recv(uint32_t uart);
void uart_wait_send_ready(uint32_t uart);
void uart_wait_recv_ready(uint32_t uart);
void uart_send_blocking(uint32_t uart, uint16_t data);
uint16_t uart_recv_blocking(uint32_t uart);

void uart_enable_rx_dma(uint32_t uart);
void uart_disable_rx_dma(uint32_t uart);
void uart_enable_tx_dma(uint32_t uart);
void uart_disable_tx_dma(uint32_t uart);

void uart_enable_fifo(uint32_t uart);
void uart_disable_fifo(uint32_t uart);
void uart_set_fifo_trigger_levels(uint32_t uart,
				  enum uart_fifo_rx_trigger_level rx_level,
				  enum uart_fifo_tx_trigger_level tx_level);

/* We inline FIFO full/empty checks as they are intended to be called from ISRs
 * */
/** @ingroup uart_fifo
 * @{
 * \brief Determine if the TX fifo is full
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
static inline
bool uart_is_tx_fifo_full(uint32_t uart)
{
	return UART_FR(uart) & UART_FR_TXFF;
}

/**
 * \brief Determine if the TX fifo is empty
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
static inline
bool uart_is_tx_fifo_empty(uint32_t uart)
{
	return UART_FR(uart) & UART_FR_TXFE;
}

/**
 * \brief Determine if the RX fifo is full
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
static inline
bool uart_is_rx_fifo_full(uint32_t uart)
{
	return UART_FR(uart) & UART_FR_RXFF;
}

/**
 * \brief Determine if the RX fifo is empty
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 */
static inline
bool uart_is_rx_fifo_empty(uint32_t uart)
{
	return UART_FR(uart) & UART_FR_RXFE;
}
/**@}*/

void uart_enable_interrupts(uint32_t uart, enum uart_interrupt_flag ints);
void uart_disable_interrupts(uint32_t uart, enum uart_interrupt_flag ints);
void uart_enable_rx_interrupt(uint32_t uart);
void uart_disable_rx_interrupt(uint32_t uart);
void uart_enable_tx_interrupt(uint32_t uart);
void uart_disable_tx_interrupt(uint32_t uart);
void uart_clear_interrupt_flag(uint32_t uart, enum uart_interrupt_flag ints);

/* Let's keep this one inlined. It's designed to be used in ISRs */
/** @ingroup uart_irq
 * @{
 * \brief Determine if interrupt is generated by the given source
 *
 * @param[in] uart UART block register address base @ref uart_reg_base
 * @param[in] source source to check.
 */
static inline
bool uart_is_interrupt_source(uint32_t uart, enum uart_interrupt_flag source)
{
	return UART_MIS(uart) & source;
}
/**@}*/

END_DECLS

#endif
