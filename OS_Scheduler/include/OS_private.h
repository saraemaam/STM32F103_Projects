/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   7 sep 2020                                            */           
/*  Version:   V01                                                   */
/*********************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct {
	u16 Periodicity  ;
	void (*Fptr)(void);
}Task;



static void Scheduler (void );








#endif
