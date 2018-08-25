################
# CONFIGURATION
################

# Compiler and tools
CC = avr-gcc
OBJCOPY = avr-objcopy

# Compiler and linker flags
CFLAGS = -Wall -std=c11 -Os
LDFLAGS = 

# Target platform and programmer
GCC_MCU = atmega16a
AVRDUDE_PARTNO = m16
AVRDUDE_PROGRAMMER = usbtiny

# Make target and object files
TARGET = eepprog
OBJECTS = main.o uart.o eeprom.o protocol.o
HEADERS = config.h BitIO.h uart.h eeprom.h protocol.h

# Default target (build hex file)
all: hex


################
# BUILD TARGETS
################

# Shortcuts for build targets
hex: $(TARGET).hex
elf: $(TARGET).elf

# Convert elf binary to ihex format
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex

# Elf binary
$(TARGET).elf: $(OBJECTS)
	$(CC) -mmcu=$(GCC_MCU) $(LDFLAGS) -o $(TARGET).elf $(OBJECTS)

# Object files
%.o: %.c $(HEADERS)
	$(CC) -mmcu=$(GCC_MCU) $(CFLAGS) -c -o $@ $<


##############
# PROGRAMMING
##############

# Program controller
program: writeflash

writeflash: $(TARGET).hex
	sudo avrdude -p $(AVRDUDE_PARTNO) -c $(AVRDUDE_PROGRAMMER) -U flash:w:$(TARGET).hex

readfuse:
	sudo avrdude -p $(AVRDUDE_PARTNO) -c $(AVRDUDE_PROGRAMMER) -U lfuse:r:m -U hfuse:r:m

writefuse:
	sudo avrdude -p $(AVRDUDE_PARTNO) -c $(AVRDUDE_PROGRAMMER) -U lfuse:w:0xef:m -U hfuse:w:0xd9:m


################
# OTHER TARGETS
################

# Clean generated files
clean:
	rm -f $(OBJECTS) $(TARGET).elf $(TARGET).hex


.PHONY: all hex elf program writeflash clean

