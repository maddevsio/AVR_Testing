#include "adc-temp_testCase.c"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "sim_avr.h"
#include "avr_ioport.h"
#include "avr_adc.h"
#include "sim_elf.h"
#include "sim_cycle_timers.h"
#include "hd44780.h"
#include <math.h>
#define CASE_SIZE 100
#define ADC_CONST 4.882813
#define TEMP_DEVIATION 1.5
const char * firmware = "main_wrapper.elf";
uint8_t adcCounter = 0;
avr_irq_t * adcPortPin;
avr_t * avr;
hd44780_t hd44780;
uint32_t lcdTimer = 50000;
bool simulationCompleted = false;
double deviationTest[CASE_SIZE];
bool testPassed = true;


uint16_t adcToVoltages(uint16_t adc){ 
	double millivolts = adc * ADC_CONST;
	return round(millivolts);
}

static void setConnections(void){
	//Command pins
	for (int i = 0; i < 4; i++) {
		avr_irq_t * iavr = avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), i);
		avr_irq_t * ilcd = hd44780.irq + IRQ_HD44780_D4 + i;
		// AVR -> LCD
		avr_connect_irq(iavr, ilcd);
		// LCD -> AVR
		avr_connect_irq(ilcd, iavr);
	}
	//Data pins
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), 4),
			hd44780.irq + IRQ_HD44780_RS);
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), 5),
			hd44780.irq + IRQ_HD44780_RW); 
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), 6),
			hd44780.irq + IRQ_HD44780_E);
	//ADC pin
	adcPortPin = avr_io_getirq(avr, AVR_IOCTL_ADC_GETIRQ , ADC_IRQ_ADC0);
}

static avr_cycle_count_t lcdDataGathering(avr_t * avr, avr_cycle_count_t when,void * param)
{	

 if (adcCounter > 0){
	double calculatedValue = hd44780_print(&hd44780);
	double actualValue = calcCase.temperature[adcCounter - 1];
	deviationTest[adcCounter] = calculatedValue - actualValue;
 }	
	if (!simulationCompleted){
	avr_raise_irq(adcPortPin, adcToVoltages( calcCase.adcVal[adcCounter]));
	adcCounter++;
	avr_cycle_timer_register_usec(avr, lcdTimer, lcdDataGathering, NULL);
	if (adcCounter == CASE_SIZE) {
		simulationCompleted = true;
	}
}
	return 0;
}

void firmwareInit(const char * fname, char * argv){
	elf_firmware_t f;
	elf_read_firmware(fname, &f);
	printf("firmware %s f=%d mmcu=%s\n", fname, (int) f.frequency, f.mmcu);
	avr = avr_make_mcu_by_name(f.mmcu);
	if (!avr) {
		fprintf(stderr, "%s: AVR '%s' not known\n", argv, f.mmcu);
		exit(1);
	}
	avr_init(avr);
	avr_load_firmware(avr, &f);
}

bool run_test(void){
	for (int i = 0; i<CASE_SIZE - 1; i++){
		if (fabs(deviationTest[i]) > TEMP_DEVIATION ){return false;}
	}
	return true;
}

int main(int argc,	char *argv[])
{
	firmwareInit(firmware,argv[0]);
	hd44780_init(avr, &hd44780, 16, 2);
	setConnections();
	avr_cycle_timer_register_usec(avr, lcdTimer, lcdDataGathering, NULL);
	while (!simulationCompleted){
		avr_run(avr);
	}

	if (run_test())
	{
		printf("TEST PASSED.\n");
	}
	else{
		printf("TEST FAILED.\n");
	}
	
	
}
