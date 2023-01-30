/** @defgroup gpio_file GPIO
 *
 *
 * @ingroup RP2040
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2021
 * James Turton <james.turton@gmx.com>
 *
 * @date 4 May 2021
 *
 * LGPL License Terms @ref lgpl_license
 *
 * @brief <b>libopencm3 RP2040 General Purpose I/O</b>
 *
 * The RP2040 GPIO API provides functionality for accessing the GPIO pins of the
 * RP2040.
 *
 * Please see the individual GPIO modules for more details. To use the GPIO, the
 * gpio.h header needs to be included:
 * @code{.c}
 *	#include <libopencm3/rp2040/gpio.h>
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

#include <libopencm3/rp2040/gpio.h>
#include <libopencm3/rp2040/sio.h>
#include <libopencm3/rp2040/pad.h>
#include <libopencm3/rp2040/io.h>

void gpio_init(uint32_t gpio)
{
    GPIO_OE_CLR = gpio;
    GPIO_OUT_CLR = gpio;
    gpio_set_func(gpio, IO_GPIO_CTRL_FUNCSEL_SIO);
}

void gpio_set_func(uint32_t gpios, uint8_t func)
{
    uint16_t i;

	/*
	 * We want to set the config only for the pins mentioned in gpios,
	 * but keeping the others, so read out the actual config first.
	 */
    for (i = 0; i < GPIO_COUNT; i++)
    {
		if (!((1 << i) & gpios))
        {
			continue;
		}

        // Enable input and output
        PAD_GPIO(i) |= PAD_IE(PAD_INPUT_ENABLE);
        PAD_GPIO(i) &= ~PAD_OD(PAD_OUTPUT_ENABLE);

        // Zero all fields apart from fsel; we want this IO to do what the
        // peripheral tells it. This doesn't affect e.g. pullup/pulldown, as
        // these are in pad controls.
        IO_GPIO_CTRL(i) = IO_GPIO_CTRL_FUNCSEL(func);
    }
}

void gpio_set_dir(uint32_t gpios, bool out)
{
    if (out)
    {
        GPIO_OE_SET = gpios;
    }
    else
    {
        GPIO_OE_CLR = gpios;
    }
}

void gpio_set(uint32_t gpios)
{
	GPIO_OUT_SET = gpios;
}

void gpio_clear(uint32_t gpios)
{
	GPIO_OUT_CLR = gpios;
}

void gpio_toggle(uint32_t gpios)
{
	GPIO_OUT_XOR = gpios;
}

/**@}*/

/**@}*/

