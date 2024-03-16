# void delay(unsigned int ms)
# {
# 	resetCoreTimer();
# 	while(readCoreTimer() < K * ms);
# }

	.equ READ_CORE_TIMER,11
	.equ RESET_CORE_TIMER,12
	.data
	.text
	.globl main

main:
	li $v0,READ_CORE_TIMER
	syscall
	
	li $v0,READ_CORE_TIMER
	syscall

