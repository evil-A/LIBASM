section .text
	global	_ft_read
	extern	___error

_ft_read:
	mov 	rax, 0x02000003
	syscall
	jc		_error	;carrier
	ret
_error:
	mov		r15, rax	;r15 is negative register?
	call	___error
	mov		[rax], r15	;go to pointer
	mov		rax, -1
	ret
