/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC16F18855
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#include <xc.h>
#include "pin_manager.h"
#include <stdbool.h>

void PIN_MANAGER_Initialize(void)
{
    LATB = 0x0;
    WPUE = 0x8;
    LATA = 0x0;
    LATC = 0x1;
    WPUA = 0xFF;
    WPUB = 0xE1;
    WPUC = 0x18;
    ANSELA = 0x7F;
    ANSELB = 0x7F;
    ANSELC = 0xF5;
    TRISB = 0xE1;
    TRISC = 0x5A;
    TRISA = 0xFF;

    


    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    T4AINPPSbits.T4AINPPS = 0x13;   //RC3->TMR4:T4IN;
    RC0PPS = 0x10;   //RC0->EUSART:TX;
    RXPPSbits.RXPPS = 0x11;   //RC1->EUSART:RX;
    CLCIN0PPSbits.CLCIN0PPS = 0x07;   //RA7->CLC1:CLCIN0;
    CLCIN2PPSbits.CLCIN2PPS = 0x0F;   //RB7->CLC1:CLCIN2;
    CLCIN3PPSbits.CLCIN3PPS = 0x0F;   //RB7->CLC1:CLCIN3;
    RB4PPS = 0x0C;   //RB4->CCP4:CCP4;
    RC2PPS = 0x01;   //RC2->CLC1:CLC1OUT;
    T2AINPPSbits.T2AINPPS = 0x07;   //RA7->TMR2:T2IN;
    CLCIN1PPSbits.CLCIN1PPS = 0x07;   //RA7->CLC1:CLCIN1;
    RB1PPS = 0x09;   //RB1->CCP1:CCP1;
    RB2PPS = 0x0A;   //RB2->CCP2:CCP2;
    RB3PPS = 0x0B;   //RB3->CCP3:CCP3;
    RC5PPS = 0x0D;   //RC5->CCP5:CCP5;
    RC7PPS = 0x0F;   //RC7->PWM7:PWM7OUT;

    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x01; // lock PPS

    GIE = state;

}


void PIN_MANAGER_IOC(void)
{    
}

/**
 End of File
*/
