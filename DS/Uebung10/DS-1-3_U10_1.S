.section .data
.align 16
    A:
        .float 1.1, 1.2, 1.3, /**/ 2.1, 2.2, 2.3

.align 16
    B:
        .float 1.1, 1.2, /**/ 2.1, 2.2, /**/ 3.1, 3.2

.section .text
.globl exit
.type exit, @function
exit:
    mov $60, %rax
    mov $0, %rdi
    syscall

.globl _start     
_start:
    //! C wird dann so erechnet:
    //! c11: A[0] * B[0] + A[1] * B[2] + A[2] * B[4]
    //! c12: A[0] * B[1] + A[1] * B[3] + A[2] * B[5]
    //! c21: A[3] * B[0] + A[4] * B[2] + A[5] * B[4]
    //! c22: A[3] * B[1] + A[4] * B[3] + A[5] * B[5]

    //! damit kann man die operationen in 3 multiplikationen und 2 vektor additionen zerlegen.

    //! für die multiplikationen brauchen wir also diese 3 allignments für die Multiplikationen:
    //! 1.
    //! A[0] A[0] A[3] A[3]
    //! B[0] B[1] B[0] B[1]
    //! 2.
    //! A[1] A[1] A[4] A[4]
    //! B[2] B[3] B[2] B[3]
    //! 3.
    //! A[2] A[2] A[5] A[5]
    //! B[4] B[5] B[4] B[5]

    //! begin vom program
    //! Store A into xmm1 and xmm2
    vmovaps A, %xmm1

    movq $A, %rdi
    addq $32, %rdi
    vmovaps (%rdi), %xmm2

    //! Store B in xmm3 and xmm4
    vmovaps B, %xmm3

    movq $B, %rdi
    addq $32, %rdi
    vmovaps (%rdi), %xmm4

    //! 1. calulation
    // first operand xmm5
    vshufps $0b00001111, %xmm1, %xmm1, %xmm5
    // second operand xmm6
    vshufps $0b00010001, %xmm3, %xmm3, %xmm6 

    // store result into xmm7
    vmulps %xmm5, %xmm6, %xmm7

    //! 2. calculation
    // first operand xmm5
    vshufps $0b01010000, %xmm1, %xmm2, %xmm5
    // second operand xmm6
    vshufps $0b10111011, %xmm3, %xmm3, %xmm6

    // store result into xmm8
    vmulps %xmm5, %xmm6, %xmm8

    //! 3. calculation
    // first operand xmm5
    vshufps $0b10101010, %xmm1, %xmm2, %xmm5
    // second operand xmm6
    vshufps $0b00010010, %xmm4, %xmm4, %xmm6

    // store result into xmm9
    vmulps %xmm5, %xmm6, %xmm9

    //! add results together.
    vaddps %xmm7, %xmm8, %xmm0
    vaddps %xmm9, %xmm0, %xmm0
    //! result is in xmm0 now

   call exit
