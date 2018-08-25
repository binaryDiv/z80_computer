#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#include "config.h"
#include "protocol.h"

#include "uart.h"
#include "eeprom.h"

// Reads, parses and executes next command
void parseNextCommand();

// Runs main loop to parse commands
void protocolMainLoop();

#endif /* PROTOCOL_H_ */
