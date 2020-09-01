/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   22 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H




#define NVIC_ISER0          *((u32*)0xE000E100)  /*Enable external interrupts from address 0 to 31 */
#define NVIC_ISER1          *((u32*)0xE000E104)  /*Enable external interrupts from address 32 to 63 */

#define NVIC_ICER0          *((u32*)0xE000E180)
#define NVIC_ICER1          *((u32*)0xE000E184)

#define NVIC_ISPR0          *((u32*)0xE000E200)
#define NVIC_ISPR1          *((u32*)0xE000E204)

#define NVIC_ICPR0          *((u32*)0xE000E280)
#define NVIC_ICPR1          *((u32*)0xE000E284)
 
#define NVIC_IABR0          *((volatile u32*)0xE000E300)
#define NVIC_IABR1          *((volatile u32*)0xE000E304)

#define NVIC_IPR             ((volatile u8*)0xE000E100 + 0x300)
#define SCB_AIRCR           *((volatile u32*)0xE000ED00 + 0x0C)

#define MNVIC_GROUP_4_SUB_0                 0x05FA0300  //4 bits for group priority 
#define MNVIC_GROUP_3_SUB_1                 0x05FA0400  //3 bits for group 1 for sub
#define MNVIC_GROUP_2_SUB_2                 0x05FA0500  //2 bits for group 2 for sub 
#define MNVIC_GROUP_1_SUB_3                 0x05FA0600  //1 bits for group 3 for sub 
#define MNVIC_GROUP_0_SUB_4                 0x05FA0700  //0 bits for group 4 for sub 

#endif

