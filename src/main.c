#include "lcd.h"
#include "adc.h"
#include "calculate.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

double tempetarure = 0;
char buffer[10] = {0};
uint16_t adc = 0;

int main()
{
	adcInit();
	lcd_init();
	while (1) {
		adc = adcRead(0);
		tempetarure = adcToTemp(adc);
		dtostrf(tempetarure,6,2,buffer);
		lcd_print(buffer, 0 ,0 );
	}
}
