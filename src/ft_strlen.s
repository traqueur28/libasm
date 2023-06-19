section .text
global  ft_strlen

ft_strlen:
    xor rax, rax    ;init rcx at 0
    mov rcx, rdi    ;Get rdi (parameter) to rax

loop:
    ; parcourir rax jusqu'a byte = 0
    cmp byte [rcx], 0   ; check if rax == 0
    je  end_loop        ; if cmp return true jump end_loop
    inc rax
    inc rcx
    jmp loop            ; jump loop begin

end_loop:
    ret                 ; return rax
