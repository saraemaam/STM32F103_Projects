/*
 * main.c
 *
 *  Created on: Aug 26, 2020
 *      Author: Sarah Abuzaid
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include"SysTick_interface.h"

void main(void){
	/*initialize clock system */
	RCC_voidInitSysClock();
	/*Enable GPIOA peripheral on APB2 bus */
	RCC_voidEnableClock (RCC_APB2 , 2) ;
	/*Initialize Systick */
	MSTK_voidInit();
	/*initialize Leds */
	Led_voidInit (LED_1);
	Led_voidInit (LED_2);
	Led_voidInit (LED_3);
	Led_voidInit (LED_4);
	Led_voidInit (LED_5);
	Led_voidInit (LED_6);
	Led_voidInit (LED_7);
	Led_voidInit (LED_8);

	while(1){
		/*First scenario */
	/*	for(u8 i=0 ; i <=3 ; i++ ){
			Led_voidLeft_shifting();
			Led_voidRight_shifting();
		}

*/

		/*Second scenario*/
		/*
		for(u8 k=0 ; k<=3 ;  k++){
			Led_voidInOut();

			Led_voidOutIn();
		}
		*/

		/* third scenario */
/*
		for( u8 j=0 ; j<=7 ; j++ ){
			Led_voidFlashing();
		}

*/
		Led_voidTurnOn(LED_1);
	}
}

