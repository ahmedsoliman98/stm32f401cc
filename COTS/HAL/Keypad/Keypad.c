/*
 * Keypad.c
 *
 *  Created on: Mar 19, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Std_types.h"
#include "../../Bit_utils.h"
#include "../MCAL/GPIO.h"
#include "Keypad.h"
#include "Keypad_cfg.h"


#define READED    '\0'
#define PRESSED    0

/* TO INDICATING THE PHYSIAL PRESSED AND RELEASED OF THE USER */
#define NOT_PRESS  1
#define PRESSING   2


/* THE CONDITON OF THE STATIC PROCESS */
typedef enum{
	DONE,
	NOT_YET,
}Process_Condition_t;

/* DATA THE USER WANT TO DISPLAY IN KEYPAD */
extern const u8 Keypad_arrData [][KEYPAD_COLMDATA_SIZE];

/* THE PIN CONFIGURATION ARRAY DEFINED IN CONFIGURATION FILE */
extern const KeyPad_Pin_cfg KeyPad_Pins[KEYPAD_TOT_PINS];

/*
 * make array for each witch in the system current state
 */
static u8 Keypad_Value = READED;


Keypad_Error_State_t Keypad_enuInit(void)
{
	Keypad_Error_State_t Loc_enuErrorState = Keypad_enuOK;
	u8 Loc_u8idx = 0;
	Gpio_PinCfg_t PinConfig;
	/* INIT THE KEYPAD PINS ARRAY */
	for(Loc_u8idx = 0; Loc_u8idx < KEYPAD_TOT_PINS; Loc_u8idx++)
	{
		PinConfig.Gpio_PinMode =KeyPad_Pins[Loc_u8idx].Keypad_pinMode;
		PinConfig.Gpio_PinNumber = KeyPad_Pins[Loc_u8idx].Keypad_u64PinNum;
		PinConfig.Gpio_PinPort = KeyPad_Pins[Loc_u8idx].Keypad_vidPort;
		PinConfig.Gpio_PinSpeed = Gpio_u16SpeedCfg_HIGH;
		/* CHECK THE ERROR COME FROM THE INIT GPIO FUNCTION */
		if(Gpio_initPin(&PinConfig) != Gpio_enuOK)
		{
			Loc_enuErrorState = Keypad_enuNOK;
			break;
		}
	}

	return Loc_enuErrorState;
}

/* RETURN TO THE USER THE VALUE OF THE KEY THAT PRESSED */
u8 Keypad_u8GetKey(void)
{
	return Keypad_Value;
}

/* THE USER CALL THIS FUNCTION TO INDICATE THAT THE KEY IS ALREADY READ */
void Keypad_KeyReaded(void)
{
	Keypad_Value = READED;
}




