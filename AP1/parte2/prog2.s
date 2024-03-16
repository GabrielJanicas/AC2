    .equ getChar, 2
    .equ putChar, 3

    .data
    .text
    .globl main
	
main:
do:		li	$v0, getChar
		syscall
		move	$t0, $v0
		li	$v0, putChar
		move	$a0, $t0
		addiu	$a0, $a0, 1
		syscall
		bne	$t0, '\n', do

		li	$v0, 0
		jr	$ra