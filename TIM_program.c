/*
 * TIM_program.c
 *
 *  Created on: Nov 12, 2022
 *      Author: Aspire
 */

#include"TIM_interface.h"
#include"TIM_configure.h"



void TIMER_INITIAL()
{

#if MOOD == NORMAL_MOOD
		SET_BIT(TIMSK, TIMSK_TOIE0);
		CLR_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);
/*TCCRO->WGM00=0;
 * TCCRO->WGM01=1;
BY STRUCT;*/

#elif MOOD == PWM_MOOD

		SET_BIT(TCCR0_REG,WGM00);
		CLR_BIT(TCCR0_REG,WGM01);


#elif MOOD == CTC_MOOD

		CLR_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);



#elif MOOD == FAST_PWM_MOOD

		SET_BIT(TCCR0_REG,WGM00);
		SET_BIT(TCCR0_REG,WGM01);



#endif
}

void TIMER_STOP(void)
{

	CLR_BIT(TCCR0_REG,CS00);
    CLR_BIT(TCCR0_REG,CS01);
    CLR_BIT(TCCR0_REG,CS02);

}

void TIMER_START()
{
#if PRESCALLER == PRESCALLER_8
	CLR_BIT(TCCR0_REG,CS00);
	SET_BIT(TCCR0_REG,CS01);
    CLR_BIT(TCCR0_REG,CS02);
#elif PRESCALLER == PRESCALLER_64
    SET_BIT(TCCR0_REG,CS00);
    SET_BIT(TCCR0_REG,CS01);
    CLR_BIT(TCCR0_REG,CS02);
#elif PRESCALLER == PRESCALLER_256
    CLR_BIT(TCCR0_REG,CS00);
    CLR_BIT(TCCR0_REG,CS01);
    SET_BIT(TCCR0_REG,CS02);

#endif
}
/*void TIM_PWM_MOOD(void)
{

#if FAST_PWM == NORMAL_PORT
	CLR_BIT(TCCR0_REG,COM00);
	CLR_BIT(TCCR0_REG,COM01);

#elif FAST_PWM == RESERVED
	SET_BIT(TCCR0_REG,COM00);
	CLR_BIT(TCCR0_REG,COM01);

#elif FAST_PWM == CLEAR_OC0
	CLR_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);

#elif FAST_PWM == SET_OC0
	SET_BIT(TCCR0_REG,COM00);
	SET_BIT(TCCR0_REG,COM01);
#endif
}*/
void (*TIM_CallBack)(void);
void TIM_voidSetCallBack(  void (*ptr_ext)(void) )
{

	if(ptr_ext!= NULL)
	{
		TIM_CallBack=ptr_ext;
	}

}
void  __vector_11() __attribute__((signal)) ;
void __vector_11 ()
{
	TIM_CallBack();


}

