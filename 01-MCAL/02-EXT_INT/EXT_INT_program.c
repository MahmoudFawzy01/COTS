/*
 * EXT_INT_Program.c
 *
 *  Created on: Oct 26, 2019
 *      Author: Mahmoud Fawzy
 */


 #include "STD_Types.h"
 #include "BIT_MATH.h"
 #include "EXT_INT_interface.h"

/*Description:External Interrupt Initialization
 * Input     : NA
 * Output    : NA
 * */
void EXT_INT_voidInit(void)
{
	if (SREG_GIE_STATUS)
		EXT_INT_voidEnableGlobal();
	else
		EXT_INT_voidDisableGlobal();
	///////////////////////////////////////////////
	if (INT0_STATUS)
		EXT_INT_EnuEnable(EXT_INT_GICR_INT0);
	else
		EXT_INT_EnuDisable(EXT_INT_GICR_INT0);
	///////////////////////////////////////////////
	if (INT1_STATUS)
		EXT_INT_EnuEnable(EXT_INT_GICR_INT1);
	else
		EXT_INT_EnuDisable(EXT_INT_GICR_INT1);
	///////////////////////////////////////////////
	if (INT2_STATUS)
		EXT_INT_EnuEnable(EXT_INT_GICR_INT2);
	else
		EXT_INT_EnuDisable(EXT_INT_GICR_INT2);
	///////////////////////////////////////////////
	EXT_INT_EnuSetLevel(EXT_INT_GICR_INT0,INT0_SENSE);
	EXT_INT_EnuSetLevel(EXT_INT_GICR_INT1,INT1_SENSE);
	EXT_INT_EnuSetLevel(EXT_INT_GICR_INT2,INT2_SENSE);
}

/*Description:Enable Global Interrupt
 * Input     : NA
 * Output    : NA
 * */
void EXT_INT_voidEnableGlobal(void)
{
	//SET_BIT(SREG,SREG_GIE); // set
	asm("SEI");
}


/*Description:Disable Global Interrupt
 * Input     : NA
 * Output    : NA
 * */
void EXT_INT_voidDisableGlobal(void)
{
	//CLR_BIT(SREG,SREG_GIE); // clear
	asm("CLI");
}


/*Description:Enable a Specific Interrupt(INT0 or INT1 or INT2)
 * Input     : Copy_u8InterruptPinNo(Interrupt Type to Enable)(INT0 or INT1 or INT2)
 * Output    : ERROR status
 * */
ErrorStatus EXT_INT_EnuEnable(u8 Copy_u8InterruptPinNo)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	switch(Copy_u8InterruptPinNo)
	{
	case EXT_INT_GICR_INT0:
		SET_BIT(GICR,EXT_INT_GICR_INT0); // set
		Local_EnuError = OK;
		break;
	case EXT_INT_GICR_INT1:
		SET_BIT(GICR,EXT_INT_GICR_INT1); // set
		Local_EnuError = OK;
		break;
	case EXT_INT_GICR_INT2:
		SET_BIT(GICR,EXT_INT_GICR_INT2); // set
		Local_EnuError = OK;
		break;
	default:
		Local_EnuError = OUTOFRANGE;
		break;
	}

	return Local_EnuError;
}

/*Description:Disable a Specific Interrupt(INT0 or INT1 or INT2)
 * Input     : Copy_u8InterruptPinNo(Interrupt Type to Disable)(INT0 or INT1 or INT2)
 * Output    : ERROR status
 * */
ErrorStatus EXT_INT_EnuDisable(u8 Copy_u8InterruptPinNo)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	switch(Copy_u8InterruptPinNo)
	{
	case EXT_INT_GICR_INT0:
		CLR_BIT(GICR,EXT_INT_GICR_INT0); // set
		Local_EnuError = OK;
		break;
	case EXT_INT_GICR_INT1:
		CLR_BIT(GICR,EXT_INT_GICR_INT1); // set
		Local_EnuError = OK;
		break;
	case EXT_INT_GICR_INT2:
		CLR_BIT(GICR,EXT_INT_GICR_INT2); // set
		Local_EnuError = OK;
		break;
	default:
		Local_EnuError = OUTOFRANGE;
		break;
	}

	return Local_EnuError;
}

/*Description:Set Interrupt Level(Rising Edge or Falling Edge or On Change or Low Level)
 * Input     : Copy_u8InterruptPinNo(Interrupt Type to Enable)(INT0 or INT1 or INT2), Copy_u8InterruptLevel(Rising Edge or Falling Edge or On Change or Low Level)
 * Output    : ERROR status
 * */
