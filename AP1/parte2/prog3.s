# int main(void)
# {
# 	char c;
# 	int cnt = 0;
# do {
# 	c = inkey();
# 	if( c != 0 )
# 	putChar( c );
# else
# 	putChar('.');
# 	cnt++;
# } while( c != '\n' );
# 	printInt(cnt, 10);
# 	return 0;
# }

    .equ putChar, 3
	.equ inkey,1
	.equ print_int,6

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