void H_Keypad_task(void) //CALL EVERY 5msec
{
	u8 Loc_u8RowPin = 0;
	u16 Loc_u8ClmPin = 0;
	static u8 pressingColmPin_Indx;
	static u8 pressingRowPin_Indx;
	static u32 counter[KEYPAD_ROWDATA_SIZE][KEYPAD_COLMDATA_SIZE];
	static u8 prevState[KEYPAD_ROWDATA_SIZE][KEYPAD_COLMDATA_SIZE];
	static u8 pressState = NOT_PRESS;
	u8 CurState;

	/*IF pressState EQUAL PRESSED THAT MEAN THAT THE USER STILL NO RELEASE THE BOTTON SO WILL NO CHANGE THE STATE OF ROWS*/
	if(pressState == NOT_PRESS)
	{
		for(Loc_u8RowPin = 0; Loc_u8RowPin < KEYPAD_ROWDATA_SIZE; Loc_u8RowPin++)
		{

			/* SET LOW TO THE ROW x */
			Gpio_WritePinValue(KeyPad_Pins[Loc_u8RowPin].Keypad_vidPort,KeyPad_Pins[Loc_u8RowPin].Keypad_u64PinNum, Gpio_u8PIN_LOW);


			/* READ THE COLM VALUE */
			/* THE COLMS PINS START IN SEQUENCE AFTER ROWS PINS IN KeyPad_Pins ARRAY */
			for(Loc_u8ClmPin =KEYPAD_ROWDATA_SIZE; Loc_u8ClmPin < KEYPAD_TOT_PINS; Loc_u8ClmPin++)
			{
				/* IF THE VALUE OF THE COLM IS LOW THAT MEAN THAT THE BOTTON MAY PRESSED */
				Gpio_ReadPinValue(KeyPad_Pins[Loc_u8ClmPin].Keypad_vidPort,KeyPad_Pins[Loc_u8ClmPin].Keypad_u64PinNum,&CurState);
				/* IF THE STATE IS SAME THET MEAN IT MAY BE STABLE TO BE AN ACUAL BOTTON STATE */
				if(CurState == prevState[Loc_u8RowPin][Loc_u8ClmPin-KEYPAD_ROWDATA_SIZE])
				{
					counter[Loc_u8RowPin][Loc_u8ClmPin-KEYPAD_ROWDATA_SIZE]++;
				}
				else
				{
					counter[Loc_u8RowPin][Loc_u8ClmPin-KEYPAD_ROWDATA_SIZE] = 0;
					/* START NEW STATE CONDETION */
					prevState[Loc_u8RowPin][Loc_u8ClmPin-KEYPAD_ROWDATA_SIZE] = CurState;
				}
				/* THE TASK IS COME EVERY 5ms IS THE COUNTER REACH 5 OF THE SAME STATE THAT MEAN IT DEFINITLY DOES BOUNCING */
				if(counter[Loc_u8RowPin][Loc_u8ClmPin-KEYPAD_ROWDATA_SIZE] == 5)
				{
					/* ONLY RETURN THE VALUE IF THE STATE IS PRESSED */
					if(CurState == PRESSED)
					{
						/* DEFINED THE Keypad_Value WITH THE DATA IN THAT CURRENT ROW AND COLM LOCATION */
						Keypad_Value = Keypad_arrData[Loc_u8RowPin][Loc_u8ClmPin-KEYPAD_ROWDATA_SIZE];
						pressingColmPin_Indx = Loc_u8ClmPin;
						pressingRowPin_Indx = Loc_u8RowPin;
						pressState = PRESSING;
					}
					prevState[Loc_u8RowPin][Loc_u8ClmPin-KEYPAD_ROWDATA_SIZE] = CurState;
				}
			}
			/* IF THE PRESS SATE IS PRESSING WE DO NOT WANT THE ROW CHANGE IT IS VALUE TO AVOID IF THE USER HOLD IT HAND TO MAKE COLM READ SAME VALUE */
			if(pressState != PRESSING)
			{
				/* RETURN ROW VALUE TO NORMAR 'HIGH' */
				Gpio_WritePinValue(KeyPad_Pins[Loc_u8RowPin].Keypad_vidPort,KeyPad_Pins[Loc_u8RowPin].Keypad_u64PinNum, Gpio_u8PIN_HIGH);

			}
		}
	}
	/* PRESS STATE IS PRESSING SO WHILING ON THE STATE OF THE PRESSING COLM*/
	else
	{
		/* IF THE VALUE OF THE COLM IS LOW THAT MEAN THAT THE BOTTON MAY PRESSED */
		Gpio_ReadPinValue(KeyPad_Pins[pressingColmPin_Indx].Keypad_vidPort,KeyPad_Pins[pressingColmPin_Indx].Keypad_u64PinNum,&CurState);

		/* SEQUENCE OF DEBOUNSING THE READING STATE */
		if(CurState == prevState[Loc_u8RowPin][pressingColmPin_Indx-KEYPAD_ROWDATA_SIZE])
		{
			counter[Loc_u8RowPin][pressingColmPin_Indx-KEYPAD_ROWDATA_SIZE]++;
		}
		else
		{
			counter[Loc_u8RowPin][pressingColmPin_Indx-KEYPAD_ROWDATA_SIZE] = 0;
			/* START NEW STATE CONDETION MAKING THE prevState EQULA VALUE OF REALSING */
			prevState[Loc_u8RowPin][pressingColmPin_Indx-KEYPAD_ROWDATA_SIZE] = CurState;
		}
		/* THE TASK IS COME EVERY 5ms IS THE COUNTER REACH 5 OF THE SAME STATE THAT MEAN IT DEFINITLY DOES BOUNCING */
		if(counter[Loc_u8RowPin][pressingColmPin_Indx-KEYPAD_ROWDATA_SIZE] == 5)
		{
			if(CurState == NOT_PRESS)
			{
				/*IF THE READING VALUE CHANGE THAT MEAN THAT USER RELEASE THE BOTTON SO IT READ THE PULL UP NORMAL STATE*/
				pressState = NOT_PRESS;
				/* RETURN ROW VALUE TO NORMAR 'HIGH' */
				Gpio_WritePinValue(KeyPad_Pins[pressingRowPin_Indx].Keypad_vidPort,KeyPad_Pins[pressingRowPin_Indx].Keypad_u64PinNum, Gpio_u8PIN_HIGH);

			}
		}
	}
}
