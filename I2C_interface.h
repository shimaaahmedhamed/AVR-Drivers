/*
 * I2C_interface.h
 *
 *  Created on: Nov 19, 2022
 *      Author: Aspire
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include"I2C_private.h"

typedef enum
{
I2C_OK,
I2C_NOK,
START_COND_ERROR,
STOP_COND_ERROR,
SLAVE_ADDRESS_WRITE_ERROR,
SLAVE_ADDRESS_READ_ERROR,
DATA_MASTER_SEND_ERROR,
DATA_MASTER_RECIEVE_ERROR,
DATA_SLAVE_SEND_ERROR,
DATA_SLAVE_RECIEVE_ERROR


}I2C_ERROR;


void I2C_VOIDMASTER_INIT(void);

void I2C_VOIDSLAVE_INIT(u8 slave_add);

I2C_ERROR send_start_condition(void);

I2C_ERROR send_stop_condition(void);

I2C_ERROR send_slave_addresswrite(u8 slave_add);

I2C_ERROR send_slave_addressread(u8 slave_add);

I2C_ERROR send_DATAMASTER(u8 data);

I2C_ERROR RECIEVE_DATAMASTER(u8 *data);

I2C_ERROR send_DATASLAVE(u8 data);

I2C_ERROR RECIEVE_DATASLAVE(u8 *data);



#endif /* I2C_INTERFACE_H_ */
