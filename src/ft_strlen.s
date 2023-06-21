bits 64
section .text
global  ft_strlen

ft_strlen:
    xor rax, rax    ;init rax at 0
    mov rcx, rdi    ;Get rdi (parameter) to rcx

loop:
    ; parcourir rax jusqu'a byte = 0
    cmp byte [rcx], 0   ; check if rcx == 0
    je  end_loop        ; if cmp return true jump end_loop
    inc rax             ; lenght ++
    inc rcx
    jmp loop            ; jump loop begin

end_loop:
    ret                 ; return rax
