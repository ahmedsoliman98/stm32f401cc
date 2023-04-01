/*
 * Sched.c
 *
 *  Created on: Apr 2, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Bit_utils.h"
#include "../../Std_types.h"
#include "Systick.h"
#include "GPIO.h"
#include "Sched.h"
#include "Sched_cfg.h"

/* Global variable indicate that systick timer reach it is set time */
u8 Scheduler_Start = 0;
extern const Runnable Runnable_List[];



/*
 * <Sched>
 * this function will schedule between the tasks depend on it is time to run
 */

static Sched_Error_State Sched (void)
{
	u16 Local_u16idx;
	static u32 time_ms = FIRST_SCHED_TIME;

	Sched_Error_State Local_enuErrorState = Sched_Error_ok;
	for(Local_u16idx =0; Local_u16idx < TOT_APPRUNNABLE && Local_enuErrorState == Sched_Error_ok; Local_u16idx++)
	{
		if(Runnable_List[Local_u16idx].Runnable_Task != NULL)
		{
			if((time_ms %Runnable_List[Local_u16idx].CyclicTime_ms) == 0)
			{
				(Runnable_List[Local_u16idx].Runnable_Task)();
			}
			else
			{
				/* Do Nothing */

			}
		}
		else
		{
			Local_enuErrorState = Sched_NullRunnable_Error;
		}
	}
	/* INCREASE THE VALUE OF THE SOFTWARE TIMER BY THE VALUE OF TICK TIME THAT CONFIGURE */
	time_ms+= System_CyclicTime_ms;
	/* HANDLEE IF AN OVERFLOW HAPPEN TO THE COUNTER */
	if(time_ms == 0)
	{
		time_ms = FIRST_SCHED_TIME;
	}
	return Local_enuErrorState;

}




/*
 * <Sched_SystickHandle>
 * When the tick time done each time it will change Scheduler_Start state to run Sched function
 */

static void Sched_SystickHandle(void)
{
	Scheduler_Start = 1;
}


/* <Sched_init>
 * This function responsible to select systick time in ms
 *                              register systick Call back function
 *                              init Systick
 */
void Sched_init(void)
{
	Systick_init();
	Systick_SetTickTime_ms(System_CyclicTime_ms);
	Systick_RegisterCBF(Sched_SystickHandle);
}


/* <Sched_Start>
 * This function responsible to start the scheduler operation by run Systick
 */
void Sched_Start(void)
{
	Systick_Start();
	while(1)
	{
		if(Scheduler_Start == 1)
		{
			Scheduler_Start = 0;
			Sched();
		}

		if(H_Switch_GetStatus(ButtonStart) == PRESSED)
		{
			 Lcd_vidDisplayChar('a');
		}
			// Do Nothing

	}
}





