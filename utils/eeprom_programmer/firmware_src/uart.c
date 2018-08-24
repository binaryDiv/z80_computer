#include "config.h"
#include "uart.h"

#include <avr/io.h>
#include <util/setbaud.h>

// Initialize UART
void uartInit() {
	// Set Baud register
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;

	// Reset status register
	UCSRA = 0x00;

#if USE_2X
	// U2X mode necessary
	UCSRA |= (1 << U2X);
#else
	// U2X mode not necessary
	UCSRA &= ~(1 << U2X);
#endif
	
	// Enable transmitter and receiver
	UCSRB |= (1 << TXEN) | (1 << RXEN);
	
	// Set frame format (8 bit)
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

// Transmit a single character
void uartPutChar(unsigned char data) {
	// Block until controller is ready to send
	while (!(UCSRA & (1 << UDRE))) {
	}
	
	// Write character to UART data register
	UDR = data;
}

// Transmit a string
void uartPutString(char* data) {
	// Write characters until \0 is reached
	while (*data) {
		uartPutChar(*data++);
	}
}

// Receive a single character (blocking)
unsigned char uartGetChar() {
	// Block until a character has been received
	while (!(UCSRA & (1 << RXC))) {
	}
	
	// Get character and return
	return UDR;
}

// Receive a string until \n (blocking)
uint8_t uartGetLine(char* buffer, uint8_t maxLength) {
	uint8_t readChars = 0;
	unsigned char nextChar;

	// Read a maximum of maxLength-1 characters (-1 because we need one char for '\0')
	while (readChars < maxLength - 1) {
		// Get next character
		nextChar = uartGetChar();

		// Skip trailing \n and \r
		if (nextChar == '\n' || nextChar == '\r') {
			if (readChars == 0) {
				// Skip trailing \n and \r
				continue;
			}
			else {
				// End line (do not append the \r or \n to the buffer)
				break;
			}
		}

		// Write character to buffer
		*buffer++ = nextChar;
		
		// Increment counter
		readChars++;
	}
	
	// Write a terminating '\0' byte
	*buffer++ = '\0';

	// Return number of read bytes (excluding the \0)
	return readChars;
}

