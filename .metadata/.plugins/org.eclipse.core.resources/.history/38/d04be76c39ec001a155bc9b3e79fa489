/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   26 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/*Define Callback Global variable*/
static void(*MSTK_CallBack)(void);
/*Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval ;

void MSTK_voidInit()
{
	#if   MSTK_CLK_SRC == MSTK_SRC_AHB 
	/*Disable SysTick - Disable interrupt - Set Clock Source AHB */
	MSTK->STK_CTRL = 0x00000004 ;
	#elif MSTK_CLK_SRC = MSTK_SRC_AHB_DIV_8
	/*Disable SysTick - Disable interrupt - Set Clock Source AHB divided by 8 */
	MSTK->STK_CTRL = 0 ;
	#else
	      #error ("Wrong Clock source Choice ")
	#endif
}
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks )
{
	/*Load Ticks to Load register */
	MSTK->STK_LOAD = Copy_u32Ticks ;
	/*Start Timer*/
	SET_BIT(MSTK->STK_CTRL , ENABLE_BIT );
	/*Wait till Flag is Raised */
	while((GET_BIT( MSTK->STK_CTRL , COUNT_FLAG ) == 0);
	
	/*Stop Timer*/
	CLR_BIT(MSTK->STK_CTRL , ENABLE_BIT );
	MSTK->STK_LOAD = 0 ;
	MSTK->STK_VAL  = 0 ;
	
}

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks , void (*Copy_ptr )(void) )
{
	/*Load Ticks to Load register */
	MSTK->STK_LOAD = Copy_u32Ticks ;
	
	/*Start Timer*/
	SET_BIT(MSTK->STK_CTRL , ENABLE_BIT );
	
	/*Save CallBack*/
	MSTK_CallBack=Copy_ptr ;
	
	/*Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL ;
	
	/*Enable interrupt */
	SET_BIT( STK->STK_CTRL , TICK_INT);
	
}

void MTSK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void (*Copy_ptr )(void))
{
    /*Load Ticks to Load register */
	MSTK->STK_LOAD = Copy_u32Ticks ;
	
	/*Start Timer*/
	SET_BIT(MSTK->STK_CTRL , ENABLE_BIT );
	
	/*Save CallBack*/
	MSTK_CallBack=Copy_ptr ;
	
	/*Set Mode to Periodic */
	MSTK_u8ModeOfInterval = MSTK_PERIODIC_INTERVAL ;
	
	/*Enable interrupt */
	SET_BIT( STK->STK_CTRL , TICK_INT);
}

void MTSK_voidStopTimer(void){
	/*Disable Interrupt */
	CLR_BIT( MSTK->STK_CTRL ,TICK_INT );
	
	/*Stop Timer*/
	CLR_BIT(MSTK->STK_CTRL , ENABLE_BIT );
	MSTK->STK_LOAD = 0 ;
	MSTK->STK_VAL  = 0 ;
}

u32  MTSK_u32GetElapsedTime(void){
  
  u32 Local_u32ElapsedTime ;

  Local_u32ElapsedTime = MSTK->STK_LOAD - MSTK->STK_VAL ;
  return Local_u32ElapsedTime ;
  
}

u32  MTSK_u32GetRemainingTime(void){
	
  u32 Local_u32RemainingTime ;

  Local_u32ElapsedTime = MSTK->STK_VAL ;
  
  return Local_u32RemainingTime;
}

void SysTick_Handler (void)
{	
 
  u8 Local_u8Temporary ;
  
  if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL )
  {
    /*Disable Interrupt */
	CLR_BIT( MSTK->STK_CTRL ,TICK_INT );
	
	/*Stop Timer*/
	CLR_BIT(MSTK->STK_CTRL , ENABLE_BIT );
	MSTK->STK_LOAD = 0 ;
	MSTK->STK_VAL  = 0 ;
  }
  
    /*Call Back notification */
    MSTK_CallBack();
    
	/*Clear Interrupt Flag*/
	
	Local_u8Temporary = GET_BIT (MSTK -> STK_CTRL , COUNT_FLAG );

}
