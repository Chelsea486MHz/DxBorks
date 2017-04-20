#include <math/pow.h>

long double pow(const long double base, const int16_t exp)
{
  int32_t p;
  long double res;

  p = 1;
  res = 1;
  if (exp < 0)
    return (1 / pow(base, -exp));
  if (exp == 0)
    return (1);
  while (p <= exp)
  {
    res *= base;
    ++p;
  }
  return (res);
}
