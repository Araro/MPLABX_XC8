#include <xc.h>
#include "config.h"
void interrupt compara(){
    TMR1=0;
    CCP2IF=0;
}
void main(void) {
    //*****oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
    //******Puertos
    TRISC=0;
    PORTC=0;
    
    //Interrupciones
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;  //Habiliación interrupción por periférico
    PIR2bits.CCP2IF=0;  //se limpia la bandera de CCP2
    PIE2bits.CCP2IE=1;  //Se habilita interrupción por CCP2
    //Configuración Timer1
    T1CONbits.TMR1CS=0b00;  //Fosc/4
    T1CONbits.T1CKPS=0b11;  //1:8
    //1 Tick=1us
    TMR1=0;                 //inicializa conteo
    //******Configuración CCP2
    CCP2CONbits.CCP2M=0b0010;       //modo comparación toogle                    					        //output
    //*************************
    CCPR2=20000;                    //20000 ticks= 20ms
    //
    T1CONbits.TMR1ON=1;     //Timer 1 ON
    *************************************************************
    while(1);
    
    return;
}
