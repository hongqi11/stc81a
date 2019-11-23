#include "SYSTEM.H"
#include "rs232.h"
#include "io.h"
#include "app.h"

ERRORSTATUS g_USART_Flag = ERROR;

u8 Host_data[data_length]={0};

void main(){
	struct mainboxstruct mainbox;     
    struct mainboxstruct mainboxNew;
	enum UpNum UpData = Nothing;	
	IO_Init();  // IO 初始化
	MainBoxInit(&mainboxNew,&mainbox);
	UartInit(); // enable interrupt
	while(1){
		if(g_USART_Flag == SUCCESS){
			SPAnalysis(Host_data,&mainboxNew,&UpData);   // update newmainbox
			MainBoxComparison(&mainboxNew,&mainbox,&UpData);		//断开目标定时器
			delay2ms();
			mainbox = mainboxNew;		//数据写入寄存器
			MainBoxAssignment(&mainbox,&UpData);		//数据写入继电器
			delay5ms();
			g_USART_Flag = ERROR;   //清除标志位
		}
	}
}
