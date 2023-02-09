#include <stdint.h>

#define READONLY const
// CRL stands for  "Configure Register Low"
// CRH stands for  "Configure Register High"

#define GPIO_A_OFFSET_ADDR ((uint32_t) 0x40010800)
#define GPIO_B_OFFSET_ADDR ((uint32_t) 0x40010C00)
#define GPIO_C_OFFSET_ADDR ((uint32_t) 0x40011000)

#define GPIO_A_CRL_ADDR (GPIO_A_OFFSET_ADDR + 0x00)
#define GPIO_A_CRH_ADDR (GPIO_A_OFFSET_ADDR + 0x04)

#define GPIO_B_CRL_ADDR (GPIO_B_OFFSET_ADDR + 0x00)
#define GPIO_B_CRH_ADDR (GPIO_B_OFFSET_ADDR + 0x04)

#define GPIO_C_CRL_ADDR (GPIO_C_OFFSET_ADDR + 0x00)
#define GPIO_C_CRH_ADDR (GPIO_C_OFFSET_ADDR + 0x04)


#define GPIO_A_CRL ((volatile uint32_t*) GPIO_A_CRL_ADDR)[0]
#define GPIO_A_CRH ((volatile uint32_t*) GPIO_A_CRH_ADDR)[0]

#define GPIO_B_CRL ((volatile uint32_t*) GPIO_B_CRL_ADDR)[0]
#define GPIO_B_CRH ((volatile uint32_t*) GPIO_B_CRH_ADDR)[0]

#define GPIO_C_CRL ((volatile uint32_t*) GPIO_C_CRL_ADDR)[0]
#define GPIO_C_CRH ((volatile uint32_t*) GPIO_C_CRH_ADDR)[0]

// IDR stands for "Input Data Register"
// ODR stands for "Output Data Register"

#define GPIO_A_IDR_ADDR (GPIO_A_OFFSET_ADDR + 0x08)
#define GPIO_A_ODR_ADDR (GPIO_A_OFFSET_ADDR + 0x0C)

#define GPIO_B_IDR_ADDR (GPIO_B_OFFSET_ADDR + 0x08)
#define GPIO_B_ODR_ADDR (GPIO_B_OFFSET_ADDR + 0x0C)

#define GPIO_C_IDR_ADDR (GPIO_C_OFFSET_ADDR + 0x08)
#define GPIO_C_ODR_ADDR (GPIO_C_OFFSET_ADDR + 0x0C)


#define GPIO_A_IDR ((READONLY volatile uint32_t*) GPIO_A_IDR_ADDR)[0]
#define GPIO_A_ODR ((volatile uint32_t*) GPIO_A_ODR_ADDR)[0]

#define GPIO_B_IDR ((READONLY volatile uint32_t*) GPIO_B_IDR_ADDR)[0]
#define GPIO_B_ODR ((volatile uint32_t*) GPIO_B_ODR_ADDR)[0]

#define GPIO_C_IDR ((READONLY volatile uint32_t*) GPIO_C_IDR_ADDR)[0]
#define GPIO_C_ODR ((uint32_t*) GPIO_C_ODR_ADDR)[0]


/// GPIO (AFIO) configuration value
/// for make port disconnected (open drain)
/// (see page 171 of the stm32 RM0008 Rev 21)
/// [link](https://st.com/resource/en/reference_manual/cd00171190-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
#define IO_DISCONNECT_CONFIG 0x44444444


int naiveSleep(int a)
{
    int i = 10000;
    while (i > 0) {i--;}

    for (int j = 0; j < a; ++j)
    {
        if (a > 10 && (i & 1))
            a++;
    }
    return a;
}

void start(void)
{
    //Configure registers to output
    //Configure all bit as open drain (aka disconnected)
    GPIO_A_CRL = IO_DISCONNECT_CONFIG;
    GPIO_A_CRH = IO_DISCONNECT_CONFIG;

    GPIO_C_CRL = 0b0001;

    GPIO_C_CRL &= ~(0b1111 << (4 * 0)); // Erase 4 bits for configuring pin (MODE and CNF)
    GPIO_C_CRH &= ~(0b1111 << (4 * 5)); // Erase 4 bits for configuring pin (MODE and CNF)


    GPIO_C_CRL |= 0b01 << (4 * 0 + 0); // MODE to 10 MHz speed
    GPIO_C_CRL |= 0b00 << (4 * 0 + 2); // CNF to push-pull


    while (1)
    {
        naiveSleep(74);
        GPIO_C_ODR = 0b0000000000000000;
        naiveSleep(263);
        GPIO_C_ODR = 0b0010000000000000;
    }
}

