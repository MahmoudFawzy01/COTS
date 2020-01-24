/*
 * EXT_INT_register.h
 *
 *  Created on: Jan 12, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef EXT_INT_REGISTER_H_
#define EXT_INT_REGISTER_H_

 #define SREG_ADRESS	 (0x5F)		// Address of the register
 #define MCUCR_ADRESS	 (0x55)		// Address of the register
 #define MCUCSR_ADRESS	 (0x54)		// Address of the register
 #define GICR_ADRESS 	 (0x5B)		// Address of the register
 #define GIFR_ADRESS 	 (0x5A)		// Address of the register

 #define SREG 	*((volatile u8 *)SREG_ADRESS) 	// Get value of the status register
 #define MCUCR 	*((volatile u8 *)MCUCR_ADRESS) 	// Get value of the external interrupt sense control register (INT0,INT1)
 #define MCUCSR *((volatile u8 *)MCUCSR_ADRESS) // Get value of the external interrupt sense control register (INT2)
 #define GICR 	*((volatile u8 *)GICR_ADRESS) 	// Get value of the external interrupt control enable register
 #define GIFR 	*((volatile u8 *)GIFR_ADRESS) 	// Get value of the flag register

#endif /* EXT_INT_REGISTER_H_ */
