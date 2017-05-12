#include <kernel/vm/vm.h>
#include <kernel/def.h>
#include <kernel/tty.h>

uint8_t vm_op_push(t_vm *dxvm)
{
  --(dxvm->sp);
  (dxvm->mem)[dxvm->sp] = (dxvm->mem)[++(dxvm->ip)];
  return (KSUCCESS);
}
