/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   26 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/
#ifndef SySTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void MSTK_voidInit();
void MSTK_voidInterruptEnable();
void MSTK_voidLoadValue(u32 Copy_u32LoadValue );
void MSTK_voidDelay_us( u16 copy_u16MicroSeconds );
void MSTK_voidDelay_ms( u16 copy_u16MilliSeconds );



#endif
