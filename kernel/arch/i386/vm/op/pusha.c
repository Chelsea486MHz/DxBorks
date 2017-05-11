#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_pusha(t_vm *dxvm)
{
  --(dxvm->sp);
  (dxvm->mem)[dxvm->sp] = (dxvm->reg)[0];
  return (KSUCCESS);
}
