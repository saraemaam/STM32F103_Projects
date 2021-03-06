/*
 * main.c
 *
 *  Created on: Sep 1, 2020
 *      Author: Sarah Abuzaid
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"RCC_interface.h"
#include"STK_interface.h"
#include"LEDMRX_interface.h"

/*	A		*/
u8 DataArray [8]={0, 124, 18, 18, 18, 18, 124, 0};

void main(void){
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


	HLEDMRX_voidDisplay(DataArray);

}

