#include "STD_Types.h"
#include "BIT_MATH.h"

#include "LED_interface.h"


// Config to the available leds you can connect.
// You can access the port directly this way each port have an array contains 0~7 (8)pins
// the pin status should be on of those two status (LED_PIN_CONNECTED/LED_PIN_NOT_CONNECTED)
// The  mode should be LED_FORWARD_CONNECTION/LED_REVERSE_CONNECTION

u8 LED_Au8LedsConfig[LED_PORTS_COUNT][LED_PINS_COUNT][LED_MODE_AND_VALUE]= {
		{{LED_FORWARD_CONNECTION,LED_PIN_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED}},
		{{LED_FORWARD_CONNECTION,LED_PIN_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED}},
		{{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED}},
		{{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED},{LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED}}
};

/*
// an other way to edit the leds connected array
// Config to the available leds you can connect.
// You can access the port directly this way LED_Au8LedsConfig[PORT_NUMBER][PIN_NUMBER]
// PORT LED_PORTA/LED_PORTB/LED_PORTC/LED_PORTD 
// each port have an array contains LED_PIN0~7 (8)pins
// the pin status should be on of those two status (LED_PIN_CONNECTED/LED_PIN_NOT_CONNECTED)

// Port A
LED_Au8LedsConfig[LED_PORTA][LED_PIN0] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTA][LED_PIN1] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTA][LED_PIN2] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTA][LED_PIN3] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTA][LED_PIN4] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTA][LED_PIN5] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTA][LED_PIN6] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTA][LED_PIN7] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
// Port B
LED_Au8LedsConfig[LED_PORTB][LED_PIN0] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTB][LED_PIN1] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTB][LED_PIN2] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTB][LED_PIN3] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTB][LED_PIN4] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTB][LED_PIN5] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTB][LED_PIN6] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTB][LED_PIN7] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
// Port C
LED_Au8LedsConfig[LED_PORTC][LED_PIN0] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTC][LED_PIN1] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTC][LED_PIN2] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTC][LED_PIN3] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTC][LED_PIN4] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTC][LED_PIN5] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTC][LED_PIN6] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTC][LED_PIN7] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
// Port D
LED_Au8LedsConfig[LED_PORTD][LED_PIN0] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTD][LED_PIN1] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTD][LED_PIN2] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTD][LED_PIN3] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTD][LED_PIN4] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTD][LED_PIN5] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTD][LED_PIN6] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
LED_Au8LedsConfig[LED_PORTD][LED_PIN7] = {LED_FORWARD_CONNECTION,LED_PIN_NOT_CONNECTED};
*/
