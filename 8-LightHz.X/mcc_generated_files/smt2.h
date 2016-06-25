/**
  SMT2 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    smt2.h

  @Summary
    This is the generated header file for the SMT2 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for SMT2.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
        Device            :  PIC16F18855
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _SMT2_H
#define _SMT2_H

/**
  Section: Included Files
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: SMT2 APIs
*/

/**
  @Summary
    Initializes the SMT2 module

  @Description
    This routine initializes the SMT2.
    This routine must be called before any other SMT2 routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    SMT2_Initialize();
    </code>
*/
void SMT2_Initialize(void);

/**
  @Summary
    Allows to enable data acquisition

  @Description
    This routine is used to enable data acquisition

  @Preconditions
    SMT2_Initialize() function should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();
    SMT2_DataAcquisitionEnable();
    </code>
*/
void SMT2_DataAcquisitionEnable(void);

/**
  @Summary
    Allows to disable data acquisition

  @Description
    This routine is used to disable data acquisition

  @Preconditions
    SMT2_Initialize() function and SMT2_DataAcquisitionEnable() 
    should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();
    SMT2_DataAcquisitionEnable();
        .
        .
        .
    SMT2_DataAcquisitionDisable();
    </code>
*/
void SMT2_DataAcquisitionDisable(void);

/**
  @Summary
    Allows counter to be at SMT2PR and
    interrupt occurs when clocked.

  @Description
    This routine allows the counter to be at SMT2PR and
    interrupt occurs when clocked.

  @Preconditions
    SMT2_Initialize() function and SMT2_DataAcquisitionEnable() 
    should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();
    SMT2_DataAcquisitionEnable();
 
    // User Code
 
    SMT2_HaltCounter();
    </code>
*/
void SMT2_HaltCounter(void);

/**
  @Summary
    Allows to change period.

  @Description
    This routine is used to change the period

  @Preconditions
    SMT2_Initialize() function should have been called before calling this function.

  @Returns
    None

  @Param
    periodVal : Period value to be loaded

  @Example
    <code>
    SMT2_Initialize();
    SMT2_SetPeriod(0x00123456);
    </code>
*/
void SMT2_SetPeriod(uint32_t periodVal);

/**
  @Summary
    To get SMT2 period value.

  @Description
    This routine is used to get SMT2 period value.

  @Preconditions
    SMT2_Initialize() function should have been called before calling this function.

  @Returns
    uint32_t - Value of period register.

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();

    SMT2_GetPeriod();
    </code>
*/
uint32_t SMT2_GetPeriod(void);

/**
  @Summary
    Allows single data acquisition.

  @Description
    This routine allows single data acquisition.

  @Preconditions
    SMT2_Initialize() function and SMT2 data acquisition bit
    should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();
    SMT2_DataAcquisitionEnable();
 
    // User Code
 
    SMT2_SingleDataAcquisition();
    </code>
*/
void SMT2_SingleDataAcquisition(void);

/**
  @Summary
    Allows repeat data acquisition.

  @Description
    This routine allows repeat data acquisition.

  @Preconditions
    SMT2_Initialize() function and SMT2 data acquisition bit
    should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();
    SMT2_DataAcquisitionEnable();
 
    // User Code
 
    SMT2_RepeatDataAcquisition();
    </code>
*/
void SMT2_RepeatDataAcquisition(void);

/**
  @Summary
    Allows SMT2 to update SMT2PR registers.

  @Description
    This routine allows SMT2 to update SMT2PR registers.

  @Preconditions
    SMT2_Initialize() function and SMT2 data acquisition bit
    should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();
    SMT2_DataAcquisitionEnable();
 
    // User Code
 
    SMT2_ManualPeriodBufferUpdate();
    </code>
*/
void SMT2_ManualPeriodBufferUpdate(void);

/**
  @Summary
    Allows SMT2 to update SMT2CPW registers.

  @Description
    This routine allows SMT2 to update SMT2CPW registers.

  @Preconditions
    SMT2_Initialize() function and SMT2 data acquisition bit
    should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();
    SMT2_DataAcquisitionEnable();
 
    // User Code
 
    SMT2_ManualPulseWidthBufferUpdate();
    </code>
*/
void SMT2_ManualPulseWidthBufferUpdate(void);

