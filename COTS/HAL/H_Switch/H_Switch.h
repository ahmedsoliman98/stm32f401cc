/*
 * H_PushButton.h
 *
 *  Created on: Mar 25, 2022
 *      Author: Ahmed Soliman
 */

#ifndef HAL_H_SWITCH_H_
#define HAL_H_SWITCH_H_

#include "H_Switch_Cfg.h"


#define PB_u8PU_Connect   (u8)(0x10)
#define PB_u8PD_Connect   (u8)(0x11)

typedef struct
{
	u64 PB_u64PinNumber;
	void* PB_vidPort;
	u8 PB_u8Mode;
}Switch_Cfg_t;

typedef enum
{
	READED,
	PRESSED,
	RELEASED,
}Switch_State_t;

typedef enum
{
	SW_Error_ok,
	SW_Error_Nok,
}PB_enuErrorState;

PB_enuErrorState H_Switch_init (void);
Switch_State_t H_Switch_GetStatus(u8 Copy_u8PBName);
void H_Switch_task(void);





#endif /* HAL_H_SWITCH_H_ */
