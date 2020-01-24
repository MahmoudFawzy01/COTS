/*
 * USART_program.c
 *
 *  Created on: Jan 14, 2020
 *      Author: sasafizo
 */
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "USART_register.h"
#include "USART_private.h"
#include "USART_config.h"


ErrorStatus USART_EnuInit(void)
{
	ErrorStatus Local_EnuError = OK;
	u8 Local_u8UCSRC_temp = 0x80;
	u16 Local_u16BaudRateValue = 0;

#if USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE == ENABLED
	SET_BIT(UCSRA,USART_UCSRA_U2X_PIN);
#elif USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE == DISABLED
	CLR_BIT(UCSRA,USART_UCSRA_U2X_PIN);
#else
	Local_EnuError = NOK;
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if USART_DATA_REG_EMPTY_INT_ENABLE	 == ENABLED
	SET_BIT(UCSRB,USART_UCSRB_UDRIE_PIN);
#elif USART_DATA_REG_EMPTY_INT_ENABLE	 == DISABLED
	CLR_BIT(UCSRB,USART_UCSRB_UDRIE_PIN);
#else
	Local_EnuError = NOK;
#endif

#if USART_TX_COMPLETE_INT_ENABLE	 == ENABLED
	SET_BIT(UCSRB,USART_UCSRB_TXCIE_PIN);
#elif USART_TX_COMPLETE_INT_ENABLE	 == DISABLED
	CLR_BIT(UCSRB,USART_UCSRB_TXCIE_PIN);
#else
	Local_EnuError = NOK;
#endif


#if USART_RX_COMPLETE_INT_ENABLE	 == ENABLED
	SET_BIT(UCSRB,USART_UCSRB_RXCIE_PIN);
#elif USART_RX_COMPLETE_INT_ENABLE	 == DISABLED
	CLR_BIT(UCSRB,USART_UCSRB_RXCIE_PIN);
#else
	Local_EnuError = NOK;
#endif

#if USART_TX_ENABLE	 == ENABLED
	SET_BIT(UCSRB,USART_UCSRB_TXEN_PIN);
#elif USART_TX_ENABLE	 == DISABLED
	CLR_BIT(UCSRB,USART_UCSRB_TXEN_PIN);
#else
	Local_EnuError = NOK;
#endif

#if USART_RX_ENABLE	 == ENABLED
	SET_BIT(UCSRB,USART_UCSRB_RXEN_PIN);
#elif USART_RX_ENABLE	 == DISABLED
	CLR_BIT(UCSRB,USART_UCSRB_RXEN_PIN);
#else
	Local_EnuError = NOK;
#endif

/////////////////////////////////////////////////////////////////////////////////////////
#if USART_u8_MODE_SELECT	 ==  SYNCHRONOUS
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UMSEL);
#elif USART_u8_MODE_SELECT	 ==  ASYNCHRONOUS
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UMSEL);
#else
	Local_EnuError = NOK;
#endif


#if USART_PARITY_MODE	 ==  USART_NO_PARITY
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UPM0);
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UPM1);
#elif USART_PARITY_MODE	 ==  USART_EVEN_PARITY
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UPM0);
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UPM1);
#elif USART_PARITY_MODE	 ==  USART_ODD_PARITY
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UPM0);
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UPM1);
#else
	Local_EnuError = NOK;
#endif

#if USART_STOP_BITS	 ==   TWO_STOP_BIT
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_USBS);
#elif USART_STOP_BITS  ==  ONE_STOP_BIT
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_USBS);
#else
	Local_EnuError = NOK;
#endif



#if USART_u8_CHAR_SIZE	 ==  USART_CHAR_SIZE_5BIT
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCSZ1);
#elif USART_u8_CHAR_SIZE	 ==  USART_CHAR_SIZE_6BIT
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCSZ0);
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCSZ1);
#elif USART_u8_CHAR_SIZE	 ==  USART_CHAR_SIZE_7BIT
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCSZ1);
#elif USART_u8_CHAR_SIZE	 ==  USART_CHAR_SIZE_8BIT
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCSZ0);
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCSZ1);
#else
	Local_EnuError = NOK;
#endif


#if USART_u8_CLOCK_POLARITY	 ==   TRANSMIT_ON_RISING_RECEIVE_ON_FALLING
	CLR_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCPOL);
#elif USART_u8_CLOCK_POLARITY  ==  TRANSMIT_ON_FALLING_RECEIVE_ON_RISING
	SET_BIT(Local_u8UCSRC_temp,USART_UCSRC_UCPOL);
#else
	Local_EnuError = NOK;
#endif


#if (USART_u8_MODE_SELECT == ASYNCHRONOUS) && (USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE == DISABLED)
	Local_u16BaudRateValue = ((FCPU/(16*USART_BAUD_RATE))-1);
#elif (USART_u8_MODE_SELECT == ASYNCHRONOUS) && (USART_u8_DOUBLE_ASYNCHRONOUS_SPEED_ENABLE == ENABLED)
	Local_u16BaudRateValue = ((FCPU/(8*USART_BAUD_RATE))-1);
#elif (USART_u8_MODE_SELECT == SYNCHRONOUS)
	Local_u16BaudRateValue = ((FCPU/(2*USART_BAUD_RATE))-1);
