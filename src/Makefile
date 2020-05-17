PRJ = adcToLcd
BD = ../builds
FD = $(BD)/firmware
TD = $(BD)/tests
HEX = $(FD)/$(PRJ).hex
ELF = $(FD)/$(PRJ).elf
AVR_CC = avr-gcc
OBJCOPY = avr-objcopy
SIZE    = avr-size --format=avr --mcu=$(MCU)
SRC = main.c $(wildcard inc/*.c)
INC = -Iinc

UNITY_ROOT=/usr/lib/unity
TEST_CC = gcc
TEST_INC = -I$(UNITY_ROOT)/src -Iinc
TEST_SRC = $(UNITY_ROOT)/src/unity.c tests/test_runners/*_runner.c tests/*.c ./inc/calculate.c 

MCU = atmega328p
CLK = 8000000
AVR_CFLAGS = -Wall -Os -DF_CPU=$(CLK) -mmcu=$(MCU)

TEST_CFLAGS += -g 
TEST_CFLAGS += -Wall
TEST_CFLAGS += -DUNITY_DOUBLE_PRECISION=0.001f
TEST_CFLAGS += -DUNITY_INCLUDE_DOUBLE
TEST_CFLAGS += -std=c99
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
TEST_CFLAGS += -DPRINT_CASES

program: $(HEX)

$(HEX): $(ELF)
	rm -f $(HEX)
	$(OBJCOPY) -j .text -j .data -O ihex $(ELF) $(HEX)
	$(SIZE) $(ELF)

$(ELF): $(SRC)
	$(AVR_CC) $(INC) $(AVR_CFLAGS) $(SRC) -o $(ELF)
	
tests: $(TD)/$(PRJ)

$(TD)/$(PRJ): $(TEST_SRC)
	$(TEST_CC) $(TEST_CFLAGS) $(TEST_INC) $(TEST_SRC) -o $(TD)/$(PRJ) -lm

clean:
	rm -rf $(FD)/*.elf $(FD)/*.hex $(TD)/*

tests/test_runners/%_runner.c: tests/%.c
	ruby $(UNITY_ROOT)/auto/generate_test_runner.rb tests/%.c  tests/test_runners/%_runner.c

