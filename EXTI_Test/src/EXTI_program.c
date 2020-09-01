/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   23 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#define NULL   (void*)0
static void(*EXTI0_CallBack)(void) = NULL ;

void MEXTI_voidInit ()
{   
    /*External interrupt Lines */
    #if EXTI_LINE ==   LINE0
	SET_BIT( EXTI -> IMR , LINE0 );
	#elif EXTI_LINE == LINE1
	SET_BIT( EXTI -> IMR , LINE1 );
	#elif EXTI_LINE == LINE2
	SET_BIT( EXTI -> IMR , LINE2 );
	#elif EXTI_LINE == LINE3
	SET_BIT( EXTI -> IMR , LINE3 );
	#elif EXTI_LINE == LINE4
	SET_BIT( EXTI -> IMR , LINE4 );
	#elif EXTI_LINE == LINE5
	SET_BIT( EXTI -> IMR , LINE5 );
	#elif EXTI_LINE == LINE6
	SET_BIT( EXTI -> IMR , LINE6 );
	#elif EXTI_LINE == LINE7
	SET_BIT( EXTI -> IMR , LINE7 );
	#elif EXTI_LINE == LINE8
	SET_BIT( EXTI -> IMR , LINE8 );
	#elif EXTI_LINE == LINE9
	SET_BIT( EXTI -> IMR , LINE9 );
	#elif EXTI_LINE == LINE10
	SET_BIT( EXTI -> IMR , LINE10 );
	#elif EXTI_LINE == LINE11
	SET_BIT( EXTI -> IMR , LINE11 );
	#elif EXTI_LINE == LINE12
	SET_BIT( EXTI -> IMR , LINE12 );
	#elif EXTI_LINE == LINE13
	SET_BIT( EXTI -> IMR , LINE13 );
	#elif EXTI_LINE == LINE14
	SET_BIT( EXTI -> IMR , LINE14 );
	#elif EXTI_LINE == LINE15
	SET_BIT( EXTI -> IMR , LINE15 );
	#else 
		#error ("Wrong line choice !! " )
	#endif
	/*External interrupt sense mode */
	#if EXTI_MODE == RISING 
	SET_BIT( EXTI -> RTSR , EXTI_LINE );

	#elif EXTI_MODE == FALLING 
	SET_BIT( EXTI -> FTSR , EXTI_LINE );
	#elif EXTI_MODE == ON_CHANGE
	SET_BIT( EXTI -> FTSR , EXTI_LINE );
	SET_BIT( EXTI -> RTSR , EXTI_LINE );
	#else 
		#error ("Wrong mode choice ")
	#endif
	

}

void MEXTI_voidEnableEXTI( u8 Copy_u8EXTILine )
{
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine) ;
}

void MEXTI_voidDisableEXTI( u8 Copy_u8EXTILine )
{
	CLR_BIT(EXTI -> IMR , Copy_u8EXTILine ) ;
}

void MEXTI_voidSwTrigger  (u8 Copy_u8EXTILine)
{
	/*Enable interrupt on this Line*/
	SET_BIT( EXTI -> IMR , Copy_u8EXTILine );
	/*enable software trigger*/
	SET_BIT (EXTI -> SWIER , Copy_u8EXTILine );
	/*Set pending bit */
	SET_BIT (EXTI -> PR , Copy_u8EXTILine );
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode )
{
switch (Copy_u8EXTISenseMode){
	case RISING    :  SET_BIT( EXTI -> RTSR ,  Copy_u8EXTILine ); break;
	case FALLING   :  SET_BIT( EXTI -> FTSR ,  Copy_u8EXTILine ); break;
	case ON_CHANGE :  SET_BIT( EXTI -> RTSR , Copy_u8EXTILine );
	                  SET_BIT( EXTI -> FTSR , Copy_u8EXTILine ); break;
					  	
}	
SET_BIT(EXTI -> IMR , Copy_u8EXTILine ) ;

}

void MEXTI_voidSetCallBack (void (*ptr)(void))
{
	
	EXTI0_CallBack = ptr ;
}

void EXTI0_IRQHandler (void)
{
	
EXTI0_CallBack ();
 
 /*Clear pending bit*/
 SET_BIT( EXTI -> PR , EXTI_LINE);
}
