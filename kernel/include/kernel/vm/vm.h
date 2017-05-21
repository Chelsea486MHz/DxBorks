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

#define VM_DUMPMEM_ENTRIES_PER_LINE 13
#define VM_DUMPREGS 0 /* vm_dumpmem() umps the register values when set to 1 */

typedef struct s_vm t_vm;
struct s_vm
{
  uint8_t ip; /* instruction pointer */
  uint16_t sp; /* Stack pointer. Extended to a 16bits variable to allow the use of the address 0x100 */
  uint8_t st; /* Status register */
  uint8_t flag : 1; /* Flag register used by comparison instructions */

  uint8_t reg[VM_REG_NB]; /* GP registers */

  uint8_t mem[VM_MEM_SIZE]; /* memory */
} __attribute__((packed)); /* Pack the struct to save memory */

/* VM operations */
uint8_t vm_op_nop   (t_vm *dxvm);
uint8_t vm_op_add   (t_vm *dxvm);
uint8_t vm_op_sub   (t_vm *dxvm);
uint8_t vm_op_xor   (t_vm *dxvm);
uint8_t vm_op_or    (t_vm *dxvm);
uint8_t vm_op_not   (t_vm *dxvm);
uint8_t vm_op_and   (t_vm *dxvm);
uint8_t vm_op_lshift(t_vm *dxvm);
uint8_t vm_op_rshift(t_vm *dxvm);
uint8_t vm_op_loada (t_vm *dxvm);
uint8_t vm_op_loadb (t_vm *dxvm);
uint8_t vm_op_loadc (t_vm *dxvm);
uint8_t vm_op_loadd (t_vm *dxvm);
uint8_t vm_op_push  (t_vm *dxvm);
uint8_t vm_op_pusha (t_vm *dxvm);
uint8_t vm_op_pushb (t_vm *dxvm);
uint8_t vm_op_pushc (t_vm *dxvm);
uint8_t vm_op_pushd (t_vm *dxvm);
uint8_t vm_op_popa  (t_vm *dxvm);
uint8_t vm_op_popb  (t_vm *dxvm);
uint8_t vm_op_popc  (t_vm *dxvm);
uint8_t vm_op_popd  (t_vm *dxvm);
uint8_t vm_op_jmp   (t_vm *dxvm);
uint8_t vm_op_cjmp  (t_vm *dxvm);
uint8_t vm_op_stop  (t_vm *dxvm);
uint8_t vm_op_eq    (t_vm *dxvm);
uint8_t vm_op_neq   (t_vm *dxvm);
uint8_t vm_op_less  (t_vm *dxvm);
uint8_t vm_op_great (t_vm *dxvm);
uint8_t vm_op_inc   (t_vm *dxvm);
uint8_t vm_op_dec   (t_vm *dxvm);
uint8_t vm_op_disp  (t_vm *dxvm);

t_kstat vm_init(void);
t_kstat vm_exec(void);
t_kstat vm_load(void);
void vm_dumpmem(const t_vm *dxvm);

#endif
