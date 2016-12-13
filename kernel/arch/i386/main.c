#include <kernel/main.h>
#include <kernel/tty.h>
#include <kernel/panic.h>

void kernel_main(void)
{
  tty_init();
  kernel_panic(PANIC_NOTHING, __FILE__, __LINE__);
}
