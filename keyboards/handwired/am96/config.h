/* Copyright 2020 Ross Harmes <ross@rossharmes.net>
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

#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    rharmes
#define PRODUCT         AM96
#define DESCRIPTION     A joined-split ergo keyboard with central numpad

/* Key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 17

/* Key matrix pins */
#define MATRIX_ROW_PINS { D3, D2, D1, D0, D4, C6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6, F0, F1, C7, D5, B7, B5, B4, E6, D7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Use the default tapping term */
#define TAPPING_TERM 200

/* Prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN B0
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 2
#define RGBLIGHT_LAYERS 5
