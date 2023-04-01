/*
 * Dma.h
 *
 *  Created on: Apr 24, 2022
 *      Author: Ahmed Soliman
 */

#ifndef MCAL_DMA_H_
#define MCAL_DMA_H_

/*STREAM NUMBER */
#define DMA_Stream0	             (0)
#define DMA_Stream1	             (1)
#define DMA_Stream2	             (2)
#define DMA_Stream3	             (3)
#define DMA_Stream4	             (4)
#define DMA_Stream5	             (5)
#define DMA_Stream6	             (6)
#define DMA_Stream7	             (7)


/* CHANNEL NUMBER */
#define DMA_Channel0		             (0x0000000)
#define DMA_Channel1		             (0x0100000)
#define DMA_Channel2		             (0x0200000)
#define DMA_Channel3		             (0x0300000)
#define DMA_Channel4		             (0x0400000)
#define DMA_Channel5		             (0x0500000)
#define DMA_Channel6		             (0x0600000)
#define DMA_Channel7		             (0x0700000)

/* BURST TRANSFARE CONFIGURATION */
/*
 * These bits are protected and can be written only if EN is ‘0’
 * In direct mode, these bits are forced to 0x0 by hardware as soon as bit EN= '1'.
 */
#define DMA_SingeTransfer	   	(0x1000)
#define DMA_INCR4		        (0x1001)
#define DMA_INCR8		        (0x1002)
#define DMA_INCR16		        (0x1003)

/* DOUBLE BUFFER MODE ENABLE */
#define DMA_DoubleBuffer_Mode      (0x40000)
/*
 * When the peripheral is the flow controller (bit PFCTRL=1) and the stream is enabled (bit EN=1),
 * then this bit is automatically forced by hardware to 0.
 * It is automatically forced by hardware to 1 if the DBM bit is set, as soon as the stream is enabled (bit EN ='1').
 *
 */
#define DMA_NormalMode             (0x00000)
#define DMA_CircularMode           (0x00100)
/*
 * This bit is protected and can be written only if EN is ‘0’.
 * When the memory-to-memory mode is selected (bits DIR[1:0]=10), then this bit is automatically forced to 0 by hardware
 * The peripheral source or destination: this is the case when the number of data items to be transferred is unknown.
 */
#define DMA_PFCTRL_Mode            (0x00020)


/* PRIORITY LEVEL OPTION */
/*
 * These bits are protected and can be written only if EN is '0'
 */
#define DMA_Priority_LOW                         (0x00)
#define DMA_Priority_MEDIUM                      (0x10000)
#define DMA_Priority_HIGH                        (0x20000)
#define DMA_Priority_VHIGH                       (0x30000)


/* MEMORY DATA SIZE */
/*
 * These bits are protected and can be written only if EN is ‘0’.
 * In direct mode, MSIZE is forced by hardware to the same value as PSIZE as soon as bit EN = '1'
 *
 */
#define DMA_MSIZE_Byte                       (0x00)
#define DMA_MSIZE_HWord                      (0x2000)
#define DMA_MSIZE_Word                       (0x4000)

/* PERPHRAL SIZE */

#define DMA_PSIZE_Byte                       (0x00)
#define DMA_PSIZE_HWord                      (0x0x800)
#define DMA_PSIZE_Word                       (0x1000)

/* AUTO INCREAMENT MODE */
#define DMA_MEM_AUTOINC_EN                   (0x400)
#define DMA_PERIPH_AUTOINC_EN                (0x200)
#define DMA_AUTOINC_DISABLE                  (0x000)

/* DATA TRANSFER DIRECTION */
#define DMA_PERPH_to_MEM                     (0x00)
#define DMA_MEM_to_PERPH                     (0x40)
#define DMA_MEM_to_MEM                       (0x80)

/* INTERRUPT MODE ENABLE */
#define DMA_TC_INTREN                        (0x10)
#define DMA_HTC_INTREN                       (0x08)  // HALF TRANSMISSION COMPLETE
#define DMA_TE_INTREN                        (0x04)  // TRANSIMISSION ERROR INTERRUPT ENABLE
#define DMA_DME_INTREN                       (0x02) // DIRECT MODR ERROR





#define DMA1_BASE_ADDRESS                (0x40026000)
#define DMA2_BASE_ADDRESS                (0x40026400)

/* DEFINE THE NUMBER OF DMA */
#define DMA1                     (void * const)(DMA1_BASE_ADDRESS)
#define DMA2                     (void * const)(DMA2_BASE_ADDRESS)


typedef struct{
	void * DMA_Num;
	u32 Channel;
	u8  Stream;
	u16 MemData_Size;
	u16 PerphData_Size;
	u32 Channel_Priority;
	u8  Interrupt_Enable;
	u8  Direction;
	u16 PerphAutoInc;
	u16 MemAutoInc;
	u32 Mode;
	u32 SrcAdd;
	u32 DisAdd;
	u32 DataLength;
}Dma_cfg_t;

typedef enum{
	DMA_Error_Ok,
	DMA_Error_NOk,
}Dma_ErrorState_t;

/*
 * Initiallize DMA Mode AND INTERRUPT
 */
Dma_ErrorState_t DMA_Init(Dma_cfg_t* DmaCfg);
/*
 * SET THE ADDERESS OF THE SOURCE AND DISTANATION AND SET THE PERIORITY AND DIRECTION
 */
void DMA_Start(Dma_cfg_t* DmaCfg);

#endif /* MCAL_DMA_H_ */
