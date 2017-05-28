#include <math/log.h>
#include <math/pow.h>

#include <stdint.h>

long double ln(const long double x)
{
  long double res;
  uint8_t i;

  res = 0;
  for (i=1; i<= MATH_LN_TERMS; ++i)
    res += (pow(-1, i) * pow(x-1, i))/i;
  return (res);
}
