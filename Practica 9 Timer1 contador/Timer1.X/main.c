#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
    //*******************
    TRISC=255;
    TRISA=0;
    PORTA=0;
    ANSELA=0;
    //****************
    T1CONbits.TMR1CS=0b10;//eventos externos
    T1CONbits.T1OSCEN=0;  //deshabilitar oscilador LP
    T1CONbits.T1CKPS=0b10;//divisor
    
    T1GCONbits.TMR1GE=0;
    //*****************
	while(PORTCbits.RC0);
    T1CONbits.TMR1ON=1;
    TMR1H=0;              //Inicializa cuenta
    TMR1L=0;              //Inicializa cuenta
    T1CONbits.nT1SYNC=1;  //¿Sincronizar?
    //T1CONbits.TMR1ON=0;
    while(1){
        PORTA=TMR1L;
        __delay_ms(500);
        }
    return;
}
