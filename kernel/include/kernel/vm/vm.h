#ifndef VM_H_INCLUDED
#define VM_H_INCLUDED

#include <stdint.h>
#include <kernel/def.h>

#define VM_REG_NB       4  /* 4 registers */
#define VM_MEM_SIZE   256  /* 256 bytes of memory */
#define VM_DUMP_CYCLE 128

#define VM_STAT_RUN   0x00 /* Keep the VM running */
#define VM_STAT_STOP  0x01 /* Stop the VM */
#define VM_STAT_FATAL 0x02 /* Stop the VM and undergo a kernel panic */
#define VM_STAT_DUMP  0x03 /* Stp the VM and dump memory */

typedef struct s_vm t_vm;
struct s_vm
{
  uint8_t ip; /* instruction pointer */
  uint8_t reg[VM_REG_NB];
  uint8_t mem[VM_MEM_SIZE];
} __attribute__((packed)); /* Pack the struct to save memory */

/* VM operations */
t_kstat vm_op_nop(t_vm *dxvm);

t_kstat vm_init(void);
t_kstat vm_exec(void);
void vm_dumpmem(const t_vm *dxvm);

#endif
