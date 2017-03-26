/*
 * serial.h
 *
 * Licensed under GNU GPL v3
 *
 */

#ifndef _SERIAL_H_INCLUDED
#define _SERIAL_H_INCLUDED

#include <stdint.h>
#include <sys/types.h>
#include <kernel/def.h>

#define SERIAL_PORT_0 (0x3F8)
#define SERIAL_PORT_1 (0x2F8)
#define SERIAL_PORT_2 (0x3E8)
#define SERIAL_PORT_3 (0x2E8)

t_kstat serial_init(const uint16_t port);

uint8_t serial_readb(const uint16_t port);
void serial_writeb(const uint16_t port, const uint8_t data);

size_t serial_read(const uint16_t port, char *buf, const size_t len);
size_t serial_write(const uint16_t port, const char *buf, const size_t len);

#endif
