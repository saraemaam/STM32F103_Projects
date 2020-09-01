/*
 * main.c
 *
 *  Created on: Aug 14, 2020
 *      Author: Admin
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SSD_interface.h"

void main(void){

	/*initialize clock system */
	RCC_voidInitSysClock();
	/*Enable GPIOA peripheral on APB2 bus */
	RCC_voidEnableClock (RCC_APB2 , 2) ;


	GPIO_voidSetPinDir (GPIOA , PIN0 , OUTPUT_SPEED_2_MHZ_PP ) ;
	GPIO_voidSetPinDir (GPIOA , PIN1 , OUTPUT_SPEED_2_MHZ_PP ) ;
	GPIO_voidSetPinDir (GPIOA , PIN2 , OUTPUT_SPEED_2_MHZ_PP ) ;
	GPIO_voidSetPinDir (GPIOA , PIN3 , OUTPUT_SPEED_2_MHZ_PP ) ;
	GPIO_voidSetPinDir (GPIOA , PIN4 , OUTPUT_SPEED_2_MHZ_PP ) ;
	GPIO_voidSetPinDir (GPIOA , PIN5 , OUTPUT_SPEED_2_MHZ_PP ) ;
	GPIO_voidSetPinDir (GPIOA , PIN6 , OUTPUT_SPEED_2_MHZ_PP ) ;
	GPIO_voidSetPinDir (GPIOA , PIN7 , OUTPUT_SPEED_2_MHZ_PP ) ;

	while(1){

		SevenSeg_vidDisplay ( COMMON_CATHODE_SSD , 5 );
	}


}
