// Include the arduino library
#include <arduino.h>
// Include the libraries needed to use sleep
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <avr/power.h>

const unsigned int WAKE_TIME = 60000;				// How long should it be awake and blinking before shutting down? In milliseconds.
const byte LIGHTS[4] = {PB0, PB1, PB2, PB3};		// Pins the lights are bound to. See circuit file in assets folder.
const byte PIN_SENSOR = PCINT4;						// Sensor pin
unsigned long WOKE = 0;								// millis() reading of woke time

ISR(PCINT0_vect){}									// Needed to prevent crashing

// Activates sleep mode
void sleep(){

	GIMSK |= _BV(PCIE);    // turns on pin change interrupts
  	PCMSK |= _BV(PIN_SENSOR);    // turn on interrupt on sensor pin

	// Enters sleep mode
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_mode();

  	PCMSK &= ~_BV(PIN_SENSOR);    // interrupt off when waking up

}

void setup(){
	
	ADCSRA &= ~_BV(ADEN); // disable the ADC to save power

	byte i;
	// Set pin modes and turn on all lights on boot so you can see that they all work.
	for( i=0; i<4; ++i ){

		pinMode(LIGHTS[i], OUTPUT);
		digitalWrite(LIGHTS[i], HIGH);
	
	}

	// Wait 2 sec before turning them off
	delay(2000);
	for( i=0; i<4; ++i )
		digitalWrite(LIGHTS[i], LOW);

}


void loop(){

	// Blinks the eyes for WAKE_TIME milliseconds at random intervals.
	// This way the eyes will light up somewhat randomly, all eyes might not light up. But I thought it was a neat effect.
	const unsigned long ms = millis();
	if( ms-WOKE < WAKE_TIME ){

		const byte pin = LIGHTS[ms%4];
		digitalWrite(pin, LOW);
		delay(100);
		digitalWrite(pin, HIGH);

		delay((ms%750)+200);
		return;
		
	}

	// Turn off after that
	for( byte i=0; i<4; ++i )
		digitalWrite(LIGHTS[i], LOW);
	sleep();
	WOKE = millis();
	

}
