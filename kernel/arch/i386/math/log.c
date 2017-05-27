#include <math/log.h>

long double log(const long double base, const long double x)
{
  return (ln(x)/ln(base));
}
