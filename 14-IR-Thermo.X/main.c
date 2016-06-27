/*
    IR-Click Temperature Sensor demo
    (uses I2C interface)

    File Name:
        main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.30
*/

#include "mcc_generated_files/mcc.h"

// IR Thermo Click(tm) constants
#define IR_THERMO_ADDRESS   0x5A
#define AMB_TEMP            0x06
#define OBJ_TEMP            0x07

bool IR_SensorRead(uint8_t reg, float * pTemp)
{
    int16_t data;
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    static I2C2_TRANSACTION_REQUEST_BLOCK trb[2];
    
    I2C2_MasterWriteTRBBuild(&trb[0], &reg, 1, IR_THERMO_ADDRESS);
    I2C2_MasterReadTRBBuild(&trb[1], (uint8_t*)&data, 2, IR_THERMO_ADDRESS);                
    I2C2_MasterTRBInsert(2, &trb[0], &status);
    
    while(status == I2C2_MESSAGE_PENDING);         // blocking
    *pTemp = ((float)(data) *  0.02) - 273.15;     // convert to deg C

    return (status == I2C2_MESSAGE_COMPLETE); 
} 

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {
        float Temp; 
        if (IR_SensorRead( OBJ_TEMP, &Temp))
            printf("The remote temperature is %0.1f C\n", Temp);
//          printf("The remote temperature is %0.1f F\n", Temp*1.8+32);
        __delay_ms( 1000);
    }
}
/**
 End of File
*/