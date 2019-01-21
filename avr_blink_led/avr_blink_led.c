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

#include "avr_blink_led.h"

/*
 * common defines
 *
 * -> DELAYTIME ... the normal blink time
 * -> DELAYTIME_ON_ERROR ... the blinking time to indicate an error
 *
 * -> STATE_UNKNOWN ... state of template is unknown
 * -> STATE_OK ... everthing is up and running
 * -> STATE_ERROR ... an error occured
 * -> STATE_INIT_DONE ... init finished
 * -> STATE_SERIAL_INIT_DONE ... init of serial finished -> used serial
 *                               in error_indication
 * -> ...
 */
#define DELAYTIME 1000
#define DELAYTIME_ON_ERROR 100

// Note: incrising values ... do not change
#define STATE_UNKNOWN 0x00
#define STATE_OK 0x01
#define STATE_ERROR 0x02
#define STATE_SERIAL_INIT_DONE 0x04
#define STATE_INIT_DONE 0x40

// my common state info
unsigned char state_of_blink_led = STATE_UNKNOWN;


/*
 * -> init hw
 */
void
__attribute__((noinline)) init_avr_blink_led(void)
{
	// set ddr for led pin
	SET_BIT(LED_DDR, LED_PIN);
}


/*
 * -> let the led blink on errors or send error_string via serial
 */
void
error_indication(const unsigned char *error_string)
{
#if COMMUNICATION_PATH == __SERIAL__
	if (state_of_blink_led & STATE_SERIAL_INIT_DONE) {
		if (error_string != NULL)
			serial_send_string(error_string);
		else
			SET_BIT(LED_PORT, LED_PIN);
#endif
	} else {
		while (1) {
			SET_BIT(LED_PORT, LED_PIN);
			_delay_ms(DELAYTIME_ON_ERROR);

			CLEAR_BIT(LED_PORT, LED_PIN);
			_delay_ms(DELAYTIME_ON_ERROR);
		}
	}
}

/*
 * set LED on PB0 and clears it after DELAYTIME
 */
int
__attribute__((OS_main)) main(void)
{

#if COMMUNICATION_PATH == __SERIAL__
	const unsigned char greeting_string[] = "hello ... i'm an nano_v3\n\r";
	const unsigned char error_string[] = "an error occured ... pls check\n\r";
	unsigned char byte = 0x31;
#endif


	/*
	 * ---------- serial stuff ----------
	 *
	 * Note: dont use serial & lcd -> PIN conflict
	 */
#if USE_SERIAL == __YES__

#if COMMUNICATION_PATH == __SERIAL__
	// init serial and let the led blink with DELAYTIME_ON_ERROR ms
	serial_setup_async_normal_mode(DATA_8_STOP_1_NO_PARITY);
	if (serial_errno != MY_OK)
		error_indication(error_string);

	// init serial done ... send greetings to peer
	state_of_blink_led |= STATE_SERIAL_INIT_DONE;
	serial_send_string(greeting_string);

	// get an char from peer and send it as ascii
	byte = serial_receive_byte();
	serial_send_byte(byte, SERIAL_SEND_ASCII);
#endif // COMMUNICATION_PATH

#endif

	/*
	 * ---------- init template stuff ----------
	 */
	// infrastructure is ready to use ... so my init is the next step
	init_avr_blink_led();

        /*
	 * ---------- main stuff below ----------
	 */
	_delay_ms(5 * DELAYTIME);

	while (1) {

		// led on
		SET_BIT(LED_PORT, LED_PIN);
		_delay_ms(DELAYTIME);

		// led off
		CLEAR_BIT(LED_PORT, LED_PIN);
		_delay_ms(DELAYTIME);

	}
}
