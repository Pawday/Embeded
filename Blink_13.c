#include "stm32_registers.h"
#include "stm32_flags.h"

/// GPIO (AFIO) configuration value
/// for make port disconnected (open drain)
/// (see page 171 of the stm32 RM0008 Rev 21)
/// [link](https://st.com/resource/en/reference_manual/cd00171190-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf)
#define IO_DISCONNECT_CONFIG 0x44444444


void naiveSleep(void)
{
    int i = 100000;
    while (i > 0) {i--;}
}

int main(void)
{

    RCC_APB2ENR |= IOPCEN;

    GPIO_C_CRH |= 0b01 << (4 * 5 + 0); // MODE to 10 MHz speed
    GPIO_C_CRH |= 0b00 << (4 * 5 + 2); // CNF to push-pull


    while (1)
    {
        naiveSleep();
        GPIO_C_ODR = 0b0000000000000000;
        naiveSleep();
        GPIO_C_ODR = 0b0010000000000000;
    }
}

