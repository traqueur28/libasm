bits 64

extern __errno_location

section .text

;int fd, const void *buf, size_t count)
; rdi, rsi, rdx

; mov rdi, rdi        ; fd to write
; mov rsi, rsi        ; ptr text
; mov rdx, rdx        ; Size

global  ft_write

ft_write:
    mov rax, 1          ; set number syscall (1 = write)
    syscall
    test    rax, rax    ;
    js  error           ; jump if rax negative
    xor rax,rax
    ret

error:  ; write error msg and set errno
    mov rax, 1  ; set syscall
    mov rdi, 2  ; set fd error
    mov

    ret

