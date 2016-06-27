/**
    8 x Servo demo
    (uses 5 CCP modules, 2 PWM modules and builds one more using the CIPs) 

    File Name:
        main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.30
*/

#include "mcc_generated_files/mcc.h"

void main(void)
{
    uint8_t i, duty[8];
    
    SYSTEM_Initialize();

    while (1)
    {
        if (getch() != '\02')   // start of text  
            continue;
        for (i=0; i<8; i++) 
            duty[i] = getch();
            // values from 32 to 156 correspond to 0 to 180deg
        
        if (getch() == '\03') {   // end of text 
            putch('\06');   // ack
            PWM1_DutyValueSet(duty[0]<<2); PWM2_DutyValueSet(duty[1]<<2);
            PWM3_DutyValueSet(duty[2]<<2); PWM4_DutyValueSet(duty[3]<<2);
            PWM5_DutyValueSet(duty[4]<<2); PWM6_LoadDutyValue(duty[5]<<2);
            PWM7_LoadDutyValue(duty[6]<<2); TMR4_LoadPeriodRegister(duty[7]);
        } 
    }
}

