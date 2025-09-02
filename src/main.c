#include "cpu.h"
#include "memory.h"
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    FILE *rom = fopen(argv[1], "rb");
    if (!rom) {
        return 1;
    }
    fread(memory, 1, 0x8000, rom);
    fclose(rom);

    struct CPU cpu;
    cpu_reset(&cpu);

    while (1) {
        uint16_t pc_before = cpu.PC;
        uint8_t opcode = memory_read(cpu.PC++);

        switch (opcode) {
        case 0x00: // NOP
            break;
        case 0xC3: {
            uint8_t low = memory_read(cpu.PC++);
            uint8_t high = memory_read(cpu.PC++);
            uint16_t addr = (high << 8) | low;
            cpu.PC = addr;
            break;
        }
        case 0xAF:
            cpu.A ^= cpu.A;
            cpu.F = 0x80;
            break;
        case 0x21:
            uint8_t low = memory_read(cpu.PC++);
            uint8_t high = memory_read(cpu.PC++);
            cpu.HL = (high << 8) | low;
            break;
        case 0x0E:
            cpu.C = memory_read(cpu.PC++);
            break;
        case 0x06:
            cpu.B = memory_read(cpu.PC++);
            break;
        case 0x32:
            memory_write(cpu.HL, cpu.A);
            cpu.HL--;
            break;
        default:
            printf("Unimplemented opcode %02X at 0x%04X\n", opcode, pc_before);
            return 1;
        }
    }
}
