/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   26 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/
#ifndef SySTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

/*#define SYSTEM_TIMER_BASE_ADDRESS  0xE000E010

#define STK_CTRL   *((volatile u32*)SYSTEM_TIMER_BASE_ADDRESS +0x00)
#define STK_LOAD   *((volatile u32*)SYSTEM_TIMER_BASE_ADDRESS +0x04)
#define STK_VAL    *((volatile u32*)SYSTEM_TIMER_BASE_ADDRESS +0x08)
#define STK_CALIB  *((volatile u32*)SYSTEM_TIMER_BASE_ADDRESS +0x0C)

*/
typedef struct {
	volatile u32 STK_CTRL ;
	volatile u32 STK_LOAD ;
	volatile u32 STK_VAL ;
	volatile u32 STK_CALIB ;
}STK_t;

#define STK   ((volatile STK_t*)0xE000E010)

#define AHB        0
#define AHB_DIV_8  1

#endif