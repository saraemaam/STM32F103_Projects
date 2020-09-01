/*********************************************************************/
/*  Author : Sarah Abuzaid                                           */                     
/*  Date   :   23 Aug 2020                                           */           
/*  Version:   V01                                                   */
/*********************************************************************/

#ifndef AFIO_PRIVATE_H 
#define AFIO_PRIVATE_H

typedef struct {
 volatile u32 EVCR    ;
 volatile u32 MAPR    ;
 /*volatile u32 EXTICR1 ;
 volatile u32 EXTICR2 ;
 volatile u32 EXTICR3 ;
 volatile u32 EXTICR4 ;
 */
 volatile u32 EXTICR[4];
 volatile u32 MAPR2   ;	
}AFIO_t;


#define AFIO    ( (volatile AFIO_t*) 0x40010000 )


#endif
