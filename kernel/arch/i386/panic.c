#include <kernel/def.h>
#include <kernel/tty.h>
#include <kernel/panic.h>

void kernel_panic(const uint8_t err, const char *file, const size_t line)
{
  tty_set_colour(tty_map_colour(VGA_WHITE, VGA_RED));
  tty_clear();
  tty_puts(WELCOME_BANNER);
  tty_puts("\n\n\nKERNEL PANIC /!\\\n");
  tty_puts("Gordon Ramsay cannot locate the lamb sauce!\n");
  tty_puts("File name: ");
  tty_puts(file);
  tty_puts("\nLine: ");
  tty_putn(line);
  tty_puts("\nError code: ");
  tty_putn(err);
  tty_puts("\n\nHalting execution and disabling interrupts.\n");
  tty_puts("Please report this error to garuda1@protonmail.com");
  __asm__("cli;hlt");
}
