#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    int x;
    //configuración oscilador 32MHz
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
    //Puertos
    TRISC=255;
    PORTC=0;
    //CCP1CON
    CCP1CONbits.CCP1M=0b1100;   //Modo PWM
    CCP1CONbits.P1M=0b00;       //Salida Simple
    //PR2       //Frecuencia de PWM=1.95KHz
    PR2=255;
    //Timer2
    T2CONbits.T2CKPS=0b10;  //Divisor 1:16
    T2CONbits.T2OUTPS=0b0000;   //Postscaler 1:1
    T2CONbits.TMR2ON=1;         //Timer 2 ON
    //************************* Ciclo de trabajo 50%
    //CCPR1L=0b10000000;
    //CCP1CONbits.DC1B=0b00;
    CCPR1L=1023>>2;
    CCP1CONbits.DC1B=1023;
    //*********Selección de recurso para PWM
    CCPTMRS0bits.C1TSEL=0b00;   //Timer2------>CCP1
    //*********************
    TRISC=0;
    //***********************
    while(1){
        for(x=0;x<1024;x++){
        CCPR1L=x>>2;
        CCP1CONbits.DC1B=x;
        __delay_ms(100);
        }
    }
    return;
}
