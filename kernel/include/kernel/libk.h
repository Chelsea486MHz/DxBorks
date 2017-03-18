#ifndef LIBK_H_INCLUDED
#define LIBK_H_INCLUDED

/* required C standard library functions */

#include <size_t.h>

size_t memcpy(char *dst, const char *src, const size_t len);
size_t memset(char *dst, const char val, const size_t len);

#endif
