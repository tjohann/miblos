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

#include "libhelper.h"

void
helper_convert_ushort_to_string(unsigned char data_string[],
				unsigned short data)
{
	data_string[4] = 0x30 + (data % 10);
	data_string[3] = 0x30 + ((data / 10) % 10);
	data_string[2] = 0x30 + ((data / 100) % 10);
	data_string[1] = 0x30 + ((data / 1000) % 10);
	data_string[0] = 0x30 + (data / 10000);
}

void
helper_convert_uchar_to_string(unsigned char data_string[], unsigned char data)
{
	data_string[2] = 0x30 + (data % 10);
	data_string[1] = 0x30 + ((data / 10) % 10);
	data_string[0] = 0x30 + (data / 100);
}
