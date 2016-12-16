#include <kernel/main.h>
#include <kernel/tty.h>
#include <kernel/panic.h>
#include <kernel/serial.h>
#include <kernel/def.h>
#include <kernel/idt.h>

void kernel_main(void)
{
  tty_init();
  idt_init();
  serial_init(SERIAL_PORT_0);
  tty_puts(WELCOME_BANNER);
}
