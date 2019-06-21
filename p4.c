#include<18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)
int contadorB = 0; 
int contadorC = 0;
int contadorA = 0;
int contadorD = 0;
#int_timer0
void timer0(){
   contadorB++, contadorC++, contadorA++, contadorD++;
   set_timer0(15536);
}
void main(){
   setup_timer_0(T0_INTERNAL|rtcc_div_8);
   set_timer0(15536);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   enable_interrupts(NO_ANALOGS);
   set_tris_a(0x00);
   set_tris_b(0x00);
   set_tris_c(0x00);
   set_tris_d(0x00);
   int A = 1, B = 128, C = 1, D = 128;
   while(TRUE){
      if(contadorB == 1){
         output_b(B);
         B= B/2;
         if(B==0){
            B=128;
         }
         contadorB=0;
      }
      if(contadorA ==5){
         output_a(A);
         A= A*2;
         if(A ==64){
            A=1;
         }
         contadorA=0;
      }
      if(contadorC == 7){
         output_c(C);
         C= C*2;
         if(C==256){
            C=1;
         }
         contadorC=0;
      }
      if(contadorD ==10){
         output_d(D);
         D= D/2;
         if(D==0){
            D=128;
         }
         contadorD=0;
      }
   }
}


