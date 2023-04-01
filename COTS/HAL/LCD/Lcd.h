/*
 * Lcd.h
 *
 *  Created on: Apr 6, 2022
 *      Author: Ahmed Soliman
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_



/* LCD COMMANDS AND MODE CONFIGURATION */
#define Lcd_u8CLRDisplay_Command                (u8)0b00000001
#define Lcd_u8RTRHome_Command                   (u8)0b00000010
#define Lcd_u8ETRYMD_DDRinc_Command             (u8)0x06
#define Lcd_u8ETRYMD_DDRdec_Command             (u8)0x04
#define Lcd_u8ETRYMD_DispSHRT_Command           (u8)0x07
#define Lcd_u8ETRYMD_DispSHLF_Command           (u8)0x05
#define Lcd_u8ETRYMD_DispSHOFF_Command          (u8)0x04
#define Lcd_u8OFFDisplay_Command                (u8)0x08
#define Lcd_u8ONDisplay_Command                 (u8)0x0C

#define Lcd_u8ONCursor_Command                  (u8)0x0A
#define Lcd_u8OFFCursor_Command                 (u8)0x08
#define Lcd_u8ONCursorBlink_Command             (u8)0x09
#define Lcd_u8OFFCursorBlink_Command            (u8)0x08

#define Lcd_u8CusorSHRT_Command                 (u8)0b00010000
#define Lcd_u8CusorSHLF_Command                 (u8)0b00010100
#define Lcd_u8CusorSHRTWthDisp_Command          (u8)0b00011000
#define Lcd_u8CusorSHLFWthDisp_Command          (u8)0b00011100
#define Lcd_u8SlkMode_8bit                      (u8)0x30
#define Lcd_u8SlkMode_4bit                      (u8)0x20
#define Lcd_u8OneLine_Mode                      (u8)0x20
#define Lcd_u8TwoLine_Mode                      (u8)0x28
#define Lcd_u8CharFont_5x7                      (u8)0x20
#define Lcd_u8CharFont_5x10                     (u8)0x24
#define Lcd_u8CLRSCR                            (u8)0b00000001
#define Lcd_u8STCGRAM__MASK                     (u8)0b01000000
#define Lcd_u8STDDRAM__MASK                     (u8)0b10000000

/*  THE OPTION OF THE POSITION TO USER */
#define Lcd_u8Row1                              (u8)5
#define Lcd_u8Row2                              (u8)6

#define Lcd_u8Clm1                              (u8)0
#define Lcd_u8Clm2                              (u8)1
#define Lcd_u8Clm3                              (u8)2
#define Lcd_u8Clm4                              (u8)3
#define Lcd_u8Clm5                              (u8)4
#define Lcd_u8Clm6                              (u8)5
#define Lcd_u8Clm7                              (u8)6
#define Lcd_u8Clm8                              (u8)7
#define Lcd_u8Clm9                              (u8)8
#define Lcd_u8Clm10                             (u8)9
#define Lcd_u8Clm11                             (u8)10
#define Lcd_u8Clm12                             (u8)11
#define Lcd_u8Clm13                             (u8)12
#define Lcd_u8Clm14                             (u8)13
#define Lcd_u8Clm15                             (u8)14
#define Lcd_u8Clm16                             (u8)15

#define TOT_LCD_PINS      7

/* THE MAX NUMBER OF CUSTOM CHAR IN SIZE 5*7 CAN STOR IN CGRAM*/
#define Lcd_u8CGRAM_MAXINDEX (u8)8


/* THE ENTIRE LCD PROCESS */
typedef enum{
	NONE,
	LCD_INIT_Process,
	LCD_WriteString_Process,
	LCD_WriteCHAR_Process,
	LCD_WriteNumber_Process,
	LCD_COMMAND_Process,
	LCD_GenCustomCHAR_Process,
}LCD_PROCESS;


typedef struct{
	u64 Lcd_u64PinNum;
	void* Lcd_vidPort;
	u8 Lcd_pinMode;
}Lcd_Pin_cfg;

/* LCD CONFIGURATION STRUCT */
typedef struct{
	u8 LCD_u8FunctionSet_cfg;
	u8 LCD_u8CursorDisplay_cfg;
	u8 LCD_u8EntryMode_cfg;
	Lcd_Pin_cfg Lcd_Pins[TOT_LCD_PINS];

}Lcd_cfg;

/* BUFFER DATA TYPE */
typedef struct{
	ps8 String;
	/* USER PUT THE NUMER OF CAHR IN THE STRING WITHOUT COUNTING THE NULL */
	u8 STRG_Size;
}buffer_t;


/*LCD PROCESS INDICATION TO IT IS STATE */
typedef enum{
	DONE_STATE,
	BUSY_STATE,
}Lcd_State;



/* LCD FUNCTIONS MOST OF THIS FUNCTION ARE ASYNCHRONOUS FUNCTION */

Lcd_State Lcd_vidInit(void);
//void Lcd_vidSendCommand(u8 Copy_u8Command);
Lcd_State Lcd_vidDisplayNumber(u32 Copy_u32NumData);
Lcd_State Lcd_vidDisplayChar(u8 Copy_u8CharData);
//void Lcd_vidCreateCustomChar(pu8 Add_u8Pattern, u8 Copy_u8CGRAM_Index);
Lcd_State Lcd_vidgoto(u8 Copy_u8LcdRow, u8 Copy_u8LcdClm);
Lcd_State Lcd_vidDisplayStringCOPY(buffer_t* Add_pbuffer);
void H_Lcd_Task(void);






#endif /* HAL_LCD_H_ */
