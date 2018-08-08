#ifndef UART_H_
#define UART_H_

#include "config.h"
#include <avr/io.h>

// Initialize UART
void uartInit();

// Transmit a single character
void uartPutChar(unsigned char data);

// Transmit a string
void uartPutString(char* data);

// Read a single character (blocking)
unsigned char uartGetChar();

// Read a string until \n (blocking)
uint8_t uartGetLine(char* buffer, uint8_t maxLength);

#endif /* UART_H_ */
