#include "rs232.h"
#include "app.h"
#include "stdio.h"
void UartInit(void)		//115200bps@24MHz 
{
  S2CON = 0x10;     
  T2L  = BRT;
  T2H  = BRT >> 8;
  AUXR = 0x14;
  IE2  = 0x01;
  EA   = 1;
}

void SPAnalysis(u8 *p_data,struct mainboxstruct *p_box,enum UpNum *p_status )
{
	switch(p_data[3]) //relay number
	{
		case  1: if(p_data[4]) {	p_box->VoltageA.Voltage1		= PON;		}else{	p_box->VoltageA.Voltage1		    = CLOSE; }  *p_status= VolA_Volt1;	  break;
		case  2: if(p_data[4]) {	p_box->VoltageA.Voltage1		= NON;		}else{	p_box->VoltageA.Voltage1			= CLOSE; }  *p_status= VolA_Volt1;	  break;
		case  3: if(p_data[4]) {	p_box->VoltageA.Voltage2 		= PON;		}else{	p_box->VoltageA.Voltage2 			= CLOSE; }  *p_status= VolA_Volt2;	  break;
		case  4: if(p_data[4]) {	p_box->VoltageA.Voltage2 		= NON;		}else{	p_box->VoltageA.Voltage2 			= CLOSE; }  *p_status= VolA_Volt2;	  break;
		case  5: if(p_data[4]) {	p_box->ImpedanceB 			    = ON; 		}else{	p_box->ImpedanceB 					= OFF;	 }  *p_status= ImpedB;		  break;
	    case  6: if(p_data[4]) {	p_box->LoadC					= ON; 		}else{	p_box->LoadC						= OFF;   }  *p_status= LoaC;	      break;
		case  7: if(p_data[4]) {	p_box->MultimeterD.Multimeter1  = PON;		}else{	p_box->MultimeterD.Multimeter1   	= CLOSE; }  *p_status= MulD_Mul1; 	  break;
		case  8: if(p_data[4]) {	p_box->MultimeterD.Multimeter1  = NON;		}else{	p_box->MultimeterD.Multimeter1   	= CLOSE; }  *p_status= MulD_Mul1; 	  break;
		case  9: if(p_data[4]) {	p_box->MultimeterD.Multimeter2  = PON;		}else{	p_box->MultimeterD.Multimeter2  	= CLOSE; }  *p_status= MulD_Mul2; 	  break;
		case 10: if(p_data[4]) {	p_box->MultimeterD.Multimeter2  = NON;		}else{	p_box->MultimeterD.Multimeter2      = CLOSE; }  *p_status= MulD_Mul2; 	  break;
		case 11: if(p_data[4]) {	p_box->VoltageE.Voltage1        = PON;		}else{	p_box->VoltageE.Voltage1          	= CLOSE; }  *p_status= VolE_Volt1;	  break;
		case 12: if(p_data[4]) {	p_box->VoltageE.Voltage1        = NON;		}else{	p_box->VoltageE.Voltage1         	= CLOSE; }  *p_status= VolE_Volt1;	  break;
		case 13: if(p_data[4]) {	p_box->VoltageE.Voltage2        = PON;		}else{	p_box->VoltageE.Voltage2          	= CLOSE; }  *p_status= VolE_Volt2;	  break;
		case 14: if(p_data[4]) {	p_box->VoltageE.Voltage2        = NON;		}else{	p_box->VoltageE.Voltage2         	= CLOSE; }  *p_status= VolE_Volt2;	  break;
		case 15: if(p_data[4]) {	p_box->BOXF.M1_PASS			    = ON; 		}else{	p_box->BOXF.M1_PASS			    	= OFF; 	 }  *p_status= BOXF_M1_PASS;  break;
		case 16: if(p_data[4]) {	p_box->BOXF.M2_PASS				= ON; 		}else{	p_box->BOXF.M2_PASS					= OFF; 	 }  *p_status= BOXF_M2_PASS;  break;
		case 17: if(p_data[4]) {	p_box->BOXF.CM_VX				= PON;		}else{	p_box->BOXF.CM_VX				    = CLOSE; }  *p_status= BOXF_CM_VX;    break;
		case 18: if(p_data[4]) {	p_box->BOXF.CM_VX				= NON;		}else{	p_box->BOXF.CM_VX				    = CLOSE; }  *p_status= BOXF_CM_VX;    break;
		case 19: if(p_data[4]) {	p_box->BOXF.R1					= ON; 		}else{	p_box->BOXF.R1						= OFF; 	 }  *p_status= BOXF_R1;		  break;
		case 20: if(p_data[4]) {	p_box->BOXF.R2					= ON; 		}else{	p_box->BOXF.R2						= OFF;   }  *p_status= BOXF_R2;		  break;
		case 21: if(p_data[4]) {	p_box->BOXF.VM_JE				= PON;		}else{	p_box->BOXF.VM_JE				    = CLOSE; }  *p_status= BOXF_VM_JE;	  break;
		case 22: if(p_data[4]) {	p_box->BOXF.VM_JE				= NON;		}else{	p_box->BOXF.VM_JE				   	= CLOSE; }  *p_status= BOXF_VM_JE;    break;
		case 23: if(p_data[4]) {	p_box->BOXG.IM_VTH				= PON;		}else{	p_box->BOXG.IM_VTH					= CLOSE; }  *p_status= BOXG_IM_VTH;   break;
		case 24: if(p_data[4]) {	p_box->BOXG.IM_VTH				= NON;		}else{	p_box->BOXG.IM_VTH					= CLOSE; }  *p_status= BOXG_IM_VTH;   break;
		case 25: if(p_data[4]) {	p_box->BOXG.ResD				= ON; 		}else{	p_box->BOXG.ResD					= OFF; 	 }  *p_status= BOXG_ResD;     break;   
	}                                                                                     	                                      
	
}

bit busy;
void Uart2Isr() interrupt 8
{
	static u8 num = 0;
    if (S2CON & 0x01)
    {
		if(g_USART_Flag==ERROR)
		{					
			Host_data[num++] = S2BUF; 		//先接收
			if(Host_data[0] == 0X01)
			{
				if(num >= data_length)
			    {
					num = 0;
					//SPAnalysis();
					g_USART_Flag = SUCCESS;
				}			
			}
			else
			{
				num=0;
			}				
			
        }
		S2CON &= ~0x01;
	}
	
	if (S2CON & 0x02)
	{
		S2CON &= ~0x02;
		busy = 0;
	}		
}

void Uart2Send(char * dat)
{
    while(busy);
    busy = 1;
    S2BUF = *dat;
}
	
char putchar (char c)
{
	Uart2Send(&c);
    return c;
}
