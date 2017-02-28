#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000


void interrupt isr(){
    char x;
    x=RCREG;        //dato recibido
    if(x==65)       //Si es A
        LATA0=LATA0+1;
    PIR1bits.RCIF=0;
}

void main(void) {
    //OScilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
     //Puerto
    TRISA=0;
    PORTA=0;
    ANSELA=0;
    TRISC=0b10000000;
    PORTC=0;
    //*******interrupción
    INTCONbits.GIE=1;       //Interrupción global
    INTCONbits.PEIE=1;      //Interrupción por periférico
    PIR1bits.RCIF=0;        //Limpiamos bandera
    PIE1bits.RCIE=1;        //Habilitamos interrupción
    //********recepción
    RCSTAbits.SPEN=1;   //habilita puerto serie
    RCSTAbits.CREN=1;   //habilita recepción
    TXSTAbits.SYNC=0;   //asincrono
    //*****************Baud Rate
    BAUDCONbits.BRG16=0; //8 bits
    TXSTAbits.BRGH=0;    //Baja velocidad
    SPBRG=51;            // Baud Rate 9600
    //****************************************+
    while(1);
    return;
}
