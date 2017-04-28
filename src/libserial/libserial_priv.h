/*
  GPL
  (c) 2014-2017, thorsten.johannvorderbrueggen@t-online.de

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

#ifndef _LIBSERIAL_PRIV_H_
#define _LIBSERIAL_PRIV_H_

#include <libhelper.h>
#include "libserial.h"
#include <avr/io.h>
#include <util/setbaud.h>
#include <stdlib.h>


#ifdef SERIAL_ERROR
#ifndef SERIAL_ERRNO
#define SERIAL_ERRNO
unsigned char serial_errno = MY_OK;
#endif
#else
# warning "No special serial error indication!"
#endif


typedef enum {
	ASYNC_NORMAL = 0x01,
	ASYNC_DOUBLE,
	SYNC_MASTER,  /* no double in sync -> U2Xn=0 */
	SYNC_SLAVE,
	MASTER_SPI    /* TODO: Check that */
} serial_op_mode_t;


typedef enum {
	ENA_RX = 0x01,
	ENA_TX,
	ENA_ALL
} serial_enable_rxtx_t;


/*
 * error string
 */
unsigned char *serial_error_string = (unsigned char *) "SERIAL_ERROR";

/*
 * setting operation mode of usart
 */
#define SERIAL_SET_ASYNC_MODE()			\
	{					\
		UCSR0C &= ~(1 << UMSEL00);	\
		UCSR0C &= ~(1 << UMSEL01);	\
	}

#define SERIAL_SET_SYNC_MODE()			\
	{					\
		UCSR0C |= (1 << UMSEL00);	\
		UCSR0C &= ~(1 << UMSEL01);	\
	}

/* TODO: Check that */
#define SERIAL_SET_MASTER_SPI_MODE()		\
	{					\
		UCSR0C |= (1 << UMSEL00);	\
		UCSR0C |= (1 << UMSEL01);	\
	}


/*
 * set frame type
 */
#define SERIAL_SET_5_DATA_BITS()		\
	{					\
		UCSR0C &= ~(1 << UCSZ00);	\
		UCSR0C &= ~(1 << UCSZ01);	\
		UCSR0B &= ~(1 << UCSZ02);	\
	}

#define SERIAL_SET_6_DATA_BITS()		\
	{					\
		UCSR0C |= (1 << UCSZ00);	\
		UCSR0C &= ~(1 << UCSZ01);	\
		UCSR0B &= ~(1 << UCSZ02);	\
	}

#define SERIAL_SET_7_DATA_BITS()		\
	{					\
		UCSR0C &= ~(1 << UCSZ00);	\
		UCSR0C |= (1 << UCSZ01);	\
		UCSR0B &= ~(1 << UCSZ02);	\
	}

#define SERIAL_SET_8_DATA_BITS()		\
	{					\
		UCSR0C |= (1 << UCSZ00);	\
		UCSR0C |= (1 << UCSZ01);	\
		UCSR0B &= ~(1 << UCSZ02);	\
	}

#define SERIAL_SET_9_DATA_BITS()		\
	{					\
		UCSR0C |= (1 << UCSZ00);        \
		UCSR0C |= (1 << UCSZ01); 	\
		UCSR0B |= (1 << UCSZ02);	\
	}

#define SERIAL_SET_1_STOP_BIT()			\
	{					\
		UCSR0C &= ~(1 << USBS0);	\
	}

#define SERIAL_SET_2_STOP_BITS()		\
	{					\
		UCSR0C |= (1 << USBS0);		\
	}

#define SERIAL_SET_NO_PARITY()			\
	{					\
		UCSR0C &= ~(1 << UPM00);	\
		UCSR0C &= ~(1 << UPM01);	\
	}

#define SERIAL_SET_ODD_PARITY()			\
	{					\
		UCSR0C |= (1 << UPM00);		\
		UCSR0C |= (1 << UPM01);		\
	}

#define SERIAL_SET_EVEN_PARITY()		\
	{					\
		UCSR0C &= ~(1 << UPM00);	\
		UCSR0C |= (1 << UPM01);		\
	}


/*
 * enable/disable U2X0
 */
#define SERIAL_ENA_DOUBLE_SPEED()		\
	{					\
		UCSR0A |= (1 << U2X0);		\
	}

#define SERIAL_DIS_DOUBLE_SPEED()		\
	{					\
		UCSR0A &= ~(1 << U2X0);		\
	}


/*
 * enable/disable TX/RX
 */
#define SERIAL_ENA_TX()				\
	{					\
		UCSR0B |= (1 << TXEN0);		\
	}

#define SERIAL_DIS_TX()				\
	{					\
		UCSR0B &= ~(1 << TXEN0);	\
	}

#define SERIAL_ENA_RX()				\
	{					\
		UCSR0B |= (1 << RXEN0);		\
	}

#define SERIAL_DIS_RX()				\
	{					\
		UCSR0B &= ~(1 << RXEN0);	\
	}

#define SERIAL_ENA_RXTX()			\
	{					\
		UCSR0B |= (1 << TXEN0);		\
		UCSR0B |= (1 << RXEN0);		\
	}

#define SERIAL_DIS_RXTX()			\
	{					\
	        UCSR0B &= ~(1 << TXEN0);	\
		UCSR0B &= ~(1 << RXEN0);	\
	}

#define SERIAL_ENA_ALL()			\
	{					\
		UCSR0B = (1 << TXEN0) | (1 << RXEN0);	\
	}

#define SERIAL_DIS_ALL()			\
	{					\
	        UCSR0B &= ~(1 << TXEN0);	\
		UCSR0B &= ~(1 << RXEN0);	\
	}

#endif
