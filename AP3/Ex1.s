	.equ TRISE,0x6100
	.equ TRISB,0x6040
	.equ PORTE,0X6110
	.equ PORTB,0x6050
	.equ LATE,0x6120

	.data
	.text
	.globl main
main:
	lui $s0,0xBF88

	lw $t0,TRISE($s0)
	andi $t0,$t0,0xFFFE	#colocar RE0 como entrada
	sw $t0,TRISE($s0)

	lw $t1,TRISB($s0)
	ori $t1,$t1,0x0001	#colocar RB0 como saída
	sw $t1,TRISB($s0)

loop:
	lw $t0,PORTB($s0)
	lw $t1,LATE($s0)
	andi $t0,$t0,0x0001
	andi $t1,$t1,0xFFFE
	or $t0,$t0,$t1
	sw $t0,LATE($s0)
	j loop
	lw $ra,0($sp)
	lw $s0,4($sp)
	addiu $sp,$sp,8
	jr $ra