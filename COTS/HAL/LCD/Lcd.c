/*
 * Lcd.c
 *
 *  Created on: Apr 6, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Bit_utils.h"
#include "../../Std_types.h"
#include "../MCAL/GPIO.h"
#include "Lcd.h"
#include "Lcd_cfg.h"





typedef enum{
	Lcd_NON_DATA,
	Lcd_UPPER_DATA,
	Lcd_LOWER_DATA
}Lcd_DataState_t;

extern Lcd_cfg LCD_SetUp_cfg;

typedef enum{
	SETUP_PIN_STATE,
	INIT_DELAY_15ms,
	LCD_FOURBIT_MODE,
	FUNCTION_SET_STATE,
	CURSOR_DISPLAY_STATE,
	CLR_DISPLAY_STATE,
	ENTRYMODE_STATE,
}InitState_t;

/* THE CONDITON OF THE STATIC PROCESS */
typedef enum{
	DONE,
	NOT_YET,
}Process_Condition_t;

/* GLOBAL VARIABLE TO INDICATE THE CURRENT LCD STATE FOR ALL FUNCTION */
static LCD_PROCESS Cur_LCD_ProcessState;

/* GLOBLA STATIC CHAR SEND FROM THE APPLICATION */
static u8 Lcd_gu8CHAR ;

/* global variable to hold the number the lcd will display */
static u32 Loc_u32ReverceNum = 1;

/*GLOBAL BUFFER VARIABLE TO HOLD A COPY FROM USER STRING */
static buffer_t String_Copy;

/* THE CGRAM BASE ADDRESS */
#define Lcd_u8CGRAMADD           (u8)0x40

/* THE ROWS BASE MAKS */
#define Lcd_u8Row1_MASK                         (u8)0b00000000
#define Lcd_u8Row2_MASK                         (u8)0b11000000


/* INITIALLIZE THE LCD PINS AND CONFIGURATION MODE */
Lcd_State Lcd_vidInit(void)
{
	Lcd_State Loc_enuLcdState = BUSY_STATE;
	if(Cur_LCD_ProcessState == NONE)
	{
		Cur_LCD_ProcessState = LCD_INIT_Process;
		Loc_enuLcdState = DONE_STATE;
	}
	return Loc_enuLcdState;
}

/* LCD WRITE A CHAR FUNCTION THIS IS ASYNCHRONOUS FUNCTION */
Lcd_State Lcd_vidDisplayChar(u8 Copy_u8CharData)
{
	Lcd_State Loc_enuLcdState = BUSY_STATE;
	if(Cur_LCD_ProcessState == NONE)
	{
		Cur_LCD_ProcessState = LCD_WriteCHAR_Process;
		Lcd_gu8CHAR = Copy_u8CharData;
		Loc_enuLcdState = DONE_STATE;
	}
	return Loc_enuLcdState;
}

