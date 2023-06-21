bits 64

section .text

global  ft_strcmp

ft_strcmp:
    xor rax, rax    ; rax set 0
    xor rcx, rcx    ; index set 0

ft_loop:
    ; xor al, al                  ; set al 0
    ; add al, byte [rdi + rcx] 
    ; sub al, byte [rsi + rcx]    

    mov al, byte [rdi + rcx]
    cmp al, byte [rsi + rcx]    ; check diff

    ; cmp al, 0
    jl  less                    ; jup if lesser
    jg  great                   ; jump if greater
    cmp byte [rdi + rcx], 0     ; check end string
    jz  return                  ; jump if zero
    inc rcx
    jmp ft_loop

less:
    xor al, al
    dec rax;    ; set -1

    jmp return
    
great:
    xor al, al
    inc rax;    ; set 1
    jmp return

return:
    ret
