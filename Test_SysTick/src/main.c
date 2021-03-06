/*
 * main.c
 *
 *  Created on: Aug 28, 2020
 *      Author: Sarah Abuzaid
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"LED_interface.h"
#include"RCC_interface.h"
#include"DIO_interface.h"
#include"STK_interface.h"

void AppFun(void);
void main(void){
	/*initialize clock system */
	RCC_voidInitSysClock();
	/*Enable clock for GPIOA*/
	RCC_voidEnableClock(RCC_APB2 , 2 );
	MSTK_voidInit();
	/*initialize Led */
	Led_vidInit(LED_1);


	while(1){

		Led_vidTurnOn(LED_1);
		MSTK_voidSetIntervalSingle (2000,AppFun);

	}

}

void AppFun(void){
	Led_vidTurnOff(LED_1);


}
