#include <kernel/def.h>
#include <kernel/tty.h>
#include <kernel/main.h>
#include <kernel/panic.h>

#include <math/math.h>
#include <math/fact.h>
#include <math/pow.h>
#include <math/exp.h>

#include <ascii.h>
#include <vga.h>

void self_test(void)
{
  tty_puts("exp(-1)     = "); tty_putn(exp(-1)); tty_putc(ASCII_NEWLINE);
  tty_puts("exp(0)      = "); tty_putn(exp(0)); tty_putc(ASCII_NEWLINE);
  tty_puts("exp(1)      = "); tty_putn(exp(1)); tty_putc(ASCII_NEWLINE);
  /*
  tty_puts("fastexp(-1) = "); tty_putn(fastexp(-1)); tty_putc(ASCII_NEWLINE);
  tty_puts("fastexp(0)  = "); tty_putn(fastexp(0)); tty_putc(ASCII_NEWLINE);
  tty_puts("fastexp(1)  = "); tty_putn(fastexp(1)); tty_putc(ASCII_NEWLINE);
  */
  tty_puts("0!          = "); tty_putn(fact(0)); tty_putc(ASCII_NEWLINE);
  tty_puts("1!          = "); tty_putn(fact(1)); tty_putc(ASCII_NEWLINE);
  tty_puts("2!          = "); tty_putn(fact(2)); tty_putc(ASCII_NEWLINE);
  tty_puts("3!          = "); tty_putn(fact(3)); tty_putc(ASCII_NEWLINE);
  tty_puts("4!          = "); tty_putn(fact(4)); tty_putc(ASCII_NEWLINE);
  tty_puts("5!          = "); tty_putn(fact(5)); tty_putc(ASCII_NEWLINE);
  tty_puts("6!          = "); tty_putn(fact(6)); tty_putc(ASCII_NEWLINE);
  tty_set_colour(tty_map_colour(VGA_GREEN, VGA_BLACK));
  tty_puts("Self test completed, please check the results.\n");
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
}
