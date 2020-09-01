/************************************************************************/
/* Author : Sarah Abuzaid                                               */
/* Version: V01                                                         */
/* Date   : 8 Aug 2020                                                  */
/************************************************************************/
#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock(void)
{
  #if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
   RCC_CR   = 0x00010000 ; /*Enable HSE with no Bypass */
   
   RCC_CFGR = 0x00000001 ; /*Select system clock switch as HSE */
   /*	wait until the HSE to be Ready	*/
   while (GET_BIT ( RCC_CR , HSE_RDY ) == 0 );
   
   
  #elif RCC_CLOCK_TYPE == RCC_HSE_RC
   RC_CR    = 0x00050000 ; /*Enable HSE with Bypass*/
   RCC_CFGR = 0x00000001 ; /*Select system clock switch as HSE */
   /*	wait until the HSE to be Ready	*/
   while (GET_BIT ( RCC_CR , HSE_RDY ) == 0 );
   
  #elif RCC_CLOCK_TYPE == RCC_HSI
   RCC_CR   = 0x00000081 ; /*Enable HSI + Trimming =0 (by default 16 )*/
   RCC_CFGR = 0x00000000 ; /*HSI selected as system clock switch */
   /*	wait until the HSE to be Ready	*/
   while (GET_BIT ( RCC_CR , HSI_RDY ) == 0 );
   
  #elif RCC_CLOCK_TYPE == RCC_PLL
    #if   RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
	RCC_CR   = 0x00000081 ; /*Enable HSI + Trimming =0 (by default 16 )*/
	RCC_CFGR = 0x00000000 ; /* PLL input clock source HSI divided by 2 */
	
	#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL_DIV_2
     RCC_CR   = 0x00010000 ; /*Enable HSE with no Bypass */
	 RCC_CFGR = 0x00030001 ; /*HSE selected as system clock switch & Divide HSE/2 */
	 
    #elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_CRYSTAL
	RCC_CR   = 0x00010000 ; /*Enable HSE with no Bypass */
	RCC_CFGR =0x00010001  ; /*HSE selected as system clock switch & HSE not divided */
	#endif
	
	/*PLL MULTIPLICATION FACTOR SELECTION */
	/*first method */
	/*RCC_CFGR | =( (RCC_PLL_MUL_VAL - 2 ) << (PLL_MULBIT) ) ;
	/*second method */
	RCC_CFGR | = ((PLL_INPUT_CLOCK_MUL )<< (PLL_MULBIT));
	
	/*Enable PLL ON after selection PLL source and PLL multiplication factor */
	
	SET_BIT(RCC_CR , PLL_ONBIT);
	
  #else
	#error ("You choose wrong Clock Type ")
	
  #endif
}


void RCC_voidEnableClock(u8 Copy_u8BusId , u8 Copy_u8PerId )
{
	if ( Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB : SET_BIT(RCC_AHBENR , Copy_u8PerId );
			               break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR , Copy_u8PerId );
			               break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR , Copy_u8PerId );
			               break;
		}
		
	}
	else
	{
		/*Return Error */
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId )
{
	if ( Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB : CLR_BIT(RCC_AHBENR , Copy_u8PerId );
			               break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR , Copy_u8PerId );
			               break;
			case RCC_APB2: CLR_BIT(RCC_APB2ENR , Copy_u8PerId );
			               break;
			
		}
		
	}
	else
	{
		/*Return Error */
	}
}



