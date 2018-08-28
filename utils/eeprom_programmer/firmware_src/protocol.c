#include "config.h"
#include "protocol.h"

#include "uart.h"
#include "eeprom.h"

#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

// Splits a command "CMD ARGS" to two strings "CMD" and "ARGS". Returns pointer
// to "ARGS" or NULL if no arguments were found. Changes the input string!
char* tokenizeCommand(char* cmd) {
	if (cmd == NULL) {
		return NULL;
	}

	// Search for a space character
	for (char* p = cmd; *p != '\0'; p++) {
		if (*p == ' ') {
			// Split strings by replacing the space by \0, then return pointer
			// to command arguments
			*p++ = '\0';
			return p;
		}
	}

	// No space character found: command has no arguments, return NULL
	return NULL;
}

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

	// Tokenize command
	char* cmd = buffer;
	char* args = tokenizeCommand(cmd);

	// Parse command
	if (strcmp(cmd, "HELLO") == 0) {
		// HELLO command: initializes connection
		uartPutString("OHAI\r\n");
	}
	else if (strcmp(cmd, "READ") == 0) {
		// READ command: takes a hex address or address range as argument,
		// reads data and returns them in hexadecimal ASCII format.

		// Check if arguments exist
		if (args == NULL) {
			uartPutString("ERROR READ needs an address\r\n");
			return;
		}

		// Parse address(es)
		// TODO
		uartPutString(args);

		// Read...
		// TODO
	}
	else if (strcmp(cmd, "TESTREAD") == 0) {
		// TESTREAD command: for testing purposes, reads a few bytes and
		// returns them in a human readable format.

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
	else if (strcmp(cmd, "TESTWRITE") == 0) {
		// TESTWRITE command: for testing purposes, writes a few bytes

		char str[] = "Ohai world";
		address_t addr = 0x00;

		char* writeStr = str;
		if (args != NULL) {
			writeStr = args;
		}

		eepromSetWriteMode();

		// write input line instead of static string
		for (char* p = writeStr; *p != '\0'; p++) {
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

