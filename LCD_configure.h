/*
 * LCD_configure.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Aspire
 */

#ifndef LCD_CONFIGURE_H_
#define LCD_CONFIGURE_H_

#include"LCD_interface.h"
#define MODE       4BIT
#define RS_PORT    PORTA_ID
#define RS_PIN     PIN3


#define EN_PORT    PORTA_ID
#define EN_PIN     PIN2

#define D4_PORT    PORTB_ID
#define D4_PIN     PIN0

#define D5_PORT    PORTB_ID
#define D5_PIN     PIN1

#define D6_PORT    PORTB_ID
#define D6_PIN     PIN2

#define D7_PORT    PORTB_ID
#define D7_PIN     PIN4

#endif /* LCD_CONFIGURE_H_ */
