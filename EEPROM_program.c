/*****************************************************************/
/*****************************************************************/
/***************		Author: Aziz Tarek		******************/
/***************		Layer: HAL				******************/
/***************		SWC: EEPROM				******************/
/***************		Date: 30-11-2023		******************/
/***************		Version: 1.00			******************/
/*****************************************************************/
/*****************************************************************/


#include "STD_TYPES.h"
#include <util/delay.h>

#include "TWI_interface.h"

#include "EEPROM_interface.h"
#include "EEPROM_config.h"
#include "EEPROM_private.h"


void EEPROM_voidWriteDataByte (u16 Copy_u16LocationAddress , u8 Copy_u8DataByte)
{
	u8 Local_u8AddressPacket;

	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION << 2) | (u8)(Copy_u16LocationAddress >> 8);

	TWI_SendStartCondition();

	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

	TWI_MasterSendDataByte((u8)Copy_u16LocationAddress);

	TWI_MasterSendDataByte(Copy_u8DataByte);

	TWI_SendStopCondition();

	_delay_ms(10);
}
u8 EEPROM_voidReadDataByte ( u16 Copy_u16LocationAddress)
{
	u8 Local_u8AddressPacket , Local_u8RecievedData;

	Local_u8AddressPacket = EEPROM_FIXED_ADDRESS | (A2_CONNECTION<<2) | (u8)(Copy_u16LocationAddress>>8);

	TWI_SendStartCondition();

	TWI_SendSlaveAddressWithWrite(Local_u8AddressPacket);

	TWI_MasterSendDataByte((u8)Copy_u16LocationAddress);

	TWI_SendRepeatedStart();

	TWI_SendSlaveAddressWithRead(Local_u8AddressPacket);

	TWI_MasterReadDataByte(&Local_u8RecievedData);

	TWI_SendStopCondition();

	return Local_u8RecievedData;

}
