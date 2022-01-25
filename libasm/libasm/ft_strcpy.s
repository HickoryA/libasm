global ft_strcpy

section .text

ft_strcpy:
	mov rax,0
	cmp	rdi, 0
	je	return
	cmp	rsi, 0
	je	return
	

loop:
	mov dl,byte [rsi + rax]
	mov byte [rdi + rax], dl
	cmp dl,0
	je return
	inc rax
	jmp loop

return:
	mov rax,rdi
	ret