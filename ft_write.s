global _ft_write

extern ___error

section .text
_ft_write:	 ; rdi - fd, rsi - &buf, rdx - count		
	mov rax, 0x2000004
	syscall
    jc _set_err
	ret

_set_err:
    push rax
    call ___error
    pop rdi
    mov [rax], rdi
    mov rax, -1
    ret
	