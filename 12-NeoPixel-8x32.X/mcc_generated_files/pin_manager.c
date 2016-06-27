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
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
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
    WPUA = 0xBF;
    WPUB = 0xFF;
    WPUC = 0x77;
    ANSELA = 0xBC;
    ANSELB = 0x2F;
    ANSELC = 0x64;
    TRISB = 0xFF;
    TRISC = 0x7E;
    TRISA = 0xBF;

    

    // interrupts-on-change are globally disabled
    PIE0bits.IOCIE = 0;
    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    RC0PPS = 0x0010;   //RC0->EUSART:TX;
    SSP1CLKPPSbits.SSP1CLKPPS = 0x0013;   //RC3->MSSP1:SCK1;
    SSP1DATPPSbits.SSP1DATPPS = 0x0014;   //RC4->MSSP1:SDI1;
    RXPPSbits.RXPPS = 0x0011;   //RC1->EUSART:RX;
    CLCIN0PPSbits.CLCIN0PPS = 0x0000;   //RA0->CLC1:CLCIN0;
    CLCIN2PPSbits.CLCIN2PPS = 0x000E;   //RB6->CLC1:CLCIN2;
    CLCIN3PPSbits.CLCIN3PPS = 0x000F;   //RB7->CLC1:CLCIN3;
    T2AINPPSbits.T2AINPPS = 0x0013;   //RC3->TMR2:T2IN;
    CLCIN1PPSbits.CLCIN1PPS = 0x0001;   //RA1->CLC1:CLCIN1;
    ADCACTPPS = 0x000C;   //RB4->ADCC:ADCACT;
    RA6PPS = 0x0001;   //RA6->CLC1:CLC1OUT;
    RC7PPS = 0x0015;   //RC7->MSSP1:SDO1;

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