# Copyright 2021 Ross Harmes <ross@rossharmes.net>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# MCU name
MCU = atmega32u4

# Bootloader selection
#     Teensy       halfkay
#     Pro Micro    caterina
#     Atmel DFU    atmel-dfu
#     LUFA DFU     lufa-dfu
#     QMK DFU      qmk-dfu
#     ATmega32A    bootloadHID
#     ATmega328P   USBasp
BOOTLOADER = qmk-dfu

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
CONSOLE_ENABLE   = no  # Console for debug(+400)
COMMAND_ENABLE   = no  # Commands for debug and configuration
SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE      = no  # USB Nkey Rollover - not yet supported in LUFA
UNICODE_ENABLE   = yes # Enable support for arrow keys icon on the second layer.
COMBO_ENABLE     = no  # Enable combo for special function when using multiple keys at once.
TAP_DANCE_ENABLE = no  # Enable use multiple tap
RGBLIGHT_ENABLE  = no  # Enable WS2812 RGB underlight.
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality
AUDIO_ENABLE     = no  # Audio output on port C6
