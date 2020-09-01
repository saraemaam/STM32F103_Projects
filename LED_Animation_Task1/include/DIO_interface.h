/************************************************************************/
/* Author : Sarah Abuzaid                                               */
/* Version: V01                                                         */
/* Date   : 13 Aug 2020                                                  */
/************************************************************************/
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7
#define PIN8  8
#define PIN9  9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

#define HIGH  1
#define LOW   0

#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

/*INPUT MODE */
#define INPUT_ANALOG       0b0000
#define INPUT_FLOATING     0b0100
#define INPUT_PULL_UP_DOWN 0b1000 

/*OUTPUT MODE SPEED 10 MHZ */
#define OUTPUT_SPEED_10_MHZ_PP     0b0001
#define OUTPUT_SPEED_10_MHZ_OD     0b0101
#define OUTPUT_SPEED_10_MHZ_AF_PP  0b1001
#define OUTPUT_SPEED_10_MHZ_AF_OD  0b1101

/*OUTPUT MODE SPEED 2MHZ */
#define OUTPUT_SPEED_2_MHZ_PP     0b0010
#define OUTPUT_SPEED_2_MHZ_OD     0b0110
#define OUTPUT_SPEED_2_MHZ_AF_PP  0b1010
#define OUTPUT_SPEED_2_MHZ_AF_OD  0b1110

/*OUTPUT MODE SPEED 50MHZ */
#define OUTPUT_SPEED_50_MHZ_PP     0b0011
#define OUTPUT_SPEED_50_MHZ_OD     0b0111
#define OUTPUT_SPEED_50_MHZ_AF_PP  0b1011
#define OUTPUT_SPEED_50_MHZ_AF_OD  0b1111

void MGPIO_voidSetPinDir (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode ) ; 
void MGPIO_voidSetPinVal (u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value ) ;
u8   MGPIO_voidGetPinVal (u8 copy_u8Port , u8 copy_u8Pin);