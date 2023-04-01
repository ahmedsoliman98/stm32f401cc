/*
 * H_Led.h
 *
 *  Created on: Mar 24, 2022
 *      Author: Ahmed Soliman
 */

#ifndef HAL_H_LED_H_
#define HAL_H_LED_H_


#define Led_u16PortA        (u16)(0x0301)
#define Led_u16PortB        (u16)(0x0302)
#define Led_u16PortC        (u16)(0x0303)
#define Led_u16PortD        (u16)(0x0304)
#define Led_u16PortE        (u16)(0x0305)
#define Led_u16PortH        (u16)(0x0306)

#define Led_u16Pin0        (u16)(0x0200)
#define Led_u16Pin1        (u16)(0x0201)
#define Led_u16Pin2        (u16)(0x0202)
#define Led_u16Pin3        (u16)(0x0203)
#define Led_u16Pin4        (u16)(0x0204)
#define Led_u16Pin5        (u16)(0x0205)
#define Led_u16Pin6        (u16)(0x0206)
#define Led_u16Pin7        (u16)(0x0207)
#define Led_u16Pin8        (u16)(0x0208)
#define Led_u16Pin9        (u16)(0x0209)
#define Led_u16Pin10       (u16)(0x020A)
#define Led_u16Pin11       (u16)(0x020B)
#define Led_u16Pin12       (u16)(0x020C)
#define Led_u16Pin13       (u16)(0x020D)
#define Led_u16Pin14       (u16)(0x020E)
#define Led_u16Pin15       (u16)(0x020F)

#define Led_u16Active_Low    (u16)0x300
#define Led_u16Active_High   (u16)0x301

#define Led_u8OType_PP      (u8)(0x40)
#define Led_u8OType_OD      (u8)(0x41)

#define Led_u8State_ON      (0x00)
#define Led_u8State_OFF     (0x01)



/* Pin State */
/*

#define Led_u64SET_PIN0HIGH                   0x400000001
#define Led_u64SET_PIN1HIGH                   0x400000002
#define Led_u64SET_PIN2HIGH                   0x400000004
#define Led_u64SET_PIN3HIGH                   0x400000008
#define Led_u64SET_PIN4HIGH                   0x400000010
#define Led_u64SET_PIN5HIGH                   0x400000020
#define Led_u64SET_PIN6HIGH                   0x400000040
#define Led_u64SET_PIN7HIGH                   0x400000080
#define Led_u64SET_PIN8HIGH                   0x400000100
#define Led_u64SET_PIN9HIGH                   0x400000200
#define Led_u64SET_PIN10HIGH                   0x400000400
#define Led_u64SET_PIN11HIGH                   0x400000800
#define Led_u64SET_PIN12HIGH                   0x400001000
#define Led_u64SET_PIN13HIGH                   0x400002000
#define Led_u64SET_PIN14HIGH                   0x400004000
#define Led_u64SET_PIN15HIGH                   0x400008000


#define Led_u64SET_PIN0LOW                    0x400010000
#define Led_u64SET_PIN1LOW                    0x400020000
#define Led_u64SET_PIN2LOW                    0x400040000
#define Led_u64SET_PIN3LOW                    0x400080000
#define Led_u64SET_PIN4LOW                    0x400100000
#define Led_u64SET_PIN5LOW                    0x400200000
#define Led_u64SET_PIN6LOW                    0x400400000
#define Led_u64SET_PIN7LOW                    0x400800000
#define Led_u64SET_PIN8LOW                    0x401000000
#define Led_u64SET_PIN9LOW                    0x402000000
#define Led_u64SET_PIN10LOW                   0x404000000
#define Led_u64SET_PIN11LOW                   0x408000000
#define Led_u64SET_PIN12LOW                   0x410000000
#define Led_u64SET_PIN13LOW                   0x420000000
#define Led_u64SET_PIN14LOW                   0x440000000
#define Led_u64SET_PIN15LOW                   0x480000000

*/

typedef struct
{
	u16 Led_Port;
	u16 Led_Pin;
	u16 Led_ActiveState;
	u16 Led_OType;
}Led_cfg;

typedef enum
{
	Led__Ok,
	Led_Otype_Error,
	Led_Pin_Error,
	Led_Port_Error,
	Led_Type_Error,
}Led_Error_State;

/*
 * This Function used to initialized the Led by define it active state and port pin connect to it
 */
extern Led_Error_State Led_init(void);

extern Led_Error_State Led_SetState(u16 Led_Num, u8 Led_State);







#endif /* HAL_H_LED_H_ */
