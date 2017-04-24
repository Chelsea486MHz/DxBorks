#include <kernel/vm/vm.h>
#include <kernel/def.h>

t_kstat vm_op_nop(t_vm *dxvm)
{
  (void)dxvm;
  /* Does nothing and consumes a cycle */
  return (KSUCCESS);
}
