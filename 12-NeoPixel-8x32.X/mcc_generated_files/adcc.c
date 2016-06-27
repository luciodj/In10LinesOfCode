/**
  ADCC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adcc.c

  @Summary
    This is the generated driver implementation file for the ADCC driver using MPLAB(c) Code Configurator

  @Description
    This source file provides implementations for driver APIs for ADCC.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "adcc.h"
#include "mcc.h"

/**
  Section: ADCC Module APIs
*/

void ADCC_Initialize(void)
{
    // set the ADCC to the options selected in the User Interface
    // ADDSEN disabled; ADGPOL digital_low; ADIPEN disabled; ADPPOL VSS; 
    ADCON1 = 0x00;
    // ADCRS 0; ADMD Basic_mode; ADACLR disabled; ADPSIS ADFLTR; 
    ADCON2 = 0x00;
    // ADCALC First derivative of Single measurement; ADTMD disabled; ADSOI ADGO not cleared; 
    ADCON3 = 0x00;
    // ADACT disabled; 
    ADACT = 0x00;
    // ADAOV ACC or ADERR not Overflowed; 
    ADSTAT = 0x00;
    // ADCCS FOSC/32; 
    ADCLK = 0x0F;
    // ADNREF VSS; ADPREF VDD; 
    ADREF = 0x00;
    // ADCAP 0; 
    ADCAP = 0x00;
    // ADPRE 0; 
    ADPRE = 0x00;
    // ADACQ 0; 
    ADACQ = 0x00;
    // ADPCH ANA0; 
    ADPCH = 0x00;
    // ADRPT 0; 
    ADRPT = 0x00;
    // ADLTHL 0; 
    ADLTHL = 0x00;
    // ADLTHH 0; 
    ADLTHH = 0x00;
    // ADUTHL 0; 
    ADUTHL = 0x00;
    // ADUTHH 0; 
    ADUTHH = 0x00;
    // ADSTPTL 0; 
    ADSTPTL = 0x00;
    // ADSTPTH 0; 
    ADSTPTH = 0x00;
    
    // ADGO stop; ADFM right; ADON enabled; ADCONT disabled; ADCS FOSC/ADCLK; 
    ADCON0 = 0x84;
    

}

void ADCC_StartConversion(adcc_channel_t channel)
{
    // select the A/D channel
    ADPCH = channel;  
  
    // Turn on the ADC module
    ADCON0bits.ADON = 1;      

    // Start the conversion
    ADCON0bits.ADGO = 1;
}

bool ADCC_IsConversionDone()
{
    // Start the conversion
    return (!ADCON0bits.ADGO);
}

adc_result_t ADCC_GetConversionResult(void)
{
    // Return the result
    return ((ADRESH << 8) + ADRESL);
}

adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel)
{
    // select the A/D channel
    ADPCH = channel;    

    // Turn on the ADC module
    ADCON0bits.ADON = 1;
	
    //Disable the continuous mode.
    ADCON0bits.ADCONT = 0;    

    // Start the conversion
    ADCON0bits.ADGO = 1;

    // Wait for the conversion to finish
    while (ADCON0bits.ADGO)
    {
    }
    
    // Conversion finished, return the result
    return ((ADRESH << 8) + ADRESL);
}

void ADCC_StopConversion(void)
{
	//Reset the ADGO bit.
	ADCON0bits.ADGO = 0;
}

void ADCC_DischargeSampleCapacitor(void)
{
	//Set the ADC channel to AVss.
	ADPCH = 0x3C;   
}

void ADCC_LoadAcquisitionRegister(uint8_t acquisitionValue)
{
	//Load the ADACQ register.
	ADACQ = acquisitionValue;   
}

void ADCC_SetPrechargeTime(uint8_t prechargeTime)
{
	//Load the ADPRE register.
	ADPRE = prechargeTime;  
}

void ADCC_SetRepeatCount(uint8_t repeatCount)
{
	//Load the ADRPT register.
	ADRPT = repeatCount;   
}

uint8_t ADCC_GetCurrentCountofConversions(void)
{
	//Return the contents of ADCNT register
	return ADCNT;
}

void ADCC_ClearAccumulator(void)
{
	//Reset the ADCON2bits.ADACLR bit.
	ADCON2bits.ADACLR = 0;
}

uint16_t ADCC_GetAccumulatorValue(void)
{
	//Return the contents of ADACCH and ADACCL registers
	return ((ADACCH << 8) + ADACCL);
}

bool ADCC_HasAccumulatorOverflowed(void)
{
	//Return the status of ADSTATbits.ADAOV
	return ADSTATbits.ADAOV;
}

uint16_t ADCC_GetFilterValue(void)
{
	//Return the contents of ADFLTRH and ADFLTRL registers
	return ((ADFLTRH << 8) + ADFLTRL);
}

uint16_t ADCC_GetPreviousResult(void)
{
	//Return the contents of ADPREVH and ADPREVL registers
	return ((ADPREVH << 8) + ADPREVL);
}

void ADCC_DefineSetPoint(uint16_t setPoint)
{
	//Sets the ADSTPTH and ADSTPTL registers
	ADSTPTH = setPoint >> 8;
	ADSTPTL = setPoint;
}

void ADCC_SetUpperThreshold(uint16_t upperThreshold)
{
	//Sets the ADUTHH and ADUTHL registers
	ADUTHH = upperThreshold >> 8;
	ADUTHL = upperThreshold;
}

void ADCC_SetLowerThreshold(uint16_t lowerThreshold)
{
	//Sets the ADLTHH and ADLTHL registers
	ADLTHH = lowerThreshold >> 8;
	ADLTHL = lowerThreshold;
}

uint16_t ADCC_GetErrorCalculation(void)
{
#if (__XC8_VERSION < 1360)
	//Return the contents of ADSTPEH and ADSTPEL registers
	return ((ADSTPEH << 8) + ADSTPEL);
#else // __XC8_VERSION
	//Return the contents of ADERRH and ADERRL registers
	return ((ADERRH << 8) + ADERRL);
#endif // __XC8_VERSION
}

void ADCC_EnableDoubleSampling(void)
{
	//Sets the ADCON1bits.ADDSEN
	ADCON1bits.ADDSEN = 1;
}

void ADCC_EnableContinuousConversion(void)
{
	//Sets the ADCON0bits.ADCONT
	ADCON0bits.ADCONT = 1;
}

void ADCC_DisableContinuousConversion(void)
{
	//Resets the ADCON0bits.ADCONT
	ADCON0bits.ADCONT = 0;
}

bool ADCC_HasErrorCrossedUpperThreshold(void)
{
	//Returns the value of ADSTATbits.ADUTHR bit.
	return ADSTATbits.ADUTHR;
}

bool ADCC_HasErrorCrossedLowerThreshold(void)
{
	//Returns the value of ADSTATbits.ADLTHR bit.
	return ADSTATbits.ADLTHR;
}

uint8_t ADCC_GetConversionStageStatus(void)
{
	//Returns the contents of ADSTATbits.ADSTAT field.
	return ADSTATbits.ADSTAT;
}


/**
 End of File
*/
