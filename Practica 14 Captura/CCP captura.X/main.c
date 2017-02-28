#include <xc.h>
#include <stdio.h>
#include "config.h"
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"
//variable global
float tiempo;

void interrupt isr(){
    int ticks;
    ticks=CCPR1;    //Lee la captura
    tiempo=ticks*0.000001;  //convierte a tiempo la captura
    TMR1=0;         //Reinicia el timer1
    PIR1bits.CCP1IF=0;  //Limpia bandera de interrupción por CCP1
    
}


void main(void) {
    unsigned char buffer1[16];
    //Oscilador
    OSCCONbits.IRCF=0b1110; //8MHz
    OSCCONbits.SCS=0b00;    //Config1
    //Puertos
    TRISA=0;    //Puerto A como salida
    TRISC=255;  //Puerto C como entrada
    PORTA=0;    //Limpia puerto A
    ANSELA=0;   //Puerto A como digital
    ANSELB=0;   //Puerto B como digital
    //Interrupciones
    INTCONbits.GIE=1;   //Hablititar la interrupción global
    INTCONbits.PEIE=1;  //Habilitar interrupción por periférico
    PIR1bits.CCP1IF=0;  //Limpia bandera interrupcion CCP1
    PIE1bits.CCP1IE=1;  //Habilita interrupión por CCP1
    //Configuración Timer1
    T1CONbits.TMR1CS=0b00;  //Fosc/4
    T1CONbits.T1CKPS=0b11;  //1:8
    T1CONbits.nT1SYNC=1;    //Sin sincronia
    TMR1=0;
    //Configurar CCP1
    CCP1CONbits.CCP1M=0b0100;   //Captura cada flanco de bajada
    //*******LCD
    T1CONbits.TMR1ON=1; //se enciende el Timer1
    Lcd_Init();     //inicializamos el lcd
    Lcd_Cmd(LCD_CLEAR);		//limpiamos lcd
    Lcd_Cmd(LCD_CURSOR_OFF);	//apagamos el cursor
   //*********************************************
    while(1){
    sprintf(buffer1,"Tiempo %f",tiempo); 
    Lcd_Out2(1, 1, buffer1);           
    __delay_ms(500);
    }

    return;
}