/**
  @Summary
    Allows SMT2 to reset SMT2TMR registers.

  @Description
    This routine allows SMT2 to reset SMT2TMR registers.

  @Preconditions
    SMT2_Initialize() function and SMT2 data acquisition bit
    should have been called before calling this function.

  @Returns
    None

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();
    SMT2_DataAcquisitionEnable();
 
    // User Code
 
    SMT2_ManualTimerReset();
    </code>
*/
void SMT2_ManualTimerReset(void);

/**
  @Summary
    Determines if SMT2 window is open or closed.

  @Description
    This routine is used to determine if SMT2 window is open or closed.
    This bit is only valid when TS bit equals to 1. 

  @Preconditions
    SMT2_Initialize() function and SMT2 data acquisition bit
    should have been called before calling this function.

  @Returns
    1 - SMT2 window is open
    0 - SMT2 window is closed

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();

    if(SMT2_IsWindowOpen())
    {
        // User code..
    }
    else
    {
        // User code..
    }
    </code>
*/
bool SMT2_IsWindowOpen(void);

/**
  @Summary
    Determines if SMT2 signal acquisition is in progress or not.

  @Description
    This routine is used to determine if SMT2 signal acquisition is in progress or not.
    This bit is only valid when TS bit equals to 1. 
 
  @Preconditions
    SMT2_Initialize() function and SMT2 data acquisition bit
    should have been called before calling this function.

  @Returns
    1 - SMT2 signal acquisition is in progress
    0 - SMT2 signal acquisition is not in progress

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();

    while(!SMT2_IsSignalAcquisitionInProgress())
    {
        // User code..
    }
    </code>
*/
bool SMT2_IsSignalAcquisitionInProgress(void);

/**
  @Summary
    Determines if SMT2 timer is incrementing or not.

  @Description
    This routine is used to determine if SMT2 timer is incrementing or not.
     
  @Preconditions
    SMT2_Initialize() function and SMT2 data acquisition bit
    should have been called before calling this function.

  @Returns
    1 - SMT2 timer is incrementing
    0 - SMT2 timer is not incrementing

  @Param
    None

  @Example
    <code>
    SMT2_Initialize();

    while(!SMT2_IsTimerIncrementing())
    {
        // User code..
    }
    </code>
*/
bool SMT2_IsTimerIncrementing(void);

/**
  @Summary
    To get SMT2 pulse width latch register value.

  @Description
    This routine is used to get SMT2 pulse width latch register value.
     
  @Preconditions
    SMT2_Initialize() function should have been called before calling this function.

  @Returns
    uint32_t - Value of pulse width latch register.
    
  @Param
    None

  @Example
    <code>
    SMT2_Initialize();

    SMT2_GetCapturedPulseWidth();
    </code>
*/
uint32_t SMT2_GetCapturedPulseWidth(void);

/**
  @Summary
    To get SMT2 period latch register value.

  @Description
    This routine is used to get SMT2 period latch register value.
     
  @Preconditions
    SMT2_Initialize() function should have been called before calling this function.

  @Returns
    uint32_t - Value of period register.
    
  @Param
    None

  @Example
    <code>
    SMT2_Initialize();

    SMT2_GetCapturedPeriod();
    </code>
*/
uint32_t SMT2_GetCapturedPeriod(void);

/**
  @Summary
    To get SMT2 Timer latch register value.

  @Description
    This routine is used to get SMT2 Timer latch register value.
     
  @Preconditions
    SMT2_Initialize() function should have been called before calling this function.

  @Returns
    uint32_t - Value of Timer register.
    
  @Param
    None

  @Example
    <code>
    SMT2_Initialize();

    SMT2_GetTimerValue();
    </code>
*/
uint32_t SMT2_GetTimerValue(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // _SMT2_H
/**
 End of File
*/


