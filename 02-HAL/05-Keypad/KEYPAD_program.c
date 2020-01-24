/*
 * KEYPAD_program.c
 *
 *  Created on: Jan 16, 2020
 *      Author: Mahmoud Fawzy
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"
#include <util/delay.h>


u8 KEYPAD_u8GetKey(void)
{
	/*	Add the pins of rows and cols pins at two arrays	*/
	u8 Local_u8RowsCounter,Local_u8ColsCounter,Local_u8KeyPressed;
	/*	set the default value of the return value of the function that it's  not pressed	*/
	u8 Local_u8ReturnValue = KEYPAD_NOT_PRESSED;
	static u8 Local_Au8RowsPins[KEYPAD_ROWS_NUMBER] = KEYPAD_ROWS_PINS;
	static u8 Local_Au8ColsPins[KEYPAD_COLUMNS_NUMBER] = KEYPAD_COLS_PINS;
	/* used to remove the ripples */
	u8 Local_u8RipplesCount = 0;

	/*	add the output/input pins to arrays and use them at the for loop	*/
#if (KEYPAD_ROWS_PIN_DRIECTION == KEYPAD_PINS_INPUT) && (KEYPAD_COLS_PIN_DRIECTION == KEYPAD_PINS_OUTPUT)

	/*	Add the pins of rows and cols pins at two arrays	*/
	static u8 Local_Au8KeypadKeys[KEYPAD_COLUMNS_NUMBER][KEYPAD_ROWS_NUMBER] = KEYPAD_KEYS_ARR;

	/*	Cols Output, Rows Inputs	*/
		/*	Put on each output pin 0	*/
		for (Local_u8ColsCounter = 0;Local_u8ColsCounter<KEYPAD_COLUMNS_NUMBER;Local_u8ColsCounter++)
		{
			/* Set the pin col low to check the rows */
			DIO_EnuSetPinValue(Local_Au8ColsPins[Local_u8ColsCounter],DIO_PIN_LOW);

			/*	check the input pins if it's low	*/
			for (Local_u8RowsCounter = 0;Local_u8RowsCounter<KEYPAD_ROWS_NUMBER;Local_u8RowsCounter++)
			{
				DIO_EnuGetPinValue(Local_Au8RowsPins[Local_u8RowsCounter],&Local_u8KeyPressed);
				if (Local_u8KeyPressed == DIO_PIN_LOW)
				{
					/* remove the ripples */
					while (1)
					{
						DIO_EnuGetPinValue(Local_Au8RowsPins[Local_u8RowsCounter],&Local_u8KeyPressed);

						if (Local_u8KeyPressed == DIO_PIN_LOW)
						{
							if (Local_u8RipplesCount <= KEYPAD_MAX_RIPPLES_COUNT)
							Local_u8RipplesCount++ ;

							/*Set the value of pressed key*/
							if (Local_u8RipplesCount == KEYPAD_MAX_RIPPLES_COUNT)
							{
								Local_u8ReturnValue = Local_Au8KeypadKeys[Local_u8ColsCounter][Local_u8RowsCounter];
								/* floating keys */
								DIO_EnuGetPinValue(Local_Au8RowsPins[Local_u8RowsCounter],&Local_u8KeyPressed);
								while (Local_u8KeyPressed == DIO_PIN_LOW)
								{
									DIO_EnuGetPinValue(Local_Au8RowsPins[Local_u8RowsCounter],&Local_u8KeyPressed);
								}
								break;
							}
						}
						else
						{
							if (Local_u8RipplesCount > KEYPAD_MIN_RIPPLES_COUNT)
							Local_u8RipplesCount--;
						}
					}
				}
			}
			/* Set the pin col high again after checking the rows */
			DIO_EnuSetPinValue(Local_Au8ColsPins[Local_u8ColsCounter],DIO_PIN_HIGH);
		}

#elif (KEYPAD_ROWS_PIN_DRIECTION == KEYPAD_PINS_OUTPUT) && (KEYPAD_COLS_PIN_DRIECTION == KEYPAD_PINS_INPUT)

	/*	 Add the pins of rows and cols pins at two arrays	*/
	static u8 Local_Au8KeypadKeys[KEYPAD_COLUMNS_NUMBER][KEYPAD_ROWS_NUMBER] = KEYPAD_KEYS_ARR;

	/*	Cols Output, Rows Inputs	*/
		/*	Put on each output pin 0	*/
		for (Local_u8RowsCounter = 0;Local_u8RowsCounter<KEYPAD_ROWS_NUMBER;Local_u8RowsCounter++)
		{
			/* Set the pin col low to check the rows */
			DIO_EnuSetPinValue(Local_Au8RowsPins[Local_u8RowsCounter],DIO_PIN_LOW);

			/*	check the input pins if it's low	*/
			for (Local_u8ColsCounter = 0;Local_u8ColsCounter<KEYPAD_COLUMNS_NUMBER;Local_u8ColsCounter++)
			{
				DIO_EnuGetPinValue(Local_Au8ColsPins[Local_u8ColsCounter],&Local_u8KeyPressed);

				if (Local_u8KeyPressed == DIO_PIN_LOW)
				{
					/* remove the ripples */
					while (1)
					{
						DIO_EnuGetPinValue(Local_Au8ColsPins[Local_u8ColsCounter],&Local_u8KeyPressed);
						if (Local_u8KeyPressed == DIO_PIN_LOW)
						{
							if (Local_u8RipplesCount < KEYPAD_MAX_RIPPLES_COUNT)
							Local_u8RipplesCount++ ;
							/*Set the value of pressed key*/
							if (Local_u8RipplesCount == KEYPAD_MAX_RIPPLES_COUNT)
							{
								Local_u8ReturnValue = Local_Au8KeypadKeys[Local_u8ColsCounter][Local_u8RowsCounter];
								/* floating keys */
								DIO_EnuGetPinValue(Local_Au8ColsPins[Local_u8ColsCounter],&Local_u8KeyPressed);
								while (Local_u8KeyPressed == DIO_PIN_LOW)
								{
									DIO_EnuGetPinValue(Local_Au8ColsPins[Local_u8ColsCounter],&Local_u8KeyPressed);
								}
								break;
							}
						}
						else
						{
							if (Local_u8RipplesCount > KEYPAD_MIN_RIPPLES_COUNT)
							Local_u8RipplesCount--;
						}
					}
				}
			}
			/* Set the pin col high again after checking the rows */
			DIO_EnuSetPinValue(Local_Au8RowsPins[Local_u8RowsCounter],DIO_PIN_HIGH);
		}

#else
#endif

	return Local_u8ReturnValue;
}

