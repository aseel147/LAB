#ifndef DEF
#define DEFINITIONS
#include <stdint.h>

// Definitions:
//RCC:
# define RCC_BaseAdd 		0x40021000;
# define RCC_APB2RSTR		0x4002100C;		//APB2 peripheral reset register;
# define RCC_APB2ENR		0x40021018;  	//APB2 peripheral clock enable register;
//GPIO_C:
# define GPIO_C_BaseAdd 0x40011000;
# define GPIO_C_CRH 		0x40011004;		//Port configuration register high; Reset value: 0x4444 4444;
# define GPIO_C_ODR			0x4001100C;		//Port output data register
# define GPIO_C_BSRR		0x40011010;		//Port bit set/reset register
# define GPIO_C_BRR			0x40011014;		//Port bit reset register
//GPIO_B:
# define GPIO_B_BaseAdd 0x40010C00;
# define GPIO_B_CRL 		0x40010C00;		//Port configuration register low;
//USART:
# define USART_BaseAdd  0x40013800;	
# define USART_DR  			0x40013800;		//Data register [8:0]
# define USART_SR  			0x40013804;		//tells us if data entered to USART_DR
# define USART_BRR  		0x40013808;		//Baud rate register
# define USART_CR1  		0x4001380C;		//Control register 1
//AFIO:
# define AFIO_BaseAdd  0x40010000;	
# define AFIO_MAPR		  0x40010004;		//MAP USART to GPIO B IO.


#endif
//END

