#include "APP.h"
#include "io.h"
#include "intrins.h"



void MainBoxInit(struct mainboxstruct  *p_newbox, struct mainboxstruct  *p_box)
{
    p_box->VoltageA.Voltage1           = CLOSE;
    p_box->VoltageA.Voltage2           = CLOSE;
    p_box->ImpedanceB                  = OFF;
    p_box->LoadC                       = OFF;
    p_box->MultimeterD.Multimeter1     = CLOSE;
    p_box->MultimeterD.Multimeter2     = CLOSE;
    p_box->VoltageE.Voltage1           = CLOSE;
    p_box->VoltageE.Voltage2           = CLOSE;
    p_box->BOXF.M1_PASS                = OFF;
    p_box->BOXF.M2_PASS                = OFF;
    p_box->BOXF.CM_VX                  = CLOSE;    
    p_box->BOXF.R1                     = OFF;
    p_box->BOXF.R2                     = OFF;
    p_box->BOXF.VM_JE                  = CLOSE;
    p_box->BOXG.IM_VTH                 = CLOSE;
    p_box->BOXG.ResD                   = OFF;
	*p_newbox = *p_box;
}



void MainBoxAssignment(struct mainboxstruct  *p_box,enum UpNum *p_status)    
{
	switch(*p_status){
        case VolA_Volt1:
        {  
            if((p_box->VoltageA.Voltage1 == PON)  && (V1_MCU3 == UP) && (V1_MCU1 == UP) )       //P21-P20
                {V1_MCU3 = DOWN; V1_MCU1 = UP;}
            else if( (p_box->VoltageA.Voltage1 == NON) &&(V1_MCU3 == UP)  && (V1_MCU1 == UP) )
                {V1_MCU3 = UP; V1_MCU1 = DOWN;}
            else if(p_box->VoltageA.Voltage1 == CLOSE)
                {V1_MCU3 = UP; V1_MCU1 = UP;}
            else { _nop_();}            
            break;
        }
        case VolA_Volt2:   
        {
            if((p_box->VoltageA.Voltage2 == PON)       &&(V2_MCU3 == UP)  && (V2_MCU1 == UP))       //P23-P22
                {V2_MCU3 = DOWN;V2_MCU1 = UP;}
            else if((p_box->VoltageA.Voltage2 == NON)  && (V2_MCU3 == UP) && (V2_MCU1 == UP))
                {V2_MCU3 = UP;V2_MCU1 = DOWN;}
            else  if(p_box->VoltageA.Voltage2 == CLOSE)
                {V2_MCU3 = UP;V2_MCU1 = UP;}
             else { _nop_();}  
            break;
        }
        case ImpedB:
        {
            if((p_box->ImpedanceB == ON) && (S_MCU1 == UP))               //P24
                {S_MCU1 = DOWN;}
            else if(p_box->ImpedanceB == OFF)
                {S_MCU1 = UP;}
            else { _nop_();}  
            break;
        }
        case LoaC:
        {
            if((p_box->LoadC == ON)  && (EL_MCU1 == UP) )                    //P25
                {EL_MCU1 = DOWN;}
            else if(p_box->LoadC==OFF)
                {EL_MCU1 = UP;}
            else { _nop_();}  
            break; 
        }
        case MulD_Mul1:
        {
            if((p_box->MultimeterD.Multimeter1 == PON) && (PM1_V_MCU2 == UP) && (PM1_V_MCU1 == UP))  //P01-P00
                {PM1_V_MCU2 = DOWN; PM1_V_MCU1 = UP;}
            else if((p_box->MultimeterD.Multimeter1 == NON) && (PM1_V_MCU2 == UP) && (PM1_V_MCU1 == UP))
                {PM1_V_MCU2 = UP; PM1_V_MCU1 = DOWN;}
            else if(p_box->MultimeterD.Multimeter1 == CLOSE)
                {PM1_V_MCU2 = UP; PM1_V_MCU1 = UP;}
            else { _nop_();}  
            break;
        }

        case MulD_Mul2: 
         {   if((p_box->MultimeterD.Multimeter2 == PON) && (PM1_C_MCU3 == UP) && (PM1_C_MCU1 == UP))  //P03-P02
                {PM1_C_MCU3 = DOWN; PM1_C_MCU1 = UP;}
            else if((p_box->MultimeterD.Multimeter2 == NON) && (PM1_C_MCU3 == UP) && (PM1_C_MCU1 == UP))
                {PM1_C_MCU3 = UP; PM1_C_MCU1 = DOWN;}
            else if(p_box->MultimeterD.Multimeter2 == CLOSE)
                {PM1_C_MCU3 = UP; PM1_C_MCU1 = UP;}
            else { _nop_();}  
            break;
         }

        case VolE_Volt1: 
        {
            if((p_box->VoltageE.Voltage1 == PON) && (P1_V1_MCU3 == UP) && (P1_V1_MCU1 == UP))        //P15-P14
                {P1_V1_MCU3 = DOWN; P1_V1_MCU1 = UP;}
            else if(p_box->VoltageE.Voltage1 == NON)
                {P1_V1_MCU3 = UP; P1_V1_MCU1 = DOWN;}
            else if (p_box->VoltageE.Voltage1 == CLOSE)                
                {P1_V1_MCU3 = UP; P1_V1_MCU1 = UP;}
            else { _nop_();}  
            break;
        }
        case VolE_Volt2:  
        {
            if((p_box->VoltageE.Voltage2 == PON) && (P2_V2_MCU3 == UP) && (P2_V2_MCU1 == UP))        //P17-P16
                {P2_V2_MCU3 = DOWN; P2_V2_MCU1 = UP;}
            else if((p_box->VoltageE.Voltage2 == NON) && (P2_V2_MCU3 == UP) && (P2_V2_MCU1 == UP))
                {P2_V2_MCU3 = UP; P2_V2_MCU1 = DOWN;}
            else if(p_box->VoltageE.Voltage2 == CLOSE)
                {P2_V2_MCU3 = UP; P2_V2_MCU1 = UP;} 
            else { _nop_();}  
            break;
        } 

        case BOXF_M1_PASS:
         {
            if((p_box->BOXF.M1_PASS == ON) && (M1_P_MCU1 == UP))               //P26
                {M1_P_MCU1 = DOWN;}
            else if(p_box->BOXF.M1_PASS == OFF)
                {M1_P_MCU1 = UP;}   
            else { _nop_();}  
            break;
         } 
        case BOXF_M2_PASS:
        {
            if((p_box->BOXF.M2_PASS == ON) && (M2_P_MCU1 == UP))            //P27
                {M2_P_MCU1 = DOWN;}
            else if(p_box->BOXF.M2_PASS == OFF) 
                {M2_P_MCU1 = UP;}
            else { _nop_();}  
            break;
        }
        case BOXF_CM_VX: 
        {
            if((p_box->BOXF.CM_VX == PON) && (CM_MCU3 == UP) && (CM_MCU1 == UP))             //P33-P32
                {CM_MCU3 = DOWN; CM_MCU1 = UP;}
            else if((p_box->BOXF.CM_VX == NON) && (CM_MCU3 == UP) && (CM_MCU1 == UP))
                {CM_MCU3 = UP; CM_MCU1 = DOWN;}
            else if (p_box->BOXF.CM_VX == CLOSE)
                   {CM_MCU3 = UP; CM_MCU1 = UP;}   
            else { _nop_();}  
            break;
        }
        case BOXF_R1: 				
         {   if((p_box->BOXF.R1 == ON) && (R_MCU1 == UP))                   //P34
                {R_MCU1 = DOWN;}
            else if(p_box->BOXF.R1 == OFF)
                {R_MCU1 = UP;}
            else { _nop_();}  
            break;
         }
        case BOXF_R2:
         {   if((p_box->BOXF.R2 == ON) && (R_MCU2 = UP))                  //P35
                {R_MCU2 = DOWN;}
            else if(p_box->BOXF.R2 == OFF)
                {R_MCU2 = UP;}  
            else { _nop_();}  
            break;
         } 
         case BOXF_VM_JE: 
         { 
            if((p_box->BOXF.VM_JE == PON) && (VM_MCU2 == UP)&& (VM_MCU1 == UP))               //P37-P36
                {VM_MCU2 = DOWN; VM_MCU1 = UP;}
            else if((p_box->BOXF.VM_JE == NON) && (VM_MCU2 == UP)&& (VM_MCU1 == UP))
                {VM_MCU2 = UP; VM_MCU1 = DOWN;}
            else if(p_box->BOXF.VM_JE ==CLOSE)
                {VM_MCU2 = UP; VM_MCU1 = UP;}
            else { _nop_();}  
            break;
         }
        case BOXG_IM_VTH:
         {
            if((p_box->BOXG.IM_VTH == PON) && (P_MCU1 == UP) && (TH_MCU1 == UP))             //P43-P42
                {P_MCU1 = DOWN; TH_MCU1 = UP;}
            else if((p_box->BOXG.IM_VTH == NON) && (P_MCU1 == UP) && (TH_MCU1 == UP))
                {P_MCU1 = UP; TH_MCU1 = DOWN;}
            else if(p_box->BOXG.IM_VTH == CLOSE)
                {P_MCU1 = UP; TH_MCU1 = UP;}
            else { _nop_();}  
            break;
         }
         case BOXG_ResD:  
         {
            if((p_box->BOXG.ResD == ON) && (R_D_MCU == UP))                 //P41
                {R_D_MCU = DOWN;}
            else if(p_box->BOXG.ResD == CLOSE)
                {R_D_MCU = UP;}
            else { _nop_();}  
            break;
         }
         default:
            break;
    }
}



