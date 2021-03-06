/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   26 Aug 2020                                           */           
/*  Version:   V02                                                   */
/*********************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

void(*CallBackPfun)(void);
u8 Global_u8Counter ;

void MSTK_voidInit()
{
	/*Disable SysTick */
	CLR_BIT( STK->STK_CTRL , 0);
	/*Disable interrupt */
	CLR_BIT( STK->STK_CTRL , 1 );
	/*STK clock source */
	#if SYSTICK_CLKSOURCE == AHB 
	SET_BIT( STK->STK_CTRL , 2);
	#elif SYSTICK_CLKSOURCE == AHB_DIV_8
	CLR_BIT( STK->STK_CTRL , 2);
	#else
	#error ("Wrong Clock source Choice ")
	#endif
}
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks )
{
	STK->STK_LOAD = Copy_u32Ticks ;
	while(!(GET_BIT( STK->STK_CTRL , STK_CTRL_COUNT_FLAG )));
}

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks , void (*copy_ptr )(void) )
{
	Global_u8Counter=0;
	CallBackPfun = copy_ptr ;
	STK->STK_LOAD = Copy_u32Ticks ;
	/*Enable interrupt */
	SET_BIT( STK->STK_CTRL , 1 );
	/*for single interval only */
	STK->STK_LOAD=0;
	
}

void MTSK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void (*copy_ptr )(void))
{
    Global_u8Counter++;
	CallBackPfun = copy_ptr ;
	STK->STK_LOAD = Copy_u32Ticks ;
	/*Enable interrupt */
	SET_BIT( STK->STK_CTRL , 1 );
}

void MTSK_voidStopTimer(void){
	/*Disable SysTick at anytime */
	CLR_BIT( STK->STK_CTRL , 0);
}

u32  MTSK_u32GetElapsedTime(void){

  return (STK->STK_LOAD - STK->STK_VAL )	;
}

u32  MTSK_u32GetRemainingTime(void){
	
	return STK-> STK_VAL ;
}

void SysTick_Handler (void)
{	
CallBackPfun();

if (Global_u8Counter == 0)
{
	/*Disable SysTick for single interval */
	CLR_BIT( STK->STK_CTRL , 0);
}
else{
	
}

}
