bits 64

extern __errno_location

section .data

global  ft_write

ft_write:
    mov rax, 1          ; set number syscall (1 = write)
    syscall             ; systcall write
    test    rax, rax    ;
    js  error           ; jump if rax negative (-errno)
    ret                 ; return number bytes write

error:  ; write error msg and set errno
    neg		rax                 ; change rax to positive
	mov		rdi, rax            ; store rax in rdi
	call	__errno_location    ; change errno to
	mov		qword [rax], rdi    ; set errno
	mov		rax, -1             ; return -1
    ret

