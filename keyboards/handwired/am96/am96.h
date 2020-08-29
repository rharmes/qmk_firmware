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

#define KB_H
#include "quantum.h"

/*  ---------- LEFT HAND -----------  ------------ CENTER ------------  ---------- RIGHT HAND ---------- */
#define LAYOUT(                                                                                           \
                                      C00,C01,C02,C03,C04,C05,C06,C07,                                    \
    L00,L01,L02,L03,L04,L05,              C11,    C13,C14,C15,C16,          R01,R02,R03,R04,R05,R06,      \
    L10,L11,L12,L13,L14,L15,L16,          C21,    C23,C24,C25,C26,      R10,R11,R12,R13,R14,R15,R16,      \
    L20,L21,L22,L23,L24,L25,L26,          C31,    C33,C34,C35,C36,      R20,R21,R22,R23,R24,R25,R26,      \
    L30,L31,L32,L33,L34,L35,              C41,    C43,C44,C45,C46,          R31,R32,R33,R34,R35,R36,      \
            L42,L43,L44,                  C51,    C53,    C55,                  R42,R43,R44,              \
                        L55,L56,          C61,    C63,    C65,          R50,R51                           \
                                                                                                          \
) { \
	{ KC_NO, KC_NO, KC_NO, L26,   L16,   C00,   C01,   C02,   C03,   C04,   C05,   C06,   C07,   R10,   R20,   KC_NO, KC_NO }, \
	{ L00,   L01,   L02,   L03,   L04,   L05,   C11,   C13,   C14,   C15,   C16,   R01,   R02,   R03,   R04,   R05,   R06   }, \
	{ L10,   L11,   L12,   L13,   L14,   L15,   C21,   C23,   C24,   C25,   C26,   R11,   R12,   R13,   R14,   R15,   R16   }, \
	{ L20,   L21,   L22,   L23,   L24,   L25,   C31,   C33,   C34,   C35,   C36,   R21,   R22,   R23,   R24,   R25,   R26   }, \
	{ L30,   L31,   L32,   L33,   L34,   L35,   C41,   C43,   C44,   C45,   C46,   R31,   R32,   R33,   R34,   R35,   R36   }, \
	{ L42,   L43,   L44,   L55,   L56,   C61,   C51,   C53,   C63,   C55,   C65,   R50,   R51,   R42,   R43,   R44,   KC_NO }  \
}
