/*
 * keypad_configure.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Aspire
 */

#ifndef KEYPAD_CONFIGURE_H_
#define KEYPAD_CONFIGURE_H_

#include "DIO_interface.h"
#include"keypad_interface.h"

#define COLOUMN_PORT    PORTD_ID
#define ROW_PORT        PORTB_ID

#define COLOUMN_START_PIN   PIN2
#define COLOUMN_END_PIN     PIN5

#define ROW_START_PIN   PIN4
#define ROW_END_PIN     PIN7

#endif /* KEYPAD_CONFIGURE_H_ */
