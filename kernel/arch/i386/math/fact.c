#include <libk/stdint.h>
#include <math/math.h>
#include <math/fact.h>

#include <kernel/tty.h>

uint32_t fact(const uint8_t x)
{
  if (x > 11)
  {
    tty_puts("[");
    tty_set_colour(tty_map_colour(VGA_RED, VGA_BLACK));
    tty_puts("FAILED");
    tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
    tty_puts("] Error: trying to compute a value greater than 11!, aborting");
  }
  #if (MATH_FASTFACT == 1)
  uint32_t _fact_table[12] =
  {
    1,
    1,
    2,
    6,
    24,
    120,
    720,
    5040,
    40320,
    362880,
    3628800,
    39916800
  };
  return (_fact_table[x]);
  #else
  uint32_t res;
  uint8_t i;

  res = 1;
  i = 0;
  while (i <= x)
    res *= (i++);
  return (res);
  #endif
}
