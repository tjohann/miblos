/*
  GPL
  (c) 2014-2016, thorsten.johannvorderbrueggen@t-online.de

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

#ifndef _LIBSERIAL_H_
#define _LIBSERIAL_H_

#include <avr_compile_macros.h>
#include <libhelper.h>


#ifndef F_CPU
#  error "Freq of CPU not defined!"
#endif

#if USE_SERIAL == __YES__
#ifndef BAUD
#define BAUD  9600UL
#  warning "Baud rate not defined, use 9600"
#endif
#endif

/*
 * serial specific error codes
 */
typedef enum {
	SERIAL_RCV_ERROR = 0x01,
	SERIAL_SEND_ERROR,
	SERIAL_INIT_DEFAULT,
	SERIAL_RCV_DEFAULT,
	SERIAL_SEND_DEFAULT,
	SERIAL_UNKNOWN
} serial_errors_t;


/*
 * serial errno stuff
 *
 * HOTWO: use serial_errno
 * -> a global variable is defined and set to default by
 *    this lib -> unsigned char serial_errno = MY_OK;
 * -> in YOUR header file add the following declaration
 *    extern unsigned char serial_errno;
 * -> if something goes wrong, then the functions set serial_errno to
 *    an value of serial_errors_t
 * -> if everthing works fine, then serial_errno is set to MY_OK (see libhelper.h)
 * -> for an example see template.* in src/template
 *
 * Note: of course not reentrant
 *       SERIAL_ERROR is the general switch
 *       SERIAL_ERRNO for serial_errno which holds serial_error_t values
 *       unsigned char * serial_error_string = "SERIAL_ERROR" for a common error string
 *
 * Hint: its only tested in small range of possible clock and baud rates ... so
 *       i am not shure if everthing works fine!
 *
 * Tested with:    MCU=atmega168p
 *                 F_CPU=1000000
 *                 BAUD=9600
 *                 8 databits / 1 stop bit / no parity
 *                -----------------
 */
#ifndef SERIAL_ERROR
#define SERIAL_ERROR OFF
#  warning "SERIAL_ERROR not defined, use OFF"
#endif


/*
 * HOWTO: configuration of the USART0
 *
 * -> function serial_setup_asyn_normal_mode for normal mode ...
 * -> function serial_setup_asyn_double_speed for async mode with double speed ...
 *    enabled via U2xn=1
 * -> serial_setup_sync_master for sync master mode
 *
 * Note: baudrate via #define BAUD 9600UL if not via -DBAUD=9600UL
 *       frame mode (example: 8 databit, 1 stop bit, no parity) via serial_frame_type_t
 */
typedef enum {
        DATA_8_STOP_1_NO_PARITY = 0x01
} serial_frame_type_t;


/*
 * -> available modes for serial_send_byte function
 *
 * Note: example ... input 1
 *                   SERIAL_SEND_NORMAL -> send an 1
 *                   SERIAL_SEND_ASCCII -> send 049
 */
typedef enum {
	SERIAL_SEND_NORMAL = 0x01,
	SERIAL_SEND_ASCII
} serial_send_mode_t;


/*
 * ----------- functions for init/setup of USART -----------
 */

/*
 * -> setup USART0 for async mode at normal speed ... U2Xn=0
 *
 * contraints: enable rx and tx
 * serial_errno: SERIAL_INIT_DEFAULT
 */
void
serial_setup_async_normal_mode(serial_frame_type_t frame_type);

/*
 * -> setup USART0 for async mode at double speed ... U2Xn=1
 *
 * contraints: enable rx and tx
 * serial_errno: SERIAL_INIT_DEFAULT
 */
void
serial_setup_async_double_speed(serial_frame_type_t frame_type);

/*
 * -> setup USART0 for sync master mode
 *
 * contraints: enable rx and tx
 * serial_errno: SERIAL_INIT_DEFAULT
 */
void
serial_setup_sync_master(serial_frame_type_t frame_type);

/*
 * -> setup USART0 for sync slave mode
 *
 * contraints: enable rx and tx
 * serial_errno: SERIAL_INIT_DEFAULT
 */
void
serial_setup_sync_slave(serial_frame_type_t frame_type);


/*
 * ----------- functions for reading from USART -----------
 */

/*
 * -> receive data (polling)
 *
 * contrains: check for 9 databits
 * serial_errno: SERIAL_RCV_ERROR
 */
unsigned short
serial_receive_data();

/*
 * -> receive byte (polling)
 *
 *  serial_errno: SERIAL_RCV_ERROR
 */
unsigned char
serial_receive_byte();

/*
 * -> receive string (polling)
 *
 *  serial_errno: SERIAL_RCV_ERROR
 */
unsigned char *
serial_receive_string(const unsigned char size);


/*
 * ----------- functions for writing from USART -----------
 */

/*
 * -> send data (polling)
 *
 * contrains: check for 9 databits
 * serial_errno: no usage
 */
void
serial_send_data(const unsigned short data);

/*
 * -> send byte (polling)
 *
 * note: if you set mode to ASCII it will send the corresponding
 *       ASCII char instead of the value
 *       example: 0x01 in SERIAL_SEND_NORMAL and
 *                0x01 + 0x30 in SERIAL_SEND_ASCII
 * serial_errno: SERIAL_RCV_DEFAULT
 */
void
serial_send_byte(const unsigned char byte,
		 serial_send_mode_t mode);

/*
 * -> send string (polling)
 *
 * contrains: only bytes ... no 9. bit handling
 * serial_errno: no usage
 */
void
serial_send_string(const unsigned char *data);

#endif
