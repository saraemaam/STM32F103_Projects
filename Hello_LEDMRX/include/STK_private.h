/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   26 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/*(using MACROS)
#define SYSTEM_TIMER_BASE_ADDRESS  0xE000E010
#define STK_CTRL   *((volatile u32*)SYSTEM_TIMER_BASE_ADDRESS +0x00)
#define STK_LOAD   *((volatile u32*)SYSTEM_TIMER_BASE_ADDRESS +0x04)
#define STK_VAL    *((volatile u32*)SYSTEM_TIMER_BASE_ADDRESS +0x08)
#define STK_CALIB  *((volatile u32*)SYSTEM_TIMER_BASE_ADDRESS +0x0C)
*/

/*Using Struct*/
typedef struct {
	volatile u32 STK_CTRL ;
	volatile u32 STK_LOAD ;
	volatile u32 STK_VAL ;
	volatile u32 STK_CALIB ;
}MSTK_type;

#define MSTK   ((volatile MSTK_type*)0xE000E010)

#define MSTK_SRC_AHB        0
#define MSTK_SRC_AHB_DIV_8  1

#define MSTK_SINGLE_INTERVAL    0
#define MSTK_PERIODIC_INTERVAL  1

#define ENABLE_BIT  0
#define COUNT_FLAG 16
#define TICK_INT    1


#endif