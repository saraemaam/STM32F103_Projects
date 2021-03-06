/***********************************************************************************************/
/*  AUTHOR : SARAH MUHAMED EMAM                                                                */
/*  DATE   : 14 AUG 2020                                                                       */
/*  VERSION: V01                                                                               */
/************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include"SysTick_interface.h"
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

void Led_voidLeft_shifting(){
	u8 LedArr[]={LED_8 , LED_7 , LED_6 , LED_5 , LED_4 , LED_3 , LED_2 , LED_1  };
	for(u8 i=0 ; i<=7 ;i++){
		Led_voidTurnOn (LedArr[i]);
		MSTK_voidDelay_ms(200);
		Led_voidTurnOff(LedArr[i]);
		MSTK_voidDelay_ms(200);
	}
}
void Led_voidRight_shifting(){
	u8 LedArr[]={LED_1 , LED_2 , LED_3 , LED_4 , LED_5 , LED_6 , LED_7 , LED_8 };
	for(u8 i=0 ; i<=7 ;i++){
		Led_voidTurnOn (LedArr[i]);
		MSTK_voidDelay_ms(200);
		Led_voidTurnOff(LedArr[i]);
		MSTK_voidDelay_ms(200);
	}
}

void Led_voidInOut(){

	u8 LedArr[]={LED_1 , LED_2 , LED_3 , LED_4 , LED_5 , LED_6 , LED_7 , LED_8 };
	u8 Local_variable = 1;
	for(s8 i=3 ; i>=0 ;i--){
		Led_voidTurnOn(LedArr[i]);
		Led_voidTurnOn(LedArr[i]+Local_variable);
		MSTK_voidDelay_ms(200);
		Local_variable+=2;

	}

}
void Led_voidOutIn(){
	u8 LedArr[]={LED_1 , LED_2 , LED_3 , LED_4 , LED_5 , LED_6 , LED_7 , LED_8 };
	u8 Local_variable=7;
	for(u8 i=0 ; i<=3 ;i++){
		Led_voidTurnOff(LedArr[i]);
		Led_voidTurnOff(LedArr[i]+ Local_variable);
		MSTK_voidDelay_ms(200);
		Local_variable-=2;

	}

}
void Led_voidFlashing(){
	u8 LedArr[]={LED_1 , LED_2 , LED_3 , LED_4 , LED_5 , LED_6 , LED_7 , LED_8 };
	for(u8 i=0 ; i<=7 ;i++){
		Led_voidTurnOn(LedArr[i]);
	}
	MSTK_voidDelay_ms(500);
	for(u8 i=0 ; i<=7 ;i++){
		Led_voidTurnOff(LedArr[i]);
	}
}
