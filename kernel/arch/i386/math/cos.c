#include <math/cos.h>
#include <math/pow.h>
#include <math/math.h>
#include <math/fmod.h>

/* Uses the function's Taylor series */
long double cos(const long double x)
{
    long double res;

    res = fmod(x, 2*MATH_PI);
    if (res > MATH_PI/2)
      return (-cos(MATH_PI-x));
    if (res < 0)
      return (cos(-res));
    return (1.0 - ((res * res) / 2) + (pow(res, 4) / 24) - (pow(res, 6) / 720));
}
