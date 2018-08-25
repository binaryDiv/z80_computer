#include "config.h"
#include "protocol.h"

#include "uart.h"
#include "eeprom.h"

#include <string.h>
// #include <util/delay.h>

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
		// TODO ...
		uartPutString("TESTREAD not implemented yet\r\n");

		//uartPutString("Reading: ");
		//byte = eepromReadByte(addr);
		//itoa(byte, buffer, 16);
		//uartPutString(buffer);
		//uartPutString("\r\n");
		//if (byte == 0) {
		//	uartPutString("\r\n");
		//	addr = 0x20;
		//	_delay_ms(1000);
		//	continue;
		//}
		//uartPutChar(byte);

		//addr++;
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

