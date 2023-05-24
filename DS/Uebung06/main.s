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
    # loop - end
    # end
    movq $0, %rax
    popq %rbp
    ret