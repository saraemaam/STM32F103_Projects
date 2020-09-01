/*
 * main.c
 *
 *  Created on: Aug 24, 2020
 *      Author: Admin
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"DIO_interface.h"
#include"NVIC_interface.h"

void main (void){
	/*initialize clock system */
	RCC_voidInitSysClock( ) ;
	/*Enable clock for GPIOA*/
	RCC_voidEnableClock(RCC_APB2 , 2 );

	/*Pin configuration for 3 Leds */
	MGPIO_voidSetPinDir( GPIOA , PIN0 , OUTPUT_SPEED_2_MHZ_PP );
	MGPIO_voidSetPinDir( GPIOA , PIN1 , OUTPUT_SPEED_2_MHZ_PP );
	MGPIO_voidSetPinDir( GPIOA , PIN2 , OUTPUT_SPEED_2_MHZ_PP );

	/*Set priority for peripheral number 7 EXTI1 0 Group , 3 sub priority*/
	MNVIC_voidSetPriority(7,0,3);
	/*Set priority for EXTI0 3 Group and 0 sub */
	MNVIC_voidSetPriority(6,1,0);
	/*Enable interrupt for EXTI0*/
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);
	/*Set pending flag for EXT0*/
	MNVIC_voidSetPendingFlag(6);


	while(1){

	}
}
void EXTI0_IRQHandler(void){
	MGPIO_voidSetPinVal(GPIOA , PIN0 , HIGH);
	MNVIC_voidSetPendingFlag(7);
	MGPIO_voidSetPinVal(GPIOA , PIN1 , HIGH);

}

void EXTI1_IRQHandler(void){
	MGPIO_voidSetPinVal(GPIOA , PIN2 , HIGH);
}

