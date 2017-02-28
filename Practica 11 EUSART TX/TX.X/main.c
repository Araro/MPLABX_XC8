#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    char x=65;
    //Oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
    //Puerto
    TRISC=0b10000000;
    PORTC=0;
    //////Configuración Puerto Serie
    TXSTAbits.SYNC=0; //Transmisión Asíncrona
    TXSTAbits.TXEN=1; //Habilitación transmisión
    RCSTAbits.SPEN=1; //Habilita puerto serie
    //*****************Baud Rate
    BAUDCONbits.BRG16=0; //8 bits
    TXSTAbits.BRGH=0;    //Baja velocidad
    SPBRGH=0;            // Baud Rate 9600
    SPBRGL=51;
    SPBRG=51;
    //****************************************+

    while(1){
        for(x=65;x<=90;x++){
            TXREG=x;
            while(TXSTAbits.TRMT==0);
        __delay_ms(500);
        }

    }
    return;
}
