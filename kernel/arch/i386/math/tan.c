#include <math/tan.h>
#include <math/cos.h>
#include <math/sin.h>

long double tan(const long double x)
{
  return (sin(x)/cos(x));
}
