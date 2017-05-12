#include <kernel/tty.h>
#include <kernel/vm/vm.h>
#include <libk/size_t.h>
#include <libk/stdint.h>
#include <ascii.h>
#include <vga.h>

static void dump_entry(const uint8_t add, const uint8_t val)
{
  tty_set_colour(tty_map_colour(VGA_RED, VGA_BLACK));
  tty_putn_hex2_short(add);
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_putc(':');
  tty_set_colour(tty_map_colour(VGA_BLUE, VGA_BLACK));
  tty_putn_hex2_short(val);
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_putc(ASCII_SPACE);
}

void vm_dumpmem(const t_vm *dxvm)
{
  size_t x;
  size_t y;

  tty_puts("--- MEMORY DUMP ---");
  y = 0;
  while (y < (VM_MEM_SIZE / (VM_DUMPMEM_ENTRIES_PER_LINE-1)))
  {
    tty_putc(ASCII_NEWLINE);
    x = 0;
    while (x < VM_DUMPMEM_ENTRIES_PER_LINE && (y * VM_DUMPMEM_ENTRIES_PER_LINE) + x < VM_MEM_SIZE)
    {
      dump_entry((y * VM_DUMPMEM_ENTRIES_PER_LINE) + x, dxvm->mem[(y * VM_DUMPMEM_ENTRIES_PER_LINE) + x]);
      ++x;
    }
    ++y;
  }
  #if VM_DUMPREGS == 1
  tty_puts("Registers:\n");
  tty_puts("%a:  "); tty_putn_hex2(dxvm->reg[0]); tty_putc(ASCII_NEWLINE);
  tty_puts("%b:  "); tty_putn_hex2(dxvm->reg[1]); tty_putc(ASCII_NEWLINE);
  tty_puts("%c:  "); tty_putn_hex2(dxvm->reg[2]); tty_putc(ASCII_NEWLINE);
  tty_puts("%d:  "); tty_putn_hex2(dxvm->reg[3]); tty_putc(ASCII_NEWLINE);
  tty_puts("%sp: "); tty_putn_hex2(dxvm->sp); tty_putc(ASCII_NEWLINE);
  tty_puts("%ip: "); tty_putn_hex2(dxvm->ip); tty_putc(ASCII_NEWLINE);
  #endif
  tty_puts("--- MEMORY DUMP ---\n");
}
