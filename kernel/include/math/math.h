#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#define MATH_PI       ((long double)3.14159265358979323846)

#define MATH_FASTFACT TRUE /* computes x! using a table lookup instead of a summation algorithm */
#define MATH_SLOWEXP  TRUE /* computes exp(x) using a degree 11 Taylor polynomial instead of a degree 6 one */
#define MATH_LN_TERMS 11   /* Number of terms in the ln(x) Taylor series */

#endif
