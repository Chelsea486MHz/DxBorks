/*
 * kb.h
 *
 * Licensed under GNU GPL v3
 *
 */

#ifndef _KB_H_INCLUDED
#define _KB_H_INCLUDED

#define PORT_KEYBOARD_STATUS 0x64
#define PORT_KEYBOARD_DATA   0x60

void keyboard_handler_main(void);

#endif
