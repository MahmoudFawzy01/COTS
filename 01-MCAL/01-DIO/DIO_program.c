/*************************************
 * DIOProgram.c` 					 *
 *									 *
 *  Created on: Dec 31, 2019     	 *
 *      Author: Mahmoud Fawzy   	 *
 ************************************/
 
 
#include "STD_types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_registers.h"



/*
 * Description : Set the desired pin direction.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(A~D)] - [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~7)]   -  [Copy_u8PinDirection -> pin direction value = DIO_PIN_INPUT/DIO_PIN_OUTPUT].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber ,u8 Copy_u8PinDirection)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	// to ensure that the passed Pin Number value is between [0~7]
	if ((Copy_u8PinNumber >= DIO_PIN_0) && (Copy_u8PinNumber <=DIO_PIN_7))
	{
		// to ensure that the passed Direction value is between [0/1]
		if ((Copy_u8PinDirection >= DIO_PIN_INPUT) && (Copy_u8PinDirection <= DIO_PIN_OUTPUT))
		{
			//Assign value to the desired pin.
			switch (Copy_u8PortNumber)
			{
				case DIO_PORTA:
					ASSIGN_BIT(DDRA,Copy_u8PinNumber,Copy_u8PinDirection);
					Local_EnuError = OK;
				break;
				case DIO_PORTB:
					ASSIGN_BIT(DDRB,Copy_u8PinNumber,Copy_u8PinDirection);
					Local_EnuError = OK;
				break;
				case DIO_PORTC:
					ASSIGN_BIT(DDRC,Copy_u8PinNumber,Copy_u8PinDirection);
					Local_EnuError = OK;
				break;
				case DIO_PORTD:
					ASSIGN_BIT(DDRD,Copy_u8PinNumber,Copy_u8PinDirection);
					Local_EnuError = OK;
				break;
				default:
					Local_EnuError = OUTOFRANGE;
				break;
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

/*
 * Description : Set the desired pin value.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(A~D)] - [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~7)]   -  [Copy_u8PinValue -> pin value = DIO_PIN_LOW/DIO_PIN_HIGH].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber ,u8 Copy_u8PinValue)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	// to ensure that the passed Pin Number value is between [0~7]
	if ((Copy_u8PinNumber >= DIO_PIN_0) && (Copy_u8PinNumber <=DIO_PIN_7))
	{
		// to ensure that the passed Direction value is between [0/1]
		if ((Copy_u8PinValue >= DIO_PIN_LOW) && (Copy_u8PinValue <= DIO_PIN_HIGH))
		{
			//Assign value to the desired pin.
			switch (Copy_u8PortNumber)
			{
				case DIO_PORTA:
					ASSIGN_BIT(PORTA,Copy_u8PinNumber,Copy_u8PinValue);
					Local_EnuError = OK;
				break;
				case DIO_PORTB:
					ASSIGN_BIT(PORTB,Copy_u8PinNumber,Copy_u8PinValue);
					Local_EnuError = OK;
				break;
				case DIO_PORTC:
					ASSIGN_BIT(PORTC,Copy_u8PinNumber,Copy_u8PinValue);
					Local_EnuError = OK;
				break;
				case DIO_PORTD:
					ASSIGN_BIT(PORTD,Copy_u8PinNumber,Copy_u8PinValue);
					Local_EnuError = OK;
				break;
				default:
					Local_EnuError = OUTOFRANGE;
				break;
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


/*
 * Description : Get the desired pin value.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(A~D)] - [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~7)] - [* Copy_Pu8PinValue used to receive the pin value 0/1] 
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE/NULLPOINTER].
 * */