ErrorStatus EXT_INT_EnuSetLevel(u8 Copy_u8InterruptPinNo,u8 Copy_u8InterruptLevel)
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].

	switch(Copy_u8InterruptPinNo)
	{
		case EXT_INT_GICR_INT0:
		{
			CLR_BIT(MCUCR,EXT_INT_MCUCR_ISC00);
			CLR_BIT(MCUCR,EXT_INT_MCUCR_ISC01);

			switch(Copy_u8InterruptLevel)
			{
			case EXT_INT0_MCUCR_SENSE_LOWLEVEL:
				EDIT_REG(MCUCR,EXT_INT0_MCUCR_SENSE_LOWLEVEL);
				Local_EnuError = OK;
				break;
			case EXT_INT0_MCUCR_SENSE_LOGICALCHANGE:
				EDIT_REG(MCUCR,EXT_INT0_MCUCR_SENSE_LOGICALCHANGE);
				Local_EnuError = OK;
				break;
			case EXT_INT0_MCUCR_SENSE_FALLING_EDGE:
				EDIT_REG(MCUCR,EXT_INT0_MCUCR_SENSE_FALLING_EDGE);
				Local_EnuError = OK;
				break;
			case EXT_INT0_MCUCR_SENSE_RISING_EDGE:
				EDIT_REG(MCUCR,EXT_INT0_MCUCR_SENSE_RISING_EDGE);
				Local_EnuError = OK;
				break;
			default:
				Local_EnuError = OUTOFRANGE;
				break;
			}
		}
		break;
	case EXT_INT_GICR_INT1:
		{
			CLR_BIT(MCUCR,EXT_INT_MCUCR_ISC10);
			CLR_BIT(MCUCR,EXT_INT_MCUCR_ISC11);

			switch(Copy_u8InterruptLevel)
			{
			case EXT_INT1_MCUCR_SENSE_LOWLEVEL:
				EDIT_REG(MCUCR,EXT_INT1_MCUCR_SENSE_LOWLEVEL);
				Local_EnuError = OK;
				break;
			case EXT_INT1_MCUCR_SENSE_LOGICALCHANGE:
				EDIT_REG(MCUCR,EXT_INT1_MCUCR_SENSE_LOGICALCHANGE);
				Local_EnuError = OK;
				break;
			case EXT_INT1_MCUCR_SENSE_FALLING_EDGE:
				EDIT_REG(MCUCR,EXT_INT1_MCUCR_SENSE_FALLING_EDGE);
				Local_EnuError = OK;
				break;
			case EXT_INT1_MCUCR_SENSE_RISING_EDGE:
				EDIT_REG(MCUCR,EXT_INT1_MCUCR_SENSE_RISING_EDGE);
				Local_EnuError = OK;
				break;
			default:
				Local_EnuError = OUTOFRANGE;
				break;
			}
		}
		break;
	case EXT_INT_GICR_INT2:
		{
			CLR_BIT(MCUCSR,EXT_INT_MCUCSR_ISC2);

			switch(Copy_u8InterruptLevel)
			{
			case EXT_INT2_MCUCR_SENSE_FALLING_EDGE:
				EDIT_REG(MCUCSR,EXT_INT2_MCUCR_SENSE_FALLING_EDGE);
				Local_EnuError = OK;
				break;
			case EXT_INT2_MCUCR_SENSE_RISING_EDGE:
				EDIT_REG(MCUCSR,EXT_INT2_MCUCR_SENSE_RISING_EDGE);
				Local_EnuError = OK;
				break;
			default:
				Local_EnuError = OUTOFRANGE;
				break;
			}
		}
		break;
	default:
		Local_EnuError = OUTOFRANGE;
		break;
	}

	return Local_EnuError;
}

/*Description:Send Address of Function To Call Back Pointer to maintain
 * the architecture of System(No one from Lower Level can Call one from Higher Level
 * and no calling between two in the Same Layer) and to hide Vector Function from main
 * Input     : Copy_u8InterruptPinNo(Interrupt Type to Enable)(INT0 or INT1 or INT2),
 *             *Copy_FunctionAddress Pointer to function with INPUT void and OUTPUT void
 *             to send Function Address to Call Back Function
 * Output    : NA
 * */
ErrorStatus EXT_INT_EnuSetCallBack(u8 Copy_u8InterruptPinNo,void (*Copy_voidCallBackFuncAddress)(void))
{
	ErrorStatus Local_EnuError = NOK; //ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE/NULLPOINTER].
	
	if (Copy_voidCallBackFuncAddress == NULL_POINTER)
	{
		Local_EnuError = NULLPOINTER;
	}
	else
	{
		switch(Copy_u8InterruptPinNo)
		{
		case EXT_INT_GICR_INT0:
			EXT_INT_voidCallBackInt0 = Copy_voidCallBackFuncAddress;
			Local_EnuError = OK;
			break;
		case EXT_INT_GICR_INT1:
			EXT_INT_voidCallBackInt1 = Copy_voidCallBackFuncAddress;
			Local_EnuError = OK;
			break;
		case EXT_INT_GICR_INT2:
			EXT_INT_voidCallBackInt2 = Copy_voidCallBackFuncAddress;
			Local_EnuError = OK;
			break;
		default:
			Local_EnuError = OUTOFRANGE;
			break;
		}
	}

	return Local_EnuError;
}
void __vector_1()
{
	asm("SEI");
	if (EXT_INT_voidCallBackInt0 != 0)
	EXT_INT_voidCallBackInt0();
}

void __vector_2()
{
	asm("SEI");
	if (EXT_INT_voidCallBackInt1 != 0)
	EXT_INT_voidCallBackInt1();
}

void __vector_3()
{
	asm("SEI");
	if (EXT_INT_voidCallBackInt2 != 0)
	EXT_INT_voidCallBackInt2();
}
