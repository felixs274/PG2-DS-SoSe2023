.section .rodata
    format:
        .asciz "Sum = %ld\n"
.section .bss
    .lcomm results 16
.section .data
    .align 16
    farr1:
        .float 13.99, 17.4, 2.0, 3.0

.align 16
     :
        .float -214.0, 0.75, 5.5, 30.52

.section .text
.globl main     
.type main, @function
main:
    pushq %rbp
    #...
    subq $32, %rsp

    # calc 1. 13.99 - 17.4
    movss $farr1, %xmm0
    subss ($farr1, 4,), %xmm0
    movss %xmm0, (%rsp)
    # ...
    # calc 2. √2.0 + √3.0
    movss ($farr1, 8,) %xmm0
    sqrtss %xmm0, %xmm0

    movss ($farr1, 12,) %xmm1
    sqrtss %xmm1, %xmm1

    addss %xmm1, %xmm0

    movss %xmm0, 4(%rsp)

    # calc 3.  -214.0 * 0.75
    movss ($farr1, 8,) %xmm0
    movss 0.75, %xmm1
    mulss %xmm1, %xmm0
    movss %xmm0, 8(%rsp

    # calc 4. max(5.52, 30.52)
    movss ($farr, 12,), %xmm0
    movss ($farr, 16), %xmm1

    maxss %xmm1, %xmm0

    movss %xmm0, 12(%rsp) 

    # call truncDec
    leaq results, %rdi
    call truncDec

    # printf
    leaq format, %rdi
    movq %rax, %rsi
    call printf

    # exit 0
    movq $0, %rax
    popq %rbp
    ret

.globl truncDec
.type truncDec, @function
truncDec:
    push     %rbp
    mov      %rsp, %rbp
    xor      %eax, %eax
    xorps    %xmm0, %xmm0

    mov      $0, %rcx

    loop:
        cmp      $4, %rcx
        jge      lend

        movss    (%rdi,%rcx,4), %xmm1

        addss    %xmm1, %xmm0

        add      $1, %rcx
        jmp      loop

    lend:
        movss    %xmm0, (%rdi)
        movss    (%rdi), %xmm0

    pop      %rbp
    ret
