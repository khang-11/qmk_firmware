/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

/* Both of these features were removed from QMK long ago, so these do nothing.
 * Kept only because they were in the keymap this was taken from. */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* DPI and drag-scroll speed are deliberately not set here, so this keymap
 * inherits exactly what the Adept inherits from keyboards/ploopyco/ploopyco.c:
 *
 *   PLOOPY_DPI_OPTIONS           {900}   -> 900 CPI
 *   PLOOPY_DPI_DEFAULT           0
 *   PLOOPY_DRAGSCROLL_DIVISOR_H  64.0
 *   PLOOPY_DRAGSCROLL_DIVISOR_V  64.0
 *
 * That is 900 / 64.0 = about 14 scroll ticks per inch of ball travel, the same
 * rate the Adept runs at. Set the defines here to diverge from it.
 *
 * PLOOPY_DRAGSCROLL_INVERT is absent on purpose. The keymap this was adapted
 * from set it, so leaving it out reverses the drag-scroll direction.
 *
 * If you ever set PLOOPY_DPI_OPTIONS here, make sure PLOOPY_DPI_DEFAULT is 0.
 * This tree only rejects a stored index greater than the array size, so a
 * single-entry array with default 1 reads one element past dpi_array[] and
 * leaves the sensor on a garbage CPI. */
