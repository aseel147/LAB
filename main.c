#include "defines.h"
#include <stdint.h>

//MAIN:
int main(void)
{
	//Variables declare:
	uint32_t* address_RCC_APB2ENR=	(uint32_t*)RCC_APB2ENR;
	uint32_t* address_GPIO_C_CRH=		(uint32_t*)GPIO_C_CRH;
	uint32_t* address_GPIO_C_BRR=		(uint32_t*)GPIO_C_BRR;
	uint32_t* address_GPIO_C_BSRR=	(uint32_t*)GPIO_C_BSRR;
	uint32_t* address_GPIO_B_CRL=		(uint32_t*)GPIO_B_CRL;
	uint32_t* address_USART_CR1=		(uint32_t*)USART_CR1;
	uint32_t* address_USART_BRR=		(uint32_t*)USART_BRR;
	uint32_t* address_USART_DR=			(uint32_t*)USART_DR;
	uint32_t* address_USART_SR=			(uint32_t*)USART_SR;
	uint32_t* address_AFIO_MAPR=		(uint32_t*)AFIO_MAPR;
	//define HELP variables:
	char send_one=0;									//set manually!!!!!
	char send_zero='0';							//set manually!!!!!
	uint32_t dataIO;
		
	//Frist configurations:
	//CLOCK Enables:
	*address_RCC_APB2ENR=0x00004019;	//USART1EN=1,IOPCEN=1,IOPBEN=1,AFIOEN=1;
	//port C enable:
	*address_GPIO_C_CRH=0x44544444;		//MODE13=01 to turn led on;
	//USART set:
	*address_USART_CR1=0x0000200C;		//UE=1,RE=1,TE=1;
	*address_USART_BRR=0x00000341;		//fraction=x1, mantissa=x0034;
	*address_USART_SR|=0x000001C0;
	//AFIO set:
	*address_AFIO_MAPR=0x00000004;		//USART1_REMAP=1;
	//port B set:
	*address_GPIO_B_CRL=0x49000000;		//CNF7=01,MODE7=00,CNF6=10,MODE6=01;
	
	/////////////////////////////////////////////////////////////////////////
	
	//infinite while loop:
	while(1){	
		//check if recieve data in USART SR RXNE bit == 1:
		if(*address_USART_SR&0x20)
		{
			//if recieve, check DR and SET dataIO to 1 or 0:
			//if DR=='1':
			if(*address_USART_DR=='1')
			{
			dataIO=1;
			}
			//if DR=='0':
			if(*address_USART_DR=='0')
			{
			dataIO=0;
			}
			//CHECK dataIO:
			if(dataIO==1){
				//TURN LIGHT ON:
				*address_GPIO_C_BRR=0x2000;
			}
			else if(dataIO==0){
				//TURN LIGHT OFF:
				*address_GPIO_C_BSRR=0x2000;
			}
			//reset USART SR RXNE bit5 to 0 (because we recieved data):
			*address_USART_SR^=0x00000020;				//XOR from 1 to 0
		}
		//if data was not recived- check what to send:
		if(send_one=='1')
		{
			//put in DR the value of '1':
			*address_USART_DR=0x0110001;
			//wait to end of Tx:
			while (!(*address_USART_SR&0x00000080));
			//set to polling:
			send_one=0;
		}
		else if(send_zero=='0')
		{
			//put in DR the value of '0':
			*address_USART_DR=0x0110000;
			//wait to end of Tx:
			while (!(*address_USART_SR&0x00000080));
			//set to polling:
			send_zero=0;
		}
	}
}

		
	
