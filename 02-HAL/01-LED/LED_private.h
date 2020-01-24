#ifndef LED_PRIVATE_H_
#define LED_PRIVATE_H_

// LED available pins
#define LED_PIN0		DIO_PIN_0
#define LED_PIN1		DIO_PIN_1
#define LED_PIN2		DIO_PIN_2
#define LED_PIN3		DIO_PIN_3
#define LED_PIN4		DIO_PIN_4
#define LED_PIN5		DIO_PIN_5
#define LED_PIN6		DIO_PIN_6
#define LED_PIN7		DIO_PIN_7

// LED available ports
#define LED_PORTA	DIO_PORTA
#define LED_PORTB	DIO_PORTB
#define LED_PORTC	DIO_PORTC
#define LED_PORTD	DIO_PORTD

// LED available ports/pins count
#define LED_PORTS_COUNT		4
#define LED_PINS_COUNT		8
#define LED_MODE_AND_VALUE	2
#define LED_MODE_Index		0
#define LED_VALUE_Index		1


// used at LED array if there are no led connected at the port or the pin
#define LED_PIN_NOT_CONNECTED		0
#define LED_PIN_CONNECTED			1

// LED Modes 
// LED_FORWARD_CONNECTION means that led anode is connected to the current pin and the cathode is already connected to gnd
// LED_REVERSE_CONNECTION means that led cathode is connected to the pin and the anode is already connected to vcc (5v)
#define LED_FORWARD_CONNECTION		1   // forward apply 5 volt
#define LED_REVERSE_CONNECTION		0   // reverse apply 0 volt

#endif
