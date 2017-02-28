#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void interrupt isr(){
    if(IOCBFbits.IOCBF0)
        LATAbits.LATA0=LATA0+1;
    if(IOCBFbits.IOCBF4)
        LATA1=LATA1+1;
    __delay_ms(300);
    IOCBF=0;
    INTCONbits.IOCIF=0;
}

void main(void) {
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;

    TRISA=0;
    ANSELA=0;
    ANSELB=0;
    TRISB=255;
    PORTA=0;

    OPTION_REGbits.nWPUEN=0;
    WPUB=255;
    WPUBbits.WPUB0=1;
    WPUBbits.WPUB4=1;

    INTCONbits.GIE=1;
    INTCONbits.IOCIF=0;
    INTCONbits.IOCIE=1;

    IOCBNbits.IOCBN0=1;
    //IOCBPbits.IOCBP0=1;
    IOCBPbits.IOCBP4=1;

    IOCBF=0;

    while(1);
    return;
}
