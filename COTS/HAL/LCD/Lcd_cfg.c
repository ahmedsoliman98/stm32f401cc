/*
 * Lcd_cfg.c
 *
 *  Created on: Apr 6, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Bit_utils.h"
#include "../../Std_types.h"
#include "../MCAL/GPIO.h"
#include "Lcd.h"
#include "Lcd_cfg.h"



Lcd_cfg LCD_SetUp_cfg = {
		/* SET THE INSTRUXTION CONFIGURATION */
		.LCD_u8FunctionSet_cfg = Lcd_FUNCTION_SET,
		.LCD_u8CursorDisplay_cfg = Lcd_CursorDisplay_Cfg,
		.LCD_u8EntryMode_cfg = Lcd_EntryMode,
		/* SET THE PIN CONFIGURATION OF THE LCD PINS INSTRUCTION AND DATA*/
		.Lcd_Pins[Lcd_u8RS_PIN]={
				.Lcd_u64PinNum = Gpio_u64PinNumber_PIN0,
				.Lcd_vidPort = GPIOA,
				.Lcd_pinMode =Gpio_u8PinMode_PP,
		},
		.Lcd_Pins[Lcd_u8RW_PIN]={
				.Lcd_u64PinNum = Gpio_u64PinNumber_PIN1,
				.Lcd_vidPort = GPIOA,
				.Lcd_pinMode =Gpio_u8PinMode_PP,
		},
		.Lcd_Pins[Lcd_u8EN_PIN]={
				.Lcd_u64PinNum = Gpio_u64PinNumber_PIN2,
				.Lcd_vidPort = GPIOA,
				.Lcd_pinMode =Gpio_u8PinMode_PP,
		},
		.Lcd_Pins[Lcd_u8D4_PIN]={
				.Lcd_u64PinNum = Gpio_u64PinNumber_PIN3,
				.Lcd_vidPort = GPIOA,
				.Lcd_pinMode =Gpio_u8PinMode_PP,
		},
		.Lcd_Pins[Lcd_u8D5_PIN]={
				.Lcd_u64PinNum = Gpio_u64PinNumber_PIN4,
				.Lcd_vidPort = GPIOA,
				.Lcd_pinMode =Gpio_u8PinMode_PP,
		},
		.Lcd_Pins[Lcd_u8D6_PIN]={
				.Lcd_u64PinNum = Gpio_u64PinNumber_PIN5,
				.Lcd_vidPort = GPIOA,
				.Lcd_pinMode =Gpio_u8PinMode_PP,
		},
		.Lcd_Pins[Lcd_u8D7_PIN]={
				.Lcd_u64PinNum = Gpio_u64PinNumber_PIN6,
				.Lcd_vidPort = GPIOA,
				.Lcd_pinMode =Gpio_u8PinMode_PP,
		},

};



