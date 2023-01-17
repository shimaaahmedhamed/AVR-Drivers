/*
 * keypad_interface.h
 *
 *  Created on: Nov 6, 2022
 *      Author: Aspire
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "keypad_private.h"

#define KPD_NOT_PRESSED   255

void KPD_voidInit(void);

u8 KPD_voidGetPressedKey(void);


#endif /* KEYPAD_INTERFACE_H_ */
