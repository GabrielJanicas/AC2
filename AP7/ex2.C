#include <detpic32.h>

volatile unsigned char voltage = 0; // Global variable
int main(void)
{
unsigned int cnt = 0;
// Configure all (digital I/O, analog input, A/D module, interrupts)
...
EnableInterrupts(); // Global Interrupt Enable
while(1)
{
if(cnt == 0) // 0, 200 ms, 400 ms, ... (5 samples/second)
{
// Start A/D conversion
}
// Send "voltage" value to displays
cnt = (cnt + 1) % ??;
// Wait ?? ms
}
return 0;
}
void _int_(VECTOR) isr_adc(void)
{
// Read 8 samples (ADC1BUF0, ..., ADC1BUF7) and calculate average
// Calculate voltage amplitude
// Convert voltage amplitude to decimal and store the result in the
global variable "voltage"
// Reset AD1IF flag
}