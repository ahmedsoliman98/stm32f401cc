/*
 * H_PushButton_Cfg.c
 *
 *  Created on: Mar 25, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Std_types.h"
#include "../../Bit_utils.h"
#include "H_Switch.h"
#include "H_Switch_Cfg.h"
#include "../MCAL/GPIO.h"

/*
 * The switches configuration array of struts
 * each Switch must configure it is
 *  Port , Pin , Mode
 */

const Switch_Cfg_t Switches[]={
		[ButtonStart]={
				.PB_u64PinNumber = Gpio_u64PinNumber_PIN6,
				.PB_vidPort = GPIOB,
				.PB_u8Mode = Gpio_u8PinMode_INPU
		},

};



