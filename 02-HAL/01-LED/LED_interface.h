#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

// include MCAL drivers
#include "DIO_interface.h"
// include current driver header files
#include "LED_private.h"

/*
 * Description : Configure the driver to be ready to use.
 * Inputs  : void
 * Outputs : void
 * */
void LED_voidInit(void);

/*
 * Description : Set the desired Led on.
 * Inputs  : void
 * Outputs : void
 * */
void LED_voidSetLedOn(u8 Copy_u8LedPort,u8 Copy_u8LedPin);

/*
 * Description : Set the desired Led off.
 * Inputs  : void
 * Outputs : void
 * */
void LED_voidSetLedOff(u8 Copy_u8LedPort,u8 Copy_u8LedPin);




#endif
