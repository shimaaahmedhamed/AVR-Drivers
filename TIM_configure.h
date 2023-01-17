/*
 * TIM_configure.h
 *
 *  Created on: Nov 12, 2022
 *      Author: Aspire
 */

#ifndef TIM_CONFIGURE_H_
#define TIM_CONFIGURE_H_

#include"TIM_interface.h"

/*NORMAL_MOOD
 * PWM_MOOD
 * CTC_MOOD
 * FAST_PWM_MOOD
 */
#define MOOD                 NORMAL_MOOD

//#define FAST_PWM             CLEAR_OC0

/*NO_PRESCALLER
 *PRESCALLER_8
 * PRESCALLER_64
 * PRESCALLER_256
 * PRESCALLER_1024
 */
#define PRESCALLER    PRESCALLER_8



#endif /* TIM_CONFIGURE_H_ */
