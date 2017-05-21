#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_popd(t_vm *dxvm)
{
  if (dxvm->sp == VM_MEM_SIZE)
    return (VM_STAT_FATAL);
  (dxvm->reg)[3] = (dxvm->mem)[(dxvm->sp)];
  ++(dxvm->sp);
  return (VM_STAT_RUN);
}
