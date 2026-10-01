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

/* Pinned at 1400 CPI. With a single entry, DPI_CONFIG computes
 * (0 + 1) % 1 == 0 and does nothing, so the CPI can no longer be changed by
 * accidentally pressing a key bound to it.
 *
 * The ladder used to find this value was { 1100, 1200, 1300, 1400, 1500 } -
 * swap it back in here if 1400 needs revisiting. The sensor steps in units of
 * 100 CPI (PMW33XX_CPI_STEP), so 50 increments are not possible.
 *
 * Note this tree only rejects a stored index *greater* than the array size, so
 * a single-entry array with PLOOPY_DPI_DEFAULT 0 would read out of bounds if
 * the stored index were exactly 1. If the pointer ever feels wildly wrong after
 * flashing, that guard in keyboards/ploopyco/ploopyco.c wants to be >= rather
 * than >. */
#define PLOOPY_DPI_OPTIONS { 1400 }
#define PLOOPY_DPI_DEFAULT 0

/* Drag-scroll speed is inherited from ploopyco.c as 64.0, the same divisor the
 * Adept uses. Note the rate scales with CPI, since ticks per inch is
 * CPI / divisor: at 1200 CPI this gives ~19 ticks per inch, against ~14 on the
 * Adept at 900. Set PLOOPY_DRAGSCROLL_DIVISOR_H/V to 85.0 below to hold the
 * Adept's rate at 1200 CPI. */
