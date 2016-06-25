/**
 7 Segments LED display multiplexer 

 Author: Lucio Di Jasio

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.15
        Device            :  PIC16F18855
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
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

#include "mcc_generated_files/mcc.h"


#define LIMIT_NONE  0x00
#define LIMIT_10mA  0x80
#define LIMIT_5mA   0x81
#define LIMIT_2mA   0x82
#define LIMIT_1mA   0x83

uint8_t matrix[] = {
//  a  b  c  d  e  f  g
    1, 1, 1, 1, 1, 1, 0, // 0
    0, 1, 1, 0, 0, 0, 0,
    1, 1, 0, 1, 1, 0, 1, // 2
    1, 1, 1, 1, 0, 0, 1,
    0, 1, 1, 0, 0, 1, 1, // 4
    1, 0, 1, 1, 0, 1, 1,
    1, 0, 1, 1, 1, 1, 1, // 6
    1, 1, 1, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, // 8
    1, 1, 1, 1, 0, 1, 1,
    1, 1, 1, 0, 1, 1, 1, // a
    0, 0, 1, 1, 1, 1, 1,
    0, 0, 0, 1, 1, 0, 1, // c
    0, 1, 1, 1, 1, 0, 1,
    1, 0, 0, 1, 1, 1, 1, // e
    1, 0, 0, 0, 1, 1, 1,
};

void digitShow(uint8_t value)
{
    uint8_t *p = &matrix[value * 7];
    SEG_A_LAT = ~*p++;
    SEG_B_LAT = ~*p++;
    SEG_C_LAT = ~*p++;
    SEG_D_LAT = ~*p++;
    SEG_E_LAT = ~*p++;
    SEG_F_LAT = ~*p++;
    SEG_G_LAT = ~*p++;    
}

void main(void)
{
    SYSTEM_Initialize();
    CCDNC |= 0b01111000;   // enable constant current for pin RC6-RC3
    CCDNB |= 0b00000111;   // enable constant current for pin RB2-RB0
    
    while (1)
    {
        // get a 4 bit value from the POT reading
        uint8_t digit = (ADCC_GetSingleConversion(POT) >> 6); 
        
        // second digit: unlimited current
        A2_SetHigh(); A1_SetLow();
        CCDCON = LIMIT_NONE;
        digitShow(digit);
        __delay_ms(10);

        // first digit: current limited
        A2_SetLow();  A1_SetHigh();
        CCDCON = LIMIT_2mA;
        digitShow(digit);
        __delay_ms(10);
    }
}
