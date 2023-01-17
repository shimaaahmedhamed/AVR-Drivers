/*
 * ADC_interface.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Aspire
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_private.h"

#define CHANNEL_0  0
#define CHANNEL_1  1
#define CHANNEL_2  2
#define CHANNEL_3  3
#define CHANNEL_4  4
#define CHANNEL_5  5
#define CHANNEL_6  6
#define CHANNEL_7  7

#define AVCC       1
#define AREF       2


#define RIGHT_ADJUST       1
#define LEFT_ADJUST        2

#define PRESCALLER_16       1
#define PRESCALLER_64       2
#define PRESCALLER_128      3

void ADC_INIT(void);
u16 ADC_READ(void);
//void ADC_CHANNEL_SELECT(u8 channel_select);


#endif /* ADC_INTERFACE_H_ */
