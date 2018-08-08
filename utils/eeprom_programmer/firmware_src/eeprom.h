#ifndef EEPROM_H_
#define EEPROM_H_

#include "config.h"
#include <avr/io.h>

// Define macro for NOP instruction
#define _NOP() __asm__ __volatile__ ("nop");

// Define type for (to be shifted) addresses
typedef uint16_t address_t;

// Define address length
// TODO 15 or 16?
#define ADDRESS_LENGTH 15

// Macros for IO pins
#define EEP_ADDR_LOW_PORT  PORTC
#define EEP_ADDR_LOW_DDR   DDRC
#define EEP_ADDR_HIGH_PORT PORTB
#define EEP_ADDR_HIGH_DDR  DDRB

#define EEP_DATA_PORT      PORTA
#define EEP_DATA_PIN       PINA
#define EEP_DATA_DDR       DDRA

#define EEP_CTRL_PORT      PORTD
#define EEP_CTRL_DDR       DDRD
#define EEP_CTRL_BIT_CE    PD2
#define EEP_CTRL_BIT_OE    PD3
#define EEP_CTRL_BIT_WE    PD4

// Initialize EEPROM
void eepromInit();

// Enable read mode (set data direction registers and enable output)
void eepromSetReadMode();

// Enable write mode (set data direction registers)
void eepromSetWriteMode();

// Read byte (assumes we're in read mode)
uint8_t eepromReadByte(address_t address);

// Write byte (assumes we're in write mode)
void eepromWriteByte(address_t address, uint8_t data);

#endif /* EEPROM_H_ */
