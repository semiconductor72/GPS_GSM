#include "GSM.h"
#include "UART2.h"


void USART2_IRQHandler()
	{

		
		/*Need to read Rx data to clear receive inturrupt*/
			//uart2_Rx(Data_to_rec);
				get_gsm_string();
		
			//uart2_Tx(Data_to_rec);
	
	}
	

