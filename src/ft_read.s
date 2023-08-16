bits    64

extern  __errno_location

section .data

global  ft_read

; sys_read :
; System call number: 0
; Register :
;   rdi : File descriptor
;   rsi : Ptr buffer to read
;   rdx : Size bytes read

ft_read:
    xor rax, rax        ; set number syscall (0 = read)
    syscall             ; systcall read
    test    rax, rax    ;
    js  error           ; if error
    ret                 ; return rax (size read)

error:
    neg rax                     ; set correct errno in rax
    mov rdi, rax                ; store rax in rdi
    call    __errno_location    ; get errno_location
    mov qword [rax], rdi        ; set errno
    mov rax, -1                 ; set rax at -1
    ret                         ; return rax (-1)
