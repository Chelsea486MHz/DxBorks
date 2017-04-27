#include <kernel/vm/vm.h>
#include <kernel/tty.h>
#include <kernel/def.h>
#include <libk/libk.h>

/* The VM itself */
static t_vm dxvm;

/* Opcode table */
t_kstat (*vm_op_tab[])(t_vm *dxvm) =
{
  vm_op_nop
};

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
  uint32_t cycle;
  t_kstat vmstat;

  cycle = 0;
  tty_puts("[DxVM] Virtual Machine beggining program execution...\n");
  while ((vmstat = vm_op_tab[dxvm.mem[dxvm.ip]](&dxvm)) != VM_STAT_STOP)
  {
    ++dxvm.ip;              /* Increment the instruction pointer */
    dxvm.ip %= VM_MEM_SIZE; /* Increment the instruction pointer */
    ++cycle;
    if (cycle == VM_DUMP_CYCLE)
    {
      tty_puts("[DxVM] Execution stopped at cycle ");
      tty_putn(cycle);
      tty_puts(", dumping memory:\n");
      vm_dumpmem(&dxvm);
      vmstat = VM_STAT_DUMP;
      break;
    }
  }
  return (vmstat);
}
