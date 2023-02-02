
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#define READONLY const

/// CRL stands for  "Configure Register Low"
/// CRH stands for  "Configure Register High"

#define GPIO_A_OFFSET_ADDR 0x40010800
#define GPIO_B_OFFSET_ADDR 0x40010C00
#define GPIO_C_OFFSET_ADDR 0x40011000


#define GPIO_A_CRL_ADDR (GPIO_A_OFFSET_ADDR + 0x00)
#define GPIO_A_CRH_ADDR (GPIO_A_OFFSET_ADDR + 0x04)

#define GPIO_B_CRL_ADDR (GPIO_B_OFFSET_ADDR + 0x00)
#define GPIO_B_CRH_ADDR (GPIO_B_OFFSET_ADDR + 0x04)

#define GPIO_C_CRL_ADDR (GPIO_C_OFFSET_ADDR + 0x00)
#define GPIO_C_CRH_ADDR (GPIO_C_OFFSET_ADDR + 0x04)


#define GPIO_A_CRL ((uint32_t*) GPIO_A_CRL_ADDR)[0]
#define GPIO_A_CRH ((uint32_t*) GPIO_A_CRH_ADDR)[0]

#define GPIO_B_CRL ((uint32_t*) GPIO_B_CRL_ADDR)[0]
#define GPIO_B_CRH ((uint32_t*) GPIO_B_CRH_ADDR)[0]

#define GPIO_C_CRL ((uint32_t*) GPIO_C_CRL_ADDR)[0]
#define GPIO_C_CRH ((uint32_t*) GPIO_C_CRH_ADDR)[0]

/// IDR stands for "Input Data Register"
/// ODR stands for "Output Data Register"

#define GPIO_A_IDR_ADDR (GPIO_A_OFFSET_ADDR + 0x08)
#define GPIO_A_ODR_ADDR (GPIO_A_OFFSET_ADDR + 0x0C)

#define GPIO_B_IDR_ADDR (GPIO_B_OFFSET_ADDR + 0x08)
#define GPIO_B_ODR_ADDR (GPIO_B_OFFSET_ADDR + 0x0C)

#define GPIO_C_IDR_ADDR (GPIO_C_OFFSET_ADDR + 0x08)
#define GPIO_C_ODR_ADDR (GPIO_C_OFFSET_ADDR + 0x0C)


#define GPIO_A_IDR ((READONLY uint16_t*) GPIO_A_IDR_ADDR)[0]
#define GPIO_A_ODR ((uint16_t*) GPIO_A_ODR_ADDR)[0]

#define GPIO_B_IDR ((READONLY uint16_t*) GPIO_B_IDR_ADDR)[0]
#define GPIO_B_ODR ((uint16_t*) GPIO_B_ODR_ADDR)[0]

#define GPIO_C_IDR ((READONLY uint16_t*) GPIO_C_IDR_ADDR)[0]
#define GPIO_C_ODR ((uint16_t*) GPIO_C_ODR_ADDR)[0]


/// GPIO (AFIO) configuration value
/// for make port disconnected (open drain)
/// (see page 171 of the stm32 RM0008 Rev 21)
/// [link](https://st.com/resource/en/reference_manual/cd00171190-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
#define IO_DISCONNECT_CONFIG 0x44444444

void naiveDelay(void)
{
    unsigned int i = 0;
    while (i != 4000000) i++;
}

_Noreturn void start(void)
{
    //Configure registers to output

    //Configure all bit as open drain (aka disconnected)
//    GPIO_A_CRL = IO_DISCONNECT_CONFIG;
//    GPIO_A_CRH = IO_DISCONNECT_CONFIG;

//    GPIO_A_CRL &= ~(0b1111 << (4 * 0)); // Erase 4 bits for configuring first pin (MODE and CNF)

    GPIO_A_CRL = (IO_DISCONNECT_CONFIG & ~0b1111) | 0b11;



//    GPIO_A_CRL = 0b01 << (4 * 0 + 0); // MODE to 10 MHz speed
//    GPIO_A_CRL = 0b00 << (4 * 0 + 2); // CNF to push-pull

    while (1)
    {
        naiveDelay();
        //flip first bit
//        GPIO_A_ODR = 0b100000000000000;
    }
}