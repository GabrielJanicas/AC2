#include <detpic32.h>

void delay(unsigned int ms){
	resetCoreTimer();
	while (readCoreTimer() < 20000 * ms);
}

int main(void){

	TRISE &= 0xFF03;//1111 1111 0000 0011
	TRISB |= 0x0005;//0000 0000 0000 0101

	int count = 0x0030;
	int ms = 95;

	while (1){
		LATE = (LATE & 0xFF03) | (count << 2);

		count = count >> 1;

		if (count < 0x0003){
			count = 0x0030;
		}

		if (PORTBbits.RB0 == 1 && PORTBbits.RB2 == 1){
			ms = 285;
		}
		else if (PORTBbits.RB0 == 0 && PORTBbits.RB2 == 0){
			ms = 95;
		}

		delay(ms);
	}
}