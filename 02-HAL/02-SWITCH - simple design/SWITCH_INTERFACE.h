/*
 * SWITCH_INTERFACE.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: user
 */

#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#define SWITCH_PRESSED 0	/*SWITCH IS PRESSED*/
#define SWITCH_NOT_PRESSED 1	/*SWITCH IS NOT PRESSED*/



ErroStatus SWITCH_u8GetSwitchtatus(u8 * copy_u8SwitchSatatus);	/*function to get the status of the switch*/


#endif /* SWITCH_INTERFACE_H_ */
