/*
 * NVIC.c
 *
 *  Created on: Mar 29, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Bit_utils.h"
#include "../../Std_types.h"
#include "NVIC.h"


#define NVICREG_BASEADD         (0xE000E100)
#define AIRCR_BASEADD           (0xE000ED0C)
#define REG_NBITS               (32)
#define NVIC_PRIO_BITS          (4)


typedef struct
{
	u32 NVIC_ISER[8];
	u32 RES1[24];
	u32 NVIC_ICER[8];
	u32 RES2[24];
	u32 NVIC_ISPR[8];
	u32 RES3[24];
	u32 NVIC_ICPR[8];
	u32 RES4[24];
	u32 NVIC_IABR[8];
	u32 RES5[56];
	u8 NVIC_IPR[240];
	u32 RES6[644];
	u32 STIR;
}nvic_regs;


#define NVIC_REGS                    ((nvic_regs *)(NVICREG_BASEADD))
#define SCB_AIRCR                     (*(volatile pu32)(AIRCR_BASEADD))
#define CLR_AIRCR_BITS                (u32)(0x700)


/*Enable an external interrupt*/
void NVIC_EnableIRQ (IRQn_Type IRQn)
{
	u8 Loc_u8RegNum = IRQn/REG_NBITS;
	u8 Loc_u8BitNum = IRQn%REG_NBITS;
	(NVIC_REGS)->NVIC_ISER[Loc_u8RegNum] |= (1<<Loc_u8BitNum);
}
/*Disable an external interrupt*/
void NVIC_DisableIRQ (IRQn_Type IRQn)
{
	u8 Loc_u8RegNum = IRQn/REG_NBITS;
	u8 Loc_u8BitNum = IRQn%REG_NBITS;
	(NVIC_REGS)->NVIC_ICER[Loc_u8RegNum] |= (1<<Loc_u8BitNum);
}

/* Read The Active status */
u8 NVIC_ActiveStatus (IRQn_Type IRQn)
{
	u8 Loc_u8RegNum = IRQn/REG_NBITS;
	u8 Loc_u8BitNum = IRQn%REG_NBITS;
	u8 Loc_u8State = 0;
	Loc_u8State = (NVIC_REGS)->NVIC_IABR[Loc_u8RegNum]&(1<<Loc_u8BitNum);
	return Loc_u8State;
}

/* Set Pending by software to enable software interrupt */
void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	u8 Loc_u8RegNum = IRQn/REG_NBITS;
	u8 Loc_u8BitNum = IRQn%REG_NBITS;
	(NVIC_REGS)->NVIC_ISPR[Loc_u8RegNum] |= (1<<Loc_u8BitNum);
}

void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	u8 Loc_u8RegNum = IRQn/REG_NBITS;
	u8 Loc_u8BitNum = IRQn%REG_NBITS;
	(NVIC_REGS)->NVIC_ICPR[Loc_u8RegNum] |= (1<<Loc_u8BitNum);
}


/*Clear PRIMASK to enable interrupts*/
void __enable_irq(void)
{
	asm("CPSIE I");
}
/* Set PRIMASK to disable all interrupts*/
void __disable_irq(void)
{
	asm("CPSID I");
}


/*Set priority grouping value*/
void NVIC_SetPriorityGrouping (u32 PriorityGroup)
{
	u32 Local_u32AIRCR = SCB_AIRCR;  /* read old register configuration    */
	/*
	 * Clear the 3 bits 8-10
	 */
	Local_u32AIRCR &= ~(CLR_AIRCR_BITS);
	Local_u32AIRCR |= PriorityGroup;
	SCB_AIRCR = Local_u32AIRCR;


}

/*Generate encoded priority value based on priority grouping, group priority and sub-priority*/
u8 NVIC_EncodePriority(u32 PriorityGroup,u32 Pre_emptPriority,u32 Sub_priority)
{
	u32 PriorityGroupTmp = (PriorityGroup & 0x07);   /* GET THE FIRT 3 BIT ONLY TO LIMIT THE VALUE FROM 0-7 */
	u32 PreemptPriorityBits;
	u32 SubPriorityBits;

	/* GET THE NUMBER OF BITS THAT THE USER ASSIGN IN THE FUNCTION OF SET PERIORITY GROUPING */
	PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (u32)(NVIC_PRIO_BITS)) ? (u32)(NVIC_PRIO_BITS) : (u32)(7UL - PriorityGroupTmp);
	SubPriorityBits     = ((PriorityGroupTmp + (u32)(NVIC_PRIO_BITS)) < (u32)7UL) ? (u32)0UL : (u32)((PriorityGroupTmp - 7UL) + (u32)(NVIC_PRIO_BITS));

	return (

			/* GET FROM THE USER SEND VARIABLE THE EXACT NUMBER OF BITS SELECTED THEN SHIFT CAUSE THE IN REGISTER PER7,6|SUB4,5 BITS*/
			((Pre_emptPriority & (u8)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
			((Sub_priority     & (u8)((1UL << (SubPriorityBits    )) - 1UL)))
	);
}

/*Set the priority of an interrupt*/
void NVIC_SetPriority (IRQn_Type IRQn, u8 priority)
{
	/* WE DEVIDE IPR TO U8 240 REGISTER SO ASSIGN DIRECTLY TO THE ENUM INDEX THE VALUE THAT GET FROM THE ENCODE FUNCTION */
	(NVIC_REGS)->NVIC_IPR[IRQn] = priority<<4;
}
