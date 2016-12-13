ENTRY(_start)

SECTIONS
{
  . = 0x100000;

  .text BLOCK(4K) : ALIGN(4K)
  {
    *(.multiboot_header)
    *(.text)
  }

  .rodata BLOCK(4K) : ALIGN(4K)
  {
    *(.rodata)
  }

  .data BLOCK(4K) : ALIGN(4K)
  {
    *(.data)
  }

  .bss BLOCK(4K) : ALIGN(4K)
  {
    *(COMMON)
    *(.bss)
  }
}
