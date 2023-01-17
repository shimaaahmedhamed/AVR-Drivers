/*
 * SPI_private.h
 *
 *  Created on: Nov 17, 2022
 *      Author: Aspire
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include"BIT_MATH.h"
#include"STD_TYPES.h"


#define SPDR     *((volatile u8*)0x2F)
#define LSB     PIN0
#define MSB     PIN6

#define SPSR     *((volatile u8*)0x2E)
#define SPI2X   PIN0
#define WCOL    PIN6
#define SPIF    PIN7


#define SPCR      *((volatile u8*)0x2D)
#define SPR0     PIN0
#define SPR1     PIN1
#define CPHA     PIN2
#define CPOL     PIN3
#define MSTR     PIN4
#define DORD     PIN5
#define SPE      PIN6
#define SPIE     PIN7

#endif /* SPI_PRIVATE_H_ */
