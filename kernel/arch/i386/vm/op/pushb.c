#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_pushb(t_vm *dxvm)
{
  --(dxvm->sp);
  (dxvm->mem)[dxvm->sp] = (dxvm->reg)[1];
  return (VM_STAT_RUN);
}
