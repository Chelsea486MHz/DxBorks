.global inb
.type   inb,  @function

.global outb
.type   outb, @function

.section .text

inb:
  mov 4(%esp), %edx
  in  %dx,     %al
  ret

outb:
  mov 4(%esp), %edx
  mov 8(%esp), %al
  out %al,     %dx
  ret
