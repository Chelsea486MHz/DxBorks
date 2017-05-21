#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_cjmp(t_vm *dxvm)
{
  if (dxvm->flag)
    dxvm->ip = dxvm->mem[((dxvm->ip)+1) % VM_MEM_SIZE] % VM_MEM_SIZE;
  return (VM_STAT_RUN);
}
