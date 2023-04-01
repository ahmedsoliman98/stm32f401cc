/*
 * GPIO.c
 *
 *  Created on: Mar 19, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Std_types.h"
#include "../../Bit_utils.h"
#include "GPIO.h"

#define GPIOA_BASE_ADDRESS        0x40020000
#define GPIOB_BASE_ADDRESS        0x40020400
#define GPIOC_BASE_ADDRESS        0x40020800
#define GPIOD_BASE_ADDRESS        0x40020C00
#define GPIOE_BASE_ADDRESS        0x40021000
#define GPIOH_BASE_ADDRESS        0x40021C00






#define CHCK_MODE_VALUE           (u8)0x00
#define CHCK_SPEED_VALUE          (u8)1
#define CHCK_PINNUMBER_VALUE      (u8)2
#define CHCK_PORT_VALUE           (u8)3
#define CHCK_PINSTATE_VALUE       (u8)4
#define CHCK_u16SHIFT_VALUE       (u8)8
#define CHCK_u64SHIFT_VALUE       (u8)32
#define CHCK_MODESHIFT_VALUE      (u8)128



/* Mask To Get Dir/Type/ PUPD from mask */

#define GET_PUORPD     (u8)0x03
#define GET_TYPE       (u8)0x08
#define GET_MODE       (u8)0x60
#define CLR_MSK_2bit   (u8)0x03
#define CLR_MSK_1bit   (u8)0x01



typedef struct{
	volatile u32 GPIOx_MODER;
	volatile u32 GPIOx_OTYPER;
	volatile u32 GPIOx_OSPEEDR;
	volatile u32 GPIOx_PUPDER;
	volatile u32 GPIOx_IDR;
	volatile u32 GPIOx_ODR;
	volatile u32 GPIOx_BSRR;
	volatile u32 GPIOx_LCKR;
	volatile u32 GPIOx_AFRL;
	volatile u32 GPIOx_AFRH;
}Gpio_reg;


#define GPIOA     ((Gpio_reg * const)(GPIOA_BASE_ADDRESS))
#define GPIOB     ((Gpio_reg * const)(GPIOB_BASE_ADDRESS))
#define GPIOC     ((Gpio_reg * const)(GPIOC_BASE_ADDRESS))
#define GPIOD     ((Gpio_reg * const)(GPIOD_BASE_ADDRESS))
#define GPIOE     ((Gpio_reg * const)(GPIOE_BASE_ADDRESS))
#define GPIOH     ((Gpio_reg * const)(GPIOH_BASE_ADDRESS))



