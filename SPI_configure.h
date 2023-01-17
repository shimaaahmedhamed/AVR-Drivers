/*
 * SPI_configure.h
 *
 *  Created on: Nov 17, 2022
 *      Author: Aspire
 */

#ifndef SPI_CONFIGURE_H_
#define SPI_CONFIGURE_H_

#include"SPI_interface.h"

#define MOSI_PORT  PORTB_ID
#define MOSI_PIN   PIN5


#define MISO_PORT  PORTB_ID
#define MISO_PIN   PIN6


#define SCK_PORT   PORTB_ID
#define SCK_PIN    PIN7


#define SPI_MODE  SPI_SLAVE

#endif /* SPI_CONFIGURE_H_ */
