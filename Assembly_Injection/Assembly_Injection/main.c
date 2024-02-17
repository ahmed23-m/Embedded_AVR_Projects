/*
 * Assembly_Injection.c
 *
 * Created: 2024/2/12 3:37:57 AM
 * Author : Ahmed Adel
 */ 

#include <avr/io.h>

int main(void) {
	// Configure PB5 as an output
	DDRB = 0b10000000;

	// Turn on the LED
	__asm(
	"sbi %[port], %[pin]" // Set bit in PORTB to turn on the LED
	:
	: [port] "I" (_SFR_IO_ADDR(PORTB)), [pin] "I" (7)
	);

	/*
	-[port] "I" (_SFR_IO_ADDR(PORTB)):
		This part defines an input operand for the assembly code.
		=>[port] is a placeholder that represents the actual value.
		=>"I" specifies that the value is an immediate constant (a compile-time constant).
		=>_SFR_IO_ADDR(PORTB) is a macro that evaluates to the address of the PORTB register.
	-[pin] "I" (7):
		This part defines another input operand.
		=>[pin] is another placeholder.
		=>"I" indicates an immediate constant.
		=>(7) specifies the value 7 as the immediate constant.
		
	-we use the sbi instruction to set a specific bit in the **PORTB** register.
	*/
	
	// Configure PB5 as an output
	DDRA = 0b01000000;

	// Turn on the LED
	__asm("sbi 0x1B, 6");	// Set bit in PORTA to turn on the LED

	while (1) {
		// Your other code here...
	}

	return 0;
}

