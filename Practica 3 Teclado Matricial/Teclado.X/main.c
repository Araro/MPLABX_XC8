#include <xc.h>
#include <stdio.h>
#define _XTAL_FREQ 32000000
#include "flex_lcd.h"
#include "config.h"

int main(void)
{
unsigned char i, j;
char x;
unsigned char buffer1[20];

  OSCCONbits.SPLLEN=1;        //configuración del Oscilador
  OSCCONbits.IRCF=0b1110;     //configuración del Oscilador
  OSCCONbits.SCS=0b00;        //configuración del Oscilador
  //*****************************************************

ANSELA=0;       //seleccionamos los puertos como digitales
ANSELB=0;
ANSELE=0;
ANSELD=0;
TRISA=0;
TRISB=0;
TRISD=0;
TRISE=0;
Lcd_Init();     //inicializamos el lcd
Lcd_Cmd(LCD_CLEAR);		//limpiamos lcd
Lcd_Cmd(LCD_CURSOR_OFF);	//apagamos el cursor
__delay_ms(100);		//esperamos 100ms


//ciclo infinito
while(1){
    PORTA=1;
    switch (PORTB){
        case 1:
            x=55;
            break;
        case 2:
            x=56;
            break;
        case 4:
            x=57;
            break;
        case 8:
            x=47;
            break;
       }
    PORTA=2;
    switch (PORTB){
        case 1:
            x=52;
            break;
        case 2:
            x=53;
            break;
        case 4:
            x=54;
            break;
        case 8:
            x=120;
            break;
       }
    PORTA=4;
    switch (PORTB){
        case 1:
            x=49;
            break;
        case 2:
            x=50;
            break;
        case 4:
            x=51;
            break;
        case 8:
            x=45;
            break;
       }
    PORTA=8;
    switch (PORTB){
        case 1:
            x=49;
            break;
        case 2:
            x=48;
            break;
        case 4:
            x=61;
            break;
        case 8:
            x=43;
            break;
       }
    sprintf(buffer1,"Tecla %c",x);   //guardamos en el string Buffer1 la palabra Cuenta espacio y el valor de i
    Lcd_Out2(1, 1, buffer1);            //escribimos en el renglon uno espaco 1 la que contiene buffer1
    __delay_ms(300);

}
return 0;
} //fin
