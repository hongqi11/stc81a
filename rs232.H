#ifndef RS232_H
#define RS232_H

#include "SYSTEM.H"
#include "app.h"

#define FOSC            24000000UL
#define BRT             (65536 - FOSC / 115200 / 4)

typedef enum
{
	ERROR = 0,
	SUCCESS,
	
}ERRORSTATUS;

extern ERRORSTATUS g_USART_Flag;

#define data_length 8
extern u8 Host_data[data_length];

void UartInit();
void SPAnalysis(u8 *p_data,struct mainboxstruct *p_box,enum UpNum *p_status);
void Uart2Send(char * dat);

#endif

