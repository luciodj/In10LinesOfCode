/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC16F18855
        Version           :  1.01
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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED0 aliases
#define LED0_TRIS               TRISA0
#define LED0_LAT                LATA0
#define LED0_PORT               RA0
#define LED0_WPU                WPUA0
#define LED0_ANS                ANSA0
#define LED0_SetHigh()    do { LATA0 = 1; } while(0)
#define LED0_SetLow()   do { LATA0 = 0; } while(0)
#define LED0_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define LED0_GetValue()         PORTAbits.RA0
#define LED0_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define LED0_SetPullup()    do { WPUA0 = 1; } while(0)
#define LED0_ResetPullup()   do { WPUA0 = 0; } while(0)
#define LED0_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define LED0_SetDigitalMode()   do { ANSA0 = 0; } while(0)


// get/set LED1 aliases
#define LED1_TRIS               TRISA1
#define LED1_LAT                LATA1
#define LED1_PORT               RA1
#define LED1_WPU                WPUA1
#define LED1_ANS                ANSA1
#define LED1_SetHigh()    do { LATA1 = 1; } while(0)
#define LED1_SetLow()   do { LATA1 = 0; } while(0)
#define LED1_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define LED1_GetValue()         PORTAbits.RA1
#define LED1_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define LED1_SetPullup()    do { WPUA1 = 1; } while(0)
#define LED1_ResetPullup()   do { WPUA1 = 0; } while(0)
#define LED1_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define LED1_SetDigitalMode()   do { ANSA1 = 0; } while(0)


// get/set LED2 aliases
#define LED2_TRIS               TRISA2
#define LED2_LAT                LATA2
#define LED2_PORT               RA2
#define LED2_WPU                WPUA2
#define LED2_ANS                ANSA2
#define LED2_SetHigh()    do { LATA2 = 1; } while(0)
#define LED2_SetLow()   do { LATA2 = 0; } while(0)
#define LED2_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define LED2_GetValue()         PORTAbits.RA2
#define LED2_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define LED2_SetPullup()    do { WPUA2 = 1; } while(0)
#define LED2_ResetPullup()   do { WPUA2 = 0; } while(0)
#define LED2_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define LED2_SetDigitalMode()   do { ANSA2 = 0; } while(0)


// get/set LED3 aliases
#define LED3_TRIS               TRISA3
#define LED3_LAT                LATA3
#define LED3_PORT               RA3
#define LED3_WPU                WPUA3
#define LED3_ANS                ANSA3
#define LED3_SetHigh()    do { LATA3 = 1; } while(0)
#define LED3_SetLow()   do { LATA3 = 0; } while(0)
#define LED3_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define LED3_GetValue()         PORTAbits.RA3
#define LED3_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define LED3_SetPullup()    do { WPUA3 = 1; } while(0)
#define LED3_ResetPullup()   do { WPUA3 = 0; } while(0)
#define LED3_SetAnalogMode()   do { ANSA3 = 1; } while(0)
#define LED3_SetDigitalMode()   do { ANSA3 = 0; } while(0)


// get/set CS aliases
#define CS_TRIS               TRISB2
#define CS_LAT                LATB2
#define CS_PORT               RB2
#define CS_WPU                WPUB2
#define CS_ANS                ANSB2
#define CS_SetHigh()    do { LATB2 = 1; } while(0)
#define CS_SetLow()   do { LATB2 = 0; } while(0)
#define CS_Toggle()   do { LATB2 = ~LATB2; } while(0)
#define CS_GetValue()         PORTBbits.RB2
#define CS_SetDigitalInput()    do { TRISB2 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISB2 = 0; } while(0)

#define CS_SetPullup()    do { WPUB2 = 1; } while(0)
#define CS_ResetPullup()   do { WPUB2 = 0; } while(0)
#define CS_SetAnalogMode()   do { ANSB2 = 1; } while(0)
#define CS_SetDigitalMode()   do { ANSB2 = 0; } while(0)

//
/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
*/