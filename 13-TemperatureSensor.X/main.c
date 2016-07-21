/**
    EMC1001 Temperature Sensor demo
    (uses I2C module and on-board EMC1001 sensor)
    
    File Name:
      main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.35
    MPLAB             :  MPLAB X 3.20
*/

#include "mcc_generated_files/mcc.h"

#define EMC1001_ADDRESS     0x49   // slave device address

bool EMC1001_Read(uint8_t reg, uint8_t *pData)
{
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    static I2C2_TRANSACTION_REQUEST_BLOCK trb[2];
    
    I2C2_MasterWriteTRBBuild(&trb[0], &reg, 1, EMC1001_ADDRESS);
    I2C2_MasterReadTRBBuild(&trb[1], pData, 1, EMC1001_ADDRESS);                
    I2C2_MasterTRBInsert(2, &trb[0], &status);
    
    while(status == I2C2_MESSAGE_PENDING);      // blocking

    return (status == I2C2_MESSAGE_COMPLETE); 
} 

// EMC1001 registers
#define TEMP_HI     0       // temperature value high byte 
#define TEMP_LO     2       // low byte containing 1/4 deg fraction

void main(void)
{
    uint8_t data;
    int8_t  temp;
    uint8_t templo;

    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
        
    while (1)
    {
        printf("\x0C");   // comment out if terminal does not support Form Feed
        puts("Temperature Sensor Demo\n");
        if (EMC1001_Read(0xfd, &data)) printf("Product ID: EMC1001%s\n", data ? "-1" : "");
        if (EMC1001_Read(0xfe, &data)) printf("Manufacturer ID: 0x%X\n", data);
        if (EMC1001_Read(0xff, &data)) printf("Revision : %d\n", data);
        
        if (EMC1001_Read(TEMP_HI, (uint8_t*)&temp)) {
            EMC1001_Read(TEMP_LO, &templo);     // get lsb 
            templo = templo >> 6;                   
            if (temp < 0) templo = 3-templo;    // complement to 1 if T negative
            printf("\nThe temperature is: %d.%d C\n", temp, templo*25);
        }

        if (EMC1001_Read(4, &data)) printf("\nThe Conversion rate is: %x\n", data);
        if (EMC1001_Read(5, &data)) printf("The high limit is: %d C\n", data);
        if (EMC1001_Read(7, &data)) printf("The low limit is: %d C\n", data);
            
        __delay_ms(1000);
    }
}
