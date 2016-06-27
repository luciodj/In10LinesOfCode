/**
    7 Segments LED display driver / multiplexer 

    File Name:
        main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.30
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
