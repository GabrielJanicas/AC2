#include <detpic32.h>

void delay(unsigned int ms)
{
	while(readCoreTimer() < 20000 * ms);
}

int main(void)
{
	unsigned char segment;
	// enable display low (RD5) and disable display high (RD6)
	// configure RB8-RB14 as outputs
	// configure RD5-RD6 as outputs
	while(1)
	{
		segment = 1;
		for(i=0; i < 7; i++)
		{
		TRISB = TRISB & 0x80FF;
		// send "segment" value to display
		// wait 0.5 second
		segment = segment << 1;
		}
		// toggle display selection
	}
	return 0;
}