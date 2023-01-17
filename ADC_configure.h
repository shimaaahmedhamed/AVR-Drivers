/*
 * ADC_configure.h
 *
 *  Created on: Nov 14, 2022
 *      Author: Aspire
 */

#ifndef ADC_CONFIGURE_H_
#define ADC_CONFIGURE_H_

#include"ADC_interface.h"
#include"DIO_interface.h"

#define REF_VOLT    AVCC                 /* AVCC , AREF,  */
#define TYPE_DATA   RIGHT_ADJUST         /*RIGHT_ADJUST , LEFT ADJUST  */
#define PRESCALLER  PRESCALLER_128
#define CHANNEL_SELECT    CHANNEL_1
#define ADC_PORT    PORTA_ID
#define ADC_PIN     PIN1




#endif /* ADC_CONFIGURE_H_ */
