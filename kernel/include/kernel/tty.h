#ifndef TTY_H_INCLUDED
#define TTY_H_INCLUDED

#include <libk/size_t.h>
#include <libk/stdint.h>
#include <libk/bool.h>
#include <vga.h>

#include <kernel/def.h>

#define TTY_WIDTH (80)
#define TTY_HEIGHT (25)
#define TTY_BUFFER ((uint16_t*)0xB8000)

t_kstat  tty_init(void);
void     tty_clear(void);
void     tty_scroll(void);
t_kstat  tty_delete_last(void);
void     tty_set_colour(const uint8_t colour);

uint8_t  tty_map_colour(const t_vga_colour fg, const t_vga_colour bg);
uint16_t tty_map_char(const char c, const uint8_t colour);

t_kstat  tty_put_raw(const char c, const size_t x, const size_t y);
size_t   tty_write(const char *buf, const size_t len);
size_t   tty_putc(const char c);
size_t   tty_puts(const char *str);
size_t   tty_putn(const int n);

size_t   tty_putn_hex2(uint8_t n); /* Outputs n formated as "0x**" */
size_t   tty_putn_hex(uint32_t n); /* Outputs n formated as "0x********" */

#endif
