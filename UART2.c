#include "UART2.h"
#include "stm32f10x.h"

void uart2_init(void)
	{
		__disable_irq();
		/*dont know why ARM have not given AF(alternative function clock) register
		for APB1 bus, to enable UART2 clock which is from APB1 bus we need to 
		enable the alternative function clock from APB2 bus*/
		RCC->APB2ENR |= 1;
		
		/*enabling The UART2 peripheral under APB1 bus*/		
		RCC->APB1ENR |= (1<<17);
		
		/*enable port A clock*/
		RCC->APB2ENR |= (1<<2);
		
		/*from GPIOA configuration of port pins A2 and A3 for Tx and Rx of UART2 
			respectivly, confughuring Tx pin as output 50MHz with alternatiung function
			with push pull and Rx pin as input with pull up/down*/
		GPIOA->CRL = 0x00000000;	//found that already garbedge vaslues thats why reset
		GPIOA->CRL |= 0x00000A00; //1011 0000 0000
		GPIOA->CRL |= 0x00008000;
		
		/*Baud rate 9600 bps*/
		USART2->BRR = 0x00000EA6;




		USART2->CR1 = 0x0000;
		
						/*Enable UART Rx Interrupt*/
		USART2->CR1 |= (1<<5);
		NVIC_EnableIRQ(USART2_IRQn);
		__enable_irq();
		
		
		/*Enable Tx from USART2*/
		USART2->CR1 |= (1<<3);
		
		/*Enable Rx from USART2*/
		USART2->CR1 |= (1<<2);		

		/*Enable USART2 */
		USART2->CR1 |= (1<<13);
		

		
	}
	
void uart2_Tx(char *Data_to_send)
	{
			// Transmit Char
			//for(i=0;(*Data_to_send+i)!='\0';i++)
				while((*Data_to_send != '\0'))
				{
					while((uint16_t)(USART2->SR & (1<<7)) != 0x80);
					USART2->DR = *Data_to_send;
					Data_to_send++;
				}
	}

void uart2_Rx(char *Data_to_rec)
	{		
		volatile char *temp;
		//temp = Data_to_rec;
		//do{	
				while((USART2->SR & 0x20) == 0x00);
				*Data_to_rec = USART2->DR;
		//		Data_to_rec++;
		//	} while((*(Data_to_rec)) != '\0');
		//Data_to_rec = temp;
	}	
