global _ft_strdup
	
extern _malloc
extern _ft_strlen
extern _ft_strcpy

section .text

_ft_strdup:			;	rdi - s
	push rdi
	call _ft_strlen
	inc rax			;   for '\0'
	mov rdi, rax	
	call _malloc
	test rax, rax
	jz _exit
	mov rdi, rax
	pop rsi			;	rsi = s
	call _ft_strcpy
_exit:
	ret