section .text
	global _ft_strlen
_ft_strlen:
	mov	rax, 0
_while:
	cmp BYTE[rdi + rax], 0 ;compare
	je _return ;return siempre devuelve rax
	inc	rax
	jmp _while
_return:
	ret
