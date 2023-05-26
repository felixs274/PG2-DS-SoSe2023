.section .rodata
scanfAB:
    .asciz "%d %d"
scanfLetter:
    .asciz "%c"
puts1:
    .asciz "Enter 2 numbers from [1, 9]:"
puts2:
    .asciz "Enter +, -, * or /:"
puts3:
    .asciz "wrong entry\n"
printChoice:
    .asciz "\nFurther calculation? y/n: "
plus:
    .asciz "%d + %d = %d\n"
minus:
    .asciz "%d - %d = %d\n"
times:
    .asciz "%d * %d = %d\n"
divide:
    .asciz "%d / %d = %d\n"


# Hier die Sprungtabelle einfügen
# jump table
.align 8
.switch_table:
    .quad .case_times   # * : 0x2a
    .quad .case_plus    # + : 0x2b
    .quad .case_default #     0x2c
    .quad .case_minus   # - : 0x2d
    .quad .case_default #     0x2e
    .quad .case_divided # / : 02f


.section .bss
    .lcomm a, 4
    .lcomm b, 4
    .lcomm op, 1
    .lcomm choice, 1
.section .text
.globl main
.type main, @function


main:
    pushq %rbp


# loop - start
loop:
    movq $puts1, %rdi
    call puts
    movq $scanfAB, %rdi
    movq $a, %rsi
    movq $b, %rdx
    call scanf
    # read \n
    call getchar
    movq $puts2, %rdi
    call puts
    movq $scanfLetter, %rdi
    movq $op, %rsi
    call scanf
    # read \n
    call getchar
    # Hier switch und den Rest der Schleife einfügen
bs:
    movq $0, %rsi
    movb op, %sil
    subb $0x2a, %sil
    cmpb $6, %sil
    jae .switch_end
    jmp *.switch_table(, %rsi, 8)

.case_times:
    jmp .switch_end
.case_plus:

    movl a, %ecx 
    addl b, %ecx

    movl b, %edx
    movl a, %esi
    movq $plus, %rdi
    call printf
    jmp .switch_end
.case_minus:
    movl a, %ecx 
    subl b, %ecx

    movl b, %edx
    movl a, %esi
    movq $minus, %rdi
    call printf
    jmp .switch_end
.case_divided:

    movl a

    movl b, %edx
    movl a, %esi
    movq $divide, %rdi
    call printf
    jmp .switch_end
.case_default:
.switch_end:

    # loop - end

    movq $printChoice, %rdi
    call printf

    movq $scanfLetter, %rdi
    movq $choice, %rsi
    call scanf

    # read \n
    call getchar
    movq %rax, %rdi
    movq %rax, %r8
    call putchar

before_shit:
    cmpq $'y', %r8
    je loop

    # end
    movq $0, %rax
    popq %rbp
    ret
