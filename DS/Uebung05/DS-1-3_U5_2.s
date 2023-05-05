.section .text
.globl signum
.type signum, @function
signum:
    # arg1(rdi): number to check sign for 
    movq %rdi, %rsi
    movq $0, %rdi
    cmpq %rdi, %rsi
    js negative # jump to negative if number is negative
    je zero # jum to zero if zero flag is set
    # if we dont jump the value is positive and we go into the positive label 
    
    positive:
        mov $1, %rax
        ret

    zero:
        mov $0, %rax
        ret

    negative:
        mov $-1, %rax
        ret

.globl main
.type main, @function
main:
    pushq %rbp
    movq $-1000, %rdi
    call signum
    movq $0, %rdi
    call signum
    movq $1000, %rdi
    call signum
    # end
    movq $1, %rax
    popq %rbp
    ret
