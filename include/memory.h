#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

extern uint8_t memory[0x10000];

uint8_t memory_read(uint16_t addr);
void memory_write(uint16_t addr, uint8_t val);

#endif
