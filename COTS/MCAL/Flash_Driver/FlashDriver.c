/*
 * FlashDriver.c
 *
 *  Created on: May 9, 2022
 *      Author: Ahmed Soliman
 */
#include "../../Std_types.h"
#include "../../Bit_utils.h"
#include "FlashDriver.h"

/* FLASH INTERFACE REGISTER BASE ADDRESS */
#define FLASH_INTERFACE_BASEADD      (0x40023C00)

/* KEYS WRITE ON THE FLASH_KEYR TO ALLOW ACCESS TO FLASH_CR */
#define KEY1               (0x45670123)
#define KEY2               (0xCDEF89AB)

/* SET LOCK BIT VALUE */
#define LOCK_VALUE         (0x80000000)

#define BSY_FLAG           (0x10000)
#define NO_ONGOING_OPR     (0)

/* SHIFT TO GET THE ERROR CHECK BIT */
#define SHIFTGETCHCK        (8)

/* SECTOR CHECK VALUE */
#define SECTOR_CHECKVALUE    (1)

/* CLEAR THE SECTOR BITS VALUE 3-6 BIT */
#define CLR_SECTORNUMER      (0x38)

/* SET SER BIT TO INDIACTE THAT WE ERASE A SECTOR */
#define SET_SER              (0x02)

/* SET THE START BIT IN FLASH_CR TO TRIGGER OPERATION */
#define SET_STRT             (0x10000)

/* PAGE SIZE TO PROGRAM TO BYTE BY MAKE BIT 8&9 EQUAL 00 */
#define CLR_PSIZE_BYTE       (0x300)
#define SET_PSIZE_BYTE       (0x200)

/* SET THE PG VALUE IN BIT 0*/
#define SET_PG               (0x01)

/* PAGE PRGRAM ERROR CHECK  CHECK ON ALL THE ERROR FLAGS AT TIME */
#define ERROR_CHECK_VALUE           (0x1F0)

/* FLASH DRIVER ALL REGIESTER */
typedef struct{
	volatile u32 FLASH_ACR;
	volatile u32 FLASH_KEYR;
	volatile u32 FLASH_OPTKEYR;
	volatile u32 FLASH_SR;
	volatile u32 FLASH_CR;
	volatile u32 FLASH_OPTCR;
}Flash_Reg;

/* CAST THE BASE ADDRESS TO THE PERPHERAL REGISTER STRUCT */
#define flashDriver_Regs                        ((Flash_Reg * const)(FLASH_INTERFACE_BASEADD))



/* LOCKED FUNCTION THAT LOCK FLASH_CR */
void FlashDriver_Lock(void)
{
	/* SET THE LOCK BIT IN THE FLASH_CR */
	flashDriver_Regs->FLASH_CR |=LOCK_VALUE;
}

/* UNLOCKED FUNCTION TO UNLOSK FLASH_CR */
void FlashDriver_Unlock(void)
{
	/* TO UNLOCK MUST WRITE THE RIGHT SEQUENCE BY WRITE THE KEY ONE AND IN THE NEXT INSTRUCTION WRITE KEY TW */
	flashDriver_Regs->FLASH_KEYR = KEY1;
	flashDriver_Regs->FLASH_KEYR = KEY2;
}


/* ERASE A SECTOR */
error_t FlashDriver_SectorErase(u16 SectorIndex)
{
	error_t ErrorStatus = FLASH_ERROR_OK;
	u32 Loc_u32FlashReg = flashDriver_Regs->FLASH_CR;
	if((SectorIndex >> SHIFTGETCHCK) != SECTOR_CHECKVALUE)
	{
		ErrorStatus = FLASH_ARGUMENT_ERROR;
	}
	else
	{
		/* WAIT THAT IS NO FLASH MEMORY OPERATION IS ONGOING */
		while((flashDriver_Regs->FLASH_SR & BSY_FLAG) != NO_ONGOING_OPR);
		/* SET THE SECTOR NUMBER WANT TO ERASE */
		Loc_u32FlashReg &= ~(CLR_SECTORNUMER);
		/* CAST TO U8 TO AVOID CHECK BIT VALUE */
		Loc_u32FlashReg |=  ((u8)(SectorIndex));
		/* SET THE SER BIT TO INDICAE THAT WE ERASE A FLAG */
		Loc_u32FlashReg |= SET_SER;

		flashDriver_Regs->FLASH_CR = Loc_u32FlashReg;

		/* SET THE START BIT */
		flashDriver_Regs->FLASH_CR |= SET_STRT;
		/* WAIT THAT IS NO FLASH MEMORY OPERATION IS ONGOING */
		while((flashDriver_Regs->FLASH_SR & BSY_FLAG) != NO_ONGOING_OPR);
	}
	return ErrorStatus;
}


/* PROGRAM PAGE ASSUME THAT ALWAYS PAGE SIZE IS 16*/
error_t FlashDriver_BufferProgram(Buffer_t * buff,pu32 MemAddress)
{
	error_t Loc_enuErrorStatus = FLASH_ERROR_OK;
	pu32 Add_OnPageSize = MemAddress;
	if(buff->data == NULL || MemAddress == NULL)
	{
		Loc_enuErrorStatus = FLASH_NULLPTR_ERROR;
	}
	else
	{
		/* SET THE PSIZE ALWAYS TO BE  32 BIT */
		flashDriver_Regs->FLASH_CR &= ~(CLR_PSIZE_BYTE);
		flashDriver_Regs->FLASH_CR |= SET_PSIZE_BYTE;
		/* LOOP ON THE SEQUENCE OF WRITE DATA UNTILL FINISH WHE WHOLE BUFFER */
		while(buff->used < (buff->size/4))
		{
			/* WAIT THAT IS NO FLASH MEMORY OPERATION IS ONGOING */
			while((flashDriver_Regs->FLASH_SR & BSY_FLAG) != NO_ONGOING_OPR);
			/* SET THE PG BIT TO INDICATE THAT WE PROGRAM */
			flashDriver_Regs->FLASH_CR |= (SET_PG);

			/* PERFRM THE DATA WRITE OPERATION IN MEMORY DECIRED ADDRESS */
			*Add_OnPageSize = ((pu32)buff->data)[buff->used];
			buff->used++;

			/* THE NEXT MEMORY ADDRESS MUST TO BE ALIGNED TO THE PAGE SIZE */
			Add_OnPageSize++;

			/* WAIT THAT IS NO FLASH MEMORY OPERATION IS ONGOING */
			while((flashDriver_Regs->FLASH_SR & BSY_FLAG) != NO_ONGOING_OPR);

			/* CHECK ON  THE ALL ERROR FLAG IF ANY ON OF THEM IS SET */
			if((flashDriver_Regs->FLASH_SR & ERROR_CHECK_VALUE) != 0)
			{
				Loc_enuErrorStatus = FLASH_ERROR_NOK;
				break;
			}
		}
	}

	return Loc_enuErrorStatus;
}
