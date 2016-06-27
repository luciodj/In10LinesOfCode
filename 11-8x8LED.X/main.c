/**
    8x8-LED Click display demo 
    (using SPI module)

    File Name:
        main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.20
*/

#include "mcc_generated_files/mcc.h"
#include "led8x8.h"

uint8_t m[8];


void main(void) 
{
    SYSTEM_Initialize(); 
    
    puts("8x8R Click Demo");
    
    LED8x8_Initialize(0);
    LED8x8_HorMessage( m, (void*)"Hello World");

// simple diagonal pattern
//    uint8_t reg;
//    for(reg=0; reg<8; reg++)
//        LED8x8_Write(reg+1, 1<<reg);
    
    while (1) {
        char c = getch();       // get char from serial port
        putch(c);               // echo
        LATA = c & 0xf;         // show 4 lsb on the LEDs
        LED8x8_Putch(&m, c);    // convert to matrix
        LED8x8_Display(&m);     // updated display
    }
}
