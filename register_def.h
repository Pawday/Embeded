#pragma once

#define READONLY const


// Apply those macros only when address is final
// otherwise address arithmetic will screw your address out
// For example:
//              (uint32_t*)(1) - ((uint32_t*) (1) - 1) != 1
//              (uint32_t*)(1) - ((uint32_t*) (1) - 1) == sizeof(uint32_t)
#define CAST_RW (volatile uint32_t*)
#define CAST_R (volatile READONLY uint32_t*)


//_____________________________________________________________
//___________________RESET, CLOCK, CONTROL_____________________
//_____________________________________________________________


#define RCC_OFFSET_ADDR 0x40021000

#define RCC_CR_ADDR (RCC_OFFSET_ADDR + 0x00)

#define RCC_CR (CAST_RW RCC_OFFSET_ADDR)[0]

#define RCC_APB2ENR_ADDR (RCC_OFFSET_ADDR + 0x18)
#define RCC_APB2ENR (CAST_RW RCC_APB2ENR_ADDR)[0]

#define IOPAEN 0b00100
#define IOPBEN 0b01000
#define IOPCEN 0b10000



//_____________________________________________________________
//_____________________GPIO REGISTERS__________________________
//_____________________________________________________________


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


#define GPIO_A_CRL (CAST_RW GPIO_A_CRL_ADDR)[0]
#define GPIO_A_CRH (CAST_RW GPIO_A_CRH_ADDR)[0]

#define GPIO_B_CRL (CAST_RW GPIO_B_CRL_ADDR)[0]
#define GPIO_B_CRH (CAST_RW GPIO_B_CRH_ADDR)[0]

#define GPIO_C_CRL (CAST_RW GPIO_C_CRL_ADDR)[0]
#define GPIO_C_CRH (CAST_RW GPIO_C_CRH_ADDR)[0]

// IDR stands for "Input Data Register"
// ODR stands for "Output Data Register"

#define GPIO_A_IDR_ADDR (GPIO_A_OFFSET_ADDR + 0x08)
#define GPIO_A_ODR_ADDR (GPIO_A_OFFSET_ADDR + 0x0C)

#define GPIO_B_IDR_ADDR (GPIO_B_OFFSET_ADDR + 0x08)
#define GPIO_B_ODR_ADDR (GPIO_B_OFFSET_ADDR + 0x0C)

#define GPIO_C_IDR_ADDR (GPIO_C_OFFSET_ADDR + 0x08)
#define GPIO_C_ODR_ADDR (GPIO_C_OFFSET_ADDR + 0x0C)


#define GPIO_A_IDR (CAST_R GPIO_A_IDR_ADDR)[0]
#define GPIO_A_ODR (CAST_RW GPIO_A_ODR_ADDR)[0]

#define GPIO_B_IDR (CAST_R GPIO_B_IDR_ADDR)[0]
#define GPIO_B_ODR (CAST_RW GPIO_B_ODR_ADDR)[0]

#define GPIO_C_IDR (CAST_R GPIO_C_IDR_ADDR)[0]
#define GPIO_C_ODR (CAST_RW GPIO_C_ODR_ADDR)[0]