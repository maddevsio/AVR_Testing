
#include "inc/calculate.h" // Тестируемый функционал
#include <stdio.h>
#ifdef TEST //Если задана директива TEST, то добавляем библиотеку с тестами
    #include "tests/test.h"
#else // Иначе добавляем библиотеки общения с периферией, инициализируем переменные и тд.
#include "inc/adc.h"
#include "inc/lcd.h"
    #define ADC_PIN 1
    uint16_t adcValue;
    float temperature;

#endif

int main(void)
{
    #ifdef TEST // Запускаем тесты если задана директива TEST
    RUN_TESTS();
    
    #else // Иначе инициализируем АЦП, ЖК экран и считываем, выводим температуру на дисплей
    adcInit();
    lcdInit();
    for(;;){
        char temp[10] = {0};
        adcValue = adcRead(ADC_PIN);
        temperature = adcToTemp(adcValue);   
        sprintf(temp, "%f", temperature); 
        lcdPrintLn(temp);
    }

    #endif
}
