#include <kernel/vm/vm.h>
#include <kernel/tty.h>
#include <kernel/def.h>
#include <libk/libk.h>

/* The VM itself */
static t_vm dxvm;

/* Opcode table */
uint8_t (*vm_op_tab[])(t_vm *dxvm) =
{
  vm_op_nop,
  vm_op_add,
  vm_op_sub,
  vm_op_xor,
  vm_op_or,
  vm_op_not,
  vm_op_and,
  vm_op_lshift,
  vm_op_rshift,
  vm_op_loada,
  vm_op_loadb,
  vm_op_loadc,
  vm_op_loadd,
  vm_op_push,
  vm_op_pusha,
  vm_op_pushb,
  vm_op_pushc,
  vm_op_pushd,
  vm_op_popa,
  vm_op_popb,
  vm_op_popc,
  vm_op_popd
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
  uint8_t vmstat;

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
