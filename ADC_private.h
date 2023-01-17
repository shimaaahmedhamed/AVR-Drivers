/*
 * ADC_private.h
 *
 *  Created on: Nov 8, 2022
 *      Author: Aspire
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#define ADMUX  *( (volatile u8* ) 0x27)  //multiplexer selection register

#define MUX0   PIN0
#define MUX1   PIN1
#define MUX2   PIN2
#define MUX3   PIN3
#define MUX4   PIN4
#define ADLAR  PIN5
#define REFS0  PIN6
#define REFS1  PIN7

#define ADCSRA  *( (volatile u8* ) 0x26)  //control and status register

#define ADPS0   PIN0
#define ADPS1   PIN1
#define ADPS2   PIN2
#define ADIE    PIN3
#define ADIF    PIN4
#define ADATE   PIN5
#define ADSC    PIN6
#define ADEN    PIN7

#define ADCL    *( ( volatile u8* )0x24)  //when ADLAR = 0 do right read/write
#define ADCH    *( ( volatile u8* )0x25)
#define ADC_VALUE   *( ( volatile u16* )0x24)

#define SFIOR   *( ( volatile u8* )0x50)
#define ADTS0   PIN5
#define ADTS1   PIN6
#define ADTS2   PIN7

#endif /* ADC_PRIVATE_H_ */
