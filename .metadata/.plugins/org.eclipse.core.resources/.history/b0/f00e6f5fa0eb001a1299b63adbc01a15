/************************************************************************/
/* Author : Sarah Abuzaid                                               */
/* Version: V01                                                         */
/* Date   : 8 Aug 2020                                                  */
/************************************************************************/
#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/* Options RCC_HSE_CRYSTAL 
           RCC_HSE_RC 
		   RCC_HSI
		   RCC_PLL     */
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL


/* Options RCC_PLL_IN_HSI_DIV_2 
           RCC_PLL_IN_HSE_CRYSTAL_DIV_2 
		   RCC_PLL_IN_HSE_CRYSTAL       */
		   
/*Note Select value if only you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT    RCC_PLL_IN_HSE_CRYSTAL_DIV_2
#endif
/*first method */
/* Options : choose number of multiplication you want to multiply input clock source of PLL 
            2 to 16 */
/*Note Select value if only you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
/*First method*/
#define RCC_PLL_MUL_VAL  4

/*Second method*/
/* Options : PLL_INPUT_CLOCK_MUL_2 
             PLL_INPUT_CLOCK_MUL_3
			 PLL_INPUT_CLOCK_MUL_4
			 PLL_INPUT_CLOCK_MUL_5
			 PLL_INPUT_CLOCK_MUL_6 
			 PLL_INPUT_CLOCK_MUL_7 
			 PLL_INPUT_CLOCK_MUL_8 
			 PLL_INPUT_CLOCK_MUL_9 
			 PLL_INPUT_CLOCK_MUL_10 
			 PLL_INPUT_CLOCK_MUL_11
			 PLL_INPUT_CLOCK_MUL_12
			 PLL_INPUT_CLOCK_MUL_13
			 PLL_INPUT_CLOCK_MUL_14
			 PLL_INPUT_CLOCK_MUL_15
			 PLL_INPUT_CLOCK_MUL_16 */
/*Note Select value if only you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
/*Second method*/
#define PLL_INPUT_CLOCK_MUL   PLL_INPUT_CLOCK_MUL_2

  




#endif


#endif