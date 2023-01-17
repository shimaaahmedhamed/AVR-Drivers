/*
 * UART_interface.h
 *
 *  Created on: Nov 15, 2022
 *      Author: Aspire
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "UART_private.h"

#define SYNCHRONOUS      0
#define ASYNCHRONOUS     1

#define DISABLED          0
#define EVEN              1
#define ODD               2

#define ONE_BIT            0
#define TWO_BIT           1

#define FIVE_BIT          0
#define SIX_BIT           1
#define SEVEN_BIT         2
#define EIGHT_BIT         3
#define NINE_BIT          4


void UART_INIT(u16 baud);

void UART_DATA_TRANSMITT(u8 data);

void UART_SEND_STRING(u8 *string);

u8 UART_DATA_RECIEVE(void);


#endif /* UART_INTERFACE_H_ */
