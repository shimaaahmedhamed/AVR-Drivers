/*
 * keypad_program.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Aspire
 */

#include "keypad_configure.h"
#include "DIO_interface.h"
#include "avr/delay.h"



u8 SwitchVal[ROW_SIZE][COL_SIZE]=
{
		{0x00, 0x01, 0x02,0x03  },
		{0x04,0x05, 0x06, 0x07 },
		{0x08, 0x09, 0x0A, 0x0B },
		{0x0C, 0x0D, 0x0E, 0x0F }
};

void KPD_voidInit()
{
	for (u8 PinID = ROW_START_PIN; PinID <= ROW_END_PIN; PinID++)
	{
		DIO_voidSetPinDirection(ROW_PORT, PinID, PIN_OUTPUT);

	}

	for (u8 PinID = COLOUMN_START_PIN; PinID <= COLOUMN_END_PIN; PinID++)
	{
		DIO_voidSetPinDirection(COLOUMN_PORT, PinID, PIN_INPUT);
		DIO_voidSetPinValue(COLOUMN_PORT, PinID, PIN_HIGH);
	}

}
u8 KPD_voidGetPressedKey()
{
	u8 Column, Row, PinVal;
		u8 local_u8_PressedKey = KPD_NOT_PRESSED;

		for (Row = ROW_START_PIN; Row <= ROW_END_PIN; Row++)
		{
			DIO_voidSetPinValue(ROW_PORT, Row, PIN_LOW); /* Activate the ROW */

			for (Column = COLOUMN_START_PIN; Column <= COLOUMN_END_PIN; Column++)
			{
				PinVal=DIO_voidGetBitValue(COLOUMN_PORT, Column); /* Check the status of the switch */

				if (PinVal == 0)
				{
					local_u8_PressedKey = SwitchVal[Row - ROW_START_PIN][Column - COLOUMN_START_PIN]; /* Get the value of the currently pressed switch */

					while (PinVal == 0)
					{
						PinVal=DIO_voidGetBitValue(COLOUMN_PORT, Column);

					}
					_delay_ms(20);
					return local_u8_PressedKey;
				}
			}
			DIO_voidSetPinValue(ROW_PORT, Row, PIN_HIGH); /* Deactivate the Column */
		}

		return local_u8_PressedKey; /* Returning the value */
}
