/*
 * Keypad_cfg.c
 *
 *  Created on: Apr 17, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Std_types.h"
#include "../../Bit_utils.h"
#include "../MCAL/GPIO.h"
#include "Keypad.h"
#include "Keypad_cfg.h"

/* KEYPAD ARRAY DEFINE THE ROWS AND COLM PINS IN SEQUENCE */
//u8 Keypad_RowPins[]={Keypad_u8Row0, Keypad_u8Row1, Keypad_u8Row2, Keypad_u8Row3};
//u8 Keypad_ClmPins[]={ Keypad_u8Clm0, Keypad_u8Clm1, Keypad_u8Clm2, Keypad_u8Clm3};

/* THE DATA ARRAY THE KEPAD WILL DISPLAY */
const u8 Keypad_arrData [][KEYPAD_COLMDATA_SIZE] ={
		 {'1','2','3','/'},
		 {'4','5','6','*'},
		 {'7','8','9','-'},
		 {'c','0','=','+'}
		 };

/* THE CONFIGURATION ARRAY OF THE HOLW KEYPAD PIN */
const KeyPad_Pin_cfg KeyPad_Pins[KEYPAD_TOT_PINS]={
		[Keypad_u8Row0]={
				.Keypad_u64PinNum = Gpio_u64PinNumber_PIN15,
				.Keypad_vidPort = GPIOA,
				.Keypad_pinMode = Gpio_u8PinMode_PP_PU
		},
		[Keypad_u8Row1]={
				.Keypad_u64PinNum = Gpio_u64PinNumber_PIN3,
				.Keypad_vidPort = GPIOB,
				.Keypad_pinMode = Gpio_u8PinMode_PP_PU
		},
		[Keypad_u8Row2]={
				.Keypad_u64PinNum = Gpio_u64PinNumber_PIN4,
				.Keypad_vidPort = GPIOB,
				.Keypad_pinMode = Gpio_u8PinMode_PP_PU
		},
		[Keypad_u8Row3]={
				.Keypad_u64PinNum = Gpio_u64PinNumber_PIN5,
				.Keypad_vidPort = GPIOB,
				.Keypad_pinMode = Gpio_u8PinMode_PP_PU
		},
		[Keypad_u8Clm0]={
				.Keypad_u64PinNum = Gpio_u64PinNumber_PIN6,
				.Keypad_vidPort = GPIOB,
				.Keypad_pinMode = Gpio_u8PinMode_INPU
		},
		[Keypad_u8Clm1]={
				.Keypad_u64PinNum = Gpio_u64PinNumber_PIN7,
				.Keypad_vidPort = GPIOB,
				.Keypad_pinMode = Gpio_u8PinMode_INPU
		},
		[Keypad_u8Clm2]={
				.Keypad_u64PinNum = Gpio_u64PinNumber_PIN8,
				.Keypad_vidPort = GPIOB,
				.Keypad_pinMode = Gpio_u8PinMode_INPU
		},
		[Keypad_u8Clm3]={
				.Keypad_u64PinNum = Gpio_u64PinNumber_PIN9,
				.Keypad_vidPort = GPIOB,
				.Keypad_pinMode = Gpio_u8PinMode_INPU
		},
};


