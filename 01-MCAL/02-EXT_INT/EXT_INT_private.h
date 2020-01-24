/*
 * EXT_INT_private.h
 *
 *  Created on: Jan 12, 2020
 *      Author: sasafizo
 */

#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_

/*__________________________________________________________________________________________
 * VECTOR FUNCTIONS :-
 * _________________________________________________________________________________________
 * */
void __vector_1(void)__attribute((signal,used));
void __vector_2(void)__attribute((signal,used));
void __vector_3(void)__attribute((signal,used));
/*__________________________________________________________________________________________
 * CALLBACK FUNCTIONS PROTOTYPE :-
 * _________________________________________________________________________________________
 * */
static volatile void (*EXT_INT_voidCallBackInt0)(void) = 0;
static volatile void (*EXT_INT_voidCallBackInt1)(void) = 0;
static volatile void (*EXT_INT_voidCallBackInt2)(void) = 0;


#endif /* EXT_INT_PRIVATE_H_ */
