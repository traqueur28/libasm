bits 64

section .text

global  ft_strcpy
ft_strcpy:
    xor rcx, rcx

ft_loop:
    mov al, byte [rsi + rcx]
    mov byte [rdi + rcx], al
    inc rcx
    cmp al, 0
    jne ft_loop                 ; while dest[rcx] != 0 cpy

return:
    mov rax, rdi
    ret

