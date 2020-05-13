#include "calculate.h"
#include <stdio.h>
#include <math.h>
#define A_CONST  0.00112485
#define B_CONST  0.000234822
#define C_CONST  0.000000085
#define KELVIN  273.15

double resistance;
double logRes;
double tempKelvin;
double tempCel;

double adcToTemp(uint16_t adcVal){

	resistance=((10230000/adcVal) - 10000);
	logRes = log(resistance);

    tempKelvin = 1 / (A_CONST + ( B_CONST * logRes) + ( C_CONST * pow(logRes,3)));
	tempCel = tempKelvin - KELVIN;
	return tempCel;
}