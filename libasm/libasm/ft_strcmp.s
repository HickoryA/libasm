global ft_strcmp

section .text


ft_strcmp:
	;rdi - s1 
	;rsi - s2
	;rcx - counter
	;возьмем dl и al если надо будет можем взять еще bl
	mov rcx,0
	cmp	rdi, 0
	je	return
	cmp	rsi, 0
	je	return
	

loop:
	mov dl,byte [rdi + rcx]
	mov al, byte [rsi + rcx]
	cmp dl,al
	jg more
	jl less
	cmp dl,0
	je equal
	inc rcx
	jmp loop

more:
	mov rax,1
	ret
less:
	mov rax, -1
	ret
equal:
	mov rax,0
	ret
return:
	ret
