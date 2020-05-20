#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include <pthread.h>
#include "sim_avr.h"
#include "avr_ioport.h"
#include "sim_elf.h"
#include "hd44780.h"


avr_t * avr = NULL;
hd44780_t hd44780;

static void * avr_run_thread(void * ignore){
	while (1) {
		avr_run(avr);
	}
	return 0;
}


int
main(int argc,char *argv[])
{
	elf_firmware_t f;
	const char * fname = "main_adcToTemp.elf";
	elf_read_firmware(fname, &f);
	printf("firmware %s f=%d mmcu=%s\n", fname, (int) f.frequency, f.mmcu);
	avr = avr_make_mcu_by_name(f.mmcu);

	if (!avr) {
		fprintf(stderr, "%s: AVR '%s' not known\n", argv[0], f.mmcu);
		exit(1);
	}

	avr_init(avr);
	avr_load_firmware(avr, &f);


	hd44780_init(avr, &hd44780, 16, 2);

	for (int i = 0; i < 4; i++) {
		avr_irq_t * iavr = avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('D'), i);
		avr_irq_t * ilcd = hd44780.irq + IRQ_HD44780_D4 + i;
		avr_connect_irq(iavr, ilcd);
		avr_connect_irq(ilcd, iavr);
	}
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('C'), 0),
			hd44780.irq + IRQ_HD44780_RS);
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('C'), 2),
			hd44780.irq + IRQ_HD44780_E);
	avr_connect_irq(
			avr_io_getirq(avr, AVR_IOCTL_IOPORT_GETIRQ('C'), 1),
			hd44780.irq + IRQ_HD44780_RW);

	pthread_t run;
	pthread_create(&run, NULL, avr_run_thread, NULL);

}
