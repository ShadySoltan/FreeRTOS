/*
* OCT23.c
*
* Created: 3/17/2023 3:45:07 PM
* Author : user
*/

#include <avr/io.h>
#include <stdlib.h>
#include "BitMath.h"
#include "Clock.h"
#include "DIO.h"
#include "LCD.h"
#include "Keypad.h"
#include "SSD.h"
#include "GINT.h"
#include "Ext_Int.h"
#include "ADC.h"
#include "LM35.h"
#include <avr/interrupt.h>
#include "PWM.h"
#include "ServoMotor.h"
#include "Ultrasonic.h"
#include "Bluetooth.h"
#include "SPI.h"
#include "TWI.h"
#include "EEPROM.h"
#include "FreeRTOS.h"
#include "task.h"

// void GreenLed (void * ptr);
// void BlueLed (void * ptr);
// void RedLed (void * ptr);

void xPrint(void * string);

int main(void)
{
	//DIO_Init();
	UART_Config options = {BaudRate_9600,DoupleSpeed_Disable,CharacterSize_8Bits,Stop_1Bit,Parity_Disable,TX_Enable,RX_Enable};
	UART_Init(&options);
	
	//xTaskCreate(RedLed,"Red",100,NULL,1,NULL);
	//xTaskCreate(BlueLed,"Blue",100,NULL,1,NULL);
	//xTaskCreate(GreenLed,"Green",100,NULL,1,NULL);
	
	xTaskCreate(xPrint,"Task1",100,(void *)"Task1\n\r",1,NULL);
	xTaskCreate(xPrint,"Task2",100,(void *)"Task2\n\r",2,NULL);
	
	vTaskStartScheduler();
	
	while (1)
	{

		
	}
}

// void RedLed (void * ptr){
// 	while(1){
// 		DIO_ToggleChannel(DIO_ChannelC7);
// 		vTaskDelay(200 / portTICK_PERIOD_MS);
// 	}
// }
//
// void BlueLed (void * ptr){
// 	while(1){
// 		DIO_ToggleChannel(DIO_ChannelD3);
// 		vTaskDelay(350 / portTICK_PERIOD_MS);
// 	}
// }
// void GreenLed (void * ptr){
// 	while(1){
// 		DIO_ToggleChannel(DIO_ChannelC2);
// 		vTaskDelay(500 / portTICK_PERIOD_MS);
// 	}
// }

void xPrint(void * string){
	while (1)
	{
		UART_TransmaitString((s8*)string);
		vTaskDelay(10 / portTICK_PERIOD_MS);
	}
}
