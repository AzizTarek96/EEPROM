/*
 * main.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Aziz
 */


#include "STD_TYPES.h"

#include "TWI_interface.h"
#include "PORT_interface.h"
#include "DIO_interface.h"

void main(void)
{
	u8 Local_u8RecievedData;

	PORT_voidInit();

	TWI_voidInitMaster(0);

	EEPROM_voidWriteDataByte(0,0x55);

	Local_u8RecievedData = EEPROM_voidReadDataByte(0);

	DIO_u8SetPortValue(DIO_u8PORTA,Local_u8RecievedData);

	while(1)
	{

	}
}
