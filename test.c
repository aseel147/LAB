// test file
//to p.50-51
# define BaseAddres 0x40000000;
# define AFIO (BaseAddres+10000) ;
# define RCC (BaseAddres+0X21000) ;
# define GPIO (BaseAddres+11000) ;
# define USART (BaseAddres+138000) ;
//manual 7.2
typedef struct{
  uint32_t RCC_CR;//0x00 control register
  uint32_t RCC_CFGR;//0x04 Clock configuration register
  uint32_t RCC_CIR;//0x08 Clock interrupt register 
  uint32_t RCC_APB2RSTR;//0x0C APB2 peripheral reset register 
  uint32_t RCC_ABPB1RSTR;//0x10 APB1 peripheral reset register
  uint32_t RCC_AHBENR;//0x14 AHB peripheral clock enable register
  uint32_t  RCC_APB2ENR;//0x18 APB2 peripheral clock enable register 
  uint32_t RCC_APB1ENR;//0x1C  APB1 peripheral clock enable register 
  uint32_t RCC_BDCR;//0x20  Backup domain control register 
  uint32_t RCC_CSR;//0x24 Control/status register
}RCC_S;
//MANUAL9.4 P.183-..
typedef struct{
  uint32_t AFIO_EVCR ;//Event control register 0X00
  uint32_t  AFIO_MAPR;  //AF remap and debug I/O configuration register 0X04
  uint32_t   AFIO_EXTICR1 ;//External interrupt configuration register1 0X08
  uint32_t    AFIO_EXTICR2;//External interrupt configuration register 2 0X0C
  uint32_t    AFIO_EXTICR3; //External interrupt configuration register 3 0X10
  uint32_t AFIO_EXTICR4;//External interrupt configuration register 4 0x14
  uint32_t AFIO_MAPR2; //AF remap and debug I/O configuration register2 0X1C
}AFIO_S;//***********
typdef struct{
//manual 9.2
uint32_t PIOx_CRL; //0x00 Port configuration register low
uint32_t GPIOx_CRH; //0x04 Port configuration register high
uint32_t GPIOx_IDR; //0x08Port input data register 
uint32_t GPIOx_ODR; //0x0cPort output data register 
uint32_t GPIOx_BSRR; //0x10ort bit set/reset register
uint32_t GPIOx_BRR; //0x14 Port bit reset register
uint32_t GPIOx_LCKR; //0x18Port configuration lock register 
}GPIO_S;
//manual 27.6.1
typdef struct{
//manual 9.2
uint32_t USART_SR; //0x00 Status register
uint32_t USART_DR; //0x04 Data register 
uint32_t USART_BRR; //0x08 Baud rate register
uint32_t USART_CR1; //0x0c Control register 1
uint32_t  USART_CR2; //0x10 Control register 2
uint32_t USART_CR3; //0x14 Control register 3
uint32_t USART_GTPR ; //0x18 Guard time and prescaler register
}USART_S;
 






