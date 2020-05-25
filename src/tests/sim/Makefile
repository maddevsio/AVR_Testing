SIMAVR = /home/oxide/simavr
BOARD = adcToLcd
FIRMWARE = main_wrapper
AVR-GCC = avr-gcc
MCU = atmega1284
CLC = 8000000
SRC_DIR = ../..

FIRMWARE_SRC = $(wildcard $(SRC_DIR)/inc/*.c) $(FIRMWARE).c
PARTS = parts

OBJ = obj-${shell $(CC) -dumpmachine}

BOARD_CFLAGS	=  -std=c99 -MMD -O2 -Wall -Wextra -Wno-unused-parameter \
		-Wno-unused-result -Wno-missing-field-initializers \
		-Wno-sign-compare -g -fPIC \
		-Wl,-rpath,-$(SIMAVR)/simavr/obj-x86_64-linux-gnu

BOARD_LDFLAGS = -lpthread -L$(SIMAVR)/simavr/obj-x86_64-linux-gnu -lsimavr -lm -lelf

AVR_FLAGS = -Wall -gdwarf-2 -Os -std=gnu99 \
			-mmcu=$(MCU) \
			-DF_CPU=$(CLC) \
			-fno-inline-small-functions \
			-ffunction-sections -fdata-sections \
			-Wl,--relax,--gc-sections \
			-Wl,--undefined=_mmcu,--section-start=.mmcu=0x910000 \
			

AVR_LDFLAGS = -lm 

BOARD_IPATH = -I. \
			-I.. \
			-I$(PARTS) \
			-I${SIMAVR}/include \
			-I${SIMAVR}/simavr/sim \

FIRMWARE_IPATH = -I$(SIMAVR)/simavr/sim/avr/ -I$(SRC_DIR)/inc/ -I$(SRC_DIR)

TARGET = ${OBJ}/${BOARD}.tst

VPATH = . $(PARTS)


sim-test: obj $(FIRMWARE).elf $(TARGET) link

link: $(TARGET) $(FIRMWARE).elf
	@rm -rf $(BOARD)
	@ln -s $(TARGET) $(BOARD)

${TARGET} : ${OBJ}/hd44780.o
${TARGET} : ${OBJ}/${BOARD}.o


$(FIRMWARE).elf : $(FIRMWARE_SRC)
	$(AVR-GCC) $(FIRMWARE_IPATH) $(AVR_FLAGS) ${^} -o ${@} $(AVR_LDFLAGS)

${OBJ}/%.o: %.c
	$(CC) $(BOARD_IPATH) ${BOARD_CFLAGS} $< -c -o $@

${OBJ}/%.tst:
	$(CC) $(BOARD_IPATH) ${BOARD_CFLAGS} -o $@ ${filter %.o,$^} ${BOARD_LDFLAGS} 

obj: ${OBJ}

${OBJ}:
	@mkdir -p ${OBJ}

clean:
	rm -rf *.elf ${TARGET} $(BOARD) $(OBJ)
