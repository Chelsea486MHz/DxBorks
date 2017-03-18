##
## Makefile
##
## Licensed under GNU GPL v3
##

.PHONY: all clean re test Debug Release

CC := gcc
AS := as
LD := ld

NAME := dxborks
ARCH := i386

BIN_DIR := ./bin
OBJ_DIR := $(BIN_DIR)/obj
SRC_DIR := ./kernel/arch/$(ARCH)
HDR_DIR := ./kernel/include

C_SRCS := $(shell find $(SRC_DIR) -name "*.c")
C_OBJS := $(C_SRCS:.c=.o)

WARNINGS := -Wall -Wextra -Werror -Wshadow -Wpointer-arith -Wcast-align -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wno-long-long -Wuninitialized -Wstrict-prototypes

CFLAGS := -c -m32 -std=c89 -ffreestanding -nostdlib -O2 -I$(HDR_DIR) $(WARNINGS)

all: $(C_OBJS)
	$(AS) --32 $(SRC_DIR)/boot/boot.s -o $(OBJ_DIR)/asm_boot.o
	$(AS) --32 $(SRC_DIR)/io.s -o $(OBJ_DIR)/asm_io.o
	$(AS) --32 $(SRC_DIR)/idt.s -o $(OBJ_DIR)/asm_idt.o
	$(AS) --32 $(SRC_DIR)/kb.s -o $(OBJ_DIR)/asm_kb.o
	mv $(C_OBJS) $(OBJ_DIR)
	$(LD) -m elf_i386 -nostdlib -T $(SRC_DIR)/linker.ld -o $(BIN_DIR)/isofiles/boot/$(NAME).bin $(OBJ_DIR)/*.o
	grub-mkrescue -d /usr/lib/grub/$(ARCH)-pc -o $(BIN_DIR)/$(NAME)-$(ARCH).iso $(BIN_DIR)/isofiles

clean:
	-@rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(NAME)* $(BIN_DIR)/isofiles/boot/$(NAME).bin

test:
	qemu-system-x86_64 --cdrom $(BIN_DIR)/$(NAME)-$(ARCH).iso

re: clean all

#For Code::Blocks compatibility
Release: all
Debug: all test
