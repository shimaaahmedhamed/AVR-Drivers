/*
 * SPI_program.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Aspire
 */
#include "SPI_configure.h"
#include"DIO_Interface.h"
#include"DIO_Private.h"


void SPI_INIT(void)
{
#if SPI_MODE == SPI_MASTER
	SET_BIT(SPCR,MSTR);
	SET_BIT(DDRB_REG,PIN4);
	SET_BIT(DDRB_REG,PIN5);
	CLR_BIT(DDRB_REG,PIN6);
	SET_BIT(DDRB_REG,PIN7);
	// FACTOR 128
	SET_BIT(SPCR,SPR0);
	SET_BIT(SPCR,SPR1);
	CLR_BIT(SPSR,SPI2X);


#elif SPI_MODE == SPI_SLAVE
	CLR_BIT(SPCR,MSTR);
	CLR_BIT(DDRB_REG,PIN4);
	CLR_BIT(DDRB_REG,PIN5);
	SET_BIT(DDRB_REG,PIN6);
	CLR_BIT(DDRB_REG,PIN7);

#endif
	SET_BIT(SPCR,SPE);
}

u8 SPI_TRANSMIT_RECIEVE (u8 datasend)
{
	SPDR=datasend;
	while (GET_BIT(SPSR,SPIF)==0);
	return SPDR;
}

