/*
 * CLCD_config.h
 *
 *  Created on: Jan 15, 2020
 *      Author: Mahmoud Fawzy
 */

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* Data Pins */
#define CLCD_D0_PIN		DIO_PIN_16
#define CLCD_D1_PIN		DIO_PIN_17
#define CLCD_D2_PIN		DIO_PIN_18
#define CLCD_D3_PIN		DIO_PIN_19
#define CLCD_D4_PIN		DIO_PIN_20
#define CLCD_D5_PIN		DIO_PIN_21
#define CLCD_D6_PIN		DIO_PIN_22
#define CLCD_D7_PIN		DIO_PIN_23

/* Control pins  */
/*Register status pin
 *
 * this pin used to select that you write data or  cmnd
 * */
#define CLCD_RS_PIN		DIO_PIN_0

/*RW pin
 *
 * this pin used to select the mode (write or read)
 * */
#define CLCD_RW_PIN		DIO_PIN_1

/*RE pin
 *
 * this pin used to tell the LCD MC that i finished the data writing and confirm the data to show
 *
 * rh default is low and to confirm we should make it high for 130 ns
 * */
#define CLCD_E_PIN		DIO_PIN_2




#endif /* CLCD_CONFIG_H_ */
