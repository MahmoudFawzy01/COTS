/*
 * SevenSeg_Interface.h
 *
 *  Created on: Oct 20, 2019
 *      Author: Mahmoud Fawzy
 */

#ifndef SEVENSEG_INTERFACE_H_
#define SEVENSEG_INTERFACE_H_

// Selecting Diode type if cathode or anode
#define SEVENSEG_COMMON_ANODE_MODE		0
#define SEVENSEG_COMMON_CATHODE_MODE	1

// Enable/Disable the seven seg dot
#define SEVENSEG_DOT_ON			1
#define SEVENSEG_DOT_OFF		0

// available seven segments to use
#define SEVENSEG_ONE 0
#define SEVENSEG_TWO 1

// available numbers to be displayed
#define SEVENSEG_DISPLAY_ZERO		0
#define SEVENSEG_DISPLAY_ONE		1
#define SEVENSEG_DISPLAY_TWO		2
#define SEVENSEG_DISPLAY_THREE		3
#define SEVENSEG_DISPLAY_FOUR		4
#define SEVENSEG_DISPLAY_FIVE		5
#define SEVENSEG_DISPLAY_SIX		6
#define SEVENSEG_DISPLAY_SEVEN		7
#define SEVENSEG_DISPLAY_EIGHT		8
#define SEVENSEG_DISPLAY_NINE		9
#define SEVENSEG_DISPLAY_OFF		10


/*
 * Description : Enable the Seven Segment
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SEVENSEG_EnuEnable (u8 Copy_u8SevenSegNumber);

/*
 * Description : Enable the Seven Segment
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SEVENSEG_EnuDisable  (u8 Copy_u8SevenSegNumber);

/*
 * Description : Enable the seven seg dot
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT || Copy_u8DotStatus :  SEVEN_SEG_DOT_ON/SEVEN_SEG_DOT_OFF
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SevenSeg_EnuEnableDot (u8 Copy_u8SevenSegNumber);

/*
 * Description : Disable the seven seg dot
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT || Copy_u8DotStatus :  SEVEN_SEG_DOT_ON/SEVEN_SEG_DOT_OFF
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SevenSeg_EnuDisableDot (u8 Copy_u8SevenSegNumber);

/*
 * Description : Change the the seven seg display value
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT || Copy_u8Number :  the number between 0~9
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SevenSeg_EnuDisplayNumber (u8 Copy_u8SevenSegNumber, u8 Copy_u8Number);

#endif /* SEVENSEG_INTERFACE_H_ */
