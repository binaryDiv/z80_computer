#include "config.h"
#include "eeprom.h"

#include <avr/io.h>
#include <util/delay.h>
#include "BitIO.h"

// Initialize EEPROM
void eepromInit() {
	// Set initial value for control port (all disabled -- INVERTED VALUES, ~CE, ~OE, ~WE)
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_CE);
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_OE);
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_WE);

	// Set data direction register for control port
	EEP_CTRL_DDR |= (1 << EEP_CTRL_BIT_CE)
	             |  (1 << EEP_CTRL_BIT_OE)
	             |  (1 << EEP_CTRL_BIT_WE);

	// Set initial value for address (0x0000)
	EEP_ADDR_LOW_PORT  = 0x00;
	EEP_ADDR_HIGH_PORT = 0x00;

	// Set data direction register for address ports
	EEP_ADDR_LOW_DDR  = 0xFF;
	EEP_ADDR_HIGH_DDR = 0xFF;

	// Set data direction register and initial value for IO port (initialize in reading mode)
	EEP_DATA_PORT = 0x00;
	EEP_DATA_DDR  = 0x00;
}

// Enable read mode (set data direction registers and enable output)
void eepromSetReadMode() {
	// Reset control bits (shouldn't be necessary, but let's be safe)
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_CE);
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_OE);
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_WE);

	// Set data pins as input, reset PORT to disable pullups
	EEP_DATA_PORT = 0x00;
	EEP_DATA_DDR  = 0x00;
}

// Enable write mode (set data direction registers)
void eepromSetWriteMode() {
	// Reset control bits (shouldn't be necessary, but let's be safe)
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_CE);
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_OE);
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_WE);

	// Set data pins as output, reset data port
	EEP_DATA_PORT = 0x00;
	EEP_DATA_DDR  = 0xFF;
}

// Set address
static inline void eepromSetAddress(address_t address) {
	// Set low and high address bytes
	// (We actually only have 15 bit, the 16th will just be ignored)
	EEP_ADDR_LOW_PORT  = address & 0xFF;
	EEP_ADDR_HIGH_PORT = address >> 8;
}

// Read byte (assumes we're in read mode)
uint8_t eepromReadByte(address_t address) {
	// Assume we're in read mode

	// Set address
	eepromSetAddress(address);

	// Latch address
	BIT_CLEAR(&EEP_CTRL_PORT, EEP_CTRL_BIT_CE);
	BIT_CLEAR(&EEP_CTRL_PORT, EEP_CTRL_BIT_OE);

	// 1 tick = 62.5 ns, EEPROM access time is 150 ns.
	// 2 NOPs seem to be sufficient, but let's be sure.
	_NOP();
	_NOP();
	_NOP();

	// Get data
	uint8_t byte = EEP_DATA_PIN;

	// Reset ~OE, ~CE
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_OE);
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_CE);

	// Read and return data byte
	return byte;
}

// Write byte (assumes we're in write mode)
void eepromWriteByte(address_t address, uint8_t data) {
	// Assume we're in write mode

	// Set address
	eepromSetAddress(address);

	// Falling edge: latch address
	BIT_CLEAR(&EEP_CTRL_PORT, EEP_CTRL_BIT_CE);
	BIT_CLEAR(&EEP_CTRL_PORT, EEP_CTRL_BIT_WE);

	// Set data byte
	EEP_DATA_PORT = data;

	// Data setup time (50ns)
	_NOP();

	// Rising edge: latch data, start write cycle
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_WE);
	BIT_SET(&EEP_CTRL_PORT, EEP_CTRL_BIT_CE);

	// Write pulse width high (50ns)
	_NOP();
}

