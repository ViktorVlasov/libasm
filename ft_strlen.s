global ft_strlen

section		.text
ft_strlen:	xor rax, rax
.loop:		cmp [rdi + rax], 0x0
			je .exit
			inc rax
			jmp .loop
.exit:		ret