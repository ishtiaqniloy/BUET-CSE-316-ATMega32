#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 1000000

int main(void){

	DDRA = 0;
	DDRB = 0XFF;

	PORTB = 0;

	while(1){
		if( PINA & 0b00000001){	//active high switch at A0
				PORTB = PORTB^1;

				_delay_ms(200);

		}
	}

}
