#include "memory.h"

uint8_t memory[0x10000];

uint8_t memory_read(uint16_t addr) { return memory[addr]; }

void memory_write(uint16_t addr, uint8_t value) { memory[addr] = value; }
