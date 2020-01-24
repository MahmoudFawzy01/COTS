/*
 * USART_interface.h
 *
 *  Created on: Jan 14, 2020
 *      Author: sasafizo
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define USART_ParityMode_PIN0	4
#define USART_ParityMode1		5

ErrorStatus USART_EnuInit(void);

void USART_EnuSend(u8 Copy_u8Data);

u8 USART_EnuReceive(void);

ErrorStatus USART_voidReceiveString(u8 * Copy_u8String,u8 Copy_u8MessageSize);

ErrorStatus USART_voidSendString(const char * Copy_u8String);

ErrorStatus USART_EnuSendStringASY(const char * Copy_u8Data, void (*Copy_voidNotificationAction)(void));

ErrorStatus USART_EnuReceiveStringASY(char * Copy_u8ReceivedData,u8 Copy_u8ReceivedDataSize ,void (*Copy_voidNotificationAction)(void));


#endif /* USART_INTERFACE_H_ */
