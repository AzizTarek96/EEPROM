/*
 * main.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Aziz
 */


#include "../LIB/STD_TYPES.h"

#include "../MCAL/TWI/TWI_interface.h"
#include "../MCAL/PORT/PORT_interface.h"
#include "../MCAL/DIO/DIO_interface.h"

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
