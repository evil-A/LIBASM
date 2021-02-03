global _ft_write
extern ___error

section .text

_ft_write:
	mov rax, 0x02000004
	syscall
	jc		_error
	ret
_error:
	mov		rdx, rax
	call	___error
	mov		[rax], rdx
	mov		rax, -1
	ret
