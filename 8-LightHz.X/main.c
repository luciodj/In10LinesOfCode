/**
    Light Hz Click sensor demo
    (measuring a frequency)
    
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
    while (1)
    {
        if (PIR8bits.SMT1PWAIF) {
            printf("counted %ld pulses\n", SMT1_GetCapturedPulseWidth());
            SMT1_ManualTimerReset();
            PIR8bits.SMT1PWAIF = 0;
        }
    }
}
