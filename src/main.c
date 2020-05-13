
#include "inc/calculate.h" 
#include <stdio.h>
#include "inc/adc.h"
#include "inc/lcd.h"

#define ADC_PIN 1
uint16_t adcValue;
float temperature;


int main(void)
{
    adcInit();
    lcdInit();
    for(;;){
        char temp[10] = {0};
        adcValue = adcRead(ADC_PIN);
        temperature = adcToTemp(adcValue);   
        sprintf(temp, "%f", temperature); 
        lcdPrintLn(temp);
    }
}
