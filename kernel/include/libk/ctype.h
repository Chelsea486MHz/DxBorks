#ifndef CTYPE_H
#define CTYPE_H

/* Declared extern for standard purposes */
/* Otherwise, mainly used internally */
extern char _ctype[];

#define CT_UP  0x01 /* upper case */
#define CT_LOW 0x02 /* lower case */
#define CT_DIG 0x04 /* decimal digit */
#define CT_CTL 0x08 /* ASCII control character */
#define CT_PUN 0x10 /* punctuation character */
#define CT_WHT 0x20 /* white space */
#define CT_HEX 0x40 /* hexadecimal digit */
#define CT_SP  0x80 /* ASCII white space */

/* The following functions are too simple to get a proper implementation */
#define is_alnum(c)	((_ctype + 1)[(unsigned)(c)] & (CT_UP | CT_LOW | CT_DIG))
#define is_alpha(c)	((_ctype + 1)[(unsigned)(c)] & (CT_UP | CT_LOW))
#define is_cntrl(c)	((_ctype + 1)[(unsigned)(c)] & (CT_CTL))
#define is_digit(c)	((_ctype + 1)[(unsigned)(c)] & (CT_DIG))
#define is_graph(c)	((_ctype + 1)[(unsigned)(c)] & (CT_PUN | CT_UP | CT_LOW | CT_DIG))
#define is_lower(c)	((_ctype + 1)[(unsigned)(c)] & (CT_LOW))
#define is_print(c)	((_ctype + 1)[(unsigned)(c)] & (CT_PUN | CT_UP | CT_LOW | CT_DIG | CT_SP))
#define is_punct(c)	((_ctype + 1)[(unsigned)(c)] & (CT_PUN))
#define is_space(c)	((_ctype + 1)[(unsigned)(c)] & (CT_WHT))
#define is_upper(c)	((_ctype + 1)[(unsigned)(c)] & (CT_UP))
#define is_xdigit(c)	((_ctype + 1)[(unsigned)(c)] & (CT_DIG | CT_HEX))
#define is_ascii(c)	((unsigned)(c) <= 0x7F)
#define to_ascii(c)	((unsigned)(c) & 0x7F)
#define to_lower(c)	(isupper(c) ? c + 'a' - 'A' : c)
#define to_upper(c)	(islower(c) ? c + 'A' - 'a' : c)

#endif
