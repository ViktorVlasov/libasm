global _ft_strlen

section		.text
_ft_strlen:	; rdi - char *str
	xor rax, rax
_loop:		
	cmp byte[rdi + rax], 0x0
	je _exit
	inc rax
	jmp _loop
_exit:	
	ret