/*
 *
 *  Created on: Nov 11, 2022
 *      Author: Aspire
 */


#include "LCD_configure.h"
#include "util/delay.h"

void writebittosend(u8 byte)
{
	DIO_voidSetPinValue( EN_PORT, EN_PIN, PIN_LOW);

	DIO_voidSetPinValue(D7_PORT, D7_PIN, (byte>>7) & 1 );
	DIO_voidSetPinValue(D6_PORT, D6_PIN, (byte>>6) & 1 );
	DIO_voidSetPinValue(D5_PORT, D5_PIN, (byte>>5) & 1 );
	DIO_voidSetPinValue(D4_PORT, D4_PIN, (byte>>4) & 1 );

	DIO_voidSetPinValue( EN_PORT, EN_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue( EN_PORT, EN_PIN, PIN_LOW);
	_delay_ms(30);

	DIO_voidSetPinValue(D7_PORT, D7_PIN, (byte>>3) & 1 );
	DIO_voidSetPinValue(D6_PORT, D6_PIN, (byte>>2) & 1 );
	DIO_voidSetPinValue(D5_PORT, D5_PIN, (byte>>1) & 1 );
	DIO_voidSetPinValue(D4_PORT, D4_PIN, (byte>>0) & 1 );

	DIO_voidSetPinValue( EN_PORT, EN_PIN, PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue( EN_PORT, EN_PIN, PIN_LOW);
	_delay_ms(30);

}

void LCD_INIT(void)
{
	_delay_ms(30);
	DIO_voidSetPinDirection(RS_PORT, RS_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(EN_PORT, EN_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(D7_PORT, D7_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(D6_PORT, D6_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(D5_PORT, D5_PIN, PIN_OUTPUT);
	DIO_voidSetPinDirection(D4_PORT, D4_PIN, PIN_OUTPUT);



	LCD_WRITE_COMMAND(TWO_LINES_4_BIT);
	_delay_ms(2);
	LCD_WRITE_COMMAND(DISPLAY_ON_CURSER_OFF);
	_delay_ms(2);
	LCD_WRITE_COMMAND(CLEAR_SCREEN);
	_delay_ms(2);
	LCD_WRITE_COMMAND(ENTRY_MODE_SET);


}

void LCD_WRITE_COMMAND(u8 command)
{
	DIO_voidSetPinValue(RS_PORT, RS_PIN, PIN_LOW);
	writebittosend(command);
}

void LCD_WRITE_DATA(u8 data)
{
	DIO_voidSetPinValue(RS_PORT, RS_PIN, PIN_HIGH);
	writebittosend(data);
}

void LCD_WRITE_STRING(u8 *str)
{
	u32 i=0;
	while(str[i] !='\0')
	{
		LCD_WRITE_DATA(str[i]);
		i++;

	}
}

void LCD_voidClear(void)
{
	LCD_WRITE_COMMAND(CLEAR_SCREEN);
}
void LCD_voidGoToXY(u8 copy_u8row,u8 copy_u8col)
{

	static u8 local_address ;
	if(copy_u8row == 0)
	{
		local_address =copy_u8col ;
	}
	else if(copy_u8row == 1)
	{
		local_address =0x40+copy_u8col ;
	}

}
void LCD_voidWriteInt(int data)
{
   u16 buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_WRITE_STRING(buff); /* Display the string */
}




