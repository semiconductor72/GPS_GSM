#include "GSM.h"
#include "UART2.h"


char rec_data,*Data_to_rec;
char GGA_Pointers[20];
char GGA_data[3];
char GGA_Buffer[100];
char Latitude_Buffer[15];
char Longitude_Buffer[15];
char degrees_buffer[12];
char degree_lattitude[12];
char degree_longitude[12];
int GGA_Index = 0;
int CommaCounter = 0;
int IsItGGAString = 0;

void get_gsm_string(void)
//void USART2_IRQHandler()
	{
		//*Data_to_rec = '0';
		
		
		uart2_Rx(Data_to_rec);
		//Data_to_rec ++;
		//uart2_Tx(Data_to_rec);
		
		if(*Data_to_rec == '$')
			{
				GGA_Index = 0;
				CommaCounter = 0;
				IsItGGAString = 0;

			}
			
			else if(IsItGGAString)
				{
					if(*Data_to_rec == ',')
						{
							GGA_Pointers[CommaCounter ++] = GGA_Index;
						}
						GGA_Buffer[GGA_Index ++] = *Data_to_rec;
						
				}
			
			else if(GGA_data[2] == 'G' && GGA_data[1] == 'G' && GGA_data[0] == 'A')
				{
					
						IsItGGAString = 1;
						GGA_data[0]=0;
						GGA_data[1]=0;
						GGA_data[2]=0;
					
				}
		
			else
				{
					GGA_data[2] = GGA_data[1];
					GGA_data[1] = GGA_data[0];
					GGA_data[0] = *Data_to_rec;
			
		}
	}












int get_latitude(uint16_t lat_pointer){
	//cli();
//	__disable_irq();
	uint8_t lat_index;
	uint8_t index = lat_pointer+1;
	if(GGA_Buffer[index] == ',')
		{
			return 1;
		}
	lat_index=0;
	
	/* parse Latitude in GGA string stored in buffer */
	for(;GGA_Buffer[index]!=',';index++){
		Latitude_Buffer[lat_index]= GGA_Buffer[index];
		lat_index++;
	}
	
	//Latitude_Buffer[lat_index++] = GGA_Buffer[index++];
	//Latitude_Buffer[lat_index]   = GGA_Buffer[index];  /* get direction */
	convert_to_degrees(Latitude_Buffer);
	strcpy(degree_lattitude,degrees_buffer);
	//strcpy(degree_lattitude,"\0");
	//sei();
	//__enable_irq();
	return 0;
}

int get_longitude(uint16_t long_pointer){
	//cli();
	//__disable_irq();	
	uint8_t long_index;
	uint8_t index = long_pointer+1;
		if(GGA_Buffer[index] == ',')
		{
			return 1;
		}
	long_index=0;
	
	/* parse Longitude in GGA string stored in buffer */
	for( ; GGA_Buffer[index]!=','; index++){
		Longitude_Buffer[long_index]= GGA_Buffer[index];
		long_index++;
	}
	
	//Longitude_Buffer[long_index++] = GGA_Buffer[index++];
	//Longitude_Buffer[long_index]   = GGA_Buffer[index]; /* get direction */
	convert_to_degrees(Longitude_Buffer);
	strcpy(degree_longitude,degrees_buffer);
	//sei();
	//__enable_irq();
	return 0;
}



void convert_to_degrees(char *raw){
	
	double value;
	float decimal_value,temp;
	
	int32_t degrees;
	
	float position;
	value = atof(raw);    /* convert string into float for conversion */
	
	/* convert raw latitude/longitude into degree format */
	decimal_value = (value/100);
	degrees       = (int)(decimal_value);
	temp          = (decimal_value - (int)decimal_value)/0.6; 
	position      = (float)degrees + temp;
	
	/* convert float value into string */
	sprintf(degrees_buffer, "%f", position);
  	
}