/* SEND AN INSTRUCTION TO THE LCD THIS FUNCTION IS A PROCESS FUNCTION */
Process_Condition_t Lcd_vidSendCommand()
{
	Process_Condition_t Loc_enuPState = NOT_YET;
	static u8 Loc_u8EN_Value = Gpio_u8PIN_HIGH;
	static Lcd_DataState_t Loc_u8CU_Data = Lcd_NON_DATA;

	/* CHECK ON THE STATE OF THE ENABLE PIN  TO DEFINE THE NUMBER OF TIME YOU ENTER THE FUNCTION*/
	if(Loc_u8EN_Value == Gpio_u8PIN_HIGH  )
	{
		if(Loc_u8CU_Data == Lcd_NON_DATA)
		{
			/*MAKE THE OUTPUT STATE LOW ON THE PIN OF RS AND RW TO INDICATE THAT LCD SEND INSTRUCTION */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8RW_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8RW_PIN].Lcd_u64PinNum,Gpio_u8PIN_LOW);
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8RS_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8RS_PIN].Lcd_u64PinNum,Gpio_u8PIN_LOW);

			/* SET THE ENABLE PIN HIGH */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_u64PinNum,Gpio_u8PIN_HIGH);

			/*PREPARE THE NEXT STATE TO SEND THE UPPER PART OF DAT */
			Loc_u8CU_Data = Lcd_UPPER_DATA;
		}
		else if(Loc_u8CU_Data == Lcd_UPPER_DATA)
		{
			/* At The First We Send The MSB 4-bit Of The Instruction */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D4_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D4_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,4));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D5_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D5_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,5));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D6_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D6_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,6));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D7_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D7_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,7));
			/* PREPARE THE EN PIN TO RETURN TO 0 AFTER WAITE 1MS AFTER SEND DATA */
			Loc_u8EN_Value = Gpio_u8PIN_LOW;
		}
		else if (Loc_u8CU_Data == Lcd_LOWER_DATA)
		{
			/* SET THE ENABLE PIN HIGH TO PREPARE TO SEND LSB  */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_u64PinNum,Gpio_u8PIN_HIGH);

			/* CHANGE THE VALUE TO PREPARE TO RETURN EN TO LOW AFTER SEND LSB */
			Loc_u8EN_Value = Gpio_u8PIN_LOW;

		}

	}

	else if (Loc_u8EN_Value == Gpio_u8PIN_LOW)
	{
		if(Loc_u8CU_Data == Lcd_UPPER_DATA)
		{
			/* SET THE ENABLE PIN LOW AFTER SEND THE MSB */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_u64PinNum,Gpio_u8PIN_LOW);

			/* PREPARE THE VALUES TO SET THE EN HIGH AFTER 1MS */
			Loc_u8CU_Data = Lcd_LOWER_DATA;
			Loc_u8EN_Value = Gpio_u8PIN_HIGH;


		}
		else if(Loc_u8CU_Data == Lcd_LOWER_DATA)
		{
			/* At The SECOUND We Send The LSB 4-bit Of The Instruction */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D4_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D4_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,0));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D5_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D5_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,1));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D6_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D6_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,2));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D7_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D7_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,3));
			/* PREPARE THE EN PIN TO RETURN TO 0 AFTER WAITE 1MS AFTER SEND DATA */
			Loc_u8EN_Value = Gpio_u8PIN_LOW;

			/* CHANGE THE DATA CONDITION TO NON DATA INDICATE THAT WE SEND ALL INSTRUCTION AND NEED TO RETURN EN PIN TO LOW */
			Loc_u8CU_Data = Lcd_NON_DATA;
		}
		else if(Loc_u8CU_Data == Lcd_NON_DATA)
		{
			/* SET THE ENABLE PIN LOW AFTER SEND THE LSB */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_u64PinNum,Gpio_u8PIN_LOW);

			/* PREPARE THE VALUE OF THE EN PIN AND DATA STATE TO NEXT INSTRUCTION */
			Loc_u8EN_Value = Gpio_u8PIN_HIGH;
			Loc_u8CU_Data = Lcd_NON_DATA;

			/* INDICATE THAT THE FUNCTION SEND INSTRUCTION FINISH IT IS TASK */
			Loc_enuPState = DONE;
		}

	}
	return Loc_enuPState;
}

