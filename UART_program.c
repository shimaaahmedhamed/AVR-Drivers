/*
 * UART_program.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Aspire
 */

#include"UART_interface.h"
#include"UART_configure.h"
#include "STD_TYPES.h"

#define F_CPU 16000000UL

#define BAUD_PRESCALE (((F_CPU / (baud * 16UL))) - 1)

void UART_INIT(u16 baud)
{
	UBRRL = (u8) BAUD_PRESCALE;                     //set baud rate
	UBRRH = (u8) (BAUD_PRESCALE>>8);
	UCSRB = (1<<RXEN) | (1<<TXEN);         //Enable transmit and recieve
	UCSRC = (1<<URSEL) | (1<<USBS)|(3<<UCSZ0);  //set frame format

/*#if MODE_SELECT==SYNCHRONOUS
    	SET_BIT(UCSRC,UMSEL);
#elif MODE_SELECT== ASYNCHRONOUS
    	CLR_BIT(UCSRC,UMSEL);
#endif

#if PARITY_MODE==EVEN
    	CLR_BIT(UCSRC,UPM0);
    	SET_BIT(UCSRC,UPM1);
#elif PARITY_MODE== ODD
    	SET_BIT(UCSRC,UPM0);
    	SET_BIT(UCSRC,UPM1);
#elif PARITY_MODE== DISABLED
    	CLR_BIT(UCSRC,UPM0);
    	CLR_BIT(UCSRC,UPM1);

#endif

#if STOP_BIT_SELECT==ONE_BIT
    	CLR_BIT(UCSRC,USBS);
#elif STOP_BIT_SELECT==TWO_BIT
    	SET_BIT(UCSRC,USBS);

#endif


#if BIT_SETTING==FIVE_BIT
    	CLR_BIT(UCSRC,UCSZ0);
        CLR_BIT(UCSRC,UCSZ1);
    	CLR_BIT(UCSRC,UCSZ2);
#elif BIT_SETTING==SIX_BIT
    	SET_BIT(UCSRC,UCSZ0);
    	CLR_BIT(UCSRC,UCSZ1);
    	CLR_BIT(UCSRC,UCSZ2);
#elif BIT_SETTING==SEVEN_BIT
    	CLR_BIT(UCSRC,UCSZ0);
    	SET_BIT(UCSRC,UCSZ1);
    	CLR_BIT(UCSRC,UCSZ2);
#elif BIT_SETTING==EIGHT_BIT
    	SET_BIT(UCSRC,UCSZ0);
    	SET_BIT(UCSRC,UCSZ1);
    	CLR_BIT(UCSRC,UCSZ2);
#elif BIT_SETTING==NINE_BIT
    	SET_BIT(UCSRC,UCSZ0);
    	SET_BIT(UCSRC,UCSZ1);
    	SET_BIT(UCSRC,UCSZ2);

#endif
*/
}

void UART_DATA_TRANSMITT(u8 data)  //set transmitt enable
{

        while (! (UCSRA & (1<<UDRE))); //wait for empty transmit
        UDR = data;


}

u8 UART_DATA_RECIEVE()  //set reciever enable
{
	while (! (UCSRA & (1<<RXC))); //wait till data recieved
	return UDR;


}
void UART_SEND_STRING(u8 *string)
{
	u8 i=0;
	while(string[i]!=0)
	{
		UART_DATA_TRANSMITT(string[i]);

		i++;
	}



}

