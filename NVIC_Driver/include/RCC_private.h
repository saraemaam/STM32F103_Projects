/************************************************************************/
/* Author : Sarah Abuzaid                                               */
/* Version: V01                                                         */
/* Date   : 8 Aug 2020                                                  */
/************************************************************************/
#ifndef _RCC_PRIVATE_H
#define _RCC_PRIVATE_H

     /* Register Definitions */
	 
#define RCC_CR         *((u32*)0x40021000)
#define RCC_CFGR       *((u32*)0x40021004)
#define RCC_CIR        *((u32*)0x40021008)
#define RCC_APB2RSTR   *((u32*)0x4002100C)
#define RCC_APB1RSTR   *((u32*)0x40021010)
#define RCC_AHBENR     *((u32*)0x40021014)
#define RCC_APB2ENR    *((u32*)0x40021018)
#define RCC_APB1ENR    *((u32*)0x4002101C)
#define RCC_BDCR       *((u32*)0x40021020)
#define RCC_CSR        *((u32*)0x40021024)


 /*Clock Types */
#define RCC_HSE_CRYSTAL  0
#define RCC_HSE_RC       1
#define RCC_HSI          2
#define RCC_PLL          3

/*PLL options */
#define RCC_PLL_IN_HSI_DIV_2           0
#define RCC_PLL_IN_HSE_CRYSTAL_DIV_2   1    
#define	RCC_PLL_IN_HSE_CRYSTAL         2

#define PLL_MULBIT  18
#define PLL_ONBIT   24
#define HSE_RDY     17
#define HSI_RDY     1

/*PLL Multiplication factor */
#define  PLL_INPUT_CLOCK_MUL_2  0b0000
#define  PLL_INPUT_CLOCK_MUL_3  0b0001
#define	 PLL_INPUT_CLOCK_MUL_4  0b0010
#define	 PLL_INPUT_CLOCK_MUL_5  0b0011
#define	 PLL_INPUT_CLOCK_MUL_6  0b0100
#define	 PLL_INPUT_CLOCK_MUL_7  0b0101
#define	 PLL_INPUT_CLOCK_MUL_8  0b0110
#define	 PLL_INPUT_CLOCK_MUL_9  0b0111
#define	 PLL_INPUT_CLOCK_MUL_10 0b1000
#define	 PLL_INPUT_CLOCK_MUL_11 0b1001
#define	 PLL_INPUT_CLOCK_MUL_12 0b1010
#define	 PLL_INPUT_CLOCK_MUL_13 0b1011
#define	 PLL_INPUT_CLOCK_MUL_14 0b1100
#define  PLL_INPUT_CLOCK_MUL_15 0b1101
#define	 PLL_INPUT_CLOCK_MUL_16 0b1110
		   






#endif