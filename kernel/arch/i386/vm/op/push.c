#include <kernel/vm/vm.h>
#include <kernel/def.h>

uint8_t vm_op_push(t_vm *dxvm)
{
  --(dxvm->sp);
  (dxvm->mem)[dxvm->sp] = (dxvm->mem)[++(dxvm->ip) % VM_MEM_SIZE];
  return (KSUCCESS);
}
