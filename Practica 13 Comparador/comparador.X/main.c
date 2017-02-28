#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    //oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
    //*******puerto
    TRISA=0b11101111;
    PORTA=0;
    ANSELA=0;
    //******CM1CON0
    CM1CON0bits.C1ON=1; //habilita C1
    CM1CON0bits.C1OE=1; //habilita salida fisica
    CM1CON0bits.C1POL=0;//Salida invertida
    CM1CON0bits.C1OUT=0;//canal pos menor al neg
    CM1CON0bits.C1SP=1; //modo normal
    CM1CON0bits.C1HYS=0;//Sin hysteresis
    CM1CON0bits.C1SYNC=0;//Sin sincronizar
    //******CM1CON1
    CM1CON1bits.C1PCH=0b00; //C1IN+
    CM1CON1bits.C1NCH=0b00; //C12IN0-
    //*****************
    
    while(1);
    return;
}
