#include "config.h"
#include "uart.h"
#include "eeprom.h"

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "BitIO.h"


int main(void) {
	char buffer[80];
	uint8_t byte;
	
	// Init components (UART, EEPROM, ...)
	uartInit();
	eepromInit();

	// Initial pause (EEPROM needs 5ms startup time)
	_delay_ms(100);


	// Write message via UART
	uartPutString("Hello\r\n");
	
	address_t addr = 0x42;

	eepromSetWriteMode();

	// Disable SDP?
	
	//uartPutString("Now writing SDP disable sequence...\r\n");

	//eepromWriteByte(0x5555, 0xAA);
	//eepromWriteByte(0x2AAA, 0x55);
	//eepromWriteByte(0x5555, 0x80);
	//eepromWriteByte(0x5555, 0xAA);
	//eepromWriteByte(0x2AAA, 0x55);
	//eepromWriteByte(0x5555, 0x20);

	uartPutString("Enter data: ");
	uartGetLine(buffer, 80);

	addr = 0x20;

	for (int i = 0; i < 80; i++ ) {
		eepromWriteByte(addr+i, buffer[i]);

		if (buffer[i] == '\0') {
			break;
		}
	}

	// TODO Implement polling


	//_eepromWrite(0x20, 0x42);
	//_eepromWrite(0x21, 0xAA);
	//_eepromWrite(0x22, 0xBB);


	//_delay_ms(1);

	eepromSetReadMode();

	uartPutString("Reading: ");
	addr = 0x20;

	while(1) {
		//uartPutString("Reading: ");

		byte = eepromReadByte(addr);

		//itoa(byte, buffer, 16);
		//uartPutString(buffer);
		//uartPutString("\r\n");

		if (byte == 0) {
			uartPutString("\r\n");
			addr = 0x20;
			_delay_ms(1000);
			continue;
		}

		uartPutChar(byte);

		addr++;

		//_delay_ms(1000);
	
		//uartGetLine(buffer, 80);

//		char buffer[80];
//		int readLength;
//		uint8_t byte;
//
//		eepromSetReadMode();
//		byte = eepromReadByte(addr);
//
//		uartPutString("0x42: ");
//		itoa(byte, buffer, 10);
//		uartPutString(buffer);
//		uartPutString("\r\n");
//
//		uartPutString("Write to 0x42 (length): ");
//		readLength = uartGetLine(buffer, 80);
//
//		eepromSetWriteMode();
//		eepromWriteByte(addr, readLength);
//
//		uartPutString("Writing to 0x42: ");
//		itoa(readLength, buffer, 10);
//		uartPutString(buffer);
//		uartPutString("\r\n");

		
		//readLength = uartGetChar();

		//shiftAddress(readLength);

		//shiftAddress(crap);
		//_delay_ms(100);
	}
}

