global _ft_strcpy

section .text

_ft_strcpy: ; rdi - *dest; rsi - *src;
    mov rax, rdi;
    xor r8, r8;
_loop:
    mov r8b, byte[rsi];
    mov byte[rdi], r8b;
    test r8b, r8b
    jz _exit
    inc rsi
    inc rdi
    jmp _loop
_exit:
    ret