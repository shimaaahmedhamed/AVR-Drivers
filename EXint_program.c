/*
 * EXint_program.c
 *
 *  Created on: Nov 7, 2022
 *      Author: Aspire
 */
#include"EXint_interface.h"
#include"DIO_interface.h"

void (*ptr_ArrCallBack[ ])(void) = {NULL,NULL,NULL};

void Global_Interrupt(void)                                   //global interrupt
{
		SET_BIT(EXINT_REG_SREG,I_SREG);

}

void EXT_VOID_INT(u8 EXT_int,u8 INTERRUPT_SENSE_CONTROL)
{
	switch(EXT_int)
	{

	case EXTERNAL_INTERRUPT0:
	{
	SET_BIT(EXINT_REG_GICR,INT0_GICR);                     //peripheral interrupt

	DIO_voidSetPinDirection(PORTD_ID,PIN2,PIN_INPUT);       //PD2

	  if(INTERRUPT_SENSE_CONTROL==RISING)                  //SENSE CONTROL 0
		{
			SET_BIT(EXINT_REG_MCUCR,ISC00_MCUCR);
		    SET_BIT(EXINT_REG_MCUCR,ISC01_MCUCR);
		}
	  else if(INTERRUPT_SENSE_CONTROL==FALLING)
		{
			SET_BIT(EXINT_REG_MCUCR,ISC01_MCUCR);
			CLR_BIT(EXINT_REG_MCUCR,ISC00_MCUCR);
		}
	break;
	}

	case EXTERNAL_INTERRUPT1:

	{
		SET_BIT(EXINT_REG_GICR,INT1_GICR);                //peripheral interrupt

		DIO_voidSetPinDirection(PORTD_ID,PIN3,PIN_INPUT); //PD3

		if(INTERRUPT_SENSE_CONTROL==RISING)               //SENSE CONTROL 1
			{
				SET_BIT(EXINT_REG_MCUCR,ISC10_MCUCR);
			    SET_BIT(EXINT_REG_MCUCR,ISC11_MCUCR);
			}
		else if(INTERRUPT_SENSE_CONTROL==FALLING)
			{
				SET_BIT(EXINT_REG_MCUCR,ISC11_MCUCR);
				CLR_BIT(EXINT_REG_MCUCR,ISC10_MCUCR);
			}
	 break;
	}

	case EXTERNAL_INTERRUPT2:
	{
		SET_BIT(EXINT_REG_GICR,INT2_GICR);                   //peripheral interrupt

		DIO_voidSetPinDirection(PORTB_ID,PIN2,PIN_INPUT);   //PB2 bs not in this AVR

		if(INTERRUPT_SENSE_CONTROL==RISING)                 //SENSE CONTROL 2
				{
					SET_BIT(EXINT_REG_MCUCSR,ISC2_MCUCSR);

				}
		else if(INTERRUPT_SENSE_CONTROL==FALLING)
				{

					CLR_BIT(EXINT_REG_MCUCSR,ISC2_MCUCSR);
				}
	break;
	}

  }



}
void EXT_VOID_INTcallback(void (*ptr) (void), u8 EXT_int)
{


	 switch(EXT_int)
		   {
		   case EXTERNAL_INTERRUPT0:
			   ptr_ArrCallBack[ 0 ]= ptr;
			   break;
		   case EXTERNAL_INTERRUPT1:
			   ptr_ArrCallBack[ 1 ]= ptr;
		   	   break;
		   case EXTERNAL_INTERRUPT2:
			   ptr_ArrCallBack[ 2 ]= ptr;
		   	   break;
		   default: break;
		   }



}


void __vector_1 () __attribute__ ((signal));
void __vector_1 ()
{

	ptr_ArrCallBack[0]();



}

void __vector_2 () __attribute__ ((signal));
void __vector_2 ()
{


	ptr_ArrCallBack[1]();

}

void __vector_3 () __attribute__ ((signal));
void __vector_3 ()
{

	ptr_ArrCallBack[2]();

}

