/*
 * Rcc.c
 *
 *  Created on: Mar 10, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Bit_utils.h"
#include "../../Std_types.h"
#include "Rcc.h"

#define RCC_CHKVALUE_CLK_MODE   0xC
#define RCC_MAX_STATE           2
#define RCC_CLKMODE_NSTABLE     0
#define RCC_CHKVALUE_PLLSCR     0
#define RCC_CHKVALUE_PLLM       2
#define RCC_CHKVALUE_PLLN       3
#define RCC_CHKVALUE_PLLP       2
#define RCC_CHKVALUE_PLLQ       1


#define RCC_CHKVALUE_APB1       0x4
#define RCC_CHKVALUE_APB2       0x5
#define RCC_CHKVALUE_AHB        0x6
#define RCC_CHKVALUE_AHB        0x6
#define RCC_CHKVALUE_AHB1PERPH  0x8
#define RCC_CHKVALUE_AHB2PERPH  0x9
#define RCC_CHKVALUE_APB1PERPH  0xA
#define RCC_CHKVALUE_APB2PERPH  0xB

#define RCC_REG_BASE            0x40023800

#define RCC_CFGR_SW_MASK          0x03

#define RCC_CR_HISON              0x00000001
#define RCC_CR_HSIRDY             0x00000002
#define RCC_CR_CrystalHSEON       0x00010000
#define RCC_CR_ByPassHSEON        0x00060000
#define RCC_CR_HSERDY             0x00020000
#define RCC_CR_HSEBYP             0x00040000
#define RCC_CR_PLLON              0x01000000
#define RCC_CR_PLLRDY             0x02000000




#define RCC_CHECK_SHIFTVALUE      32

#define PLL                       0x0002

#define RCC_REG ((Rcc_reg *const )(RCC_REG_BASE))


typedef struct
{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RSTR;
	volatile u32 RCC_AHB2RSTR;
	volatile u32 RES0;
	volatile u32 RES1;
	volatile u32 RCC_APB1RSTR;
	volatile u32 RCC_APB2RSTR;
	volatile u32 RES2;
	volatile u32 RES3;
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 RES4;
	volatile u32 RES5;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
}Rcc_reg;




Rcc_tenuErrorStatus Rcc_enuSelect_SysClk(u64 Copy_u64SClk)
{
	Rcc_tenuErrorStatus Local_enuError = Rcc_enuOk;
	u32 Local_RCC_CFGR = RCC_REG->RCC_CFGR;
	Local_RCC_CFGR &= ~(RCC_CFGR_SW_MASK);
	if(( Copy_u64SClk >> RCC_CHECK_SHIFTVALUE) != RCC_CHKVALUE_CLK_MODE)
	{
		Local_enuError = Rcc_enuSysClk_Select_Error;
	}
	else
	{
		Local_RCC_CFGR |= (u32)Copy_u64SClk;
		RCC_REG->RCC_CFGR = Local_RCC_CFGR;
	}
	return Local_enuError;
}


Rcc_tenuErrorStatus Rcc_enuControlClk(u64 Copy_u64Clk,u8 Copy_u8ClkState)
{
	Rcc_tenuErrorStatus Local_enuError = Rcc_enuOk;
	u32 Local_u32RCC_CR = RCC_REG->RCC_CR;
	u8 TimeOut = 50;
	if(((Copy_u64Clk >> RCC_CHECK_SHIFTVALUE) != RCC_CHKVALUE_CLK_MODE) || (Copy_u8ClkState > RCC_MAX_STATE ))
	{
		Local_enuError = Rcc_enuClk_Control_Error;
	}
	else
	{
		switch(Copy_u64Clk)
		{
		case Rcc_u8HSIMode:
			switch(Copy_u8ClkState)
			{
			case Rcc_u8ClkON_State:
				Local_u32RCC_CR |= RCC_CR_HISON;
				RCC_REG->RCC_CR = Local_u32RCC_CR;
				while((((RCC_REG->RCC_CR) & RCC_CR_HSIRDY) == RCC_CLKMODE_NSTABLE) && TimeOut){TimeOut--;}
				break;
			case Rcc_u8ClkOFF_State:
				Local_u32RCC_CR &= ~(1 << RCC_CR_HISON);
				break;
			}
			break;
			case Rcc_u8HSE_ByPassMode:
				switch(Copy_u8ClkState)
				{
				case Rcc_u8ClkON_State:
					Local_u32RCC_CR |= RCC_CR_ByPassHSEON;
					RCC_REG->RCC_CR = Local_u32RCC_CR;
					while((((RCC_REG->RCC_CR) & RCC_CR_HSERDY) == RCC_CLKMODE_NSTABLE) && TimeOut ){TimeOut--;}
					break;
				case Rcc_u8ClkOFF_State:
					Local_u32RCC_CR &= ~(RCC_CR_ByPassHSEON);
					break;
				}
				break;
				case Rcc_u8HSE_CrystalMode:
					switch(Copy_u8ClkState)
					{
					case Rcc_u8ClkON_State:
						Local_u32RCC_CR |= RCC_CR_CrystalHSEON;
						RCC_REG->RCC_CR = Local_u32RCC_CR;
						while((((RCC_REG->RCC_CR) & RCC_CR_HSERDY) == RCC_CLKMODE_NSTABLE) && TimeOut){TimeOut--;}
						break;
					case Rcc_u8ClkOFF_State:
						Local_u32RCC_CR &= ~(RCC_CR_CrystalHSEON);
						break;
					}
					break;
					case Rcc_u8PllMode:
						switch(Copy_u8ClkState)
						{
						case Rcc_u8ClkON_State:
							Local_u32RCC_CR |= RCC_CR_PLLON;
							RCC_REG->RCC_CR = Local_u32RCC_CR;
							while((((RCC_REG->RCC_CR) & RCC_CR_PLLRDY) == RCC_CLKMODE_NSTABLE) && TimeOut ){TimeOut--;}
							break;
						case Rcc_u8ClkOFF_State:
							Local_u32RCC_CR &= ~(RCC_CR_PLLON);
							break;
						}
						break;

		}


	}
	return Local_enuError;
}


u8 Rcc_u8IsClkReady(u64 Copy_u64SClk)
{
	u8 Local_u8ClkIsRDY = Rcc_u8ClkNRDY;
	switch(Copy_u64SClk)
	{
	case Rcc_u8HSIMode:
		if(((RCC_REG->RCC_CR) & RCC_CR_HSIRDY))
		{
			Local_u8ClkIsRDY = Rcc_u8ClkRDY;
		}
		break;
	case Rcc_u8HSE_ModeSysClk:
		if(((RCC_REG->RCC_CR) & (RCC_CR_HSERDY)))
		{
			Local_u8ClkIsRDY = Rcc_u8ClkRDY;
		}
		break;
	case Rcc_u8PllMode:
		if(((RCC_REG->RCC_CR) & (RCC_CR_PLLRDY)) == 1)
		{
			Local_u8ClkIsRDY = Rcc_u8ClkRDY;
		}
		break;
	}
	return Local_u8ClkIsRDY;
}
Rcc_tenuErrorStatus Rcc_enuPll_Cfg(u64 Copy_u32PllSCR,u64 Copy_u32PllM, u64 Copy_u32PllP, u64 Copy_u32PllQ, u64 Copy_u16PllN)
{
	u32 Local_RCC_PllCFGR = 0;
	Rcc_tenuErrorStatus Local_enuError = Rcc_enuOk;


	if(( Copy_u32PllSCR >> RCC_CHECK_SHIFTVALUE ) != RCC_CHKVALUE_PLLSCR)
	{
		Local_enuError = Rcc_enuPllSCR_Cfg_Error;
	}
	else if(( Copy_u32PllM >> RCC_CHECK_SHIFTVALUE ) != RCC_CHKVALUE_PLLM)
	{
		Local_enuError = Rcc_enuPllM_Cfg_Error;
	}
	else if(( Copy_u16PllN >> RCC_CHECK_SHIFTVALUE ) != RCC_CHKVALUE_PLLN)
	{
		Local_enuError = Rcc_enuPllN_Cfg_Error;
	}
	else if(( Copy_u32PllP >> RCC_CHECK_SHIFTVALUE ) != RCC_CHKVALUE_PLLP)
	{
		Local_enuError = Rcc_enuPllP_Cfg_Error;
	}
	else if(( Copy_u32PllQ >> RCC_CHECK_SHIFTVALUE ) != RCC_CHKVALUE_PLLQ)
	{
		Local_enuError = Rcc_enuPllQ_Cfg_Error;
	}
	else
	{
		Local_RCC_PllCFGR =( (u32)Copy_u32PllM | (u32)Copy_u32PllSCR | (u32)Copy_u32PllQ | (u32)Copy_u32PllP | (u8)Copy_u16PllN );
		RCC_REG->RCC_PLLCFGR = Local_RCC_PllCFGR;

	}

	return Local_enuError;
}



Rcc_tenuErrorStatus Rcc_enuCtrlBus_Prescaler(u64 Copy_u16AHB_PRESC,u64 Copy_u8APB1_PRESC, u64 Copy_u8APB2_PRESC)
{
	u32 Local_RCC_CFGR = 0;
	Rcc_tenuErrorStatus Local_enuError = Rcc_enuOk;
	if(( Copy_u16AHB_PRESC >> RCC_CHECK_SHIFTVALUE ) != RCC_CHKVALUE_AHB)
	{
		Local_enuError = Rcc_enuAHB_Cfg_Error;
	}
	else if(( Copy_u8APB1_PRESC >> RCC_CHECK_SHIFTVALUE ) != RCC_CHKVALUE_APB1)
	{
		Local_enuError = Rcc_enuAPB2_Cfg_Error;
	}
	else if(( Copy_u8APB2_PRESC >> RCC_CHECK_SHIFTVALUE ) != RCC_CHKVALUE_APB2)
	{
		Local_enuError = Rcc_enuAPB2_Cfg_Error;
	}
	else
	{
		Local_RCC_CFGR = (u32)Copy_u8APB2_PRESC | (u32)Copy_u8APB1_PRESC | (u32)Copy_u16AHB_PRESC ;
		RCC_REG->RCC_CFGR = Local_RCC_CFGR;
	}

	return Local_enuError;
}



Rcc_tenuErrorStatus Rcc_enuPerpheralClk_Control(u8 Copy_u8Bus,u64 Copy_u64Perpheral,u8 Copy_u8PerphClkState)
{
	Rcc_tenuErrorStatus Local_enuError = Rcc_enuOk;
	u32 Local_u32RCCPerph_REG = 0;
	switch(Copy_u8Bus)
	{
	case Rcc_u8AHB1_BUS:
		if((Copy_u64Perpheral >> RCC_CHECK_SHIFTVALUE) == RCC_CHKVALUE_AHB1PERPH)
		{
			Local_u32RCCPerph_REG = RCC_REG->RCC_AHB1ENR;
			if(Copy_u8PerphClkState == Rcc_u8ClkON_State)
			{
				Local_u32RCCPerph_REG &= (u32)~(Copy_u64Perpheral);
				Local_u32RCCPerph_REG|= (u32)Copy_u64Perpheral;
			}
			else
			{
				Local_u32RCCPerph_REG &= (u32)~(Copy_u64Perpheral);
			}
			RCC_REG->RCC_AHB1ENR = Local_u32RCCPerph_REG;
		}
		else
		{
			Local_enuError = Rcc_enuAHBPerph_Arg_Error;
		}
		break;
	case Rcc_u8AHB2_BUS:
		if((Copy_u64Perpheral >> RCC_CHECK_SHIFTVALUE) == RCC_CHKVALUE_AHB2PERPH)
		{
			Local_u32RCCPerph_REG = RCC_REG->RCC_AHB2ENR;
			if(Copy_u8PerphClkState == Rcc_u8ClkON_State)
			{
				Local_u32RCCPerph_REG &= (u32)~(Copy_u64Perpheral);
				Local_u32RCCPerph_REG|= (u32)Copy_u64Perpheral;
			}
			else
			{
				Local_u32RCCPerph_REG &= (u32)~(Copy_u64Perpheral);
			}
			RCC_REG->RCC_AHB2ENR = Local_u32RCCPerph_REG;
		}
		break;
	case Rcc_u8APB1_BUS:
		if((Copy_u64Perpheral >> RCC_CHECK_SHIFTVALUE) == RCC_CHKVALUE_APB1PERPH)
		{
			Local_u32RCCPerph_REG = RCC_REG->RCC_APB1ENR;
			if(Copy_u8PerphClkState == Rcc_u8ClkON_State)
			{
				Local_u32RCCPerph_REG &= (u32)~(Copy_u64Perpheral);
				Local_u32RCCPerph_REG|= (u32)Copy_u64Perpheral;
			}
			else
			{
				Local_u32RCCPerph_REG &= (u32)~(Copy_u64Perpheral);
			}
			RCC_REG->RCC_APB1ENR = Local_u32RCCPerph_REG;
		}
		break;
	case Rcc_u8APB2_BUS:
		if((Copy_u64Perpheral >> RCC_CHECK_SHIFTVALUE) == RCC_CHKVALUE_APB2PERPH)
		{
			Local_u32RCCPerph_REG = RCC_REG->RCC_APB2ENR;
			if(Copy_u8PerphClkState == Rcc_u8ClkON_State)
			{
				Local_u32RCCPerph_REG &= (u32)~(Copy_u64Perpheral);
				Local_u32RCCPerph_REG|= (u32)Copy_u64Perpheral;
			}
			else
			{
				Local_u32RCCPerph_REG &= (u32)~(Copy_u64Perpheral);
			}
			RCC_REG->RCC_APB2ENR = Local_u32RCCPerph_REG;
		}
		break;
	default:
		Local_enuError = Rcc_enuBUSSLK_Perph_Error;
	}
	return Local_enuError;
}
