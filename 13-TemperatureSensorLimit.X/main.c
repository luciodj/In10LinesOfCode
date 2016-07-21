/**
    EMC1001 Temperature Sensor demo
    (uses I2C module and on-board EMC1001 sensor)
    
    File Name         :  main.c

    Device            :  PIC16F18855
    Compiler          :  XC8 1.37
    MPLAB             :  MPLAB X 3.35
*/

#include "mcc_generated_files/mcc.h"

#define EMC1001_ADDRESS     0x38   // SMB device address

bool EMC1001_Read(uint8_t reg, uint8_t *pData)
{
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    static I2C2_TRANSACTION_REQUEST_BLOCK trb[2];
    
    I2C2_MasterWriteTRBBuild(&trb[0], &reg, 1, EMC1001_ADDRESS);
    I2C2_MasterReadTRBBuild(&trb[1], pData, 1, EMC1001_ADDRESS);                
    I2C2_MasterTRBInsert(2, &trb[0], &status);  // 2 transactions W + R
    
    while(status == I2C2_MESSAGE_PENDING);      // blocking

    return (status == I2C2_MESSAGE_COMPLETE); 
} 

bool EMC1001_Write(uint8_t reg, uint8_t data)
{
    uint8_t buffer[2];
    buffer[0] = reg; buffer[1] = data;
    I2C2_MESSAGE_STATUS status = I2C2_MESSAGE_PENDING;
    static I2C2_TRANSACTION_REQUEST_BLOCK trb;
    
    I2C2_MasterWriteTRBBuild(&trb, buffer, 2, EMC1001_ADDRESS);
    I2C2_MasterTRBInsert(1, &trb, &status); // 1 transaction W 
    
    while(status == I2C2_MESSAGE_PENDING);      // blocking

    return (status == I2C2_MESSAGE_COMPLETE); 
} 

// EMC1001 registers
#define EMC_TEMP_HI     0x00        // temperature value high byte 
#define EMC_STATUS      0x01        // Status register
#define EMC_TEMP_LO     0x02        // low byte containing 1/4 deg fraction
#define EMC_CONFIG      0x03        // configuration register  
#define EMC_LIMIT       0x20        // THERM limit temperature (->ALARM1)
#define EMC_HIST        0x21        // THERM hysteresis
#define EMC_PROD_ID     0xFD        // Product ID
#define EMC_MANUF_ID    0xFE        // Manufacturer ID
#define EMC_REVISION    0xFF        // Revision 

void main(void)
{
    uint8_t data;
    int8_t  temp;
    uint8_t templo;

    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
        
    EMC1001_Write(EMC_LIMIT, 28);   // set the THERM limit 
    EMC1001_Write(EMC_HIST,  2);    // reduce the hysteresis
    
    while (1) {
        printf("\x0C");   // comment out if terminal does not support Form Feed
        puts("Temperature Sensor Demo\n");
        if (EMC1001_Read(EMC_PROD_ID, &data)) 
            printf("Product ID: EMC1001%s\n", data ? "-1" : "");
        if (EMC1001_Read(EMC_MANUF_ID, &data)) 
            printf("Manufacturer ID: 0x%X\n", data);
        if (EMC1001_Read(EMC_REVISION, &data)) 
            printf("Revision : %d\n", data);
        
        if (EMC1001_Read(EMC_TEMP_HI, (uint8_t*)&temp)) {
            EMC1001_Read(EMC_TEMP_LO, &templo);     // get lsb 
            templo = templo >> 6;                   
            if (temp < 0) templo = 3-templo;    // complement to 1 if T negative
            printf("\nThe temperature is: %d.%d C\n", temp, templo*25);
        }

        if (EMC1001_Read(EMC_STATUS, (uint8_t*)&temp)) {
            if (temp & 1) 
                puts("ALARM1: The temperature is above the set limit!");
            else 
                puts("The temperature is below the set limit");
        }
            
        __delay_ms(1000);
    }
}
