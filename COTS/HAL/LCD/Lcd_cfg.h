/*
 * Lcd_cfg.h
 *
 *  Created on: Apr 6, 2022
 *      Author: Ahmed Soliman
 */

#ifndef HAL_LCD_CFG_H_
#define HAL_LCD_CFG_H_


/* Operation Mode */
/* IN CASE OF SELECT THE 4BIT CONNECTION MODE */
/* Connect the Bits From 4 To 7 In The LCD To The Pins From 4 To 7 In The Micro controller  */
#define Lcd_FUNCTION_SET                      (u8)(Lcd_u8SlkMode_4bit | Lcd_u8TwoLine_Mode | Lcd_u8CharFont_5x7)

#define Lcd_CursorDisplay_Cfg                 (u8)(Lcd_u8ONDisplay_Command | Lcd_u8OFFCursor_Command | Lcd_u8OFFCursorBlink_Command)

#define Lcd_EntryMode                         (u8)(Lcd_u8ETRYMD_DDRinc_Command | Lcd_u8ETRYMD_DispSHOFF_Command)



/* MAX STRING SIZE THE LCD SHOULD DISPLAY */
#define MAX_STRG_SIZE      16

/* CONTROL PINS */
#define Lcd_u8RS_PIN     0
#define Lcd_u8RW_PIN     1
#define Lcd_u8EN_PIN     2
/* DATA PINS */
//#define Lcd_u8D0_PIN     (u8)ChID_u8PIN0
//#define Lcd_u8D1_PIN     (u8)ChID_u8PIN1
//#define Lcd_u8D2_PIN     (u8)ChID_u8PIN2
//#define Lcd_u8D3_PIN     (u8)ChID_u8PIN3
#define Lcd_u8D4_PIN     (u8)3
#define Lcd_u8D5_PIN     (u8)4
#define Lcd_u8D6_PIN     (u8)5
#define Lcd_u8D7_PIN     (u8)6





#endif /* HAL_LCD_CFG_H_ */
