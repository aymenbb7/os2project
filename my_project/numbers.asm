section .text
global lcm_asm
global int_to_binary_asm
global factorial_asm

; LCM calculation
lcm_asm:
    push rbp
    mov rbp, rsp
    
    mov eax, edi
    mov ebx, esi
    
.gcd_loop:
    cmp ebx, 0
    je .gcd_done
    xor edx, edx
    div ebx
    mov eax, ebx
    mov ebx, edx
    jmp .gcd_loop
    
.gcd_done:
    mov ecx, eax
    mov eax, edi
    mul esi
    div ecx
    
    pop rbp
    ret

; Convert integer to binary string
int_to_binary_asm:
    push rbp
    mov rbp, rsp
    push rbx
    push r12
    
    mov eax, edi
    mov r12, rsi
    
    mov ecx, 32
    lea r12, [r12+32]
    mov byte [r12], 0
    
.convert_loop:
    dec r12
    mov ebx, eax
    shr ebx, cl
    and ebx, 1
    add bl, '0'
    mov [r12], bl
    loop .convert_loop
    
    pop r12
    pop rbx
    pop rbp
    ret

; Factorial calculation
factorial_asm:
    mov eax, 1
    test edi, edi
    jz .done
    
.loop:
    mul edi
    dec edi
    jnz .loop
    
.done:
    ret
