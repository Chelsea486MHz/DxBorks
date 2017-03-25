#ifndef ASM_H_INCLUDED
#define ASM_H_INCLUDED

#include <stdint.h>

/* This file contains definitions for the different functions
   implemented in assembly. */

void outb(const uint8_t port, const uint8_t value);
uint8_t inb(const uint8_t port);

void keyboard_handler(void);

#endif