/* SEND AN DATA TO THE LCD THIS FUNCTION IS A PROCESS FUNCTION */
Process_Condition_t Lcd_vidWriteChar()
{
	Process_Condition_t Loc_enuPState = NOT_YET;
	static u8 Loc_u8EN_Value = Gpio_u8PIN_HIGH;
	static Lcd_DataState_t Loc_u8CU_Data = Lcd_NON_DATA;

	/* CHECK ON THE STATE OF THE ENABLE PIN  TO DEFINE THE NUMBER OF TIME YOU ENTER THE FUNCTION*/
	if(Loc_u8EN_Value == Gpio_u8PIN_HIGH  )
	{
		if(Loc_u8CU_Data == Lcd_NON_DATA)
		{
			/*MAKE THE OUTPUT STATE LOW ON THE PIN OF RW AND HIGH ON RS PIN TO INDICATE THAT LCD SEND DATA */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8RW_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8RW_PIN].Lcd_u64PinNum,Gpio_u8PIN_LOW);
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8RS_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8RS_PIN].Lcd_u64PinNum,Gpio_u8PIN_HIGH);

			/* SET THE ENABLE PIN HIGH */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_u64PinNum,Gpio_u8PIN_HIGH);

			/*PREPARE THE NEXT STATE TO SEND THE UPPER PART OF DAT */
			Loc_u8CU_Data = Lcd_UPPER_DATA;
		}
		else if(Loc_u8CU_Data == Lcd_UPPER_DATA)
		{
			/* At The First We Send The MSB 4-bit Of The Instruction */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D4_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D4_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,4));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D5_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D5_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,5));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D6_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D6_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,6));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D7_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D7_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,7));
			/* PREPARE THE EN PIN TO RETURN TO 0 AFTER WAITE 1MS AFTER SEND DATA */
			Loc_u8EN_Value = Gpio_u8PIN_LOW;
		}
		else if (Loc_u8CU_Data == Lcd_LOWER_DATA)
		{
			/* SET THE ENABLE PIN HIGH TO PREPARE TO SEND LSB  */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_u64PinNum,Gpio_u8PIN_HIGH);

			/* CHANGE THE VALUE TO PREPARE TO RETURN EN TO LOW AFTER SEND LSB */
			Loc_u8EN_Value = Gpio_u8PIN_LOW;

		}

	}

	else if (Loc_u8EN_Value == Gpio_u8PIN_LOW)
	{
		if(Loc_u8CU_Data == Lcd_UPPER_DATA)
		{
			/* SET THE ENABLE PIN LOW AFTER SEND THE MSB */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_u64PinNum,Gpio_u8PIN_LOW);
			/* PREPARE THE VALUES TO SET THE EN HIGH AFTER 1MS */
			Loc_u8CU_Data = Lcd_LOWER_DATA;
			Loc_u8EN_Value = Gpio_u8PIN_HIGH;


		}
		else if(Loc_u8CU_Data == Lcd_LOWER_DATA)
		{
			/* At The SECOUND We Send The LSB 4-bit Of The Instruction */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D4_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D4_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,0));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D5_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D5_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,1));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D6_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D6_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,2));
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D7_PIN].Lcd_vidPort, LCD_SetUp_cfg.Lcd_Pins[Lcd_u8D7_PIN].Lcd_u64PinNum, GET_BIT(Lcd_gu8CHAR,3));
			/* PREPARE THE EN PIN TO RETURN TO 0 AFTER WAITE 1MS AFTER SEND DATA */
			Loc_u8EN_Value = Gpio_u8PIN_LOW;

			/* CHANGE THE DATA CONDITION TO NON DATA INDICATE THAT WE SEND ALL INSTRUCTION AND NEED TO RETURN EN PIN TO LOW */
			Loc_u8CU_Data = Lcd_NON_DATA;
		}
		else if(Loc_u8CU_Data == Lcd_NON_DATA)
		{
			/* SET THE ENABLE PIN LOW AFTER SEND THE LSB */
			Gpio_WritePinValue(LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_vidPort,LCD_SetUp_cfg.Lcd_Pins[Lcd_u8EN_PIN].Lcd_u64PinNum,Gpio_u8PIN_LOW);

			/* PREPARE THE VALUE OF THE EN PIN AND DATA STATE TO NEXT INSTRUCTION */
			Loc_u8EN_Value = Gpio_u8PIN_HIGH;
			Loc_u8CU_Data = Lcd_NON_DATA;

			/* INDICATE THAT THE FUNCTION SEND INSTRUCTION FINISH IT IS TASK */
			Loc_enuPState = DONE;
		}

	}
	return Loc_enuPState;
}


static Process_Condition_t Lcd_vidWriteNumber(void)
{
	Process_Condition_t Loc_enuPState = NOT_YET;
	if(Loc_u32ReverceNum != 1)
	{
		/* AT FIRST TIME IT WILL DISPLAY THE LAST NUMBER ELEMENT IN REV VARIABLE */
		if(Lcd_vidWriteChar()== DONE)
		{
			/*THE NEXT NUMBER HOLD  IN THE GLOBAL CHAR DATA TO DISPLAY BY CHAR WRITE FUNCTION */
			Lcd_gu8CHAR = ((Loc_u32ReverceNum %10)+'0');
			Loc_u32ReverceNum /= 10;
		}

	}
	else
	{
		/* PRINT THE LAST ELEMENT IN THE NUMBER BEFORE GET DONE */
		if(Lcd_vidWriteChar()== DONE)
		{
			Loc_enuPState = DONE;
		}

	}
	return Loc_enuPState;
}

Lcd_State Lcd_vidDisplayNumber(u32 Copy_u32NumData)
{
	Lcd_State Loc_enuLcdState = BUSY_STATE;
	if(Cur_LCD_ProcessState == NONE)
	{
		/* IF THE NUMBER 432 IT WILL HOLD IN REV VARIABLE AS 1234 */
		while (Copy_u32NumData != 0)
		{
			Loc_u32ReverceNum = Loc_u32ReverceNum * 10 +((Copy_u32NumData %10));
			Copy_u32NumData /= 10;
		}
		/* HOLD THE LAST ELMENT IN REV VARIABLE IN CHAR GLOBAL TO PREPARE TO DISPLAY*/
		Lcd_gu8CHAR = ((Loc_u32ReverceNum %10)+'0');
		Loc_u32ReverceNum /= 10;
		Cur_LCD_ProcessState = LCD_WriteNumber_Process;
		Loc_enuLcdState = DONE_STATE;
	}
	return Loc_enuLcdState;
}


