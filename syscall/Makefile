# Makefile for xv6 without file system components

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -O -fno-omit-frame-pointer -ggdb -m32 -fno-pic -no-pie -nostdinc -I.

# List of source files
CSRC = \
    syscall.c \
    printf.c \
    # ... (other source files) \
    test.c

# Object files
COBJ = $(CSRC:.c=.o)

# Include xv6 Makefile
# include Makefile.mk

# # Kernel
# kernel: $(OBJS) entry.o entryother initcode entrypgdir
# 	@echo creating kernel
# 	@$(LD) $(LDFLAGS) -Ttext 0x100000 -e main -o kernel entry.o $(OBJS) -b binary initcode entryother entrypgdir
# 	@$(OBJDUMP) -S kernel > kernel.asm
# 	@$(OBJCOPY) -S -O binary kernel kernel

# Clean
clean:
	@rm -f $(OBJS) $(COBJ) kernel kernel.asm

# Test code
test: kernel
	@qemu-system-i386 -kernel kernel -smp $(CPUS) -m $(MEM) -serial mon:stdio

# ... (other rules and dependencies)

# Include dependencies
-include *.d
