/**
    NeoPixel 8x32 matrix display demo
    (uses Adafruit 8x32 matrix module)
    
    File Name:
      main.c

    Summary:

    Device            :  PIC16F18855
    Compiler          :  XC8 v1.35
    MPLAB             :  MPLAB X v3.30
*/

#include "NeoPixel.h"
#include "mcc_generated_files/mcc.h"
#include <ctype.h>
#include <string.h>

#define STR_SIZE    32
char s[STR_SIZE];

uint32_t bg = NEO_BLACK;        // default background color
uint32_t fg = NEO_GREEN;        // default foreground color
bool scrolling = true;

uint32_t xtoc(char *s)
{ // convert a hex string to a 24-bit RGB value
    char c;
    uint32_t color = 0;
    while( c = *s++) {
        if (isxdigit(c)) {
            c -= '0'; c = (c > 9) ? (c-7) : c;
            color = (color << 4) + c; 
        }
    }
    return color & 0xffffff;    
}

void ProcessInput( char c)
{
    static bool cmd = false;
    uint8_t len = strlen(s);
    if (cmd) {
        switch(toupper(c)) {
        case '\r': 
                return;
        case 'D': // display string
            NeoPixel_Clear(bg);
            NeoPixel_Puts(0, s, fg);
            NeoPixel_Show();
            scrolling = false;
            puts("->Display");
            break;
        case 'S': // scroll string
            NeoPixel_Scroll(s, fg, true);
            scrolling = true;
            puts("->Scroll");
            cmd = false;
            putch('"');
            return;
        case 'B': // background color
            if (len >= 6)
                bg = xtoc(s);
            puts("->Background" );
            break;
        case 'F': // foreground color
            if (len >= 6)
                fg = xtoc(s);
            puts("->Foreground");
            break;
        case 'C': // clear screen
            NeoPixel_Clear(bg);
            NeoPixel_Show();
            scrolling = false;
            puts("->Clear");
            break;
        case '\n': // start a new string
            break;
        default:   // command not recognized
            puts("->valid commands are: B, C, D, F, S");
            putch(':');
            return; 
        }
        s[0] = '\0';
        cmd = false;
        putch('"');
    }
    else switch(c) {
        case '\r': 
            break;
        case '\n':
            cmd = true; putch(':');
            break;
        default:    // buffering
            if ((c < ' ') || (c > '~'))
                return;
            if (len < STR_SIZE-1)          
                s[len++] = c; s[len] = '\0';
            break;
    }
}

/*
                         Main application
 */
void main(void)
{
    uint8_t delay=0, delaySet=0;
    s[0] = '\0';
    scrolling = true;
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    ADCC_StartConversion(POT);
    puts("\nXPRESS NeoPixel Demo");
    NeoPixel_Clear(NEO_BLACK);  
    strcpy(s, "** Xpress ");
    NeoPixel_Scroll(s, NEO_GREEN, true);
    
    // start in string mode
    putch('"');
    while (1)
    {
        if (EUSART_DataReady)
            ProcessInput(getche());

        if (ADCC_IsConversionDone()) {
            delaySet = ADCC_GetConversionResult() >> 6; // need only 4 bit
            ADCC_StartConversion(POT);
        }
        if ( TMR2_HasOverflowOccured()) {    // 10ms
            if ( delay > 0) delay--;
            else {
                if (scrolling)  NeoPixel_Scroll(s, fg, false);
                delay = delaySet;
            }
        }
    }
}
/**
 End of File
*/