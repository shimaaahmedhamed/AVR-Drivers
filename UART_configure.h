/*
 * UART_configure.h
 *
 *  Created on: Nov 15, 2022
 *      Author: Aspire
 */

#ifndef UART_CONFIGURE_H_
#define UART_CONFIGURE_H_

#include"UART_interface.h"
//SYNCHRONOUS OR ASYNCHRONOUS
#define MODE_SELECT      ASYNCHRONOUS


//DISABLED OR EVEN OR ODD
#define PARITY_MODE      EVEN

//FIVE-BIT OR SIX-BIT OR SEVEN-BIT OR EIGHT-BIT OR NINE-BIT
#define BIT_SETTING   EIGHT_BIT

//ONE-BIT OR TWO-BIT
#define STOP_BIT_SELECT   ONE_BIT


#endif /* UART_CONFIGURE_H_ */
