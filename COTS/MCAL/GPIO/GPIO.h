/*
 * GPIO.h
 *
 *  Created on: Mar 19, 2022
 *      Author: Ahmed Soliman
 */

#ifndef GPIO_H_
#define GPIO_H_


/*Port */
#define Gpio_u16PortA  (u16)(0x0301)
#define Gpio_u16PortB  (u16)(0x0302)
#define Gpio_u16PortC  (u16)(0x0303)
#define Gpio_u16PortD  (u16)(0x0304)
#define Gpio_u16PortE  (u16)(0x0305)
#define Gpio_u16PortH  (u16)(0x0306)



/* Speed */

#define Gpio_u16SpeedCfg_LOW      (u16)(0x0100)
#define Gpio_u16SpeedCfg_MEDIUM   (u16)(0x0101)
#define Gpio_u16SpeedCfg_HIGH     (u16)(0x0102)
#define Gpio_u16SpeedCfg_VHIGH    (u16)(0x0103)


/* Pin Mode */
#define Gpio_u8PinMode_PP           (u8)(0b00100000)
#define Gpio_u8PinMode_PP_PU        (u8)(0b00100001)
#define Gpio_u8PinMode_PP_PD        (u8)(0b00100010)

#define Gpio_u8PinMode_OD           (u8)(0b00101000)
#define Gpio_u8PinMode_OD_PU        (u8)(0b00101001)
#define Gpio_u8PinMode_OD_PD        (u8)(0b00101010)

#define Gpio_u8PinMode_AFPP         (u8)(0b01000000)
#define Gpio_u8PinMode_AFPP_PU      (u8)(0b01000001)
#define Gpio_u8PinMode_AFPP_PD      (u8)(0b01000010)

#define Gpio_u8PinMode_AFOD         (u8)(0b01001000)
#define Gpio_u8PinMode_AFOD_PU      (u8)(0b01001001)
#define Gpio_u8PinMode_AFOD_PD      (u8)(0b01001010)

#define Gpio_u8PinMode_INFL         (u8)(0b00000000)
#define Gpio_u8PinMode_INPU         (u8)(0b00000001)
#define Gpio_u8PinMode_INPD         (u8)(0b00000010)

#define Gpio_PinMdeo_Analog       (u8)(0b01100000)

/* Pin Number */
#define Gpio_u16PinNumber_PIN0        (u16)(0x0200)
#define Gpio_u16PinNumber_PIN1        (u16)(0x0201)
#define Gpio_u16PinNumber_PIN2        (u16)(0x0202)
#define Gpio_u16PinNumber_PIN3        (u16)(0x0203)
#define Gpio_u16PinNumber_PIN4        (u16)(0x0204)
#define Gpio_u16PinNumber_PIN5        (u16)(0x0205)
#define Gpio_u16PinNumber_PIN6        (u16)(0x0206)
#define Gpio_u16PinNumber_PIN7        (u16)(0x0207)
#define Gpio_u16PinNumber_PIN8        (u16)(0x0208)
#define Gpio_u16PinNumber_PIN9        (u16)(0x0209)
#define Gpio_u16PinNumber_PIN10       (u16)(0x020A)
#define Gpio_u16PinNumber_PIN11       (u16)(0x020B)
#define Gpio_u16PinNumber_PIN12       (u16)(0x020C)
#define Gpio_u16PinNumber_PIN13       (u16)(0x020D)
#define Gpio_u16PinNumber_PIN14       (u16)(0x020E)
#define Gpio_u16PinNumber_PIN15       (u16)(0x020F)

/* Pin State */


#define Gpio_u64SET_PIN0HIGH                   0x400000001
#define Gpio_u64SET_PIN1HIGH                   0x400000002
#define Gpio_u64SET_PIN2HIGH                   0x400000004
#define Gpio_u64SET_PIN3HIGH                   0x400000008
#define Gpio_u64SET_PIN4HIGH                   0x400000010
#define Gpio_u64SET_PIN5HIGH                   0x400000020
#define Gpio_u64SET_PIN6HIGH                   0x400000040
#define Gpio_u64SET_PIN7HIGH                   0x400000080
#define Gpio_u64SET_PIN8HIGH                   0x400000100
#define Gpio_u64SET_PIN9HIGH                   0x400000200
#define Gpio_u64SET_PIN10HIGH                   0x400000400
#define Gpio_u64SET_PIN11HIGH                   0x400000800
#define Gpio_u64SET_PIN12HIGH                   0x400001000
#define Gpio_u64SET_PIN13HIGH                   0x400002000
#define Gpio_u64SET_PIN14HIGH                   0x400004000
#define Gpio_u64SET_PIN15HIGH                   0x400008000


#define Gpio_u64SET_PIN0LOW                    0x400010000
#define Gpio_u64SET_PIN1LOW                    0x400020000
#define Gpio_u64SET_PIN2LOW                    0x400040000
#define Gpio_u64SET_PIN3LOW                    0x400080000
#define Gpio_u64SET_PIN4LOW                    0x400100000
#define Gpio_u64SET_PIN5LOW                    0x400200000
#define Gpio_u64SET_PIN6LOW                    0x400400000
#define Gpio_u64SET_PIN7LOW                    0x400800000
#define Gpio_u64SET_PIN8LOW                    0x401000000
#define Gpio_u64SET_PIN9LOW                    0x402000000
#define Gpio_u64SET_PIN10LOW                   0x404000000
#define Gpio_u64SET_PIN11LOW                   0x408000000
#define Gpio_u64SET_PIN12LOW                   0x410000000
#define Gpio_u64SET_PIN13LOW                   0x420000000
#define Gpio_u64SET_PIN14LOW                   0x440000000
#define Gpio_u64SET_PIN15LOW                   0x480000000


typedef struct{
	u8 Gpio_PinMode;
	u16 Gpio_PinSpeed;
	u16 Gpio_PinNumber;
	u16 Gpio_PinPort;
}Gpio_PinCfg_t;



/* Error State */
typedef enum
{
	Gpio_enuOK,
	Gpio_enuPinCfgMode_Error,
	Gpio_enuPinCfgSpeed_Error,
	Gpio_enuPinCfgPinNumber_Error,
	Gpio_enuPinCfgPinPort_Error,
	Gpio_enuSetPin_State_Error,
	Gpio_enuNUL_Ptr_Error,
}Gpio_tenuErrorStatus;

Gpio_tenuErrorStatus Gpio_initPin(Gpio_PinCfg_t * Add_Gpio_Pincfg_GpioPin);
Gpio_tenuErrorStatus Gpio_SetPinValue(Gpio_PinCfg_t * Add_Gpio_Pincfg,u64 Copy_u64PinState);
Gpio_tenuErrorStatus Gpio_GetPinValue(Gpio_PinCfg_t * Add_Gpio_Pincfg,pu8 Add_u8PinState);


#endif /* GPIO_H_ */
