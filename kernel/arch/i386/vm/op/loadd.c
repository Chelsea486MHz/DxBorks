#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_loadd(t_vm *dxvm)
{
  (dxvm->reg)[3] = (dxvm->mem)[++(dxvm->ip)];
  return (KSUCCESS);
}
