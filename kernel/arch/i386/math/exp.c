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
    res += pow(x, 2) / fact(2);
    res += pow(x, 3) / fact(3);
    res += pow(x, 4) / fact(4);
    res += pow(x, 5) / fact(5);
    res += pow(x, 6) / fact(6);
    res += pow(x, 7) / fact(7);
    #if (MATH_SLOWEXP == TRUE)
    res += pow(x, 8) / fact(8);
    res += pow(x, 9) / fact(9);
    res += pow(x, 10) / fact(10);
    res += pow(x, 11) / fact(11);
    res += pow(x, 12) / fact(12);
    #endif
    return (res);
}
