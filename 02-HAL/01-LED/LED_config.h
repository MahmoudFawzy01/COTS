#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

// add Led to the desired pin
#define LED_PIN		DIO_PIN_0

// Configure the desired port that pin connected to.
#define LED_PORT	DIO_PORTA


// Configure the desired connection mode of the led.
// LED_REVERSE_CONNECTION/LED_FORWARD_CONNECTION
// LED_FORWARD_CONNECTION : apply 5 volt
// LED_REVERSE_CONNECTION : apply 0 volt
#define LED_MODE	LED_FORWARD_CONNECTION



#endif