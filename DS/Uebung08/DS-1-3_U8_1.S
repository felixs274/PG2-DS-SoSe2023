.section .data

.section .rodata
outstr:
	.asciz "Char: %c\nInt: %d\nPnt: %p (=%d)\n\n"
sumstr:
	.asciz "Sum: %d\n"

.section .bss
.comm obj1, 13, 8
.comm obj2, 16, 8
.comm obj3, 13, 8


.section .text
.globl main
main:
    push %rbp
    
    # Create struct obj1
    movq $obj1, %r9	# Move Adress of obj into %r9
    movb $'a', (%r9)	# Move char "a" into first section of %r9
    movl $42, 1(%r9)	# Move int 42 into %r9 and skip one byte because of the char
    leaq 1(%r9), %rax	# Load Adress of the Int into %rax
    movq %rax, 5(%r9)	# Move that Adress into the last section of obj1 and skip five bytes because of the char & int
    
    movb (%r9), %sil	# Move Char into 2. Argument %sil
    movl 1(%r9), %edx	# Move Int into 3. Argument %edx
    movq 5(%r9), %rcx	# Move Pointer of Int into 4. Argument %rcx
    movl (%rax), %r8d	# Move dereferenced Pointer on Int into 5. Argument %r8d

    movq $outstr, %rdi
    movq $0, %rax
    call printf


    # Create struct obj2
    movq $obj2, %r9	# Move Adress of obj into %r9
    movq $0, (%r9)	# Fill entire struct obj2 with zeros
    movb $'b', (%r9)	# Move char "b" into first section of %r9
    movl $43, 4(%r9)	# Move int 43 into %r9 and skip four bytes because of the char
    leaq 4(%r9), %rax	# Load Adress of the Int into %rax
    movq %rax, 8(%r9)	# Move that Adress into the last section of obj1 and skip eight bytes because of the char & int
    
    movb (%r9), %sil	# Move Char into 2. Argument %sil
    movl 4(%r9), %edx	# Move Int into 3. Argument %edx
    movq 8(%r9), %rcx	# Move Pointer of Int into 4. Argument %rcx
    movl (%rax), %r8d	# Move dereferenced Pointer on Int into 5. Argument %r8d

    movq $outstr, %rdi
    movq $0, %rax
    call printf


    # Create struct obj3
    movq $obj3, %r9	# Move Adress of obj into %r9
    movl $44, (%r9)	# Move int 43 into the first section %r9 
    leaq (%r9), %rax	# Load Adress of the Int into %rax
    movq %rax, 4(%r9)	# Move that Adress into obj1 and skip 4 bytes because of the int
    movb $'c', 12(%r9)	# Move char "c" into the last section of %r9    

    movb 12(%r9), %sil	# Move Char into 2. Argument %sil
    movl (%r9), %edx	# Move Int into 3. Argument %edx
    movq 4(%r9), %rcx	# Move Pointer of Int into 4. Argument %rcx
    movl (%rax), %r8d	# Move dereferenced Pointer on Int into 5. Argument %r8d

    movq $outstr, %rdi
    movq $0, %rax
    call printf


    # Sum of the ints
    movq $obj1, %rsi
    movq $obj2, %rdx
    movq $obj3, %rcx    

    movq 5(%rsi), %rsi	# Move Int Pointer of obj1 into %rdi
    movq 8(%rdx), %rdx	# Move Int Pointer of obj2 into %rsi	
    movq 4(%rcx), %rcx	# Move Int Pointer of obj3 into %rdx

    movq (%rsi), %rsi	# Dereference Pointer
    movq (%rdx), %rdx	# Dereference Pointer
    movq (%rcx), %rcx 	# Dereference Pointer

    addq %rdx, %rsi	# obj1 + obj2 into %rsi
    addq %rcx, %rsi	# obj3 + %rsi into %rsi (2. Argument)

    movq $sumstr, %rdi
    movq $0, %rax
    call printf   

 
    ret
