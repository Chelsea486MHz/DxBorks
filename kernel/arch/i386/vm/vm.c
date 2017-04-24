#include <kernel/vm/vm.h>
#include <kernel/tty.h>
#include <kernel/def.h>
#include <libk/libk.h>

static t_vm dxvm;

t_kstat vm_init(void)
{
  memset((void*)&dxvm, 0, sizeof(t_vm)); /* Zero out the VM and its registers/memory */

  tty_puts("[  ");
  tty_set_colour(tty_map_colour(VGA_GREEN, VGA_BLACK));
  tty_puts("OK");
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_puts("  ] VM initialized\n");
  return (KSUCCESS);
}

t_kstat vm_exec(void)
{
  t_kstat vmstat;
  while ((vmstat = vm_op_tab[dxvm.ip](&dxvm)) != VM_STAT_STOP)
  {
    ++dxvm.ip;              /* Increment the instruction pointer */
    dxvm.ip %= VM_MEM_SIZE; /* Increment the instruction pointer */
  }
  return (vmstat);
}
