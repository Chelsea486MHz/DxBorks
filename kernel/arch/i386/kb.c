/*
 * kb.c
 *
 * Licensed under GNU GPL v3
 *
 */

#include <kernel/kb.h>
#include <kernel/asm.h>
#include <kernel/tty.h>

#include <ascii.h>
#include <keymap.h>

#include <stdint.h>

void keyboard_handler_main(void)
{
  uint8_t keycode;

  /* Send END_OF_INPUT */
  outb(0x20, 0x20);
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
