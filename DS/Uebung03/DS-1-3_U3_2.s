.section .rodata
outstring:
    .asciz " 'A' - 0454 + 0x12345678 = 0x%lX\n"

.section .text
.globl main
.type main, @function

main:
    pushq %rbp

    xor %esi, %esi # clear register so we don't have leftover data.
    movb $'A', %sil # 8 bit size
    subw $0454, %si # 16 bit size
    addl $0x12345678, %esi # 32 bit size
    movslq %esi, %rsi

    mov $outstring, %rdi
    call printf

    mov $0, %rdi # return 0 as return value. We didn't xor to be more descriptive
    call exit

    pop %rbp
