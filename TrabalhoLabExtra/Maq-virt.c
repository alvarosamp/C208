#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


static inline uint8_t extract_op(uint32_t inst) { return (inst >> 26) & 0x3F; }
static inline uint8_t extract_rs(uint32_t inst) { return (inst >> 21) & 0x1F; }
static inline uint8_t extract_rt(uint32_t inst) { return (inst >> 16) & 0x1F; }
static inline uint8_t extract_rd(uint32_t inst) { return (inst >> 11) & 0x1F; }
static inline int16_t extract_imm(uint32_t inst) { return (int16_t)(inst & 0xFFFF); }
static inline uint8_t extract_funct(uint32_t inst) { return inst & 0x3F; }

#define MIPS_TEXT_ADDR 0x00400000

typedef struct {
    uint8_t *text;
    int32_t mem[1024]; // Memória para simulação
} mem_t;

typedef struct {
    uint32_t regs[32];
    uint32_t pc;
    mem_t *mem;
} vm_t;

// Função para carregar uma palavra da memória de texto
static inline uint32_t mem_text_lw(mem_t* mem, uint32_t addr) {
    uint8_t* ptr = mem->text + (addr - MIPS_TEXT_ADDR);
    return (ptr[0] << 24) | (ptr[1] << 16) | (ptr[2] << 8) | ptr[3];
}

static void fail(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

// Função para imprimir o estado dos registradores
void print_registers(vm_t* vm) {
    printf("Registradores relevantes:\n");
    printf(" $t0 ($8) = %d\n", vm->regs[8]);
    printf(" $t1 ($9) = %d\n", vm->regs[9]);
    printf(" PC = 0x%08X\n", vm->pc);
    printf("-------------------------\n");
}

void step(vm_t* vm) {
    uint32_t inst = mem_text_lw(vm->mem, vm->pc);
    printf("Instrução na PC=0x%08X: 0x%08X\n", vm->pc, inst); // Linha de depuração
    vm->pc += 4;

    uint8_t op = extract_op(inst);
    uint32_t* regs = vm->regs;

    switch (op) {
    case 0x09: { // ADDIU
        uint8_t rs = extract_rs(inst);
        uint8_t rt = extract_rt(inst);
        int16_t imm = extract_imm(inst);
        regs[rt] = regs[rs] + imm;
        printf("ADDIU: $%d = $%d + %d -> %d\n", rt, rs, imm, regs[rt]);
    } break;

    case 0x00: { //(SUBU)
        uint8_t funct = extract_funct(inst);
        if (funct == 0x23) { // SUBU
            uint8_t rs = extract_rs(inst);
            uint8_t rt = extract_rt(inst);
            uint8_t rd = extract_rd(inst);
            regs[rd] = regs[rs] - regs[rt];
            printf("SUBU: $%d = $%d - $%d -> %d\n", rd, rs, rt, regs[rd]);
        }
    } break;

    case 0x2B: { // SW
        uint8_t rs = extract_rs(inst);
        uint8_t rt = extract_rt(inst);
        int16_t offset = extract_imm(inst);
        if ((regs[rs] + offset) / 4 < 0 || (regs[rs] + offset) / 4 >= 1024) {
            fail("Endereço de memória inválido para SW");
        }
        vm->mem->mem[(regs[rs] + offset) / 4] = regs[rt];
        printf("SW: Mem[%d] = $%d -> %d\n", (regs[rs] + offset) / 4, rt, regs[rt]);
    } break;

    case 0x05: { // BNE
        uint8_t rs = extract_rs(inst);
        uint8_t rt = extract_rt(inst);
        int16_t offset = extract_imm(inst);
        printf("BNE: Offset extraído = %d\n", offset); // Linha de depuração
        if (regs[rs] != regs[rt]) {
            vm->pc += offset * 4; 
            printf("BNE: $%d != $%d, jump para 0x%08X\n", rs, rt, vm->pc);
        } else {
            printf("BNE: $%d == $%d, condição satisfeita. $t0 atingiu zero.\n", rs, rt);
        }
    } break;

    default:
        fail("Opcode inválido");
    }

    // Imprimir o estado dos registradores após cada instrução
    print_registers(vm);
}

int main() {
    int i;
    // Programa MIPS com instruções codificadas (BNE corrigido)
    uint8_t program[] = {
        0x24, 0x08, 0xFE, 0xC0, // addiu $t0, $zero, -320
        0x24, 0x09, 0xFF, 0xB0, // addiu $t1, $zero, -80
        0x01, 0x09, 0x40, 0x23, // subu $t0, $t0, $t1 
        0xAC, 0x08, 0x00, 0x00, // sw $t0, 0($zero)
        0x15, 0x00, 0xFF, 0xFD  // bne $t0, $zero, label 
    };

    mem_t mem = { .text = program };
    vm_t vm = { .mem = &mem, .pc = MIPS_TEXT_ADDR };

    // Inicializar registradores
    for (i = 0; i < 32; ++i) {
        vm.regs[i] = 0;
    }

    printf("Início da simulação:\n");
    printf("-------------------------\n");

   
    for (i = 0; i < 12; ++i) {
        printf("Passo %d:\n", i + 1);
        step(&vm);
        if (vm.regs[8] == 0) { // $t0 é o registrador 8
            printf("$t0 atingiu zero. Encerrando a simulação.\n");
            break;
        }
    }

    printf("Estado Final:\n");
    printf("$t0 = %d\n", vm.regs[8]);
    printf("$t1 = %d\n", vm.regs[9]);
    printf("Mem[0] = %d\n", mem.mem[0]);
    return 0;
}
