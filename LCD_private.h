/*
 * LCD_private.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Aspire
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include "DIO_interface.h"


#define CLEAR_SCREEN            0x01
#define RETURN_HOME             0X02
#define ENTRY_MODE_SET          0X06
#define DISPLAY_ON_CURSER_OFF   0X0C
#define TWO_LINES_4_BIT         0X28

#define SET_DDRAM_ADDRESS  0x80

#endif /* LCD_PRIVATE_H_ */
