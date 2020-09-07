/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   7 sep 2020                                            */           
/*  Version:   V01                                                   */
/*********************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"STK_interface.h"
#include"OS_interface.h"
#include"OS_private.h"
#include"OS_config.h"

#define NULL   (void*)0
/*Array of structure Array of Tasks */
static Task OS_Tasks[NUMBER_OF_TASKS] = { NULL } ;





void SOS_voidCreateTask (u8 Copy_u8Id , u16 Copy_u16Periodicity , void (*Ptr)(void) )
{
	OS_Tasks[Copy_u8Id].Periodicity = Copy_u16Periodicity ;
	OS_Tasks[Copy_u8Id].Fptr        = Ptr ;
}

void SOS_voidStart(void)
{
		/*Initialization*/
		/*determine Tick Time */
		MSTK_voidInit();
		/*Tick 1msec*/
		/*HSE *MHZ / 8 => 1000 usec = 1msec */
		MTSK_voidSetIntervalPeriodic( 1000 ,Scheduler );	
}

volatile u16 Tick_Counts = 0 ;
/*Ordering of Tasks*/
static void Scheduler (void )
{

   for (u8 i = 0 ; i < NUMBER_OF_TASKS ; i++ )
   {
	   if ( (Tick_Counts % OS_Tasks[i].Periodicity )== 0 )
	   {
		   OS_Tasks[i].Fptr();
	   }
		   
   }	

  Tick_Counts++;
	
}
