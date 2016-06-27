/*
    NeoPixel RGB LED basic demo
    (uses 4x4 RGB Click module)

    File Name:
        main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.30
*/

#include "mcc_generated_files/mcc.h"

void NeoPixel_Stream(uint8_t *p, uint8_t count) 
{   // sends count x GRB data packets (24-bit each)
    uint8_t bitCount, data;
    while (count--) {
        bitCount = 24;
        do {
            if ((bitCount & 7) == 0) 
                data = *p++;    
            SSP1BUF = ((data & 0x80)) ? 0xFE : 0xC0;  // WS2812B 900ns - 350ns           
            data <<= 1;
        } while (--bitCount);
    } 
}

void main(void)
{
    SYSTEM_Initialize();
    //                 G R B triplets
    uint8_t color[] = {0x08, 0, 0,    0, 0x8, 0,    0, 0, 0x8,    0x8, 0x8, 0x8};   
    
    while (1)
    {
        NeoPixel_Stream(color, 4);
        __delay_ms(250);
    }
}