Gpio_tenuErrorStatus Gpio_initPin(Gpio_PinCfg_t * Add_Gpio_Pincfg_GpioPin)
{
	Gpio_tenuErrorStatus Loc_enuErrorState = Gpio_enuOK;
	u32 Loc_u32TempReg = 0x00;
	if ( ( Add_Gpio_Pincfg_GpioPin->Gpio_PinMode & CHCK_MODESHIFT_VALUE ) != CHCK_MODE_VALUE)
	{
		Loc_enuErrorState = Gpio_enuPinCfgMode_Error;
	}
	else if ((Add_Gpio_Pincfg_GpioPin->Gpio_PinSpeed >> CHCK_u16SHIFT_VALUE) != CHCK_SPEED_VALUE)
	{
		Loc_enuErrorState = Gpio_enuPinCfgSpeed_Error;
	}
	else if ((Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber >> CHCK_u16SHIFT_VALUE) != CHCK_PINNUMBER_VALUE)
	{
		Loc_enuErrorState = Gpio_enuPinCfgPinNumber_Error;
	}
	else if ((Add_Gpio_Pincfg_GpioPin->Gpio_PinPort >> CHCK_u16SHIFT_VALUE) != CHCK_PORT_VALUE)
	{
		Loc_enuErrorState = Gpio_enuPinCfgPinPort_Error;
	}
	else
	{
		switch(Add_Gpio_Pincfg_GpioPin->Gpio_PinPort)
		{
		case Gpio_u16PortA:
			Loc_u32TempReg = GPIOA->GPIOx_MODER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_MODE)>>5) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)) *2));
			GPIOA->GPIOx_MODER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOA->GPIOx_OTYPER;
			Loc_u32TempReg &= ~(CLR_MSK_1bit << (u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_TYPE)>>3) << ((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)));
			GPIOA->GPIOx_OTYPER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOA->GPIOx_PUPDER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_PUORPD)) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			GPIOA->GPIOx_PUPDER = Loc_u32TempReg;

			GPIOA->GPIOx_OSPEEDR = (((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinSpeed) << ((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)*2);

			break;
		case Gpio_u16PortB:
			Loc_u32TempReg = GPIOB->GPIOx_MODER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_MODE)>>5) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)) *2));
			GPIOB->GPIOx_MODER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOB->GPIOx_OTYPER;
			Loc_u32TempReg &= ~(CLR_MSK_1bit << (u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_TYPE)>>3) << ((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)));
			GPIOB->GPIOx_OTYPER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOB->GPIOx_PUPDER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_PUORPD)) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			GPIOB->GPIOx_PUPDER = Loc_u32TempReg;

			GPIOB->GPIOx_OSPEEDR = (((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinSpeed) << ((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)*2);
			break;
		case Gpio_u16PortC:
			Loc_u32TempReg = GPIOC->GPIOx_MODER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_MODE)>>5) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)) *2));
			GPIOC->GPIOx_MODER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOC->GPIOx_OTYPER;
			Loc_u32TempReg &= ~(CLR_MSK_1bit << (u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_TYPE)>>3) << ((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)));
			GPIOC->GPIOx_OTYPER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOC->GPIOx_PUPDER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_PUORPD)) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			GPIOC->GPIOx_PUPDER = Loc_u32TempReg;

			GPIOC->GPIOx_OSPEEDR = (((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinSpeed) << ((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)*2);
			break;
		case Gpio_u16PortD:
			Loc_u32TempReg = GPIOD->GPIOx_MODER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_MODE)>>5) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)) *2));
			GPIOD->GPIOx_MODER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOD->GPIOx_OTYPER;
			Loc_u32TempReg &= ~(CLR_MSK_1bit << (u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_TYPE)>>3) << ((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)));
			GPIOD->GPIOx_OTYPER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOD->GPIOx_PUPDER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_PUORPD)) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			GPIOD->GPIOx_PUPDER = Loc_u32TempReg;

			GPIOD->GPIOx_OSPEEDR = (((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinSpeed) << ((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)*2);
			break;
		case Gpio_u16PortE:
			Loc_u32TempReg = GPIOE->GPIOx_MODER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_MODE)>>5) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)) *2));
			GPIOE->GPIOx_MODER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOE->GPIOx_OTYPER;
			Loc_u32TempReg &= ~(CLR_MSK_1bit << (u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_TYPE)>>3) << ((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)));
			GPIOE->GPIOx_OTYPER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOE->GPIOx_PUPDER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_PUORPD)) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			GPIOE->GPIOx_PUPDER = Loc_u32TempReg;

			GPIOE->GPIOx_OSPEEDR = (((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinSpeed) << ((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)*2);
			break;
		case Gpio_u16PortH:
			Loc_u32TempReg = GPIOH->GPIOx_MODER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_MODE)>>5) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)) *2));
			GPIOH->GPIOx_MODER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOH->GPIOx_OTYPER;
			Loc_u32TempReg &= ~(CLR_MSK_1bit << (u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_TYPE)>>3) << ((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)));
			GPIOH->GPIOx_OTYPER = Loc_u32TempReg;

			Loc_u32TempReg = GPIOH->GPIOx_PUPDER;
			Loc_u32TempReg &= ~(CLR_MSK_2bit << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			Loc_u32TempReg |= (((((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinMode)&GET_PUORPD)) << (((u8)(Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber))*2));
			GPIOH->GPIOx_PUPDER = Loc_u32TempReg;

			GPIOH->GPIOx_OSPEEDR = (((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinSpeed) << ((u8)Add_Gpio_Pincfg_GpioPin->Gpio_PinNumber)*2);
			break;
		}
	}
	return Loc_enuErrorState;

}
Gpio_tenuErrorStatus Gpio_SetPinValue(Gpio_PinCfg_t * Add_Gpio_Pincfg,u64 Copy_u64PinState)
{
	Gpio_tenuErrorStatus Loc_enuErrorState = Gpio_enuOK;
	if((Copy_u64PinState >> CHCK_u64SHIFT_VALUE) != CHCK_PINSTATE_VALUE)
	{
		Loc_enuErrorState = Gpio_enuSetPin_State_Error;
	}
	else if ( ( Add_Gpio_Pincfg->Gpio_PinMode & CHCK_MODESHIFT_VALUE ) != CHCK_MODE_VALUE)
	{
		Loc_enuErrorState = Gpio_enuPinCfgMode_Error;
	}
	else if ((Add_Gpio_Pincfg->Gpio_PinSpeed >> CHCK_u16SHIFT_VALUE) != CHCK_SPEED_VALUE)
	{
		Loc_enuErrorState = Gpio_enuPinCfgSpeed_Error;
	}
	else if ((Add_Gpio_Pincfg->Gpio_PinNumber >> CHCK_u16SHIFT_VALUE) != CHCK_PINNUMBER_VALUE)
	{
		Loc_enuErrorState = Gpio_enuPinCfgPinNumber_Error;
	}
	else if ((Add_Gpio_Pincfg->Gpio_PinPort >> CHCK_u16SHIFT_VALUE) != CHCK_PORT_VALUE)
	{
		Loc_enuErrorState = Gpio_enuPinCfgPinPort_Error;
	}
	else
	{
		switch(Add_Gpio_Pincfg->Gpio_PinPort)
		{
		case Gpio_u16PortA:
			GPIOA->GPIOx_BSRR = (u32)Copy_u64PinState;
			break;
		case Gpio_u16PortB:
			GPIOB->GPIOx_BSRR = (u32)Copy_u64PinState;
			break;
		case Gpio_u16PortC:
			GPIOC->GPIOx_BSRR = (u32)Copy_u64PinState;
			break;
		case Gpio_u16PortD:
			GPIOD->GPIOx_BSRR = (u32)Copy_u64PinState;
			break;
		case Gpio_u16PortE:
			GPIOE->GPIOx_BSRR = (u32)Copy_u64PinState;
			break;
		case Gpio_u16PortH:
			GPIOH->GPIOx_BSRR = (u32)Copy_u64PinState;
			break;

		}
	}
	return Gpio_enuPinCfgPinPort_Error;
}



