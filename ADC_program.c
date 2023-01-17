/*
 * ADC_program.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Aspire
 */
#include "ADC_configure.h"
#include "ADC_interface.h"

void ADC_INIT()
{

/**********************select Vref***************************/
#if REF_VOLT==AREF
	CLR_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);
#elif REF_VOLT==AVCC
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

#endif

/**********************select TYPE DATA**********************/
#if TYPE_DATA==RIGHT_ADJUST
	CLR_BIT(ADMUX,ADLAR);

#elif TYPE_DATA==LEFT_ADJUST
	SET_BIT(ADMUX,ADLAR);
#endif

/*********************select prescaler -> 125KHZ***********************/
#if PRESCALLER==PRESCALLER_16
		CLR_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
#elif PRESCALLER==PRESCALLER_64
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
#elif PRESCALLER==PRESCALLER_128
		SET_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS2);
#endif

/*********************select CHANNEL***********************/
#if CHANNEL_SELECT==CHANNEL_0
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);
#elif CHANNEL_SELECT==CHANNEL_1
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);
#elif CHANNEL_SELECT==CHANNEL_2
		CLR_BIT(ADMUX,MUX0);
		SET_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);
#endif
/**********************ADC Enable******************************/
	SET_BIT(ADCSRA,ADEN);

/**********************AUTO TRIGGER Enable RELATED TO ADTS TO ENABLE AUTO TRIGGER******************************/
	SET_BIT(ADCSRA,ADATE);

}
/*******select channel - it's single*********/
//void ADC_CHANNEL_SELECT(u8 channel_select)
//{
//	switch(channel_select)
//	{
//	case CHANNEL_0:
//	{
//		CLR_BIT(ADMUX,MUX0);
//		CLR_BIT(ADMUX,MUX1);
//		CLR_BIT(ADMUX,MUX2);
//		CLR_BIT(ADMUX,MUX3);
//		CLR_BIT(ADMUX,MUX4);
//		break;
//	}
//	case CHANNEL_1:
//	{
//		SET_BIT(ADMUX,MUX0);
//		CLR_BIT(ADMUX,MUX1);
//		CLR_BIT(ADMUX,MUX2);
//		CLR_BIT(ADMUX,MUX3);
//		CLR_BIT(ADMUX,MUX4);
//		break;
//	}
//	case CHANNEL_2:
//	{
//		CLR_BIT(ADMUX,MUX0);
//		SET_BIT(ADMUX,MUX1);
//		CLR_BIT(ADMUX,MUX2);
//		CLR_BIT(ADMUX,MUX3);
//		CLR_BIT(ADMUX,MUX4);
//		break;
//	}
//}
//}

u16 ADC_READ(void)
{

/**********************start conversion******************************/
	SET_BIT(ADCSRA,ADSC);

	while(GET_BIT(ADCSRA,ADIF) == 0);   /* when finishing will change to 1 and for new conversion it's cleared automatically*/

    return ADC_VALUE;
}

