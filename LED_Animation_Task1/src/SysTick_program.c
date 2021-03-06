/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   26 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "SysTick_interface.h"
#include"SysTick_config.h"
#include"SysTick_private.h"


void MSTK_voidInit(){
	/*Enable counter */
	SET_BIT( STK->STK_CTRL , 0);
	/*STK clock source */
	#if SYSTICK_CLKSOURCE == AHB 
	SET_BIT( STK->STK_CTRL , 2);
	#elif SYSTICK_CLKSOURCE == AHB_DIV_8
	CLR_BIT( STK->STK_CTRL , 2);
	#endif
	/*Disable interrupt */
	CLR_BIT( STK->STK_CTRL , 1 );
}
void MSTK_voidInterruptEnable(){
	/*Enable interrupt */
	SET_BIT( STK->STK_CTRL , 1 );
}
void MSTK_voidLoadValue(u32 Copy_u32LoadValue ){
	STK->STK_LOAD = Copy_u32LoadValue ;
	
}

void MSTK_voidDelay_us( u16 copy_u16MicroSeconds ){

	switch(SYSTICK_CLKSOURCE){
	case AHB :
		MSTK_voidLoadValue(8* copy_u16MicroSeconds);
		break;
	case AHB_DIV_8:
		/*Timer freq 1 MHZ
		* TsysTick =1 Microsecond */
		MSTK_voidLoadValue(copy_u16MicroSeconds);
		break;
	default :
		break;
	}
	/*wait until underflow flag is raised */
	while(!(GET_BIT(STK-> STK_CTRL , STK_CTRL_COUNT_FLAG )));

	/*clear underflow flag*/


}
void MSTK_voidDelay_ms( u16 copy_u16MilliSeconds ){
u8 var;
	switch(SYSTICK_CLKSOURCE){
		case AHB :
			MSTK_voidLoadValue(1000*8*copy_u16MilliSeconds);
			break;
		case AHB_DIV_8:
			/*Timer freq 1 MHZ
			* TsysTick =1 Microsecond */
			MSTK_voidLoadValue(1000*copy_u16MilliSeconds);
			break;
		default :
			break;
		}
		/*wait until underflow flag is raised */
		while(!(GET_BIT(STK-> STK_CTRL , STK_CTRL_COUNT_FLAG )));

		/*clear underflow flag*/
		var =GET_BIT(STK-> STK_CTRL , STK_CTRL_COUNT_FLAG );
}

