#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_popb(t_vm *dxvm)
{
  if (dxvm->sp == VM_MEM_SIZE)
    return (VM_STAT_FATAL);
  (dxvm->reg)[1] = (dxvm->mem)[(dxvm->sp)];
  ++(dxvm->sp);
  return (KSUCCESS);
}
