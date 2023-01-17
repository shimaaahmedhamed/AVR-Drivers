/*
 * DIO_interface.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Aspire
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_private.h"

#define PORTA_ID    0
#define PORTB_ID    1
#define PORTC_ID    2
#define PORTD_ID    3

#define PIN0       0
#define PIN1       1
#define PIN2       2
#define PIN3       3
#define PIN4       4
#define PIN5       5
#define PIN6       6
#define PIN7       7



#define PIN_OUTPUT 0x01
#define PIN_INPUT  0x00

#define PIN_HIGH   0x01
#define PIN_LOW    0x00


void DIO_voidSetPinDirection(u8 PORT_ID, u8 PIN_ID, u8 DDR_ID);
void DIO_voidSetPinValue(u8 PORT_ID, u8 PIN_ID, u8 value_ID);
void DIO_voidToggelPin(u8 copy_u8PortID,u8 copy_u8PinID);
u8 DIO_voidGetBitValue(u8 copy_u8PortID , u8 copy_PinID );

#endif /* DIO_INTERFACE_H_ */

