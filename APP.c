#include "stm32f10x.h"
#include "SysTickTimer.h"
#include "UART2.h"
#include "GPIO.h"
#include "LOG.h"	
#include "GSM.h"



void Interrupt_config(void);
char def_link[]="https://maps.google.com/?q=";
char link[100]="";

int main(void)
	{
		int ret0,ret1;
		Data_to_rec = &rec_data;
		//GPIO_config_c();
		SysTick_init();
		uart2_init();
		s_delay(1000);
		while(1)
			{
				/*Enable Intterupt*/
				__enable_irq();
				
				s_delay(2000);

				/*Disable Intterupt*/
				__disable_irq();
				ret0 = get_latitude(GGA_Pointers[0]);
				ret1 = get_longitude(GGA_Pointers[2]);				
				if(ret0 | ret1)
					{
						LOG_DBG("Signal Not Found");
						LOG_WRN("Warning");

						
						
					}
				//get_longitude(GGA_Pointers[2]);
					else{
						uart2_Tx("\r\n");
						strcat(link,def_link);
						//degree_lattitude[9] = '\0';
						//strcat(link,"123456789");
						strcat(link,degree_lattitude);
						strcat(link,",");
						//strcat(link,"0000 0000");
						strcat(link,degree_longitude);
					//	strcat(link,"\0");
//						uart2_Tx("\r\n");
//						uart2_Tx(degree_lattitude);
//						uart2_Tx("    ");
//						uart2_Tx(degree_longitude);
							uart2_Tx(link);
							memset(link,'\0', strlen(link));

						
					}

			}
	}


