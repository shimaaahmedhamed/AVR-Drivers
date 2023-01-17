/*
 * DIO_Program.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Aspire
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_private.h"
#include "DIO_interface.h"


void DIO_voidSetPinDirection(u8 PORT_ID, u8 PIN_ID, u8 DDR_ID)
{
		if(DDR_ID==PIN_OUTPUT)//Output
		{
			switch(PORT_ID)
			{
			case PORTA_ID:    SET_BIT(DDRA_REG,PIN_ID); break;
			case PORTB_ID:    SET_BIT(DDRB_REG,PIN_ID); break;
			case PORTC_ID:    SET_BIT(DDRC_REG,PIN_ID); break;
			case PORTD_ID:    SET_BIT(DDRD_REG,PIN_ID); break;

			default:   break;

			}
		}
		else if(DDR_ID==PIN_INPUT)//Input
		{
			switch(PORT_ID)
			{
			case PORTA_ID:   CLR_BIT(DDRA_REG,PIN_ID); break;
			case PORTB_ID:   CLR_BIT(DDRB_REG,PIN_ID); break;
			case PORTC_ID:   CLR_BIT(DDRC_REG,PIN_ID); break;
			case PORTD_ID:   CLR_BIT(DDRD_REG,PIN_ID); break;
			default:   break;
			}
		}
	}


void DIO_voidSetPinValue(u8 PORT_ID, u8 PIN_ID, u8 value_ID)
{
		if(value_ID==PIN_HIGH)//High
		{
			switch(PORT_ID)
			{
			case PORTA_ID :    SET_BIT(PORTA_REG,PIN_ID); break;
			case PORTB_ID :    SET_BIT(PORTB_REG,PIN_ID); break;
			case PORTC_ID :    SET_BIT(PORTC_REG,PIN_ID); break;
			case PORTD_ID :    SET_BIT(PORTD_REG,PIN_ID); break;

			}
		}
		else if(value_ID==PIN_LOW)//Low
		{
			switch(PORT_ID)
			{
			case PORTA_ID : CLR_BIT(PORTA_REG,PIN_ID); break ;
			case PORTB_ID : CLR_BIT(PORTB_REG,PIN_ID); break ;
			case PORTC_ID : CLR_BIT(PORTC_REG,PIN_ID) ;break ;
			case PORTD_ID : CLR_BIT(PORTD_REG,PIN_ID) ;break ;

			}
		}
}
void DIO_voidToggelPin(u8 copy_u8PortID,u8 copy_u8PinID)
{

	switch (copy_u8PortID)
	{
	case PORTA_ID :  TOG_BIT(PORTA_REG,copy_u8PinID) ; break ;
	case PORTB_ID :  TOG_BIT(PORTB_REG,copy_u8PinID) ; break ;
	case PORTC_ID :  TOG_BIT(PORTC_REG,copy_u8PinID) ; break ;
	case PORTD_ID :  TOG_BIT(PORTD_REG,copy_u8PinID) ; break ;


	}
}
u8 DIO_voidGetBitValue(u8 copy_u8PortID , u8 copy_PinID )
{

		u8 Local_PinVal ;

		switch(copy_u8PortID)
		{

		case PORTA_ID : Local_PinVal=GET_BIT(PINA_REG,copy_PinID)   ; break ;
		case PORTB_ID : Local_PinVal=GET_BIT(PINB_REG,copy_PinID)   ; break ;

		case PORTC_ID : Local_PinVal=GET_BIT(PINC_REG,copy_PinID)   ; break ;

		case PORTD_ID : Local_PinVal=GET_BIT(PIND_REG,copy_PinID)   ; break ;

		}

		return Local_PinVal ;

}
