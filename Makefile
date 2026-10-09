AS = nasm
CC = gcc
LD = ld

ASFLAGS = -f elf32
CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra -nostdlib -fno-builtin
LDFLAGS = -m elf_i386 -T src/arch/x86/linker.ld

BUILD_DIR = build
SRC_DIR = src

TARGET = $(BUILD_DIR)/paizos.bin
OBJS = $(BUILD_DIR)/boot.o $(BUILD_DIR)/kernel.o

all: setup $(TARGET)

setup:
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/boot.o: $(SRC_DIR)/arch/x86/boot.asm
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)/kernel.o: $(SRC_DIR)/kernel/kernel.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

run: all
	qemu-system-i386 -kernel $(TARGET)

clean:
	rm -rf $(BUILD_DIR)
