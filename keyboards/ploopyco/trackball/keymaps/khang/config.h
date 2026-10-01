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

/* DPI ladder, stepped at runtime with the DPI_CONFIG keycode - assign "DPI
 * Config" to any button in VIA. Each press advances one entry and wraps.
 *
 * DPI_CONFIG writes the chosen index to EEPROM, so the value you settle on
 * survives reboots and firmware flashes. No reflashing needed to change DPI.
 *
 * Increments of 50 are not possible. The PMW3360 steps in units of 100 CPI
 * (PMW33XX_CPI_STEP) and pmw33xx_set_cpi() does `cpi / PMW33XX_CPI_STEP`, so
 * 1150 writes the same register value as 1100 and reads back as 1100. A 50
 * ladder would just contain duplicate values. 100 CPI is the finest available.
 *
 * Index 0 is 1100 on purpose: this tree only rejects a stored index *greater*
 * than the array size, and the index was last left at 0, so index 0 is what
 * boots. Each press from there steps forward. */
#define PLOOPY_DPI_OPTIONS { 1100, 1200, 1300, 1400, 1500 }
#define PLOOPY_DPI_DEFAULT 0

/* Drag-scroll speed is inherited from ploopyco.c as 64.0, the same divisor the
 * Adept uses. Note the rate scales with CPI, since ticks per inch is
 * CPI / divisor: at 1200 CPI this gives ~19 ticks per inch, against ~14 on the
 * Adept at 900. Set PLOOPY_DRAGSCROLL_DIVISOR_H/V to 85.0 below to hold the
 * Adept's rate at 1200 CPI. */
