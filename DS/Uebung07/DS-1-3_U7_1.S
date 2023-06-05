.section .rodata
charstr:
    .ascii "%c"

word:
    .asciz "ABC"

.section .text

#rsi: word
#rdx: len
printReverse:
    pushq %rbp

    movq $0, %rdi
    cmpq %rdx, %rdi
    je ret_reverse

    #movq %rdi, %r12
    pushq %rsi

    subq $1, %rdx
    #movq %rdx, %r13
    pushq %rdx

#if 1
    movb (%rsi, %rdx), %sil
    movq $charstr, %rdi
    call printf
#else
    xorq %rsi, %rsi
    movb (%rsi, %rdx), %sil
    call putchar
#endif
    
    # movq %r12, %rdi
    # movq %r13, %rdx
    popq %rdx
    popq %rsi

    call printReverse

ret_reverse:
    popq %rbp
    ret

.globl main
.type main, @function

main:
    pushq %rbp

    #! easier for register shifting
    movq $word, %rsi
    movq $3, %rdx
    call printReverse
    # end
    movq $0, %rax
    popq %rbp
    ret
