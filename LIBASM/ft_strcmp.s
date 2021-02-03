section .text
	global _ft_strcmp
_ft_strcmp:
	mov	rcx, -1
	mov	rax, 0
	mov rbx, 0
	mov rdx, 0

_while:
	inc	rcx
	mov dl, BYTE[rdi + rcx]
	mov bl, BYTE[rsi + rcx]
	cmp dl, bl
	jne _diff
	cmp dl, 0
	jne _while
	ret
_diff:
	sub	rdx, rbx
	mov rax, rdx
	ret
