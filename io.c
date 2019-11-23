#include "io.h"

void IO_Init(){

P0M1 &= 0xF0;			//�������P00~P03
P0M0 |= 0x0F;	
P1M0 &= 0x0F;			//�������P14~P17
P1M1 |= 0xf0;		  
P2M0  = 0xFF;		  //�������P2���ж˿�
P2M1  = 0x00;
P3M1 &= 0x07;			//�������P32~P37
P3M0 |= 0xF8;			
P4M1 &= 0x0E;			//�������P41~P43
P4M0 |= 0xF1;			

		
P0 |= 0x0F;				//���ߵ�λ ��ʼ��
P1 |= 0xF0;	
P2  = 0xFF;		
P3 |= 0xFC;
P4 |= 0x0E;	
}





