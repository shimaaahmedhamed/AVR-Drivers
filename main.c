/*
 * main.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Aspire
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"
//#include "avr/io.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_configure.h"
//#include "keypad_configure.h"
//#include "keypad_interface.h"
//#include"EXint_interface.h"
//#include"TIM_configure.h"
//#include"TIM_interface.h"
#include"UART_interface.h"
#include"UART_configure.h"
#include"ADC_interface.h"
#include"ADC_configure.h"
//#include"I2C_interface.h"
//#include"SPI_interface.h"
//#include"SPI_configure.h"
#include"wifimodule_configure.h"
#include"Free_RTOS/FreeRTOS.h"
#include"Free_RTOS/FreeRTOSConfig.h"
#include"Free_RTOS/task.h"
#include"Free_RTOS/semphr.h"
u16 x = 0;


void Buzzerfun()
 {

 	while(1)
 	{

 		DIO_voidSetPinValue(PORTA_ID,PIN4,PIN_HIGH);
 		DIO_voidSetPinValue(PORTC_ID, PIN6, PIN_HIGH);
 			_delay_ms(100);
 		DIO_voidSetPinValue(PORTC_ID, PIN6, PIN_LOW);

 	    vTaskDelay(5000);
 	}
 }
 void WLSfun()
 {

 	while(1)
 	{

 		DIO_voidSetPinValue(PORTA_ID,PIN5,PIN_HIGH);
			x = ADC_READ();
 			LCD_voidWriteInt(x);
 			_delay_ms(1000);
 			LCD_voidClear();

 	    vTaskDelay(3000);
 	}
 }


int main()
{
	ADC_INIT();
	LCD_INIT();
	DIO_voidSetPinDirection(ADC_PORT, ADC_PIN, PIN_INPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN6, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA_ID,PIN5,PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTA_ID,PIN4,PIN_OUTPUT);
	xTaskCreate(WLSfun,"WLSfun",100,NULL,0,NULL);
	xTaskCreate(Buzzerfun,"Buzzerfun",100,NULL,1,NULL);
	LCD_WRITE_STRING(" WLS Reading is ");
	vTaskStartScheduler();
	while(1)
	{

	}

return 0;
}

/*
//uart code
int main()
{
   u8 R;
	UART_INIT(9600);
 	UART_SEND_STRING("\n \t EChO TEST");

    while(1)
      {
    	R=UART_DATA_RECIEVE();
    	UART_DATA_TRANSMITT(R);


        }

	return 0;
}
*/


/*
//SPI CODE
int main()
{
	LCD_INIT();
	SPI_INIT();
	DIO_voidSetPinDirection(PORTC_ID, PIN0, PIN_OUTPUT);
	u8 data;

		//LCD_voidGoToXY(0,1);

while(1)
{

	if( SPI_TRANSMIT_RECIEVE('2') == '1')
	{
		LCD_WRITE_DATA('A');
			}
	else
	{
				DIO_voidSetPinValue(PORTC_ID, PIN0, PIN_HIGH);
			}
	_delay_ms(1000);

}



return 0;
}
*/





// I2C CODE
/*
int main(){

	u8 data;

	LCD_INIT();

	I2C_ERROR local_enum = I2C_NOK;

	I2C_VOIDSLAVE_INIT(0x05);

	_delay_ms(1000);

	local_enum = RECIEVE_DATASLAVE(&data);
	LCD_voidGoToXY(1,2);
	LCD_voidWriteInt(local_enum);
	LCD_WRITE_DATA(data);

*/
/*
		LCD_voidGoToXY(0, 0);
		LCD_WRITE_STRING("IIC STATUS");

		DIO_voidSetPinDirection(PORTC_ID, PIN0, PIN_OUTPUT);
		DIO_voidSetPinDirection(PORTC_ID, PIN1, PIN_OUTPUT);

		I2C_VOIDMASTER_INIT();

		local_enum=send_start_condition();
		LCD_voidGoToXY(1, 0);
		LCD_voidWriteInt(local_enum);

		local_enum=send_slave_addresswrite(0x05);
		LCD_voidGoToXY(1, 3);
		LCD_voidWriteInt(local_enum);

		local_enum=send_DATAMASTER(7);
		LCD_voidGoToXY(1, 6);
		LCD_voidWriteInt(local_enum);

		local_enum = send_stop_condition();
		LCD_voidGoToXY(1, 6);
		LCD_voidWriteInt(local_enum);

		_delay_ms(1000);

	while(1)
	{

	}

return 0;
}
*/

