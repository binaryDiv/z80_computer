#include "config.h"
#include "protocol.h"

#include "uart.h"
#include "eeprom.h"

#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

// Reads, parses and executes next command
void parseNextCommand() {
	const int bufferLength = 80;
	char buffer[bufferLength];

	// Read next command
	int readChars = uartGetLine(buffer, bufferLength);

	// Check if line is non-empty and has been read completely
	if (readChars == 0) {
		return;
	}
	else if (readChars >= bufferLength-1) {
		// Reading was aborted after bufferLength-1 characters to prevent
		// buffer overflow.
		// TODO Actually this isn't quite correct: if exactly bufferLen-1
		//      characters have been read including the \n, this could be
		//      true as well... test this?
		uartPutString("ERROR buffer overflow while reading line\r\n");
		return;
	}

	// Parse command
	if (strcmp(buffer, "HELLO") == 0) {
		// HELLO command: initializes connection
		uartPutString("OHAI\r\n");
	}
	else if(strcmp(buffer, "TESTREAD") == 0) {
		// TESTREAD command: for testing purposes, reads a few bytes and
		// returns them in a human readable format

		uint8_t byte;
		char outBuffer[20];

		eepromSetReadMode();

		for (int i = 0x00; i < 0x20; i++) {
			itoa(i, outBuffer, 16);
			uartPutString("TESTREAD 0x");
			uartPutString(outBuffer);
			uartPutString(": ");

			byte = eepromReadByte(i);
			itoa(byte, outBuffer, 16);

			uartPutChar(byte);
			uartPutString(" (0x");
			uartPutString(outBuffer);
			uartPutString(")\r\n");
		}
	}
	else if(strcmp(buffer, "TESTWRITE") == 0) {
		// TESTWRITE command: for testing purposes, writes a few bytes

		char str[] = "Ohai world";
		address_t addr = 0x00;

		eepromSetWriteMode();

		for (char* p = str; *p != '\0'; p++) {
			eepromWriteByte(addr, *p);
			//_delay_ms(100);
			addr++;
		}

		// TODO necessary?
		_delay_ms(100);

		uartPutString("TESTWRITE success\r\n");
	}
	else {
		// unknown command: return error message
		uartPutString("ERROR invalid command\r\n");
	}
}

// Runs main loop to parse commands
void protocolMainLoop() {
	while(1) {
		// Parse next command
		parseNextCommand();
	}
}

