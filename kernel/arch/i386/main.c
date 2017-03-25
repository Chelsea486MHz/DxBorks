#include <kernel/main.h>
#include <kernel/tty.h>
#include <kernel/panic.h>
#include <kernel/serial.h>
#include <kernel/def.h>
#include <kernel/idt.h>
#include <kernel/kb.h>

void kernel_main(void)
{
  tty_init();
  idt_init();
  keyboard_init();
  serial_init(SERIAL_PORT_0);

  tty_puts(WELCOME_BANNER);

  serial_write(SERIAL_PORT_0, "Hello, world!", 13);
  /*kernel_panic(PANIC_NOTHING, __FILE__, __LINE__);*/
}
