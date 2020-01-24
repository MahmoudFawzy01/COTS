/*
 * KEYPAD_config.h
 *
 *  Created on: Jan 16, 2020
 *      Author: Mahmoud Fawzy
 */

/*

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#endif KEYPAD_INTERFACE_H_

*/


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_ROWS_NUMBER			4
#define KEYPAD_COLUMNS_NUMBER		4

/*	Rows Pins	*/
#define KEYPAD_R1_PIN		DIO_PIN_8
#define KEYPAD_R2_PIN		DIO_PIN_9
#define KEYPAD_R3_PIN		DIO_PIN_10
#define KEYPAD_R4_PIN		DIO_PIN_11
/*	Columns Pins	*/
#define KEYPAD_C1_PIN		DIO_PIN_12
#define KEYPAD_C2_PIN		DIO_PIN_13
#define KEYPAD_C3_PIN		DIO_PIN_14
#define KEYPAD_C4_PIN		DIO_PIN_15

/*	Adjust the pins 	*/
#define KEYPAD_ROWS_PINS	{KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN,KEYPAD_R4_PIN}
#define KEYPAD_COLS_PINS	{KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN,KEYPAD_C4_PIN}

#define KEYPAD_KEYS_ARR     { {'1','2','3','+'},{'4','5','6','-'},{'7','8','9','*'},{'0','=','/','%'}}

#define KEYPAD_NOT_PRESSED	0xff

#define KEYPAD_ROWS_PIN_DRIECTION	KEYPAD_PINS_INPUT
#define KEYPAD_COLS_PIN_DRIECTION	KEYPAD_PINS_OUTPUT

#endif /* KEYPAD_CONFIG_H_ */
