#include <sys/types.h>
#include <stdint.h>

#include <kernel/def.h>
#include <kernel/panic.h>
#include <kernel/tty.h>
#include <kernel/libk.h>
#include <vga.h>
#include <ascii.h>

static size_t tty_row;
static size_t tty_column;
static uint8_t tty_colour;
static uint16_t *tty_buffer;

void tty_init(void)
{
  tty_row = 0;
  tty_column = 0;
  tty_colour = tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK);
  tty_buffer = TTY_BUFFER;
  tty_clear();
  tty_puts("[ ");
  tty_set_colour(tty_map_colour(VGA_GREEN, VGA_BLACK));
  tty_puts("OK");
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_puts(" ] TTY initialized\n");
}

void tty_clear(void)
{
  size_t x;
  size_t y;

  y = 0;
  while (y < TTY_HEIGHT)
  {
    x = 0;
    while (x < TTY_WIDTH)
    {
      tty_put_raw(ASCII_SPACE, x, y);
      ++x;
    }
    ++y;
  }
  tty_column = 0;
  tty_row = 0;
}

uint8_t tty_map_colour(const t_vga_colour fg, const t_vga_colour bg)
{
  return (fg | (bg << 4));
}

uint16_t tty_map_char(const char c, const uint8_t colour)
{
  return (c | (colour << 8));
}

void tty_set_colour(const uint8_t colour)
{
  tty_colour = colour;
}

int tty_put_raw(const char c, const size_t x, const size_t y)
{
  if ((x >= TTY_WIDTH) || (y >= TTY_HEIGHT))
    kernel_panic(PANIC_BADTTYCOORDS, __FILE__, __LINE__);
  tty_buffer[(y * TTY_WIDTH) + x] = tty_map_char(c, tty_colour);
  return (KERNEL_SUCCESS);
}

size_t tty_write(const char *buf, const size_t len)
{
  size_t i;

  i = 0;
  while (i < len)
  {
    if (buf[i] == ASCII_NEWLINE)
    {
      tty_column = 0;
      tty_row = (tty_row + 1);
      if (tty_row >= TTY_HEIGHT)
      {
        tty_scroll();
        tty_row -= 1;
      }
    }

    else
    {
      tty_put_raw(buf[i], tty_column, tty_row);
      if (++tty_column == TTY_WIDTH)
      {
        tty_column = 0;
        if (++tty_row == TTY_HEIGHT)
        {
          tty_scroll();
          tty_row -= 1;
        }
      }
    }
    ++i;
  }
  return (i);
}

size_t tty_putc(const char c)
{
  return ((tty_write(&c, sizeof(char)) != sizeof(char)) ? KERNEL_FAILURE : KERNEL_SUCCESS);
}

size_t tty_puts(const char *str)
{
  size_t i;

  i = 0;
  while (str[i] != ASCII_NULL)
  {
    if (tty_putc(str[i]) == KERNEL_FAILURE)
      return (KERNEL_FAILURE);
    ++i;
  }
  return (i);
}

size_t tty_putn(const int n)
{
  int nb;
  int mod;
  size_t count;

  nb = n;
  mod = 0;
  count = 0;

  if (nb < 10 && nb > -1)
    count += tty_putc(nb + 48);

  else if (nb < 0)
  {
    count += tty_putc('-');
    nb *= -1;
    if (nb < 10 && nb > -1)
      count += tty_putc(nb + 48);
  }

  else
  {
    mod = nb % 10;
    count += tty_putn(nb / 10);
    count += tty_putc(mod + 48);
  }
  return (count);
}

void tty_scroll(void)
{
  size_t y;

  y = 0;
  while (y < TTY_HEIGHT - 1)
  {
    memcpy((char*)tty_buffer + (y * TTY_WIDTH), (char*)tty_buffer + ((y + 1) * TTY_WIDTH), TTY_WIDTH);
  }
  memset((char*)tty_buffer + ((TTY_HEIGHT - 1) * TTY_WIDTH), tty_map_char(ASCII_SPACE, tty_colour), TTY_WIDTH);
}

void tty_delete_last(void)
{
  if (tty_column == 0)
    return;
  --tty_column;
  tty_putc(' ');
}
