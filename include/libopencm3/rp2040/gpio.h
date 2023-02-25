/** @defgroup gpio_defines General Purpose I/O Defines
 *
 * @ingroup RP2040_defines
 *
 * @brief <b>Defined Constants and Types for the RP2040 General Purpose I/O</b>
 *
 * @version 1.0.0
 * 
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 * 
 * @date 4 May 2021
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

#ifndef RP2040_GPIO_H
#define RP2040_GPIO_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/rp2040/memorymap.h>
#include <libopencm3/rp2040/sio.h>
#include <libopencm3/rp2040/pad.h>
#include <libopencm3/rp2040/io.h>

/* =============================================================================
 * GPIO number definitions (for convenience)
 *
 * These are usable across all GPIO registers
 * ---------------------------------------------------------------------------*/
/** @defgroup gpio_pin_id GPIO pin identifiers
 * @{*/
#define GPIO0				(1 << 0)
#define GPIO1				(1 << 1)
#define GPIO2				(1 << 2)
#define GPIO3				(1 << 3)
#define GPIO4				(1 << 4)
#define GPIO5				(1 << 5)
#define GPIO6				(1 << 6)
#define GPIO7				(1 << 7)
#define GPIO8				(1 << 8)
#define GPIO9				(1 << 9)
#define GPIO10				(1 << 10)
#define GPIO11				(1 << 11)
#define GPIO12				(1 << 12)
#define GPIO13				(1 << 13)
#define GPIO14				(1 << 14)
#define GPIO15				(1 << 15)
#define GPIO16				(1 << 16)
#define GPIO17				(1 << 17)
#define GPIO18				(1 << 18)
#define GPIO19				(1 << 19)
#define GPIO20				(1 << 20)
#define GPIO21				(1 << 21)
#define GPIO22				(1 << 22)
#define GPIO23				(1 << 23)
#define GPIO24				(1 << 24)
#define GPIO25				(1 << 25)
#define GPIO26				(1 << 26)
#define GPIO27				(1 << 27)
#define GPIO28				(1 << 28)
#define GPIO29				(1 << 29)

#define GPIO_ALL			(0x3fffffff)
#define GPIO_COUNT			(30)

#define GPIO_DIR_IN			(0)
#define GPIO_DIR_OUT		(1)
/** @} */


/* =============================================================================
 * Convenience enums
 * ---------------------------------------------------------------------------*/
/**
 * \brief  GPIO function definitions for use with function select
 *
 * Each GPIO can have one function selected at a time. Likewise, each peripheral
 * input (e.g. UART0 RX) should only be selected on one GPIO at a time. If the
 * same peripheral input is connected to multiple GPIOs, the peripheral sees the
 * logical OR of these GPIO inputs.
 */
enum gpio_function {
    GPIO_FUNC_XIP,
    GPIO_FUNC_SPI,
    GPIO_FUNC_UART,
    GPIO_FUNC_I2C,
    GPIO_FUNC_PWM,
    GPIO_FUNC_SIO,
    GPIO_FUNC_PIO0,
    GPIO_FUNC_PIO1,
    GPIO_FUNC_GPCK,
    GPIO_FUNC_USB,
    GPIO_FUNC_NULL = 0x1f,
};


/* =============================================================================
 * Function prototypes
 * ---------------------------------------------------------------------------*/
BEGIN_DECLS

void gpio_init(uint32_t gpios);
void gpio_set_func(uint32_t gpios, enum gpio_function func);
void gpio_set_dir(uint32_t gpios, bool out);
void gpio_set(uint32_t gpios);
void gpio_clear(uint32_t gpios);
void gpio_toggle(uint32_t gpios);

/** @} */
END_DECLS

#endif

/**@}*/

