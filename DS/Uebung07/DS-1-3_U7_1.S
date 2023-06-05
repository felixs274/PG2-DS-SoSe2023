.section .rodata
charstr:
    .asciz "%c"

emptyStr:
    .asciz ""

word:
    .ascii "ABC"

.section .text

#rsi: word
#rdx: len
printReverse:
    pushq %rbp

    movq $0, %rdi
    cmpq %rdx, %rdi
    je ret_reverse

    pushq %rsi

    decq %rdx
    pushq %rdx

    movb (%rsi, %rdx), %sil
    movq $charstr, %rdi
    call printf

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

    movq $emptyStr, %rdi
    call puts

    # end
    movq $0, %rax
    popq %rbp
    ret
