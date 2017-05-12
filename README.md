# DxBorks

**To execute your own program, edit the program's memory in `DxBorks/kernel/arch/i386/vm/vm.c`. Example programs can be found below.**

- The executed instruction is located at the address (%ip). The value C is the value located at the address (%ip) + 1.

- There are 4 registers, %a, %b, %c, and %d

- %ip is the instruction pointer

- %sp is the stack pointer, pointing to the top of the stack

- Every instruction takes 1 cycle to complete.

- The stack grows downwards from the highest memory location

- The program is loaded at address 0

- The VM's memory is somewhere between 0 and 256 bytes large.

- Registers are 8 bits wide


    OPCODE    MNEMONIC    DESCRIPTION
    
    0x00      nop         Does nothing and consumes a cycle
    
    0x01      add         %a += %b
    
    0x02      sub         %a -= %b
    
    0x03      xor         %a ^= %b
    
    0x04      or          %a |= %b
    
    0x05      not         %a = ~%a
    
    0x06      and         %a &= %b
    
    0x07      lshift      %a << %b
    
    0x08      rshift      %a >> %b
    
    0x09      loada       %a = C
    
    0x0a      loadb       %b = C
    
    0x0b      loadc       %c = C
    
    0x0c      loadd       %d = C
    
    0x0d      push        ++(%sp), mem[%sp] = C
    
    0x0e      pusha       ++(%sp), mem[%sp] = %a

    0x0f      pushb       ++(%sp), mem[%sp] = %b
    
    0x10      pushc       ++(%sp), mem[%sp] = %c
    
    0x11      pushd       ++(%sp), mem[%sp] = %d
    
    0x12      popa        a = mem[%sp], --(%sp)
    
    0x13      popb        b = mem[%sp], --(%sp)
    
    0x14      popc        c = mem[%sp], --(%sp)
    
    0x15      popd        d = mem[%sp], --(%sp)
    
    0x16      jmp         %ip = C
    
    0x17      cjmp        if (flag) %ip = C
    
    0x18      stop        stops execution
    
    0x19      eq          flag = (%a == %b ? 1 : 0)
    
    0x19      neq         flag = (%a != %b ? 1 : 0)
    
    0x19      lesser      flag = (%a <= %b ? 1 : 0)
    
    0x19      greater     flag = (%a >= %b ? 1 : 0)
    
    
    Special instructions:
    
    0x--      exp         %a = exp(%a)
    
    0x--      log         %a = log(%a)
    
    0x--      mul         %a *= %b
    
    0x--      div         %a /= %b
    
    0x--      mod         %a %= %b

# Example programs

This program loads 22 in %a, 16 in %b, computes the sum of %a + %b, substracts 10, and doubles its value before storing it at the stop of the stack:

    push 22       # Stores 22 on top of the stack
    push 16       # Stores 16 on top of the stack
    popb          # Pops the top of the stack (16) to %b
    popa          # Pops the top of the stack (22) to %a
    add           # Adds %b (16) to %a (22)
    loadb 10      # Sets %b (16) to 10
    sub           # Subtracts %b (10) from %a (38)
    pusha         # Stores %a (38) on top of the stack
    popb          # Pops the top of the stack (38) to %b (10)
    add           # Adds %b (38) to %a (38)
    pusha         # Stores %a (76) on top of the stack

When translated to hexadecimal VM code, we get:

    0x0d 0x16
    0x0d 0x10
    0x13
    0x12
    0x01
    0x0a 0x0a
    0x02
    0x0e
    0x13
    0x01
    0x0e

Our program, when inlined, should be:

    0x0d 0x16 0x0d 0x10 0x13 0x12 0x01 0x0a 0x0a 0x02 0x0e 0x13 0x01 0x0e

And should store 0x4C at the memory address (VM_MEM_SIZE-1) (default: 0xFF)
