/*
 * main.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Admin
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"DIO_interface.h"
#include"STK_interface.h"
#include"STP_interface.h"

void main(void){
	/*Clock initialization*/
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2, 2);
	MGPIO_voidSetPinDir(GPIOA, PIN0, OUTPUT_SPEED_2_MHZ_PP);
	MGPIO_voidSetPinDir(GPIOA, PIN1, OUTPUT_SPEED_2_MHZ_PP);
	MGPIO_voidSetPinDir(GPIOA, PIN2, OUTPUT_SPEED_2_MHZ_PP);

	MSTK_voidInit();





	while(1){
		for(u8 i = 0 ; i<8 ; i++){

			HSTP_voidSendSynchronus(1<<i);
			MSTK_voidSetBusyWait(300000);

		}
	}

}



