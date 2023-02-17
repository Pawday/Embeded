#include <stm32/_VectorTable.h>

#include <stdint.h>
#include <stddef.h>

#define SRAM_START  0x20000000U
#define SRAM_HIGH_WORD  0x2000U
#define STACK_SIZE  0x5000

#define FLASH_START 0x08000000U
#define FLASH_START_HIGH 0x0800U

#define ENTRY_ADDR 0x0200U
#define VECTOR_TABLE_SIZE 0x0150

int main(void);


void ResetHandler(void)
{
    int exitCode = main();

    // TODO: ask libc developers what they are doing if program exits
    if (!exitCode) HardFault();
}


/// See page 35 of the stm32 PM0056 Rev 6
///[link](https://www.st.com/resource/en/programming_manual/pm0056-stm32f10xxx20xxx21xxxl1xxxx-cortexm3-programming-manual-stmicroelectronics.pdf)

volatile size_t VectorTable[VECTOR_TABLE_SIZE / sizeof(size_t)] =
{
        SRAM_START + STACK_SIZE, // stack pointer position
        (size_t) ResetHandler,   // aka pre-main
        (size_t) NMI,            // Non Mask Interrupt
        (size_t) HardFault,
        (size_t) MemoryManagementFault,
        (size_t) BusFault,
        (size_t) UsageFault,
        /* Reserved */ 0,0,0,0,
        (size_t) SVCall,         // idn what it is, may SV -> SuperVisor
        0,                       // Reserved for debug
        0,                       // Just reserved
        (size_t) PendSV,
        (size_t) SysTick,
        (size_t) IRQ0Handler,           // IRQ0
        (size_t) IRQ1Handler,           // IRQ1
        (size_t) IRQ2Handler,           // IRQ2
        (size_t) IRQ3Handler,           // IRQ3
        (size_t) IRQ4Handler,           // IRQ4
        (size_t) IRQ5Handler,           // IRQ5
        (size_t) IRQ6Handler,           // IRQ6
        (size_t) IRQ7Handler,           // IRQ7
        (size_t) IRQ8Handler,           // IRQ8
        (size_t) IRQ9Handler,           // IRQ9
        (size_t) IRQ10Handler,          // IRQ10
        (size_t) IRQ11Handler,          // IRQ11
        (size_t) IRQ12Handler,          // IRQ12
        (size_t) IRQ13Handler,          // IRQ13
        (size_t) IRQ14Handler,          // IRQ14
        (size_t) IRQ15Handler,          // IRQ15
        (size_t) IRQ16Handler,          // IRQ16
        (size_t) IRQ17Handler,          // IRQ17
        (size_t) IRQ18Handler,          // IRQ18
        (size_t) IRQ19Handler,          // IRQ19
        (size_t) IRQ20Handler,          // IRQ20
        (size_t) IRQ21Handler,          // IRQ21
        (size_t) IRQ22Handler,          // IRQ22
        (size_t) IRQ23Handler,          // IRQ23
        (size_t) IRQ24Handler,          // IRQ24
        (size_t) IRQ25Handler,          // IRQ25
        (size_t) IRQ26Handler,          // IRQ26
        (size_t) IRQ27Handler,          // IRQ27
        (size_t) IRQ28Handler,          // IRQ28
        (size_t) IRQ29Handler,          // IRQ29
        (size_t) IRQ30Handler,          // IRQ30
        (size_t) IRQ31Handler,          // IRQ31
        (size_t) IRQ32Handler,          // IRQ32
        (size_t) IRQ33Handler,          // IRQ33
        (size_t) IRQ34Handler,          // IRQ34
        (size_t) IRQ35Handler,          // IRQ35
        (size_t) IRQ36Handler,          // IRQ36
        (size_t) IRQ37Handler,          // IRQ37
        (size_t) IRQ38Handler,          // IRQ38
        (size_t) IRQ39Handler,          // IRQ39
        (size_t) IRQ40Handler,          // IRQ40
        (size_t) IRQ41Handler,          // IRQ41
        (size_t) IRQ42Handler,          // IRQ42
        (size_t) IRQ43Handler,          // IRQ43
        (size_t) IRQ44Handler,          // IRQ44
        (size_t) IRQ45Handler,          // IRQ45
        (size_t) IRQ46Handler,          // IRQ46
        (size_t) IRQ47Handler,          // IRQ47
        (size_t) IRQ48Handler,          // IRQ48
        (size_t) IRQ49Handler,          // IRQ49
        (size_t) IRQ50Handler,          // IRQ50
        (size_t) IRQ51Handler,          // IRQ51
        (size_t) IRQ52Handler,          // IRQ52
        (size_t) IRQ53Handler,          // IRQ53
        (size_t) IRQ54Handler,          // IRQ54
        (size_t) IRQ55Handler,          // IRQ55
        (size_t) IRQ56Handler,          // IRQ56
        (size_t) IRQ57Handler,          // IRQ57
        (size_t) IRQ58Handler,          // IRQ58
        (size_t) IRQ59Handler,          // IRQ59
        (size_t) IRQ60Handler,          // IRQ60
        (size_t) IRQ61Handler,          // IRQ61
        (size_t) IRQ62Handler,          // IRQ62
        (size_t) IRQ63Handler,          // IRQ63
        (size_t) IRQ64Handler,          // IRQ64
        (size_t) IRQ65Handler,          // IRQ65
        (size_t) IRQ66Handler,          // IRQ66
        (size_t) IRQ67Handler           // IRQ67
};
