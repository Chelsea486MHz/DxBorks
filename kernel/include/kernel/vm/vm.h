#ifndef VM_H_INCLUDED
#define VM_H_INCLUDED

#include <stdint.h>
#include <kernel/def.h>

#define REG_NB   0x04 /* 4 registers */
#define MEM_SIZE 0xFF /* 256 bytes of memory */

typedef struct s_vm t_vm;
struct s_vm
{
  uint8_t reg[REG_NB];
  uint8_t mem[MEM_SIZE];
} __attribute__((packed)); /* Pack the struct to save memory */

t_kstat vm_init(void);

#endif