////ADC Code
//int main()
//{
//	ADC_INIT();
//	LCD_INIT();
//    u16 x = 0;
//	DIO_voidSetPinDirection(ADC_PORT, ADC_PIN, PIN_INPUT);
//
//
//	while(1)
//	{
//		x = ADC_READ();
//		LCD_WRITE_STRING(" WLS Reading is ");
//		LCD_voidWriteInt(x);
//		_delay_ms(1000);
//		LCD_voidClear();
//	}
//
//return 0;
//}


/*//SEVEN SEGMENT IN INTERRUPT
 *
#define ZERO   0X3F
#define ONE    0X06
#define TWO    0X5B
#define THREE  0X4F
#define FOUR   0X66
#define FIVE   0X6D
#define SIX    0X7D
#define SEVEN  0X07
#define EIGHT  0X7F
#define NINE   0X67

void SEVEN_SEGMENT()
{


	    SET_PORT(PORTA,ONE<<1);
		DIO_voidSetPinValue(PORTC_ID, PIN6, PIN_HIGH);
		DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_LOW);

		_delay_ms(70);

		SET_PORT(PORTA,TWO<<1);
		DIO_voidSetPinValue(PORTC_ID, PIN6, PIN_LOW);
		DIO_voidSetPinValue(PORTC_ID, PIN7, PIN_HIGH);

}

int main()
{
	    SET_PORT(DDRA_REG,0XFF);
		DIO_voidSetPinDirection(PORTC_ID, PIN6, PIN_OUTPUT);
		DIO_voidSetPinDirection(PORTC_ID, PIN7, PIN_OUTPUT);

		EXT_VOID_INT(EXTERNAL_INTERRUPT0,FALLING);
		EXT_VOID_INTcallback(SEVEN_SEGMENT, EXTERNAL_INTERRUPT0);
		Global_Interrupt();
    while(1);

return 0;
}

*/




/*GRE,RE,BL LEDS AND BUZZ
 * int main()
{

	DIO_voidSetPinDirection(PORTC_ID, PIN1, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN0, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN2, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN5, PIN_OUTPUT);

	while(1)
	{
		DIO_voidSetPinValue(PORTC_ID, PIN1, PIN_HIGH);
		_delay_ms(30);
		DIO_voidSetPinValue(PORTC_ID, PIN1, PIN_LOW);

		DIO_voidSetPinValue(PORTC_ID, PIN0, PIN_HIGH);
		_delay_ms(50);
		DIO_voidSetPinValue(PORTC_ID, PIN0, PIN_LOW);

		DIO_voidSetPinValue(PORTC_ID, PIN2, PIN_HIGH);
		_delay_ms(70);
		DIO_voidSetPinValue(PORTC_ID, PIN2, PIN_LOW);

		DIO_voidSetPinValue(PORTC_ID, PIN5, PIN_HIGH);
		_delay_ms(100);
		DIO_voidSetPinValue(PORTC_ID, PIN5, PIN_LOW);

	}

return 0;
}
*/





/*//interrupt_buz
void LED_TOGG()
{
	DIO_voidToggelPin(PORTC_ID,PIN5);
}


int main()
{
	DIO_voidSetPinDirection(PORTC_ID,PIN5,PIN_OUTPUT);
	Global_Interrupt();
	EXT_VOID_INT(EXTERNAL_INTERRUPT0,FALLING);
	EXT_VOID_INTcallback(LED_TOGG, EXTERNAL_INTERRUPT0);
    while(1);


}
*/


/*
//KEYPAD_CODE
int main()
{
	KPD_voidInit();
	LCD_INIT();
	DIO_voidSetPinDirection(PORTC_ID, PIN1, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN2, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN3, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN0, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN4, PIN_OUTPUT);
	DIO_voidSetPinDirection(PORTC_ID, PIN5, PIN_OUTPUT);

	while(1)
	{
	switch(KPD_voidGetPressedKey())
	{
	case 0x00:      DIO_voidSetPinValue(PORTC_ID, PIN1, PIN_HIGH);   break;
	case 0x01:      DIO_voidSetPinValue(PORTC_ID, PIN0, PIN_HIGH);   break;
	case 0x02:      DIO_voidSetPinValue(PORTC_ID, PIN2, PIN_HIGH);   break;
	case 0x03:      DIO_voidSetPinValue(PORTC_ID, PIN3, PIN_HIGH);   break;
	case 0x04:      DIO_voidSetPinValue(PORTC_ID, PIN4, PIN_HIGH);   break;
	case 0x05:      DIO_voidToggelPin(PORTC_ID,PIN5);                break;
	case 0x08:      LCD_WRITE_STRING("THIS IS EGYPT");               break;
	default:        break;

	}
	}


		return 0;
	}

*/



