/*
 * TIM_interface.h
 *
 *  Created on: Nov 12, 2022
 *      Author: Aspire
 */

#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_
#include "TIM_private.h"

#define NORMAL_MOOD  0
#define PWM_MOOD     1
#define CTC_MOOD     2
#define FAST_PWM_MOOD 3


#define NO_PRESCALLER  0
#define PRESCALLER_8   1
#define PRESCALLER_64  2
#define PRESCALLER_256 3
#define PRESCALLER_1024 4

#define NORMAL_PORT  0
#define RESERVED     1
#define CLEAR_OC0    2
#define SET_OC0      3

void TIMER_INITIAL(void);
void TIMER_STOP(void);
void TIMER_START(void);
void TIM_PWM_MOOD(void);
void TIM_voidSetCallBack(  void (*ptr_ext)(void) );

#endif /* TIM_INTERFACE_H_ */
