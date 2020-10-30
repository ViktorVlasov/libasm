global _ft_strdup
	
extern _malloc
extern _ft_strlen
extern _ft_strcpy

section .text

_ft_strdup:			;	rdi - s
	push rdi		;	save s
	call _ft_strlen
	inc rax
	mov rdi, rax
	call _malloc		;	rax = new_s
	pop rsi			;	rsi = s
	test rax, rax
	jz _ret
	mov rdi, rax
	call _ft_strcpy
_ret:
	ret