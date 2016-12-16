#include <kernel/libk.h>

size_t memset(char *dst, const char val, const size_t len)
{
  size_t i;

  i = 0;
  while (i < len)
    dst[i++] = val;
  return (i);
}
