.extern keyboard_handler_main
.global keyboard_handler

.section .text
keyboard_handler:
  call keyboard_handler_main
  iret
