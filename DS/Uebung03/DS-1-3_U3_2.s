.section .rodata
outstring:
    .asciz " 'A' - 0454 + 0x12345678 = 0x%X\n"

.section .text
.globl main
.type main, @function

main:
    pushq %rbp

    xor %rsi, %rsi # clear register so we dont have leftover data
    movb $'A', %sil # 8 bit size
    subw $454, %si # 16 bit size
    addl $0x12345678, %esi # 32 bit size
    mov $outstring, %rdi
    call printf

    mov $0, %rdi
    call exit
