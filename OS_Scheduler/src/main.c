/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   7 sep 2020                                            */           
/*  Version:   V01                                                   */
/*********************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "RCC_Interface.h"
#include "DIO_Interface.h"
#include "OS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);

void main (void ){
	/*initialization */
	RCC_voidInitSysClock() ;
	/*Enable GPIOA*/
	 RCC_voidEnableClock (RCC_APB2 , 2) ;

	MGPIO_voidSetPinDir( GPIOA , PIN0 , OUTPUT_SPEED_2_MHZ_PP);
    MGPIO_voidSetPinDir( GPIOA , PIN1 , OUTPUT_SPEED_2_MHZ_PP );
	MGPIO_voidSetPinDir( GPIOA , PIN2 , OUTPUT_SPEED_2_MHZ_PP);
	
	/*Create Tasks*/
	SOS_voidCreateTask(0 , 1000 , LED1);
	SOS_voidCreateTask(1 , 2000 , LED2);
	SOS_voidCreateTask(2 , 3000 , LED3);
	
	SOS_voidStart();
	while(1){
		
		
	}
}

void LED1 (void)
{
	
static u8 Local_u8Pin0 = 0 ;

TOG_BIT(Local_u8Pin0,0)	;

MGPIO_voidSetPinVal(GPIOA , PIN0 , Local_u8Pin0 );
	
}

void LED2(void)
{
	static u8 Local_Pin1=0;
	TOG_BIT(Local_Pin1,0);
	MGPIO_voidSetPinVal( GPIOA , PIN1 , Local_Pin1 );
}

void LED3(void)
{
	static u8 Local_Pin2=0;
	TOG_BIT(Local_Pin2,0);
	MGPIO_voidSetPinVal( GPIOA , PIN2 , Local_Pin2 );
}
