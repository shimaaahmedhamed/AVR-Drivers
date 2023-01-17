/*
 * I2C_private.h
 *
 *  Created on: Nov 19, 2022
 *      Author: Aspire
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_interface.h"

#define I2C_TWBR         *((volatile u8*)0x20)                 //BIT RATE REGISTER

#define I2C_TWCR         *((volatile u8*)0x56)                   //CONTROL REGISTER
#define I2C_TWIE     PIN0
#define I2C_TWEN     PIN2
#define I2C_TWWC     PIN3
#define I2C_TWSTO    PIN4
#define I2C_TWSTA    PIN5
#define I2C_TWEA     PIN6
#define I2C_TWINT    PIN7

#define I2C_TWSR         *((volatile u8*)0x21)                   //STATUS REGISTER
#define I2C_TWPS0   PIN0
#define I2C_TWPS1   PIN1
#define I2C_TWS3    PIN3
#define I2C_TWS4    PIN4
#define I2C_TWS5    PIN5
#define I2C_TWS6    PIN6
#define I2C_TWS7    PIN7

#define I2C_TWDR         *((volatile u8*)0x23)                   //DATA REGISTER

#define I2C_TWAR         *((volatile u8*)0x22)                  //SLAVE ADDRESS REGISTER

#endif /* I2C_PRIVATE_H_ */
