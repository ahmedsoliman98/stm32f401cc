/*
 * H_Led_cfg.c
 *
 *  Created on: Mar 24, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Bit_utils.h"
#include "../../Std_types.h"
#include "H_Led.h"
#include "H_Led_cfg.h"


const Led_cfg App_Leds[]={

		[LED_STOP]={
				.Led_Port = Led_u16PortA,
				.Led_Pin = Led_u16Pin0,
				.Led_ActiveState = Led_u16Active_High,
				.Led_OType = Led_u8OType_PP
		},
		[LED_START]={
				.Led_Port = Led_u16PortB,
				.Led_Pin = Led_u16Pin0,
				.Led_ActiveState = Led_u16Active_Low,
				.Led_OType = Led_u8OType_PP
		}

};




