.set SYS_EXIT, 60

.section .text
exit:
    mov $0, %rdi # exit with return code 0
    mov $SYS_EXIT, %rax 
    syscall

.globl _start
_start:
    # ((200 % 24) + (200 / 24)) * ((100 % 15) + (100 / 15))

    movq $200, %rax # move 200 in rax for divide
    movq $24, %rdi # move 24 into rdi for divide
    divq %rdi # unsinged divide %rdx:%rax by %rdi, % is in rdx, / is in rax

    addq %rax, %rdx # add / and %
    movq %rdx, %r8 # store value in r8

    movq $100, %rax # move 100 in rax for divide
    movq $15, %rdi # move 15 into rdi for divide
    cqto # sign extend %rax to %rdx
    div %rdi # unsigned divide %rax by %rdi, % is in rdx, / is in rax

    addq %rdx, %rax # add / and %
    mulq %r8 # multiply %rax with %r8, store result in rdx:rax

    # the final value is in %rbx:%rax
    jmp exit
