/**
    PING ))) demo using CIPs
    (measuring distance with an ultrasonic sensor)

    File Name:
        main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.20
*/

#include "mcc_generated_files/mcc.h"

void main(void)
{
    SYSTEM_Initialize();
    T1G_SetHigh();                              // prepare LAT high
    
    while (1)
    {
        T1G_SetDigitalOutput();                 // send a short pulse
        __delay_us(5);
        T1G_SetDigitalInput();                  // return to input
        
        TMR1GIF = 0;                            
        TMR1_WriteTimer(0);                     // clear count
        TMR1_StartSinglePulseAcquisition();
        while (!TMR1GIF);                       // wait for echo pulse
        
//        printf("Distance = %.2f cm\n", TMR1_ReadTimer()*(300.0/37000));
        printf("Distance = %.2f in\n", TMR1_ReadTimer()*(118.1/37000));
        __delay_ms(250);
    }
}
