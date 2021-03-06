#include "test.h"
#include <assert.h>
#include <stdio.h>
struct CalcTestCase
{
    uint16_t adcVal[100];
    double temperature[100];
};


struct CalcTestCase calcCase = {
.adcVal=  
 {
10, 20, 30, 40, 50, 60, 70, 80, 90, 100
 ,110, 120, 130, 140, 150, 160, 170, 180, 190, 200
 , 210, 220, 230, 240, 250, 260, 270, 280, 290, 300
 , 310, 320, 330, 340, 350, 360, 370, 380, 390, 400
 , 410, 420, 430, 440, 450, 460, 470, 480, 490, 500
 , 510, 520, 530, 540, 550, 560, 570, 580, 590, 600
 , 610, 620, 630, 640, 650, 660, 670, 680, 690, 700
 , 710, 720, 730, 740, 750, 760, 770, 780, 790, 800
 , 810, 820, 830, 840, 850, 860, 870, 880, 890, 900
 , 910, 920, 930, 940, 950, 960, 970, 980, 990 
 },
 .temperature = 
 {
-55.609, -45.834, -39.719, -35.168, 
-31.5, -28.4, -25.699, -23.293, -21.116,
-19.12, -17.27, -15.544233, -13.92, -12.383,
-10.923, -9.528, -8.190, -6.904, -5.662,
-4.461, -3.295, -2.162, -1.058,0.019407,
1.073, 2.106, 3.120, 4.116, 5.096, 6.061,
7.014, 7.955, 8.885, 9.806, 10.719535, 11.624763,
12.523, 13.415, 14.304, 15.188, 16.069,
16.948, 17.825, 18.7, 19.576, 20.452, 
21.331, 22.209, 23.091, 23.974, 24.865, 
25.756, 26.656, 27.56, 28.47, 29.391, 
30.317, 31.255, 32.203, 33.157, 34.129, 
35.11, 36.108, 37.122, 38.152, 39.198, 
40.268, 41.353, 42.464, 43.601, 44.764, 
45.954, 47.178, 48.432, 49.723, 51.06, 
52.439, 53.861, 55.339, 56.876, 58.478, 
60.149, 61.897, 63.74, 65.676, 67.73, 
69.917, 72.237, 74.748, 77.460, 80.410, 
83.642, 87.215, 91.284, 95.869, 101.222, 
107.639, 115.620, 125.990 
}
 };

double temperatureDeviation = 0.12;





void RUN_TESTS(void){
 test_AdcCalc();   
    
}


void test_AdcCalc(void){
    uint8_t adc_caseSize = sizeof(calcCase.adcVal)/sizeof(calcCase.adcVal[0]);
    printf("Actual value:Calculated value:Deviation\n");

    for (int i = 0; i<adc_caseSize-1;i++){
            double calcResult = adcToTemp(calcCase.adcVal[i]);
            assert(test_DivEqual(calcResult, temperatureDeviation, calcCase.temperature[i]));       
            printf("%f:%f:%f\n",calcCase.temperature[i],calcResult,calcCase.temperature[i]-calcResult);  
    }
     printf("CALCULATION TEST PASSED.\n");

}


bool test_DivEqual( double testVal, double diviation, double value){
    if (((testVal <= value + diviation) && (testVal >= value - diviation))) { 
        return true; 
    }
    else
    {
        return false;
    }
}