/*
 * I2C_program.c
 *
 *  Created on: Nov 19, 2022
 *      Author: Aspire
 */

#include"I2C_interface.h"
#include"I2C_configure.h"

I2C_ERROR local_enum = I2C_NOK;

void I2C_VOIDMASTER_INIT(void)       //SET BIT RATE = 100KHZ
{

I2C_TWBR = 72;
SET_BIT(I2C_TWCR,I2C_TWEN);         //ENABLE TWI
SET_BIT(I2C_TWCR,I2C_TWEA);         //ENABLE ACKNOWLAGE
I2C_TWAR = (MASTER_ADDRESS<<1);

}

void I2C_VOIDSLAVE_INIT(u8 slave_add)  //SLAVE ADDRESS , ENABLE
{
	SET_BIT(I2C_TWCR,I2C_TWEA);        //ENABLE ACKNOWLAGE
	SET_BIT(I2C_TWCR,I2C_TWEN);        //ENABLE TWI
	I2C_TWAR = (slave_add<<1);         //ASSIGN SLAVE ADDRESS

}

I2C_ERROR send_start_condition(void)
{

SET_BIT(I2C_TWCR,I2C_TWINT);               //CLEAR FLAG
SET_BIT(I2C_TWCR,I2C_TWSTA);               //SEND START CONDITION

while(GET_BIT(I2C_TWCR,I2C_TWINT)==0);     //wait on flag

 if((I2C_TWSR & 0XF8) == 0x08)               //ERROR CHECK *IMPORTANT*
 {

	 local_enum = I2C_OK;

 }

 else
 {
	 local_enum = START_COND_ERROR;

 }

	 return local_enum;
}

I2C_ERROR send_stop_condition(void)
{

	SET_BIT(I2C_TWCR,I2C_TWINT);       //CLEAR FLAG
	SET_BIT(I2C_TWCR,I2C_TWSTO);       //SEND STOP CONDITION

	while(GET_BIT(I2C_TWCR,I2C_TWINT)==0);     //wait on flag

	 if((I2C_TWSR & 0XF8) == 0xA0)  //ERROR CHECK *IMPORTANT*
	 {
		 local_enum = I2C_OK;

	 }

	 else

	 {
		local_enum=STOP_COND_ERROR;

	 }

	 return local_enum;


}

I2C_ERROR send_slave_addresswrite(u8 slave_add)
{

	SET_BIT(I2C_TWCR,I2C_TWINT);       //CLEAR FLAG

	CLR_BIT(I2C_TWCR,I2C_TWSTA);       //CLEAR START CONDITION

	I2C_TWDR = (slave_add<<1);

		 //CLR_BIT(I2C_TWDR,0);                   //FOR WRITE OPERATION FIRST BIT=ZERO

		while(GET_BIT(I2C_TWCR,I2C_TWINT)==0);     //wait on flag


		 if((I2C_TWSR & 0XF8) ==0X18 )  //ERROR CHECK *IMPORTANT*
		 {
			local_enum = I2C_OK;

		 }

		 else

		 {
			local_enum=SLAVE_ADDRESS_WRITE_ERROR;

		 }

		 return local_enum;




}

I2C_ERROR send_slave_addressread(u8 slave_add)
{

		SET_BIT(I2C_TWCR,I2C_TWINT);       //CLEAR FLAG

		CLR_BIT(I2C_TWCR,I2C_TWSTA);       //CLEAR START CONDITION

		I2C_TWDR = (slave_add<<1);

			 SET_BIT(I2C_TWDR,0);                  //FOR READ OPERATION FIRST BIT =ONE

			while(GET_BIT(I2C_TWCR,I2C_TWINT)==0);     //wait on flag


			 if((I2C_TWSR & 0XF8 )== 0X40)  //ERROR CHECK *IMPORTANT*
			 {
				local_enum = I2C_OK;

			 }

			 else

			 {
				local_enum=SLAVE_ADDRESS_READ_ERROR;

			 }

			 return local_enum;

}

I2C_ERROR send_DATAMASTER(u8 data)
{

	SET_BIT(I2C_TWCR,I2C_TWINT);                   //CLEAR FLAG

	I2C_TWDR = data;                               //SET DATA

		while(GET_BIT(I2C_TWCR,I2C_TWINT)==0);     //wait on flag


			 if((I2C_TWSR & 0XF8) == 0X28 )  //ERROR CHECK *IMPORTANT*
			 {
				local_enum = I2C_OK;

			 }

			 else

			 {
				 local_enum=DATA_MASTER_SEND_ERROR;

			 }

			 return local_enum;

}

I2C_ERROR RECIEVE_DATAMASTER(u8 *data)
{
	SET_BIT(I2C_TWCR,I2C_TWINT);                   //CLEAR FLAG

			while(GET_BIT(I2C_TWCR,I2C_TWINT)==0);     //wait on flag


				 if((I2C_TWSR & 0XF8) == 0X50 )  //ERROR CHECK *IMPORTANT*
				 {
					local_enum = I2C_OK;
					*data  = I2C_TWDR;

				 }

				 else

				 {
					 local_enum=DATA_MASTER_RECIEVE_ERROR;

				 }

				 return local_enum;
}

I2C_ERROR send_DATASLAVE(u8 data)
{
	SET_BIT(I2C_TWCR,I2C_TWINT);                   //CLEAR FLAG

		I2C_TWDR = data;                               //SET DATA

			while(GET_BIT(I2C_TWCR,I2C_TWINT)==0);     //wait on flag


				 if((I2C_TWSR & 0XF8) == 0XB8 )  //ERROR CHECK *IMPORTANT*
				 {
					local_enum = I2C_OK;

				 }

				 else

				 {
					 local_enum=DATA_SLAVE_SEND_ERROR;

				 }

				 return local_enum;
}

I2C_ERROR RECIEVE_DATASLAVE(u8 *data)
{
	SET_BIT(I2C_TWCR,I2C_TWINT);                   //CLEAR FLAG

				while(GET_BIT(I2C_TWCR,I2C_TWINT)==0);     //wait on flag


					 if((I2C_TWSR & 0XF8) == 0X80 )  //ERROR CHECK *IMPORTANT*
					 {
						local_enum = I2C_OK;
						*data  = I2C_TWDR;

					 }

					 else

					 {
						 local_enum=DATA_SLAVE_RECIEVE_ERROR;

					 }

					 return local_enum;

}
