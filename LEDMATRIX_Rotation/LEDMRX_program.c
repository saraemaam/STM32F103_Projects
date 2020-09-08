/*********************************************************************/
/* Author	: Sarah Abuzaid									         */
/* Version  : V01													 */
/* Date     : 31 August 202										     */
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include"LEDMRX_interface.h"
#include"LEDMRX_config.h"
#include"LEDMRX_private.h"

u8 ColumnArray [16] = {LED_MRX_COL0_PIN, LED_MRX_COL1_PIN ,LED_MRX_COL2_PIN ,LED_MRX_COL3_PIN
		,LED_MRX_COL4_PIN ,LED_MRX_COL5_PIN ,LED_MRX_COL6_PIN ,LED_MRX_COL7_PIN};

u8 ROWSArray [16] = {LED_MRX_ROW0_PIN , LED_MRX_ROW1_PIN ,LED_MRX_ROW2_PIN ,LED_MRX_ROW3_PIN
		,LED_MRX_ROW4_PIN,LED_MRX_ROW5_PIN ,LED_MRX_ROW6_PIN,LED_MRX_ROW7_PIN};


void HLEDMRX_voidInit(void)
{
	for(u8 i =0 ; i< 16 ; ){
  		MGPIO_voidSetPinDir(ROWSArray[i],ROWSArray[i+1],OUTPUT_SPEED_2_MHZ_PP);
		MGPIO_voidSetPinDir(ColumnArray[i],ColumnArray[i+1],OUTPUT_SPEED_2_MHZ_PP);
		i+=2;

	}

}
	void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
	{
		u8 j = 0 ;
		for(u8 i=0 ; i < 8 ; i++){
			/* Disable all Columns */
			DisableAllCols();
			//send value
			SetRowValues(Copy_u8Data[i]);
			/* Enable Column  */
			MGPIO_voidSetPinVal(ColumnArray[j],ColumnArray[j+1], LOW );
			j+=2 ;
			//2.5 msec delay
			MSTK_voidSetBusyWait(2500);

		}
	}

	static void DisableAllCols(void)
	{
		for(u8 i =0 ; i< 16 ; ){

			/* Disable all Columns */
			MGPIO_voidSetPinVal(ColumnArray[i],ColumnArray[i+1],HIGH);
			i+=2;
		}
	}

	static void SetRowValues(u8 Copy_u8Value)
	{
		u8 Local_u8BIT;
		u8 j = 0 ;
		for(u8 i =0 ; i< 8 ; i++){
			Local_u8BIT = GET_BIT(Copy_u8Value,i);
			MGPIO_voidSetPinVal(ROWSArray[j],ROWSArray[j+1],Local_u8BIT);
			j+=2 ;
					}
	}
