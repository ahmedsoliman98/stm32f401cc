/*
 * H_Led.c
 *
 *  Created on: Mar 24, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Bit_utils.h"
#include "../../Std_types.h"
#include "../MCAL/GPIO.h"
#include "H_Led.h"
#include "H_Led_cfg.h"






#define SHIFT_CHCK_VALUE 8
#define CHCK_LED_TYPE    3



extern Led_cfg App_Leds[];

extern Led_Error_State Led_init(void)
{
	Gpio_PinCfg_t Led_CFG;
	Led_Error_State Loc_enuErrorState = Led__Ok;
	u8 Loc_u8Counter;
	for(Loc_u8Counter = 0; Loc_u8Counter < LED_TOT_NUM; Loc_u8Counter++)
	{
		if ((App_Leds[Loc_u8Counter].Led_ActiveState >> SHIFT_CHCK_VALUE) != CHCK_LED_TYPE)
		{
			Loc_enuErrorState = Led_Type_Error;
		}
		else
		{
			switch(App_Leds[Loc_u8Counter].Led_OType)
			{
			case Led_u8OType_PP:
				if(App_Leds[Loc_u8Counter].Led_ActiveState == Led_u16Active_Low)
				{
					Led_CFG.Gpio_PinMode = Gpio_u8PinMode_PP_PU;
				}
				else
				{
					Led_CFG.Gpio_PinMode = Gpio_u8PinMode_PP_PD;
				}
				break;
			case Led_u8OType_OD:
				if(App_Leds[Loc_u8Counter].Led_ActiveState == Led_u16Active_Low)
				{
					Led_CFG.Gpio_PinMode = Gpio_u8PinMode_OD_PU;
				}
				else
				{
					Led_CFG.Gpio_PinMode = Gpio_u8PinMode_OD_PD;
				}
				break;
			}
			Led_CFG.Gpio_PinNumber = App_Leds[Loc_u8Counter].Led_Pin;
			Led_CFG.Gpio_PinPort = App_Leds[Loc_u8Counter].Led_Port;
			Led_CFG.Gpio_PinSpeed = Gpio_u16SpeedCfg_HIGH;
			Gpio_initPin(&Led_CFG);
		}
	}

	return Loc_enuErrorState;

}

extern Led_Error_State Led_SetState(u16 Led_Name, u8 Led_State)
{
	u8 Loc_u8PinValue = App_Leds[Led_Name].Led_ActiveState ^ Led_State;
	Led_Error_State Loc_enuErrorState = Led__Ok;
	if(Loc_u8PinValue == 0)
	{
		switch(App_Leds[Led_Name].Led_Pin)
		{
		case Led_u16Pin0:
			Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN0LOW);
			break;
		case Led_u16Pin1:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN1LOW);
					break;
		case Led_u16Pin2:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN2LOW);
					break;
		case Led_u16Pin3:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN3LOW);
					break;
		case Led_u16Pin4:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN4LOW);
					break;
		case Led_u16Pin5:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN5LOW);
					break;
		case Led_u16Pin6:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN6LOW);
					break;
		case Led_u16Pin7:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN7LOW);
					break;
		case Led_u16Pin8:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN8LOW);
					break;
		case Led_u16Pin9:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN9LOW);
					break;
		case Led_u16Pin10:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN10LOW);
					break;
		case Led_u16Pin11:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN11LOW);
					break;
		case Led_u16Pin12:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN12LOW);
					break;
		case Led_u16Pin13:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN13LOW);
					break;
		case Led_u16Pin14:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN14LOW);
					break;
		case Led_u16Pin15:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN15LOW);
					break;
		}
	}
	else
	{
		switch(App_Leds[Led_Name].Led_Pin)
				{
				case Led_u16Pin0:
					Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN0HIGH);
					break;
				case Led_u16Pin1:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN1HIGH);
							break;
				case Led_u16Pin2:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN2HIGH);
							break;
				case Led_u16Pin3:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN3HIGH);
							break;
				case Led_u16Pin4:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN4HIGH);
							break;
				case Led_u16Pin5:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN5HIGH);
							break;
				case Led_u16Pin6:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN6HIGH);
							break;
				case Led_u16Pin7:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN7HIGH);
							break;
				case Led_u16Pin8:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN8HIGH);
							break;
				case Led_u16Pin9:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN9HIGH);
							break;
				case Led_u16Pin10:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN10HIGH);
							break;
				case Led_u16Pin11:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN11HIGH);
							break;
				case Led_u16Pin12:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN12HIGH);
							break;
				case Led_u16Pin13:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN13HIGH);
							break;
				case Led_u16Pin14:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN14HIGH);
							break;
				case Led_u16Pin15:
							Gpio_WritePinValue(App_Leds[Led_Name].Led_Port,Gpio_u64SET_PIN15HIGH);
							break;
				}
	}

	return Loc_enuErrorState;

}
