/*
 * Keypad.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Ahmed Soliman
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_

#define READED    '\0'

typedef struct{
	u64 Keypad_u64PinNum;
	void* Keypad_vidPort;
	u8 Keypad_pinMode;
}KeyPad_Pin_cfg;

typedef enum{
	Keypad_enuOK,
	Keypad_enuNOK,
	Keypad_enuPtrNull_Error,
}Keypad_Error_State_t;


Keypad_Error_State_t Keypad_enuInit(void);
void Keypad_KeyReaded(void);
void H_Keypad_task(void);
u8 Keypad_u8GetKey(void);

#endif /* HAL_KEYPAD_H_ */
