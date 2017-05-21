#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_nop(t_vm *dxvm)
{
  (void)dxvm;
  /* Does nothing and consumes a cycle */
  return (VM_STAT_RUN);
}
