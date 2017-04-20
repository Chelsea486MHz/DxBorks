/*
 * serial.c
 *
 * Licensed under GNU GPL v3
 *
 */

#include <kernel/serial.h>
#include <kernel/panic.h>
#include <kernel/asm.h>
#include <kernel/tty.h>

#include <stdint.h>
#include <kernel/def.h>
#include <sys/types.h>

/* This function initializes a serial port with the following:
 * - 8 bit data length
 * - No parity bit
 * - 1 stop bit
 * - 115200 bauds
 */
t_kstat serial_init(const uint16_t port)
{
  if (port != SERIAL_PORT_0 &&
      port != SERIAL_PORT_1 &&
      port != SERIAL_PORT_2 &&
      port != SERIAL_PORT_3)
    kernel_panic(PANIC_INVALIDSERIALPORT, __FILE__, __LINE__);

  /* Disable interupts */
  outb(port + 1, 0x00);

  /* Here we're setting the speed */
  outb(port + 3, 0x80);
  outb(port + 0, 0x01);
  outb(port + 1, 0x00);

  /* Here we clean up some stuff and set the different parameters */
  outb(port + 3, 0x03);
  outb(port + 2, 0xC7);

  /* Enable interrupts */
  outb(port + 4, 0x0B);

  tty_puts("[  ");
  tty_set_colour(tty_map_colour(VGA_GREEN, VGA_BLACK));
  tty_puts("OK");
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_puts("  ] Serial port ");
  tty_putn(port - SERIAL_PORT_0);
  tty_puts(" initialized\n");
  return (KSUCCESS);
}

uint8_t serial_readb(const uint16_t port)
{
  if (port != SERIAL_PORT_0 &&
      port != SERIAL_PORT_1 &&
      port != SERIAL_PORT_2 &&
      port != SERIAL_PORT_3)
    kernel_panic(PANIC_INVALIDSERIALPORT, __FILE__, __LINE__);
  /* Wait for input */
  while (!(inb(port + 5) & 1));
  return (inb(port));
}

void serial_writeb(const uint16_t port, const uint8_t data)
{
  if (port != SERIAL_PORT_0 &&
      port != SERIAL_PORT_1 &&
      port != SERIAL_PORT_2 &&
      port != SERIAL_PORT_3)
    kernel_panic(PANIC_INVALIDSERIALPORT, __FILE__, __LINE__);
  /* Wait for CTS */
  while (!(inb(port + 5) & 0x20));
  outb(port, data);
}

size_t serial_read(const uint16_t port, char *buf, const size_t len)
{
  size_t i;

  i = 0;
  while (i < len)
    buf[i++] = serial_readb(port);
  return (i);
}

size_t serial_write(const uint16_t port, const char *buf, const size_t len)
{
  size_t i;

  i = 0;
  while (i < len)
  {
    serial_writeb(port, buf[i]);
    #ifdef DEBUG
    {
      tty_puts("[");
      tty_set_colour(tty_map_colour(VGA_BROWN, VGA_BLACK));
      tty_puts("SERIAL");
      tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
      tty_puts("] Byte \"");
      tty_putn(buf[i]);
      tty_puts("\" has been sent through serial port ");
      tty_putn(port - SERIAL_PORT_0);
      tty_putc('\n');
    }
    #endif
    ++i;
  }
  return (i);
}
