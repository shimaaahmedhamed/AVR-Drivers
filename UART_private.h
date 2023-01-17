/*
 * UART_private.h
 *
 *  Created on: Nov 15, 2022
 *      Author: Aspire
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_private.h"
#include"DIO_interface.h"

#define UDR    *((volatile u8*)0x2C)     //register for transmit and recieve data

#define UCSRA  *((volatile u8*)0x2B)     //control and status
#define MPCM  PIN0
#define U2X   PIN1
#define PE    PIN2
#define DOR   PIN3
#define FE    PIN4
#define UDRE  PIN5
#define TXC   PIN6
#define RXC   PIN7

#define UCSRB  *((volatile u8*)0x2A)     //control and status
#define TXB8  PIN0
#define RXB8  PIN1
#define UCSZ2 PIN2
#define TXEN  PIN3
#define RXEN  PIN4
#define UDRIE PIN5
#define TXCIE PIN6
#define RXCIE PIN7

#define UCSRC  *((volatile u8*)0x40)     //control and status
#define UCPOL PIN0
#define UCSZ0 PIN1
#define UCSZ1 PIN2
#define USBS  PIN3
#define UPM0  PIN4
#define UPM1  PIN5
#define UMSEL PIN6
#define URSEL PIN7

#define UBRRL   *((volatile u8*)0x29)    //register baud
#define UBRRH   *((volatile u8*)0x40)    //register baud

#endif /* UART_PRIVATE_H_ */
