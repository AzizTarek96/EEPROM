/*****************************************************************/
/*****************************************************************/
/***************		Author: Aziz Tarek		******************/
/***************		Layer: HAL				******************/
/***************		SWC: EEPROM				******************/
/***************		Date: 30-11-2023		******************/
/***************		Version: 1.00			******************/
/*****************************************************************/
/*****************************************************************/


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_voidWriteDataByte (u16 Copy_u16LocationAddress , u8 Copy_u8DataByte);

u8 EEPROM_voidReadDataByte ( u16 Copy_u16LocationAddress);



#endif
