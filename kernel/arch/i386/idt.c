/*
 * idt.c
 *
 * Licensed under GNU GPL v3
 *
 */

#include <kernel/idt.h>
#include <kernel/panic.h>
#include <kernel/asm.h>
#include <kernel/tty.h>
#include <kernel/def.h>

#include <stdint.h>

static t_IDT_entry IDT[IDT_SIZE];

t_kstat idt_init(void)
{
  uint32_t keyboard_handler_address;
  uint32_t idt_address;
  /*uint16_t idt_ptr[2];*/

  keyboard_handler_address = (uint32_t)keyboard_handler;
  IDT[0x21].offset_lowerbits = keyboard_handler_address & 0xFFFF;
  IDT[0x21].selector = KERNEL_CODE_SEGMENT_OFFSET;
  IDT[0x21].zero = 0;
  IDT[0x21].type_attr = INTERRUPT_GATE;
  IDT[0x21].offset_higherbits = (keyboard_handler_address & 0xFFFF0000) >> 16;

  /* Send signals to initialize the PICs
   *
   * The PICs will be initialized using the bit string 00010001 (0x11) as the first Initialisation Control Word (ICW1)
   *
   * BIT    VALUE     DESCRIPTION
   * 0      1         Tells the PIC we're not going to send IC4 during initialisation
   * 1      0         Tells the PIC to cascade another 8259A
   * 2      0         Ignored by most x86 devices
   * 3      0         Use edge triggered mode instead of level triggered mode
   * 4      1         Tells the PIC it has to be initialized
   * 5      0         Required to be 0 by x86 devices
   * 6      0         Required to be 0 by x86 devices
   * 7      0         Required to be 0 by x86 devices
   */

  /* Initialisation Control Word 1 */
  outb(PORT_PIC1_COMMAND, 0x11); /* Initialise master */
  outb(PORT_PIC2_COMMAND, 0x11); /* Initialise slave */

  /* Initialisation Control Word 2 */
  outb(PORT_PIC1_DATA, 0x20); /* Map the master PIC's IRQ0 to 0x20 */
  outb(PORT_PIC2_DATA, 0x28); /* Map the slave PIC's IRQ8 to 0x28 */
                              /* The master can only handle interrupts 0x20 to 0x27 */

  /* Initialisation Control Word 3 */
  outb(PORT_PIC1_DATA, 0x04); /* 0100 (BIT1=1) Tell the master the slave is connected to IRQ2 */
  outb(PORT_PIC2_DATA, 0x02); /* Tells the slave IR2 is the communication line with the master */

  /* Initialisation Control Word 4 (required by ICW1) */
  /* This ICW will only be used to signal the PICS we're in x86 mode */
  outb(PORT_PIC1_DATA, 0x01); /* 00000001, the first bit signals the x86 mode (0 means MCS-80/86 mode) */
  outb(PORT_PIC2_DATA, 0x01);

  /* Send EOI to master */
  outb(PORT_PIC1_COMMAND, 0x20);

  /* We now need to clear out the PIC data registers... we don't want garbage in there */
  outb(PORT_PIC1_DATA, 0x00);
  outb(PORT_PIC2_DATA, 0x00);

  idt_address = (uint32_t)IDT;/*
  idt_ptr[0] = (sizeof(t_IDT_entry) * IDT_SIZE) + ((idt_address & 0xFFFF) << 16);
  idt_ptr[1] = idt_address >> 16; */

  /* Load the Interrupt Descriptor Table */
  load_idt((void*)idt_address, IDT_SIZE);

  #ifdef DEBUG
  tty_puts("[  ");
  tty_set_colour(tty_map_colour(VGA_GREEN, VGA_BLACK));
  tty_puts("OK");
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_puts("  ] IDT remaped to address ");
  tty_putn(idt_address);
  tty_puts(" with size ");
  tty_putn(IDT_SIZE);
  tty_putc('\n');
  #else
  tty_puts("[  ");
  tty_set_colour(tty_map_colour(VGA_BROWN, VGA_BLACK));
  tty_puts("OK");
  tty_set_colour(tty_map_colour(VGA_LIGHT_GREY, VGA_BLACK));
  tty_puts("  ] IDT remaped\n");
  #endif
  return (KSUCCESS);
}

/* thanks wiki.osdev.org for this. Old implementation was in idt.s */
void load_idt(void* add, const uint16_t size)
{
    struct
    {
        uint16_t length;
        void*    base;
    } __attribute__((packed)) IDTR = { size, add };

    __asm__( "lidt %0" : : "m"(IDTR) );
}
