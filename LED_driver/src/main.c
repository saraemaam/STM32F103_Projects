/*
 * main.c
 *
 *  Created on: Aug 14, 2020
 *      Author: Admin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include"DIO_interface.h"
#include"RCC_interface.h"


int main(void){

	RCC_voidInitSysClock();

	RCC_voidEnableClock (RCC_APB2 , 2 );
	RCC_voidEnableClock (RCC_APB2 , 3 );
	RCC_voidEnableClock (RCC_APB2 , 4 );

	Led_vidInit(LED_1);
	Led_vidInit(LED_7);

	while(1){
		Led_vidTurnOn(LED_1);
		Led_vidTurnOn(LED_7);
	}
return 0;
}
