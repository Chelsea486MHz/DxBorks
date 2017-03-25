/*
 * kb.c
 *
 * Licensed under GNU GPL v3
 *
 */

#include <kernel/kb.h>
#include <kernel/asm.h>
#include <kernel/tty.h>
#include <kernel/idt.h>

#include <ascii.h>
#include <keymap.h>

#include <stdint.h>

void keyboard_handler_main(void)
{
  uint8_t keycode;

  outb(PORT_PIC1_COMMAND, 0x20);
  if (inb(PORT_KEYBOARD_STATUS) & 0x01)
  {
    keycode = inb(PORT_KEYBOARD_DATA);
    switch (keycode)
    {
      case ASCII_BACKSPACE:
        tty_delete_last();
        break;

      default:
        tty_putc(keymap[keycode]);
    }
  }
}

void keyboard_init(void)
{
    outb(PORT_PIC1_DATA, 0xFD);
}
