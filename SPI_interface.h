/*
 * SPI_interface.h
 *
 *  Created on: Nov 17, 2022
 *      Author: Aspire
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include"SPI_private.h"


#define SPI_MASTER  0
#define SPI_SLAVE  1



void SPI_INIT(void);

u8 SPI_TRANSMIT_RECIEVE (u8 datasend);

#endif /* SPI_INTERFACE_H_ */
