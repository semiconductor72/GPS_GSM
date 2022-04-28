#include "LOG.h"
#include "UART2.h"



void LOG_ERR(char *data)
	{
		uart2_Tx(ANSI_RED);
		uart2_Tx("\r\n");
		uart2_Tx(data);
		uart2_Tx(ANSI_RESET);
	}
	
void LOG_WRN(char *data)
	{
		uart2_Tx(ANSI_YELLOW);
		uart2_Tx("\r\n");
		uart2_Tx(data);
		uart2_Tx(ANSI_RESET);
	}	
	
void LOG_DBG(char *data)
	{
		uart2_Tx(ANSI_CYAN);
		uart2_Tx("\r\n");
		uart2_Tx(data);
		uart2_Tx(ANSI_RESET);
	}
	
void LOG_INFO(char *data)
	{
		//uart2_Tx(ANSI_YELLOW);
		uart2_Tx("\r\n");
		uart2_Tx(data);
		uart2_Tx(ANSI_RESET);
	}