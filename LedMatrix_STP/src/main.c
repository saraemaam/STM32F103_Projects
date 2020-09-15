/*
 * main.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Sarah Abuzaid
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"DIO_interface.h"
#include"STK_interface.h"
#include"STP_interface.h"

void main(void){

	u8 DataArray [8]={0, 0, 46, 42, 42, 58, 0, 0};

	/*Clock initialization*/
	RCC_voidInitSysClock();
	/*Enable GPIOA clock */
	RCC_voidEnableClock(RCC_APB2, 2);
	MGPIO_voidSetPinDir(GPIOA, PIN0, OUTPUT_SPEED_2_MHZ_PP);
	MGPIO_voidSetPinDir(GPIOA, PIN1, OUTPUT_SPEED_2_MHZ_PP);
	MGPIO_voidSetPinDir(GPIOA, PIN2, OUTPUT_SPEED_2_MHZ_PP);
	/*Systick initialization*/
	MSTK_voidInit();

	u8 Local_Colume = 1;

	while (1)
	{
		for (u8 i = 0; i <=7; i++)
		{
			u16 Local_u16DataToSend = (~Local_Colume << 8) | DataArray[i];
			HSTP_voidSendSynchronous(Local_u16DataToSend, 2);
			MSTK_voidSetBusyWait(1350);
			Local_Colume = Local_Colume << 1;
		}
		Local_Colume = 1;
	}
}
