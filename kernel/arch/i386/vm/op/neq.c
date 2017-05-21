#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_neq(t_vm *dxvm)
{
  dxvm->flag = ((dxvm->reg)[0] != (dxvm->reg)[1] ? 1 : 0);
  return (VM_STAT_RUN);
}
