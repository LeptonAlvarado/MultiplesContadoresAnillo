#include<18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT, INTRC_IO
#fuses NOPBADEN, /*NOMCLR,*/ STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

int count = 0;
int count2= 0;
int count3= 0;
int count4= 0;
#int_timer0

void timer0()
{
    count++;
    count2++;
    count3++;
    count4++;
    set_timer0(15536);
}
 
void main ()
{
    //setup_oscillator(OSC_16MHZ);
    setup_timer_0(rtcc_internal|rtcc_div_8);
    set_timer0(15536);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);
    set_tris_a(0x00); 
    set_tris_b(0x00);
    set_tris_c(0x00); //Se inicializa el puerto 0 es de salida y 1 de entrada
    set_tris_d(0x00);
    int ledsA = 1, ledsB =128, ledsC = 1, ledsD = 128;
    while(TRUE)
    {
       if(count==1){
           output_b(ledsB);
           ledsB /= 2;
           if(ledsB == 1)
              ledsB=128;
           count = 0;
       }
       if(count3 == 5){
           output_a(ledsA);
           ledsA *=2;
           if(ledsA == 256)
               ledsA = 1;
           count3=0;
       }
       if(count2 == 7){
           output_c(ledsC);
           ledsC *=2;
           count2 = 0;
           if(ledsC==256)
               ledsC = 1;
       }        
       if(count4 == 10){
           output_d(ledsD);
           ledsD /=2;
           if(ledsD == 1)
               ledsD = 128;
           count4 = 0;
       }     
    }
}
