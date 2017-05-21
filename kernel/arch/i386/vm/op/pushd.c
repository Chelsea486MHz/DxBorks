#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_pushd(t_vm *dxvm)
{
  --(dxvm->sp);
  (dxvm->mem)[dxvm->sp] = (dxvm->reg)[3];
  return (VM_STAT_RUN);
}
