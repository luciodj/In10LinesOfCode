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

// get/set SEG_G aliases
#define SEG_G_TRIS               TRISB0
#define SEG_G_LAT                LATB0
#define SEG_G_PORT               RB0
#define SEG_G_WPU                WPUB0
#define SEG_G_ANS                ANSB0
#define SEG_G_SetHigh()    do { LATB0 = 1; } while(0)
#define SEG_G_SetLow()   do { LATB0 = 0; } while(0)
#define SEG_G_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define SEG_G_GetValue()         PORTBbits.RB0
#define SEG_G_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define SEG_G_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define SEG_G_SetPullup()    do { WPUB0 = 1; } while(0)
#define SEG_G_ResetPullup()   do { WPUB0 = 0; } while(0)
#define SEG_G_SetAnalogMode()   do { ANSB0 = 1; } while(0)
#define SEG_G_SetDigitalMode()   do { ANSB0 = 0; } while(0)


// get/set SEG_F aliases
#define SEG_F_TRIS               TRISB1
#define SEG_F_LAT                LATB1
#define SEG_F_PORT               RB1
#define SEG_F_WPU                WPUB1
#define SEG_F_ANS                ANSB1
#define SEG_F_SetHigh()    do { LATB1 = 1; } while(0)
#define SEG_F_SetLow()   do { LATB1 = 0; } while(0)
#define SEG_F_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define SEG_F_GetValue()         PORTBbits.RB1
#define SEG_F_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define SEG_F_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define SEG_F_SetPullup()    do { WPUB1 = 1; } while(0)
#define SEG_F_ResetPullup()   do { WPUB1 = 0; } while(0)
#define SEG_F_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define SEG_F_SetDigitalMode()   do { ANSB1 = 0; } while(0)


// get/set SEG_E aliases
#define SEG_E_TRIS               TRISB2
#define SEG_E_LAT                LATB2
#define SEG_E_PORT               RB2
#define SEG_E_WPU                WPUB2
#define SEG_E_ANS                ANSB2
#define SEG_E_SetHigh()    do { LATB2 = 1; } while(0)
#define SEG_E_SetLow()   do { LATB2 = 0; } while(0)
#define SEG_E_Toggle()   do { LATB2 = ~LATB2; } while(0)
#define SEG_E_GetValue()         PORTBbits.RB2
#define SEG_E_SetDigitalInput()    do { TRISB2 = 1; } while(0)
#define SEG_E_SetDigitalOutput()   do { TRISB2 = 0; } while(0)

#define SEG_E_SetPullup()    do { WPUB2 = 1; } while(0)
#define SEG_E_ResetPullup()   do { WPUB2 = 0; } while(0)
#define SEG_E_SetAnalogMode()   do { ANSB2 = 1; } while(0)
#define SEG_E_SetDigitalMode()   do { ANSB2 = 0; } while(0)


// get/set A1 aliases
#define A1_TRIS               TRISC2
#define A1_LAT                LATC2
#define A1_PORT               RC2
#define A1_WPU                WPUC2
#define A1_ANS                ANSC2
#define A1_SetHigh()    do { LATC2 = 1; } while(0)
#define A1_SetLow()   do { LATC2 = 0; } while(0)
#define A1_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define A1_GetValue()         PORTCbits.RC2
#define A1_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define A1_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define A1_SetPullup()    do { WPUC2 = 1; } while(0)
#define A1_ResetPullup()   do { WPUC2 = 0; } while(0)
#define A1_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define A1_SetDigitalMode()   do { ANSC2 = 0; } while(0)


// get/set SEG_D aliases
#define SEG_D_TRIS               TRISC3
#define SEG_D_LAT                LATC3
#define SEG_D_PORT               RC3
#define SEG_D_WPU                WPUC3
#define SEG_D_ANS                ANSC3
#define SEG_D_SetHigh()    do { LATC3 = 1; } while(0)
#define SEG_D_SetLow()   do { LATC3 = 0; } while(0)
#define SEG_D_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define SEG_D_GetValue()         PORTCbits.RC3
#define SEG_D_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define SEG_D_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

