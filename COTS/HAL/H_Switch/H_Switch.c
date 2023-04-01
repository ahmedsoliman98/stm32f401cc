/*
 * H_Switch.c
 *
 *  Created on: Mar 25, 2022
 *      Author: Ahmed Soliman
 */


#include "../../Std_types.h"
#include "../../Bit_utils.h"
#include "../MCAL/GPIO.h"
#include "H_Switch.h"
#include "H_Switch_Cfg.h"



extern const Switch_Cfg_t Switches[];
/*
 * make array for each witch in the system current state
 */
static Switch_State_t Status[SW_TOT_NUM];



PB_enuErrorState H_Switch_init (void)
{
	PB_enuErrorState Loc_enuErrorS = SW_Error_ok;
	u8 Loc_u8Counter = 0;
	Gpio_PinCfg_t PB_cfg;
	for(Loc_u8Counter = 0; Loc_u8Counter < SW_TOT_NUM; Loc_u8Counter++)
	{
		PB_cfg.Gpio_PinNumber = Switches[Loc_u8Counter].PB_u64PinNumber;
		PB_cfg.Gpio_PinPort = Switches[Loc_u8Counter].PB_vidPort;
		PB_cfg.Gpio_PinMode = Switches[Loc_u8Counter].PB_u8Mode;
		PB_cfg.Gpio_PinSpeed = Gpio_u16SpeedCfg_HIGH;

		if(Gpio_initPin(&PB_cfg) != Gpio_enuOK)
		{
			Loc_enuErrorS = SW_Error_Nok;
			break;
		}
	}


	return Loc_enuErrorS;
}

Switch_State_t H_Switch_GetStatus(u8 Copy_u8PBName)
{
	return Status[Copy_u8PBName];
}

/*
 * <H_Switch_Readed>
 * THIS FUNCTION INDICATE SOFTWARE THAT THE SWITCH IS ALREADY READ TO PREVENT READ SWITCH MORE THAN ONE TIME
 */
void H_Switch_Readed (u8 SwitchName)
{
	Status[SwitchName] = READED;
}
/*
 * <H_Switch_task>
 * ths main task is decide the state of the switch every 1ms
 * to help to debouce we read the state 5 times if it same vale that mean it current switch stat not boucing signal
 */

void H_Switch_task(void)
{
	static u32 counter[SW_TOT_NUM];
	static u8 prevState[SW_TOT_NUM];
	u8 CurState;
	u32 idx = 0;
	for(idx =0; idx < SW_TOT_NUM; idx++)
	{
		 Gpio_ReadPinValue(Switches[idx].PB_vidPort,Switches[idx].PB_u64PinNumber,&CurState);
		 if(CurState == prevState[idx])
		 {
			 counter[idx]++;
		 }
		 else
		 {
			 counter[idx] = 0;
			 /* START NEW STATE CONDETION */
			 prevState[idx] = CurState;
		 }

		 if(counter[idx] == 5)
		 {
			 /* COMPAER THE CURRENT PB STATE WITH IT INITIAL MODE STATE */
			 if(CurState != (Switches[idx].PB_u8Mode & 0x01))
			 {
				 Status[idx] = PRESSED;
			 }
			 else
			 {
				 Status[idx] = RELEASED;
			 }

			 prevState[idx] = CurState;
		 }
	}

}
