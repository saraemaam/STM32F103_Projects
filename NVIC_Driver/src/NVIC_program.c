/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   22 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include"NVIC_private.h"
#include"NVIC_config.h"


void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNumber )
{
	//u8 ErrorStatus ;
	if ( Copy_u8IntNumber <=31 )
	{
		//SET_BIT(NVIC_ISER0 , Copy_u8IntNumber );
		//because zero has no effect do direct equal operation 
		NVIC_ISER0 = (1 << Copy_u8IntNumber );
		//ErrorStatus=0;
	}

	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32 ;
		//SET_BIT(NVIC_ISER1 , Copy_u8IntNumber );
		NVIC_ISER1 = (1 << Copy_u8IntNumber );
		//ErrorStatus=0;
	}	
	else
	{
		/*Return Error */
		//ErrorStatus=1;
	}
	//return ErrorStatus ;
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber )
{

	if ( Copy_u8IntNumber <=31 )
	{

		NVIC_ICER0 = (1 << Copy_u8IntNumber );
		//ErrorStatus=0;
	}

	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32 ;

		NVIC_ICER1 = (1 << Copy_u8IntNumber );

	}	
	else
	{

	}

}

void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber){

	if ( Copy_u8IntNumber <=31 )
	{

		NVIC_ISPR0 = (1 << Copy_u8IntNumber );

	}

	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32 ;

		NVIC_ISPR1 = (1 << Copy_u8IntNumber );

	}	
	else
	{

	}

}


void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber){

	if ( Copy_u8IntNumber <=31 )
	{

		NVIC_ICPR0 = (1 << Copy_u8IntNumber );

	}

	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32 ;

		NVIC_ICPR1 = (1 << Copy_u8IntNumber );

	}	
	else
	{

	}

}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber){
	u8 Local_u8Result ;

	if ( Copy_u8IntNumber <=31 )
	{

		Local_u8Result =GET_BIT( NVIC_IABR0 ,  Copy_u8IntNumber );

	}

	else if ( Copy_u8IntNumber <=59 )
	{
		Copy_u8IntNumber -= 32 ;

		Local_u8Result =GET_BIT( NVIC_IABR1 ,  Copy_u8IntNumber );

	}	
	else
	{

	}

	return Local_u8Result ;
}	

void MNVIC_voidSetPriority(u8 copy_u8IntId , u8 copy_u8GroupPriority , u8 copy_u8SubPriority )
{
	u8 Local_u8Priority = (copy_u8SubPriority)|(copy_u8GroupPriority)<<(( NO_OF_GROUPS_SUB_GROUP - 0x05FA0300 )/256) ;


	/*external peripheral*/

	NVIC_IPR[copy_u8IntId] = (Local_u8Priority << 4 );

	/*Vectkey*/
	SCB_AIRCR = NO_OF_GROUPS_SUB_GROUP ;
}
