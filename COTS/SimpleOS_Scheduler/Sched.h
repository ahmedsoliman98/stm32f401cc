/*
 * Sched.h
 *
 *  Created on: Apr 2, 2022
 *      Author: Ahmed Soliman
 */

#ifndef SCHED_H_
#define SCHED_H_


/* Pointer to runnable function*/
typedef void(* runnable_ptr)(void);


typedef struct{
	runnable_ptr Runnable_Task;
	u32 CyclicTime_ms;
}Runnable;

/* Scheduler Error State */
typedef enum{
	Sched_Error_ok,
	Sched_NullRunnable_Error,
}Sched_Error_State;

/*********************** Sched function *********************************/


/* <Sched_init>
 * This function responsible to select systick time in ms
 *                              register systick Call back function
 *                              init Systick
 */
void Sched_init(void);

/* <Sched_Start>
 * This function responsible to start the scheduler operation by run Systick
 */
void Sched_Start(void);






#endif /* SCHED_H_ */
