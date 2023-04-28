.section .data
decstr:
    .asciz "%ld\n"

hexstr:
    .asciz "0x%lX\n"

.section .text

.globl main
.type main, @function

main:

    pushq %rbp

    movq $50000000000, %rax

    # work around
    # create bitmask for upper bytes
    # remove lower 32 bit from rax
    # write new eax value with or
    movq  $1, %rbx
    salq $32, %rbx
    subq $1, %rbx
    salq $32, %rbx
    andq %rbx, %rax
    orq     $50000000, %rax

    movw       $50000, %ax
    movb          $50, %al
    movb           $5, %ah

    mov %rax, %rbx # save value since rax can be overwritten

    mov $decstr, %rdi
    mov %rbx, %rsi
    call printf

    mov $hexstr , %rdi
    mov %rbx, %rsi
    call printf 

    mov $0, %rax
    pop %rbp
    ret
