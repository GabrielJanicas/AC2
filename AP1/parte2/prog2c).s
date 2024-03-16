	.equ putChar,3
	.equ inkey,1
	.equ printInt,6
	
	.data	
	.text 
	.globl main
	
main: 
	li $t0,0
do:
	li	$v0,inkey	# c = inkey()
	syscall
	move	$t0,$v0
if:	beq	$t1, $0, else
	
	li $v0,putChar
	move $a0,$t0	
	syscall
	addiu $t0,1
	
	j endif
	
else:
	li $v0,putChar
	li $a0,'.'
	syscall
	addiu $t0,1

endif:
	bne $t0,'\n',do
	
	li $v0,0
	jr $ra
	
