/*
 * main.c
 *
 *  Created on: Aug 13, 2020
 *      Author: Sarah Abuzaid
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"


void main(void){

	/*initialize clock system */
	RCC_voidInitSysClock();
	/*Enable GPIOA peripheral on APB2 bus */
	RCC_voidEnableClock (RCC_APB2 , 2) ;
	/*Enable GPIOB peripheral on APB2 bus */
	RCC_voidEnableClock (RCC_APB2 , 3) ;
	/*Enable GPIOC peripheral on APB2 bus */
	RCC_voidEnableClock (RCC_APB2 , 4) ;

	/*Configure A0 as input pull up pin */
	MGPIO_voidSetPinDir (GPIOA , PIN0 , INPUT_PULL_UP_DOWN ) ;
	/*Choosing PULL UP or DOWN using ODR register */
	MGPIO_voidSetPinVal(GPIOA , PIN0 , HIGH);

	/*Configure A0:A5 as output push pull @ 10 MHZ*/
	MGPIO_voidSetPinDir (GPIOA , PIN1 , OUTPUT_SPEED_10_MHZ_PP ) ;
	MGPIO_voidSetPinDir (GPIOA , PIN2 , OUTPUT_SPEED_10_MHZ_PP ) ;
	MGPIO_voidSetPinDir (GPIOA , PIN3 , OUTPUT_SPEED_10_MHZ_PP ) ;
	MGPIO_voidSetPinDir (GPIOA , PIN4 , OUTPUT_SPEED_10_MHZ_PP ) ;
	MGPIO_voidSetPinDir (GPIOA , PIN5 , OUTPUT_SPEED_10_MHZ_PP ) ;
	MGPIO_voidSetPinDir (GPIOA , PIN6 , OUTPUT_SPEED_10_MHZ_PP ) ;
	MGPIO_voidSetPinDir (GPIOA , PIN7 , OUTPUT_SPEED_10_MHZ_PP ) ;

	while(1){

		MGPIO_voidSetPinVal(GPIOA , PIN0 , HIGH);
		MGPIO_voidSetPinVal(GPIOA , PIN1 , HIGH);
		MGPIO_voidSetPinVal(GPIOA , PIN2 , HIGH);
		MGPIO_voidSetPinVal(GPIOA , PIN3 , HIGH);
		MGPIO_voidSetPinVal(GPIOA , PIN4 , HIGH);
		MGPIO_voidSetPinVal(GPIOA , PIN5 , HIGH);
		MGPIO_voidSetPinVal(GPIOA , PIN6 , HIGH);
		MGPIO_voidSetPinVal(GPIOA , PIN7 , HIGH);

		/*For delay */
		for(u16 i=0 ; i<600 ; i++)
		{
			for(u16 k=0 ; k<600 ; k++)
			{
				asm("NOP");
			}
		}

		MGPIO_voidSetPinVal(GPIOA , PIN0 , LOW);
		MGPIO_voidSetPinVal(GPIOA , PIN1 , LOW);

		/*For delay */
		for(u16 i=0 ; i<600 ; i++)
		{
			for(u16 k=0 ; k<600 ; k++)
			{
				asm("NOP");

			}
		}

		if( MGPIO_voidGetPinVal(GPIOA , PIN5) == 0)
		{
			MGPIO_voidSetPinVal(GPIOA , PIN5 , HIGH);
		}
		else
		{
			MGPIO_voidSetPinVal(GPIOA , PIN5 , LOW);
		}


		if (MGPIO_voidGetPinVal (GPIOA , PIN0 ) == 0 )
		{
			MGPIO_voidSetPinVal( GPIOA , PIN1 , HIGH );
		}
		else
		{
			MGPIO_voidSetPinVal( GPIOA , PIN1 , LOW );
		}
	}


}
