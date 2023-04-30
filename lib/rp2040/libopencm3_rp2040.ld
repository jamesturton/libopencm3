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

/* Generic linker script for rp2040 targets using libopencm3. */

/* Memory regions must be defined in the ld script which includes this one. */

MEMORY
{
	ram (rwx) : ORIGIN = 0x20000000, LENGTH = 256K
}

EXTERN(BOOT2_ROM)

/* Define sections. */
SECTIONS
{
    .boot2 : {
        _boot2 = .;
        KEEP (*(.boot2))
		. = ALIGN(4);
        _eboot2 = .;
    } >rom
}

INCLUDE cortex-m-generic.ld