/* DISPLAY STRING FUNCTION */
static Process_Condition_t Lcd_vidWriteString(void)
{
	Process_Condition_t Loc_enuPState = NOT_YET;
	static u8 string_indx = 0;
	static u8 str_Copy[MAX_STRG_SIZE];
	if(string_indx < String_Copy.STRG_Size)
	{
		if(string_indx == 0)
		{
			/* AT THE FIRST TIME CALL THIS FUNCTION IT WILL COPY THE STRING IN STATIC LOCAL ARRAY */
			for(string_indx = 0; string_indx < String_Copy.STRG_Size; string_indx++)
			{
				str_Copy[string_indx] = String_Copy.String[string_indx];
			}
			string_indx =0;
		}
		/* HOLD THE CHAR FROM THE STRING INTO CHAR DISPLAY GLOBAL VARIABLE */
		Lcd_gu8CHAR = str_Copy[string_indx];
		if(Lcd_vidWriteChar() == DONE)
		{
			/* IF THE LCD DISPLAY THE CHAR SUCCESSFULLY INCREASE THE INDEX TO GET THE NEXT CHAR*/
			string_indx++;
		}
	}
	else
	{
		/* IF THE STRING_INDEX EQUAL THE STRING SIZE THAT MEAN THAT THE STRING IS FINISH */
		string_indx = 0; //TO PREPARE FOR THE NEXT STRING
		Loc_enuPState = DONE ;//THE PROCESS IS DONE
	}

	return Loc_enuPState;
}

//void Lcd_vidCreateCustomChar(pu8 Add_u8Pattern, u8 Copy_u8CGRAM_Index)
//{
//
//}

Lcd_State Lcd_vidgoto(u8 Copy_u8LcdRow, u8 Copy_u8LcdClm)
{
	Lcd_State Loc_enuLcdState = BUSY_STATE;
	u8 Lcd_AddPosition = 0;
	if(Cur_LCD_ProcessState == NONE)
	{
		switch(Copy_u8LcdRow)
		{
		case Lcd_u8Row1:
			Lcd_AddPosition = Copy_u8LcdClm | Lcd_u8Row1_MASK;
			break;
		case Lcd_u8Row2:
			Lcd_AddPosition = Copy_u8LcdClm | Lcd_u8Row2_MASK;
			break;
		}
		Cur_LCD_ProcessState = LCD_COMMAND_Process;
		Lcd_gu8CHAR = Lcd_AddPosition;
		Loc_enuLcdState = DONE_STATE;
	}
	return Loc_enuLcdState;

}

Lcd_State Lcd_vidDisplayStringCOPY(buffer_t* Add_pbuffer)
{
	Lcd_State Loc_enuLcdState = BUSY_STATE;
	if(Add_pbuffer != NULL)
	{
		if(Add_pbuffer->String != NULL)
		{
			if(Cur_LCD_ProcessState == NONE)
			{
				/* SAVE A COPY FROM THE STRING SIZE */
				String_Copy.STRG_Size = Add_pbuffer->STRG_Size;
				/* SAVE A COPY FROM THE STRING IN A GLOPAL STATIC VARIABLE */
				String_Copy.String = Add_pbuffer->String;


				/* CHANGE THE LCD STATE TO DISPLAY STRING */
				Cur_LCD_ProcessState = LCD_WriteString_Process;
			}
			Loc_enuLcdState = DONE_STATE;
		}
	}

	return Loc_enuLcdState;
}

