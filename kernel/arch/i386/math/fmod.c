#include <math/fmod.h>

long double fmod(const long double a, const long double b)
{
  long double res;

  res = a;
  while (res > b)
    res -= b;
  return (res);
}
