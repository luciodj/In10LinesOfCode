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
    WPUB = 0xF8;
    WPUC = 0x7A;
    ANSELA = 0xFC;
    ANSELB = 0xF;
    ANSELC = 0xF1;
    TRISB = 0xF8;
    TRISC = 0x7E;
    TRISA = 0xFF;

    


    bool state = GIE;
    GIE = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCKbits.PPSLOCKED = 0x00; // unlock PPS

    RC0PPS = 0x10;   //RC0->EUSART:TX;
    CLCIN1PPSbits.CLCIN1PPS = 0x01;   //RA1->CLC1:CLCIN1;
    RXPPSbits.RXPPS = 0x11;   //RC1->EUSART:RX;
    CLCIN0PPSbits.CLCIN0PPS = 0x00;   //RA0->CLC1:CLCIN0;
    SMT2SIGPPSbits.SMT2SIGPPS = 0x0D;   //RB5->SMT2:SMT2SIG;
    CLCIN2PPSbits.CLCIN2PPS = 0x0E;   //RB6->CLC1:CLCIN2;
    CLCIN3PPSbits.CLCIN3PPS = 0x0F;   //RB7->CLC1:CLCIN3;
    SMT2WINPPSbits.SMT2WINPPS = 0x0C;   //RB4->SMT2:SMT2WIN;
    SMT1SIGPPSbits.SMT1SIGPPS = 0x12;   //RC2->SMT1:SMT1SIG;
    SMT1WINPPSbits.SMT1WINPPS = 0x13;   //RC3->SMT1:SMT1WIN;

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
