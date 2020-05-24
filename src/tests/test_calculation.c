#include "calculate.h"
#include "unity.h"
#include "adc-temp_testCase.c"
double temperatureDeviation = 0.13;

void setUp(void)
{
}
  
void tearDown(void)
{
}

void test_adcToTemp(void)
{
int8_t caseSize = sizeof(calcCase.adcVal)/sizeof(calcCase.adcVal[0]);
#ifdef PRINT_CASES
    printf("Actual:calculated temperature.");
#endif

for (int i = 0; i < caseSize - 1; i++){
    double actualTemp = calcCase.temperature[i];
    double calculatedTemp = adcToTemp(calcCase.adcVal[i]);
    #ifdef PRINT_CASES
        printf("%f:%f\n",actualTemp,calculatedTemp);
    #endif
    TEST_ASSERT_DOUBLE_WITHIN(temperatureDeviation, actualTemp, calculatedTemp);
}
}