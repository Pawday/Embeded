#include <stdint.h>
#include <stddef.h>

#define SRAM_START  0x20000000U
#define SRAM_HIGH_WORD  0x2000U
#define STACK_SIZE  0x5000

#define FLASH_START 0x08000000U
#define FLASH_START_HIGH 0x0800U

#define ENTRY_ADDR 0x0200U
#define VECTOR_TABLE_SIZE 0x0150

void start(void);

#define DAMMY_LOOP while(1){}

void ResetHandler(void)
{
    start();
}

void NMI(void)
{
    DAMMY_LOOP
}

void HardFault(void)
{
    DAMMY_LOOP
}

void BusFault(void)
{
    DAMMY_LOOP
}

void UsageFault(void)
{
    DAMMY_LOOP
}

void MemoryManagementFault(void)
{
    DAMMY_LOOP
}

void SVCall(void)
{
    DAMMY_LOOP
}

void InterruptDummy(void)
{
    return;
}

void PendSV(void)
{
    DAMMY_LOOP
}

void SysTick(void)
{
    DAMMY_LOOP
}

/// See page 35 of the stm32 PM0056 Rev 6
///[link](https://www.st.com/resource/en/programming_manual/pm0056-stm32f10xxx20xxx21xxxl1xxxx-cortexm3-programming-manual-stmicroelectronics.pdf)

volatile size_t VectorTable[VECTOR_TABLE_SIZE / sizeof(size_t)] =
{
        SRAM_START + STACK_SIZE, // stack pointer position
        (size_t) ResetHandler,   // aka pre-start
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
        (size_t) InterruptDummy,          // IRQ0
        (size_t) InterruptDummy,          // IRQ1
        (size_t) InterruptDummy,          // IRQ2
        (size_t) InterruptDummy,          // IRQ3
        (size_t) InterruptDummy,          // IRQ4
        (size_t) InterruptDummy,          // IRQ5
        (size_t) InterruptDummy,          // IRQ6
        (size_t) InterruptDummy,          // IRQ7
        (size_t) InterruptDummy,          // IRQ8
        (size_t) InterruptDummy,          // IRQ9
        (size_t) InterruptDummy,          // IRQ10
        (size_t) InterruptDummy,          // IRQ11
        (size_t) InterruptDummy,          // IRQ12
        (size_t) InterruptDummy,          // IRQ13
        (size_t) InterruptDummy,          // IRQ14
        (size_t) InterruptDummy,          // IRQ15
        (size_t) InterruptDummy,          // IRQ16
        (size_t) InterruptDummy,          // IRQ17
        (size_t) InterruptDummy,          // IRQ18
        (size_t) InterruptDummy,          // IRQ19
        (size_t) InterruptDummy,          // IRQ20
        (size_t) InterruptDummy,          // IRQ21
        (size_t) InterruptDummy,          // IRQ22
        (size_t) InterruptDummy,          // IRQ23
        (size_t) InterruptDummy,          // IRQ24
        (size_t) InterruptDummy,          // IRQ25
        (size_t) InterruptDummy,          // IRQ26
        (size_t) InterruptDummy,          // IRQ27
        (size_t) InterruptDummy,          // IRQ28
        (size_t) InterruptDummy,          // IRQ29
        (size_t) InterruptDummy,          // IRQ30
        (size_t) InterruptDummy,          // IRQ31
        (size_t) InterruptDummy,          // IRQ32
        (size_t) InterruptDummy,          // IRQ33
        (size_t) InterruptDummy,          // IRQ34
        (size_t) InterruptDummy,          // IRQ35
        (size_t) InterruptDummy,          // IRQ36
        (size_t) InterruptDummy,          // IRQ37
        (size_t) InterruptDummy,          // IRQ38
        (size_t) InterruptDummy,          // IRQ39
        (size_t) InterruptDummy,          // IRQ40
        (size_t) InterruptDummy,          // IRQ41
        (size_t) InterruptDummy,          // IRQ42
        (size_t) InterruptDummy,          // IRQ43
        (size_t) InterruptDummy,          // IRQ44
        (size_t) InterruptDummy,          // IRQ45
        (size_t) InterruptDummy,          // IRQ46
        (size_t) InterruptDummy,          // IRQ47
        (size_t) InterruptDummy,          // IRQ48
        (size_t) InterruptDummy,          // IRQ49
        (size_t) InterruptDummy,          // IRQ50
        (size_t) InterruptDummy,          // IRQ51
        (size_t) InterruptDummy,          // IRQ52
        (size_t) InterruptDummy,          // IRQ53
        (size_t) InterruptDummy,          // IRQ54
        (size_t) InterruptDummy,          // IRQ55
        (size_t) InterruptDummy,          // IRQ56
        (size_t) InterruptDummy,          // IRQ57
        (size_t) InterruptDummy,          // IRQ58
        (size_t) InterruptDummy,          // IRQ59
        (size_t) InterruptDummy,          // IRQ60
        (size_t) InterruptDummy,          // IRQ61
        (size_t) InterruptDummy,          // IRQ62
        (size_t) InterruptDummy,          // IRQ63
        (size_t) InterruptDummy,          // IRQ64
        (size_t) InterruptDummy,          // IRQ65
        (size_t) InterruptDummy,          // IRQ66
        (size_t) InterruptDummy           // IRQ67
};
