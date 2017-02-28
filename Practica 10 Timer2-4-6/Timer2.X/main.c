#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000


void interrupt isr(){
    LATA0=LATA0+1;
    PIR1bits.TMR2IF=0;
}
void main(void) {
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0;

    TRISA=0;
    PORTA=0;
    ANSELA=0;

    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    PIR1bits.TMR2IF=0;
    PIE1bits.TMR2IE=1;
  

    T2CONbits.T2CKPS=0b11;
    T2CONbits.T2OUTPS=9;
    TMR2=0;
    PR2=125;

    T2CONbits.TMR2ON=1;

    while(1);
    return;
}
