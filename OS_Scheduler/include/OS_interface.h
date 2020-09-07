/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   7 sep 2020                                            */           
/*  Version:   V01                                                   */
/*********************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask (u8 Copy_u8Id , u16 Copy_u16Periodicity , void (*Ptr)(void) );
void SOS_voidStart(void);
void SOS_voidDeleteTask();
void SOS_voidPauseTask();

































#endif