#include "cpu.h"
#include <stdint.h>
#include <string.h>

void cpu_init(struct CPU *cpu) { memset(cpu, 0, sizeof(*cpu)); }

void cpu_reset(struct CPU *cpu) {
  memset(cpu, 0, sizeof(struct CPU));

  cpu->AF = 0x01B0;
  cpu->BC = 0x0013;
  cpu->DE = 0x00D8;
  cpu->HL = 0x014D;

  cpu->SP = 0xFFFE;
  cpu->PC = 0x0100;
}
