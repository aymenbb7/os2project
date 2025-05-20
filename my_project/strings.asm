section .text
global is_empty_asm
global strlen_asm

is_empty_asm:
    mov al, byte [rdi]
    test al, al
    sete al
    ret

strlen_asm:
    xor rax, rax
    
.count_loop:
    cmp byte [rdi + rax], 0
    je .done
    inc rax
    jmp .count_loop
    
.done:
    ret
