/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   23 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H


/*Port Map parameters for any port */
#define PORTA_PIN   0b0000
#define PORTB_PIN   0b0001
#define PORTC_PIN   0b0010
#define PORTD_PIN   0b0011
#define PORTE_PIN   0b0100
#define PORTF_PIN   0b0101
#define PORTG_PIN   0b0110


void MAFIO_voidSetEXTIConfiguration ( u8 Copy_u8Line , u8 Copy_u8PortMap );











#endif
