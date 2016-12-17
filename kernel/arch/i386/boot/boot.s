.global _start
.type   _start, @function

.set ALIGN,    1 << 0
.set MEMINFO,  1 << 1
.set FLAGS,    (ALIGN | MEMINFO)
.set MAGIC,    0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

.section .multiboot_header
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .bss
.align 16
.skip 65536
stack:

.align 4
.section .text
_start:
  cli
  movl $stack, %esp
  call kernel_main
  sti
  hlt

.size _start, . - _start
