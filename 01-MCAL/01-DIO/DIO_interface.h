/*
 * DIO_interface.h
 *
 *  Created on: Dec 31, 2019
 *      Author: Mahmoud Fawzy
 */
 
 #ifndef	DIO_INTERFACE_H_
 #define	DIO_INTERFACE_H_



/*Macro for Port Numbers*/
#define DIO_PORTA	 0
#define DIO_PORTB 	 1
#define DIO_PORTC 	 2
#define DIO_PORTD  	 3

/*Macro for PIN Numbers*/
#define DIO_PIN_0	 0
#define DIO_PIN_1	 1
#define DIO_PIN_2	 2
#define DIO_PIN_3	 3
#define DIO_PIN_4	 4
#define DIO_PIN_5	 5
#define DIO_PIN_6	 6
#define DIO_PIN_7	 7

/*Macro for Pin Directions*/
#define DIO_PIN_INPUT	0
#define DIO_PIN_OUTPUT 	1

/*Macro for Pin Value*/
#define DIO_PIN_LOW 	0
#define DIO_PIN_HIGH 	1

/*Macro for Port Directions*/
#define DIO_PORT_INPUT 	0
#define DIO_PORT_OUTPUT 0xFF

/*Macro for Port Value*/
#define DIO_PORT_LOW	0
#define DIO_PORT_HIGH 	0xFF

/*Macro for Input Types*/
#define DIO_INPUT_FLOATING 	0
#define DIO_INPUT_PULLUP 	1

/*
 * Description : Set the desired pin direction.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(0~4)] - [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~7)]   -  [Copy_u8Direction -> pin direction value = DIO_PIN_INPUT/DIO_PIN_OUTPUT].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber ,u8 Copy_u8PinDirection);

/*
 * Description : Set the desired pin value.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(0~4)] - [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~7)]   -  [Copy_u8Direction -> pin value = DIO_PIN_LOW/DIO_PIN_HIGH].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber ,u8 Copy_u8PinValue);


/*
 * Description : Get the desired pin value.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_rPORT_(0~4)] - [Copy_u8PinNumber-> pin number value = DIO_PIN_(0~7)] - [* Copy_u8Value used to receive the pin value 0/1] 
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuGetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber ,u8 * Copy_Pu8PinValue);

/*
* Description : Set the whole port direction.
* Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(0~4)]  -  [Copy_u8Direction -> port direction value = DIO_PIN_INPUT/DIO_PIN_OUTPUT].
* Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
* */
ErrorStatus DIO_EnuSetPortDirection(u8 Copy_u8PortNumber, u8 Copy_u8PortDirection);

/*
 * Description : Set the whole port Value.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(0~4)]  -  [Copy_u8Value -> port value = DIO_PORT_LOW/DIO_PORT_HIGH].
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuSetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue);

/*
 * Description : Get the desired port value.
 * Inputs  : [Copy_u8PortNumber-> port number value = DIO_PORT_(0~4)] - [* Copy_u8Value used to receive the port value] 
 * Outputs : ErrorStatus [ErrorStatus Enum] -> [OK/NOK/OUTOFRANGE].
 * */
ErrorStatus DIO_EnuGetPortValue(u8 Copy_u8PortNumber ,u8 * Copy_u8PortValue);


 
 #endif