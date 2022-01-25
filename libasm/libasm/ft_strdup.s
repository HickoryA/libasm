			section	.text
			global	ft_strdup
			extern	malloc
			extern	ft_strlen
			extern	ft_strcpy

ft_strdup:
			cmp		rdi, 0
			je		return_null
			call	ft_strlen 
			inc		rax
			push	rdi
			mov		rdi, rax
			call	malloc wrt ..plt
			pop		rsi
			cmp		rax, 0
			je		return_null
			mov		rdi, rax
			call	ft_strcpy 
			ret

return_null:
			xor		rax, rax
			ret