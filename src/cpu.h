#ifndef CPU_H
#define CPU_H

#include <stdint.h>

struct CPU {
  union {
    struct {
      uint8_t F;
      uint8_t A;
    };
    uint16_t AF;
  };

  union {
    struct {
      uint8_t C;
      uint8_t B;
    };
    uint16_t BC;
  };

  union {
    struct {
      uint8_t E;
      uint8_t D;
    };
    uint16_t DE;
  };

  union {
    struct {
      uint8_t L;
      uint8_t H;
    };
    uint16_t HL;
  };

  uint16_t SP; // Stack Pointer
  uint16_t PC; // Program Counter
};

void cpu_reset(struct CPU *cpu);

#endif
