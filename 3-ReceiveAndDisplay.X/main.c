/**
    Serial Port Echo and display demo

    File Name:
        main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.30
*/

#include "mcc_generated_files/mcc.h"

void main(void)
{
    SYSTEM_Initialize();

    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    puts("Receive and Display");
    while (1)
    {
        char c = getch();   // wait for a new character
        putch(c);           // echo it back
        LATA = c;           // publish to LEDs
    }
}
