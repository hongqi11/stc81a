#include "system.h"
#include "intrins.h"


void delay5ms()			//约
{		
   u8 i,j;
   _nop_();
   _nop_();
   i=156;
   j=213;
   do
   {
      
       while (--j);  /* code */ 
       
   } while (--i);
   
}

void delay2ms()			//约
{		
   u8 i,j;
   _nop_();
   _nop_();
   i=85;
   j=213;
   do
   {
      
       while (--j);  /* code */ 
       
   } while (--i);
   
}