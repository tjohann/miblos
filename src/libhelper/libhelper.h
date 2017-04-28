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

#ifndef _LIBHELPER_H_
#define _LIBHELPER_H_

/* more or less common inc */
#include <avr/io.h>
#include <stdlib.h>


/*
 * common defines
 * -------------
 */
#define MY_ON = 1;
#define MY_OFF = 0;

#define MY_OK 0
#define MY_ERROR -1


/*
 * common macros
 * -------------
 */
#ifndef SET_BIT
#define SET_BIT(sfr, bit)			\
	(_SFR_BYTE(sfr) |= (1 << bit))
#endif

#ifndef CLEAR_BIT
#define CLEAR_BIT(sfr, bit)			\
	(_SFR_BYTE(sfr) &= ~(1 << bit))
#endif

#ifndef TOGGLE_BIT
#define TOGGLE_BIT(sfr, bit)			\
	(_SFR_BYTE(sfr) ^= (1 << bit))
#endif


/*
 * libhelper.c
 * ===========
 */
void
helper_convert_ushort_to_string(unsigned char data_string[],
				unsigned short data);

void
helper_convert_uchar_to_string(unsigned char data_string[], unsigned char data);

#endif
