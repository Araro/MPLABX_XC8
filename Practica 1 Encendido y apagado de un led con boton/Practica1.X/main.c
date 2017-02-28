#include <xc.h>
#define _XTAL_FREQ 32000000

// CONFIG1
#pragma config FOSC = INTOSC        // Oscillator Selection (HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config VCAPEN = OFF     // Voltage Regulator Capacitor Enable (All VCAP pin functionality is disabled)
#pragma config PLLEN = ON      // PLL Enable (4x PLL disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)



void main(void) {
    OSCCONbits.SPLLEN=1;        //configuración del Oscilador
     OSCCONbits.SCS=0b00;        //configuración del Oscilador
    OSCCONbits.IRCF=0b1110;     //configuración del Oscilador
   
    OSCTUNEbits.TUN=0b000000;

    //*****************************************************
    PORTB=0;                    //se limpia puerto B
    PORTA=0;                    //se limpia puerto A
    //****************************************************+
    ANSELA=0;       //Puerto A como digital
    ANSELB=0;       //Puerto B como digital
    //*****************************************
    TRISB=0;        //Puerto B como salidas
    TRISA=255;      //Puerto A como entradas

    while(1){
        if(RA0==1){
             RB7=RB7+1;
            __delay_ms(500);
        }
        
    }

    return;
}
