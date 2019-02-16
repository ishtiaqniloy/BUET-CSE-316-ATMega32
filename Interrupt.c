#include<avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>

#define F_CPU 1000000

ISR(INT2_vect){

	PORTB = PORTB^1;
	_delay_ms(200);

	GIFR = GIFR | (1<<INT2);

}

int main(void){
	DDRB = 1;
	PORTB = 0;


	GICR = GICR | 0b00100000;

	MCUCSR = MCUCSR & 0b10111111;	//active high switch, falling edge interrupt for int2 at PB2
	sei();


	while(1){

	}

}
