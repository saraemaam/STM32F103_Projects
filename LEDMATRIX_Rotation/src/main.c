/*
 * main.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Admin
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"RCC_interface.h"
#include"STK_interface.h"
#include"LEDMRX_interface.h"

void main(void){
	u8 Arr[8]={0,94,82,82,82,114,0,0};
	/*initialize clock system */
	RCC_voidInitSysClock();
	/*Enable GPIOA clock */
	RCC_voidEnableClock(RCC_APB2,2);
	/*Enable GPIOB*/
	RCC_voidEnableClock(RCC_APB2,3);
	/*Systick initialization*/
	MSTK_voidInit();
	/*initialize led matrix */
	HLEDMRX_voidInit();
	/* send data to led matrix */
	HLEDMRX_voidDisplay(Arr);

	while(1){

HLEDMRX_voidDisplay(Arr);
	}
}
