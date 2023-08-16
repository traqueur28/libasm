bits    64

extern  ft_strlen
extern  ft_strcpy
extern  malloc
extern  __errno_location

section .data

global  ft_strdup


;   The strdup() function returns a pointer to a new string which is a duplicate of the string s.
;   Memory for the new string is obtained with malloc(3), and can be freed with free(3).

;   rdi = string to cpy
ft_strdup:
    call    ft_strlen   ; get size string
    push    rdi         ; store rdi on stack
    inc rax
    mov rdi, rax        ; store size in rdi
    call    malloc      ; rax = malloc(rdi)
    test    rax, rax    ; check if error
    js  error           ;
    pop rsi             ; get src
    mov rdi, rax        
    call    ft_strcpy   ; rax = ft_strcpy(rdi, rsi)
    ret

error:
    neg		rax                 ; change rax to positive
	mov		rdx, rax            ; store rax in rdi
	call	__errno_location    ; change errno to
	mov		qword [rax], rdx    ; set errno
	mov		rax, 0              ; return 0
    ret