#define SEG_D_SetPullup()    do { WPUC3 = 1; } while(0)
#define SEG_D_ResetPullup()   do { WPUC3 = 0; } while(0)
#define SEG_D_SetAnalogMode()   do { ANSC3 = 1; } while(0)
#define SEG_D_SetDigitalMode()   do { ANSC3 = 0; } while(0)


// get/set SEG_C aliases
#define SEG_C_TRIS               TRISC4
#define SEG_C_LAT                LATC4
#define SEG_C_PORT               RC4
#define SEG_C_WPU                WPUC4
#define SEG_C_ANS                ANSC4
#define SEG_C_SetHigh()    do { LATC4 = 1; } while(0)
#define SEG_C_SetLow()   do { LATC4 = 0; } while(0)
#define SEG_C_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define SEG_C_GetValue()         PORTCbits.RC4
#define SEG_C_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define SEG_C_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

#define SEG_C_SetPullup()    do { WPUC4 = 1; } while(0)
#define SEG_C_ResetPullup()   do { WPUC4 = 0; } while(0)
#define SEG_C_SetAnalogMode()   do { ANSC4 = 1; } while(0)
#define SEG_C_SetDigitalMode()   do { ANSC4 = 0; } while(0)


// get/set SEG_B aliases
#define SEG_B_TRIS               TRISC5
#define SEG_B_LAT                LATC5
#define SEG_B_PORT               RC5
#define SEG_B_WPU                WPUC5
#define SEG_B_ANS                ANSC5
#define SEG_B_SetHigh()    do { LATC5 = 1; } while(0)
#define SEG_B_SetLow()   do { LATC5 = 0; } while(0)
#define SEG_B_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define SEG_B_GetValue()         PORTCbits.RC5
#define SEG_B_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define SEG_B_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define SEG_B_SetPullup()    do { WPUC5 = 1; } while(0)
#define SEG_B_ResetPullup()   do { WPUC5 = 0; } while(0)
#define SEG_B_SetAnalogMode()   do { ANSC5 = 1; } while(0)
#define SEG_B_SetDigitalMode()   do { ANSC5 = 0; } while(0)


// get/set SEG_A aliases
#define SEG_A_TRIS               TRISC6
#define SEG_A_LAT                LATC6
#define SEG_A_PORT               RC6
#define SEG_A_WPU                WPUC6
#define SEG_A_ANS                ANSC6
#define SEG_A_SetHigh()    do { LATC6 = 1; } while(0)
#define SEG_A_SetLow()   do { LATC6 = 0; } while(0)
#define SEG_A_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define SEG_A_GetValue()         PORTCbits.RC6
#define SEG_A_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define SEG_A_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

#define SEG_A_SetPullup()    do { WPUC6 = 1; } while(0)
#define SEG_A_ResetPullup()   do { WPUC6 = 0; } while(0)
#define SEG_A_SetAnalogMode()   do { ANSC6 = 1; } while(0)
#define SEG_A_SetDigitalMode()   do { ANSC6 = 0; } while(0)


// get/set A2 aliases
#define A2_TRIS               TRISC7
#define A2_LAT                LATC7
#define A2_PORT               RC7
#define A2_WPU                WPUC7
#define A2_ANS                ANSC7
#define A2_SetHigh()    do { LATC7 = 1; } while(0)
#define A2_SetLow()   do { LATC7 = 0; } while(0)
#define A2_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define A2_GetValue()         PORTCbits.RC7
#define A2_SetDigitalInput()    do { TRISC7 = 1; } while(0)
#define A2_SetDigitalOutput()   do { TRISC7 = 0; } while(0)

#define A2_SetPullup()    do { WPUC7 = 1; } while(0)
#define A2_ResetPullup()   do { WPUC7 = 0; } while(0)
#define A2_SetAnalogMode()   do { ANSC7 = 1; } while(0)
#define A2_SetDigitalMode()   do { ANSC7 = 0; } while(0)



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