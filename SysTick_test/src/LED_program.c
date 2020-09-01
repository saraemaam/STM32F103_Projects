/***********************************************************************************************/
/*  AUTHOR : SARAH MUHAMED EMAM                                                                */
/*  DATE   : 14 AUG 2020                                                                       */
/*  VERSION: V01                                                                               */
/************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"

void Led_voidInit   (u8 LedId ){
	switch (LedId){
	case LED_1 :
		MGPIO_voidSetPinDir ( LED_PORT , LED_u8ID_1 , LED_OUTPUT_MODE ) ;
		break;
	case LED_2 :
		MGPIO_voidSetPinDir ( LED_PORT , LED_u8ID_2 , LED_OUTPUT_MODE ) ;
		break;
	case LED_3 :
		MGPIO_voidSetPinDir ( LED_PORT , LED_u8ID_3 , LED_OUTPUT_MODE ) ;
		break;
	case LED_4 :
		MGPIO_voidSetPinDir ( LED_PORT , LED_u8ID_4 , LED_OUTPUT_MODE ) ;
		break;
	case LED_5:
		MGPIO_voidSetPinDir ( LED_PORT , LED_u8ID_5 , LED_OUTPUT_MODE ) ;
		break;
	case LED_6:
		MGPIO_voidSetPinDir ( LED_PORT , LED_u8ID_6 , LED_OUTPUT_MODE ) ;
		break;
	case LED_7:
		MGPIO_voidSetPinDir ( LED_PORT , LED_u8ID_7 , LED_OUTPUT_MODE ) ;
		break;
	case LED_8:
		MGPIO_voidSetPinDir ( LED_PORT , LED_u8ID_8 , LED_OUTPUT_MODE ) ;
		break;
	default:
		break;
	}
}
void Led_voidTurnOn (u8 LedId){
	switch (LedId){
	case LED_1 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_1 , HIGH ) ;
		break;
	case LED_2 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_2 , HIGH ) ;
		break;
	case LED_3 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_3 , HIGH ) ;
		break;
	case LED_4 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_4 , HIGH ) ;
		break;
	case LED_5 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_5 , HIGH ) ;
		break;
	case LED_6 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_6 , HIGH ) ;
		break;
	case LED_7 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_7 , HIGH ) ;
		break;
	case LED_8 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_8 , HIGH ) ;
		break;

	}
}
void Led_voidTurnOff(u8 LedId){
	switch(LedId){
	case LED_1 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_1 , LOW ) ;
		break;
	case LED_2 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_2 , LOW ) ;
		break;
	case LED_3 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_3 , LOW ) ;
		break;
	case LED_4 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_4 , LOW ) ;
		break;
	case LED_5 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_5 , LOW ) ;
		break;
	case LED_6 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_6 , LOW ) ;
		break;
	case LED_7 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_7 , LOW ) ;
		break;
	case LED_8 :
		MGPIO_voidSetPinVal (  LED_PORT , LED_u8ID_8 , LOW ) ;
		break;
	default :
		break;
	}
}

