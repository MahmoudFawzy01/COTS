/*
 * SWITCH_PROGRAME.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */
#include "STD_Types.h"
#include "SWITCH_INTERFACE.h"
#include "SWITCH_PRIVATE.h"
#include "DIO_INTERFACE.h"
#include "SWITCH_CONFIGURATION.h"


ErrorStatus SWITCH_u8GetSwitchtatus(u8 * copy_u8SwitchSatatus)	/*function to get the status of the switch*/
{
	DIO_EnuGetPinValue(SWITCH_1_PIN,copy_u8SwitchSatatus); /* get pin value*/
}
