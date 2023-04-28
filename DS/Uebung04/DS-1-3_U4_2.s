.section .data

formatstr:
    .asciz "shift: %d, leaq: %d\n"

.section .text

.globl main
.type main, @function

main:

    pushq %rbp

    # 3 * 304 – 7
    movq $304, %rsi # save 304 in rsi (first argument for printf format string)
    mov $1, %cl # move 1 into lower bit of rcx to later double rsi 
    shlq %cl, %rsi # double rsi
    addq $304, %rsi # add 304 to get * 3
    leaq -7(%rsi), %rdx # add -7 and write in second argument for printf format string

    mov $formatstr, %rdi
    call printf

    mov $0, %rax
    pop %rbp
    ret
