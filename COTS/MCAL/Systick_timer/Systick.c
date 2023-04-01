/*
 * Systick.c
 *
 *  Created on: Mar 27, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Std_types.h"
#include "../../Bit_utils.h"
#include "Systick.h"
#include "Systick_cfg.h"

#define CHCK_SHIFT_VALUE        15
#define STK_CLKSOURCE_CHCK      0
#define STK_EXPCONTROL_CHCK     1
#define STK_BASEADDERSS        (0xE000E010)
#define STK_START              (0x01)
#define MAX_TICKS_VALUE        (0x00FFFFFF)

#define STK_Regs              ((void *) (STK_BASEADDERSS))

static SysticCBF_t App_Func = NULL;

typedef struct
{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;
}Systick_Reg;


STK_ErrorState_t Systick_init (void)
{
	STK_ErrorState_t Loc_enuErrorState = Systick_Error_ok;
	u32 Loc_u32STKCTR = ((Systick_Reg *)STK_Regs)->STK_CTRL;
	if((STK_CLOCKSOURCE >> CHCK_SHIFT_VALUE) != STK_CLKSOURCE_CHCK)
	{
		Loc_enuErrorState = Systick_ClkSource_Error;
	}
	else if((STC_EXPCONTROL >> CHCK_SHIFT_VALUE) != STK_EXPCONTROL_CHCK)
	{
		Loc_enuErrorState = Systick_ExpControl_Error;
	}
	else
	{
		Loc_u32STKCTR |= (u32)((u8)STK_CLOCKSOURCE | (u8)STC_EXPCONTROL);
		((Systick_Reg *)STK_Regs)->STK_CTRL = Loc_u32STKCTR;
	}


	return Loc_enuErrorState;
}
STK_ErrorState_t Systick_SetTickTime_ms(u32 Ticks_ms)
{
	STK_ErrorState_t Loc_enuErrorState = Systick_Error_ok;
	// ms = (numOfTicks)+1 * (1/clkSource)
	u32 Loc_u32NumOTicks = 0;
	Loc_u32NumOTicks = (Ticks_ms * (SYS_CLK_FRQMHZ)*1000) - 1;
	if(Loc_u32NumOTicks > MAX_TICKS_VALUE)
	{
		Loc_enuErrorState = Systick_Value_Error;
	}
	else
	{
		((Systick_Reg *)STK_Regs)->STK_LOAD = Loc_u32NumOTicks;
	}

	return Loc_enuErrorState;

}


void Systick_Start(void)
{
	((Systick_Reg *)STK_Regs)->STK_CTRL |= STK_START;
}
STK_ErrorState_t Systick_RegisterCBF(SysticCBF_t CBG)
{
	STK_ErrorState_t Loc_enuErrorState = Systick_Error_ok;
	if(CBG != NULL)
	{
		App_Func = CBG;
	}
	else
	{
		Loc_enuErrorState = Systick_NULLCBF_Error;
	}

	return Loc_enuErrorState;
}

void SysTick_Handler (void)
{
  if(App_Func != NULL)
  {
	  ((Systick_Reg *)STK_Regs)->STK_CTRL &= ~(0x8000);
	  App_Func();
  }
}

