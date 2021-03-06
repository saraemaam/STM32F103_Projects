/************************************************************************/
/* Author : Sarah Abuzaid                                               */
/* Version: V01                                                         */
/* Date   : 13 Aug 2020                                                  */
/************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"DIO_private.h"


void MGPIO_voidSetPinDir (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode ) {
	
switch(copy_u8Port){
	
	case GPIOA:
	      if(copy_u8Pin <= 7)/*LOW register */
		  {
			 GPIOA_CRL &= ~ ( (0b1111)<< ( copy_u8Pin *4 ) );
             GPIOA_CRL |= ( copy_u8Mode ) << (copy_u8Pin *4);		 
		  }
		  else if (copy_u8Pin <= 15) /*HIGH register*/
		  {
			  copy_u8Pin = copy_u8Pin - 8 ;
			  GPIOA_CRH &= ~ ( (0b1111)<< ( copy_u8Pin *4 ) );
              GPIOA_CRH |= ( copy_u8Mode ) << (copy_u8Pin *4);	
		  }
		  break;
		  
	case GPIOB:
	 if(copy_u8Pin <= 7)/*LOW register */
		  {
			 GPIOB_CRL &= ~ ( (0b1111)<< ( copy_u8Pin *4 ) );
             GPIOB_CRL |= ( copy_u8Mode ) << (copy_u8Pin *4);		 
		  }
		  else if (copy_u8Pin <= 15) /*HIGH register*/
		  {
			  copy_u8Pin = copy_u8Pin - 8 ;
			  GPIOB_CRH &= ~ ( (0b1111)<< ( copy_u8Pin *4 ) );
              GPIOB_CRH |= ( copy_u8Mode ) << (copy_u8Pin *4);	
		  }
		  break;
	
	case GPIOC:
	 if(copy_u8Pin <= 7)/*LOW register */
		  {
			 GPIOC_CRL &= ~ ( (0b1111)<< ( copy_u8Pin *4 ) );
             GPIOC_CRL |= ( copy_u8Mode ) << (copy_u8Pin *4);		 
		  }
		  else if (copy_u8Pin <= 15) /*HIGH register*/
		  {
			  copy_u8Pin = copy_u8Pin - 8 ;
			  GPIOC_CRH &= ~ ( (0b1111)<< ( copy_u8Pin *4 ) );
              GPIOC_CRH |= ( copy_u8Mode ) << (copy_u8Pin *4);	
		  }
		  break;
		  default : break ;
}
}
void MGPIO_voidSetPinVal(u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value ) {
    
    switch(copy_u8Port)
	{
	case GPIOA :
	if ( copy_u8Value == HIGH ){
     SET_BIT( GPIOA_ODR , copy_u8Pin );
	 
	}
	else if ( copy_u8Value == LOW ){
		CLR_BIT( GPIOA_ODR , copy_u8Pin );
	}
	break;
	case GPIOB :
	if ( copy_u8Value == HIGH ){
     SET_BIT( GPIOB_ODR , copy_u8Pin );
	 
	}
	else if ( copy_u8Value == LOW ){
		CLR_BIT( GPIOB_ODR , copy_u8Pin );
	}
	break;
	case GPIOC :
	if ( copy_u8Value == HIGH ){
     SET_BIT( GPIOC_ODR , copy_u8Pin );
	 
	}
	else if ( copy_u8Value == LOW ){
		CLR_BIT( GPIOC_ODR , copy_u8Pin );
	}
	break;
	default:
		break;
	}
	
	
	
}
u8 MGPIO_voidGetPinVal(u8 copy_u8Port , u8 copy_u8Pin)
{
	u8 LOC_u8Result=0;
	
	switch(copy_u8Port){
		
		case GPIOA:
		LOC_u8Result=GET_BIT(GPIOA_IDR , copy_u8Pin );
		break;
		case GPIOB:
		LOC_u8Result=GET_BIT(GPIOB_IDR , copy_u8Pin );
		break;
		case GPIOC:
		LOC_u8Result=GET_BIT(GPIOC_IDR , copy_u8Pin );
		break;
		
	}
	return LOC_u8Result;
	
	
}
