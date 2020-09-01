/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   22 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber );
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNumber );
void MNVIC_voidSetPendingFlag  (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(u8 copy_u8IntId , u8 copy_u8GroupPriority , u8 copy_u8SubPriority ) ;



#endif

