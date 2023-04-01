/*
 * Systick.h
 *The SysTick counter runs on the processor clock. If this clock signal is stopped for low
 *The power mode, the SysTick counter stops
 *
 *The the correct initialization sequence for the SysTick counter is:
 *  1. Program reload value.
 *  2. Clear current value.
 *  3. Program Control and Status register
 *  Created on: Mar 27, 2022
 *      Author: Ahmed Soliman
 */

#ifndef MCAL_SYSTICK_H_
#define MCAL_SYSTICK_H_







typedef void (*SysticCBF_t)(void);

typedef enum
{
	Systick_Error_ok,
	Systick_ExpControl_Error,
	Systick_ClkSource_Error,
	Systick_Value_Error,
	Systick_NULLCBF_Error

}STK_ErrorState_t;


STK_ErrorState_t Systick_init (void);
STK_ErrorState_t Systick_SetTickTime_ms(u32 Ticks_ms);
void Systick_Start(void);
STK_ErrorState_t Systick_RegisterCBF(SysticCBF_t CBG);

#endif /* MCAL_SYSTICK_H_ */
