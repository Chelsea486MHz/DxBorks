/*
 * idt.c
 *
 * Licensed under GNU GPL v3
 *
 */

#include <kernel/idt.h>
#include <kernel/panic.h>
#include <kernel/asm.h>

#include <stdint.h>

static t_IDT_entry IDT[IDT_SIZE];

void idt_init(void)
{
  uint32_t keyboard_address;
  uint32_t idt_address;
  uint32_t idt_ptr[2];

  keyboard_address = (uint32_t)keyboard_handler;
  IDT[0x21].offset_lowerbits = keyboard_address & 0xFFFF;
  IDT[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
  IDT[0x21].zero = 0;
  IDT[0x21].type_attr = INTERRUPT_GATE;
  IDT[0x21].offset_higherbits = (keyboard_address & 0xFFFF0000) >> 16;

  outb(PORT_PIC1_COMMAND, 0x11);
  outb(PORT_PIC2_COMMAND, 0x11);

  outb(PORT_PIC1_DATA, 0x20);
  outb(PORT_PIC2_DATA, 0x28);

  outb(PORT_PIC1_DATA, 0x00);
  outb(PORT_PIC2_DATA, 0x00);

  outb(PORT_PIC1_DATA, 0x01);
  outb(PORT_PIC2_DATA, 0x01);

  outb(PORT_PIC1_DATA, 0xFF);
  outb(PORT_PIC2_DATA, 0xFF);

  idt_address = (uint32_t)IDT;
  idt_ptr[0] = (sizeof(t_IDT_entry) * IDT_SIZE) + ((idt_address & 0xFFFF) << 16);
  idt_ptr[1] = idt_address >> 16;

  load_idt((uint32_t)idt_ptr);

  /* Enable IRQ1, 0xFD = 11111101 */
  outb(0x21, 0xFD);
}
