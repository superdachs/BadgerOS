.section multiboot
#define MB_MAGIC 0x1badb002
#define MB_FLAGS 0x0
#define MB_CHECKSUM -(MB_MAGIC + MB_FLAGS)
 
// Multiboot-Header
.align 4
.int    MB_MAGIC
.int    MB_FLAGS
.int    MB_CHECKSUM
 

.section .text
 
// Identify external function
.extern init

// Make _start global to make linker find it
.global _start
_start:
    // Init stack
    mov $kernel_stack, %esp
 
    // Call init from c code
    call init
 
_stop:
    cli
    hlt
 
    jmp _stop
 
.section .bss
.space 8192
kernel_stack:
