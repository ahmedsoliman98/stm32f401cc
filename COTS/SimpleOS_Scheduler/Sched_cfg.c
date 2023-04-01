/*
 * Sched_cfg.c
 *
 *  Created on: Apr 2, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Bit_utils.h"
#include "../../Std_types.h"
#include"../../PushButton_Driver/src/HAL/H_Switch.h"
#include "../HAL/Lcd.h"
#include "Sched.h"
#include "Sched_cfg.h"

/*
 * This responsible to assign the user task_Rannable
 *  to the list of the scheduler runnable function
 *  it must include all application module to access there tasks function
 *  the index of the array is priority of the running task so assign the higher priority at index 0
 */
const Runnable Runnable_List[TOT_APPRUNNABLE]={
		[0]={
				.Runnable_Task = H_Switch_task,
				.CyclicTime_ms = 150,
		},
		[1]={
				.Runnable_Task = H_Lcd_Task,
				.CyclicTime_ms = 1,
		},
};

