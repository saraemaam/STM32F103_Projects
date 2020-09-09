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
	u8 Arr[23]={0,46,42,42,42,58,0,62,10,10,62,0,62,10,10,22,32,0,62,10,10,62,0};
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

	HLEDMRX_voidAnimation(Arr);


}

