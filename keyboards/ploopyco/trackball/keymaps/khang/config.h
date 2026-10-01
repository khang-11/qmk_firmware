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

/* One DPI option, so the default index has to be 0. The original had
 * PLOOPY_DPI_DEFAULT 1 against a single-element array, which reads one element
 * past the end of dpi_array[] - on this board that lands on the keyboard_report
 * pointer and leaves the sensor on a garbage CPI. */
#define PLOOPY_DPI_OPTIONS { 1200 }
#define PLOOPY_DPI_DEFAULT 0

#define PLOOPY_DRAGSCROLL_INVERT
#define PLOOPY_DRAGSCROLL_DIVISOR_H 120.0
#define PLOOPY_DRAGSCROLL_DIVISOR_V 120.0
