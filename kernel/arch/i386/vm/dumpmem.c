#include <kernel/tty.h>
#include <kernel/vm/vm.h>
#include <libk/size_t.h>
#include <libk/stdint.h>
#include <ascii.h>
#include <vga.h>

static void dump_entry(const uint8_t add, const uint8_t val)
{
  tty_set_colour(tty_map_colour(VGA_RED, VGA_BLACK));
  tty_putn_hex2(add);
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_putc(':');
  tty_set_colour(tty_map_colour(VGA_BLUE, VGA_BLACK));
  tty_putn_hex2(val);
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_putc(ASCII_SPACE);
}

void vm_dumpmem(const t_vm *dxvm)
{
  size_t i;
  size_t j;

  tty_puts("--- MEMORY DUMP ---\n");
  i = 0;
  while (i < VM_MEM_SIZE / 8)
  {
    j = 0;
    while (j < 8 && (i * 8) + j < VM_MEM_SIZE)
    {
      dump_entry((i * 8) + j, dxvm->mem[(i * 8) + j]);
      ++j;
    }
    ++i;
  }
  tty_puts("--- MEMORY DUMP ---\n");
}
