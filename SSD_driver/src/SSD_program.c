/***********************************************************************************************/
/*  AUTHOR : SARAH MUHAMED EMAM                                                                */
/*  DATE   : 14 AUG 2020                                                                       */
/*  VERSION: V01                                                                               */
/**********************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_config.h"


void SevenSeg_vidDisplay ( u8 SevenSeg_type , u8 num ){

	u8 numArr[10]={0x3F , 0x06 , 0x5B , 0x4F ,0x66 , 0x6D , 0x7D ,0x07 ,0x7F , 0x1F };
	switch ( SevenSeg_type ){
	case COMMON_ANODE_SSD :
		GPIO_voidSetPinVal ( SSD_PORT , PIN0 , ~GET_BIT (numArr[num] , 0 )  );
		GPIO_voidSetPinVal ( SSD_PORT , PIN1 , ~GET_BIT (numArr[num] , 1 )  );
		GPIO_voidSetPinVal ( SSD_PORT , PIN2 , ~GET_BIT (numArr[num] , 2 )  );
		GPIO_voidSetPinVal ( SSD_PORT , PIN3 , ~GET_BIT (numArr[num] , 3 )  );
		GPIO_voidSetPinVal ( SSD_PORT , PIN4 , ~GET_BIT (numArr[num] , 4 )  );
		GPIO_voidSetPinVal ( SSD_PORT , PIN5 , ~GET_BIT (numArr[num] , 5 )  );
		GPIO_voidSetPinVal ( SSD_PORT , PIN6 , ~GET_BIT (numArr[num] , 6 )  );
		break;

	case COMMON_CATHODE_SSD :
		GPIO_voidSetPinVal ( SSD_PORT , PIN0 , GET_BIT( numArr[num] , 0 ) ) ;
		GPIO_voidSetPinVal ( SSD_PORT , PIN1 , GET_BIT( numArr[num] , 1 ) ) ;
		GPIO_voidSetPinVal ( SSD_PORT , PIN2 , GET_BIT( numArr[num] , 2 ) ) ;
		GPIO_voidSetPinVal ( SSD_PORT , PIN3 , GET_BIT( numArr[num] , 3 ) ) ;
		GPIO_voidSetPinVal ( SSD_PORT , PIN4 , GET_BIT( numArr[num] , 4 ) ) ;
		GPIO_voidSetPinVal ( SSD_PORT , PIN5 , GET_BIT( numArr[num] , 5 ) ) ;
		GPIO_voidSetPinVal ( SSD_PORT , PIN6 , GET_BIT( numArr[num] , 6 ) ) ;

		break;
	}

}
