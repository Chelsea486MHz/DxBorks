#include <math/math.h>
#include <math/cos.h>
#include <math/sin.h>

long double sin(const long double x)
{
    return (cos((MATH_PI/2)-x));
}
