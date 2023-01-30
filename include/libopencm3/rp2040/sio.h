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

#ifndef LIBOPENCM3_SIO_H
#define LIBOPENCM3_SIO_H

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>

#define CPUID                   MMIO32((SIO_BASE) + 0x000)
#define GPIO_IN                 MMIO32((SIO_BASE) + 0x004)
#define GPIO_HI_IN              MMIO32((SIO_BASE) + 0x008)
#define GPIO_OUT                MMIO32((SIO_BASE) + 0x010)
#define GPIO_OUT_SET            MMIO32((SIO_BASE) + 0x014)
#define GPIO_OUT_CLR            MMIO32((SIO_BASE) + 0x018)
#define GPIO_OUT_XOR            MMIO32((SIO_BASE) + 0x01c)
#define GPIO_OE                 MMIO32((SIO_BASE) + 0x020)
#define GPIO_OE_SET             MMIO32((SIO_BASE) + 0x024)
#define GPIO_OE_CLR             MMIO32((SIO_BASE) + 0x028)
#define GPIO_OE_XOR             MMIO32((SIO_BASE) + 0x02c)
#define GPIO_HI_OUT             MMIO32((SIO_BASE) + 0x030)
#define GPIO_HI_OUT_SET         MMIO32((SIO_BASE) + 0x034)
#define GPIO_HI_OUT_CLR         MMIO32((SIO_BASE) + 0x038)
#define GPIO_HI_OUT_XOR         MMIO32((SIO_BASE) + 0x03c)
#define GPIO_HI_OE              MMIO32((SIO_BASE) + 0x040)
#define GPIO_HI_OE_SET          MMIO32((SIO_BASE) + 0x044)
#define GPIO_HI_OE_CLR          MMIO32((SIO_BASE) + 0x048)
#define GPIO_HI_OE_XOR          MMIO32((SIO_BASE) + 0x04c)
#define FIFO_ST                 MMIO32((SIO_BASE) + 0x050)
#define FIFO_WR                 MMIO32((SIO_BASE) + 0x054)
#define FIFO_RD                 MMIO32((SIO_BASE) + 0x058)
#define SPINLOCK_ST             MMIO32((SIO_BASE) + 0x05c)
#define DIV_UDIVIDEND           MMIO32((SIO_BASE) + 0x060)
#define DIV_UDIVISOR            MMIO32((SIO_BASE) + 0x064)
#define DIV_SDIVIDEND           MMIO32((SIO_BASE) + 0x068)
#define DIV_SDIVISOR            MMIO32((SIO_BASE) + 0x06c)
#define DIV_QUOTIENT            MMIO32((SIO_BASE) + 0x070)
#define DIV_REMAINDER           MMIO32((SIO_BASE) + 0x074)
#define DIV_CSR                 MMIO32((SIO_BASE) + 0x078)
#define INTERP0_ACCUM0          MMIO32((SIO_BASE) + 0x080)
#define INTERP0_ACCUM1          MMIO32((SIO_BASE) + 0x084)
#define INTERP0_BASE0           MMIO32((SIO_BASE) + 0x088)
#define INTERP0_BASE1           MMIO32((SIO_BASE) + 0x08c)
#define INTERP0_BASE2           MMIO32((SIO_BASE) + 0x090)
#define INTERP0_POP_LANE0       MMIO32((SIO_BASE) + 0x094)
#define INTERP0_POP_LANE1       MMIO32((SIO_BASE) + 0x098)
#define INTERP0_POP_FULL        MMIO32((SIO_BASE) + 0x09c)
#define INTERP0_PEEK_LANE0      MMIO32((SIO_BASE) + 0x0a0)
#define INTERP0_PEEK_LANE1      MMIO32((SIO_BASE) + 0x0a4)
#define INTERP0_PEEK_FULL       MMIO32((SIO_BASE) + 0x0a8)
#define INTERP0_CTRL_LANE0      MMIO32((SIO_BASE) + 0x0ac)
#define INTERP0_CTRL_LANE1      MMIO32((SIO_BASE) + 0x0b0)
#define INTERP0_ACCUM0_ADD      MMIO32((SIO_BASE) + 0x0b4)
#define INTERP0_ACCUM1_ADD      MMIO32((SIO_BASE) + 0x0b8)
#define INTERP0_BASE_1AND0      MMIO32((SIO_BASE) + 0x0bc)
#define INTERP1_ACCUM0          MMIO32((SIO_BASE) + 0x0c0)
#define INTERP1_ACCUM1          MMIO32((SIO_BASE) + 0x0c4)
#define INTERP1_BASE0           MMIO32((SIO_BASE) + 0x0c8)
#define INTERP1_BASE1           MMIO32((SIO_BASE) + 0x0cc)
#define INTERP1_BASE2           MMIO32((SIO_BASE) + 0x0d0)
#define INTERP1_POP_LANE0       MMIO32((SIO_BASE) + 0x0d4)
#define INTERP1_POP_LANE1       MMIO32((SIO_BASE) + 0x0d8)
#define INTERP1_POP_FULL        MMIO32((SIO_BASE) + 0x0dc)
#define INTERP1_PEEK_LANE0      MMIO32((SIO_BASE) + 0x0e0)
#define INTERP1_PEEK_LANE1      MMIO32((SIO_BASE) + 0x0e4)
#define INTERP1_PEEK_FULL       MMIO32((SIO_BASE) + 0x0e8)
#define INTERP1_CTRL_LANE0      MMIO32((SIO_BASE) + 0x0ec)
#define INTERP1_CTRL_LANE1      MMIO32((SIO_BASE) + 0x0f0)
#define INTERP1_ACCUM0_ADD      MMIO32((SIO_BASE) + 0x0f4)
#define INTERP1_ACCUM1_ADD      MMIO32((SIO_BASE) + 0x0f8)
#define INTERP1_BASE_1AND0      MMIO32((SIO_BASE) + 0x0fc)
#define SPINLOCK0               MMIO32((SIO_BASE) + 0x100)
#define SPINLOCK1               MMIO32((SIO_BASE) + 0x104)
#define SPINLOCK2               MMIO32((SIO_BASE) + 0x108)
#define SPINLOCK3               MMIO32((SIO_BASE) + 0x10c)
#define SPINLOCK4               MMIO32((SIO_BASE) + 0x110)
#define SPINLOCK5               MMIO32((SIO_BASE) + 0x114)
#define SPINLOCK6               MMIO32((SIO_BASE) + 0x118)
#define SPINLOCK7               MMIO32((SIO_BASE) + 0x11c)
#define SPINLOCK8               MMIO32((SIO_BASE) + 0x120)
#define SPINLOCK9               MMIO32((SIO_BASE) + 0x124)
#define SPINLOCK10              MMIO32((SIO_BASE) + 0x128)
#define SPINLOCK11              MMIO32((SIO_BASE) + 0x12c)
#define SPINLOCK12              MMIO32((SIO_BASE) + 0x130)
#define SPINLOCK13              MMIO32((SIO_BASE) + 0x134)
#define SPINLOCK14              MMIO32((SIO_BASE) + 0x138)
#define SPINLOCK15              MMIO32((SIO_BASE) + 0x13c)
#define SPINLOCK16              MMIO32((SIO_BASE) + 0x140)
#define SPINLOCK17              MMIO32((SIO_BASE) + 0x144)
#define SPINLOCK18              MMIO32((SIO_BASE) + 0x148)
#define SPINLOCK19              MMIO32((SIO_BASE) + 0x14c)
#define SPINLOCK20              MMIO32((SIO_BASE) + 0x150)
#define SPINLOCK21              MMIO32((SIO_BASE) + 0x154)
#define SPINLOCK22              MMIO32((SIO_BASE) + 0x158)
#define SPINLOCK23              MMIO32((SIO_BASE) + 0x15c)
#define SPINLOCK24              MMIO32((SIO_BASE) + 0x160)
#define SPINLOCK25              MMIO32((SIO_BASE) + 0x164)
#define SPINLOCK26              MMIO32((SIO_BASE) + 0x168)
#define SPINLOCK27              MMIO32((SIO_BASE) + 0x16c)
#define SPINLOCK28              MMIO32((SIO_BASE) + 0x170)
#define SPINLOCK29              MMIO32((SIO_BASE) + 0x174)
#define SPINLOCK30              MMIO32((SIO_BASE) + 0x178)
#define SPINLOCK31              MMIO32((SIO_BASE) + 0x17c)


#endif