Process_Condition_t Lcd_init_Process(void)
{
	Process_Condition_t Loc_enuPCondition = NOT_YET;
	static InitState_t Cur_initState= SETUP_PIN_STATE;
	static u8 Loc_u8idx = 0;
	Gpio_PinCfg_t Lcd_gpio_pin;

	/*SWITCH ON THE INITIALLIZATION STATE PROCESS UNTILL FINISH */
	switch(Cur_initState)
	{
	case SETUP_PIN_STATE:
		/* INITIALLIZE PIN CONFIGURATION */
		for(Loc_u8idx = 0; Loc_u8idx < TOT_LCD_PINS; Loc_u8idx++)
		{
			Lcd_gpio_pin.Gpio_PinMode = LCD_SetUp_cfg.Lcd_Pins[Loc_u8idx].Lcd_pinMode;
			Lcd_gpio_pin.Gpio_PinNumber=LCD_SetUp_cfg.Lcd_Pins[Loc_u8idx].Lcd_u64PinNum;
			Lcd_gpio_pin.Gpio_PinPort = LCD_SetUp_cfg.Lcd_Pins[Loc_u8idx].Lcd_vidPort;
			Lcd_gpio_pin.Gpio_PinSpeed = Gpio_u16SpeedCfg_HIGH;
			Gpio_initPin(&Lcd_gpio_pin);
		}
		Loc_u8idx = 0;
		Cur_initState = INIT_DELAY_15ms;
		break;
	case INIT_DELAY_15ms:
		/* WAIT 15MS AFTER SETUP THE PINS */
		Loc_u8idx++;
		if(Loc_u8idx == 50)
		{

			Cur_initState = LCD_FOURBIT_MODE;
			Lcd_gu8CHAR = 0x02;
			Loc_u8idx = 0;
		}
		break;
	case LCD_FOURBIT_MODE:
		if(Lcd_vidSendCommand() == DONE)
		{
			Lcd_gu8CHAR = LCD_SetUp_cfg.LCD_u8FunctionSet_cfg;
			Cur_initState = FUNCTION_SET_STATE;
		}

		break;
	case FUNCTION_SET_STATE:
		/* SEND FUNCTION SET COMMAND TO LCD */
		if(Lcd_vidSendCommand() == DONE)
		{
			Lcd_gu8CHAR = LCD_SetUp_cfg.LCD_u8CursorDisplay_cfg;
			Cur_initState = CURSOR_DISPLAY_STATE;
		}
		break;
	case CURSOR_DISPLAY_STATE:
		/* SEND CURSOR AND DISPLAY CONFIGURATION COMMAN TO LCD */
		if(Lcd_vidSendCommand() == DONE)
		{
			Lcd_gu8CHAR = CLR_DISPLAY_STATE ;
			Cur_initState = CLR_DISPLAY_STATE;
		}

		break;
	case CLR_DISPLAY_STATE:
		/*SEND CLEAR SCREEN COMMAND TO LCD */
		if(Lcd_vidSendCommand() == DONE)
		{
			Lcd_gu8CHAR = LCD_SetUp_cfg.LCD_u8EntryMode_cfg ;
			//Systick_SetTickTime_ms(1);
			Cur_initState = ENTRYMODE_STATE;
		}


		break;
	case ENTRYMODE_STATE:
		/*SEND ENTRY MODE COMMAND TO LCD */
		if(Lcd_vidSendCommand() == DONE)
		{
			/* RETURN INIT STATE VALUE TO SET UP PIN TO PREPARE FOR NEXT CALLING */
			Cur_initState = SETUP_PIN_STATE;

			/* AT THIS POINT THE LCD INIT SEQUENCE IS DONE */
			Loc_enuPCondition = DONE;
		}

		break;

	}
	return Loc_enuPCondition;
}

void H_Lcd_Task(void)
{
	static Process_Condition_t Loc_enuProcesState = NOT_YET;

	if(Cur_LCD_ProcessState == LCD_INIT_Process && Loc_enuProcesState == NOT_YET)
	{
		Loc_enuProcesState = Lcd_init_Process();
	}
	else if(Cur_LCD_ProcessState == LCD_WriteCHAR_Process && Loc_enuProcesState == NOT_YET)
	{
		Loc_enuProcesState = Lcd_vidWriteChar();
	}
	else if(Cur_LCD_ProcessState == LCD_WriteNumber_Process && Loc_enuProcesState == NOT_YET)
	{
		Loc_enuProcesState = Lcd_vidWriteNumber();
	}
	else if(Cur_LCD_ProcessState == LCD_WriteString_Process && Loc_enuProcesState == NOT_YET)
	{
		Loc_enuProcesState = Lcd_vidWriteString();
	}
	else if(Cur_LCD_ProcessState == LCD_COMMAND_Process && Loc_enuProcesState == NOT_YET)
	{
		Loc_enuProcesState = Lcd_vidSendCommand();
	}
	else
	{
		/* RETURN TO THE DEFAULT CONDTION OF NOT YET */
		Loc_enuProcesState = NOT_YET;
		/* INDICATE THAT THE PROCESS IS DONE */
		Cur_LCD_ProcessState = NONE;
	}
}
