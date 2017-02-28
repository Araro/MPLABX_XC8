#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
//variable global
int x=0;
//funci�n de interrupci�n
void interrupt isr(){
    x++;
    if(x==100){        //Si temporizaci�n es 1s
    LATA0=LATA0+1;      //Toogle RA0
    x=0;}
    TMR0=131;           //Cargamos Timer
    INTCONbits.TMR0IF=0;//Limpiamos bandera de interrupci�n
}


void main(void) {
    //Configuraci�n de oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
//COnfiguraci�n de puertos
    TRISA=0;
    PORTA=0;
//***************configuraci�n de interrupci�n
    INTCONbits.GIE=1;
    INTCONbits.TMR0IE=1;
    INTCONbits.TMR0IF=0;
//configuraci�n de TIMER0
    OPTION_REGbits.TMR0CS=0; //como temporizador
    OPTION_REGbits.T0SE=0;   //selecci�n del flanco
    OPTION_REGbits.PSA=0;    //asignaci�n de divisor
    OPTION_REGbits.PS=0b101; //1:64
//Carga para Temporizaci�n
    TMR0=131;
    while(1);
    return;
}
