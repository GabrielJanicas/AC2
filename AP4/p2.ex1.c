#include <detpic32.h>

void delay(unsigned int ms){
	while(readCoreTimer() < 20000 * ms);
}


int main(void)
{
	TRISB = TRISB & 0x80FF;
	TRISDbits.TRISD5 = 0;
	TRISDbits.TRISD6 = 0;


	LATDbits.LATD5 = 1;
	LATDbits.LATD6 = 0;

	while(1){
		char user_input = getChar();
		putChar(user_input);
		switch (user_input)
		{
		case 0x41:
		case 0x61:
			LATB = (LATB & 0x80FF) | 0x0100;
			break;
		case 0x42:
		case 0x62:
			LATB = (LATB & 0x80FF) | 0x0200;
			break;
		case 0x43:
		case 0x63:
			LATB = (LATB & 0x80FF) | 0x0400;
			break;
		case 0x44:
		case 0x64:
			LATB = (LATB & 0x80FF) | 0x0800;
			break;
		case 0x45:
		case 0x65:
			LATB = (LATB & 0x80FF) | 0x1000;
			break;
		case 0x46:
		case 0x66:
			LATB = (LATB & 0x80FF) | 0x2000;
			break;
		case 0x47:
		case 0x67:
			LATB = (LATB & 0x80FF) | 0x4000;
			break;
		case 0x0A:
            putChar('s');
            LATDbits.LATD5 = !LATDbits.LATD5;
            LATDbits.LATD6 = !LATDbits.LATD6;
		default:
			break;
		}
	}
}