Gpio_tenuErrorStatus Gpio_GetPinValue(Gpio_PinCfg_t * Add_Gpio_Pincfg,pu8 Add_u8PinState)
{
	    Gpio_tenuErrorStatus Loc_enuErrorState = Gpio_enuOK;
		if ( ( Add_Gpio_Pincfg->Gpio_PinMode & CHCK_MODESHIFT_VALUE ) != CHCK_MODE_VALUE)
		{
			Loc_enuErrorState = Gpio_enuPinCfgMode_Error;
		}
		else if ((Add_Gpio_Pincfg->Gpio_PinSpeed >> CHCK_u16SHIFT_VALUE) != CHCK_SPEED_VALUE)
		{
			Loc_enuErrorState = Gpio_enuPinCfgSpeed_Error;
		}
		else if ((Add_Gpio_Pincfg->Gpio_PinNumber >> CHCK_u16SHIFT_VALUE) != CHCK_PINNUMBER_VALUE)
		{
			Loc_enuErrorState = Gpio_enuPinCfgPinNumber_Error;
		}
		else if ((Add_Gpio_Pincfg->Gpio_PinPort >> CHCK_u16SHIFT_VALUE) != CHCK_PORT_VALUE)
		{
			Loc_enuErrorState = Gpio_enuPinCfgPinPort_Error;
		}
		else if(Add_u8PinState == NULL)
		{
			Loc_enuErrorState = Gpio_enuNUL_Ptr_Error;
		}
		else
		{
			switch(Add_Gpio_Pincfg->Gpio_PinPort)
					{
					case Gpio_u16PortA:
						*Add_u8PinState = GET_BIT(GPIOA->GPIOx_IDR,((u8)Add_Gpio_Pincfg->Gpio_PinNumber));
						break;
					case Gpio_u16PortB:
						*Add_u8PinState = GET_BIT(GPIOB->GPIOx_IDR,((u8)Add_Gpio_Pincfg->Gpio_PinNumber));
						break;
					case Gpio_u16PortC:
						*Add_u8PinState = GET_BIT(GPIOC->GPIOx_IDR,((u8)Add_Gpio_Pincfg->Gpio_PinNumber));
						break;
					case Gpio_u16PortD:
						*Add_u8PinState = GET_BIT(GPIOD->GPIOx_IDR,((u8)Add_Gpio_Pincfg->Gpio_PinNumber));
						break;
					case Gpio_u16PortE:
						*Add_u8PinState = GET_BIT(GPIOE->GPIOx_IDR,((u8)Add_Gpio_Pincfg->Gpio_PinNumber));
						break;
					case Gpio_u16PortH:
						*Add_u8PinState = GET_BIT(GPIOH->GPIOx_IDR,((u8)Add_Gpio_Pincfg->Gpio_PinNumber));
						break;

					}
		}

		return Loc_enuErrorState;
}



