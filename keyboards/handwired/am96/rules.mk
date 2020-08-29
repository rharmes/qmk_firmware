# Copyright 2020 Ross Harmes <ross@rossharmes.net>
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

# Processor frequency.
#     This will define a symbol, F_CPU, in all source code files equal to the
#     processor frequency in Hz. You can then use this symbol in your source code to
#     calculate timings. Do NOT tack on a 'UL' at the end, this will be done
#     automatically to create a 32-bit value in your source code.
#
#     This will be an integer division of F_USB below, as it is sourced by
#     F_USB after it has run through any CPU prescalers. Note that this value
#     does not *change* the processor frequency - it should merely be updated to
#     reflect the processor speed set externally so that the code can use accurate
#     software delays.
F_CPU = 16000000

# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
ARCH = AVR8

# Input clock frequency.
#     This will define a symbol, F_USB, in all source code files equal to the
#     input clock frequency (before any prescaling is performed) in Hz. This value may
#     differ from F_CPU if prescaling is used on the latter, and is required as the
#     raw input clock is fed directly to the PLL sections of the AVR for high speed
#     clock generation for the USB and other AVR subsections. Do NOT tack on a 'UL'
#     at the end, this will be done automatically to create a 32-bit value in your
#     source code.
#
#     If no clock division is performed on the input clock inside the AVR (via the
#     CPU clock adjust registers or the clock division fuses), this will be equal to F_CPU.
F_USB = $(F_CPU)

# Interrupt driven control endpoint task(+60)
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT


# Boot Section Size in *bytes*
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = yes # Mouse keys(+4700)
EXTRAKEY_ENABLE  = yes # Audio control and System control(+450)
CONSOLE_ENABLE   = no  # Console for debug(+400)
COMMAND_ENABLE   = no  # Commands for debug and configuration
SLEEP_LED_ENABLE = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE      = no  # USB Nkey Rollover - not yet supported in LUFA
UNICODE_ENABLE   = yes # Enable support for arrow keys icon on the second layer.
COMBO_ENABLE     = yes # Enable combo for special function when using multiple keys at once.
TAP_DANCE_ENABLE = no  # Enable use multiple tap
RGBLIGHT_ENABLE  = yes
BACKLIGHT_ENABLE = no 
AUDIO_ENABLE     = no