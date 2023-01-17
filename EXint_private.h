/*
 * EXint_private.h
 *
 *  Created on: Nov 7, 2022
 *      Author: Aspire
 */

#ifndef EXINT_PRIVATE_H_
#define EXINT_PRIVATE_H_

#include"BIT_MATH.h"
#include"STD_TYPES.h"

#define EXINT_REG_MCUCR *((volatile u8* )0x55)    //sense control 0 , sense control 1
#define ISC00_MCUCR   PIN0
#define ISC01_MCUCR   PIN1
#define ISC10_MCUCR   PIN2
#define ISC11_MCUCR   PIN3


#define EXINT_REG_MCUCSR *((volatile u8* )0x54)   //sense control 2
#define ISC2_MCUCSR   PIN6


#define EXINT_REG_GICR *((volatile u8* )0x5B)     //peripheral interrupt
#define INT2_GICR   PIN5
#define INT0_GICR   PIN6
#define INT1_GICR   PIN7

#define EXINT_REG_GIFR *((volatile u8* )0x5A)     //flag interrupt
#define INTF2_GIFR   PIN5
#define INTF0_GIFR   PIN6
#define INTF1_GIFR   PIN7

#define EXINT_REG_SREG *((volatile u8* )0x5F)    //global interrupt
#define I_SREG   PIN7


#endif /* EXINT_PRIVATE_H_ */
