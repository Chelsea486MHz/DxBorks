#ifndef PANIC_H_INCLUDED
#define PANIC_H_INCLUDED

#include <stdint.h>
#include <sys/types.h>

#define PANIC_NOTHING 0x00 /* Nothing wrong, used for debugging */
#define PANIC_BADTTYCOORDS 0x01 /* tty_put_raw tries to write outside the screen */
#define PANIC_INVALIDSERIALPORT 0x02 /* Trying to use an invalid serial port */
void kernel_panic(const uint8_t err, const char *file, const size_t line);

#endif
