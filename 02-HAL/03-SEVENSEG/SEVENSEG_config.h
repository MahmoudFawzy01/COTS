/*
 * SEVENSEG_config.h
 *
 *  Created on: Jan 13, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef SEVENSEG_CONFIG_H_
#define SEVENSEG_CONFIG_H_

/* Seven Segment Count */
#define SEVENSEG_COUNT 2

// the 7 seg value should be from 0 ~ 9 
#define SEVENSEG_DEFAULT_VALUE	10
#define SEVENSEG_DOT_DEFAULT_VALUE	DIO_PIN_LOW
/*
// Here the configuration of the seven segments connected
// PinA ~H and CommonPin of the seven segments configured by the DIO pins 0~31
// Mode configured by SEVENSEG_COMMON_ANODE_MODE / SEVENSEG_COMMON_CATHODE_MODE
// DisplayedValue configured or used at run time or you can configure it to a default value.
// Note you need to used the configuration block for each 7 seg added.
// Each block added you should adjust the SEVENSEG_COUNT to the number of blocks
block example :
{
	PinA,
	PinB,
	PinC,
	PinD,
	PinE,
	PinF,
	PinG,
	PinH,
	CommonPin,
	Mode,
	DisplayedValue,
	DotStatus
}
*/
SevenSeg SEVENSEG_AStrSevenSeg[SEVENSEG_COUNT]= {
	{
		DIO_PIN_0,
		DIO_PIN_1,
		DIO_PIN_2,
		DIO_PIN_3,
		DIO_PIN_4,
		DIO_PIN_5,
		DIO_PIN_6,
		DIO_PIN_31,
		DIO_PIN_8,
		SEVENSEG_COMMON_ANODE_MODE,
		SEVENSEG_DEFAULT_VALUE,
		SEVENSEG_DOT_DEFAULT_VALUE
	},
	{
		DIO_PIN_0,
		DIO_PIN_1,
		DIO_PIN_2,
		DIO_PIN_3,
		DIO_PIN_4,
		DIO_PIN_5,
		DIO_PIN_6,
		DIO_PIN_31,
		DIO_PIN_9,
		SEVENSEG_COMMON_ANODE_MODE,
		SEVENSEG_DEFAULT_VALUE,
		SEVENSEG_DOT_DEFAULT_VALUE
	}
};



#endif /* SEVENSEG_CONFIG_H_ */
