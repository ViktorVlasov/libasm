global _ft_strcmp

section .text

_ft_strcmp: ; rdi - s1; rsi - s2;
    xor rax, rax;
    xor rcx, rcx;
_loop:
    mov al, byte[rdi];
    mov cl, byte[rsi];
    sub rax, rcx
    jnz _exit
    test cl, cl
    jz  _exit
    inc rdi
    inc rsi
    jmp _loop
_exit:
    ret
