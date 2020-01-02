#include "STD_Types.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



/*
 * Description : Set the desired Led on.
 * Inputs  : void
 * Outputs : void
 * */
void LED_voidSetLedOn(void)
{
	#if	LED_MODE == LED_FORWARD_CONNECTION
	DIO_EnuSetPinValue(LED_PORT,LED_PIN,DIO_PIN_HIGH);
	#elif LED_MODE == LED_REVERSE_CONNECTION
	DIO_EnuSetPinValue(LED_PORT,LED_PIN,DIO_PIN_LOW);	
	#endif
}

/*
 * Description : Set the desired Led off.
 * Inputs  : void
 * Outputs : void
 * */
void LED_voidSetLedOff(void)
{
	#if	LED_MODE == LED_FORWARD_CONNECTION
	DIO_EnuSetPinValue(LED_PORT,LED_PIN,DIO_PIN_LOW);
	#elif LED_MODE == LED_REVERSE_CONNECTION
	DIO_EnuSetPinValue(LED_PORT,LED_PIN,DIO_PIN_HIGH);	
	#endif
}