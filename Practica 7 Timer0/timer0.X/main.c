#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
//variable global
int x=0;
//función de interrupción
void interrupt isr(){
    x++;
    if(x==100){        //Si temporización es 1s
    LATA0=LATA0+1;      //Toogle RA0
    x=0;}
    TMR0=131;           //Cargamos Timer
    INTCONbits.TMR0IF=0;//Limpiamos bandera de interrupción
}


void main(void) {
    //Configuración de oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
//COnfiguración de puertos
    TRISA=0;
    PORTA=0;
//***************configuración de interrupción
    INTCONbits.GIE=1;
    INTCONbits.TMR0IE=1;
    INTCONbits.TMR0IF=0;
//configuración de TIMER0
    OPTION_REGbits.TMR0CS=0; //como temporizador
    OPTION_REGbits.T0SE=0;   //selección del flanco
    OPTION_REGbits.PSA=0;    //asignación de divisor
    OPTION_REGbits.PS=0b101; //1:64
//Carga para Temporización
    TMR0=131;
    while(1);
    return;
}
