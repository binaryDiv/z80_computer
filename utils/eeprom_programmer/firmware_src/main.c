#include "config.h"
#include "uart.h"
#include "eeprom.h"
#include "protocol.h"

#include <util/delay.h>

int main(void) {
	// Init components (UART, EEPROM, ...)
	uartInit();
	eepromInit();

	// Initial pause (EEPROM needs 5ms startup time)
	_delay_ms(100);

	// Write initial message via UART
	uartPutString("INFO -- EEPROM programmer by binaryDiv\r\n");
	
	while(1) {
		// Run main loop endlessly
		protocolMainLoop();
	}
}

