/*
 * SEVENSEG_program.c
 *
 *  Created on: Jan 13, 2019
 *      Author: Mahmoud Fawzy
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "SEVENSEG_Interface.h"
#include "PORT_interface.h"
#include "SEVENSEG_private.h"
#include "SEVENSEG_config.h"


/*
 * Description : Enable the Seven Segment
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SEVENSEG_EnuEnable (u8 Copy_u8SevenSegNumber)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	if ((Copy_u8SevenSegNumber >= SEVENSEG_MIN_COUNT)&&(Copy_u8SevenSegNumber < SEVENSEG_COUNT))
	{
		if (SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].Mode == SEVENSEG_COMMON_ANODE_MODE)
		{
			DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].CommonPin,DIO_PIN_HIGH);
			Local_EnuError = OK;
			SevenSeg_EnuDisplayNumber(Copy_u8SevenSegNumber,SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].DisplayedValue);
		}
		else if (SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].Mode == SEVENSEG_COMMON_CATHODE_MODE)
		{
			DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].CommonPin,DIO_PIN_LOW);
			Local_EnuError = OK;
			SevenSeg_EnuDisplayNumber(Copy_u8SevenSegNumber,SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].DisplayedValue);
		}
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}
	return Local_EnuError;
}

/*
 * Description : Enable the Seven Segment
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SEVENSEG_EnuDisable (u8 Copy_u8SevenSegNumber)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	if ((Copy_u8SevenSegNumber >= SEVENSEG_MIN_COUNT)&&(Copy_u8SevenSegNumber < SEVENSEG_COUNT))
	{
		if (SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].Mode == SEVENSEG_COMMON_ANODE_MODE)
		{
			DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].CommonPin,DIO_PIN_LOW);
			Local_EnuError = OK;
		}
		else if (SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].Mode == SEVENSEG_COMMON_CATHODE_MODE)
		{
			DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].CommonPin,DIO_PIN_HIGH);
			Local_EnuError = OK;
		}
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}
	return Local_EnuError;
}

/*
 * Description : Enable the seven seg dot
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT || Copy_u8DotStatus :  SEVEN_SEG_DOT_ON/SEVEN_SEG_DOT_OFF
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SevenSeg_EnuEnableDot (u8 Copy_u8SevenSegNumber)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	if ((Copy_u8SevenSegNumber >= SEVENSEG_MIN_COUNT)&&(Copy_u8SevenSegNumber < SEVENSEG_COUNT))
	{
			SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].DotStatus = DIO_PIN_HIGH;
			Local_EnuError = OK;
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}
	return Local_EnuError;
}

/*
 * Description : Disable the seven seg dot
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT || Copy_u8DotStatus :  SEVEN_SEG_DOT_ON/SEVEN_SEG_DOT_OFF
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SevenSeg_EnuDisableDot (u8 Copy_u8SevenSegNumber)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	if ((Copy_u8SevenSegNumber >= SEVENSEG_MIN_COUNT)&&(Copy_u8SevenSegNumber < SEVENSEG_COUNT))
	{
			SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].DotStatus = DIO_PIN_LOW;
			Local_EnuError = OK;
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}
	return Local_EnuError;
}


/*
 * Description : Change the the seven seg display value
 * Inputs  : Copy_u8SevenSegNumber->  the number of the SevenSeg to SEVENSEG_COUNT || Copy_u8Number :  the number between 0~9
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus SevenSeg_EnuDisplayNumber (u8 Copy_u8SevenSegNumber, u8 Copy_u8Number)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	// Global Array with the port representation of the numbers 0~9
	//gfedcba								0	 	 1	  	 	2	  		3			4 		  5 	 	6	  	   7	   		8		 9			 off
	static u8 SevenSeg_u8Numbers[] = {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111,0b00000000};
	//gfedcba							0	  1	   2	  3		4 	5 	 6	  7	   8	9	 off  A	   B	C	 D	  E    F
	//static u8 SevenSeg_u8Numbers[] = {0x3F,0x06,0x5B, 0x4F ,0x4E,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x77,0x7C,0x39,0x5E,0x79,0x71};

	if ((Copy_u8SevenSegNumber >= SEVENSEG_MIN_COUNT)&&(Copy_u8SevenSegNumber < SEVENSEG_COUNT))
	{
		if ((Copy_u8Number >= SEVENSEG_DISPLAY_ZERO) && (Copy_u8Number<=SEVENSEG_NUMBERS_COUNT))
		{
			if (SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].Mode == SEVENSEG_COMMON_ANODE_MODE)
			{
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINA_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinA,DIO_PIN_HIGH);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinA,DIO_PIN_LOW);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINB_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinB,DIO_PIN_HIGH);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinB,DIO_PIN_LOW);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINC_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinC,DIO_PIN_HIGH);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinC,DIO_PIN_LOW);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PIND_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinD,DIO_PIN_HIGH);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinD,DIO_PIN_LOW);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINE_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinE,DIO_PIN_HIGH);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinE,DIO_PIN_LOW);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINF_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinF,DIO_PIN_HIGH);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinF,DIO_PIN_LOW);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PING_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinG,DIO_PIN_HIGH);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinG,DIO_PIN_LOW);
				}
				////////////////
				if (SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].DotStatus == DIO_PIN_LOW)
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinH,DIO_PIN_HIGH);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinH,DIO_PIN_LOW);
				}

				Local_EnuError = OK;
				SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].DisplayedValue = Copy_u8Number;
			}
			else if (SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].Mode == SEVENSEG_COMMON_CATHODE_MODE)
			{
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINA_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinA,DIO_PIN_LOW);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinA,DIO_PIN_HIGH);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINB_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinB,DIO_PIN_LOW);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinB,DIO_PIN_HIGH);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINC_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinC,DIO_PIN_LOW);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinC,DIO_PIN_HIGH);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PIND_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinD,DIO_PIN_LOW);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinD,DIO_PIN_HIGH);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINE_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinE,DIO_PIN_LOW);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinE,DIO_PIN_HIGH);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PINF_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinF,DIO_PIN_LOW);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinF,DIO_PIN_HIGH);
				}
				////////////////
				if (GET_BIT(~SevenSeg_u8Numbers[Copy_u8Number],SEVENSEG_PING_INDEX))
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinG,DIO_PIN_LOW);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinG,DIO_PIN_HIGH);
				}
				////////////////
				if (SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].DotStatus == DIO_PIN_LOW)
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinH,DIO_PIN_LOW);
				}
				else
				{
					DIO_EnuSetPinValue(SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].PinH,DIO_PIN_HIGH);
				}

				Local_EnuError = OK;
				SEVENSEG_AStrSevenSeg[Copy_u8SevenSegNumber].DisplayedValue = Copy_u8Number;
			}
		}
		else
		{
			Local_EnuError = OUTOFRANGE;
		}
	}
	else
	{
		Local_EnuError = OUTOFRANGE;
	}
	return Local_EnuError;
}
