/*
  GPL
  (c) 2019, thorsten.johannvorderbrueggen@t-online.de

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*/

#include <avr/io.h>

#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <string.h>
#include <stdbool.h>
#include <avr/interrupt.h>
#include <util/atomic.h>

/*
 * -> my avr_sdk libs
 */
#include <avr_compile_macros.h>
#include <libhelper.h>
#include <libserial.h>


// make shure that COMMUNICATION_PATH is available
#ifndef COMMUNICATION_PATH
#error "COMMUNICATION_PATH not defined"
#endif

/*
 * -> use serial_errno
 */
extern unsigned char serial_errno;

/*
 * special pins for blinking ...
 */
#define LED_PIN PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

/*
 * -> the global msg
 */
volatile bool update = false;

