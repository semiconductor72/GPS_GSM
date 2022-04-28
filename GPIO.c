#include "GPIO.h"
#include "stm32f10x.h"

	
	/*
	
//GPIO PORT A.0 clock enable, confuguration as Alternating function "Interrupt"
void Interrupt_config(void)
	{
		AFIO->EXTICR[0] &= ~(uint32_t)(0x0000000F);//select port A.0 as external interrupt pin
		EXTI->IMR |= 0x01;//Disable Interrupt mask
		EXTI->RTSR |= 0x01;//rising edge selected for port A
		NVIC_SetPriority(EXTI0_IRQn,1);//Inturrupt priority
		NVIC_EnableIRQ(EXTI0_IRQn);//Enable Inturrupt
	
//		RCC->APB2ENR |= 0x10; /// Or  0b10000 --> Anabling Preiph GPIOC
//		GPIOC->CRH &= 0xFF0FFFFF;  /// Reset the PORT C PIN 13
//		GPIOC->CRH |= 0x00300000;  /// Set Port C PIN 13 as Output 
	}
*/

	
//GPIO PORT C.13 clock enable, port direction ouitput and confuguration as IO PUSH PULL
void GPIO_config_c(void)
	{
		RCC->APB2ENR |= 0x10; /// Or  0b10000 --> Anabling Preiph clock GPIOC
		GPIOC->CRH &= 0xFF0FFFFF;  /// Reset the PORT C PIN 13
		GPIOC->CRH |= 0x00300000;  /// Set Port C PIN 13 as Output 
	}

//GPIO PORT B.0 clock enable, port direction INPUT and confuguration as IO PUSH PULL
void GPIO_config_b(void)
	{
		RCC->APB2ENR |= (1<<3);   //clock enabled for port
		GPIOB->CRL &= 0xFFFFFFF0;  /// Reset the PORT C PIN 13
		GPIOB->CRL |= 0x00000008;  /// Set Port C PIN 13 as Output 
	}	
