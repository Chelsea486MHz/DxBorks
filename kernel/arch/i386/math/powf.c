#include <math/pow.h>
#include <math/exp.h>
#include <math/log.h>

long double powf(const long double base, const long double _exp)
{
  return (exp(_exp*ln(base)));
}
