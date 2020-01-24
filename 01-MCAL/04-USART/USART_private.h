/*
 * USART_private.h
 *
 *  Created on: Jan 14, 2020
 *      Author: sasafizo
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define USART_NO_PARITY				999
#define USART_EVEN_PARITY			1
#define USART_ODD_PARITY			2

#define USART_CHAR_SIZE_5BIT		999
#define USART_CHAR_SIZE_6BIT		1
#define USART_CHAR_SIZE_7BIT		2
#define USART_CHAR_SIZE_8BIT		3


#define USART_BIT_HIGH				1
#define USART_BIT_LOW				999


#define ENABLED		1
#define DISABLED	999

#define SYNCHRONOUS		1
#define ASYNCHRONOUS	999

#define	TWO_STOP_BIT	1
#define	ONE_STOP_BIT	999

#define TRANSMIT_ON_FALLING_RECEIVE_ON_RISING	1
#define TRANSMIT_ON_RISING_RECEIVE_ON_FALLING	999

#define ISR(NO)	void __vector_##NO(void)__attribute__((signal)); \
	void __vector_##NO(void)


/*
 *
 * 		ASY
 *
 * */
void (*USART_voidPointerToFunction)(void);
void (*USART_voidReceivePointerToFunction)(void);

const static char * u8Data = NULL_POINTER;
static u8 u8DataIndex;

static char * u8ReceivedData = NULL_POINTER;
static u8 u8ReceivedDataSize;
static u8 u8ReceivedDataIndex;

#endif /* USART_PRIVATE_H_ */
