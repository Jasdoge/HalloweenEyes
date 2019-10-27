#include <arduino.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>

const unsigned int WAKE_TIME = 60000;
const byte LIGHTS[4] = {PB0, PB1, PB2, PB3};
const byte PIN_SENSOR = PCINT4;
unsigned long WOKE = 0;

ISR(PCINT0_vect){}

void sleep(){

	GIMSK |= _BV(PCIE);    // turns on pin change interrupts
  	PCMSK |= _BV(PIN_SENSOR);    // turn on interrupt on sensor pin

	// Enters sleep mode
    //sleep_enable();                          // enables the sleep bit in the mcucr register so sleep is possible
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);    // replaces above statement
	sleep_mode();

  	PCMSK &= ~_BV(PIN_SENSOR);    // interrupt off

}

// Animates the eyes up
void wakeAnim(){

	byte order[4] = {0xFF,0xFF,0xFF,0xFF};
	for( byte i=0; i<4; ++i ){
		const byte slot = millis()%(4-i);
		byte n = 0;
		for( byte s=0; s<4; ++s ){
			if( order[s] == 0xFF ){
				if( n == slot ){
					order[s] = LIGHTS[i];
					break;
				}
				++n;
			}
		}
	}

	for( byte i=0; i<4; ++i ){
		digitalWrite(order[i], HIGH);
		delay(100+(millis()%1000));
	}

}

void setup(){
	
	for( byte i=0; i<4; ++i ){

		pinMode(LIGHTS[i], OUTPUT);
		digitalWrite(LIGHTS[i], LOW);
	
	}

	ADCSRA &= ~_BV(ADEN); // disable the ADC
	wakeAnim();

}

void loop(){

	const unsigned long ms = millis();
	if( ms-WOKE < WAKE_TIME ){

		
		const byte pin = LIGHTS[ms%4];
		digitalWrite(pin, LOW);
		delay(100);
		digitalWrite(pin, HIGH);

		delay((ms%750)+200);
		return;
	}


	for( byte i=0; i<4; ++i ){
		digitalWrite(LIGHTS[i], LOW);
	}
	sleep();
	WOKE = millis();
	

}
