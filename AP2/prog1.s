# A frequência do incremento do counter é de 1 Hz.

# int main(void)
# {
# 	int counter = 0;
# 	while(1)
#	{
#		putChar('\r'); // cursor regressa ao inicio da linha no ecrã
# 		printInt(counter, 10 | 4 << 16); // Ver nota de rodapé 1
# 		resetCoreTimer();
# 		while(readCoreTimer() < 200000);
# 		counter++;
# 	}
# 		return 0;
# }

	.equ READ_CORE_TIMER,11
	.equ RESET_CORE_TIMER,12
	.equ PUT_CHAR,3
	.equ PRINT_INT,6
	.data
	.text
	.globl main

main:	
		li $t0,0 	# counter=0
while: 				# while (1) {
		li $v0,RESET_CORE_TIMER #
		syscall # resetCoreTimer()
while1:	
		li $v0,READ_CORE_TIMER
		syscall
		bge $v0,200000,endw
		j while1

endw:	
		li $v0,PRINT_INT
		move $a0,$t0
		li $a1,4
		sll $a1,$a1,16
		ori $a1,$a1,10
		syscall

		addiu $t0,$t0,1 

		li $a0,'\r'
		li $v0,PUT_CHAR
		syscall

		j while # }

		li $v0,0	
		jr $ra 