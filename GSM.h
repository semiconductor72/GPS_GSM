#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
extern char rec_data,*Data_to_rec;

extern int GGA_Index;
extern int CommaCounter;
extern int IsItGGAString;
extern char GGA_Pointers[20];
extern char GGA_data[3];
extern char GGA_Buffer[100];
extern char Latitude_Buffer[15];
extern char Longitude_Buffer[15];
extern char degrees_buffer[12];
extern char degree_lattitude[12];
extern char degree_longitude[12];

int get_latitude(uint16_t lat_pointer);
int get_longitude(uint16_t long_pointer);
void get_gsm_string(void);

void convert_to_degrees(char *raw);

