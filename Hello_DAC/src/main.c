/*
 * main.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Sarah Abuzaid
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"DIO_interface.h"
#include"STK_interface.h"
#include"file.h"
#include "DIO_private.h"
volatile u16 i = 0 ;
void voidSetDAC (void){
	GPIOA_ODR = Amaren_raw [i] ;

			 i++;
	if (i == 39660){
		i=0 ;
	}
}

void main(void){
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2, 2);

	MGPIO_voidSetPinDir(GPIOA, PIN0, 0b0010);
	MGPIO_voidSetPinDir(GPIOA, PIN1, 0b0010);
	MGPIO_voidSetPinDir(GPIOA, PIN2, 0b0010);
	MGPIO_voidSetPinDir(GPIOA, PIN3, 0b0010);
	MGPIO_voidSetPinDir(GPIOA, PIN4, 0b0010);
	MGPIO_voidSetPinDir(GPIOA, PIN5, 0b0010);
	MGPIO_voidSetPinDir(GPIOA, PIN6, 0b0010);
	MGPIO_voidSetPinDir(GPIOA, PIN7, 0b0010);

	MSTK_voidInit();
	MTSK_voidSetIntervalPeriodic(125 , voidSetDAC);

}
