PRJ = adcToLcd
BD = ../builds
FD = $(BD)/firmware
TD = $(BD)/tests
OD = ./obj
HEX = $(FD)/$(PRJ).hex
ELF = $(FD)/$(PRJ).elf
AVR_CC = avr-gcc
TEST_CC = gcc
SRC=$(wildcard *.c) $(wildcard ./inc/*.c)
OBJS = $(SRC:.c=.o)
SRC_TEST = main.c ./inc/calculate.c ./tests/test.c
TOD = ./test_obj

MCU = atmega328p
CLK = 8000000
AVR_CFLAGS = -Wall -Os -DF_CPU=$(CLK) -mmcu=$(MCU)
TEST_CFLAGS = -g -D TEST
OBJCOPY = avr-objcopy
SIZE    = avr-size --format=avr --mcu=$(MCU)

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

$(TD)/$(PRJ): $(TOD)/*.o
	$(TEST_CC) $(TEST_CFLAGS) -o $(TD)/$(PRJ) $(TOD)/*.o -lm
	
$(TOD)/*.o: $(SRC_TEST)
	$(TEST_CC) $(TEST_CFLAGS) -c $(SRC_TEST)
	mv *.o $(TOD)/

clean:
	rm -rf $(OD)/* $(FD)/*.elf $(FD)/*.hex $(TD)/* ./*.o $(TOD)/*.o

