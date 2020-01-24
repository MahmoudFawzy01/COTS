/*
 * SEVENSEG_private.h
 *
 *  Created on: Jan 13, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef SEVENSEG_PRIVATE_H_
#define SEVENSEG_PRIVATE_H_

// available numbers to be displayed
#define SEVENSEG_NUMBERS_COUNT	11

#define SEVENSEG_MIN_COUNT	0

// this struct used to config the 7seg and it's property
typedef struct
{
	u8	PinA;
	u8	PinB;
	u8	PinC;
	u8	PinD;
	u8	PinE;
	u8	PinF;
	u8	PinG;
	u8	PinH;
	u8	CommonPin;
	u8	Mode;
	u8	DisplayedValue;
	u8	DotStatus;
} SevenSeg;

#define	SEVENSEG_PINA_INDEX		0
#define	SEVENSEG_PINB_INDEX		1
#define	SEVENSEG_PINC_INDEX		2
#define	SEVENSEG_PIND_INDEX		3
#define	SEVENSEG_PINE_INDEX		4
#define	SEVENSEG_PINF_INDEX		5
#define	SEVENSEG_PING_INDEX		6

#endif /* SEVENSEG_PRIVATE_H_ */
