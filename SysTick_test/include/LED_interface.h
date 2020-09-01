/***********************************************************************************************/
/*  AUTHOR : SARAH MUHAMED EMAM                                                                */
/*  DATE   : 14 AUG 2020                                                                       */
/*  VERSION: V01                                                                               */
/************************************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#define LED_1 1
#define LED_2 2
#define LED_3 3
#define LED_4 4
#define LED_5 5
#define LED_6 6
#define LED_7 7
#define LED_8 8

void Led_voidInit   (u8 LedId);
void Led_voidTurnOn (u8 LedId);
void Led_voidTurnOff(u8 LedId);
void Led_voidLeft_shifting();
void Led_voidRight_shifting();
void Led_voidInOut();
void Led_voidOutIn();
void Led_voidFlashing();






















#endif
