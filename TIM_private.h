/*
 * TIM_private.h
 *
 *  Created on: Nov 12, 2022
 *      Author: Aspire
 */

#ifndef TIM_PRIVATE_H_
#define TIM_PRIVATE_H_

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#define TCCR0_REG        *((volatile u8 *)0x53)
#define CS00   PIN0
#define CS01   PIN1
#define CS02   PIN2
#define WGM01  PIN3
#define COM00  PIN4
#define COM01  PIN5
#define WGM00  PIN6
#define FOC0   PIN7

/*typedef TCCR0
{
CS:3;
WGM01:1;
COM:2;
WGM00:1;
FOC:1;
}
*/

#define TCNT0            *((volatile u8 *)0x52)

#define OCR0             *((volatile u8 *)0x5C)

#define TIMSK            *((volatile u8 *)0x59)
#define TIMSK_TOIE0           PIN0
#define TIMSK_OCIE0           PIN1

#define TIFR             *((volatile u8 *)0x58)
#define TIFR_TOV0             PIN0
#define TIFR_OCF0             PIN1






#endif /* TIM_PRIVATE_H_ */
