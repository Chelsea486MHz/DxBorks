/*
 * idt.h
 *
 * Licensed under GNU GPL v3
 *
 */

#ifndef _IDT_H_INCLUDED
#define _IDT_H_INCLUDED

#include <stdint.h>

#define IDT_SIZE 256
#define INTERRUPT_GATE 0x8E
#define KERNEL_CODE_SEGMENT_OFFSET 0x08

#define PORT_PIC1_COMMAND 0x20
#define PORT_PIC2_COMMAND 0xA0
#define PORT_PIC1_DATA    0x21
#define PORT_PIC2_DATA    0xA1

typedef struct s_IDT_entry t_IDT_entry;
struct s_IDT_entry
{
  uint16_t offset_lowerbits;
  uint16_t selector;
  uint8_t  zero;
  uint8_t  type_attr;
  uint16_t offset_higherbits;
} __attribute__((packed));

void idt_init(void);

#endif
