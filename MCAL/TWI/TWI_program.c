/*****************************************************************/
/*****************************************************************/
/***************		Author: Aziz Tarek		******************/
/***************		Layer: MCAL				******************/
/***************		SWC: TWI				******************/
/***************		Date: 30-11-2023		******************/
/***************		Version: 1.00			******************/
/*****************************************************************/
/*****************************************************************/


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "TWI_interface.h"
#include "TWI_config.h"
#include "TWI_private.h"
#include "TWI_register.h"

void TWI_voidInitMaster(u8 Copy_u8Adress)
{
	TWBR=2;

	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);

	SET_BIT(TWCR,TWCR_TWEA);

	if (Copy_u8Adress != 0)
	{
		TWAR = Copy_u8Adress << 1;
	}
	else
	{

	}

	SET_BIT(TWCR,TWCR_TWEN);
}
void TWI_voidInitSlave(u8 Copy_u8Adress)
{
	SET_BIT(TWCR,TWCR_TWEA);

	TWAR = Copy_u8Adress << 1;

	SET_BIT(TWCR,TWCR_TWEN);

}
TWI_ErrStatus TWI_SendStartCondition(void)
{
	TWI_ErrStatus Loca_Error = NOERROR;

	SET_BIT(TWCR,TWCR_TWSTA);

	SET_BIT(TWCR,TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if( ( TWSR & Status_Mask ) != START_ACK)
	{
		Loca_Error = StartConditionError;
	}
	else
	{

	}

	return Loca_Error;
}
TWI_ErrStatus TWI_SendRepeatedStart(void)
{
	TWI_ErrStatus Loca_Error = NOERROR;

	SET_BIT(TWCR,TWCR_TWSTA);

	SET_BIT(TWCR,TWCR_TWINT);

	while(GET_BIT(TWCR,TWCR_TWINT) == 0);

	if( ( TWSR & Status_Mask ) != REP_START_ACK)
	{
		Loca_Error = RepeatedStartError;
	}
	else
	{

	}

	return Loca_Error;

}
TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Loca_Error = NOERROR;

	//CLR_BIT(TWCR,TWCR_TWSTA);

	TWDR = Copy_u8SlaveAddress << 1;
	CLR_BIT(TWDR,0);

	//SET_BIT(TWCR,TWCR_TWINT);
	TWCR = (1<<TWCR_TWEA)  |  (1<<TWCR_TWEN)  |  (1<<TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);
	if((TWSR & Status_Mask) != SLAVE_ADD_AND_WR_ACK )
	{
		Loca_Error = SlaveAddressWithWriteError;
	}
	else
	{

	}

	return Loca_Error;
}
TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrStatus Loca_Error = NOERROR;

	//CLR_BIT(TWCR,TWCR_TWSTA);



	TWDR = Copy_u8SlaveAddress << 1;
	SET_BIT(TWDR,0);

	//SET_BIT(TWCR,TWCR_TWINT);
	TWCR = (1<<TWCR_TWEA)  |  (1<<TWCR_TWEN)  |  (1<<TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);
	if((TWSR & Status_Mask) != SLAVE_ADD_AND_RD_ACK )
	{
		Loca_Error = SlaveAddressWithReadError;
	}

	return Loca_Error;
}
TWI_ErrStatus TWI_MasterSendDataByte(u8 Copy_u8DataByte)
{
	TWI_ErrStatus Loca_Error = NOERROR;

	TWDR = Copy_u8DataByte;

	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);
	if((TWSR & Status_Mask) != MSTR_WR_BYTE_ACK)
	{
		Loca_Error = MasterWriteByteError;
	}
	else
	{

	}

	return Loca_Error;
}
TWI_ErrStatus TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	TWI_ErrStatus Loca_Error = NOERROR;

	SET_BIT(TWCR,TWCR_TWINT);
	while(GET_BIT(TWCR,TWCR_TWINT) == 0);
	if((TWSR & Status_Mask) != MSTR_RD_BYTE_WITH_ACK)
	{
		Loca_Error = MasterReadByteError;
	}
	else
	{
		*Copy_pu8DataByte = TWDR;
	}

	return Loca_Error;

}
TWI_ErrStatus TWI_SendStopCondition(void)
{
	TWI_ErrStatus Loca_Error = NOERROR;

	SET_BIT(TWCR,TWCR_TWSTO);

	SET_BIT(TWCR,TWCR_TWINT);

	return Loca_Error;
}
