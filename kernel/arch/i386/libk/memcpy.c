#include <libk/libk.h>

size_t memcpy(char *dst, const char *src, const size_t len)
{
  size_t i;

  i = 0;
  while (i < len)
  {
    dst[i] = src[i];
    ++i;
  }
  return (i);
}
