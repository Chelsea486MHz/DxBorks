#include <math/exp.h>
#include <math/pow.h>
#include <math/fact.h>
#include <math/pow.h>
#include <math/math.h>

/* Uses the function's Taylor series */
long double exp(const long double x)
{
    long double res;

    res = 1;
    res +=  x;
    res += pow(x, 2) * 0.5000000000;
    res += pow(x, 3) * 0.1666666666;
    res += pow(x, 4) * 0.0416666666;
    res += pow(x, 5) * 0.0083333333;
    res += pow(x, 6) * 0.0013888888;
    res += pow(x, 7) * 0.0001984126;
    #if (MATH_SLOWEXP == TRUE)
    res += pow(x, 8) * 0.0000248015;
    res += pow(x, 9) * 2.7557319223E-6;
    res += pow(x, 10) * 2.755731922E-7;
    res += pow(x, 11) * 2.505210838E-8;
    #endif
    return (res);
}
