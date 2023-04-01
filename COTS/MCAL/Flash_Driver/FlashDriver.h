/*
 * FlashDriver.h
 *
 *  Created on: May 9, 2022
 *      Author: Ahmed Soliman
 */

#ifndef MCAL_FLASHDRIVER_H_
#define MCAL_FLASHDRIVER_H_


/* SECTOR ERASE NUMBER */
#define SECTOR0_16KB      (0x0100)
#define SECTOR1_16KB      (0x0108)
#define SECTOR2_16KB      (0x0110)
#define SECTOR3_16KB      (0x0118)
#define SECTOR4_64KB      (0x0120)
#define SECTOR5_128KB     (0x0128)


/* FLASH DRIVER ERROR STATE INDICATOR */
typedef enum{
	FLASH_ERROR_OK,
	FLASH_ERROR_NOK,
	FLASH_ARGUMENT_ERROR,
	FLASH_NULLPTR_ERROR,
}error_t;
/* LOCKED FUNCTION THAT LOCK FLASH_CR */
void FlashDriver_Lock(void);

/* UNLOCKED FUNCTION TO UNLOSK FLASH_CR */
void FlashDriver_Unlock(void);

/* ERASE A SECTOR */
error_t FlashDriver_SectorErase(u16 SectorIndex);

/* PROGRAM PAGE ASSUME THAT ALWAYS PAGE SIZE IS 8 CAUSE WE USIG UART TO GET THE DATA*/
error_t FlashDriver_BufferProgram(Buffer_t * buff,pu32 MemAddress);


#endif /* MCAL_FLASHDRIVER_H_ */
