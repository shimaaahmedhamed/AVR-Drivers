/*
 * LCD_interface.h
 *
 *  Created on: Nov 11, 2022
 *      Author: Aspire
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_private.h"

void writebittosend(u8 byte);
void LCD_INIT(void);
void LCD_WRITE_COMMAND(u8 command);
void LCD_WRITE_DATA(u8 data);
void LCD_WRITE_STRING(u8 *str);
void LCD_voidClear(void);
void LCD_voidGoToXY(u8 copy_u8row,u8 copy_u8col);
void LCD_voidWriteInt(int data);

#endif /* LCD_INTERFACE_H_ */
