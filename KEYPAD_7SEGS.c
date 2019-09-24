//KEYBAD+7SEG
#include<16f877.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=4M)
#use rs232(baud=9600, xmit=PIN_c6,rcv=PIN_c7)
//*******************************************************************
int16 number = 3333; //GLOBALS so interrupts talk to each other
int tim=0;
int8 d0,d1,d2,d3; 

#INT_TIMER0
void display()
{
	set_timer0(100); //you must set it after every rest
	
	d0=number%10;
	number/=10;
	d1=number%10;
	number/=10;
	d2=number%10;
	number/=10;
	d3=number%10;
	
   
   /*output_high (PIN_c0);
   OUTPUT_D (d3);
   delay_ms (1);
   output_low (PIN_c0);

   output_high (PIN_c1);
   OUTPUT_D (d2);
   delay_ms (1);
   output_low (PIN_c1);

   output_high (PIN_c2);
   OUTPUT_D (d1);
   delay_ms (1);
   output_low (PIN_c2);*/

   output_high (PIN_c3);
   OUTPUT_D (d0);
   delay_ms (1);
   output_low (PIN_c3);
}
//**************************************************************
//get the time from the PC if tim=1 means  the digit will be shifted each 10ms.
//if tim=2 means  the digit will be shifted each 20ms and so on.



//**************************************************************
void main()
{
    enable_interrupts(INT_TIMER0); 
    enable_interrupts(GLOBAL);    
    setup_timer_0(RTCC_INTERNAL |RTCC_DIV_256);
    set_timer0(100);
   

    port_b_pullups(true);
    set_tris_b(0b11110000); //b7b6b5b4-b3b2b1b0
    Set_tris_d (0x00);
    Set_tris_c (0x00);
   
    while(1)
    {
      output_low(PIN_B0);
      output_high(PIN_B1);
      output_high(PIN_B2);
      output_high(PIN_B3);

      if(input(PIN_B4)==false)
      {number = 1;
      while(input(PIN_B4)==false);}
      if(input(PIN_B5)==false)
      {number = 2;
      while(input(PIN_B5)==false);}
      if(input(PIN_B6)==false)
      {number = 3;
      while(input(PIN_B6)==false);}
      if(input(PIN_B7)==false)
      {number = 4;
      while(input(PIN_B7)==false);}

      delay_ms(10);
         
      output_high(PIN_B0);
      output_low(PIN_B1);
      output_high(PIN_B2);
      output_high(PIN_B3);

      if(input(PIN_B4)==false)
      {number = 5;
      while(input(PIN_B4)==false);}
      if(input(PIN_B5)==false)
      {number = 6;
      while(input(PIN_B5)==false);}
      if(input(PIN_B6)==false)
      {number = 7;
      while(input(PIN_B6)==false);}
      if(input(PIN_B7)==false)
      {number = 8;
      while(input(PIN_B7)==false);}

      delay_ms(10);

      output_high(PIN_B0);
      output_high(PIN_B1);
      output_low(PIN_B2);
      output_high(PIN_B3);

      if(input(PIN_B4)==false)
      {number = 9;
      while(input(PIN_B4)==false);}
      if(input(PIN_B5)==false)
      {number = 10;
      while(input(PIN_B5)==false);}
      if(input(PIN_B6)==false)
      {number = 11;
      while(input(PIN_B6)==false);}
      if(input(PIN_B7)==false)
      {number = 12;
      while(input(PIN_B7)==false);}

      delay_ms(10);
      output_high(PIN_B0);
      output_high(PIN_B1);
      output_high(PIN_B2);
      output_low(PIN_B3);

      if(input(PIN_B4)==false)
      {number = 13;
      while(input(PIN_B4)==false);};
      if(input(PIN_B5)==false)
      {number = 14;
      while(input(PIN_B5)==false);};
      if(input(PIN_B6)==false)
      {number = 15;
      while(input(PIN_B6)==false);};
      if(input(PIN_B7)==false)
      {number = 16;
      while(input(PIN_B7)==false);};
      delay_ms(10);
   }
}
