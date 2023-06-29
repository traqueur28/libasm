bits    64

section .text

global  ft_atoi_base

;   rdi : string convert
;   rsi : string base

; checker base
; convertir convert jusqu'a \0 ou space
; gerer cas min max (pas a faire selon sujet ft_atoi)
; gerer nb -

check_duplicate:
    cmp byte[rsi + rdx], 0;
    je  end_check_duplicate
    cmp al, byte [rsi + rdx]
    je  return_err_duplicate
    inc rdx
    jmp check_duplicate

in_base:
    cmp byte[rsi + rbx], 0
    je  return  ; no match return result
    push    rbx ; store rbx
    mov bl, byte[rsi + rbx]
    cmp bl, byte[rdi + rcx]
    je  found   ; match
    pop rbx     ; get rbx here
    inc rbx
    jmp in_base

; ---------
change_sign:
    neg rdx ; change to (1 -> -1) or (-1 -> 1)
    inc rcx ; skip inc so inc here


skip_sign:
    cmp byte[rdi + rcx], 0      ; end string return 0
    je  return_err
    cmp byte[rdi + rcx], '-'    ; just and change sign
    je  change_sign
    cmp byte[rdi + rcx], '+'    ; just skip
    jne calc_result             ; not \0 '+' '-'
    inc rcx
    jmp skip_sign

; ----------

ft_atoi_base:
    ; chhecking
    xor rax, rax    ; set rax 0

checker:
    ; read base to get if base is unvalid
    cmp byte [rsi + rax], 0   ; check if base[i] == 0
    je  end_checker

    ; check whitespace and + -
    cmp byte[rsi + rax], '+'
    je  return_err
    cmp byte[rsi + rax], '-'
    je  return_err
    cmp byte[rsi + rax], ' '
    je  return_err
    cmp byte[rsi + rax], 11
    je  return_err
    cmp byte[rsi + rax], 12
    je  return_err
    cmp byte[rsi + rax], 13
    je  return_err
    cmp byte[rsi + rax], 9
    je  return_err
    cmp byte[rsi + rax], 13
    je  return_err

    ; check duplicate
    mov rdx, rax
    push    rax             ; push rax because al in rax
    mov al, byte[rsi + rax]
    inc rdx         ; rdx = rax + 1
    jmp check_duplicate
end_check_duplicate:
    pop rax     ; get rax
    inc rax
    jmp checker

end_checker:
    cmp rax, 2      ; if rax < 2
    jl  return_err  ; size base < 2 error    
    mov r8, rax     ; store base's size in r8

    ; check rdi neg
    ; create number
    xor rax, rax    ; set rax 0 - result
    mov rdx, 1      ; set rdx 1 - sign
    xor rcx, rcx    ; set rcx 0 - index


    ; skip and count '+' '-'
    jmp skip_sign
calc_result:                ; now we are at beginning
    cmp byte[rdi + rcx], 0  ; end string return 
    je  return
    xor rbx, rbx            ; set rbx 0 to count
    jmp in_base             ; check byte[rdi + rcx] in rsi

found:    ; match at rsi + rbx
    pop rbx                     ; get rbx if not pop before
    imul rax, r8                ; rax * 10 TODO len base
    add rax, rbx                ; add result
    inc rcx
    jmp calc_result
    ;while
    ; get index rdi[0] in rsi   OK
    ; Si pas trouve return      OK
    ; rax += rsi[index]         OK
    ; si finit return           OK
    ; pas fini rax * 10         OK
    ; while



    

return:
    ; mov rax, 21
    imul    rax, rdx    ; get signe
    ret

return_err:
    xor rax, rax    ; return 0 when error
    ret

return_err_duplicate:
    pop rax
    xor rax, rax    ; return 0
    ret