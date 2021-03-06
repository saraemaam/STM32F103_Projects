/*
 * main.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Sarah Abuzaid
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"LED_interface.h"
#include"RCC_interface.h"
#include"DIO_interface.h"
#include"NVIC_interface.h"
#include"STK_interface.h"
#include"EXTI_interface.h"
#include"AFIO_interface.h"

void AppFun (void);
void main(void){
	/*initialize Clock system*/
	MRCC_voidInitSysClock();
	/*Enable Peripheral 2 on APB2 Bus GPIOA */
	MRCC_voidEnableClock(RCC_APB2 ,  2);
	/*Enable Peripheral 0 on APB2 Bus AFIO*/
	MRCC_voidEnableClock(RCC_APB2 ,  0);
	MEXTI_voidSetCallBack(AppFun);
	/*Configure A0 as Input pin */
	MGPIO_voidSetPinDir(GPIOA,PIN0,INPUT_PULL_UP_DOWN);
	/*A0 input PULL UP*/
	MGPIO_voidSetPinVal(GPIOA,PIN0,HIGH);
	/*initialize PIN2 */
	Led_voidInit(LED_2);
	/*Select Line 0 and Port A of Alternative function*/
	MAFIO_voidSetEXTIConfiguration ( LINE0 , PORTA_PIN );

	/*Enable EXTI0 interrupt */
	MNVIC_voidEnableInterrupt(6);

	/*Set Priorities for EXTI0 */
	MNVIC_voidSetPriority(6,1,3);
	/*EXTI0 initialize*/
	MEXTI_voidInit();
	MEXTI_voidSetSignalLatch(LINE0 ,FALLING);




	while(1)
	{

	}

}

void AppFun(void)
{
	/*Turn on Led*/
	Led_voidTurnOn(LED_2);
	/*Delay for 1 second*/
	MSTK_voidSetBusyWait(1000000);
	/*Turn off Led*/
	Led_voidTurnOff(LED_2);
	/*Delay for 1 second*/
	MSTK_voidSetBusyWait(1000000);
}


