#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_stop(t_vm *dxvm)
{
  (void)dxvm;
  return (VM_STAT_STOP);
}
