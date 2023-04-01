/*
 * Systick_cfg.h
 *
 *  Created on: Mar 27, 2022
 *      Author: Ahmed Soliman
 */

#ifndef MCAL_SYSTICK_CFG_H_
#define MCAL_SYSTICK_CFG_H_



#define STK_CLOCKSOURCE   STK_u16MPCLK_SOURCE

#define STC_EXPCONTROL     STK_EXPENABLE

/* Enter the current microprocessor clock frequency */
#define SYS_CLK_FRQMHZ        (16)


/* The clock source to the system option do not change this value*/
#define STK_u16MPCLK_SOURCE        (u16)(0x0004)
#define STK_AHBDIV8CLK_SOURCE      (u16)(0x0000)

/* The Exception Control */
#define STK_EXPENABLE              (u16)(0x8002)
#define STK_EXPDISABLE             (u16)(0x8000)








#endif /* MCAL_SYSTICK_CFG_H_ */
