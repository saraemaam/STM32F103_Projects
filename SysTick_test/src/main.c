/*
 * main.c
 *
 *  Created on: Aug 28, 2020
 *      Author: Sarah Abuzaid
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"DIO_interface.h"
#include"LED_interface.h"
#include"RCC_interface.h"

//#include"STK_interface.h"


void main(void){
	/*initialize clock system */
	RCC_voidInitSysClock();
	/*Enable clock for GPIOA*/
	RCC_voidEnableClock(RCC_APB2 , 2 );
	/*initialize Led */
	Led_voidInit(LED_1);

	while(1){

		Led_voidTurnOn(LED_1);


	}

}



