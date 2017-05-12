#include <kernel/main.h>
#include <kernel/tty.h>
#include <kernel/panic.h>
#include <kernel/serial.h>
#include <kernel/def.h>
#include <kernel/idt.h>
#include <kernel/kb.h>
#include <kernel/vm/vm.h>

#include <ascii.h>

void kernel_main(void)
{
  tty_init();
  idt_init();
  keyboard_init();
  serial_init(SERIAL_PORT_0);
  serial_init(SERIAL_PORT_1);
  serial_init(SERIAL_PORT_2);
  serial_init(SERIAL_PORT_3);
  vm_init();
  tty_puts(WELCOME_BANNER"\n");

  tty_puts("Initiating self-test...\n");
  self_test();
  serial_write(SERIAL_PORT_0, "Hello, world!", 13);
  tty_puts("Hello, world!\n");
  vm_exec();
  /*kernel_panic(PANIC_NOTHING, __FILE__, __LINE__);*/
}
