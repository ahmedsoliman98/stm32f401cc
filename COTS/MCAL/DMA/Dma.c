/*
 * Dma->c
 *
 *  Created on: Apr 24, 2022
 *      Author: Ahmed Soliman
 */

#include "../../Std_types.h"
#include "../../Bit_utils.h"
#include "Dma.h"


#define CLR_EN                ~(0x01)                     // ISW TO CLEAR THE ENABLE BIT VALUE
#define CLR_CHANNEL_VALUE     ~(DMA_Channel7)             //TO CLEAR THE 3 BITS OF THE CHANNEL FROM BITS 25-27
#define CLR_PRIORITY_VALUE    ~(DMA_Priority_VHIGH)       // TO CLEAR THE 2 BITS OF THE PRIORITY FROM BITS 16-17
#define CLR_DIRECTION_VALUE   ~(0xC0)                     // TO CLEAR THE 2 BITS OF THE DIRECTION FROM BITS 6-7
#define CLR_MEMSIZE_VLAUE     ~(0x6000)                   // TO CLEAR THE 2 BITS OF THE MEMORY SIZE FROM BITS 13-14
#define CLR_PERPHSIZE_VLAUE   ~(0x1800)                   // TO CLEAR THE 2 BITS OF THE PERIPHERAL SIZE FROM BITS 13-14
#define CLR_INTREN_VALUE      ~(0x1E)                     // TO CLEAE THE BITS OF THE ENABLE ALL INTERRUPT

/*  THIS SEQUENCE OF REGESTER IS REPEATED FOR THE 8 STREAM */
typedef struct
{
	u32 DMA_SxCR;       // CONTROL REGESTER
	u32 DMA_SxNDTR;     //SET THE COUNTER OF DATA TO BE TRASLATE
	u32 DMA_SxPAR;      // THE ADDRESS OF THE PERPHERAL
	u32 DMA_SxM0AR;     // SET THE ADDRESS OF MEMORY
	u32 DMA_SxM1AR;     // SET THE SECOUND ADDRESS OF THE MEMORY IN CASE OF DOUBLE BUFFER MODE
	u32 DMA_SxFCR;
}StreamReg;

/* DMA TOTAL REGISTER FOR ALL 8 STREAM */
typedef struct
{
	u32 DMA_LISR;      // READ THE INTERRUPT FLAGS FOR STREAM FROM 0 TO 3
	u32 DMA_HISR;      // READ THE INTERRUPT FLAGS FOR STREAM FROM 4 TO 7
	u32 DMA_LIFCR;     // CLEAR THE CORRESPONDING INTERRUPT FLAG IN ISR REGIESTER BY WRITE 1 FOR STREAM FROM 0 TO 3
	u32 DMA_HIFCR;     // CLEAR THE CORRESPONDING INTERRUPT FLAG IN ISR REGIESTER BY WRITE 1 FOR STREAM FROM 4 TO 7
	StreamReg Streams[8];
}DAM_reg_t;





/*
 * Initiallize DMA Mode AND INTERRUPT
 */
Dma_ErrorState_t DMA_Init(Dma_cfg_t* DmaCfg)
{
	Dma_ErrorState_t Loc_enuErrorState = DMA_Error_Ok;
	DAM_reg_t  *Loc_DMA_Reg = DmaCfg->DMA_Num;
	/* WRITE 0 TO EN BIT TO MAKE SURE THERE NO ONGOING OPERATION */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR &= CLR_EN;
	/* WAITE UNTILL MAKE SURE THAT EN IS 0 */
	while((Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR & 0x01) != 0);
	/* CLEAR THE STATUS REGIESTER VALUE DMA_LISR AND DMA_HISR */
	//	Loc_DMA_Reg->DMA_LIFCR = 0xff;
	//	Loc_DMA_Reg->DMA_HIFCR = 0x
	/* SET THE PERPHERAL PORT ADDRESS IN DMA_SxPAR */
	/* SET THE MEMOREY ADDRESS IN DMA_SxMA0R AND DMA_SxMA1R IN CAS OF DOUBLE BUFFER MODE */
	if(DmaCfg->Direction == DMA_PERPH_to_MEM || DmaCfg->Direction == DMA_MEM_to_MEM)
	{
		Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxPAR = DmaCfg->SrcAdd;
		Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxM0AR = DmaCfg->DisAdd;
	}
	/* MEMORY TO PERPHERAL */
	else
	{
		Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxPAR = DmaCfg->SrcAdd;
		Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxM0AR = DmaCfg->DisAdd;
	}

	/* CONFIGURE THE TOTAL NUMBER OF DATA ITME TO BE TRANSMETED */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxNDTR = DmaCfg->DataLength;
	/* SELECT THE DMA CHANNEL */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR &= CLR_CHANNEL_VALUE;    // CLEAR THE OLD CHANNEL VALUE
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->Channel;     //SET THE NEW CHANNEL VALUE
	/* SET IF THE MODE BETWEEN CYCLE AND CONTROL FLOW AND NORMAL */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->Mode;
	/* SET PRIORITY */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR &= CLR_PRIORITY_VALUE;  // CLEAR THE OLD  VALUE
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->Channel_Priority;
	/* DATA DIRECTION */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR &= ~(CLR_DIRECTION_VALUE);        // CLEAR THE OLD  VALUE
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->Direction;
	/* AUTO INCREMENT CONFIGURATION */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->MemAutoInc;
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->PerphAutoInc;
	/* DATA SIZE */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR &= CLR_MEMSIZE_VLAUE;
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR &= CLR_PERPHSIZE_VLAUE;
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->MemData_Size;
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->PerphData_Size;
	/* INTERRUPT ENABLE */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR &= CLR_INTREN_VALUE;
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= DmaCfg->Interrupt_Enable;

	return Loc_enuErrorState;
}
/*
 * SET THE ADDERESS OF THE SOURCE AND DISTANATION AND SET THE PERIORITY AND DIRECTION
 */
void DMA_Start(Dma_cfg_t* DmaCfg)
{
	DAM_reg_t  *Loc_DMA_Reg = DmaCfg->DMA_Num;
	/* SET THE ENABLE BIT TO START OPERATION OF THE DMA */
	Loc_DMA_Reg->Streams[DmaCfg->Stream].DMA_SxCR |= 0x01;
}
