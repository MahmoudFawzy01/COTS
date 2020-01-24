#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LED_interface.h"

extern u8 LED_Au8LedsConfig[LED_PORTS_COUNT][LED_PINS_COUNT][LED_MODE_AND_VALUE];

/*
 * Description : Configure the driver to be ready to use.
 * Inputs  : void
 * Outputs : void
 * */
void LED_voidInit(void)
{
	u8 Local_u8Index1,Local_u8Index2;
	
	// loop on ports
	for (Local_u8Index1 = 0 ; Local_u8Index1 < LED_PORTS_COUNT ; Local_u8Index1++)
	{
		// loop on each port pins 
		for (Local_u8Index2 = 0 ; Local_u8Index2 < LED_PINS_COUNT ; Local_u8Index2++)
		{
			// check if the pin is connected to led as configured
			if (LED_Au8LedsConfig[Local_u8Index1][Local_u8Index2][LED_VALUE_Index] == LED_PIN_CONNECTED)
			{
				// set the direction of that led to output.
				DIO_EnuSetPinDirection(Local_u8Index1,Local_u8Index2,DIO_PIN_OUTPUT);
			}
		}
	}
}


/*
 * Description : Set the desired Led on.
 * Inputs  : u8 Copy_u8LedPort,u8 Copy_u8LedPin
 * Outputs : void
 * */
void LED_voidSetLedOn(u8 Copy_u8LedPort,u8 Copy_u8LedPin)
{
	// check if the desired led is configured as connected or not
	if (LED_Au8LedsConfig[Copy_u8LedPort][Copy_u8LedPin][LED_VALUE_Index] == LED_PIN_CONNECTED)
	{
		// set the value of that led according to its mod.
		if	(LED_Au8LedsConfig[Copy_u8LedPort][Copy_u8LedPin][LED_MODE_Index] == LED_FORWARD_CONNECTION)
		{
			DIO_EnuSetPinValue(Copy_u8LedPort,Copy_u8LedPin,DIO_PIN_HIGH);
		}
		else if (LED_Au8LedsConfig[Copy_u8LedPort][Copy_u8LedPin][LED_MODE_Index] == LED_REVERSE_CONNECTION)
		{
			DIO_EnuSetPinValue(Copy_u8LedPort,Copy_u8LedPin,DIO_PIN_LOW);
		}
	}
}


/*
 * Description : Set the desired Led off.
 * Inputs  : u8 Copy_u8LedPort,u8 Copy_u8LedPin
 * Outputs : void
 * */
void LED_voidSetLedOff(u8 Copy_u8LedPort,u8 Copy_u8LedPin)
{
	// check if the desired led is configured as connected or not
	if (LED_Au8LedsConfig[Copy_u8LedPort][Copy_u8LedPin][LED_VALUE_Index] == LED_PIN_CONNECTED)
	{
		// set the value of that led according to its mod.
		if	(LED_Au8LedsConfig[Copy_u8LedPort][Copy_u8LedPin][LED_MODE_Index] == LED_FORWARD_CONNECTION)
		{
			DIO_EnuSetPinValue(Copy_u8LedPort,Copy_u8LedPin,DIO_PIN_LOW);
		}
		else if (LED_Au8LedsConfig[Copy_u8LedPort][Copy_u8LedPin][LED_MODE_Index] == LED_REVERSE_CONNECTION)
		{
			DIO_EnuSetPinValue(Copy_u8LedPort,Copy_u8LedPin,DIO_PIN_HIGH);
		}
	}	
}
