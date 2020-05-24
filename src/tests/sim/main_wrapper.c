
#undef F_CPU
#define F_CPU 8000000

#include "avr_mcu_section.h"

#define VCC 5000
#define AVCC 5000
#define AREF 5000

AVR_MCU(F_CPU, "atmega1284");
AVR_MCU_VOLTAGES(VCC, AVCC, AREF);

#include "../../main.c"