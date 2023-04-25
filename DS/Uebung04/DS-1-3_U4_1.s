.section .text
.globl _start

_start:
    movq $50000000000,  %rax
    movl $50000000,     %eax
    movw $50000,        %ax
    movb $50,           %al
    movb $5,            %ah