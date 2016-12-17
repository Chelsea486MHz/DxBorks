.global load_idt
.type   load_idt, @function

.section .text

load_idt:
  mov 4(%esp), %edx
  lidt (%edx)
  ret
