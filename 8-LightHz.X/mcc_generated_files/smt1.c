/**
  SMT1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    smt1.c

  @Summary
    This is the generated driver implementation file for the SMT1 driver using MPLAB(c) Code Configurator

  @Description
    This source file provides APIs for SMT1.
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "smt1.h"

/**
  Section: SMT1 APIs
*/

void SMT1_Initialize(void)
{
    // WPOL high/rising edge enabled; STP rolls over to 24'h000000; SPOL high/rising edge enabled; SMT1EN enabled; SMT1PS 1:1 Prescaler; CPOL rising edge; 
    SMT1CON0 = 0x80;

    // REPEAT Repeat Data Acquisition; MODE Gated counter; SMT1GO disabled; 
    SMT1CON1 = 0x49;

    // SMT1CPWUP SMT1CPW1 update complete; SMT1CPRUP SMT1PR1 update complete; RST SMT1TMR1 update complete; 
    SMT1STAT = 0x00;

    // SMT1CSEL FOSC/4; 
    SMT1CLK = 0x00;

    // SMT1WSEL CLC1OUT; 
    SMT1WIN = 0x14;

    // SMT1SSEL SMT1WINPPS; 
    SMT1SIG = 0x00;

    // SMT1PR 255; 
    SMT1PRU = 0xFF;

    // SMT1PR 255; 
    SMT1PRH = 0xFF;

    // SMT1PR 255; 
    SMT1PRL = 0xFF;

    // Start the SMT module by writing to SMTxGO bit
    SMT1CON1bits.SMT1GO = 1;
    
}
        
void SMT1_DataAcquisitionEnable(void)
{
    // Start the SMT module by writing to SMTxGO bit
    SMT1CON1bits.SMT1GO = 1;
}

void SMT1_DataAcquisitionDisable(void)
{
    // Start the SMT module by writing to SMTxGO bit
    SMT1CON1bits.SMT1GO = 0;
}

void SMT1_HaltCounter(void)
{
    SMT1CON0bits.STP = 1;
}

void SMT1_SetPeriod(uint32_t periodVal)
{
    // Write to the SMT1 Period registers
    SMT1PRU = (periodVal >> 16);
    SMT1PRH = (periodVal >> 8);
    SMT1PRL = periodVal;
}

uint32_t SMT1_GetPeriod()
{
    return (SMT1PR);
}

void SMT1_SingleDataAcquisition(void)
{
    SMT1CON1bits.REPEAT = 0;
}

void SMT1_RepeatDataAcquisition(void)
{
    SMT1CON1bits.REPEAT = 1;
}

void SMT1_ManualPeriodBufferUpdate(void)
{
    SMT1STATbits.SMT1CPRUP = 1;
}

void SMT1_ManualPulseWidthBufferUpdate(void)
{
    SMT1STATbits.SMT1CPWUP = 1;
}

void SMT1_ManualTimerReset(void)
{
    SMT1STATbits.RST = 1;
}

bool SMT1_IsWindowOpen(void)
{
    return (SMT1STATbits.SMT1WS);
}

bool SMT1_IsSignalAcquisitionInProgress(void)
{
    return (SMT1STATbits.SMT1AS);
}

bool SMT1_IsTimerIncrementing(void)
{
    return (SMT1STATbits.SMT1TS);
}

uint32_t SMT1_GetCapturedPulseWidth()
{
    return (SMT1CPW);
}

uint32_t SMT1_GetCapturedPeriod()
{
    return (SMT1CPR);
}

uint32_t SMT1_GetTimerValue()
{
    return (SMT1TMR);
}
/**
 End of File
*/