ErrorStatus DIO_EnuGetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber ,u8 * Copy_Pu8PinValue)
{
	ErrorStatus Local_EnuError = NOK;
	// to ensure that the passed Pin Number value is between [0~7]
	if ((Copy_u8PinNumber >= DIO_PIN_0) && (Copy_u8PinNumber <=DIO_PIN_7))
	{
		// Check if the pointer passed 
		if (Copy_Pu8PinValue != NULL_POINTER)
		{
			// Get the value of the pin
			switch (Copy_u8PortNumber)
			{
				case DIO_PORTA:
					*Copy_Pu8PinValue = GET_BIT(PINA,Copy_u8PinNumber);
					Local_EnuError = OK;
				break;
				case DIO_PORTB:
					*Copy_Pu8PinValue = GET_BIT(PINB,Copy_u8PinNumber);
					Local_EnuError = OK;
				break;
				case DIO_PORTC:
					*Copy_Pu8PinValue = GET_BIT(PINC,Copy_u8PinNumber);
					Local_EnuError = OK;
				break;
				case DIO_PORTD:
					*Copy_Pu8PinValue = GET_BIT(PIND,Copy_u8PinNumber);
					Local_EnuError = OK;
				break;
				default:
					Local_EnuError = OUTOFRANGE;
				break;
			}	
		}
		else
		{
			Local_EnuError = NULLPOINTER;
		}
	}
	else
	{
			Local_EnuError = NULLPOINTER;
	}
	

	return Local_EnuError;

}

/*
* Description : Set the whole port direction.
* Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(A~D)]  -  [Copy_u8Direction -> port direction value = DIO_PIN_INPUT/DIO_PIN_OUTPUT].
* Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
* */
ErrorStatus DIO_EnuSetPortDirection(u8 Copy_u8PortNumber, u8 Copy_u8PortDirection)
{
	ErrorStatus Local_EnuError = NOK;	// ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
	
	//Assign value to the port.
	switch (Copy_u8PortNumber)
	{
		case DIO_PORTA:
			ASSIGN_REG(DDRA,Copy_u8PortDirection);
			Local_EnuError = OK;
		break;
		case DIO_PORTB:
			ASSIGN_REG(DDRB,Copy_u8PortDirection);
			Local_EnuError = OK;
		break;
		case DIO_PORTC:
			ASSIGN_REG(DDRC,Copy_u8PortDirection);
			Local_EnuError = OK;
		break;
		case DIO_PORTD:
			ASSIGN_REG(DDRD,Copy_u8PortDirection);
			Local_EnuError = OK;
		break;
		default:
			Local_EnuError = OUTOFRANGE;
		break;
	}
	
	return Local_EnuError;
}

/*
 * Description : Set the whole port Value.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(A~D)]  -  [Copy_u8Value -> port value = DIO_PORT_LOW/DIO_PORT_HIGH].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue)
{
	ErrorStatus Local_EnuError = NOK;	//ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
	
	//Assign value to the port.
	switch (Copy_u8PortNumber)
	{
		case DIO_PORTA:
			ASSIGN_REG(PORTA,Copy_u8PortValue);
			Local_EnuError = OK;
		break;
		case DIO_PORTB:
			ASSIGN_REG(PORTB,Copy_u8PortValue);
			Local_EnuError = OK;
		break;
		case DIO_PORTC:
			ASSIGN_REG(PORTC,Copy_u8PortValue);
			Local_EnuError = OK;
		break;
		case DIO_PORTD:
			ASSIGN_REG(PORTD,Copy_u8PortValue);
			Local_EnuError = OK;
		break;
		default:
			Local_EnuError = OUTOFRANGE;
		break;
	}
	
	return Local_EnuError;
}

/*
 * Description : Get the desired port value.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(A~D)] - [* Copy_Pu8PortValue used to receive the port value] 
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE/NULLPOINTER].
 * */
ErrorStatus DIO_EnuGetPortValue(u8 Copy_u8PortNumber ,u8 * Copy_Pu8PortValue)
{
	ErrorStatus Local_EnuError = NOK;

	// check  if the pointer is NULL and invalid to use.
	if (Copy_Pu8PortValue != NULL_POINTER)
	{
		// Get port value
		switch (Copy_u8PortNumber)
		{
			case DIO_PORTA:
				*Copy_Pu8PortValue = PINA;
				Local_EnuError = OK;
			break;
			case DIO_PORTB:
				*Copy_Pu8PortValue = PINB;
				Local_EnuError = OK;
			break;
			case DIO_PORTC:
				*Copy_Pu8PortValue = PINC;
				Local_EnuError = OK;
			break;
			case DIO_PORTD:
				*Copy_Pu8PortValue = PIND;
				Local_EnuError = OK;
			break;
			default:
				Local_EnuError = OUTOFRANGE;
			break;
		}
	}
	else
	{
		Local_EnuError = NULLPOINTER;
	}

	return Local_EnuError;
}


