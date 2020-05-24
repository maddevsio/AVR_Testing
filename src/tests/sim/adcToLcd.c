#include "adc-temp_testCase.c"
#include <stdlib.h>
#include <stdio.h>
#include "sim_avr.h"
#include "avr_ioport.h"
#include "avr_adc.h"
#include "sim_elf.h"
#include "sim_cycle_timers.h"
#include "hd44780.h"
#include <math.h>

#define ADC_CONST 4.882813
uint8_t adcCounter = 0;


avr_t * avr = NULL;
hd44780_t hd44780;
uint32_t lcdTimer = 100000;

uint16_t adcToVoltages(uint16_t adc){
	double millivolts = adc * ADC_CONST;
	return round(millivolts);
}

static void setConnections(void){
	for (int i = 0; i < 4; i++) {
		avr_irq_t * iavr = avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), i);
		avr_irq_t * ilcd = hd44780.irq + IRQ_HD44780_D4 + i;
		// AVR -> LCD
		avr_connect_irq(iavr, ilcd);
		// LCD -> AVR
		avr_connect_irq(ilcd, iavr);
	}
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), 4),
			hd44780.irq + IRQ_HD44780_RS);
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), 5),
			hd44780.irq + IRQ_HD44780_RW); 
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), 6),
			hd44780.irq + IRQ_HD44780_E);
}



static avr_cycle_count_t lcdPrint(avr_t * avr,avr_cycle_count_t when,void * param)
{	
	
 if (adcCounter > 0){
	double calculatedValue;
	double actualValue = calcCase.temperature[adcCounter - 1];
	calculatedValue =  hd44780_print(&hd44780);
	printf("%f",calculatedValue-actualValue);
 }

	avr_raise_irq(avr_io_getirq(avr, AVR_IOCTL_ADC_GETIRQ , ADC_IRQ_ADC0), \
	 adcToVoltages( calcCase.adcVal[adcCounter]));
	adcCounter++;
	if (adcCounter == sizeof(calcCase.adcVal)/sizeof(calcCase.adcVal[0])){
		adcCounter = 0;
	}


	avr_cycle_timer_register_usec(avr, lcdTimer, lcdPrint, NULL);
	return 0;
}


int
main(
		int argc,
		char *argv[])
{
	elf_firmware_t f;
	const char * fname = "main_wrapper.elf";
	elf_read_firmware(fname, &f);

	printf("firmware %s f=%d mmcu=%s\n", fname, (int) f.frequency, f.mmcu);

	avr = avr_make_mcu_by_name(f.mmcu);
	if (!avr) {
		fprintf(stderr, "%s: AVR '%s' not known\n", argv[0], f.mmcu);
		exit(1);
	}
	avr_init(avr);
	avr_load_firmware(avr, &f);
	avr_irq_t * adc0 = avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('C'), 0);
	avr_cycle_timer_register_usec(avr, lcdTimer, lcdPrint, adc0);
	hd44780_init(avr, &hd44780, 16, 2);

	setConnections();

	while (1){
		avr_run(avr);
	}
	
}
