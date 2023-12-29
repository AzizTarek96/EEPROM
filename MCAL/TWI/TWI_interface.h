/*****************************************************************/
/*****************************************************************/
/***************		Author: Aziz Tarek		******************/
/***************		Layer: MCAL				******************/
/***************		SWC: TWI				******************/
/***************		Date: 30-11-2023		******************/
/***************		Version: 1.00			******************/
/*****************************************************************/
/*****************************************************************/

typedef enum
{
	NOERROR,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterWriteByteError,
	MasterReadByteError,
}TWI_ErrStatus;


#ifndef		TWI_INTERFACE_H_
#define		TWI_INTERFACE_H_

/* Pass 0 to the adress argument if this Master node will be not adressed*/
void TWI_voidInitMaster(u8 Copy_u8Adress);

void TWI_voidInitSlave(u8 Copy_u8Adress);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterSendDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

TWI_ErrStatus TWI_MasterRFlush();

TWI_ErrStatus TWI_SendStopCondition(void);

#endif
