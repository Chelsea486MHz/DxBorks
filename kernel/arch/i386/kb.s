.extern keyboard_handler_main
.global keyboard_handler
.type   keyboard_handler, @function

.section .text
keyboard_handler:
  call keyboard_handler_main
  iret
