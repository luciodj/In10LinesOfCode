/**
    Button Debouncing using CIPs

    File Name:
      main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.20
*/

#include "mcc_generated_files/mcc.h"

#define PRESSED     0

void main(void)
{
    SYSTEM_Initialize();

    while (1)
    {
        // while (BTN_GetValue() != PRESSED); 
        // while (BTN_GetValue() == PRESSED); 
        // LED0_Toggle();
    }
}
