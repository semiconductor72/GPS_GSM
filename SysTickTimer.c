#include "SysTickTimer.h"
#include "stm32f10x.h"

void SysTick_init(void)
	{
		SysTick->CTRL = 0x00;
		SysTick->LOAD = 0x00FFFFFF;
		SysTick->VAL = 0;
		
		SysTick->CTRL = 0x04;
		
		
	}	
	
void ms_delay(void)
	{
		SysTick->LOAD = 72000 - 1;
		SysTick->VAL = 0;
		SysTick->CTRL |= 0x01;
		while(!(SysTick->CTRL & (1<<16)));	
	}	
	
	
void s_delay(uint16_t m_sec)
	{
		while(m_sec)
			{
				ms_delay();
				m_sec--;
			}
		
	}
	
/// Random time delay Function	
void delay(volatile int rep)
	{
		for(;rep>0;rep--)
		{
		//int i;
			for (volatile int i = 0; i < rep; i++);
		}
	}
