/**
  Analog input and output demo 

  File Name:
    main.c

  Device            :  PIC16F18855
  Compiler          :  XC8 1.35
  MPLAB             :  MPLAB X 3.30
*/

#include "mcc_generated_files/mcc.h"

void main(void)
{
    SYSTEM_Initialize();

    while (1)
    {
        PWM7_LoadDutyValue(ADCC_GetSingleConversion(POT));
    }
}
/**
 End of File
*/