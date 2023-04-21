.section .text
.globl _start

_start:
    # a)
    # wert auf stack legen
    sub $8, %rsp # 8 bytes auf den stack allokieren
    movq $3, (%rsp) # 3 reinschreiben
    add $4, (%rsp) # 4 addieren

    # b)
    # wert ausgeben
    addl $'0', (%rsp) # convert to ascii
    movq $'\n', 1(%rsp) # add new line

    mov $1, %rdi # write to stdout
    mov %rsp, %rsi # write ascii value
    mov $2, %rdx # 2 bytes ausgeben
    movq $1, %rax # write syscall
    syscall

    # c)
    # speicher freigeben
    add $8, %rsp # die 8 bytes wieder deallokieren

    # exit 
    mov $60, %rax
    mov $0, %rdi
    syscall
