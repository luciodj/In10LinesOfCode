 /**
   PWM6 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     pwm6.c
 
   @Summary
     This is the generated driver implementation file for the PWM6 driver using MPLAB(c) Code Configurator
 
   @Description
     This source file provides implementations for driver APIs for PWM6.
     Generation Information :
         Product Revision  :  MPLAB(c) Code Configurator - 3.15.0
         Device            :  PIC16F18855
         Driver Version    :  2.00
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
 #include "pwm6.h"

 /**
   Section: PWM Module APIs
 */

 void PWM6_Initialize(void)
 {
     // Set the PWM to the options selected in the MPLAB(c) Code Configurator.
     // PWM6POL active_hi; PWM6EN enabled; 
     PWM6CON = 0x80;
     
     // DC 127; 
     PWM6DCH = 0x7F;
     
     // DC 3; 
     PWM6DCL = 0xC0;
     
     
     // Select timer
     CCPTMRS1bits.P6TSEL = 0x1;
 }

 void PWM6_LoadDutyValue(uint16_t dutyValue)
 {
     // Writing to 8 MSBs of PWM duty cycle in PWMDCH register
     PWM6DCH = (dutyValue & 0x03FC)>>2;
     
     // Writing to 2 LSBs of PWM duty cycle in PWMDCL register
     PWM6DCL = (dutyValue & 0x0003)<<6;
 }
 /**
  End of File
 */
