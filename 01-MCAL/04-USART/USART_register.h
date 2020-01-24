/*
 * USART_register.h
 *
 *  Created on: Jan 14, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_


 #define UDR_ADRESS 		(0x2C)		// Address of the register
 #define UBRRH_ADRESS 		(0x40)		// Address of the register
 #define UCSRC_ADRESS 		(0x40)		// Address of the register
 #define UCSRA_ADRESS 		(0x2B)		// Address of the register
 #define UCSRB_ADRESS 		(0x2A)		// Address of the register
 #define UBRRL_ADRESS 		(0x29)		// Address of the register


/*	USART Data register	*/
#define UDR 			*((volatile u8 *)UDR_ADRESS) 	// Value of the register
/*		*/
#define UBRRH		 	*((volatile u8 *)UBRRH_ADRESS) 	// Value of the register

/*	USART Control and Status Register C	*/
#define UCSRC		 	*((volatile u8 *)UCSRC_ADRESS) 	// Value of the register
// UCSRC register pins
#define USART_UCSRC_UCPOL			0	// Clock Polarity
#define USART_UCSRC_UCSZ0			1	// Char size bit 0
#define USART_UCSRC_UCSZ1			2	// Char size bit 1
#define USART_UCSRC_USBS			3	// Stop bit select
#define USART_UCSRC_UPM0			4	// Parity Mode bit 0
#define USART_UCSRC_UPM1			5	// Parity Mode bit 1
#define USART_UCSRC_UMSEL			6	// Mode Select
#define USART_UCSRC_URSEL			7	// Register Select


// UCSRA register / USART control and status register
 #define UCSRA 			*((volatile u8 *)UCSRA_ADRESS) 	// Value of the register
// UCSRA register pins
#define USART_UCSRA_MPCM_PIN			0	//Multi-processor Communication Mode pin
#define USART_UCSRA_U2X_PIN				1	//Double the USART Transmission Speed pin
#define USART_UCSRA_PE_PIN				2	//Parity Error pin
#define USART_UCSRA_DOR_PIN				3	//Data OverRun pin
#define USART_UCSRA_FE_PIN				4	//Frame Error pin
#define USART_UCSRA_UDRE_PIN			5	//USART Data Register Empty pin
#define USART_UCSRA_TXC_PIN				6	//USART Transmit Complete pin
#define USART_UCSRA_RXC_PIN				7	//USART Receive Complete pin

/*	USART Control and Status Register B	*/
 #define UCSRB 			*((volatile u8 *)UCSRB_ADRESS) 	// Value of the register
// UCSRB register pins
#define USART_UCSRB_TXB8_PIN				0	// Transmitter bit 8
#define USART_UCSRB_RXB8_PIN				1	// Receiver bit 8
#define USART_UCSRB_UCSZ2_PIN				2	// Char size bit 2
#define USART_UCSRB_TXEN_PIN				3	// Transmitter Enable
#define USART_UCSRB_RXEN_PIN				4	// Receiver Enable
#define USART_UCSRB_UDRIE_PIN				5	// Data Register Empty Interrupt Enable
#define USART_UCSRB_TXCIE_PIN				6	// TX Complete Interrupt Enable
#define USART_UCSRB_RXCIE_PIN				7	// RX Complete Interrupt Enable

 #define UBRRL		 	*((volatile u8 *)UBRRL_ADRESS)	// Value of the register

// you now can use the register name to refer the address of it.


#endif /* USART_REGISTER_H_ */
