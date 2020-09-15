/*****************************************************/
/* Author   : Sarah Abuzaid                           */
/* Version  : V01                                    */
/* Date     : 14 SEP 2020                            */
/*****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidSendSynchronous(u32 Copy_u8DataToSend, u8 Copy_u8NumberOfRegisters)
{
	s8 Local_u8Counter;
	u8 Local_u8Bit;

	Local_u8Counter = Copy_u8NumberOfRegisters * 8 - 1;

	for (; Local_u8Counter >= 0; Local_u8Counter--)
	{
		/*Send bit by bit starting from MSb*/
		Local_u8Bit = GET_BIT(Copy_u8DataToSend, Local_u8Counter);

		MGPIO_voidSetPinVal(HSTP_SERIAL_DATA, Local_u8Bit);

		/*send pulse to shift reg clock*/
		MGPIO_voidSetPinVal(HSTP_SHIFT_CLOCK, HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinVal(HSTP_SHIFT_CLOCK, LOW);
		MSTK_voidSetBusyWait(1);
	}
	/*send pulse to storage clock*/
	MGPIO_voidSetPinVal(HSTP_STORE_CLOCK, HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinVal(HSTP_STORE_CLOCK , LOW);
	MSTK_voidSetBusyWait(1);
}
