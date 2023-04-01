
#ifndef _Bit_utils_H_
#define _Bit_utils_H_

#define REG_SIZE   8
#if REG_SIZE == 8
	#define BIT_SET_MASK    0xFF
	#define BIT_RESET_MASK  0x00
	#define SET_H_NIB_MASK  0xF0
	#define SET_L_NIB_MASK  0x0F
	#define RESET_H_NIB_MASK  0x0F
	#define RESET_L_NIB_MASK  0xF0
#elif REG_SIZE == 16
	#define BIT_SET_MASK    0xFFFF
	#define BIT_RESET_MASK  0x0000
	#define SET_H_NIB_MASK  0xFF00
	#define SET_L_NIB_MASK  0x00FF
	#define RESET_H_NIB_MASK  0x00FF
	#define RESET_L_NIB_MASK  0xFF00
#endif


#define SET_BIT(Reg, Bit)        (Reg |= (1 << (Bit)))
#define CLR_BIT(Reg, Bit)        (Reg &= ~(1 << (Bit)))
#define GET_BIT(Reg, Bit)        ((Reg >> Bit) & 1)
#define RSHFT_REG(Reg, No)       Reg = ((Reg) >> (No))
#define LSHFT_REG(Reg, No)       Reg = ((Reg) << (No))
#define CLSHFT_REG(Reg, No)      Reg = (Reg << (No)) | (Reg >> (REG_SIZE-(No)))
#define CRSHFT_REG(Reg, No)      Reg = (Reg>>(No)) | (Reg << (REG_SIZE-(No)))
#define ASSIGN_REG(Reg, Value)   Reg = (Value)
#define SET_REG(Reg)             Reg |= BIT_SET_MASK
#define CLR_REG(Reg)             Reg &= BIT_RESET_MASK
#define TGL_BIT(Reg,Bit)         Reg ^= (1 << Bit)
#define TGL_REG(Reg)             Reg ^= BIT_SET_MASK
#define SET_H_NIB(Reg)           Reg |= SET_H_NIB_MASK
#define SET_L_NIB(Reg)           Reg |= SET_L_NIB_MASK
#define CLR_H_NIB(Reg)           Reg &= RESET_H_NIB_MASK
#define CLR_L_NIB(Reg)           Reg &= RESET_L_NIB_MASK
#define TGL_H_NIB(Reg)           Reg ^= SET_H_NIB_MASK
#define TGL_L_NIB(Reg)           Reg ^= SET_L_NIB_MASK
#define GET_H_NIB(Reg)           (Reg>>(REG_SIZE/2))
#define GET_L_NIB(Reg)           (Reg & SET_L_NIB_MASK)
#define ASSIGN_H_NIB(Reg, Value)  Reg = (Reg & SET_L_NIB_MASK) | ((Value)<<(REG_SIZE/2))
#define ASSIGN_L_NIB(Reg, Value)  Reg = (Reg & SET_H_NIB_MASK) | (Value & (SET_L_NIB_MASK))
#define SWAP_NIB(Reg)             Reg = (Reg << (REG_SIZE/2)) | (Reg >> (REG_SIZE/2))
								
								
#endif 