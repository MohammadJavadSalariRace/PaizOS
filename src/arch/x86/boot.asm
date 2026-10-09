; ==========================================
; PaizOS - boot.asm
; ==========================================

bits 32

MAGIC    equ 0x1BADB002        ; کد مالتی‌بوت
FLAGS    equ 0x00              
CHECKSUM equ -(MAGIC + FLAGS)  

section .multiboot
    align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

section .text
global _start
extern kernel_main

_start:
    cli                        ; غیرفعال کردن وقفه‌ها
    mov esp, stack_top         ; تنظیم استک
    call kernel_main           ; رفتن به کد C هسته پاییز

.halt:
    hlt                        
    jmp .halt

section .bss
align 16
stack_bottom:
    resb 16384                 ; ۱۶ کیلوبایت فضا برای استک
stack_top:
