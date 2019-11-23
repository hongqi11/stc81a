#ifndef IO_H
#define IO_H
/*
(P2.0  P2.1) (P2.2  P2.3)
 P2.4  P2.5  (P0.0  P0.1) 
(P0.2  P0.3) (P1.4  P1.5)
(P1.6  P1.7)  P2.6  P2.7  
(P3.2  P3.3)  P3.4  P3.5  
(P3.6  P3.7) (P4.3  P4.2) 
 P4.1

*/
#include "SYSTEM.H"

#define V1_MCU1 P20			//CH1
#define V1_MCU3 P21
#define V2_MCU1 P22
#define V2_MCU3 P23

#define S_MCU1  P24			//CH2

#define EL_MCU1 P25			//CH3

#define PM1_V_MCU1 P00		//CH4
#define PM1_V_MCU2 P01
#define PM1_C_MCU1 P02
#define PM1_C_MCU3 P03

#define P1_V1_MCU1 P14		//CH5
#define P1_V1_MCU3 P15
#define P2_V2_MCU1 P16
#define P2_V2_MCU3 P17

#define M1_P_MCU1 P26		//CH6
#define M2_P_MCU1 P27
#define CM_MCU1 P32
#define CM_MCU3 P33
#define R_MCU1 P34
#define R_MCU2 P35
#define VM_MCU1 P36
#define VM_MCU2 P37

#define P_MCU1 P43			//CH7
#define TH_MCU1 P42
#define R_D_MCU P41
 
#define UP 	 1
#define DOWN 0 
 
 
#endif