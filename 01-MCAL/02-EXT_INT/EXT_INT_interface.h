/*
 * EXT_INT_interface.h
 *
 *  Created on: Oct 23, 2019
 *      Author: Mahmoud Fawzy
 */

#ifndef EXT_INT_INTERFACE_H_
#define EXT_INT_INTERFACE_H_

#include "EXT_INT_private.h"
#include "EXT_INT_registers.h"
#include "EXT_INT_config.h"


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//********************************************************************************************
/*____________________________________________________________________________________________
  PINS :-
 _____________________________________________________________________________________________
 */

// Global Interrupt enable pin
#define SREG_GIE		 		7

// External Interrupt enable pins
#define EXT_INT_GICR_INT0 		6
#define EXT_INT_GICR_INT1 		7
#define EXT_INT_GICR_INT2 		5

// External Interrupt flag pins
#define EXT_INT_GIFR_INT0 		6
#define EXT_INT_GIFR_INT1 		7
#define EXT_INT_GIFR_INT2		5

//Interrupt 0 Sense Control bits
#define EXT_INT_MCUCR_ISC00		0
#define EXT_INT_MCUCR_ISC01		1
//Interrupt 1 Sense Control bits
#define EXT_INT_MCUCR_ISC10		2
#define EXT_INT_MCUCR_ISC11		3
//Interrupt Sense Control 2 bit
#define EXT_INT_MCUCSR_ISC2 	6


//********************************************************************************************
/*____________________________________________________________________________________________
  PINS STATUS/ SENSE LEVEL :-
 _____________________________________________________________________________________________
 */
// Enable/Disable global interrupt pin at status register
#define SREG_GIE_DISABLE		 	0
#define SREG_GIE_ENABLE		 		1
// Enable/Disable interrupt pins
#define EXT_INT_PIN_DISABLE			0
#define EXT_INT_PIN_ENABLE			1

//Interrupt 0 Sense Control levels
#define EXT_INT0_MCUCR_SENSE_LOWLEVEL			0x00
#define EXT_INT0_MCUCR_SENSE_LOGICALCHANGE		0x01
#define EXT_INT0_MCUCR_SENSE_FALLING_EDGE		0x02
#define EXT_INT0_MCUCR_SENSE_RISING_EDGE		0x03

//Interrupt 1 Sense Control levels
#define EXT_INT1_MCUCR_SENSE_LOWLEVEL			0x00
#define EXT_INT1_MCUCR_SENSE_LOGICALCHANGE		0x04
#define EXT_INT1_MCUCR_SENSE_FALLING_EDGE		0x08
#define EXT_INT1_MCUCR_SENSE_RISING_EDGE		0x0C

//Interrupt 2 Sense Control levels
#define EXT_INT2_MCUCR_SENSE_FALLING_EDGE		0x00
#define EXT_INT2_MCUCR_SENSE_RISING_EDGE		0x40

//********************************************************************************************

/*____________________________________________________________________________________________
  FUNCTIONS PROTOTYPES :-
 _____________________________________________________________________________________________
 */

/*Description:External Interrupt Initialization
 * Input     : NA
 * Output    : NA
 * */
void EXT_INT_voidInit(void);

/*Description:Enable Global Interrupt
 * Input     : NA
 * Output    : NA
 * */
void EXT_INT_voidEnableGlobal(void);

/*Description:Disable Global Interrupt
 * Input     : NA
 * Output    : NA
 * */
void EXT_INT_voidDisableGlobal(void);

/*Description:Enable a Specific Interrupt(INT0 or INT1 or INT2)
 * Input     : Copy_u8InterruptPinNo(Interrupt Type to Enable)(INT0 or INT1 or INT2)
 * Output    : ERROR status
 * */
ErrorStatus EXT_INT_EnuEnable(u8 Copy_u8InterruptPinNo);

/*Description:Disable a Specific Interrupt(INT0 or INT1 or INT2)
 * Input     : Copy_u8InterruptPinNo(Interrupt Type to Disable)(INT0 or INT1 or INT2)
 * Output    : ERROR status
 * */
ErrorStatus EXT_INT_EnuDisable(u8 Copy_u8InterruptPinNo);

/*Description:Set Interrupt Level(Rising Edge or Falling Edge or On Change or Low Level)
 * Input     : Copy_u8InterruptPinNo(Interrupt Type to Enable)(INT0 or INT1 or INT2), Copy_u8InterruptLevel(Rising Edge or Falling Edge or On Change or Low Level)
 * Output    : ERROR status
 * */
ErrorStatus EXT_INT_EnuSetLevel(u8 Copy_u8InterruptPinNo,u8 Copy_u8InterruptLevel);

/*Description:Send Address of Function To Call Back Pointer to maintain
 * the architecture of System(No one from Lower Level can Call one from Higher Level
 * and no calling between two in the Same Layer) and to hide Vector Function from main
 * Input     : Copy_u8InterruptPinNo(Interrupt Type to Enable)(INT0 or INT1 or INT2),
 *             *Copy_FunctionAddress Pointer to function with INPUT void and OUTPUT void
 *             to send Function Address to Call Back Function
 * Output    : NA
 * */
ErrorStatus EXT_INT_EnuSetCallBack(u8 Copy_u8InterruptPinNo,void (*Copy_voidCallBackFunc)(void));

#endif /* EXT_INT_INTERFACE_H_ */
