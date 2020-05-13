UNITY_ROOT=/usr/lib/unity
PRJ = adcToLcd
BD = ../builds
FD = $(BD)/firmware
TD = $(BD)/tests
OD = ./obj
HEX = $(FD)/$(PRJ).hex
ELF = $(FD)/$(PRJ).elf
AVR_CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE    = avr-size --format=avr --mcu=$(MCU)

TEST_CC = gcc
SRC=$(wildcard *.c) $(wildcard ./inc/*.c)
OBJS = $(SRC:.c=.o)
TEST_INC = -I$(UNITY_ROOT)/src -Iinc
SRC_TEST = $(UNITY_ROOT)/src/unity.c tests/test_runners/test_calculation_runner.c tests/test_calculation.c ./inc/calculate.c 

MCU = atmega328p
CLK = 8000000
AVR_CFLAGS = -Wall -Os -DF_CPU=$(CLK) -mmcu=$(MCU)

TEST_CFLAGS += -g 
TEST_CFLAGS += -Wall
TEST_CFLAGS += -DUNITY_DOUBLE_PRECISION=0.001f
TEST_CFLAGS += -DUNITY_INCLUDE_DOUBLE
TEST_CFLAGS += -std=c89
TEST_CFLAGS += -Wall
TEST_CFLAGS += -Wextra
TEST_CFLAGS += -Wpointer-arith
TEST_CFLAGS += -Wcast-align
TEST_CFLAGS += -Wwrite-strings
TEST_CFLAGS += -Wswitch-default
TEST_CFLAGS += -Wunreachable-code
TEST_CFLAGS += -Winit-self
TEST_CFLAGS += -Wmissing-field-initializers
TEST_CFLAGS += -Wno-unknown-pragmas
TEST_CFLAGS += -Wstrict-prototypes
TEST_CFLAGS += -Wundef
TEST_CFLAGS += -Wold-style-definition

program: $(HEX)

$(HEX): $(ELF)
	rm -f $(HEX)
	$(OBJCOPY) -j .text -j .data -O ihex $(ELF) $(HEX)
	$(SIZE) $(ELF)

$(ELF): $(OBJS)
	mv *.o $(OD)
	$(AVR_CC) $(AVR_CFLAGS) -o $(ELF) $(OD)/*.o

$(OBJS): $(SRC)
	$(AVR_CC) $(AVR_CFLAGS) -c $(SRC)
	
tests: $(TD)/$(PRJ)

$(TD)/$(PRJ): $(SRC_TEST)
	$(TEST_CC) $(TEST_CFLAGS) $(TEST_INC) $(SRC_TEST) -o $(TD)/$(PRJ) -lm

clean:
	rm -rf $(OD)/* $(FD)/*.elf $(FD)/*.hex $(TD)/* ./*.o $(TOD)/*.o

tests/test_runners/test_calculation_runner.c: tests/test_calculation.c
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb tests/test_calculation.c  tests/test_runners/test_calculation_runner.c
