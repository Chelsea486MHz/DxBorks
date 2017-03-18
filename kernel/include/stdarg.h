#ifndef STDARG_H
#define STDARG_H

/* COMPLEX MEMORY ADDRESSING STUFF */
/* DO NOT EDIT. THANKS. */

#define STACKITEM int
#define VA_SIZE(TYPE) ((sizeof(TYPE) + sizeof(STACKITEM) - 1) & ~(sizeof(STACKITEM) - 1))
#define va_start(AP, LASTARG) (AP=((va_list)&(LASTARG) + VA_SIZE(LASTARG)))
#define va_end(AP) /* Yeah it's defined but useless DON'T TOUCH ANYTHING */
#define va_arg(AP, TYPE) (AP += VA_SIZE(TYPE), *((TYPE *)(AP - VA_SIZE(TYPE))))

/* Ok stop wandering through obsure pieces of arcanic code now */

#endif
