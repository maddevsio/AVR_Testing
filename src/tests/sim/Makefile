SIMAVR = /home/oxide/simavr

BOARD = board_adcToTemp
FIRMWARE = main_adcToTemp

MCU = atmega8
CLC = 8000000
SRC_DIR = ../..
BOARD_SRC = ../..
FIRMWARE_SRC = $(wildcard $(SRC_DIR)/inc/*.c) main_adcToTemp.c

PARTS = parts

OBJ = obj-${shell $(CC) -dumpmachine}

BOARD_CFLAGS	= -O2 -Wall -Wextra -Wno-unused-parameter \
		-Wno-unused-result -Wno-missing-field-initializers \
		-Wno-sign-compare \
		-g
BOARD_LDFLAGS = -lpthread -lsimavr -lm -lelf

AVR_FLAGS = -Wall -gdwarf-2 -Os -std=gnu99 \
			-mmcu=$(MCU) \
			-DF_CPU=$(CLC) \
			-fno-inline-small-functions \
			-ffunction-sections -fdata-sections \
			-Wl,--relax,--gc-sections \
			-Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 

AVR_LDFLAGS = -lm


BOARD_IPATH = -I. \
		-I$(PARTS) \
		-I${SIMAVR}/include \
		-I${SIMAVR}/simavr/sim 

FIRMWARE_IPATH = -I$(SIMAVR)/simavr/sim/avr/ -I../../inc

TARGET = ${OBJ}/${BOARD}.tst

VPATH = . $(PARTS)


sim-test: obj $(FIRMWARE).elf $(TARGET) link

link: $(TARGET) $(FIRMWARE).elf
	@rm -rf $(BOARD)
	@ln -s $(TARGET) $(BOARD)

${TARGET} : ${OBJ}/hd44780.o
${TARGET} : ${OBJ}/${BOARD}.o


$(FIRMWARE).elf : $(FIRMWARE_SRC)
	avr-gcc $(FIRMWARE_IPATH) $(AVR_FLAGS) ${^} -o ${@} $(AVR_LDFLAGS)

${OBJ}/%.o: %.c
	$(CC) $(BOARD_IPATH) ${BOARD_CFLAGS} -MMD $< -c -o $@

${OBJ}/%.tst:
	$(CC) $(BOARD_IPATH) -MMD -o $@ ${filter %.o,$^} ${BOARD_LDFLAGS} 

obj: ${OBJ}

${OBJ}:
	@mkdir -p ${OBJ}

clean:
	rm -rf *.elf ${TARGET} ${OBJ} $(BOARD)
