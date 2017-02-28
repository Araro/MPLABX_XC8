#include <xc.h>
#define _XTAL_FREQ 32000000
#include "config.h"

//****************Función de interrupción
void interrupt isr(){
    LATAbits.LATA0=LATAbits.LATA0+1;   //Toogle bit en RA0
    __delay_ms(300);
    INTCONbits.INTF=0;  //Limpiamos flag de interrupción por INT
}

void main(void) {
    //*********configuración del oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0;
    //*********confoguración de puertos
    TRISA=0;
    TRISB=255;
    PORTA=0;
    PORTB=0;
    //*********Configuración de PULL-UP
    OPTION_REGbits.nWPUEN=0;  //Habilitación general
    WPUBbits.WPUB0=1;   //Pull-up en RB0
    //*********Configuración de interrupción
    INTCONbits.GIE=1; //se habilita interrupción global
    INTCONbits.INTF=0;//Se limpia la bandera de
    //interrupción externa
    INTCONbits.INTE=1;//Se habilita interrupción
    //externa
    OPTION_REGbits.INTEDG=1;// flanco de bajada
    //*********************************************
    while(1);
    return;
}
