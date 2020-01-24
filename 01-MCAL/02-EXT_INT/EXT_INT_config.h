#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_

			/****Configurations*****/
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// GIE status
#define SREG_GIE_STATUS		SREG_GIE_ENABLE

// Int pins status
#define INT0_STATUS			EXT_INT_PIN_ENABLE
#define INT1_STATUS			EXT_INT_PIN_DISABLE
#define INT2_STATUS			EXT_INT_PIN_DISABLE

// Int pins sense level
#define INT0_SENSE			EXT_INT0_MCUCR_SENSE_FALLING_EDGE
#define INT1_SENSE			EXT_INT1_MCUCR_SENSE_FALLING_EDGE
#define INT2_SENSE			EXT_INT2_MCUCR_SENSE_FALLING_EDGE

#endif /*EXT_INT_CONFIG_H_*/