/*
 * LED 8x8 Click driver
 */

#include "mcc_generated_files/mcc.h"
#include "led8x8.h"

// send register / value pair
void LED8x8_Write( uint8_t reg, uint8_t b)
{
    CS_SetLow();
      SPI1_Exchange8bit( reg);
      SPI1_Exchange8bit( b);
    CS_SetHigh();
}


void LED8x8_Initialize( uint8_t intensity)
{
    // exit display shut down mode
    LED8x8_Write( 0x0C, 0x01);
    // configure driver for scanning columns 0..7
    LED8x8_Write( 0x0B, 0x07);
    // limit current drive to 1/32
    LED8x8_Write( 0x0A, intensity);  
}

// font initialization
const uint8_t font_first = '@';
const uint8_t font_table[] = { 
    0, 0, 0, 0, 0, 0, 0, 0, // @ used as space!!! 
    0b00000000,     // A
    0b00011111,
    0b00100100,
    0b01000100,
    0b01000100,
    0b00100100,
    0b00011111,
    0b00000000,
    0b00000000,     // B
    0b00000000,
    0b00110110,
    0b01001001,
    0b01001001,
    0b01001001,
    0b01111111,
    0b00000000,
    0b00000000,     // C
    0b00100010,
    0b01000001,
    0b01000001,
    0b01000001,
    0b00100010,
    0b00011100,
    0b00000000,
    0b00000000,     // D
    0b00011100,
    0b00100010,
    0b01000001,
    0b01000001,
    0b01000001,
    0b01111111,
    0b00000000,
    0b00000000,     // E
    0b00000000,
    0b01000001,
    0b01001001,
    0b01001001,
    0b01001001,
    0b01111111,
    0b00000000,
    
    0b00000000,     // F
    0b00000000,
    0b01000000,
    0b01001000,
    0b01001000,
    0b01001000,
    0b01111111,
    0b00000000,
    0b00000000,     // G
    0b00100111,
    0b01000101,
    0b01000001,
    0b01000001,
    0b00100010,
    0b00011100,
    0b00000000,
    0b00000000,     // H
    0b01111111,
    0b00001000,
    0b00001000,
    0b00001000,
    0b00001000,
    0b01111111,
    0b00000000,
    0b00000000,     // 'I'
    0b00000000,
    0b00000000,
    0b01000001,
    0b01111111,
    0b01000001,
    0b00000000,
    0b00000000,
    0b00000000,     // 'J'
    0b00000000,
    0b00000000,
    0b01000000,
    0b01111110,
    0b01000001,
    0b00000010,
    0b00000000,
    0b00000000,     // K
    0b00000000,
    0b01000001,
    0b00100100,
    0b00011000,
    0b00010000,
    0b01111111,
    0b00000000,
    0b00000000,     // L
    0b00000000,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b01111111,
    0b00000000,
    0b00000000,     // M
    0b01111111,
    0b00100000,
    0b00010000,
    0b00001000,
    0b00100000,
    0b01111111,
    0b00000000,
    0b00000000,     // N
    0b01111111,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000,
    0b01111111,
    0b00000000,
    0b00000000,     // O
    0b00011100,
    0b00100010,
    0b01000001,
    0b01000001,
    0b00100010,
    0b00011100,
    0b00000000,
    0b00000000,     // P
    0b00000000,
    0b00110000,
    0b01001000,
    0b01001000,
    0b01001000,
    0b01111111,
    0b00000000,
    0b00000000,     // Q
    0b00011101,
    0b00100011,
    0b01000001,
    0b01000001,
    0b00100010,
    0b00011100,
    0b00000000,
    0b00000000,     // R
    0b00000000,
    0b00110001,
    0b01001010,
    0b01001100,
    0b01001000,
    0b01111111,
    0b00000000,
    0b00000000,     // S
    0b01000010,
    0b01000101,
    0b01001001,
    0b01001001,
    0b00101001,
    0b00010001,
    0b00000000,
    0b00000000,     // T
    0b00000000,
    0b01000000,
    0b01000000,
    0b01111111,
    0b01000000,
    0b01000000,
    0b00000000,
    0b00000000,     // U
    0b01111110,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b01111110,
    0b00000000,
    0b00000000,     // V
    0b01111000,
    0b00000100,
    0b00000010,
    0b00000011,
    0b00000100,
    0b01111000,
    0b00000000,
    0b00000000,     // W
    0b01111110,
    0b00000001,
    0b00000001,
    0b00011110,
    0b00000001,
    0b01111110,
    0b00000000,
    0b00000000,     // X
    0b01000011,
    0b00100100,
    0b00011000,
    0b00101000,
    0b01000100,
    0b01000011,
    0b00000000,
    0b00000000,     // Y
    0b01000000,
    0b00100000,
    0b00010000,
    0b00011111,
    0b00100000,
    0b01000000,
    0b00000000,
    0b00000000,     // Z
    0b01100001,
    0b01010001,
    0b01001001,
    0b01000101,
    0b01000010,
    0b01000001,
    0b00000000,

};

void LED8x8_Display( uint8_t *m)
{
    uint8_t i;
    for( i=1; i<=8; i++)
        LED8x8_Write( i, *m++);
}

void LED8x8_Putch( uint8_t *m, unsigned char c)
{
    uint8_t i;
    if (c < font_first) c = font_first;
    if (c >= 'a') c -= 'a'-'A';
    const uint8_t *p = &font_table[( c-font_first) << 3];
    for( i=0; i<8; i++)
        m[i] = *p++;
}

void LED8x8_ShiftLeft( uint8_t *m, char c, uint8_t n)
{
    uint8_t i;
    for( i=7; i>0; i--)
        m[i] = m[i-1];
    m[0] = font_table[(( c-font_first) << 3) + 7 - n];
}

void LED8x8_ShiftUp( uint8_t *m, char c, uint8_t n)
{
    uint8_t i, k;
    const uint8_t *p;
    p = &font_table[ (c-font_first) << 3];
    for( i=0; i<8; i++)
    {
        m[i] <<= 1;
        k = *p++;
        m[i] += ((k >> (7-n)) & 1);
    }
}

void LED8x8_RotateUp( uint8_t *m)
{
    uint8_t i, b;
    for( i=0; i<8; i++)
    {
        b = m[i] & 0x80;
        m[i] <<= 1;
        if ( b)
            m[i] = m[i] + 1;
    }
}

void LED8x8_RotateLeft( uint8_t *m)
{
    uint8_t i, b;
    b = m[7];
    for( i=7; i>0; i--)
        m[i] = m[i-1];
    m[0] = b;
}


void LED8x8_HorMessage( uint8_t *m, char *s)
{
    char c;
    uint8_t i;
    for( i=0; i<8; i++)
        m[i] = 0;
    while ( c = *s++)
    {
        if (c < font_first) c = font_first;
        if (c >= 'a') c -= 'a'-'A';        
        for( i=0; i<8; i++)
        {
            LED8x8_Display( m);
            LED8x8_ShiftLeft( m, c, i);
        __delay_ms( 100);   
        }
    }
}


void LED8x8_VerMessage( uint8_t *m, char *s)
{
    char c;
    uint8_t i;
    for( i=0; i<8; i++)
        m[i] = 0;
    while ( c = *s++)
    {
        if (c < font_first) c = font_first;
        if (c >= 'a') c -= 'a'-'A';        
        for( i=0; i<8; i++)
        {
            LED8x8_ShiftUp( m, c, i);
            LED8x8_Display( m);
        __delay_ms( 100);   
        }
    }

}
