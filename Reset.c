#include <stdint.h>

/// See page 35 of the stm32 PM0056 Rev 6
///[link](https://www.st.com/resource/en/programming_manual/pm0056-stm32f10xxx20xxx21xxxl1xxxx-cortexm3-programming-manual-stmicroelectronics.pdf)

#define SRAM_START  0x20000000U
#define SRAM_HIGH_WORD  0x2000U
#define STACK_SIZE  0x5000

#define FLASH_START 0x08000000U
#define FLASH_START_HIGH 0x0800U

#define ENTRY_ADDR 0x0200U
#define VECTOR_SIZE 0x012c

#define THUMB_OFFSET 0x1

volatile uint16_t VectorTable[VECTOR_SIZE / sizeof(uint16_t)] =
{
        SRAM_HIGH_WORD, STACK_SIZE, //init stack pointer
        ENTRY_ADDR + THUMB_OFFSET, FLASH_START_HIGH,  //reset vector
};