/*
 * File:   main.c
 *
 * "Created in MPLAB Xpress"
 */


#include "mcc_generated_files/mcc.h"

void main(void) 
{
    SYSTEM_Initialize();
    
    while(1)
    {
        LED0_Toggle();
        __delay_ms(250);
    }
}
