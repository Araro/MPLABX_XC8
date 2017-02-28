#include <xc.h>

#define _XTAL_FREQ 32000000
#include "flex_lcd.h"
#include <stdio.h>
#include "config.h"
int main(void)
{
unsigned char i, j;
unsigned char buffer1[20];

  OSCCONbits.SPLLEN=1;        //configuración del Oscilador
  OSCCONbits.IRCF=0b1110;     //configuración del Oscilador
  OSCCONbits.SCS=0b00;        //configuración del Oscilador
  //*****************************************************

ANSELA=0;       //seleccionamos los puertos como digitales
ANSELB=0;
ANSELE=0;
ANSELD=0;

Lcd_Init();     //inicializamos el lcd
Lcd_Cmd(LCD_CLEAR);		//limpiamos lcd
Lcd_Cmd(LCD_CURSOR_OFF);	//apagamos el cursor
__delay_ms(100);		//esperamos 100ms

for(i=10; i>0; i--)
{

sprintf(buffer1,"Cuenta %03d",i);   //guardamos en el string Buffer1 la palabra Cuenta espacio y el valor de i
Lcd_Out2(1, 1, buffer1);            //escribimos en el renglon uno espaco 1 la que contiene buffer1
__delay_ms(100);	//esperamos 100ms y repetimos
}
Lcd_Out(2, 1, "Mecatronica");	//escribimos en la linea 2 espacio 1 la palabra mkmekatronika
__delay_ms(600);		//esperamos 600ms
Lcd_Cmd(LCD_BLINK_CURSOR_ON);   //hacemos que parpade el cursor
__delay_ms(1000);		//Esperamos 1s
Lcd_Cmd(LCD_UNDERLINE_ON);	//subraya el cursor
__delay_ms(1000);		//esperamos 1s
Lcd_Cmd(LCD_CURSOR_OFF);	//apagamos el cursor
__delay_ms(1000);
Lcd_Cmd(LCD_CLEAR);		//limpiamos el cursor
Lcd_Out(1, 4, "Gracias");	//imprimimos gracias
Lcd_Out(2, 4, "Thank u");	//imprimims thank u

while(1); //se queda ciclado sin hacer nada
return 0;
} //fin
