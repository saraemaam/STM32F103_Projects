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
#include"LEDMRX_private.h"
#include"LEDMRX_config.h"

void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDir(LEDMRX_ROW0_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_ROW1_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_ROW2_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_ROW3_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_ROW4_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_ROW5_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_ROW6_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_ROW7_PIN,0b0010);

	MGPIO_voidSetPinDir(LEDMRX_COL0_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_COL1_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_COL2_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_COL3_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_COL4_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_COL5_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_COL6_PIN,0b0010);
	MGPIO_voidSetPinDir(LEDMRX_COL7_PIN,0b0010);

}


void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1){
     /*Column 0 */
	/* Disable all Columns */
	DisableAllCols();
	//send value
	SetRowValues(Copy_u8Data[0]);
	/* Enable Column 0 */
	MGPIO_voidSetPinVal(LEDMRX_COL0_PIN,LOW);
	//2.5 msec delay 
	MSTK_voidSetBusyWait(2500); 
	
	/*Column 1 */
	/* Disable all Columns */
	DisableAllCols();
	//send value
	SetRowValues(Copy_u8Data[1]);
	/* Enable Column 1 */
	MGPIO_voidSetPinVal(LEDMRX_COL1_PIN,LOW);
	//2.5 msec delay 
	MSTK_voidSetBusyWait(2500); 
	
	/*Column2 */
	/* Disable all Columns */
	DisableAllCols();
	//send value
	SetRowValues(Copy_u8Data[2]);
	/* Enable Column 2 */
	MGPIO_voidSetPinVal(LEDMRX_COL2_PIN,LOW);
	//2.5 msec delay 
	MSTK_voidSetBusyWait(2500); 
	
	/*Column 3 */
	/* Disable all Columns */
	DisableAllCols();
	//send value
	SetRowValues(Copy_u8Data[3]);
	/* Enable Column 3 */
	MGPIO_voidSetPinVal(LEDMRX_COL3_PIN,LOW);
	//2.5 msec delay 
	MSTK_voidSetBusyWait(2500); 
	
	/*Column 4 */
	/* Disable all Columns */
	DisableAllCols();
	//send value
	SetRowValues(Copy_u8Data[4]);
	/* Enable Column 4 */
	MGPIO_voidSetPinVal(LEDMRX_COL4_PIN,LOW);
	//2.5 msec delay 
	MSTK_voidSetBusyWait(2500); 
	
	/*Column 5 */
	/* Disable alsl Columns */
	DisableAllCols();
	//send value
	SetRowValues(Copy_u8Data[5]);
	/* Enable Column 5 */
	MGPIO_voidSetPinVal(LEDMRX_COL5_PIN,LOW);
	//2.5 msec delay 
	MSTK_voidSetBusyWait(2500); 
	
	/*Column 6 */
	/* Disable all Columns */
	DisableAllCols();
	//send value
	SetRowValues(Copy_u8Data[6]);
	/* Enable Column 0 */
	MGPIO_voidSetPinVal(LEDMRX_COL6_PIN,LOW);
	//2.5 msec delay 
	MSTK_voidSetBusyWait(2500); 
	
	/*Column 7 */
	/* Disable all Columns */
	DisableAllCols();
	//send value
	SetRowValues(Copy_u8Data[7]);
	/* Enable Column 7 */
	MGPIO_voidSetPinVal(LEDMRX_COL7_PIN,LOW);
	//2.5 msec delay 
	MSTK_voidSetBusyWait(2500); 
	
	}
}


static void DisableAllCols(void)
{
	/* Disable all Columns */
		MGPIO_voidSetPinVal(LEDMRX_COL0_PIN,HIGH);
		MGPIO_voidSetPinVal(LEDMRX_COL1_PIN,HIGH);
		MGPIO_voidSetPinVal(LEDMRX_COL2_PIN,HIGH);
		MGPIO_voidSetPinVal(LEDMRX_COL3_PIN,HIGH);
		MGPIO_voidSetPinVal(LEDMRX_COL4_PIN,HIGH);
		MGPIO_voidSetPinVal(LEDMRX_COL5_PIN,HIGH);
		MGPIO_voidSetPinVal(LEDMRX_COL6_PIN,HIGH);
		MGPIO_voidSetPinVal(LEDMRX_COL7_PIN,HIGH);

}

static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	Local_u8BIT = GET_BIT(Copy_u8Value,0);
	MGPIO_voidSetPinVal(LEDMRX_ROW0_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,1);
	MGPIO_voidSetPinVal(LEDMRX_ROW1_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,2);
	MGPIO_voidSetPinVal(LEDMRX_ROW2_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,3);
	MGPIO_voidSetPinVal(LEDMRX_ROW3_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,4);
	MGPIO_voidSetPinVal(LEDMRX_ROW4_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,5);
	MGPIO_voidSetPinVal(LEDMRX_ROW5_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,6);
	MGPIO_voidSetPinVal(LEDMRX_ROW6_PIN,Local_u8BIT);

	Local_u8BIT = GET_BIT(Copy_u8Value,7);
	MGPIO_voidSetPinVal(LEDMRX_ROW7_PIN,Local_u8BIT);

}
