#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_sub(t_vm *dxvm)
{
  (dxvm->reg)[0] -= (dxvm->reg)[1];
  return (VM_STAT_RUN);
}