#else
	Local_EnuError = NOK;
#endif
	/*	Assing the baudrate to UBRR registers	*/
	UBRRL = (u8) Local_u16BaudRateValue;
	UBRRH = (u8) (Local_u16BaudRateValue >> 8);

/*	 Send Value to UCSRC from Local_u8UCSRC_temp 	*/

	ASSIGN_REG(UCSRC,Local_u8UCSRC_temp);


	return Local_EnuError;
}




void USART_EnuSend(u8 Copy_u8Data)
{
	while (GET_BIT(UCSRA,USART_UCSRA_UDRE_PIN) != USART_BIT_HIGH)
	{

	}
	UDR = Copy_u8Data;
}

u8 USART_EnuReceive(void)
{
	while (GET_BIT(UCSRA,USART_UCSRA_RXC_PIN) != USART_BIT_HIGH)
	{

	}
	return UDR;
}

ErrorStatus USART_voidSendString(const char * Copy_u8String)
{
	ErrorStatus Local_EnuError = OK;
	u8 Local_u8Index = 0;

	if (Copy_u8String != NULL_POINTER)
	{
		while (Copy_u8String[Local_u8Index] != '\0')
		{
			USART_EnuSend(Copy_u8String[Local_u8Index]);
			Local_u8Index++;
		}
	}
	else
	{
		Local_EnuError = NULLPOINTER;
	}

	return Local_EnuError;
}

ErrorStatus USART_voidReceiveString(u8 * Copy_u8String,u8 Copy_u8MessageSize)
{
	ErrorStatus Local_EnuError = OK;
	u8 Local_u8Index = 0;
	if (Copy_u8String != NULL_POINTER)
	{
		while (Local_u8Index < Copy_u8MessageSize)
		{
			Copy_u8String[Local_u8Index] = USART_EnuReceive();
			Local_u8Index++;
		}
	}
	else
	{
		Local_EnuError = NULLPOINTER;
	}

	return Local_EnuError;
}


/*
 * ASY functions are not tested
 *
 * */

ErrorStatus USART_EnuSendStringASY(const char * Copy_u8Data, void (*Copy_voidNotificationAction)(void))
{
	ErrorStatus Local_EnuError = OK;

	/* CHaeck if the pointers are null or not */
	if ((Copy_u8Data != NULL_POINTER) && (Copy_voidNotificationAction != NULL_POINTER))
	{
		asm("SEI");

		/* Assign the passed ptr to the global ptr */
		u8Data = Copy_u8Data;

		/* Assign the passed Fptr to the global Fptr */
		USART_voidPointerToFunction = Copy_voidNotificationAction;

		/*	Set the index of the passed array to 0	*/
		u8DataIndex = 0;

		// Open the int of UDR empty .
		SET_BIT(UCSRA,USART_UCSRA_UDRE_PIN);
	}
	else
	{
		/*	One of the passed ptr is null	*/
		Local_EnuError = NULLPOINTER;
	}
	return Local_EnuError;
}

ISR(14)
{
	/*	check if the data existed is  not null	*/
	if (u8Data[u8DataIndex] != '\0')
	{
		UDR = u8Data[u8DataIndex];
		u8DataIndex++;
	}
	else
	{
		USART_voidPointerToFunction();
		// Close the int of UDR empty .
		CLR_BIT(UCSRA,USART_UCSRA_UDRE_PIN);
	}
}


ErrorStatus USART_EnuReceiveStringASY(char * Copy_u8ReceivedData,u8 Copy_u8ReceivedDataSize ,void (*Copy_voidNotificationAction)(void))
{
	ErrorStatus Local_EnuError = OK;
	// Close the int of UDR empty .
	CLR_BIT(UCSRA,USART_UCSRA_UDRE_PIN);
	/* CHaeck if the pointers are null or not */
	if ((Copy_u8ReceivedData != NULL_POINTER) && (Copy_voidNotificationAction != NULL_POINTER))
	{

		asm("SEI");


		/* Assign the passed ptr to the global ptr */
		u8ReceivedData = Copy_u8ReceivedData;

		/* Assign the passed Fptr to the global Fptr */
		USART_voidReceivePointerToFunction = Copy_voidNotificationAction;

		/*	Set the index of the passed array to 0	*/
		u8ReceivedDataIndex = 0;

		/*	 Set the expected size of the message	*/
		u8ReceivedDataSize = Copy_u8ReceivedDataSize;

		// Open the int of RxE
		SET_BIT(UCSRA,USART_UCSRA_RXC_PIN);
	}
	else
	{
		/*	One of the passed ptr is null	*/
		Local_EnuError = NULLPOINTER;
	}

	return Local_EnuError;
}

ISR(13)
{

	if (u8ReceivedDataIndex != u8ReceivedDataSize)
	{
		u8ReceivedData[u8ReceivedDataIndex] = UDR;
		u8ReceivedDataIndex++;
	}
	else
	{

		USART_voidReceivePointerToFunction();
		// Open the int of UDR empty .
		CLR_BIT(UCSRA,USART_UCSRA_RXC_PIN);
	}
}
