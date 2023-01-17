/*
 * EXint_interface.h
 *
 *  Created on: Nov 7, 2022
 *      Author: Aspire
 */

#ifndef EXINT_INTERFACE_H_
#define EXINT_INTERFACE_H_

#include"EXint_private.h"

#define EXTERNAL_INTERRUPT0   0
#define EXTERNAL_INTERRUPT1   1
#define EXTERNAL_INTERRUPT2   2

#define FALLING   0
#define RISING    1

void EXT_VOID_INT(u8 EXT_int,u8 INTERRUPT_SENSE_CONTROL);
void EXT_VOID_INTcallback(void (*ptr) (void), u8 EXT_int);
void Global_Interrupt(void);

#endif /* EXINT_INTERFACE_H_ */
