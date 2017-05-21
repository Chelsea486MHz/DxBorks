#include <kernel/vm/vm.h>
#include <kernel/def.h>
#include <kernel/tty.h>

uint8_t vm_op_disp(t_vm *dxvm)
{
  ++(dxvm->ip);
  tty_putc((dxvm->mem)[dxvm->ip]);
  return (VM_STAT_RUN);
}
