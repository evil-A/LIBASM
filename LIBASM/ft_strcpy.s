section .text
	global _ft_strcpy
_ft_strcpy:
	mov	rcx, -1
_while:
	inc	rcx
	mov dl, BYTE[rsi + rcx]
	mov BYTE[rdi + rcx], dl
	cmp BYTE[rsi + rcx], 0
	jne _while
	mov rax, rdi
	ret
