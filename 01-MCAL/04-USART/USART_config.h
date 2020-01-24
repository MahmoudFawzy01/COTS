/*
 * USART_config.h
 *
 *  Created on: Jan 14, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_

/*
 * USART_ODD_PARITY
 * USART_EVEN_PARITY
 * USART_NO_PARITY
 * */
#define USART_PARITY_MODE						USART_NO_PARITY

/*
 *
 * USART_CHAR_SIZE_5BIT ||
 * USART_CHAR_SIZE_6BIT ||
 * USART_CHAR_SIZE_7BIT ||
 * USART_CHAR_SIZE_8BIT ||
 *
 * */
#define  USART_u8_CHAR_SIZE						USART_CHAR_SIZE_8BIT


/**
 * Options : ENABLED
 * 			DISABLED
 * */
#define USART_DATA_REG_EMPTY_INT_ENABLE			DISABLED

/**
 * Options : ENABLED
 * 			DISABLED
 * */
#define USART_TX_COMPLETE_INT_ENABLE			DISABLED

/**
 * Options : ENABLED
 * 			DISABLED
 * */
#define USART_RX_COMPLETE_INT_ENABLE			DISABLED

/**
 * Options : ONE_STOP_BIT
 * 			TWO_STOP_BIT
 * */
#define USART_STOP_BITS							ONE_STOP_BIT

/**
 * Options : ENABLED
 * 			DISABLED
 * */
#define USART_TX_ENABLE							ENABLED

/**
 * Options : ENABLED
 * 			DISABLED
 * */
#define USART_RX_ENABLE							ENABLED

/**
 * Options : ENABLED
 * 			DISABLED
 * */
#define USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE		DISABLED

/**
 * Options : SYNCHRONOUS
 * 			ASYNCHRONOUS
 * */
#define USART_u8_MODE_SELECT							ASYNCHRONOUS

/**
 * Options : TRANSMIT_ON_FALLING_RECEIVE_ON_RISING
 * 			TRANSMIT_ON_RISING_RECEIVE_ON_FALLING
 * */
#define USART_u8_CLOCK_POLARITY							TRANSMIT_ON_RISING_RECEIVE_ON_FALLING


#define FCPU											8000000UL  // unsigned long


#define USART_BAUD_RATE									9600UL	   // Unsinged long



#endif /* USART_CONFIG_H_ */

