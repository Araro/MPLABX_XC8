#include <xc.h>
#define _XTAL_FREQ 32000000
#include "config.h"

//****************Funci�n de interrupci�n
void interrupt isr(){
    LATAbits.LATA0=LATAbits.LATA0+1;   //Toogle bit en RA0
    __delay_ms(300);
    INTCONbits.INTF=0;  //Limpiamos flag de interrupci�n por INT
}

void main(void) {
    //*********configuraci�n del oscilador
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0;
    //*********confoguraci�n de puertos
    TRISA=0;
    TRISB=255;
    PORTA=0;
    PORTB=0;
    //*********Configuraci�n de PULL-UP
    OPTION_REGbits.nWPUEN=0;  //Habilitaci�n general
    WPUBbits.WPUB0=1;   //Pull-up en RB0
    //*********Configuraci�n de interrupci�n
    INTCONbits.GIE=1; //se habilita interrupci�n global
    INTCONbits.INTF=0;//Se limpia la bandera de
    //interrupci�n externa
    INTCONbits.INTE=1;//Se habilita interrupci�n
    //externa
    OPTION_REGbits.INTEDG=1;// flanco de bajada
    //*********************************************
    while(1);
    return;
}