/*servo_motor

#define TCCR1A_REGA   *((volatile u8 *)0x4F)
#define WGM10    PIN0
#define WGM11    PIN1
#define FOC1B    PIN2
#define FOC1A    PIN3
#define COM1B0   PIN4
#define COM1B1   PIN5
#define COM1A0   PIN6
#define COM1A1   PIN7


#define TCCR1B_REGB   *((volatile u8 *)0x4E)
#define CS10    PIN0
#define CS11    PIN1
#define CS12    PIN2
#define WGM12   PIN3
#define WGM13   PIN4
#define ICES1   PIN6
#define ICNC1   PIN7



#define ICR1   *((volatile u16 *)0x46)

#define OCR1A   *((volatile u16 *)0x4A)

int main (){


	DIO_voidSetPinDirection(PORTD_ID, PIN5, PIN_OUTPUT);

	//FAST_PWM_CLEAR_MODE
	CLR_BIT(TCCR1A_REGA,COM1A0);
	SET_BIT(TCCR1A_REGA,COM1A1);
   //FAST_PWM_ICR1
	CLR_BIT(TCCR1A_REGA,WGM10);
	SET_BIT(TCCR1A_REGA,WGM11);
	SET_BIT(TCCR1B_REGB,WGM12);
	SET_BIT(TCCR1B_REGB,WGM13);

    //TOP_VALUE
	ICR1 = 40000;
	//MATCH_VALUE
	OCR1A = 800;

	//IDENTIFY_PRESCALLING_8
		CLR_BIT(TCCR1B_REGB,CS10);
		SET_BIT(TCCR1B_REGB,CS11);
		CLR_BIT(TCCR1B_REGB,CS12);

	while(1)
	{

	}


return 0;

}*/

/*
//LCD code
 int main (){
	LCD_INIT();
	LCD_WRITE_DATA(' ');
	LCD_WRITE_DATA('s');
	LCD_WRITE_DATA( 1 );
	LCD_WRITE_STRING("SHIMA");

	while(1)
	{

	}
	return 0;
}

*/



/*
//timer code
void  LED_TOGGLE(void);

int main()
{
	DIO_voidSetPinDirection(PORTC_ID,PIN1, PIN_OUTPUT);
	Global_Interrupt();
	TIM_voidSetCallBack(LED_TOGGLE);
	TCNT0=112;
	TIMER_INITIAL();
	TIMER_START();
	while(1);
return 0;
}

void  LED_TOGGLE(void)
{
	static u16 count=0;
	count++;
	if(count==977)
	{
		DIO_voidToggelPin(PORTC_ID,PIN1);
		count=0;
		TCNT0=112;
	}

}
*/





//int main()
//{
//
//
//		uint8_t Connect_Status;
//		#ifdef SEND_DEMO
//		uint8_t Sample = 0;
//		#endif
//
//		UART_INIT(115200);			/* Initiate USART with 115200 baud rate */
////		sei();					/* Start global interrupt */
//
//		while(!ESP8266_Begin());
//		ESP8266_WIFIMode(BOTH_STATION_AND_ACCESPOINT);/* 3 = Both (AP and STA) */
//		ESP8266_ConnectionMode(SINGLE);		/* 0 = Single; 1 = Multi */
//		ESP8266_ApplicationMode(NORMAL);	/* 0 = Normal Mode; 1 = Transperant Mode */
//		if(ESP8266_connected() == ESP8266_NOT_CONNECTED_TO_AP)
//		ESP8266_JoinAccessPoint(SSID, PASSWORD);
//		ESP8266_Start(0, DOMAIN, PORT);
//		while(1)
//		{
//			Connect_Status = ESP8266_connected();
//			if(Connect_Status == ESP8266_NOT_CONNECTED_TO_AP)
//			ESP8266_JoinAccessPoint(SSID, PASSWORD);
//			if(Connect_Status == ESP8266_TRANSMISSION_DISCONNECTED)
//			ESP8266_Start(0, DOMAIN, PORT);
//
//			#ifdef SEND_DEMO
//			memset(_buffer, 0, 150);
//			sprintf(_buffer, "GET /update?api_key=%s&field1=%d", API_WRITE_KEY, Sample++);
//			ESP8266_Send(_buffer);
//			_delay_ms(15000);	/* Thingspeak server delay */
//			#endif
//
//			#ifdef RECEIVE_DEMO
//			memset(_buffer, 0, 150);
//			sprintf(_buffer, "GET /channels/%s/feeds/last.txt", CHANNEL_ID);
//			ESP8266_Send(_buffer);
//			Read_Data(_buffer);
//			_delay_ms(600);
//			#endif
//		}
//return 0;
//}



