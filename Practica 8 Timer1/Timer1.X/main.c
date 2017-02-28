#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000


void interrupt isr(){
        LATA0=LATA0+1;//toggle RA0
    TMR1H=0b00010101;   //se carga 5536 en TMR1
    TMR1L=0b10100000;
    
    PIR1bits.TMR1IF=0;//Se limpia la bandera
}

void main(void) {
    //Oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
    //******configuración del puerto
    TRISA=0;
    PORTA=0;
    //Interrupción
    PIE1bits.TMR1IE=1;//habilitación interrupción Timer1
    PIR1bits.TMR1IF=0;//Se limpia bandera de interrupción
    INTCONbits.GIE=1;//habilitación global
    INTCONbits.PEIE=1;//habilitación por periférico
    //configuración Timer1
    T1CONbits.T1CKPS=0b10;//divisor 4
    T1CONbits.TMR1CS=0b00;//Fosc/4
    T1CONbits.T1OSCEN=0;//Oscilador LP deshabilitado
    T1CONbits.nT1SYNC=1;//Sin sincronizar
    T1CONbits.TMR1ON=1;//Prende Timer1

    TMR1H=0b00010101;//se carga 5536 a TMR1
    TMR1L=0b10100000;
    while(1);
    return;
}