void MainBoxComparison(struct mainboxstruct *p_newbox,struct mainboxstruct  *p_box,enum UpNum *p_status){
	switch(*p_status){  
		case VolA_Volt1: 	if(p_newbox->VoltageA.Voltage1       != p_box->VoltageA.Voltage1)
							{p_box->VoltageA.Voltage1         = CLOSE;}              break;
		case VolA_Volt2: 	if(p_newbox->VoltageA.Voltage2       != p_box->VoltageA.Voltage2)
								{p_box->VoltageA.Voltage2         = CLOSE;}			  break;
		case ImpedB:	 	if(p_newbox->ImpedanceB              != p_box->ImpedanceB)
								{p_box->ImpedanceB                = OFF;} 				  break;
		case LoaC:  	 	if(p_newbox->LoadC                   != p_box->LoadC)
								{p_box->LoadC                     = OFF;}				  break;
		case MulD_Mul1:  	if(p_newbox->MultimeterD.Multimeter1 != p_box->MultimeterD.Multimeter1)
								{p_box->MultimeterD.Multimeter1   = CLOSE;}		      break;
		case MulD_Mul2: 	if(p_newbox->MultimeterD.Multimeter2 != p_box->MultimeterD.Multimeter2)
								{p_box->MultimeterD.Multimeter2   = CLOSE;}			  break;
		case VolE_Volt1: 	if(p_newbox->VoltageE.Voltage1       != p_box->VoltageE.Voltage1)
								{p_box->VoltageE.Voltage1         = CLOSE;} 			  break;	
		case VolE_Volt2:    if(p_newbox->VoltageE.Voltage2       != p_box->VoltageE.Voltage2)
								{p_box->VoltageE.Voltage2         = CLOSE;}			  break;
		case BOXF_M1_PASS:  if(p_newbox->BOXF.M1_PASS            != p_box->BOXF.M1_PASS)
								{p_box->BOXF.M1_PASS              = OFF;}				  break;
		case BOXF_M2_PASS:  if(p_newbox->BOXF.M2_PASS            != p_box->BOXF.M2_PASS)
								{p_box->BOXF.M2_PASS              = OFF;}				  break;
		case BOXF_CM_VX:    if(p_newbox->BOXF.CM_VX              != p_box->BOXF.CM_VX)
                                {p_box->BOXF.CM_VX                = CLOSE;}   			  break;
		case BOXF_R1:       if(p_newbox->BOXF.R1                 != p_box->BOXF.R1)
								{p_box->BOXF.R1                   = OFF;}				  break;
		case BOXF_R2:		if(p_newbox->BOXF.R2                 != p_box->BOXF.R2)
								{p_box->BOXF.R2                   = OFF;}				  break;
		case BOXF_VM_JE:    if(p_newbox->BOXF.VM_JE              != p_box->BOXF.VM_JE)
								{p_box->BOXF.VM_JE                = CLOSE;}			  break;
		case BOXG_IM_VTH:	if(p_newbox->BOXG.IM_VTH             != p_box->BOXG.IM_VTH)   
								{p_box->BOXG.IM_VTH               = CLOSE;}			  break;
		case BOXG_ResD:     if(p_newbox->BOXG.ResD               != p_box->BOXG.ResD) 
								{p_box->BOXG.ResD                 = OFF;}				  break;
		default:   ; 
        MainBoxAssignment(p_box,p_status);
    }
}

