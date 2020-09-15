/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   26 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/* Apply clock choice from configuration file 
   Disable Systick
   Disable SysTick interrupt */
void MSTK_voidInit();
/*Synchronous function */
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks );
/*Asynchronous function */
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks , void (*copy_ptr )(void));
void MTSK_voidSetIntervalPeriodic( u32 Copy_u32Ticks , void (*copy_ptr )(void));
/*Stops timer at any time */
void MTSK_voidStopTimer(void);
/*returns Elapsed time*/
u32  MTSK_u32GetElapsedTime(void);
/*returns Remaining time */
u32  MTSK_u32GetRemainingTime(void);


#endif