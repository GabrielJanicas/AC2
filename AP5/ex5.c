#include <detpic32.h>

void send2displays(unsigned char value)
{
	static const char display7Scodes[] = {0x3F,0X06,0X5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
	static char displayFlag = 0;
	int dl = value & 0x0F;
	int dh = value >> 4;
	if (displayFlag == 0){
		LATD = (LATD & 0xFF9F) | 0x0020;
		LATB = (LATB & 0x80FF) | (display7Scodes[dl]) << 8;
		displayFlag = 1;
	}
	else{
		LATD = (LATD & 0xFF9F) | 0x0040;
		LATB = (LATB & 0x80FF) | (display7Scodes[dh]) << 8;
		displayFlag = 0;
	}
}

void delay(unsigned int ms){
	resetCoreTimer();
	while(readCoreTimer() < 20000 * ms);
}

int main(void)
{
// declare variables
// initialize ports
TRISB = TRISB & 0x80FF;
TRISD = TRISD & 0xFF9F;
counter = 0;
while(1){
i = 0;
}
do{
	send2displays(counter);
	delay(20);// wait 20 ms (1/50Hz)
} 
while(++i < );{
	counter++;
}
// increment counter (mod 256)
return 0;
}