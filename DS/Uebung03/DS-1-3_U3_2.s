.section .rodata
outstring:
    .asciz " 'A' - 0454 + 0x12345678 = 0x%lX\n"

.section .text
.globl main
.type main, @function

main:
    pushq %rbp

    # a)
    # wert berechnen
    xor %esi, %esi # esi bereinigen.
    movb $'A', %sil # 8 bit size
    subw $0454, %si # 16 bit size
    addl $0x12345678, %esi # 32 bit size

    # b)
    # esi auf rsi vergrößern unter beibehalten der signedness
    movslq %esi, %rsi

    # c)
    # wert ausgeben
    mov $outstring, %rdi
    call printf

    popq %rbp

    mov $0, %rax
    ret
