/**
  ******************************************************************************
  * @file    py32f005x6.h
  * @brief   CMSIS Cortex-M0+ Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for PY3F0xx devices.
  * @version v1.0.1
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by Puya under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */


/** @addtogroup CMSIS_Device
  * @{
  */

/** @addtogroup py32f005x6
  * @{
  */

#ifndef __PY32F005X6_H
#define __PY32F005X6_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief Configuration of the Cortex-M0+ Processor and Core Peripherals
   */
#define __CM0PLUS_REV             0 /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             0 /*!< PY32F0xx do not provide MPU                  */
#define __VTOR_PRESENT            1 /*!< Vector  Table  Register supported             */
#define __NVIC_PRIO_BITS          2 /*!< PY32F0xx uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0 /*!< Set to 1 if different SysTick Config is used  */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief PY32F0xx Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */

/*!< Interrupt Number Definition */
typedef enum
{
  /******  Cortex-M0+ Processor Exceptions Numbers *************************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                                          */
  HardFault_IRQn              = -13,    /*!< 3 Cortex-M Hard Fault Interrupt                                   */
  SVC_IRQn                    = -5,     /*!< 11 Cortex-M SV Call Interrupt                                     */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M Pend SV Interrupt                                     */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M System Tick Interrupt                                 */
  /******  PY32F0 specific Interrupt Numbers *******************************************************************/
  PVD_IRQn                    = 0,      /*!< PVD global Interrupt                                              */
  FLASH_IRQn                  = 1,      /*!< FLASH global Interrupt                                            */
  RCC_IRQn                    = 2,      /*!< RCC global Interrupt                                              */
  EXTI0_1_IRQn                = 3,      /*!< EXTI 0 and 1 Interrupts                                           */
  EXTI2_3_IRQn                = 4,      /*!< EXTI Line 2 and 3 Interrupts                                      */
  EXTI4_7_IRQn                = 5,      /*!< EXTI Line 4 to 7 Interrupts                                       */
  COMP1_IRQn                  = 6,      /*!< COMP1 Interrupt                                                   */
  COMP2_IRQn                  = 7,      /*!< COMP2 Interrupt                                                   */
  ADC1_IRQn                   = 8,     /*!< ADC1 Interrupt                                                     */
  TIM1_BRK_UP_TRG_COM_IRQn    = 9,      /*!< TIM1 Break, Update, Trigger and Commutation Interrupts            */
  TIM1_CC_IRQn                = 10,     /*!< TIM1 Capture Compare Interrupt                                    */
  LPTIM1_IRQn                 = 11,     /*!< LPTIM1 global Interrupts                                          */
  TIM14_IRQn                  = 12,     /*!< TIM14 global Interrupt                                            */
  I2C1_IRQn                   = 13,     /*!< I2C1 Interrupt  (combined with EXTI 23)                           */
  SPI1_IRQn                   = 14,     /*!< SPI1 Interrupt                                                    */
  USART1_IRQn                 = 15,     /*!< USART1 Interrupt                                                  */
  PWM1_IRQn                   = 16,     /*!< PWM1 Interrupt                                                     */
  UART1_IRQn                  = 17,     /*!< UART1 Interrupt                                                    */
  TIM13_IRQn                  = 18,     /*!< TIM13 Interrupt                                                   */
} IRQn_Type;

/**
  * @}
  */

#include "core_cm0plus.h"               /* Cortex-M0+ processor and core peripherals */
#include "system_py32f0xx.h"            /* PY32F0xx System Header */
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Analog to Digital Converter
  */
 typedef struct
 {
    __IO uint32_t ISR;              /*!< ADC ISR Register,                   Address offset: 0x00  */
    __IO uint32_t IER;              /*!< ADC IER Register,                   Address offset: 0x04  */
    __IO uint32_t CR;               /*!< ADC CR  Register,                   Address offset: 0x08  */
    __IO uint32_t CFGR1;            /*!< ADC CFGR1 Register,                 Address offset: 0x0C  */
    __IO uint32_t CFGR2;            /*!< ADC CFGR2 Register,                 Address offset: 0x10  */
    __IO uint32_t SMPR;             /*!< ADC SMPR1 Register,                 Address offset: 0x14  */
    __IO uint32_t TR;               /*!< ADC TR Register,                    Address offset: 0x18  */
    __IO uint32_t SQR1;             /*!< ADC SQR1 Register,                  Address offset: 0x1C  */
    __IO uint32_t SQR2;             /*!< ADC SQR2 Register,                  Address offset: 0x20  */
    __IO uint32_t SQR3;             /*!< ADC SQR3 Register,                  Address offset: 0x24  */
    __IO uint32_t DR1;              /*!< ADC DR2 Register,                   Address offset: 0x28  */
    __IO uint32_t DR2;              /*!< ADC DR3 Register,                   Address offset: 0x2C  */
    __IO uint32_t DR3;              /*!< ADC DR3 Register,                   Address offset: 0x30  */
    __IO uint32_t DR4;              /*!< ADC DR4 Register,                   Address offset: 0x34  */
    __IO uint32_t DR5;              /*!< ADC DR5 Register,                   Address offset: 0x38  */
    __IO uint32_t DR6;              /*!< ADC DR6 Register,                   Address offset: 0x3C  */
    __IO uint32_t DR7;              /*!< ADC DR7 Register,                   Address offset: 0x40  */
    __IO uint32_t CALFACT;          /*!< ADC CALFACT Register,               Address offset: 0x44  */
    __IO uint32_t CCR;              /*!< ADC CCR Register,                   Address offset: 0x48  */
 } ADC_TypeDef;
 
typedef struct
{
  __IO uint32_t CCR;          /*!< ADC common configuration register,             Address offset: ADC1 base address + 0x48 */
} ADC_Common_TypeDef;

/**
  * @brief CRC calculation unit
  */
typedef struct
{
  __IO uint32_t DR;             /*!< CRC Data register,                         Address offset: 0x00 */
  __IO uint32_t IDR;            /*!< CRC Independent data register,             Address offset: 0x04 */
  __IO uint32_t CR;             /*!< CRC Control register,                      Address offset: 0x08 */
} CRC_TypeDef;

/**
  * @brief Comparator
  */
typedef struct
{
  __IO uint32_t CSR;           /*!< COMP control and status register,           Address offset: 0x00 */
  __IO uint32_t FR;            /*!< COMP filter register,                       Address offset: 0x04 */
} COMP_TypeDef;

typedef struct
{
  __IO uint32_t CSR_ODD;    /*!< COMP control and status register located in register of comparator instance odd, used for bits common to several COMP instances, Address offset: 0x00 */
  __IO uint32_t FR_ODD;
  uint32_t RESERVED[2];     /*Reserved*/
  __IO uint32_t CSR_EVEN;   /*!< COMP control and status register located in register of comparator instance even, used for bits common to several COMP instances, Address offset: 0x04 */
  __IO uint32_t FR_EVEN;
} COMP_Common_TypeDef;

/**
* @brief OPA Registers
*/
typedef struct
{
   __IO uint32_t RESERVED1[12];      
   __IO uint32_t OCR;              /*!< OPA OCR Register,                   Address offset: 0x30  */
   __IO uint32_t CR;               /*!< OPA CR Register,                    Address offset: 0x34  */
} OPA_TypeDef;

/**
  * @brief Debug MCU
  */
typedef struct
{
  __IO uint32_t IDCODE;      /*!< MCU device ID code,              Address offset: 0x00 */
  __IO uint32_t CR;          /*!< Debug configuration register,    Address offset: 0x04 */
  __IO uint32_t APBFZ1;      /*!< Debug APB freeze register 1,     Address offset: 0x08 */
  __IO uint32_t APBFZ2;      /*!< Debug APB freeze register 2,     Address offset: 0x0C */
} DBGMCU_TypeDef;


/**
  * @brief Asynch Interrupt/Event Controller (EXTI)
  */
typedef struct
{
  __IO uint32_t RTSR;          /*!< EXTI Rising Trigger Selection Register 1,        Address offset:   0x00 */
  __IO uint32_t FTSR;          /*!< EXTI Falling Trigger Selection Register 1,       Address offset:   0x04 */
  __IO uint32_t SWIER;         /*!< EXTI Software Interrupt event Register 1,        Address offset:   0x08 */
  __IO uint32_t PR;            /*!< EXTI Pending Register 1                          Address offset:   0x0C */
  __IO uint32_t RESERVED1[4];  /*!< Reserved 1,                                                0x10 -- 0x1C */
  __IO uint32_t RESERVED2[5];  /*!< Reserved 2,                                                0x20 -- 0x30 */
  __IO uint32_t RESERVED3[11]; /*!< Reserved 3,                                                0x34 -- 0x5C */
  __IO uint32_t EXTICR[2];     /*!< EXTI External Interrupt Configuration Register,            0x60 -- 0x64 */
  __IO uint32_t RESERVED4[6];  /*!< Reserved 5,                                                0x68 -- 0x7C */
  __IO uint32_t IMR;           /*!< EXTI Interrupt Mask Register ,                   Address offset:   0x80 */
  __IO uint32_t EMR;           /*!< EXTI Event Mask Register ,                       Address offset:   0x84 */
} EXTI_TypeDef;

/**
* @brief VREFBUF Registers
*/
typedef struct
{
   __IO uint32_t CR;              /*!< PWR CR Register,                   Address offset: 0x00  */
} VREFBUF_TypeDef;

/**
  * @brief FLASH Registers
  */
typedef struct
{
  __IO uint32_t ACR;          /*!< FLASH Access Control register,                     Address offset: 0x00 */
  __IO uint32_t RESERVED1;    /*!< Reserved1,                                         Address offset: 0x04 */
  __IO uint32_t KEYR;         /*!< FLASH Key register,                                Address offset: 0x08 */
  __IO uint32_t OPTKEYR;      /*!< FLASH Option Key register,                         Address offset: 0x0C */
  __IO uint32_t SR;           /*!< FLASH Status register,                             Address offset: 0x10 */
  __IO uint32_t CR;           /*!< FLASH Control register,                            Address offset: 0x14 */
  __IO uint32_t RESERVED2[2]; /*!< Reserved2,                                         Address offset: 0x18-0x1C */
  __IO uint32_t OPTR;         /*!< FLASH Option register,                             Address offset: 0x20 */
  __IO uint32_t SDKR;         /*!< FLASH SDK address register,                        Address offset: 0x24 */
  __IO uint32_t BTCR;         /*!< FLASH boot control                                 Address offset: 0x28 */
  __IO uint32_t WRPR;         /*!< FLASH WRP address register,                        Address offset: 0x2C */
  __IO uint32_t RESERVED3[(0x90 - 0x2C) / 4 - 1];
  __IO uint32_t STCR;         /*!< FLASH sleep time config register,                  Address offset: 0x90 */
  __IO uint32_t RESERVED4[(0x100 - 0x90) / 4 - 1];
  __IO uint32_t TS0;          /*!< FLASH TS0 register,                                Address offset: 0x100 */
  __IO uint32_t TS1;          /*!< FLASH TS1 register,                                Address offset: 0x104 */
  __IO uint32_t TS2P;         /*!< FLASH TS2P register,                               Address offset: 0x108 */
  __IO uint32_t TPS3;         /*!< FLASH TPS3 register,                               Address offset: 0x10C */
  __IO uint32_t TS3;          /*!< FLASH TS3 register,                                Address offset: 0x110 */
  __IO uint32_t ERTPE;       /*!< FLASH ERTPE register,                             Address offset: 0x114 */
  __IO uint32_t RESERVED5;    
  __IO uint32_t PRGTPE;       /*!< FLASH PRGTPE register,                             Address offset: 0x11C */
  __IO uint32_t PRETPE;       /*!< FLASH PRETPE register,                             Address offset: 0x120 */
} FLASH_TypeDef;

/**
  * @brief Option Bytes
  */
typedef struct
{
  __IO uint8_t RDP;          /*!< Reserved,                                      Address offset: 0x00 */
  __IO uint8_t USER;         /*!< FLASH option byte user options,                Address offset: 0x01 */
  __IO uint8_t nRDP;         /*!< Reserved,                                      Address offset: 0x02 */
  __IO uint8_t nUSER;        /*!< Complemented FLASH option byte user options,   Address offset: 0x03 */
  __IO uint8_t SDK_STRT;     /*!< SDK area start address(stored in SDK[4:0]),    Address offset: 0x04 */
  __IO uint8_t SDK_END;      /*!< SDK area end address(stored in SDK[12:8]),     Address offset: 0x05 */
  __IO uint8_t nSDK_STRT;    /*!< Complemented SDK area start address,           Address offset: 0x06 */
  __IO uint8_t nSDK_END;     /*!< Complemented SDK area end address,             Address offset: 0x07 */
  __IO uint16_t BOOT;        /*!< FLASH option byte write protection,            Address offset: 0x0C */
  __IO uint16_t nBOOT;       /*!< Complemented FLASH option byte write protection,Address offset: 0x0E */
  __IO uint8_t WRP;          /*!< FLASH option byte write protection,            Address offset: 0x0C */
  __IO uint8_t Reserved1;    /*!< FLASH option byte write protection,            Address offset: 0x0C */
  __IO uint8_t nWRP;         /*!< Complemented FLASH option byte write protection,Address offset: 0x0E */
  __IO uint8_t Reserved2;    /*!< FLASH option byte write protection,            Address offset: 0x0C */
} OB_TypeDef;

/**
  * @brief General Purpose I/O
  */
typedef struct
{
  __IO uint32_t MODER;       /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;      /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;     /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;       /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;         /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;         /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;        /*!< GPIO port bit set/reset  register,     Address offset: 0x18      */
  __IO uint32_t LCKR;        /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR;         /*!< GPIO alternate function registers,     Address offset: 0x20      */
       uint32_t RESERVED1;   /*!< RESERVED1,                             Address offset: 0x24      */
  __IO uint32_t BRR;         /*!< GPIO Bit Reset register,               Address offset: 0x28      */
} GPIO_TypeDef;

/**
  * @brief Inter-integrated Circuit Interface
  */
typedef struct
{
  __IO uint32_t CR1;         /*I2C Control register1,                    Address offset: 0x00      */
  __IO uint32_t CR2;         /*I2C Control register2,                    Address offset: 0x04      */
  __IO uint32_t OAR1;        /*I2C Own address register1,                Address offset: 0x08      */
       uint32_t RESERVED1;   /*!< RESERVED1,                             Address offset: 0x0C      */
  __IO uint32_t DR;          /*I2C Data register ,                       Address offset: 0x10      */
  __IO uint32_t SR1;         /*I2C Status register1 ,                    Address offset: 0x14      */
  __IO uint32_t SR2;         /*I2C Status register2 ,                    Address offset: 0x18      */
  __IO uint32_t CCR;         /*I2C Clock control register ,              Address offset: 0x1C      */
  __IO uint32_t TRISE;       /*I2C TRISE register ,                      Address offset: 0x20      */
} I2C_TypeDef;

/**
  * @brief Independent WATCHDOG
  */
typedef struct
{
  __IO uint32_t KR;          /*!< IWDG Key register,       Address offset: 0x00 */
  __IO uint32_t PR;          /*!< IWDG Prescaler register, Address offset: 0x04 */
  __IO uint32_t RLR;         /*!< IWDG Reload register,    Address offset: 0x08 */
  __IO uint32_t SR;          /*!< IWDG Status register,    Address offset: 0x0C */
} IWDG_TypeDef;

/**
  * @brief LPTIMER
  */
typedef struct
{
  __IO uint32_t ISR;         /*!< LPTIM Interrupt and Status register,                Address offset: 0x00 */
  __IO uint32_t ICR;         /*!< LPTIM Interrupt Clear register,                     Address offset: 0x04 */
  __IO uint32_t IER;         /*!< LPTIM Interrupt Enable register,                    Address offset: 0x08 */
  __IO uint32_t CFGR;        /*!< LPTIM Configuration register,                       Address offset: 0x0C */
  __IO uint32_t CR;          /*!< LPTIM Control register,                             Address offset: 0x10 */
  __IO uint32_t RESERVED1;   /*!< RESERVED1,                                          Address offset: 0x14 */
  __IO uint32_t ARR;         /*!< LPTIM Autoreload register,                          Address offset: 0x18 */
  __IO uint32_t CNT;         /*!< LPTIM Counter register,                             Address offset: 0x1C */
} LPTIM_TypeDef;

/**
  * @brief Power Control
  */
 typedef struct
 {
    __IO uint32_t CR1;              /*!< PWR CR1 Register,                   Address offset: 0x00  */
    __IO uint32_t CR2;              /*!< PWR CR2 Register,                   Address offset: 0x04  */
    __IO uint32_t RESERVED1[3];      
    __IO uint32_t SR;               /*!< PWR SR Register,                    Address offset: 0x14  */
 } PWR_TypeDef;

/**
  * @brief Reset and Clock Control
  */
typedef struct
{
   __IO uint32_t CR;               /*!< RCC CR Register,                    Address offset: 0x00  */
   __IO uint32_t ICSCR;            /*!< RCC ICSCR Register,                 Address offset: 0x04  */
   __IO uint32_t CFGR;             /*!< RCC CFGR Register,                  Address offset: 0x08  */
   __IO uint32_t RESERVED1;         
   __IO uint32_t ECSCR;            /*!< RCC ECSCR Register,                 Address offset: 0x10  */
   __IO uint32_t RESERVED2;         
   __IO uint32_t CIER;             /*!< RCC CIER Register,                  Address offset: 0x18  */
   __IO uint32_t CIFR;             /*!< RCC CIFR Register,                  Address offset: 0x1C  */
   __IO uint32_t CICR;             /*!< RCC CICR Register,                  Address offset: 0x20  */
   __IO uint32_t IOPRSTR;          /*!< RCC IOPRSTR Register,               Address offset: 0x24  */
   __IO uint32_t AHBRSTR;          /*!< RCC AHBRSTR Register,               Address offset: 0x28  */
   __IO uint32_t APBRSTR1;         /*!< RCC APBRSTR1 Register,              Address offset: 0x2C  */
   __IO uint32_t APBRSTR2;         /*!< RCC APBRSTR2 Register,              Address offset: 0x30  */
   __IO uint32_t IOPENR;           /*!< RCC IOPENR Register,                Address offset: 0x34  */
   __IO uint32_t AHBENR;           /*!< RCC AHBENR Register,                Address offset: 0x38  */
   __IO uint32_t APBENR1;          /*!< RCC APBENR1 Register,               Address offset: 0x3C  */
   __IO uint32_t APBENR2;          /*!< RCC APBENR2 Register,               Address offset: 0x40  */
   __IO uint32_t RESERVED3[4];      
   __IO uint32_t CCIPR;            /*!< RCC CCIPR Register,                 Address offset: 0x54  */
   __IO uint32_t RESERVED4;         
   __IO uint32_t BDCR;             /*!< RCC BDCR Register,                  Address offset: 0x5C  */
   __IO uint32_t CSR;              /*!< RCC CSR Register,                   Address offset: 0x60  */
} RCC_TypeDef;

/**
  * @brief Serial Peripheral Interface
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< SPI Control register 1,                              Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< SPI Control register 2,                              Address offset: 0x04 */
  __IO uint32_t SR;          /*!< SPI Status register,                                 Address offset: 0x08 */
  __IO uint32_t DR;          /*!< SPI data register,                                   Address offset: 0x0C */
} SPI_TypeDef;

/**
  * @brief System configuration controller
  */
typedef struct
{
  __IO uint32_t CFGR1;          /*!< SYSCFG configuration register 1,                   Address offset: 0x00 */
  __IO uint32_t RESERVED1[5];   /*!< Reserved,                                          Address offset: 0x04 - 0x14 */
  __IO uint32_t CFGR2;          /*!< SYSCFG configuration register 2,                   Address offset: 0x18 */
  __IO uint32_t GPIO_ENS;       /*!< GPIO Filter Enable,                                Address offset: 0x1C */
} SYSCFG_TypeDef;

/**
  * @brief TIM
  */
typedef struct
{
  __IO uint32_t CR1;         /*!< TIM control register 1,                   Address offset: 0x00 */
  __IO uint32_t CR2;         /*!< TIM control register 2,                   Address offset: 0x04 */
  __IO uint32_t SMCR;        /*!< TIM slave mode control register,          Address offset: 0x08 */
  __IO uint32_t DIER;        /*!< TIM interrupt enable register,            Address offset: 0x0C */
  __IO uint32_t SR;          /*!< TIM status register,                      Address offset: 0x10 */
  __IO uint32_t EGR;         /*!< TIM event generation register,            Address offset: 0x14 */
  __IO uint32_t CCMR1;       /*!< TIM capture/compare mode register 1,      Address offset: 0x18 */
  __IO uint32_t CCMR2;       /*!< TIM capture/compare mode register 2,      Address offset: 0x1C */
  __IO uint32_t CCER;        /*!< TIM capture/compare enable register,      Address offset: 0x20 */
  __IO uint32_t CNT;         /*!< TIM counter register,                     Address offset: 0x24 */
  __IO uint32_t PSC;         /*!< TIM prescaler register,                   Address offset: 0x28 */
  __IO uint32_t ARR;         /*!< TIM auto-reload register,                 Address offset: 0x2C */
  __IO uint32_t RCR;         /*!< TIM repetition counter register,          Address offset: 0x30 */
  __IO uint32_t CCR1;        /*!< TIM capture/compare register 1,           Address offset: 0x34 */
  __IO uint32_t CCR2;        /*!< TIM capture/compare register 2,           Address offset: 0x38 */
  __IO uint32_t CCR3;        /*!< TIM capture/compare register 3,           Address offset: 0x3C */
  __IO uint32_t CCR4;        /*!< TIM capture/compare register 4,           Address offset: 0x40 */
  __IO uint32_t BDTR;        /*!< TIM break and dead-time register,         Address offset: 0x44 */
  __IO uint32_t RESERVED[5]; /*!< Reserved,                                 Address offset: 0x48 - 0x5D */
  __IO uint32_t TISEL;       /*!< TIM TISEL register,                       Address offset: 0x5C */
  __IO uint32_t AF1;         /*!< TIM AF1 register,                         Address offset: 0x60 */
  __IO uint32_t AF2;         /*!< TIM AF2 register,                         Address offset: 0x64 */
} TIM_TypeDef;

/**
* @brief PWM Registers
*/
typedef struct
{
   __IO uint32_t CR1;              /*!< PWM CR1 Register,                   Address offset: 0x0000  */
   __IO uint32_t RESERVED1[2];      
   __IO uint32_t DIER;             /*!< PWM DIER Register,                  Address offset: 0x000C  */
   __IO uint32_t SR;               /*!< PWM SR Register,                    Address offset: 0x0010  */
   __IO uint32_t EGR;              /*!< PWM EGR Register,                   Address offset: 0x0014  */
   __IO uint32_t CMR;              /*!< PWM CMR Register,                   Address offset: 0x0018  */
   __IO uint32_t RESERVED2;         
   __IO uint32_t CER;              /*!< PWM CER Register,                   Address offset: 0x0020  */
   __IO uint32_t CNT;              /*!< PWM CNT Register,                   Address offset: 0x0024  */
   __IO uint32_t PSC;              /*!< PWM PSC Register,                   Address offset: 0x0028  */
   __IO uint32_t ARR;              /*!< PWM ARR Register,                   Address offset: 0x002C  */
   __IO uint32_t RESERVED3;         
   __IO uint32_t CCR1;             /*!< PWM CCR1 Register,                  Address offset: 0x0034  */
} PWM_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
typedef struct
{
  __IO uint32_t SR;          /*!< USART     Status  register ,              Address offset: 0x00  */
  __IO uint32_t DR;          /*!< USART Data register,                      Address offset: 0x04  */
  __IO uint32_t BRR;         /*!< USART Baud rate register,                 Address offset: 0x08  */
  __IO uint32_t CR1;         /*!< USART     Control  register 1,            Address offset: 0x0C  */
  __IO uint32_t CR2;         /*!< USART     Control  register 2,            Address offset: 0x10  */
  __IO uint32_t CR3;         /*!< USART     Control  register 3,            Address offset: 0x14  */
} USART_TypeDef;

/**
* @brief UART Registers
*/
typedef struct
{
   __IO uint32_t DR;               /*!< UART DR Register,                   Address offset: 0x00  */
   __IO uint32_t BRR;              /*!< UART BRR Register,                  Address offset: 0x04  */
   __IO uint32_t RESERVED1[2];      
   __IO uint32_t SR;               /*!< UART SR Register,                   Address offset: 0x10  */
   __IO uint32_t CR1;              /*!< UART CR1 Register,                  Address offset: 0x14  */
   __IO uint32_t CR2;              /*!< UART CR2 Register,                  Address offset: 0x18  */
   __IO uint32_t CR3;              /*!< UART CR3 Register,                  Address offset: 0x1C  */
   __IO uint32_t RAR;              /*!< UART RAR Register,                  Address offset: 0x20  */
   __IO uint32_t TAR;              /*!< UART TAR Register,                  Address offset: 0x24  */
   __IO uint32_t BRRF;             /*!< UART BRRF Register,                 Address offset: 0x28  */
} UART_TypeDef;

/** @addtogroup Peripheral_memory_map
  * @{
  */
#define FLASH_BASE            (0x08000000UL)  /*!< FLASH base address */
#define FLASH_END             (0x08007FFFUL)  /*!< FLASH end address */
#define FLASH_SIZE            (FLASH_END - FLASH_BASE + 1)
#define FLASH_PAGE_SIZE       0x00000080U     /*!< FLASH Page Size, 128 Bytes */
#define FLASH_PAGE_NB         (FLASH_SIZE / FLASH_PAGE_SIZE)
#define FLASH_SECTOR_SIZE     0x00001000U     /*!< FLASH Sector Size, 4096 Bytes */
#define FLASH_SECTOR_NB       (FLASH_SIZE / FLASH_SECTOR_SIZE)
#define SRAM_BASE             (0x20000000UL)  /*!< SRAM base address */
#define SRAM_END              (0x20000BFFUL)  /*!< SRAM end address */
#define PERIPH_BASE           (0x40000000UL)  /*!< Peripheral base address */
#define IOPORT_BASE           (0x50000000UL)  /*!< IOPORT base address */

/*!< Peripheral memory map */
#define APBPERIPH_BASE        (PERIPH_BASE)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)

/*!< APB peripherals */
#define TIM14_BASE            (APBPERIPH_BASE + 0x00002000UL)
#define TIM13_BASE            (APBPERIPH_BASE + 0x00002400UL)
#define PWM1_BASE             (APBPERIPH_BASE + 0x00002800UL)
#define IWDG_BASE             (APBPERIPH_BASE + 0x00003000UL)
#define UART1_BASE            (APBPERIPH_BASE + 0x00004800UL)
#define I2C1_BASE             (APBPERIPH_BASE + 0x00005400UL)
#define PWR_BASE              (APBPERIPH_BASE + 0x00007000UL)
#define LPTIM1_BASE           (APBPERIPH_BASE + 0x00007C00UL)
#define SYSCFG_BASE           (APBPERIPH_BASE + 0x00010000UL)
#define VREFBUF_BASE          (APBPERIPH_BASE + 0x00010100UL)
#define COMP1_BASE            (APBPERIPH_BASE + 0x00010200UL)
#define COMP2_BASE            (APBPERIPH_BASE + 0x00010210UL)
#define OPA1_BASE             (APBPERIPH_BASE + 0x00010300UL)
#define ADC1_BASE             (APBPERIPH_BASE + 0x00012400UL)
#define ADC_COMMON_BASE       (ADC1_BASE      + 0x00000048UL)
#define TIM1_BASE             (APBPERIPH_BASE + 0x00012C00UL)
#define SPI1_BASE             (APBPERIPH_BASE + 0x00013000UL)
#define USART1_BASE           (APBPERIPH_BASE + 0x00013800UL)
#define DBGMCU_BASE           (APBPERIPH_BASE + 0x00015800UL)

/*!< AHB peripherals */
#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000UL)
#define EXTI_BASE             (AHBPERIPH_BASE + 0x00001800UL)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x00002000UL) /*!< FLASH registers base address */
#define CRC_BASE              (AHBPERIPH_BASE + 0x00003000UL)
#define OB_BASE               (0x1FFF0080UL)                  /*!< FLASH Option Bytes base address */
#define FLASHSIZE_BASE        (0x1FFF01FCUL)                  /*!< FLASH Size register base address */
#define UID_BASE              (0x1FFF0000UL)                  /*!< Unique device ID register base address */
#define OTP_BASE              (0x1FFF0280UL)

/*!< IOPORT */
#define GPIOA_BASE            (IOPORT_BASE + 0x00000000UL)
#define GPIOB_BASE            (IOPORT_BASE + 0x00000400UL)
#define GPIOC_BASE            (IOPORT_BASE + 0x00000800UL)
#define GPIOD_BASE            (IOPORT_BASE + 0x00000C00UL)

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */
#define TIM14               ((TIM_TypeDef *) TIM14_BASE)
#define TIM13               ((TIM_TypeDef *) TIM13_BASE)
#define PWM1                ((PWM_TypeDef *) PWM1_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define UART1               ((UART_TypeDef *) UART1_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define LPTIM1              ((LPTIM_TypeDef *) LPTIM1_BASE)
#define LPTIM               ((LPTIM_TypeDef *) LPTIM1_BASE)
#define SYSCFG              ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define VREFBUF             ((VREFBUF_TypeDef *) VREFBUF_BASE)
#define COMP1               ((COMP_TypeDef *) COMP1_BASE)
#define COMP2               ((COMP_TypeDef *) COMP2_BASE)
#define COMP12_COMMON       ((COMP_Common_TypeDef *) COMP1_BASE)
#define OPA1                ((OPA_TypeDef *) OPA1_BASE)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC1_COMMON         ((ADC_Common_TypeDef *) ADC_COMMON_BASE)
#define ADC                 ((ADC_TypeDef *) ADC1_BASE) /* Kept for legacy purpose */
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define OB                  ((OB_TypeDef *) OB_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
* @{
*/

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/

/********************************************************************************************************************/
/********************************* ADC ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for ADC_ISR register **********************************************/                            
#define ADC_ISR_EOSMP_Pos                         (1U)
#define ADC_ISR_EOSMP_Msk                         (0x1UL<<ADC_ISR_EOSMP_Pos)                        /*!< 0x00000002 */
#define ADC_ISR_EOSMP                             ADC_ISR_EOSMP_Msk                                 
#define ADC_ISR_EOC_Pos                           (2U)
#define ADC_ISR_EOC_Msk                           (0x1UL<<ADC_ISR_EOC_Pos)                          /*!< 0x00000004 */
#define ADC_ISR_EOC                               ADC_ISR_EOC_Msk                                   
#define ADC_ISR_EOSEQ_Pos                         (3U)
#define ADC_ISR_EOSEQ_Msk                         (0x1UL<<ADC_ISR_EOSEQ_Pos)                        /*!< 0x00000008 */
#define ADC_ISR_EOSEQ                             ADC_ISR_EOSEQ_Msk                                 
#define ADC_ISR_OVR_Pos                           (4U)
#define ADC_ISR_OVR_Msk                           (0x1UL<<ADC_ISR_OVR_Pos)                          /*!< 0x00000010 */
#define ADC_ISR_OVR                               ADC_ISR_OVR_Msk                                   
#define ADC_ISR_AWD_Pos                           (7U)
#define ADC_ISR_AWD_Msk                           (0x1UL<<ADC_ISR_AWD_Pos)                          /*!< 0x00000080 */
#define ADC_ISR_AWD                               ADC_ISR_AWD_Msk                                   
#define ADC_ISR_EOH_Pos                           (8U)
#define ADC_ISR_EOH_Msk                           (0x1UL<<ADC_ISR_EOH_Pos)                          /*!< 0x00000100 */
#define ADC_ISR_EOH                               ADC_ISR_EOH_Msk                                   


/********************************* Bit definition for ADC_IER register **********************************************/                            
#define ADC_IER_EOSMPIE_Pos                       (1U)
#define ADC_IER_EOSMPIE_Msk                       (0x1UL<<ADC_IER_EOSMPIE_Pos)                      /*!< 0x00000002 */
#define ADC_IER_EOSMPIE                           ADC_IER_EOSMPIE_Msk                               
#define ADC_IER_EOCIE_Pos                         (2U)
#define ADC_IER_EOCIE_Msk                         (0x1UL<<ADC_IER_EOCIE_Pos)                        /*!< 0x00000004 */
#define ADC_IER_EOCIE                             ADC_IER_EOCIE_Msk                                 
#define ADC_IER_EOSEQIE_Pos                       (3U)
#define ADC_IER_EOSEQIE_Msk                       (0x1UL<<ADC_IER_EOSEQIE_Pos)                      /*!< 0x00000008 */
#define ADC_IER_EOSEQIE                           ADC_IER_EOSEQIE_Msk                               
#define ADC_IER_OVRIE_Pos                         (4U)
#define ADC_IER_OVRIE_Msk                         (0x1UL<<ADC_IER_OVRIE_Pos)                        /*!< 0x00000010 */
#define ADC_IER_OVRIE                             ADC_IER_OVRIE_Msk                                 
#define ADC_IER_AWDIE_Pos                         (7U)
#define ADC_IER_AWDIE_Msk                         (0x1UL<<ADC_IER_AWDIE_Pos)                        /*!< 0x00000080 */
#define ADC_IER_AWDIE                             ADC_IER_AWDIE_Msk   
#define ADC_IER_EOHIE_Pos                         (8U)
#define ADC_IER_EOHIE_Msk                         (0x1UL<<ADC_IER_EOHIE_Pos)                        /*!< 0x00000100 */
#define ADC_IER_EOHIE                             ADC_IER_EOHIE_Msk                                 


/********************************* Bit definition for ADC_CR register ***********************************************/
#define ADC_CR_ADEN_Pos                           (0U)
#define ADC_CR_ADEN_Msk                           (0x1UL<<ADC_CR_ADEN_Pos)                          /*!< 0x00000001 */
#define ADC_CR_ADEN                               ADC_CR_ADEN_Msk                                   
#define ADC_CR_ADDIS_Pos                          (1U)
#define ADC_CR_ADDIS_Msk                          (0x1UL<<ADC_CR_ADDIS_Pos)                         /*!< 0x00000002 */
#define ADC_CR_ADDIS                              ADC_CR_ADDIS_Msk                                  
#define ADC_CR_ADSTART_Pos                        (2U)
#define ADC_CR_ADSTART_Msk                        (0x1UL<<ADC_CR_ADSTART_Pos)                       /*!< 0x00000004 */
#define ADC_CR_ADSTART                            ADC_CR_ADSTART_Msk                                
#define ADC_CR_ADSTP_Pos                          (4U)
#define ADC_CR_ADSTP_Msk                          (0x1UL<<ADC_CR_ADSTP_Pos)                         /*!< 0x00000010 */
#define ADC_CR_ADSTP                              ADC_CR_ADSTP_Msk                                  
#define ADC_CR_RSTCAL_Pos                         (29U)
#define ADC_CR_RSTCAL_Msk                         (0x1UL<<ADC_CR_RSTCAL_Pos)                        /*!< 0x20000000 */
#define ADC_CR_RSTCAL                             ADC_CR_RSTCAL_Msk                                 
#define ADC_CR_ADCAL_START_Pos                    (30U)
#define ADC_CR_ADCAL_START_Msk                    (0x1UL<<ADC_CR_ADCAL_START_Pos)                   /*!< 0x40000000 */
#define ADC_CR_ADCAL_START                        ADC_CR_ADCAL_START_Msk                            
#define ADC_CR_ADCAL_Pos                          (31U)
#define ADC_CR_ADCAL_Msk                          (0x1UL<<ADC_CR_ADCAL_Pos)                         /*!< 0x80000000 */
#define ADC_CR_ADCAL                              ADC_CR_ADCAL_Msk                                  

/********************************* Bit definition for ADC_CFGR register *********************************************/
#define ADC_CFGR1_RESSEL_Pos                      (3U)
#define ADC_CFGR1_RESSEL_Msk                      (0x3UL<<ADC_CFGR1_RESSEL_Pos)                      /*!< 0x00000018 */
#define ADC_CFGR1_RESSEL                          ADC_CFGR1_RESSEL_Msk
#define ADC_CFGR1_RESSEL_0                        (0x1UL<<ADC_CFGR1_RESSEL_Pos)                      /*!< 0x00000008 */
#define ADC_CFGR1_RESSEL_1                        (0x2UL<<ADC_CFGR1_RESSEL_Pos)                      /*!< 0x00000010 */
#define ADC_CFGR1_ALIGN_Pos                       (5U)
#define ADC_CFGR1_ALIGN_Msk                       (0x1UL<<ADC_CFGR1_ALIGN_Pos)                       /*!< 0x00000020 */
#define ADC_CFGR1_ALIGN                           ADC_CFGR1_ALIGN_Msk                                
#define ADC_CFGR1_EXTSEL_Pos                      (6U)
#define ADC_CFGR1_EXTSEL_Msk                      (0x7UL<<ADC_CFGR1_EXTSEL_Pos)                      /*!< 0x000001C0 */
#define ADC_CFGR1_EXTSEL                          ADC_CFGR1_EXTSEL_Msk
#define ADC_CFGR1_EXTSEL_0                        (0x1UL<<ADC_CFGR1_EXTSEL_Pos)                      /*!< 0x00000040 */
#define ADC_CFGR1_EXTSEL_1                        (0x2UL<<ADC_CFGR1_EXTSEL_Pos)                      /*!< 0x00000080 */
#define ADC_CFGR1_EXTSEL_2                        (0x4UL<<ADC_CFGR1_EXTSEL_Pos)                      /*!< 0x00000100 */
#define ADC_CFGR1_EXTEN_Pos                       (10U)
#define ADC_CFGR1_EXTEN_Msk                       (0x3UL<<ADC_CFGR1_EXTEN_Pos)                       /*!< 0x00000C00 */
#define ADC_CFGR1_EXTEN                           ADC_CFGR1_EXTEN_Msk
#define ADC_CFGR1_EXTEN_0                         (0x1UL<<ADC_CFGR1_EXTEN_Pos)                       /*!< 0x00000400 */
#define ADC_CFGR1_EXTEN_1                         (0x2UL<<ADC_CFGR1_EXTEN_Pos)                       /*!< 0x00000800 */
#define ADC_CFGR1_OVRMOD_Pos                      (12U)
#define ADC_CFGR1_OVRMOD_Msk                      (0x1UL<<ADC_CFGR1_OVRMOD_Pos)                      /*!< 0x00001000 */
#define ADC_CFGR1_OVRMOD                          ADC_CFGR1_OVRMOD_Msk                               
#define ADC_CFGR1_CONT_Pos                        (13U)
#define ADC_CFGR1_CONT_Msk                        (0x1UL<<ADC_CFGR1_CONT_Pos)                        /*!< 0x00002000 */
#define ADC_CFGR1_CONT                            ADC_CFGR1_CONT_Msk                                 
#define ADC_CFGR1_WAIT_Pos                        (14U)
#define ADC_CFGR1_WAIT_Msk                        (0x1UL<<ADC_CFGR1_WAIT_Pos)                        /*!< 0x00004000 */
#define ADC_CFGR1_WAIT                            ADC_CFGR1_WAIT_Msk                                 
#define ADC_CFGR1_DISCEN_Pos                      (16U)
#define ADC_CFGR1_DISCEN_Msk                      (0x1UL<<ADC_CFGR1_DISCEN_Pos)                      /*!< 0x00010000 */
#define ADC_CFGR1_DISCEN                          ADC_CFGR1_DISCEN_Msk      
#define ADC_CFGR1_CALNUM_Pos                      (17U)
#define ADC_CFGR1_CALNUM_Msk                      (0x7UL<<ADC_CFGR1_CALNUM_Pos)                      /*!< 0x3C000000 */
#define ADC_CFGR1_CALNUM                          ADC_CFGR1_CALNUM_Msk
#define ADC_CFGR1_CALNUM_0                        (0x1UL<<ADC_CFGR1_CALNUM_Pos)                      /*!< 0x04000000 */
#define ADC_CFGR1_CALNUM_1                        (0x2UL<<ADC_CFGR1_CALNUM_Pos)                      /*!< 0x08000000 */
#define ADC_CFGR1_CALNUM_2                        (0x4UL<<ADC_CFGR1_CALNUM_Pos)                      /*!< 0x10000000 */
#define ADC_CFGR1_AWDSGL_Pos                      (22U)
#define ADC_CFGR1_AWDSGL_Msk                      (0x1UL<<ADC_CFGR1_AWDSGL_Pos)                      /*!< 0x00400000 */
#define ADC_CFGR1_AWDSGL                          ADC_CFGR1_AWDSGL_Msk                               
#define ADC_CFGR1_AWDEN_Pos                       (23U)
#define ADC_CFGR1_AWDEN_Msk                       (0x1UL<<ADC_CFGR1_AWDEN_Pos)                       /*!< 0x00800000 */
#define ADC_CFGR1_AWDEN                           ADC_CFGR1_AWDEN_Msk                                
#define ADC_CFGR1_AWDCH_Pos                       (26U)
#define ADC_CFGR1_AWDCH_Msk                       (0xFUL<<ADC_CFGR1_AWDCH_Pos)                       /*!< 0x3C000000 */
#define ADC_CFGR1_AWDCH                           ADC_CFGR1_AWDCH_Msk
#define ADC_CFGR1_AWDCH_0                         (0x1UL<<ADC_CFGR1_AWDCH_Pos)                       /*!< 0x04000000 */
#define ADC_CFGR1_AWDCH_1                         (0x2UL<<ADC_CFGR1_AWDCH_Pos)                       /*!< 0x08000000 */
#define ADC_CFGR1_AWDCH_2                         (0x4UL<<ADC_CFGR1_AWDCH_Pos)                       /*!< 0x10000000 */
#define ADC_CFGR1_AWDCH_3                         (0x8UL<<ADC_CFGR1_AWDCH_Pos)                       /*!< 0x20000000 */

/********************************* Bit definition for ADC_CFGR2 register ********************************************/
#define ADC_CFGR2_CKMODE_Pos                      (28U)
#define ADC_CFGR2_CKMODE_Msk                      (0xFUL<<ADC_CFGR2_CKMODE_Pos)                     /*!< 0xF0000000 */
#define ADC_CFGR2_CKMODE                          ADC_CFGR2_CKMODE_Msk
#define ADC_CFGR2_CKMODE_0                        (0x1UL<<ADC_CFGR2_CKMODE_Pos)                     /*!< 0x10000000 */
#define ADC_CFGR2_CKMODE_1                        (0x2UL<<ADC_CFGR2_CKMODE_Pos)                     /*!< 0x20000000 */
#define ADC_CFGR2_CKMODE_2                        (0x4UL<<ADC_CFGR2_CKMODE_Pos)                     /*!< 0x40000000 */
#define ADC_CFGR2_CKMODE_3                        (0x8UL<<ADC_CFGR2_CKMODE_Pos)                     /*!< 0x80000000 */

/********************************* Bit definition for ADC_SMPR register *********************************************/
#define ADC_SMPR_SMP_Pos                          (0U)
#define ADC_SMPR_SMP_Msk                          (0x7UL<<ADC_SMPR_SMP_Pos)                         /*!< 0x00000007 */
#define ADC_SMPR_SMP                              ADC_SMPR_SMP_Msk
#define ADC_SMPR_SMP_0                            (0x1UL<<ADC_SMPR_SMP_Pos)                         /*!< 0x00000001 */
#define ADC_SMPR_SMP_1                            (0x2UL<<ADC_SMPR_SMP_Pos)                         /*!< 0x00000002 */
#define ADC_SMPR_SMP_2                            (0x4UL<<ADC_SMPR_SMP_Pos)                         /*!< 0x00000004 */

/********************************* Bit definition for ADC_TR register ***********************************************/
#define ADC_TR_LT_Pos                             (0U)
#define ADC_TR_LT_Msk                             (0xFFFUL<<ADC_TR_LT_Pos)                          /*!< 0x00000FFF */
#define ADC_TR_LT                                 ADC_TR_LT_Msk
#define ADC_TR_HT_Pos                             (16U)
#define ADC_TR_HT_Msk                             (0xFFFUL<<ADC_TR_HT_Pos)                          /*!< 0x0FFF0000 */
#define ADC_TR_HT                                 ADC_TR_HT_Msk

/********************************* Bit definition for ADC_SQR1 register *********************************************/
#define ADC_SQR1_L_Pos                            (0U)
#define ADC_SQR1_L_Msk                            (0xFUL<<ADC_SQR1_L_Pos)                           /*!< 0x0000000F */
#define ADC_SQR1_L                                ADC_SQR1_L_Msk
#define ADC_SQR1_L_0                              (0x1UL<<ADC_SQR1_L_Pos)                           /*!< 0x00000001 */
#define ADC_SQR1_L_1                              (0x2UL<<ADC_SQR1_L_Pos)                           /*!< 0x00000002 */
#define ADC_SQR1_L_2                              (0x4UL<<ADC_SQR1_L_Pos)                           /*!< 0x00000004 */
#define ADC_SQR1_L_3                              (0x8UL<<ADC_SQR1_L_Pos)                           /*!< 0x00000008 */
#define ADC_SQR1_SQ1_Pos                          (6U)
#define ADC_SQR1_SQ1_Msk                          (0xFUL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x000003C0 */
#define ADC_SQR1_SQ1                              ADC_SQR1_SQ1_Msk
#define ADC_SQR1_SQ1_0                            (0x1UL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x00000040 */
#define ADC_SQR1_SQ1_1                            (0x2UL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x00000080 */
#define ADC_SQR1_SQ1_2                            (0x4UL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x00000100 */
#define ADC_SQR1_SQ1_3                            (0x8UL<<ADC_SQR1_SQ1_Pos)                         /*!< 0x00000200 */
#define ADC_SQR1_SQ2_Pos                          (12U)
#define ADC_SQR1_SQ2_Msk                          (0xFUL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x0000F000 */
#define ADC_SQR1_SQ2                              ADC_SQR1_SQ2_Msk
#define ADC_SQR1_SQ2_0                            (0x1UL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x00001000 */
#define ADC_SQR1_SQ2_1                            (0x2UL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x00002000 */
#define ADC_SQR1_SQ2_2                            (0x4UL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x00004000 */
#define ADC_SQR1_SQ2_3                            (0x8UL<<ADC_SQR1_SQ2_Pos)                         /*!< 0x00008000 */
#define ADC_SQR1_SQ3_Pos                          (18U)
#define ADC_SQR1_SQ3_Msk                          (0xFUL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x003C0000 */
#define ADC_SQR1_SQ3                              ADC_SQR1_SQ3_Msk
#define ADC_SQR1_SQ3_0                            (0x1UL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x00040000 */
#define ADC_SQR1_SQ3_1                            (0x2UL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x00080000 */
#define ADC_SQR1_SQ3_2                            (0x4UL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x00100000 */
#define ADC_SQR1_SQ3_3                            (0x8UL<<ADC_SQR1_SQ3_Pos)                         /*!< 0x00200000 */
#define ADC_SQR1_SQ4_Pos                          (24U)
#define ADC_SQR1_SQ4_Msk                          (0xFUL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x0F000000 */
#define ADC_SQR1_SQ4                              ADC_SQR1_SQ4_Msk
#define ADC_SQR1_SQ4_0                            (0x1UL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x01000000 */
#define ADC_SQR1_SQ4_1                            (0x2UL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x02000000 */
#define ADC_SQR1_SQ4_2                            (0x4UL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x04000000 */
#define ADC_SQR1_SQ4_3                            (0x8UL<<ADC_SQR1_SQ4_Pos)                         /*!< 0x08000000 */

/********************************* Bit definition for ADC_SQR2 register *********************************************/
#define ADC_SQR2_SQ5_Pos                          (0U)
#define ADC_SQR2_SQ5_Msk                          (0xFUL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x0000000F */
#define ADC_SQR2_SQ5                              ADC_SQR2_SQ5_Msk
#define ADC_SQR2_SQ5_0                            (0x1UL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x00000001 */
#define ADC_SQR2_SQ5_1                            (0x2UL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x00000002 */
#define ADC_SQR2_SQ5_2                            (0x4UL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x00000004 */
#define ADC_SQR2_SQ5_3                            (0x8UL<<ADC_SQR2_SQ5_Pos)                         /*!< 0x00000008 */
#define ADC_SQR2_SQ6_Pos                          (6U)
#define ADC_SQR2_SQ6_Msk                          (0xFUL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x000003C0 */
#define ADC_SQR2_SQ6                              ADC_SQR2_SQ6_Msk
#define ADC_SQR2_SQ6_0                            (0x1UL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x00000040 */
#define ADC_SQR2_SQ6_1                            (0x2UL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x00000080 */
#define ADC_SQR2_SQ6_2                            (0x4UL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x00000100 */
#define ADC_SQR2_SQ6_3                            (0x8UL<<ADC_SQR2_SQ6_Pos)                         /*!< 0x00000200 */
#define ADC_SQR2_SQ7_Pos                          (12U)
#define ADC_SQR2_SQ7_Msk                          (0xFUL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x0000F000 */
#define ADC_SQR2_SQ7                              ADC_SQR2_SQ7_Msk
#define ADC_SQR2_SQ7_0                            (0x1UL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x00001000 */
#define ADC_SQR2_SQ7_1                            (0x2UL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x00002000 */
#define ADC_SQR2_SQ7_2                            (0x4UL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x00004000 */
#define ADC_SQR2_SQ7_3                            (0x8UL<<ADC_SQR2_SQ7_Pos)                         /*!< 0x00008000 */
#define ADC_SQR2_SQ8_Pos                          (18U)
#define ADC_SQR2_SQ8_Msk                          (0xFUL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x003C0000 */
#define ADC_SQR2_SQ8                              ADC_SQR2_SQ8_Msk
#define ADC_SQR2_SQ8_0                            (0x1UL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x00040000 */
#define ADC_SQR2_SQ8_1                            (0x2UL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x00080000 */
#define ADC_SQR2_SQ8_2                            (0x4UL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x00100000 */
#define ADC_SQR2_SQ8_3                            (0x8UL<<ADC_SQR2_SQ8_Pos)                         /*!< 0x00200000 */
#define ADC_SQR2_SQ9_Pos                          (24U)
#define ADC_SQR2_SQ9_Msk                          (0xFUL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x0F000000 */
#define ADC_SQR2_SQ9                              ADC_SQR2_SQ9_Msk
#define ADC_SQR2_SQ9_0                            (0x1UL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x01000000 */
#define ADC_SQR2_SQ9_1                            (0x2UL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x02000000 */
#define ADC_SQR2_SQ9_2                            (0x4UL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x04000000 */
#define ADC_SQR2_SQ9_3                            (0x8UL<<ADC_SQR2_SQ9_Pos)                         /*!< 0x08000000 */

/********************************* Bit definition for ADC_SQR3 register *********************************************/
#define ADC_SQR3_SQ10_Pos                         (0U)
#define ADC_SQR3_SQ10_Msk                         (0xFUL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x0000000F */
#define ADC_SQR3_SQ10                             ADC_SQR3_SQ10_Msk
#define ADC_SQR3_SQ10_0                           (0x1UL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x00000001 */
#define ADC_SQR3_SQ10_1                           (0x2UL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x00000002 */
#define ADC_SQR3_SQ10_2                           (0x4UL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x00000004 */
#define ADC_SQR3_SQ10_3                           (0x8UL<<ADC_SQR3_SQ10_Pos)                        /*!< 0x00000008 */
#define ADC_SQR3_SQ11_Pos                         (6U)
#define ADC_SQR3_SQ11_Msk                         (0xFUL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x000003C0 */
#define ADC_SQR3_SQ11                             ADC_SQR3_SQ11_Msk
#define ADC_SQR3_SQ11_0                           (0x1UL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x00000040 */
#define ADC_SQR3_SQ11_1                           (0x2UL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x00000080 */
#define ADC_SQR3_SQ11_2                           (0x4UL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x00000100 */
#define ADC_SQR3_SQ11_3                           (0x8UL<<ADC_SQR3_SQ11_Pos)                        /*!< 0x00000200 */
#define ADC_SQR3_SQ12_Pos                         (12U)
#define ADC_SQR3_SQ12_Msk                         (0xFUL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x0000F000 */
#define ADC_SQR3_SQ12                             ADC_SQR3_SQ12_Msk
#define ADC_SQR3_SQ12_0                           (0x1UL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x00001000 */
#define ADC_SQR3_SQ12_1                           (0x2UL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x00002000 */
#define ADC_SQR3_SQ12_2                           (0x4UL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x00004000 */
#define ADC_SQR3_SQ12_3                           (0x8UL<<ADC_SQR3_SQ12_Pos)                        /*!< 0x00008000 */
#define ADC_SQR3_SQ13_Pos                         (18U)
#define ADC_SQR3_SQ13_Msk                         (0xFUL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x003C0000 */
#define ADC_SQR3_SQ13                             ADC_SQR3_SQ13_Msk
#define ADC_SQR3_SQ13_0                           (0x1UL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x00040000 */
#define ADC_SQR3_SQ13_1                           (0x2UL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x00080000 */
#define ADC_SQR3_SQ13_2                           (0x4UL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x00100000 */
#define ADC_SQR3_SQ13_3                           (0x8UL<<ADC_SQR3_SQ13_Pos)                        /*!< 0x00200000 */
#define ADC_SQR3_SQ14_Pos                         (24U)
#define ADC_SQR3_SQ14_Msk                         (0xFUL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x0F000000 */
#define ADC_SQR3_SQ14                             ADC_SQR3_SQ14_Msk
#define ADC_SQR3_SQ14_0                           (0x1UL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x01000000 */
#define ADC_SQR3_SQ14_1                           (0x2UL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x02000000 */
#define ADC_SQR3_SQ14_2                           (0x4UL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x04000000 */
#define ADC_SQR3_SQ14_3                           (0x8UL<<ADC_SQR3_SQ14_Pos)                        /*!< 0x08000000 */

/********************************* Bit definition for ADC_DR1 register **********************************************/
#define ADC_DR1_SQ1_DATA_Pos                      (0U)
#define ADC_DR1_SQ1_DATA_Msk                      (0xFFFFUL<<ADC_DR1_SQ1_DATA_Pos)                  /*!< 0x0000FFFF */
#define ADC_DR1_SQ1_DATA                          ADC_DR1_SQ1_DATA_Msk
#define ADC_DR1_SQ2_DATA_Pos                      (16U)
#define ADC_DR1_SQ2_DATA_Msk                      (0xFFFFUL<<ADC_DR1_SQ2_DATA_Pos)                  /*!< 0xFFFF0000 */
#define ADC_DR1_SQ2_DATA                          ADC_DR1_SQ2_DATA_Msk

/********************************* Bit definition for ADC_DR2 register **********************************************/
#define ADC_DR2_SQ3_DATA_Pos                      (0U)
#define ADC_DR2_SQ3_DATA_Msk                      (0xFFFFUL<<ADC_DR2_SQ3_DATA_Pos)                  /*!< 0x0000FFFF */
#define ADC_DR2_SQ3_DATA                          ADC_DR2_SQ3_DATA_Msk
#define ADC_DR2_SQ4_DATA_Pos                      (16U)
#define ADC_DR2_SQ4_DATA_Msk                      (0xFFFFUL<<ADC_DR2_SQ4_DATA_Pos)                  /*!< 0xFFFF0000 */
#define ADC_DR2_SQ4_DATA                          ADC_DR2_SQ4_DATA_Msk

/********************************* Bit definition for ADC_DR3 register **********************************************/
#define ADC_DR3_SQ5_DATA_Pos                      (0U)
#define ADC_DR3_SQ5_DATA_Msk                      (0xFFFFUL<<ADC_DR3_SQ5_DATA_Pos)                  /*!< 0x0000FFFF */
#define ADC_DR3_SQ5_DATA                          ADC_DR3_SQ5_DATA_Msk
#define ADC_DR3_SQ6_DATA_Pos                      (16U)
#define ADC_DR3_SQ6_DATA_Msk                      (0xFFFFUL<<ADC_DR3_SQ6_DATA_Pos)                  /*!< 0xFFFF0000 */
#define ADC_DR3_SQ6_DATA                          ADC_DR3_SQ6_DATA_Msk

/********************************* Bit definition for ADC_DR4 register **********************************************/
#define ADC_DR4_SQ7_DATA_Pos                      (0U)
#define ADC_DR4_SQ7_DATA_Msk                      (0xFFFFUL<<ADC_DR4_SQ7_DATA_Pos)                  /*!< 0x0000FFFF */
#define ADC_DR4_SQ7_DATA                          ADC_DR4_SQ7_DATA_Msk
#define ADC_DR4_SQ8_DATA_Pos                      (16U)
#define ADC_DR4_SQ8_DATA_Msk                      (0xFFFFUL<<ADC_DR4_SQ8_DATA_Pos)                  /*!< 0xFFFF0000 */
#define ADC_DR4_SQ8_DATA                          ADC_DR4_SQ8_DATA_Msk

/********************************* Bit definition for ADC_DR5 register **********************************************/
#define ADC_DR5_SQ9_DATA_Pos                      (0U)
#define ADC_DR5_SQ9_DATA_Msk                      (0xFFFFUL<<ADC_DR5_SQ9_DATA_Pos)                  /*!< 0x0000FFFF */
#define ADC_DR5_SQ9_DATA                          ADC_DR5_SQ9_DATA_Msk
#define ADC_DR5_SQ10_DATA_Pos                     (16U)
#define ADC_DR5_SQ10_DATA_Msk                     (0xFFFFUL<<ADC_DR5_SQ10_DATA_Pos)                 /*!< 0xFFFF0000 */
#define ADC_DR5_SQ10_DATA                         ADC_DR5_SQ10_DATA_Msk

/********************************* Bit definition for ADC_DR6 register **********************************************/
#define ADC_DR6_SQ11_DATA_Pos                     (0U)
#define ADC_DR6_SQ11_DATA_Msk                     (0xFFFFUL<<ADC_DR6_SQ11_DATA_Pos)                 /*!< 0x0000FFFF */
#define ADC_DR6_SQ11_DATA                         ADC_DR6_SQ11_DATA_Msk
#define ADC_DR6_SQ12_DATA_Pos                     (16U)
#define ADC_DR6_SQ12_DATA_Msk                     (0xFFFFUL<<ADC_DR6_SQ12_DATA_Pos)                 /*!< 0xFFFF0000 */
#define ADC_DR6_SQ12_DATA                         ADC_DR6_SQ12_DATA_Msk

/********************************* Bit definition for ADC_DR7 register **********************************************/
#define ADC_DR7_SQ13_DATA_Pos                     (0U)
#define ADC_DR7_SQ13_DATA_Msk                     (0xFFFFUL<<ADC_DR7_SQ13_DATA_Pos)                 /*!< 0x0000FFFF */
#define ADC_DR7_SQ13_DATA                         ADC_DR7_SQ13_DATA_Msk
#define ADC_DR7_SQ14_DATA_Pos                     (16U)
#define ADC_DR7_SQ14_DATA_Msk                     (0xFFFFUL<<ADC_DR7_SQ14_DATA_Pos)                 /*!< 0xFFFF0000 */
#define ADC_DR7_SQ14_DATA                         ADC_DR7_SQ14_DATA_Msk

/********************************* Bit definition for ADC_CALFACT register ******************************************/
#define ADC_CALFACT_WCALFACT_Pos                  (0U)
#define ADC_CALFACT_WCALFACT_Msk                  (0x1FFUL<<ADC_CALFACT_WCALFACT_Pos)               /*!< 0x000001FF */
#define ADC_CALFACT_WCALFACT                      ADC_CALFACT_WCALFACT_Msk
#define ADC_CALFACT_FACTSEL_Pos                   (9U)
#define ADC_CALFACT_FACTSEL_Msk                   (0x1FUL<<ADC_CALFACT_FACTSEL_Pos)                 /*!< 0x00003E00 */
#define ADC_CALFACT_FACTSEL                       ADC_CALFACT_FACTSEL_Msk
#define ADC_CALFACT_FACTSEL_0                     (0x1UL<<ADC_CALFACT_FACTSEL_Pos)                  /*!< 0x00000200 */
#define ADC_CALFACT_FACTSEL_1                     (0x2UL<<ADC_CALFACT_FACTSEL_Pos)                  /*!< 0x00000400 */
#define ADC_CALFACT_FACTSEL_2                     (0x4UL<<ADC_CALFACT_FACTSEL_Pos)                  /*!< 0x00000800 */
#define ADC_CALFACT_FACTSEL_3                     (0x8UL<<ADC_CALFACT_FACTSEL_Pos)                  /*!< 0x00001000 */
#define ADC_CALFACT_FACTSEL_4                     (0x10UL<<ADC_CALFACT_FACTSEL_Pos)                 /*!< 0x00002000 */
#define ADC_CALFACT_WRVLD_Pos                     (14U)
#define ADC_CALFACT_WRVLD_Msk                     (0x1UL<<ADC_CALFACT_WRVLD_Pos)                    /*!< 0x00004000 */
#define ADC_CALFACT_WRVLD                         ADC_CALFACT_WRVLD_Msk                             
#define ADC_CALFACT_RDVLD_Pos                     (15U)
#define ADC_CALFACT_RDVLD_Msk                     (0x1UL<<ADC_CALFACT_RDVLD_Pos)                    /*!< 0x00008000 */
#define ADC_CALFACT_RDVLD                         ADC_CALFACT_RDVLD_Msk                                                       
#define ADC_CALFACT_CALFAIL_Pos                   (21U)
#define ADC_CALFACT_CALFAIL_Msk                   (0x1UL<<ADC_CALFACT_CALFAIL_Pos)                   /*!< 0x00200000 */
#define ADC_CALFACT_CALFAIL                       ADC_CALFACT_CALFAIL_Msk                            
#define ADC_CALFACT_RCALFACT_Pos                  (23U)
#define ADC_CALFACT_RCALFACT_Msk                  (0x1FFUL<<ADC_CALFACT_RCALFACT_Pos)               /*!< 0xFF800000 */
#define ADC_CALFACT_RCALFACT                      ADC_CALFACT_RCALFACT_Msk

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos           (0U)
#define ADC_DR_DATA_Msk           (0xFFFFUL << ADC_DR_DATA_Pos)                 /*!< 0x0000FFFF */
#define ADC_DR_DATA                ADC_DR_DATA_Msk                              /*!< ADC group regular conversion data */
#define ADC_DR_DATA_0             (0x0001UL << ADC_DR_DATA_Pos)                 /*!< 0x00000001 */
#define ADC_DR_DATA_1             (0x0002UL << ADC_DR_DATA_Pos)                 /*!< 0x00000002 */
#define ADC_DR_DATA_2             (0x0004UL << ADC_DR_DATA_Pos)                 /*!< 0x00000004 */
#define ADC_DR_DATA_3             (0x0008UL << ADC_DR_DATA_Pos)                 /*!< 0x00000008 */
#define ADC_DR_DATA_4             (0x0010UL << ADC_DR_DATA_Pos)                 /*!< 0x00000010 */
#define ADC_DR_DATA_5             (0x0020UL << ADC_DR_DATA_Pos)                 /*!< 0x00000020 */
#define ADC_DR_DATA_6             (0x0040UL << ADC_DR_DATA_Pos)                 /*!< 0x00000040 */
#define ADC_DR_DATA_7             (0x0080UL << ADC_DR_DATA_Pos)                 /*!< 0x00000080 */
#define ADC_DR_DATA_8             (0x0100UL << ADC_DR_DATA_Pos)                 /*!< 0x00000100 */
#define ADC_DR_DATA_9             (0x0200UL << ADC_DR_DATA_Pos)                 /*!< 0x00000200 */
#define ADC_DR_DATA_10            (0x0400UL << ADC_DR_DATA_Pos)                 /*!< 0x00000400 */
#define ADC_DR_DATA_11            (0x0800UL << ADC_DR_DATA_Pos)                 /*!< 0x00000800 */
#define ADC_DR_DATA_12            (0x1000UL << ADC_DR_DATA_Pos)                 /*!< 0x00001000 */
#define ADC_DR_DATA_13            (0x2000UL << ADC_DR_DATA_Pos)                 /*!< 0x00002000 */
#define ADC_DR_DATA_14            (0x4000UL << ADC_DR_DATA_Pos)                 /*!< 0x00004000 */
#define ADC_DR_DATA_15            (0x8000UL << ADC_DR_DATA_Pos)                 /*!< 0x00008000 */

/********************************* Bit definition for ADCX_CCR register *********************************************/
#define ADC_CCR_VREFEN_Pos                        (22U)
#define ADC_CCR_VREFEN_Msk                        (0x1UL<<ADC_CCR_VREFEN_Pos)                      /*!< 0x00400000 */
#define ADC_CCR_VREFEN                            ADC_CCR_VREFEN_Msk                               
#define ADC_CCR_TSEN_Pos                          (23U)
#define ADC_CCR_TSEN_Msk                          (0x1UL<<ADC_CCR_TSEN_Pos)                        /*!< 0x00800000 */
#define ADC_CCR_TSEN                              ADC_CCR_TSEN_Msk                                 
#define ADC_CCR_VREFSEL_Pos                       (24U)
#define ADC_CCR_VREFSEL_Msk                       (0x1UL<<ADC_CCR_VREFSEL_Pos)                     /*!< 0x01000000 */
#define ADC_CCR_VREFSEL                           ADC_CCR_VREFSEL_Msk                              
#define ADC_CCR_PWRMODE_Pos                       (25U)
#define ADC_CCR_PWRMODE_Msk                       (0x7UL<<ADC_CCR_PWRMODE_Pos)                     /*!< 0x0E000000 */
#define ADC_CCR_PWRMODE                           ADC_CCR_PWRMODE_Msk
#define ADC_CCR_PWRMODE_0                         (0x1UL<<ADC_CCR_PWRMODE_Pos)                     /*!< 0x02000000 */
#define ADC_CCR_PWRMODE_1                         (0x2UL<<ADC_CCR_PWRMODE_Pos)                     /*!< 0x04000000 */
#define ADC_CCR_PWRMODE_2                         (0x4UL<<ADC_CCR_PWRMODE_Pos)                     /*!< 0x08000000 */

/******************************************************************************/
/*                                                                            */
/*                          CRC calculation unit (CRC)                        */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR_Pos            (0U)
#define CRC_DR_DR_Msk            (0xFFFFFFFFUL << CRC_DR_DR_Pos)                /*!< 0xFFFFFFFF */
#define CRC_DR_DR                CRC_DR_DR_Msk                                  /*!< Data register bits */

/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR_Pos          (0U)
#define CRC_IDR_IDR_Msk          (0xFFUL << CRC_IDR_IDR_Pos)                  /*!< 0xFFFFFFFF */
#define CRC_IDR_IDR              CRC_IDR_IDR_Msk                              /*!< General-purpose 8-bit data register bits */

/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET_Pos         (0U)
#define CRC_CR_RESET_Msk         (0x1UL << CRC_CR_RESET_Pos)                    /*!< 0x00000001 */
#define CRC_CR_RESET             CRC_CR_RESET_Msk                               /*!< RESET the CRC computation unit bit */

/******************************************************************************/
/*                                                                            */
/*                                Debug MCU (DBGMCU)                          */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBG_IDCODE register  *************/
#define DBGMCU_IDCODE_Pos                                 (0U)
#define DBGMCU_IDCODE_Msk                                 (0xFFFFFFFFUL << DBGMCU_IDCODE_Pos)      /*!< 0x00000003 */
#define DBGMCU_IDCODE                                     DBGMCU_IDCODE_Msk

/********************  Bit definition for DBGMCU_CR register  *****************/
#define DBGMCU_CR_DBG_SLEEP_Pos                           (0U)
#define DBGMCU_CR_DBG_SLEEP_Msk                           (0x1UL << DBGMCU_CR_DBG_SLEEP_Pos)       /*!< 0x00000001 */
#define DBGMCU_CR_DBG_SLEEP                               DBGMCU_CR_DBG_SLEEP_Msk
#define DBGMCU_CR_DBG_STOP_Pos                            (1U)
#define DBGMCU_CR_DBG_STOP_Msk                            (0x1UL << DBGMCU_CR_DBG_STOP_Pos)        /*!< 0x00000002 */
#define DBGMCU_CR_DBG_STOP                                DBGMCU_CR_DBG_STOP_Msk

/********************  Bit definition for DBGMCU_APB_FZ1 register  ***********/
#define DBGMCU_APB_FZ1_DBG_IWDG_STOP_Pos                  (12U)
#define DBGMCU_APB_FZ1_DBG_IWDG_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ1_DBG_IWDG_STOP_Pos)  /*!< 0x00004000 */
#define DBGMCU_APB_FZ1_DBG_IWDG_STOP                      DBGMCU_APB_FZ1_DBG_IWDG_STOP_Msk
#define DBGMCU_APB_FZ1_DBG_LPTIM_STOP_Pos                 (31U)
#define DBGMCU_APB_FZ1_DBG_LPTIM_STOP_Msk                 (0x1UL << DBGMCU_APB_FZ1_DBG_LPTIM_STOP_Pos) /*!< 0x00001000 */
#define DBGMCU_APB_FZ1_DBG_LPTIM_STOP                     DBGMCU_APB_FZ1_DBG_LPTIM_STOP_Msk

/********************  Bit definition for DBGMCU_APB_FZ2 register  ************/
#define DBGMCU_APB_FZ2_DBG_TIM1_STOP_Pos                  (11U)
#define DBGMCU_APB_FZ2_DBG_TIM1_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ2_DBG_TIM1_STOP_Pos)  /*!< 0x00000800 */
#define DBGMCU_APB_FZ2_DBG_TIM1_STOP                      DBGMCU_APB_FZ2_DBG_TIM1_STOP_Msk
#define DBGMCU_APB_FZ2_DBG_TIM13_STOP_Pos                 (14U)
#define DBGMCU_APB_FZ2_DBG_TIM13_STOP_Msk                 (0x1UL << DBGMCU_APB_FZ2_DBG_TIM13_STOP_Pos)  /*!< 0x00004000 */
#define DBGMCU_APB_FZ2_DBG_TIM13_STOP                     DBGMCU_APB_FZ2_DBG_TIM13_STOP_Msk
#define DBGMCU_APB_FZ2_DBG_TIM14_STOP_Pos                 (15U)
#define DBGMCU_APB_FZ2_DBG_TIM14_STOP_Msk                 (0x1UL << DBGMCU_APB_FZ2_DBG_TIM14_STOP_Pos)  /*!< 0x00008000 */
#define DBGMCU_APB_FZ2_DBG_TIM14_STOP                     DBGMCU_APB_FZ2_DBG_TIM14_STOP_Msk
#define DBGMCU_APB_FZ2_DBG_PWM1_STOP_Pos                  (19U)
#define DBGMCU_APB_FZ2_DBG_PWM1_STOP_Msk                  (0x1UL << DBGMCU_APB_FZ2_DBG_PWM1_STOP_Pos)  /*!< 0x00008000 */
#define DBGMCU_APB_FZ2_DBG_PWM1_STOP                      DBGMCU_APB_FZ2_DBG_PWM1_STOP_Msk

/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller (EXTI)              */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for EXTI_RTSR register  ******************/
#define EXTI_RTSR_RT0_Pos           (0U)
#define EXTI_RTSR_RT0_Msk           (0x1UL << EXTI_RTSR_RT0_Pos)             /*!< 0x00000001 */
#define EXTI_RTSR_RT0               EXTI_RTSR_RT0_Msk                        /*!< Rising trigger configuration for input line 0 */
#define EXTI_RTSR_RT1_Pos           (1U)
#define EXTI_RTSR_RT1_Msk           (0x1UL << EXTI_RTSR_RT1_Pos)             /*!< 0x00000002 */
#define EXTI_RTSR_RT1               EXTI_RTSR_RT1_Msk                        /*!< Rising trigger configuration for input line 1 */
#define EXTI_RTSR_RT2_Pos           (2U)
#define EXTI_RTSR_RT2_Msk           (0x1UL << EXTI_RTSR_RT2_Pos)             /*!< 0x00000004 */
#define EXTI_RTSR_RT2               EXTI_RTSR_RT2_Msk                        /*!< Rising trigger configuration for input line 2 */
#define EXTI_RTSR_RT3_Pos           (3U)
#define EXTI_RTSR_RT3_Msk           (0x1UL << EXTI_RTSR_RT3_Pos)             /*!< 0x00000008 */
#define EXTI_RTSR_RT3               EXTI_RTSR_RT3_Msk                        /*!< Rising trigger configuration for input line 3 */
#define EXTI_RTSR_RT4_Pos           (4U)
#define EXTI_RTSR_RT4_Msk           (0x1UL << EXTI_RTSR_RT4_Pos)             /*!< 0x00000010 */
#define EXTI_RTSR_RT4               EXTI_RTSR_RT4_Msk                        /*!< Rising trigger configuration for input line 4 */
#define EXTI_RTSR_RT5_Pos           (5U)
#define EXTI_RTSR_RT5_Msk           (0x1UL << EXTI_RTSR_RT5_Pos)             /*!< 0x00000020 */
#define EXTI_RTSR_RT5               EXTI_RTSR_RT5_Msk                        /*!< Rising trigger configuration for input line 5 */
#define EXTI_RTSR_RT6_Pos           (6U)
#define EXTI_RTSR_RT6_Msk           (0x1UL << EXTI_RTSR_RT6_Pos)             /*!< 0x00000040 */
#define EXTI_RTSR_RT6               EXTI_RTSR_RT6_Msk                        /*!< Rising trigger configuration for input line 6 */
#define EXTI_RTSR_RT7_Pos           (7U)
#define EXTI_RTSR_RT7_Msk           (0x1UL << EXTI_RTSR_RT7_Pos)             /*!< 0x00000080 */
#define EXTI_RTSR_RT7               EXTI_RTSR_RT7_Msk                        /*!< Rising trigger configuration for input line 7 */
#define EXTI_RTSR_RT16_Pos          (16U)
#define EXTI_RTSR_RT16_Msk          (0x1UL << EXTI_RTSR_RT16_Pos)            /*!< 0x00010000 */
#define EXTI_RTSR_RT16              EXTI_RTSR_RT16_Msk                       /*!< Rising trigger configuration for input line 16 */
#define EXTI_RTSR_RT17_Pos          (17U)
#define EXTI_RTSR_RT17_Msk          (0x1UL << EXTI_RTSR_RT17_Pos)            /*!< 0x00020000 */
#define EXTI_RTSR_RT17              EXTI_RTSR_RT17_Msk                       /*!< Rising trigger configuration for input line 17 */
#define EXTI_RTSR_RT18_Pos          (18U)
#define EXTI_RTSR_RT18_Msk          (0x1UL << EXTI_RTSR_RT18_Pos)            /*!< 0x00040000 */
#define EXTI_RTSR_RT18              EXTI_RTSR_RT18_Msk                       /*!< Rising trigger configuration for input line 18 */

/******************  Bit definition for EXTI_FTSR register  ******************/
#define EXTI_FTSR_FT0_Pos           (0U)
#define EXTI_FTSR_FT0_Msk           (0x1UL << EXTI_FTSR_FT0_Pos)             /*!< 0x00000001 */
#define EXTI_FTSR_FT0               EXTI_FTSR_FT0_Msk                        /*!< Falling trigger configuration for input line 0 */
#define EXTI_FTSR_FT1_Pos           (1U)
#define EXTI_FTSR_FT1_Msk           (0x1UL << EXTI_FTSR_FT1_Pos)             /*!< 0x00000002 */
#define EXTI_FTSR_FT1               EXTI_FTSR_FT1_Msk                        /*!< Falling trigger configuration for input line 1 */
#define EXTI_FTSR_FT2_Pos           (2U)
#define EXTI_FTSR_FT2_Msk           (0x1UL << EXTI_FTSR_FT2_Pos)             /*!< 0x00000004 */
#define EXTI_FTSR_FT2               EXTI_FTSR_FT2_Msk                        /*!< Falling trigger configuration for input line 2 */
#define EXTI_FTSR_FT3_Pos           (3U)
#define EXTI_FTSR_FT3_Msk           (0x1UL << EXTI_FTSR_FT3_Pos)             /*!< 0x00000008 */
#define EXTI_FTSR_FT3               EXTI_FTSR_FT3_Msk                        /*!< Falling trigger configuration for input line 3 */
#define EXTI_FTSR_FT4_Pos           (4U)
#define EXTI_FTSR_FT4_Msk           (0x1UL << EXTI_FTSR_FT4_Pos)             /*!< 0x00000010 */
#define EXTI_FTSR_FT4               EXTI_FTSR_FT4_Msk                        /*!< Falling trigger configuration for input line 4 */
#define EXTI_FTSR_FT5_Pos           (5U)
#define EXTI_FTSR_FT5_Msk           (0x1UL << EXTI_FTSR_FT5_Pos)             /*!< 0x00000020 */
#define EXTI_FTSR_FT5               EXTI_FTSR_FT5_Msk                        /*!< Falling trigger configuration for input line 5 */
#define EXTI_FTSR_FT6_Pos           (6U)
#define EXTI_FTSR_FT6_Msk           (0x1UL << EXTI_FTSR_FT6_Pos)             /*!< 0x00000040 */
#define EXTI_FTSR_FT6               EXTI_FTSR_FT6_Msk                        /*!< Falling trigger configuration for input line 6 */
#define EXTI_FTSR_FT7_Pos           (7U)
#define EXTI_FTSR_FT7_Msk           (0x1UL << EXTI_FTSR_FT7_Pos)             /*!< 0x00000080 */
#define EXTI_FTSR_FT7               EXTI_FTSR_FT7_Msk                        /*!< Falling trigger configuration for input line 7 */
#define EXTI_FTSR_FT16_Pos          (16U)
#define EXTI_FTSR_FT16_Msk          (0x1UL << EXTI_FTSR_FT16_Pos)            /*!< 0x00010000 */
#define EXTI_FTSR_FT16              EXTI_FTSR_FT16_Msk                       /*!< Falling trigger configuration for input line 16 */
#define EXTI_FTSR_FT17_Pos          (17U)
#define EXTI_FTSR_FT17_Msk          (0x1UL << EXTI_FTSR_FT17_Pos)            /*!< 0x00020000 */
#define EXTI_FTSR_FT17              EXTI_FTSR_FT17_Msk                       /*!< Falling trigger configuration for input line 17 */
#define EXTI_FTSR_FT18_Pos          (18U)
#define EXTI_FTSR_FT18_Msk          (0x1UL << EXTI_FTSR_FT18_Pos)            /*!< 0x00040000 */
#define EXTI_FTSR_FT18              EXTI_FTSR_FT18_Msk                       /*!< Falling trigger configuration for input line 18 */

/******************  Bit definition for EXTI_SWIER register  *****************/
#define EXTI_SWIER_SWI0_Pos         (0U)
#define EXTI_SWIER_SWI0_Msk         (0x1UL << EXTI_SWIER_SWI0_Pos)           /*!< 0x00000001 */
#define EXTI_SWIER_SWI0             EXTI_SWIER_SWI0_Msk                      /*!< Software Interrupt on line 0 */
#define EXTI_SWIER_SWI1_Pos         (1U)
#define EXTI_SWIER_SWI1_Msk         (0x1UL << EXTI_SWIER_SWI1_Pos)           /*!< 0x00000002 */
#define EXTI_SWIER_SWI1             EXTI_SWIER_SWI1_Msk                      /*!< Software Interrupt on line 1 */
#define EXTI_SWIER_SWI2_Pos         (2U)
#define EXTI_SWIER_SWI2_Msk         (0x1UL << EXTI_SWIER_SWI2_Pos)           /*!< 0x00000004 */
#define EXTI_SWIER_SWI2             EXTI_SWIER_SWI2_Msk                      /*!< Software Interrupt on line 2 */
#define EXTI_SWIER_SWI3_Pos         (3U)
#define EXTI_SWIER_SWI3_Msk         (0x1UL << EXTI_SWIER_SWI3_Pos)           /*!< 0x00000008 */
#define EXTI_SWIER_SWI3             EXTI_SWIER_SWI3_Msk                      /*!< Software Interrupt on line 3 */
#define EXTI_SWIER_SWI4_Pos         (4U)
#define EXTI_SWIER_SWI4_Msk         (0x1UL << EXTI_SWIER_SWI4_Pos)           /*!< 0x00000010 */
#define EXTI_SWIER_SWI4             EXTI_SWIER_SWI4_Msk                      /*!< Software Interrupt on line 4 */
#define EXTI_SWIER_SWI5_Pos         (5U)
#define EXTI_SWIER_SWI5_Msk         (0x1UL << EXTI_SWIER_SWI5_Pos)           /*!< 0x00000020 */
#define EXTI_SWIER_SWI5             EXTI_SWIER_SWI5_Msk                      /*!< Software Interrupt on line 5 */
#define EXTI_SWIER_SWI6_Pos         (6U)
#define EXTI_SWIER_SWI6_Msk         (0x1UL << EXTI_SWIER_SWI6_Pos)           /*!< 0x00000040 */
#define EXTI_SWIER_SWI6             EXTI_SWIER_SWI6_Msk                      /*!< Software Interrupt on line 6 */
#define EXTI_SWIER_SWI7_Pos         (7U)
#define EXTI_SWIER_SWI7_Msk         (0x1UL << EXTI_SWIER_SWI7_Pos)           /*!< 0x00000080 */
#define EXTI_SWIER_SWI7             EXTI_SWIER_SWI7_Msk                      /*!< Software Interrupt on line 7 */
#define EXTI_SWIER_SWI16_Pos        (16U)
#define EXTI_SWIER_SWI16_Msk        (0x1UL << EXTI_SWIER_SWI16_Pos)          /*!< 0x00010000 */
#define EXTI_SWIER_SWI16            EXTI_SWIER_SWI16_Msk                     /*!< Software Interrupt on line 16 */
#define EXTI_SWIER_SWI17_Pos        (17U)
#define EXTI_SWIER_SWI17_Msk        (0x1UL << EXTI_SWIER_SWI17_Pos)          /*!< 0x00020000 */
#define EXTI_SWIER_SWI17            EXTI_SWIER_SWI17_Msk                     /*!< Software Interrupt on line 17 */
#define EXTI_SWIER_SWI18_Pos        (18U)
#define EXTI_SWIER_SWI18_Msk        (0x1UL << EXTI_SWIER_SWI18_Pos)          /*!< 0x00040000 */
#define EXTI_SWIER_SWI18            EXTI_SWIER_SWI18_Msk                     /*!< Software Interrupt on line 18 */

/*******************  Bit definition for EXTI_PR register  ******************/
#define EXTI_PR_PR0_Pos             (0U)
#define EXTI_PR_PR0_Msk             (0x1UL << EXTI_PR_PR0_Pos)            /*!< 0x00000001 */
#define EXTI_PR_PR0                 EXTI_PR_PR0_Msk                       /*!< Rising Pending Interrupt Flag on line 0 */
#define EXTI_PR_PR1_Pos             (1U)
#define EXTI_PR_PR1_Msk             (0x1UL << EXTI_PR_PR1_Pos)            /*!< 0x00000002 */
#define EXTI_PR_PR1                 EXTI_PR_PR1_Msk                       /*!< Rising Pending Interrupt Flag on line 1 */
#define EXTI_PR_PR2_Pos             (2U)
#define EXTI_PR_PR2_Msk             (0x1UL << EXTI_PR_PR2_Pos)            /*!< 0x00000004 */
#define EXTI_PR_PR2                 EXTI_PR_PR2_Msk                       /*!< Rising Pending Interrupt Flag on line 2 */
#define EXTI_PR_PR3_Pos             (3U)
#define EXTI_PR_PR3_Msk             (0x1UL << EXTI_PR_PR3_Pos)            /*!< 0x00000008 */
#define EXTI_PR_PR3                 EXTI_PR_PR3_Msk                       /*!< Rising Pending Interrupt Flag on line 3 */
#define EXTI_PR_PR4_Pos             (4U)
#define EXTI_PR_PR4_Msk             (0x1UL << EXTI_PR_PR4_Pos )           /*!< 0x00000010 */
#define EXTI_PR_PR4                 EXTI_PR_PR4_Msk                       /*!< Rising Pending Interrupt Flag on line 4 */
#define EXTI_PR_PR5_Pos             (5U)
#define EXTI_PR_PR5_Msk             (0x1UL << EXTI_PR_PR5_Pos )            /*!< 0x00000020 */
#define EXTI_PR_PR5                 EXTI_PR_PR5_Msk                       /*!< Rising Pending Interrupt Flag on line 5 */
#define EXTI_PR_PR6_Pos             (6U)
#define EXTI_PR_PR6_Msk             (0x1UL << EXTI_PR_PR6_Pos)            /*!< 0x00000040 */
#define EXTI_PR_PR6                 EXTI_PR_PR6_Msk                       /*!< Rising Pending Interrupt Flag on line 6 */
#define EXTI_PR_PR7_Pos             (7U)
#define EXTI_PR_PR7_Msk             (0x1UL << EXTI_PR_PR7_Pos)            /*!< 0x00000080 */
#define EXTI_PR_PR7                 EXTI_PR_PR7_Msk                       /*!< Rising Pending Interrupt Flag on line 7 */
#define EXTI_PR_PR16_Pos            (16U)
#define EXTI_PR_PR16_Msk            (0x1UL << EXTI_PR_PR16_Pos)           /*!< 0x00010000 */
#define EXTI_PR_PR16                EXTI_PR_PR16_Msk                      /*!< Rising Pending Interrupt Flag on line 16 */
#define EXTI_PR_PR17_Pos            (17U)
#define EXTI_PR_PR17_Msk            (0x1UL << EXTI_PR_PR17_Pos)           /*!< 0x00020000 */
#define EXTI_PR_PR17                EXTI_PR_PR17_Msk                      /*!< Rising Pending Interrupt Flag on line 17 */
#define EXTI_PR_PR18_Pos            (18U)
#define EXTI_PR_PR18_Msk            (0x1UL << EXTI_PR_PR18_Pos)           /*!< 0x00080000 */
#define EXTI_PR_PR18                EXTI_PR_PR18_Msk                      /*!< Rising Pending Interrupt Flag on line 18 */

/*****************  Bit definition for EXTI_EXTICR1 register  **************/
#define EXTI_EXTICR1_EXTI0_Pos       (0U)
#define EXTI_EXTICR1_EXTI0_Msk       (0x3UL << EXTI_EXTICR1_EXTI0_Pos)         /*!< 0x00000003 */
#define EXTI_EXTICR1_EXTI0           EXTI_EXTICR1_EXTI0_Msk                    /*!< EXTI 0 configuration */
#define EXTI_EXTICR1_EXTI0_0         (0x1UL << EXTI_EXTICR1_EXTI0_Pos)         /*!< 0x00000001 */
#define EXTI_EXTICR1_EXTI0_1         (0x2UL << EXTI_EXTICR1_EXTI0_Pos)         /*!< 0x00000002 */
#define EXTI_EXTICR1_EXTI1_Pos       (8U)
#define EXTI_EXTICR1_EXTI1_Msk       (0x3UL << EXTI_EXTICR1_EXTI1_Pos)         /*!< 0x00000300 */
#define EXTI_EXTICR1_EXTI1           EXTI_EXTICR1_EXTI1_Msk                    /*!< EXTI 1 configuration */
#define EXTI_EXTICR1_EXTI1_0         (0x1UL << EXTI_EXTICR1_EXTI1_Pos)         /*!< 0x00000100 */
#define EXTI_EXTICR1_EXTI1_1         (0x2UL << EXTI_EXTICR1_EXTI1_Pos)         /*!< 0x00000200 */
#define EXTI_EXTICR1_EXTI2_Pos       (16U)
#define EXTI_EXTICR1_EXTI2_Msk       (0x3UL << EXTI_EXTICR1_EXTI2_Pos)         /*!< 0x00030000 */
#define EXTI_EXTICR1_EXTI2           EXTI_EXTICR1_EXTI2_Msk                    /*!< EXTI 2 configuration */
#define EXTI_EXTICR1_EXTI2_0         (0x1UL << EXTI_EXTICR1_EXTI2_Pos)         /*!< 0x00010000 */
#define EXTI_EXTICR1_EXTI2_1         (0x2UL << EXTI_EXTICR1_EXTI2_Pos)         /*!< 0x00020000 */
#define EXTI_EXTICR1_EXTI3_Pos       (24U)
#define EXTI_EXTICR1_EXTI3_Msk       (0x3UL << EXTI_EXTICR1_EXTI3_Pos)         /*!< 0x03000000 */
#define EXTI_EXTICR1_EXTI3           EXTI_EXTICR1_EXTI3_Msk                    /*!< EXTI 3 configuration */
#define EXTI_EXTICR1_EXTI3_0         (0x1UL << EXTI_EXTICR1_EXTI3_Pos)         /*!< 0x01000000 */
#define EXTI_EXTICR1_EXTI3_1         (0x2UL << EXTI_EXTICR1_EXTI3_Pos)         /*!< 0x02000000 */

/*****************  Bit definition for EXTI_EXTICR2 register  **************/
#define EXTI_EXTICR2_EXTI4_Pos       (0U)
#define EXTI_EXTICR2_EXTI4_Msk       (0x3UL << EXTI_EXTICR2_EXTI4_Pos)         /*!< 0x00000003 */
#define EXTI_EXTICR2_EXTI4           EXTI_EXTICR2_EXTI4_Msk                    /*!< EXTI 4 configuration */
#define EXTI_EXTICR2_EXTI4_0         (0x1UL << EXTI_EXTICR2_EXTI4_Pos)         /*!< 0x00000001 */
#define EXTI_EXTICR2_EXTI4_1         (0x2UL << EXTI_EXTICR2_EXTI4_Pos)         /*!< 0x00000002 */
#define EXTI_EXTICR2_EXTI5_Pos       (8U)
#define EXTI_EXTICR2_EXTI5_Msk       (0x3UL << EXTI_EXTICR2_EXTI5_Pos)         /*!< 0x00000100 */
#define EXTI_EXTICR2_EXTI5           EXTI_EXTICR2_EXTI5_Msk                    /*!< EXTI 5 configuration */
#define EXTI_EXTICR2_EXTI5_0         (0x1UL << EXTI_EXTICR2_EXTI5_Pos)         /*!< 0x00000100 */
#define EXTI_EXTICR2_EXTI5_1         (0x2UL << EXTI_EXTICR2_EXTI5_Pos)         /*!< 0x00000200 */
#define EXTI_EXTICR2_EXTI6_Pos       (16U)
#define EXTI_EXTICR2_EXTI6_Msk       (0x3UL << EXTI_EXTICR2_EXTI6_Pos)         /*!< 0x00010000 */
#define EXTI_EXTICR2_EXTI6           EXTI_EXTICR2_EXTI6_Msk                    /*!< EXTI 6 configuration */
#define EXTI_EXTICR2_EXTI6_0         (0x1UL << EXTI_EXTICR2_EXTI6_Pos)         /*!< 0x00010000 */
#define EXTI_EXTICR2_EXTI6_1         (0x2UL << EXTI_EXTICR2_EXTI6_Pos)         /*!< 0x00020000 */
#define EXTI_EXTICR2_EXTI7_Pos       (24U)
#define EXTI_EXTICR2_EXTI7_Msk       (0x1UL << EXTI_EXTICR2_EXTI7_Pos)         /*!< 0x01000000 */
#define EXTI_EXTICR2_EXTI7           EXTI_EXTICR2_EXTI7_Msk                    /*!< EXTI 7 configuration */
#define EXTI_EXTICR2_EXTI7_0         (0x1UL << EXTI_EXTICR2_EXTI7_Pos)         /*!< 0x01000000 */
#define EXTI_EXTICR2_EXTI7_1         (0x2UL << EXTI_EXTICR2_EXTI7_Pos)         /*!< 0x02000000 */

/*******************  Bit definition for EXTI_IMR1 register  ******************/
#define EXTI_IMR_IM_Pos             (0U)
#define EXTI_IMR_IM_Msk             (0x200700FFUL << EXTI_IMR_IM_Pos)        /*!< 0x200700FF */
#define EXTI_IMR_IM                 EXTI_IMR_IM_Msk                          /*!< Interrupt Mask All */
#define EXTI_IMR_IM0_Pos            (0U)
#define EXTI_IMR_IM0_Msk            (0x1UL << EXTI_IMR_IM0_Pos)              /*!< 0x00000001 */
#define EXTI_IMR_IM0                EXTI_IMR_IM0_Msk                         /*!< Interrupt Mask on line 0 */
#define EXTI_IMR_IM1_Pos            (1U)
#define EXTI_IMR_IM1_Msk            (0x1UL << EXTI_IMR_IM1_Pos)              /*!< 0x00000002 */
#define EXTI_IMR_IM1                EXTI_IMR_IM1_Msk                         /*!< Interrupt Mask on line 1 */
#define EXTI_IMR_IM2_Pos            (2U)
#define EXTI_IMR_IM2_Msk            (0x1UL << EXTI_IMR_IM2_Pos)              /*!< 0x00000004 */
#define EXTI_IMR_IM2                EXTI_IMR_IM2_Msk                         /*!< Interrupt Mask on line 2 */
#define EXTI_IMR_IM3_Pos            (3U)
#define EXTI_IMR_IM3_Msk            (0x1UL << EXTI_IMR_IM3_Pos)              /*!< 0x00000008 */
#define EXTI_IMR_IM3                EXTI_IMR_IM3_Msk                         /*!< Interrupt Mask on line 3 */
#define EXTI_IMR_IM4_Pos            (4U)
#define EXTI_IMR_IM4_Msk            (0x1UL << EXTI_IMR_IM4_Pos)              /*!< 0x00000010 */
#define EXTI_IMR_IM4                EXTI_IMR_IM4_Msk                         /*!< Interrupt Mask on line 4 */
#define EXTI_IMR_IM5_Pos            (5U)
#define EXTI_IMR_IM5_Msk            (0x1UL << EXTI_IMR_IM5_Pos)              /*!< 0x00000020 */
#define EXTI_IMR_IM5                EXTI_IMR_IM5_Msk                         /*!< Interrupt Mask on line 5 */
#define EXTI_IMR_IM6_Pos            (6U)
#define EXTI_IMR_IM6_Msk            (0x1UL << EXTI_IMR_IM6_Pos)              /*!< 0x00000040 */
#define EXTI_IMR_IM6                EXTI_IMR_IM6_Msk                         /*!< Interrupt Mask on line 6 */
#define EXTI_IMR_IM7_Pos            (7U)
#define EXTI_IMR_IM7_Msk            (0x1UL << EXTI_IMR_IM7_Pos)              /*!< 0x00000080 */
#define EXTI_IMR_IM7                EXTI_IMR_IM7_Msk                         /*!< Interrupt Mask on line 7 */
#define EXTI_IMR_IM16_Pos           (16U)
#define EXTI_IMR_IM16_Msk           (0x1UL << EXTI_IMR_IM16_Pos)             /*!< 0x00010000 */
#define EXTI_IMR_IM16               EXTI_IMR_IM16_Msk                        /*!< Interrupt Mask on line 16 */
#define EXTI_IMR_IM17_Pos           (17U)
#define EXTI_IMR_IM17_Msk           (0x1UL << EXTI_IMR_IM17_Pos)             /*!< 0x00020000 */
#define EXTI_IMR_IM17               EXTI_IMR_IM17_Msk                        /*!< Interrupt Mask on line 17 */
#define EXTI_IMR_IM18_Pos           (18U)
#define EXTI_IMR_IM18_Msk           (0x1UL << EXTI_IMR_IM18_Pos)             /*!< 0x00040000 */
#define EXTI_IMR_IM18               EXTI_IMR_IM18_Msk                        /*!< Interrupt Mask on line 18 */
#define EXTI_IMR_IM29_Pos           (29U)
#define EXTI_IMR_IM29_Msk           (0x1UL << EXTI_IMR_IM29_Pos)             /*!< 0x20000000 */
#define EXTI_IMR_IM29               EXTI_IMR_IM29_Msk                        /*!< Interrupt Mask on line 29 */

/*******************  Bit definition for EXTI_EMR1 register  ******************/
#define EXTI_EMR_EM_Pos             (0U)
#define EXTI_EMR_EM_Msk             (0x200700FFUL << EXTI_EMR_EM_Pos)        /*!< 0x200700FF */
#define EXTI_EMR_EM                 EXTI_EMR_EM_Msk                          /*!< Event Mask All */
#define EXTI_EMR_EM0_Pos            (0U)
#define EXTI_EMR_EM0_Msk            (0x1UL << EXTI_EMR_EM0_Pos)              /*!< 0x00000001 */
#define EXTI_EMR_EM0                EXTI_EMR_EM0_Msk                         /*!< Event Mask on line 0 */
#define EXTI_EMR_EM1_Pos            (1U)
#define EXTI_EMR_EM1_Msk            (0x1UL << EXTI_EMR_EM1_Pos)              /*!< 0x00000002 */
#define EXTI_EMR_EM1                EXTI_EMR_EM1_Msk                         /*!< Event Mask on line 1 */
#define EXTI_EMR_EM2_Pos            (2U)
#define EXTI_EMR_EM2_Msk            (0x1UL << EXTI_EMR_EM2_Pos)              /*!< 0x00000004 */
#define EXTI_EMR_EM2                EXTI_EMR_EM2_Msk                         /*!< Event Mask on line 2 */
#define EXTI_EMR_EM3_Pos            (3U)
#define EXTI_EMR_EM3_Msk            (0x1UL << EXTI_EMR_EM3_Pos)              /*!< 0x00000008 */
#define EXTI_EMR_EM3                EXTI_EMR_EM3_Msk                         /*!< Event Mask on line 3 */
#define EXTI_EMR_EM4_Pos            (4U)
#define EXTI_EMR_EM4_Msk            (0x1UL << EXTI_EMR_EM4_Pos)              /*!< 0x00000010 */
#define EXTI_EMR_EM4                EXTI_EMR_EM4_Msk                         /*!< Event Mask on line 4 */
#define EXTI_EMR_EM5_Pos            (5U)
#define EXTI_EMR_EM5_Msk            (0x1UL << EXTI_EMR_EM5_Pos)              /*!< 0x00000020 */
#define EXTI_EMR_EM5                EXTI_EMR_EM5_Msk                         /*!< Event Mask on line 5 */
#define EXTI_EMR_EM6_Pos            (6U)
#define EXTI_EMR_EM6_Msk            (0x1UL << EXTI_EMR_EM6_Pos)              /*!< 0x00000040 */
#define EXTI_EMR_EM6                EXTI_EMR_EM6_Msk                         /*!< Event Mask on line 6 */
#define EXTI_EMR_EM7_Pos            (7U)
#define EXTI_EMR_EM7_Msk            (0x1UL << EXTI_EMR_EM7_Pos)              /*!< 0x00000080 */
#define EXTI_EMR_EM7                EXTI_EMR_EM7_Msk                         /*!< Event Mask on line 7 */
#define EXTI_EMR_EM16_Pos           (16U)
#define EXTI_EMR_EM16_Msk           (0x1UL << EXTI_EMR_EM16_Pos)             /*!< 0x00010000 */
#define EXTI_EMR_EM16               EXTI_EMR_EM16_Msk                        /*!< Event Mask on line 16 */
#define EXTI_EMR_EM17_Pos           (17U)
#define EXTI_EMR_EM17_Msk           (0x1UL << EXTI_EMR_EM17_Pos)             /*!< 0x00020000 */
#define EXTI_EMR_EM17               EXTI_EMR_EM17_Msk                        /*!< Event Mask on line 17 */
#define EXTI_EMR_EM18_Pos           (18U)
#define EXTI_EMR_EM18_Msk           (0x1UL << EXTI_EMR_EM18_Pos)             /*!< 0x00040000 */
#define EXTI_EMR_EM18               EXTI_EMR_EM18_Msk                        /*!< Event Mask on line 18 */
#define EXTI_EMR_EM29_Pos           (29U)
#define EXTI_EMR_EM29_Msk           (0x1UL << EXTI_EMR_EM29_Pos)             /*!< 0x20000000 */
#define EXTI_EMR_EM29               EXTI_EMR_EM29_Msk                        /*!< Event Mask on line 29 */

/******************************************************************************/
/*                                                                            */
/*         FLASH and Option Bytes Registers                                   */
/*                                                                            */
/******************************************************************************/
#define GPIO_NRST_CONFIG_SUPPORT         /*!< GPIO feature available only on specific devices: Configure NRST pin */


/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos           (0U)
#define FLASH_ACR_LATENCY_Msk           (0x1UL << FLASH_ACR_LATENCY_Pos)     /*!< 0x00000001 */
#define FLASH_ACR_LATENCY               FLASH_ACR_LATENCY_Msk

/******************  Bit definition for FLASH_KEYR register  ******************/
#define FLASH_KEYR_KEY_Pos              (0U)
#define FLASH_KEYR_KEY_Msk              (0xFFFFFFFFUL << FLASH_KEYR_KEY_Pos) /*!< 0xFFFFFFFF */
#define FLASH_KEYR_KEY                  FLASH_KEYR_KEY_Msk                   /*!< FPEC Key */

/*****************  Bit definition for FLASH_OPTKEYR register  ****************/
#define FLASH_OPTKEYR_OPTKEY_Pos        (0U)
#define FLASH_OPTKEYR_OPTKEY_Msk        (0xFFFFFFFFUL << FLASH_OPTKEYR_OPTKEY_Pos) /*!< 0xFFFFFFFF */
#define FLASH_OPTKEYR_OPTKEY            FLASH_OPTKEYR_OPTKEY_Msk             /*!< Option Byte Key */

/******************  FLASH Keys  **********************************************/
#define FLASH_KEY1_Pos                  (0U)
#define FLASH_KEY1_Msk                  (0x45670123UL << FLASH_KEY1_Pos)     /*!< 0x45670123 */
#define FLASH_KEY1                      FLASH_KEY1_Msk                       /*!< Flash program erase key1 */
#define FLASH_KEY2_Pos                  (0U)
#define FLASH_KEY2_Msk                  (0xCDEF89ABUL << FLASH_KEY2_Pos)     /*!< 0xCDEF89AB */
#define FLASH_KEY2                      FLASH_KEY2_Msk                       /*!< Flash program erase key2: used with FLASH_PEKEY1
                                                                              to unlock the write access to the FPEC. */

#define FLASH_OPTKEY1_Pos               (0U)
#define FLASH_OPTKEY1_Msk               (0x08192A3BUL << FLASH_OPTKEY1_Pos)  /*!< 0x08192A3B */
#define FLASH_OPTKEY1                   FLASH_OPTKEY1_Msk                    /*!< Flash option key1 */
#define FLASH_OPTKEY2_Pos               (0U)
#define FLASH_OPTKEY2_Msk               (0x4C5D6E7FUL << FLASH_OPTKEY2_Pos)  /*!< 0x4C5D6E7F */
#define FLASH_OPTKEY2                   FLASH_OPTKEY2_Msk                    /*!< Flash option key2: used with FLASH_OPTKEY1 to
                                                                              unlock the write access to the option byte block */

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_Pos                (0U)
#define FLASH_SR_EOP_Msk                (0x1UL << FLASH_SR_EOP_Pos)      /*!< 0x00000001 */
#define FLASH_SR_EOP                    FLASH_SR_EOP_Msk
#define FLASH_SR_WRPERR_Pos             (4U)
#define FLASH_SR_WRPERR_Msk             (0x1UL << FLASH_SR_WRPERR_Pos)   /*!< 0x00000010 */
#define FLASH_SR_WRPERR                 FLASH_SR_WRPERR_Msk
#define FLASH_SR_OPTVERR_Pos            (15U)
#define FLASH_SR_OPTVERR_Msk            (0x1UL << FLASH_SR_OPTVERR_Pos)  /*!< 0x00008000 */
#define FLASH_SR_OPTVERR                FLASH_SR_OPTVERR_Msk
#define FLASH_SR_BSY_Pos                (16U)
#define FLASH_SR_BSY_Msk                (0x1UL << FLASH_SR_BSY_Pos)      /*!< 0x00010000 */
#define FLASH_SR_BSY                    FLASH_SR_BSY_Msk

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG_Pos                 (0U)
#define FLASH_CR_PG_Msk                 (0x1UL << FLASH_CR_PG_Pos)       /*!< 0x00000001 */
#define FLASH_CR_PG                     FLASH_CR_PG_Msk
#define FLASH_CR_PER_Pos                (1U)
#define FLASH_CR_PER_Msk                (0x1UL << FLASH_CR_PER_Pos)      /*!< 0x00000002 */
#define FLASH_CR_PER                    FLASH_CR_PER_Msk
#define FLASH_CR_MER_Pos                (2U)
#define FLASH_CR_MER_Msk                (0x1UL << FLASH_CR_MER_Pos)      /*!< 0x00000004 */
#define FLASH_CR_MER                    FLASH_CR_MER_Msk
#define FLASH_CR_SER_Pos                (11U)
#define FLASH_CR_SER_Msk                (0x1UL << FLASH_CR_SER_Pos)      /*!< 0x00000800 */
#define FLASH_CR_SER                    FLASH_CR_SER_Msk
#define FLASH_CR_OPTSTRT_Pos            (17U)
#define FLASH_CR_OPTSTRT_Msk            (0x1UL << FLASH_CR_OPTSTRT_Pos)  /*!< 0x00020000 */
#define FLASH_CR_OPTSTRT                FLASH_CR_OPTSTRT_Msk
#define FLASH_CR_PGSTRT_Pos             (19U)
#define FLASH_CR_PGSTRT_Msk             (0x1UL << FLASH_CR_PGSTRT_Pos)   /*!< 0x00080000 */
#define FLASH_CR_PGSTRT                 FLASH_CR_PGSTRT_Msk
#define FLASH_CR_EOPIE_Pos              (24U)
#define FLASH_CR_EOPIE_Msk              (0x1UL << FLASH_CR_EOPIE_Pos)    /*!< 0x01000000 */
#define FLASH_CR_EOPIE                  FLASH_CR_EOPIE_Msk
#define FLASH_CR_ERRIE_Pos              (25U)
#define FLASH_CR_ERRIE_Msk              (0x1UL << FLASH_CR_ERRIE_Pos)    /*!< 0x02000000 */
#define FLASH_CR_ERRIE                  FLASH_CR_ERRIE_Msk
#define FLASH_CR_OBL_LAUNCH_Pos         (27U)
#define FLASH_CR_OBL_LAUNCH_Msk         (0x1UL << FLASH_CR_OBL_LAUNCH_Pos) /*!< 0x08000000 */
#define FLASH_CR_OBL_LAUNCH             FLASH_CR_OBL_LAUNCH_Msk
#define FLASH_CR_OPTLOCK_Pos            (30U)
#define FLASH_CR_OPTLOCK_Msk            (0x1UL << FLASH_CR_OPTLOCK_Pos)  /*!< 0x40000000 */
#define FLASH_CR_OPTLOCK                FLASH_CR_OPTLOCK_Msk
#define FLASH_CR_LOCK_Pos               (31U)
#define FLASH_CR_LOCK_Msk               (0x1UL << FLASH_CR_LOCK_Pos)     /*!< 0x80000000 */
#define FLASH_CR_LOCK                   FLASH_CR_LOCK_Msk

/*******************  Bits definition for FLASH_OPTR register  ****************/
#define FLASH_OPTR_RDP_Pos              (0U)
#define FLASH_OPTR_RDP_Msk              (0xFFUL<<FLASH_OPTR_RDP_Pos)     /*!< 0x000000FF */
#define FLASH_OPTR_RDP                  FLASH_OPTR_RDP_Msk               /*!< Read Protection */
#define FLASH_OPTR_BOR_EN_Pos           (8U)
#define FLASH_OPTR_BOR_EN_Msk           (0x1UL << FLASH_OPTR_BOR_EN_Pos) /*!< 0x00000100 */
#define FLASH_OPTR_BOR_EN               FLASH_OPTR_BOR_EN_Msk
#define FLASH_OPTR_BOR_LEV_Pos          (9U)
#define FLASH_OPTR_BOR_LEV_Msk          (0x7UL << FLASH_OPTR_BOR_LEV_Pos) /*!< 0x00000E00 */
#define FLASH_OPTR_BOR_LEV              FLASH_OPTR_BOR_LEV_Msk
#define FLASH_OPTR_BOR_LEV_0            (0x1UL << FLASH_OPTR_BOR_LEV_Pos) /*!< 0x00000200 */
#define FLASH_OPTR_BOR_LEV_1            (0x2UL << FLASH_OPTR_BOR_LEV_Pos) /*!< 0x00000400 */
#define FLASH_OPTR_BOR_LEV_2            (0x4UL << FLASH_OPTR_BOR_LEV_Pos) /*!< 0x00000800 */
#define FLASH_OPTR_IWDG_SW_Pos          (12U)
#define FLASH_OPTR_IWDG_SW_Msk          (0x1UL << FLASH_OPTR_IWDG_SW_Pos) /*!< 0x00001000 */
#define FLASH_OPTR_IWDG_SW              FLASH_OPTR_IWDG_SW_Msk
#define FLASH_OPTR_NRST_MODE_Pos        (14U)
#define FLASH_OPTR_NRST_MODE_Msk        (0x1UL << FLASH_OPTR_NRST_MODE_Pos) /*!< 0x00004000 */
#define FLASH_OPTR_NRST_MODE            FLASH_OPTR_NRST_MODE_Msk
#define FLASH_OPTR_IWDG_STOP_Pos        (15U)
#define FLASH_OPTR_IWDG_STOP_Msk        (0x1UL << FLASH_OPTR_IWDG_STOP_Pos) /*!< 0x02000000 */
#define FLASH_OPTR_IWDG_STOP            FLASH_OPTR_IWDG_STOP_Msk

/*******************  Bits definition for FLASH_SDKR register  ****************/
#define FLASH_SDKR_SDK_STRT_Pos         (0U)
#define FLASH_SDKR_SDK_STRT_Msk         (0xFUL << FLASH_SDKR_SDK_STRT_Pos)
#define FLASH_SDKR_SDK_STRT             FLASH_SDKR_SDK_STRT_Msk
#define FLASH_SDKR_SDK_STRT_0           (0x01UL << FLASH_SDKR_SDK_STRT_Pos)
#define FLASH_SDKR_SDK_STRT_1           (0x02UL << FLASH_SDKR_SDK_STRT_Pos)
#define FLASH_SDKR_SDK_STRT_2           (0x04UL << FLASH_SDKR_SDK_STRT_Pos)
#define FLASH_SDKR_SDK_STRT_3           (0x08UL << FLASH_SDKR_SDK_STRT_Pos)
#define FLASH_SDKR_SDK_END_Pos          (8U)
#define FLASH_SDKR_SDK_END_Msk          (0xFUL << FLASH_SDKR_SDK_END_Pos)
#define FLASH_SDKR_SDK_END              FLASH_SDKR_SDK_END_Msk
#define FLASH_SDKR_SDK_END_0            (0x01UL << FLASH_SDKR_SDK_END_Pos)
#define FLASH_SDKR_SDK_END_1            (0x02UL << FLASH_SDKR_SDK_END_Pos)
#define FLASH_SDKR_SDK_END_2            (0x04UL << FLASH_SDKR_SDK_END_Pos)
#define FLASH_SDKR_SDK_END_3            (0x08UL << FLASH_SDKR_SDK_END_Pos)

/******************  Bits definition for FLASH_BTCR register  ***************/
#define FLASH_BTCR_BOOT0_Pos            (14U)
#define FLASH_BTCR_BOOT0_Msk            (0x1UL << FLASH_BTCR_BOOT0_Pos)         /*!< 0x00004000 */
#define FLASH_BTCR_BOOT0                FLASH_BTCR_BOOT0_Msk

/******************  Bits definition for FLASH_WRPR register  ***************/
#define FLASH_WRPR_WRP_Pos              (0U)
#define FLASH_WRPR_WRP_Msk              (0xFFUL << FLASH_WRPR_WRP_Pos)          /*!< 0x000000FF */
#define FLASH_WRPR_WRP                  FLASH_WRPR_WRP_Msk
#define FLASH_WRPR_WRP_0                (0x0001UL << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP_1                (0x0002UL << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP_2                (0x0004UL << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP_3                (0x0008UL << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP_4                (0x0010UL << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP_5                (0x0020UL << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP_6                (0x0040UL << FLASH_WRPR_WRP_Pos)
#define FLASH_WRPR_WRP_7                (0x0080UL << FLASH_WRPR_WRP_Pos)

/******************  Bits definition for FLASH_STCR register  ***************/
#define FLASH_STCR_SLEEP_EN_Pos         (0U)
#define FLASH_STCR_SLEEP_EN_Msk         (0x1U << FLASH_STCR_SLEEP_EN_Pos)
#define FLASH_STCR_SLEEP_EN             FLASH_STCR_SLEEP_EN_Msk
#define FLASH_STCR_SLEEP_TIME_Pos       (8U)
#define FLASH_STCR_SLEEP_TIME_Msk       (0xFFU << FLASH_STCR_SLEEP_TIME_Pos)
#define FLASH_STCR_SLEEP_TIME           FLASH_STCR_SLEEP_TIME_Msk

/******************  Bits definition for FLASH_TS0 register  ***************/
#define FLASH_TS0_TS0_Pos               (0U)
#define FLASH_TS0_TS0_Msk               (0x1FFUL << FLASH_TS0_TS0_Pos) /*!< 0x000001FF */
#define FLASH_TS0_TS0                   FLASH_TS0_TS0_Msk

/******************  Bits definition for FLASH_TS1 register  ***************/
#define FLASH_TS1_TS1_Pos               (0U)
#define FLASH_TS1_TS1_Msk               (0x3FFUL << FLASH_TS1_TS1_Pos) /*!< 0x000003FF */
#define FLASH_TS1_TS1                   FLASH_TS1_TS1_Msk

/******************  Bits definition for FLASH_TS2P register  ***************/
#define FLASH_TS2P_TS2P_Pos             (0U)
#define FLASH_TS2P_TS2P_Msk             (0x1FFUL << FLASH_TS2P_TS2P_Pos) /*!< 0x000001FF */
#define FLASH_TS2P_TS2P                 FLASH_TS2P_TS2P_Msk

/******************  Bits definition for FLASH_TPS3 register  ***************/
#define FLASH_TPS3_TPS3_Pos             (0U)
#define FLASH_TPS3_TPS3_Msk             (0xFFFUL << FLASH_TPS3_TPS3_Pos) /*!< 0x00000FFF */
#define FLASH_TPS3_TPS3                 FLASH_TPS3_TPS3_Msk

/******************  Bits definition for FLASH_TS3 register  ***************/
#define FLASH_TS3_TS3_Pos               (0U)
#define FLASH_TS3_TS3_Msk               (0x1FFUL << FLASH_TS3_TS3_Pos) /*!< 0x000001FF */
#define FLASH_TS3_TS3                   FLASH_TS3_TS3_Msk

/******************  Bits definition for FLASH_PERTPE register  ***************/
#define FLASH_PERTPE_PERTPE_Pos         (0U)
#define FLASH_PERTPE_PERTPE_Msk         (0x3FFFFUL << FLASH_PERTPE_PERTPE_Pos) /*!< 0x0003FFFF */
#define FLASH_PERTPE_PERTPE             FLASH_PERTPE_PERTPE_Msk

/******************  Bits definition for FLASH_SMERTPE register  ***************/
#define FLASH_SMERTPE_SMERTPE_Pos       (0U)
#define FLASH_SMERTPE_SMERTPE_Msk       (0x3FFFFUL << FLASH_SMERTPE_SMERTPE_Pos) /*!< 0x0003FFFF */
#define FLASH_SMERTPE_SMERTPE           FLASH_SMERTPE_SMERTPE_Msk

/******************  Bits definition for FLASH_PRGTPE register  ***************/
#define FLASH_PRGTPE_PRGTPE_Pos         (0U)
#define FLASH_PRGTPE_PRGTPE_Msk         (0xFFFFUL << FLASH_PRGTPE_PRGTPE_Pos) /*!< 0x0000FFFF */
#define FLASH_PRGTPE_PRGTPE             FLASH_PRGTPE_PRGTPE_Msk

/******************  Bits definition for FLASH_PRETPE register  ***************/
#define FLASH_PRETPE_PRETPE_Pos         (0U)
#define FLASH_PRETPE_PRETPE_Msk         (0x3FFFUL << FLASH_PRETPE_PRETPE_Pos) /*!< 0x00003FFF */
#define FLASH_PRETPE_PRETPE             FLASH_PRETPE_PRETPE_Msk

/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O (GPIO)                      */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODE0_Pos            (0U)
#define GPIO_MODER_MODE0_Msk            (0x3UL << GPIO_MODER_MODE0_Pos)          /*!< 0x00000003 */
#define GPIO_MODER_MODE0                GPIO_MODER_MODE0_Msk
#define GPIO_MODER_MODE0_0              (0x1UL << GPIO_MODER_MODE0_Pos)          /*!< 0x00000001 */
#define GPIO_MODER_MODE0_1              (0x2UL << GPIO_MODER_MODE0_Pos)          /*!< 0x00000002 */
#define GPIO_MODER_MODE1_Pos            (2U)
#define GPIO_MODER_MODE1_Msk            (0x3UL << GPIO_MODER_MODE1_Pos)          /*!< 0x0000000C */
#define GPIO_MODER_MODE1                GPIO_MODER_MODE1_Msk
#define GPIO_MODER_MODE1_0              (0x1UL << GPIO_MODER_MODE1_Pos)          /*!< 0x00000004 */
#define GPIO_MODER_MODE1_1              (0x2UL << GPIO_MODER_MODE1_Pos)          /*!< 0x00000008 */
#define GPIO_MODER_MODE2_Pos            (4U)
#define GPIO_MODER_MODE2_Msk            (0x3UL << GPIO_MODER_MODE2_Pos)          /*!< 0x00000030 */
#define GPIO_MODER_MODE2                GPIO_MODER_MODE2_Msk
#define GPIO_MODER_MODE2_0              (0x1UL << GPIO_MODER_MODE2_Pos)          /*!< 0x00000010 */
#define GPIO_MODER_MODE2_1              (0x2UL << GPIO_MODER_MODE2_Pos)          /*!< 0x00000020 */
#define GPIO_MODER_MODE3_Pos            (6U)
#define GPIO_MODER_MODE3_Msk            (0x3UL << GPIO_MODER_MODE3_Pos)          /*!< 0x000000C0 */
#define GPIO_MODER_MODE3                GPIO_MODER_MODE3_Msk
#define GPIO_MODER_MODE3_0              (0x1UL << GPIO_MODER_MODE3_Pos)          /*!< 0x00000040 */
#define GPIO_MODER_MODE3_1              (0x2UL << GPIO_MODER_MODE3_Pos)          /*!< 0x00000080 */
#define GPIO_MODER_MODE4_Pos            (8U)
#define GPIO_MODER_MODE4_Msk            (0x3UL << GPIO_MODER_MODE4_Pos)          /*!< 0x00000300 */
#define GPIO_MODER_MODE4                GPIO_MODER_MODE4_Msk
#define GPIO_MODER_MODE4_0              (0x1UL << GPIO_MODER_MODE4_Pos)          /*!< 0x00000100 */
#define GPIO_MODER_MODE4_1              (0x2UL << GPIO_MODER_MODE4_Pos)          /*!< 0x00000200 */
#define GPIO_MODER_MODE5_Pos            (10U)
#define GPIO_MODER_MODE5_Msk            (0x3UL << GPIO_MODER_MODE5_Pos)          /*!< 0x00000C00 */
#define GPIO_MODER_MODE5                GPIO_MODER_MODE5_Msk
#define GPIO_MODER_MODE5_0              (0x1UL << GPIO_MODER_MODE5_Pos)          /*!< 0x00000400 */
#define GPIO_MODER_MODE5_1              (0x2UL << GPIO_MODER_MODE5_Pos)          /*!< 0x00000800 */
#define GPIO_MODER_MODE6_Pos            (12U)
#define GPIO_MODER_MODE6_Msk            (0x3UL << GPIO_MODER_MODE6_Pos)          /*!< 0x00003000 */
#define GPIO_MODER_MODE6                GPIO_MODER_MODE6_Msk
#define GPIO_MODER_MODE6_0              (0x1UL << GPIO_MODER_MODE6_Pos)          /*!< 0x00001000 */
#define GPIO_MODER_MODE6_1              (0x2UL << GPIO_MODER_MODE6_Pos)          /*!< 0x00002000 */
#define GPIO_MODER_MODE7_Pos            (14U)
#define GPIO_MODER_MODE7_Msk            (0x3UL << GPIO_MODER_MODE7_Pos)          /*!< 0x0000C000 */
#define GPIO_MODER_MODE7                GPIO_MODER_MODE7_Msk
#define GPIO_MODER_MODE7_0              (0x1UL << GPIO_MODER_MODE7_Pos)          /*!< 0x00004000 */
#define GPIO_MODER_MODE7_1              (0x2UL << GPIO_MODER_MODE7_Pos)          /*!< 0x00008000 */

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT0_Pos             (0U)
#define GPIO_OTYPER_OT0_Msk             (0x1UL << GPIO_OTYPER_OT0_Pos)           /*!< 0x00000001 */
#define GPIO_OTYPER_OT0                 GPIO_OTYPER_OT0_Msk
#define GPIO_OTYPER_OT1_Pos             (1U)
#define GPIO_OTYPER_OT1_Msk             (0x1UL << GPIO_OTYPER_OT1_Pos)           /*!< 0x00000002 */
#define GPIO_OTYPER_OT1                 GPIO_OTYPER_OT1_Msk
#define GPIO_OTYPER_OT2_Pos             (2U)
#define GPIO_OTYPER_OT2_Msk             (0x1UL << GPIO_OTYPER_OT2_Pos)           /*!< 0x00000004 */
#define GPIO_OTYPER_OT2                 GPIO_OTYPER_OT2_Msk
#define GPIO_OTYPER_OT3_Pos             (3U)
#define GPIO_OTYPER_OT3_Msk             (0x1UL << GPIO_OTYPER_OT3_Pos)           /*!< 0x00000008 */
#define GPIO_OTYPER_OT3                 GPIO_OTYPER_OT3_Msk
#define GPIO_OTYPER_OT4_Pos             (4U)
#define GPIO_OTYPER_OT4_Msk             (0x1UL << GPIO_OTYPER_OT4_Pos)           /*!< 0x00000010 */
#define GPIO_OTYPER_OT4                 GPIO_OTYPER_OT4_Msk
#define GPIO_OTYPER_OT5_Pos             (5U)
#define GPIO_OTYPER_OT5_Msk             (0x1UL << GPIO_OTYPER_OT5_Pos)           /*!< 0x00000020 */
#define GPIO_OTYPER_OT5                 GPIO_OTYPER_OT5_Msk
#define GPIO_OTYPER_OT6_Pos             (6U)
#define GPIO_OTYPER_OT6_Msk             (0x1UL << GPIO_OTYPER_OT6_Pos)           /*!< 0x00000040 */
#define GPIO_OTYPER_OT6                 GPIO_OTYPER_OT6_Msk
#define GPIO_OTYPER_OT7_Pos             (7U)
#define GPIO_OTYPER_OT7_Msk             (0x1UL << GPIO_OTYPER_OT7_Pos)           /*!< 0x00000080 */
#define GPIO_OTYPER_OT7                 GPIO_OTYPER_OT7_Msk

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDR_OSPEED0_Pos        (0U)
#define GPIO_OSPEEDR_OSPEED0_Msk        (0x3UL << GPIO_OSPEEDR_OSPEED0_Pos)      /*!< 0x00000003 */
#define GPIO_OSPEEDR_OSPEED0            GPIO_OSPEEDR_OSPEED0_Msk
#define GPIO_OSPEEDR_OSPEED0_0          (0x1UL << GPIO_OSPEEDR_OSPEED0_Pos)      /*!< 0x00000001 */
#define GPIO_OSPEEDR_OSPEED0_1          (0x2UL << GPIO_OSPEEDR_OSPEED0_Pos)      /*!< 0x00000002 */
#define GPIO_OSPEEDR_OSPEED1_Pos        (2U)
#define GPIO_OSPEEDR_OSPEED1_Msk        (0x3UL << GPIO_OSPEEDR_OSPEED1_Pos)      /*!< 0x0000000C */
#define GPIO_OSPEEDR_OSPEED1            GPIO_OSPEEDR_OSPEED1_Msk
#define GPIO_OSPEEDR_OSPEED1_0          (0x1UL << GPIO_OSPEEDR_OSPEED1_Pos)      /*!< 0x00000004 */
#define GPIO_OSPEEDR_OSPEED1_1          (0x2UL << GPIO_OSPEEDR_OSPEED1_Pos)      /*!< 0x00000008 */
#define GPIO_OSPEEDR_OSPEED2_Pos        (4U)
#define GPIO_OSPEEDR_OSPEED2_Msk        (0x3UL << GPIO_OSPEEDR_OSPEED2_Pos)      /*!< 0x00000030 */
#define GPIO_OSPEEDR_OSPEED2            GPIO_OSPEEDR_OSPEED2_Msk
#define GPIO_OSPEEDR_OSPEED2_0          (0x1UL << GPIO_OSPEEDR_OSPEED2_Pos)      /*!< 0x00000010 */
#define GPIO_OSPEEDR_OSPEED2_1          (0x2UL << GPIO_OSPEEDR_OSPEED2_Pos)      /*!< 0x00000020 */
#define GPIO_OSPEEDR_OSPEED3_Pos        (6U)
#define GPIO_OSPEEDR_OSPEED3_Msk        (0x3UL << GPIO_OSPEEDR_OSPEED3_Pos)      /*!< 0x000000C0 */
#define GPIO_OSPEEDR_OSPEED3            GPIO_OSPEEDR_OSPEED3_Msk
#define GPIO_OSPEEDR_OSPEED3_0          (0x1UL << GPIO_OSPEEDR_OSPEED3_Pos)      /*!< 0x00000040 */
#define GPIO_OSPEEDR_OSPEED3_1          (0x2UL << GPIO_OSPEEDR_OSPEED3_Pos)      /*!< 0x00000080 */
#define GPIO_OSPEEDR_OSPEED4_Pos        (8U)
#define GPIO_OSPEEDR_OSPEED4_Msk        (0x3UL << GPIO_OSPEEDR_OSPEED4_Pos)      /*!< 0x00000300 */
#define GPIO_OSPEEDR_OSPEED4            GPIO_OSPEEDR_OSPEED4_Msk
#define GPIO_OSPEEDR_OSPEED4_0          (0x1UL << GPIO_OSPEEDR_OSPEED4_Pos)      /*!< 0x00000100 */
#define GPIO_OSPEEDR_OSPEED4_1          (0x2UL << GPIO_OSPEEDR_OSPEED4_Pos)      /*!< 0x00000200 */
#define GPIO_OSPEEDR_OSPEED5_Pos        (10U)
#define GPIO_OSPEEDR_OSPEED5_Msk        (0x3UL << GPIO_OSPEEDR_OSPEED5_Pos)      /*!< 0x00000C00 */
#define GPIO_OSPEEDR_OSPEED5            GPIO_OSPEEDR_OSPEED5_Msk
#define GPIO_OSPEEDR_OSPEED5_0          (0x1UL << GPIO_OSPEEDR_OSPEED5_Pos)      /*!< 0x00000400 */
#define GPIO_OSPEEDR_OSPEED5_1          (0x2UL << GPIO_OSPEEDR_OSPEED5_Pos)      /*!< 0x00000800 */
#define GPIO_OSPEEDR_OSPEED6_Pos        (12U)
#define GPIO_OSPEEDR_OSPEED6_Msk        (0x3UL << GPIO_OSPEEDR_OSPEED6_Pos)      /*!< 0x00003000 */
#define GPIO_OSPEEDR_OSPEED6            GPIO_OSPEEDR_OSPEED6_Msk
#define GPIO_OSPEEDR_OSPEED6_0          (0x1UL << GPIO_OSPEEDR_OSPEED6_Pos)      /*!< 0x00001000 */
#define GPIO_OSPEEDR_OSPEED6_1          (0x2UL << GPIO_OSPEEDR_OSPEED6_Pos)      /*!< 0x00002000 */
#define GPIO_OSPEEDR_OSPEED7_Pos        (14U)
#define GPIO_OSPEEDR_OSPEED7_Msk        (0x3UL << GPIO_OSPEEDR_OSPEED7_Pos)      /*!< 0x0000C000 */
#define GPIO_OSPEEDR_OSPEED7            GPIO_OSPEEDR_OSPEED7_Msk
#define GPIO_OSPEEDR_OSPEED7_0          (0x1UL << GPIO_OSPEEDR_OSPEED7_Pos)      /*!< 0x00004000 */
#define GPIO_OSPEEDR_OSPEED7_1          (0x2UL << GPIO_OSPEEDR_OSPEED7_Pos)      /*!< 0x00008000 */

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPD0_Pos            (0U)
#define GPIO_PUPDR_PUPD0_Msk            (0x3UL << GPIO_PUPDR_PUPD0_Pos)          /*!< 0x00000003 */
#define GPIO_PUPDR_PUPD0                GPIO_PUPDR_PUPD0_Msk
#define GPIO_PUPDR_PUPD0_0              (0x1UL << GPIO_PUPDR_PUPD0_Pos)          /*!< 0x00000001 */
#define GPIO_PUPDR_PUPD0_1              (0x2UL << GPIO_PUPDR_PUPD0_Pos)          /*!< 0x00000002 */
#define GPIO_PUPDR_PUPD1_Pos            (2U)
#define GPIO_PUPDR_PUPD1_Msk            (0x3UL << GPIO_PUPDR_PUPD1_Pos)          /*!< 0x0000000C */
#define GPIO_PUPDR_PUPD1                GPIO_PUPDR_PUPD1_Msk
#define GPIO_PUPDR_PUPD1_0              (0x1UL << GPIO_PUPDR_PUPD1_Pos)          /*!< 0x00000004 */
#define GPIO_PUPDR_PUPD1_1              (0x2UL << GPIO_PUPDR_PUPD1_Pos)          /*!< 0x00000008 */
#define GPIO_PUPDR_PUPD2_Pos            (4U)
#define GPIO_PUPDR_PUPD2_Msk            (0x3UL << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000030 */
#define GPIO_PUPDR_PUPD2                GPIO_PUPDR_PUPD2_Msk
#define GPIO_PUPDR_PUPD2_0              (0x1UL << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000010 */
#define GPIO_PUPDR_PUPD2_1              (0x2UL << GPIO_PUPDR_PUPD2_Pos)          /*!< 0x00000020 */
#define GPIO_PUPDR_PUPD3_Pos            (6U)
#define GPIO_PUPDR_PUPD3_Msk            (0x3UL << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x000000C0 */
#define GPIO_PUPDR_PUPD3                GPIO_PUPDR_PUPD3_Msk
#define GPIO_PUPDR_PUPD3_0              (0x1UL << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x00000040 */
#define GPIO_PUPDR_PUPD3_1              (0x2UL << GPIO_PUPDR_PUPD3_Pos)          /*!< 0x00000080 */
#define GPIO_PUPDR_PUPD4_Pos            (8U)
#define GPIO_PUPDR_PUPD4_Msk            (0x3UL << GPIO_PUPDR_PUPD4_Pos)          /*!< 0x00000300 */
#define GPIO_PUPDR_PUPD4                GPIO_PUPDR_PUPD4_Msk
#define GPIO_PUPDR_PUPD4_0              (0x1UL << GPIO_PUPDR_PUPD4_Pos)          /*!< 0x00000100 */
#define GPIO_PUPDR_PUPD4_1              (0x2UL << GPIO_PUPDR_PUPD4_Pos)          /*!< 0x00000200 */
#define GPIO_PUPDR_PUPD5_Pos            (10U)
#define GPIO_PUPDR_PUPD5_Msk            (0x3UL << GPIO_PUPDR_PUPD5_Pos)          /*!< 0x00000C00 */
#define GPIO_PUPDR_PUPD5                GPIO_PUPDR_PUPD5_Msk
#define GPIO_PUPDR_PUPD5_0              (0x1UL << GPIO_PUPDR_PUPD5_Pos)          /*!< 0x00000400 */
#define GPIO_PUPDR_PUPD5_1              (0x2UL << GPIO_PUPDR_PUPD5_Pos)          /*!< 0x00000800 */
#define GPIO_PUPDR_PUPD6_Pos            (12U)
#define GPIO_PUPDR_PUPD6_Msk            (0x3UL << GPIO_PUPDR_PUPD6_Pos)          /*!< 0x00003000 */
#define GPIO_PUPDR_PUPD6                GPIO_PUPDR_PUPD6_Msk
#define GPIO_PUPDR_PUPD6_0              (0x1UL << GPIO_PUPDR_PUPD6_Pos)          /*!< 0x00001000 */
#define GPIO_PUPDR_PUPD6_1              (0x2UL << GPIO_PUPDR_PUPD6_Pos)          /*!< 0x00002000 */
#define GPIO_PUPDR_PUPD7_Pos            (14U)
#define GPIO_PUPDR_PUPD7_Msk            (0x3UL << GPIO_PUPDR_PUPD7_Pos)          /*!< 0x0000C000 */
#define GPIO_PUPDR_PUPD7                GPIO_PUPDR_PUPD7_Msk
#define GPIO_PUPDR_PUPD7_0              (0x1UL << GPIO_PUPDR_PUPD7_Pos)          /*!< 0x00004000 */
#define GPIO_PUPDR_PUPD7_1              (0x2UL << GPIO_PUPDR_PUPD7_Pos)          /*!< 0x00008000 */

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_ID0_Pos                (0U)
#define GPIO_IDR_ID0_Msk                (0x1UL << GPIO_IDR_ID0_Pos)              /*!< 0x00000001 */
#define GPIO_IDR_ID0                    GPIO_IDR_ID0_Msk
#define GPIO_IDR_ID1_Pos                (1U)
#define GPIO_IDR_ID1_Msk                (0x1UL << GPIO_IDR_ID1_Pos)              /*!< 0x00000002 */
#define GPIO_IDR_ID1                    GPIO_IDR_ID1_Msk
#define GPIO_IDR_ID2_Pos                (2U)
#define GPIO_IDR_ID2_Msk                (0x1UL << GPIO_IDR_ID2_Pos)              /*!< 0x00000004 */
#define GPIO_IDR_ID2                    GPIO_IDR_ID2_Msk
#define GPIO_IDR_ID3_Pos                (3U)
#define GPIO_IDR_ID3_Msk                (0x1UL << GPIO_IDR_ID3_Pos)              /*!< 0x00000008 */
#define GPIO_IDR_ID3                    GPIO_IDR_ID3_Msk
#define GPIO_IDR_ID4_Pos                (4U)
#define GPIO_IDR_ID4_Msk                (0x1UL << GPIO_IDR_ID4_Pos)              /*!< 0x00000010 */
#define GPIO_IDR_ID4                    GPIO_IDR_ID4_Msk
#define GPIO_IDR_ID5_Pos                (5U)
#define GPIO_IDR_ID5_Msk                (0x1UL << GPIO_IDR_ID5_Pos)              /*!< 0x00000020 */
#define GPIO_IDR_ID5                    GPIO_IDR_ID5_Msk
#define GPIO_IDR_ID6_Pos                (6U)
#define GPIO_IDR_ID6_Msk                (0x1UL << GPIO_IDR_ID6_Pos)              /*!< 0x00000040 */
#define GPIO_IDR_ID6                    GPIO_IDR_ID6_Msk
#define GPIO_IDR_ID7_Pos                (7U)
#define GPIO_IDR_ID7_Msk                (0x1UL << GPIO_IDR_ID7_Pos)              /*!< 0x00000080 */
#define GPIO_IDR_ID7                    GPIO_IDR_ID7_Msk

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_OD0_Pos                (0U)
#define GPIO_ODR_OD0_Msk                (0x1UL << GPIO_ODR_OD0_Pos)              /*!< 0x00000001 */
#define GPIO_ODR_OD0                    GPIO_ODR_OD0_Msk
#define GPIO_ODR_OD1_Pos                (1U)
#define GPIO_ODR_OD1_Msk                (0x1UL << GPIO_ODR_OD1_Pos)              /*!< 0x00000002 */
#define GPIO_ODR_OD1                    GPIO_ODR_OD1_Msk
#define GPIO_ODR_OD2_Pos                (2U)
#define GPIO_ODR_OD2_Msk                (0x1UL << GPIO_ODR_OD2_Pos)              /*!< 0x00000004 */
#define GPIO_ODR_OD2                    GPIO_ODR_OD2_Msk
#define GPIO_ODR_OD3_Pos                (3U)
#define GPIO_ODR_OD3_Msk                (0x1UL << GPIO_ODR_OD3_Pos)              /*!< 0x00000008 */
#define GPIO_ODR_OD3                    GPIO_ODR_OD3_Msk
#define GPIO_ODR_OD4_Pos                (4U)
#define GPIO_ODR_OD4_Msk                (0x1UL << GPIO_ODR_OD4_Pos)              /*!< 0x00000010 */
#define GPIO_ODR_OD4                    GPIO_ODR_OD4_Msk
#define GPIO_ODR_OD5_Pos                (5U)
#define GPIO_ODR_OD5_Msk                (0x1UL << GPIO_ODR_OD5_Pos)              /*!< 0x00000020 */
#define GPIO_ODR_OD5                    GPIO_ODR_OD5_Msk
#define GPIO_ODR_OD6_Pos                (6U)
#define GPIO_ODR_OD6_Msk                (0x1UL << GPIO_ODR_OD6_Pos)              /*!< 0x00000040 */
#define GPIO_ODR_OD6                    GPIO_ODR_OD6_Msk
#define GPIO_ODR_OD7_Pos                (7U)
#define GPIO_ODR_OD7_Msk                (0x1UL << GPIO_ODR_OD7_Pos)              /*!< 0x00000080 */
#define GPIO_ODR_OD7                    GPIO_ODR_OD7_Msk

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS0_Pos               (0U)
#define GPIO_BSRR_BS0_Msk               (0x1UL << GPIO_BSRR_BS0_Pos)             /*!< 0x00000001 */
#define GPIO_BSRR_BS0                   GPIO_BSRR_BS0_Msk
#define GPIO_BSRR_BS1_Pos               (1U)
#define GPIO_BSRR_BS1_Msk               (0x1UL << GPIO_BSRR_BS1_Pos)             /*!< 0x00000002 */
#define GPIO_BSRR_BS1                   GPIO_BSRR_BS1_Msk
#define GPIO_BSRR_BS2_Pos               (2U)
#define GPIO_BSRR_BS2_Msk               (0x1UL << GPIO_BSRR_BS2_Pos)             /*!< 0x00000004 */
#define GPIO_BSRR_BS2                   GPIO_BSRR_BS2_Msk
#define GPIO_BSRR_BS3_Pos               (3U)
#define GPIO_BSRR_BS3_Msk               (0x1UL << GPIO_BSRR_BS3_Pos)             /*!< 0x00000008 */
#define GPIO_BSRR_BS3                   GPIO_BSRR_BS3_Msk
#define GPIO_BSRR_BS4_Pos               (4U)
#define GPIO_BSRR_BS4_Msk               (0x1UL << GPIO_BSRR_BS4_Pos)             /*!< 0x00000010 */
#define GPIO_BSRR_BS4                   GPIO_BSRR_BS4_Msk
#define GPIO_BSRR_BS5_Pos               (5U)
#define GPIO_BSRR_BS5_Msk               (0x1UL << GPIO_BSRR_BS5_Pos)             /*!< 0x00000020 */
#define GPIO_BSRR_BS5                   GPIO_BSRR_BS5_Msk
#define GPIO_BSRR_BS6_Pos               (6U)
#define GPIO_BSRR_BS6_Msk               (0x1UL << GPIO_BSRR_BS6_Pos)             /*!< 0x00000040 */
#define GPIO_BSRR_BS6                   GPIO_BSRR_BS6_Msk
#define GPIO_BSRR_BS7_Pos               (7U)
#define GPIO_BSRR_BS7_Msk               (0x1UL << GPIO_BSRR_BS7_Pos)             /*!< 0x00000080 */
#define GPIO_BSRR_BS7                   GPIO_BSRR_BS7_Msk
#define GPIO_BSRR_BR0_Pos               (16U)
#define GPIO_BSRR_BR0_Msk               (0x1UL << GPIO_BSRR_BR0_Pos)             /*!< 0x00010000 */
#define GPIO_BSRR_BR0                   GPIO_BSRR_BR0_Msk
#define GPIO_BSRR_BR1_Pos               (17U)
#define GPIO_BSRR_BR1_Msk               (0x1UL << GPIO_BSRR_BR1_Pos)             /*!< 0x00020000 */
#define GPIO_BSRR_BR1                   GPIO_BSRR_BR1_Msk
#define GPIO_BSRR_BR2_Pos               (18U)
#define GPIO_BSRR_BR2_Msk               (0x1UL << GPIO_BSRR_BR2_Pos)             /*!< 0x00040000 */
#define GPIO_BSRR_BR2                   GPIO_BSRR_BR2_Msk
#define GPIO_BSRR_BR3_Pos               (19U)
#define GPIO_BSRR_BR3_Msk               (0x1UL << GPIO_BSRR_BR3_Pos)             /*!< 0x00080000 */
#define GPIO_BSRR_BR3                   GPIO_BSRR_BR3_Msk
#define GPIO_BSRR_BR4_Pos               (20U)
#define GPIO_BSRR_BR4_Msk               (0x1UL << GPIO_BSRR_BR4_Pos)             /*!< 0x00100000 */
#define GPIO_BSRR_BR4                   GPIO_BSRR_BR4_Msk
#define GPIO_BSRR_BR5_Pos               (21U)
#define GPIO_BSRR_BR5_Msk               (0x1UL << GPIO_BSRR_BR5_Pos)             /*!< 0x00200000 */
#define GPIO_BSRR_BR5                   GPIO_BSRR_BR5_Msk
#define GPIO_BSRR_BR6_Pos               (22U)
#define GPIO_BSRR_BR6_Msk               (0x1UL << GPIO_BSRR_BR6_Pos)             /*!< 0x00400000 */
#define GPIO_BSRR_BR6                   GPIO_BSRR_BR6_Msk
#define GPIO_BSRR_BR7_Pos               (23U)
#define GPIO_BSRR_BR7_Msk               (0x1UL << GPIO_BSRR_BR7_Pos)             /*!< 0x00800000 */
#define GPIO_BSRR_BR7                   GPIO_BSRR_BR7_Msk

/****************** Bit definition for GPIO_LCKR register *********************/
#define GPIO_LCKR_LCK0_Pos              (0U)
#define GPIO_LCKR_LCK0_Msk              (0x1UL << GPIO_LCKR_LCK0_Pos)            /*!< 0x00000001 */
#define GPIO_LCKR_LCK0                  GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos              (1U)
#define GPIO_LCKR_LCK1_Msk              (0x1UL << GPIO_LCKR_LCK1_Pos)            /*!< 0x00000002 */
#define GPIO_LCKR_LCK1                  GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos              (2U)
#define GPIO_LCKR_LCK2_Msk              (0x1UL << GPIO_LCKR_LCK2_Pos)            /*!< 0x00000004 */
#define GPIO_LCKR_LCK2                  GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos              (3U)
#define GPIO_LCKR_LCK3_Msk              (0x1UL << GPIO_LCKR_LCK3_Pos)            /*!< 0x00000008 */
#define GPIO_LCKR_LCK3                  GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos              (4U)
#define GPIO_LCKR_LCK4_Msk              (0x1UL << GPIO_LCKR_LCK4_Pos)            /*!< 0x00000010 */
#define GPIO_LCKR_LCK4                  GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos              (5U)
#define GPIO_LCKR_LCK5_Msk              (0x1UL << GPIO_LCKR_LCK5_Pos)            /*!< 0x00000020 */
#define GPIO_LCKR_LCK5                  GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos              (6U)
#define GPIO_LCKR_LCK6_Msk              (0x1UL << GPIO_LCKR_LCK6_Pos)            /*!< 0x00000040 */
#define GPIO_LCKR_LCK6                  GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos              (7U)
#define GPIO_LCKR_LCK7_Msk              (0x1UL << GPIO_LCKR_LCK7_Pos)            /*!< 0x00000080 */
#define GPIO_LCKR_LCK7                  GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCKK_Pos              (16U)
#define GPIO_LCKR_LCKK_Msk              (0x1UL << GPIO_LCKR_LCKK_Pos)            /*!< 0x00010000 */
#define GPIO_LCKR_LCKK                  GPIO_LCKR_LCKK_Msk

/****************** Bit definition for GPIO_AFR register *********************/
#define GPIO_AFR_AFSEL0_Pos             (0U)
#define GPIO_AFR_AFSEL0_Msk             (0x7UL << GPIO_AFR_AFSEL0_Pos)           /*!< 0x0000000F */
#define GPIO_AFR_AFSEL0                 GPIO_AFR_AFSEL0_Msk
#define GPIO_AFR_AFSEL0_0               (0x1UL << GPIO_AFR_AFSEL0_Pos)           /*!< 0x00000001 */
#define GPIO_AFR_AFSEL0_1               (0x2UL << GPIO_AFR_AFSEL0_Pos)           /*!< 0x00000002 */
#define GPIO_AFR_AFSEL0_2               (0x4UL << GPIO_AFR_AFSEL0_Pos)           /*!< 0x00000004 */

#define GPIO_AFR_AFSEL1_Pos             (4U)
#define GPIO_AFR_AFSEL1_Msk             (0x7UL << GPIO_AFR_AFSEL1_Pos)           /*!< 0x000000F0 */
#define GPIO_AFR_AFSEL1                 GPIO_AFR_AFSEL1_Msk
#define GPIO_AFR_AFSEL1_0               (0x1UL << GPIO_AFR_AFSEL1_Pos)           /*!< 0x00000010 */
#define GPIO_AFR_AFSEL1_1               (0x2UL << GPIO_AFR_AFSEL1_Pos)           /*!< 0x00000020 */
#define GPIO_AFR_AFSEL1_2               (0x4UL << GPIO_AFR_AFSEL1_Pos)           /*!< 0x00000040 */

#define GPIO_AFR_AFSEL2_Pos             (8U)
#define GPIO_AFR_AFSEL2_Msk             (0x7UL << GPIO_AFR_AFSEL2_Pos)           /*!< 0x00000F00 */
#define GPIO_AFR_AFSEL2                 GPIO_AFR_AFSEL2_Msk
#define GPIO_AFR_AFSEL2_0               (0x1UL << GPIO_AFR_AFSEL2_Pos)           /*!< 0x00000100 */
#define GPIO_AFR_AFSEL2_1               (0x2UL << GPIO_AFR_AFSEL2_Pos)           /*!< 0x00000200 */
#define GPIO_AFR_AFSEL2_2               (0x4UL << GPIO_AFR_AFSEL2_Pos)           /*!< 0x00000400 */

#define GPIO_AFR_AFSEL3_Pos             (12U)
#define GPIO_AFR_AFSEL3_Msk             (0x7UL << GPIO_AFR_AFSEL3_Pos)           /*!< 0x0000F000 */
#define GPIO_AFR_AFSEL3                 GPIO_AFR_AFSEL3_Msk
#define GPIO_AFR_AFSEL3_0               (0x1UL << GPIO_AFR_AFSEL3_Pos)           /*!< 0x00001000 */
#define GPIO_AFR_AFSEL3_1               (0x2UL << GPIO_AFR_AFSEL3_Pos)           /*!< 0x00002000 */
#define GPIO_AFR_AFSEL3_2               (0x4UL << GPIO_AFR_AFSEL3_Pos)           /*!< 0x00004000 */

#define GPIO_AFR_AFSEL4_Pos             (16U)
#define GPIO_AFR_AFSEL4_Msk             (0x7UL << GPIO_AFR_AFSEL4_Pos)           /*!< 0x000F0000 */
#define GPIO_AFR_AFSEL4                 GPIO_AFR_AFSEL4_Msk
#define GPIO_AFR_AFSEL4_0               (0x1UL << GPIO_AFR_AFSEL4_Pos)           /*!< 0x00010000 */
#define GPIO_AFR_AFSEL4_1               (0x2UL << GPIO_AFR_AFSEL4_Pos)           /*!< 0x00020000 */
#define GPIO_AFR_AFSEL4_2               (0x4UL << GPIO_AFR_AFSEL4_Pos)           /*!< 0x00040000 */

#define GPIO_AFR_AFSEL5_Pos             (20U)
#define GPIO_AFR_AFSEL5_Msk             (0x7UL << GPIO_AFR_AFSEL5_Pos)           /*!< 0x00F00000 */
#define GPIO_AFR_AFSEL5                 GPIO_AFR_AFSEL5_Msk
#define GPIO_AFR_AFSEL5_0               (0x1UL << GPIO_AFR_AFSEL5_Pos)           /*!< 0x00100000 */
#define GPIO_AFR_AFSEL5_1               (0x2UL << GPIO_AFR_AFSEL5_Pos)           /*!< 0x00200000 */
#define GPIO_AFR_AFSEL5_2               (0x4UL << GPIO_AFR_AFSEL5_Pos)           /*!< 0x00400000 */

#define GPIO_AFR_AFSEL6_Pos             (24U)
#define GPIO_AFR_AFSEL6_Msk             (0x7UL << GPIO_AFR_AFSEL6_Pos)           /*!< 0x0F000000 */
#define GPIO_AFR_AFSEL6                 GPIO_AFR_AFSEL6_Msk
#define GPIO_AFR_AFSEL6_0               (0x1UL << GPIO_AFR_AFSEL6_Pos)           /*!< 0x01000000 */
#define GPIO_AFR_AFSEL6_1               (0x2UL << GPIO_AFR_AFSEL6_Pos)           /*!< 0x02000000 */
#define GPIO_AFR_AFSEL6_2               (0x4UL << GPIO_AFR_AFSEL6_Pos)           /*!< 0x04000000 */

#define GPIO_AFR_AFSEL7_Pos             (28U)
#define GPIO_AFR_AFSEL7_Msk             (0xFUL << GPIO_AFR_AFSEL7_Pos)           /*!< 0xF0000000 */
#define GPIO_AFR_AFSEL7                 GPIO_AFR_AFSEL7_Msk
#define GPIO_AFR_AFSEL7_0               (0x1UL << GPIO_AFR_AFSEL7_Pos)           /*!< 0x10000000 */
#define GPIO_AFR_AFSEL7_1               (0x2UL << GPIO_AFR_AFSEL7_Pos)           /*!< 0x20000000 */
#define GPIO_AFR_AFSEL7_2               (0x4UL << GPIO_AFR_AFSEL7_Pos)           /*!< 0x40000000 */

/******************  Bits definition for GPIO_BRR register  ******************/
#define GPIO_BRR_BR0_Pos                (0U)
#define GPIO_BRR_BR0_Msk                (0x1UL << GPIO_BRR_BR0_Pos)              /*!< 0x00000001 */
#define GPIO_BRR_BR0                    GPIO_BRR_BR0_Msk
#define GPIO_BRR_BR1_Pos                (1U)
#define GPIO_BRR_BR1_Msk                (0x1UL << GPIO_BRR_BR1_Pos)              /*!< 0x00000002 */
#define GPIO_BRR_BR1                    GPIO_BRR_BR1_Msk
#define GPIO_BRR_BR2_Pos                (2U)
#define GPIO_BRR_BR2_Msk                (0x1UL << GPIO_BRR_BR2_Pos)              /*!< 0x00000004 */
#define GPIO_BRR_BR2                    GPIO_BRR_BR2_Msk
#define GPIO_BRR_BR3_Pos                (3U)
#define GPIO_BRR_BR3_Msk                (0x1UL << GPIO_BRR_BR3_Pos)              /*!< 0x00000008 */
#define GPIO_BRR_BR3                    GPIO_BRR_BR3_Msk
#define GPIO_BRR_BR4_Pos                (4U)
#define GPIO_BRR_BR4_Msk                (0x1UL << GPIO_BRR_BR4_Pos)              /*!< 0x00000010 */
#define GPIO_BRR_BR4                    GPIO_BRR_BR4_Msk
#define GPIO_BRR_BR5_Pos                (5U)
#define GPIO_BRR_BR5_Msk                (0x1UL << GPIO_BRR_BR5_Pos)              /*!< 0x00000020 */
#define GPIO_BRR_BR5                    GPIO_BRR_BR5_Msk
#define GPIO_BRR_BR6_Pos                (6U)
#define GPIO_BRR_BR6_Msk                (0x1UL << GPIO_BRR_BR6_Pos)              /*!< 0x00000040 */
#define GPIO_BRR_BR6                    GPIO_BRR_BR6_Msk
#define GPIO_BRR_BR7_Pos                (7U)
#define GPIO_BRR_BR7_Msk                (0x1UL << GPIO_BRR_BR7_Pos)              /*!< 0x00000080 */
#define GPIO_BRR_BR7                    GPIO_BRR_BR7_Msk

/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface (I2C)              */
/*                                                                            */
/******************************************************************************/

/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                  (0U)
#define I2C_CR1_PE_Msk                  (0x1UL << I2C_CR1_PE_Pos)          /*!< 0x00000001 */
#define I2C_CR1_PE                      I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_ENGC_Pos                (6U)
#define I2C_CR1_ENGC_Msk                (0x1UL << I2C_CR1_ENGC_Pos)        /*!< 0x00000040 */
#define I2C_CR1_ENGC                    I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos           (7U)
#define I2C_CR1_NOSTRETCH_Msk           (0x1UL << I2C_CR1_NOSTRETCH_Pos)   /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH               I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos               (8U)
#define I2C_CR1_START_Msk               (0x1UL << I2C_CR1_START_Pos)       /*!< 0x00000100 */
#define I2C_CR1_START                   I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                (9U)
#define I2C_CR1_STOP_Msk                (0x1UL << I2C_CR1_STOP_Pos)        /*!< 0x00000200 */
#define I2C_CR1_STOP                    I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                 (10U)
#define I2C_CR1_ACK_Msk                 (0x1UL << I2C_CR1_ACK_Pos)         /*!< 0x00000400 */
#define I2C_CR1_ACK                     I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                 (11U)
#define I2C_CR1_POS_Msk                 (0x1UL << I2C_CR1_POS_Pos)         /*!< 0x00000800 */
#define I2C_CR1_POS                     I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_SWRST_Pos               (15U)
#define I2C_CR1_SWRST_Msk               (0x1UL << I2C_CR1_SWRST_Pos)       /*!< 0x00008000 */
#define I2C_CR1_SWRST                   I2C_CR1_SWRST_Msk                  /*!< Software Reset */

/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                (0U)
#define I2C_CR2_FREQ_Msk                (0x3FUL << I2C_CR2_FREQ_Pos)       /*!< 0x0000003F */
#define I2C_CR2_FREQ                    I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_FREQ_0                  (0x01UL << I2C_CR2_FREQ_Pos)       /*!< 0x00000001 */
#define I2C_CR2_FREQ_1                  (0x02UL << I2C_CR2_FREQ_Pos)       /*!< 0x00000002 */
#define I2C_CR2_FREQ_2                  (0x04UL << I2C_CR2_FREQ_Pos)       /*!< 0x00000004 */
#define I2C_CR2_FREQ_3                  (0x08UL << I2C_CR2_FREQ_Pos)       /*!< 0x00000008 */
#define I2C_CR2_FREQ_4                  (0x10UL << I2C_CR2_FREQ_Pos)       /*!< 0x00000010 */
#define I2C_CR2_FREQ_5                  (0x20UL << I2C_CR2_FREQ_Pos)       /*!< 0x00000020 */
#define I2C_CR2_ITERREN_Pos             (8U)
#define I2C_CR2_ITERREN_Msk             (0x1UL << I2C_CR2_ITERREN_Pos)     /*!< 0x00000100 */
#define I2C_CR2_ITERREN                 I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos             (9U)
#define I2C_CR2_ITEVTEN_Msk             (0x1UL << I2C_CR2_ITEVTEN_Pos)     /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                 I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos             (10U)
#define I2C_CR2_ITBUFEN_Msk             (0x1UL << I2C_CR2_ITBUFEN_Pos)     /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                 I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */

/*******************  Bit definition for I2C_OAR1 register  *******************/
#define I2C_OAR1_ADD1_7                 0x000000FEU                        /*!< Interface Address */
#define I2C_OAR1_ADD1_Pos               (1U)
#define I2C_OAR1_ADD1_Msk               (0x1UL << I2C_OAR1_ADD1_Pos)       /*!< 0x00000002 */
#define I2C_OAR1_ADD1                   I2C_OAR1_ADD1_Msk                  /*!< Bit 1 */
#define I2C_OAR1_ADD2_Pos               (2U)
#define I2C_OAR1_ADD2_Msk               (0x1UL << I2C_OAR1_ADD2_Pos)       /*!< 0x00000004 */
#define I2C_OAR1_ADD2                   I2C_OAR1_ADD2_Msk                  /*!< Bit 2 */
#define I2C_OAR1_ADD3_Pos               (3U)
#define I2C_OAR1_ADD3_Msk               (0x1UL << I2C_OAR1_ADD3_Pos)       /*!< 0x00000008 */
#define I2C_OAR1_ADD3                   I2C_OAR1_ADD3_Msk                  /*!< Bit 3 */
#define I2C_OAR1_ADD4_Pos               (4U)
#define I2C_OAR1_ADD4_Msk               (0x1UL << I2C_OAR1_ADD4_Pos)       /*!< 0x00000010 */
#define I2C_OAR1_ADD4                   I2C_OAR1_ADD4_Msk                  /*!< Bit 4 */
#define I2C_OAR1_ADD5_Pos               (5U)
#define I2C_OAR1_ADD5_Msk               (0x1UL << I2C_OAR1_ADD5_Pos)       /*!< 0x00000020 */
#define I2C_OAR1_ADD5                   I2C_OAR1_ADD5_Msk                  /*!< Bit 5 */
#define I2C_OAR1_ADD6_Pos               (6U)
#define I2C_OAR1_ADD6_Msk               (0x1UL << I2C_OAR1_ADD6_Pos)       /*!< 0x00000040 */
#define I2C_OAR1_ADD6                   I2C_OAR1_ADD6_Msk                  /*!< Bit 6 */
#define I2C_OAR1_ADD7_Pos               (7U)
#define I2C_OAR1_ADD7_Msk               (0x1UL << I2C_OAR1_ADD7_Pos)       /*!< 0x00000080 */
#define I2C_OAR1_ADD7                   I2C_OAR1_ADD7_Msk                  /*!< Bit 7 */

/********************  Bit definition for I2C_DR register  ********************/
#define I2C_DR_DR_Pos                   (0U)
#define I2C_DR_DR_Msk                   (0xFFUL << I2C_DR_DR_Pos)          /*!< 0x000000FF */
#define I2C_DR_DR                       I2C_DR_DR_Msk                      /*!< 8-bit Data Register */
#define I2C_DR_DR_0                     (0x01UL << I2C_DR_DR_Pos)
#define I2C_DR_DR_1                     (0x02UL << I2C_DR_DR_Pos)
#define I2C_DR_DR_2                     (0x04UL << I2C_DR_DR_Pos)
#define I2C_DR_DR_3                     (0x08UL << I2C_DR_DR_Pos)
#define I2C_DR_DR_4                     (0x10UL << I2C_DR_DR_Pos)
#define I2C_DR_DR_5                     (0x20UL << I2C_DR_DR_Pos)
#define I2C_DR_DR_6                     (0x40UL << I2C_DR_DR_Pos)
#define I2C_DR_DR_7                     (0x80UL << I2C_DR_DR_Pos)

/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                  (0U)
#define I2C_SR1_SB_Msk                  (0x1UL << I2C_SR1_SB_Pos)          /*!< 0x00000001 */
#define I2C_SR1_SB                      I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                (1U)
#define I2C_SR1_ADDR_Msk                (0x1UL << I2C_SR1_ADDR_Pos)        /*!< 0x00000002 */
#define I2C_SR1_ADDR                    I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                 (2U)
#define I2C_SR1_BTF_Msk                 (0x1UL << I2C_SR1_BTF_Pos)         /*!< 0x00000004 */
#define I2C_SR1_BTF                     I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_STOPF_Pos               (4U)
#define I2C_SR1_STOPF_Msk               (0x1UL << I2C_SR1_STOPF_Pos)       /*!< 0x00000010 */
#define I2C_SR1_STOPF                   I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                (6U)
#define I2C_SR1_RXNE_Msk                (0x1UL << I2C_SR1_RXNE_Pos)        /*!< 0x00000040 */
#define I2C_SR1_RXNE                    I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                 (7U)
#define I2C_SR1_TXE_Msk                 (0x1UL << I2C_SR1_TXE_Pos)         /*!< 0x00000080 */
#define I2C_SR1_TXE                     I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                (8U)
#define I2C_SR1_BERR_Msk                (0x1UL << I2C_SR1_BERR_Pos)        /*!< 0x00000100 */
#define I2C_SR1_BERR                    I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                (9U)
#define I2C_SR1_ARLO_Msk                (0x1UL << I2C_SR1_ARLO_Pos)        /*!< 0x00000200 */
#define I2C_SR1_ARLO                    I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                  (10U)
#define I2C_SR1_AF_Msk                  (0x1UL << I2C_SR1_AF_Pos)          /*!< 0x00000400 */
#define I2C_SR1_AF                      I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                 (11U)
#define I2C_SR1_OVR_Msk                 (0x1UL << I2C_SR1_OVR_Pos)         /*!< 0x00000800 */
#define I2C_SR1_OVR                     I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                 (0U)
#define I2C_SR2_MSL_Msk                 (0x1UL << I2C_SR2_MSL_Pos)         /*!< 0x00000001 */
#define I2C_SR2_MSL                     I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                (1U)
#define I2C_SR2_BUSY_Msk                (0x1UL << I2C_SR2_BUSY_Pos)        /*!< 0x00000002 */
#define I2C_SR2_BUSY                    I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                 (2U)
#define I2C_SR2_TRA_Msk                 (0x1UL << I2C_SR2_TRA_Pos)         /*!< 0x00000004 */
#define I2C_SR2_TRA                     I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_SBUSY_Pos               (3U)
#define I2C_SR2_SBUSY_Msk               (0x1UL << I2C_SR2_SBUSY_Pos)       /*!< 0x00000004 */
#define I2C_SR2_SBUSY                   I2C_SR2_SBUSY_Msk                  /*!< Slave Busy */
#define I2C_SR2_GENCALL_Pos             (4U)
#define I2C_SR2_GENCALL_Msk             (0x1UL << I2C_SR2_GENCALL_Pos)     /*!< 0x00000010 */
#define I2C_SR2_GENCALL                 I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */

/*******************  Bit definition for I2C_CCR register  ********************/
#define I2C_CCR_CCR_Pos                 (0U)
#define I2C_CCR_CCR_Msk                 (0xFFFUL << I2C_CCR_CCR_Pos)       /*!< 0x00000FFF */
#define I2C_CCR_CCR                     I2C_CCR_CCR_Msk                    /*!< Clock Control Register in Fast/Standard mode (Master mode) */
#define I2C_CCR_DUTY_Pos                (14U)
#define I2C_CCR_DUTY_Msk                (0x1UL << I2C_CCR_DUTY_Pos)        /*!< 0x00004000 */
#define I2C_CCR_DUTY                    I2C_CCR_DUTY_Msk                   /*!< Fast Mode Duty Cycle */
#define I2C_CCR_FS_Pos                  (15U)
#define I2C_CCR_FS_Msk                  (0x1UL << I2C_CCR_FS_Pos)          /*!< 0x00008000 */
#define I2C_CCR_FS                      I2C_CCR_FS_Msk                     /*!< I2C Master Mode Selection */

/******************  Bit definition for I2C_TRISE register  *******************/
#define I2C_TRISE_TRISE_Pos             (0U)
#define I2C_TRISE_TRISE_Msk             (0x3FUL << I2C_TRISE_TRISE_Pos)    /*!< 0x0000003F */
#define I2C_TRISE_TRISE                 I2C_TRISE_TRISE_Msk                /*!< Maximum Rise Time in Fast/Standard mode (Master mode) */

/******************************************************************************/
/*                                                                            */
/*                        Independent WATCHDOG (IWDG)                         */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY_Pos                 (0U)
#define IWDG_KR_KEY_Msk                 (0xFFFFUL << IWDG_KR_KEY_Pos)      /*!< 0x0000FFFF */
#define IWDG_KR_KEY                     IWDG_KR_KEY_Msk                    /*!<Key value (write only, read 0000h)  */

/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR_Pos                  (0U)
#define IWDG_PR_PR_Msk                  (0x7UL << IWDG_PR_PR_Pos)          /*!< 0x00000007 */
#define IWDG_PR_PR                      IWDG_PR_PR_Msk                     /*!<PR[2:0] (Prescaler divider) */
#define IWDG_PR_PR_0                    (0x1UL << IWDG_PR_PR_Pos)          /*!< 0x00000001 */
#define IWDG_PR_PR_1                    (0x2UL << IWDG_PR_PR_Pos)          /*!< 0x00000002 */
#define IWDG_PR_PR_2                    (0x4UL << IWDG_PR_PR_Pos)          /*!< 0x00000004 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL_Pos                 (0U)
#define IWDG_RLR_RL_Msk                 (0xFFFUL << IWDG_RLR_RL_Pos)       /*!< 0x00000FFF */
#define IWDG_RLR_RL                     IWDG_RLR_RL_Msk                    /*!<Watchdog counter reload value        */

/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU_Pos                 (0U)
#define IWDG_SR_PVU_Msk                 (0x1UL << IWDG_SR_PVU_Pos)         /*!< 0x00000001 */
#define IWDG_SR_PVU                     IWDG_SR_PVU_Msk                    /*!< Watchdog prescaler value update */
#define IWDG_SR_RVU_Pos                 (1U)
#define IWDG_SR_RVU_Msk                 (0x1UL << IWDG_SR_RVU_Pos)         /*!< 0x00000002 */
#define IWDG_SR_RVU                     IWDG_SR_RVU_Msk                    /*!< Watchdog counter reload value update */

/********************************************************************************************************************/
/********************************* OPA ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for OPA_OCR register *********************************************/
#define OPA_OCR_OPA_EXTOEN_Pos                  (0U)
#define OPA_OCR_OPA_EXTOEN_Msk                  (0x1UL<<OPA_OCR_OPA_EXTOEN_Pos)                 /*!< 0x00000001 */
#define OPA_OCR_OPA_EXTOEN                      OPA_OCR_OPA_EXTOEN_Msk                          
#define OPA_OCR_OPA_VBIAS_Pos                    (3U)
#define OPA_OCR_OPA_VBIAS_Msk                    (0x3UL<<OPA_OCR_OPA_VBIAS_Pos)                   /*!< 0x00000018 */
#define OPA_OCR_OPA_VBIAS                        OPA_OCR_OPA_VBIAS_Msk
#define OPA_OCR_OPA_VBIAS_0                      (0x1UL<<OPA_OCR_OPA_VBIAS_Pos)                   /*!< 0x00000008 */
#define OPA_OCR_OPA_VBIAS_1                      (0x2UL<<OPA_OCR_OPA_VBIAS_Pos)                   /*!< 0x00000010 */
#define OPA_OCR_OPA_VMSEL_Pos                   (5U)
#define OPA_OCR_OPA_VMSEL_Msk                   (0x3UL<<OPA_OCR_OPA_VMSEL_Pos)                  /*!< 0x00000060 */
#define OPA_OCR_OPA_VMSEL                       OPA_OCR_OPA_VMSEL_Msk
#define OPA_OCR_OPA_VMSEL_0                     (0x1UL<<OPA_OCR_OPA_VMSEL_Pos)                  /*!< 0x00000020 */
#define OPA_OCR_OPA_VMSEL_1                     (0x2UL<<OPA_OCR_OPA_VMSEL_Pos)                  /*!< 0x00000040 */
#define OPA_OCR_OPA_VBSEL_Pos                   (7U)
#define OPA_OCR_OPA_VBSEL_Msk                   (0x1UL<<OPA_OCR_OPA_VBSEL_Pos)                  /*!< 0x00000080 */
#define OPA_OCR_OPA_VBSEL                       OPA_OCR_OPA_VBSEL_Msk                           
#define OPA_OCR_OPA_PGA_GAIN_Pos                (8U)
#define OPA_OCR_OPA_PGA_GAIN_Msk                (0xFUL<<OPA_OCR_OPA_PGA_GAIN_Pos)               /*!< 0x00000F00 */
#define OPA_OCR_OPA_PGA_GAIN                    OPA_OCR_OPA_PGA_GAIN_Msk
#define OPA_OCR_OPA_PGA_GAIN_0                  (0x1UL<<OPA_OCR_OPA_PGA_GAIN_Pos)               /*!< 0x00000100 */
#define OPA_OCR_OPA_PGA_GAIN_1                  (0x2UL<<OPA_OCR_OPA_PGA_GAIN_Pos)               /*!< 0x00000200 */
#define OPA_OCR_OPA_PGA_GAIN_2                  (0x4UL<<OPA_OCR_OPA_PGA_GAIN_Pos)               /*!< 0x00000400 */
#define OPA_OCR_OPA_PGA_GAIN_3                  (0x8UL<<OPA_OCR_OPA_PGA_GAIN_Pos)               /*!< 0x00000800 */

#define OPA_OCR_OPA_ADC_SWAP_EN_Pos             (16U)
#define OPA_OCR_OPA_ADC_SWAP_EN_Msk             (0x1UL<<OPA_OCR_OPA_ADC_SWAP_EN_Pos)               /*!< 0x00000100 */
#define OPA_OCR_OPA_ADC_SWAP_EN                 OPA_OCR_OPA_ADC_SWAP_EN_Msk  
#define OPA_OCR_OPA_SWAP_Pos                    (17U)
#define OPA_OCR_OPA_SWAP_Msk                    (0x1UL<<OPA_OCR_OPA_SWAP_Pos)                      /*!< 0x00000200 */
#define OPA_OCR_OPA_SWAP                        OPA_OCR_OPA_SWAP_Msk                           
#define OPA_OCR_OPA_ADC_TRG_SEL_Pos             (18U)
#define OPA_OCR_OPA_ADC_TRG_SEL_Msk             (0x3UL<<OPA_OCR_OPA_ADC_TRG_SEL_Pos)               /*!< 0x00000C00 */
#define OPA_OCR_OPA_ADC_TRG_SEL                 OPA_OCR_OPA_ADC_TRG_SEL_Msk
#define OPA_OCR_OPA_ADC_TRG_SEL_0               (0x1UL<<OPA_OCR_OPA_ADC_TRG_SEL_Pos)               /*!< 0x00000400 */
#define OPA_OCR_OPA_ADC_TRG_SEL_1               (0x2UL<<OPA_OCR_OPA_ADC_TRG_SEL_Pos)               /*!< 0x00000800 */



/********************************* Bit definition for OPA_CR register **********************************************/
#define OPA_CR_OPAEN_Pos                        (5U)
#define OPA_CR_OPAEN_Msk                        (0x1UL<<OPA_CR_OPAEN_Pos)                       /*!< 0x00000020 */
#define OPA_CR_OPAEN                            OPA_CR_OPAEN_Msk                                

/******************************************************************************/
/*                                                                            */
/*                        Power Control (PWR)                                 */
/*                                                                            */
/******************************************************************************/

/********************************* Bit definition for PWR_CR1 register **********************************************/
#define PWR_CR1_FLS_SLPTIME_Pos                   (12U)
#define PWR_CR1_FLS_SLPTIME_Msk                   (0x3UL<<PWR_CR1_FLS_SLPTIME_Pos)                  /*!< 0x00003000 */
#define PWR_CR1_FLS_SLPTIME                       PWR_CR1_FLS_SLPTIME_Msk
#define PWR_CR1_FLS_SLPTIME_0                     (0x1UL<<PWR_CR1_FLS_SLPTIME_Pos)                  /*!< 0x00001000 */
#define PWR_CR1_FLS_SLPTIME_1                     (0x2UL<<PWR_CR1_FLS_SLPTIME_Pos)                  /*!< 0x00002000 */
#define PWR_CR1_VR_MODE_Pos                       (14U)
#define PWR_CR1_VR_MODE_Msk                       (0x3UL<<PWR_CR1_VR_MODE_Pos)                      /*!< 0x000C0000 */
#define PWR_CR1_VR_MODE                           PWR_CR1_VR_MODE_Msk
#define PWR_CR1_VR_MODE_0                         (0x1UL<<PWR_CR1_VR_MODE_Pos)                      /*!< 0x00040000 */
#define PWR_CR1_VR_MODE_1                         (0x2UL<<PWR_CR1_VR_MODE_Pos)                      /*!< 0x00080000 */
#define PWR_CR1_HSION_CTRL_Pos                    (22U)
#define PWR_CR1_HSION_CTRL_Msk                    (0x1UL<<PWR_CR1_HSION_CTRL_Pos)                   /*!< 0x00400000 */
#define PWR_CR1_HSION_CTRL                        PWR_CR1_HSION_CTRL_Msk                            

/********************************* Bit definition for PWR_CR2 register **********************************************/
#define PWR_CR2_PVDE_Pos                          (0U)
#define PWR_CR2_PVDE_Msk                          (0x1UL<<PWR_CR2_PVDE_Pos)                         /*!< 0x00000001 */
#define PWR_CR2_PVDE                              PWR_CR2_PVDE_Msk                                  
#define PWR_CR2_PVDT_Pos                          (4U)
#define PWR_CR2_PVDT_Msk                          (0x7UL<<PWR_CR2_PVDT_Pos)                         /*!< 0x00000070 */
#define PWR_CR2_PVDT                              PWR_CR2_PVDT_Msk
#define PWR_CR2_PVDT_0                            (0x1UL<<PWR_CR2_PVDT_Pos)                         /*!< 0x00000010 */
#define PWR_CR2_PVDT_1                            (0x2UL<<PWR_CR2_PVDT_Pos)                         /*!< 0x00000020 */
#define PWR_CR2_PVDT_2                            (0x4UL<<PWR_CR2_PVDT_Pos)                         /*!< 0x00000040 */
#define PWR_CR2_PVD_OUT_SEL_Pos                   (8U)
#define PWR_CR2_PVD_OUT_SEL_Msk                   (0x1UL<<PWR_CR2_PVD_OUT_SEL_Pos)                  /*!< 0x00000800 */
#define PWR_CR2_PVD_OUT_SEL                       PWR_CR2_PVD_OUT_SEL_Msk      
#define PWR_CR2_FLTEN_Pos                         (8U)
#define PWR_CR2_FLTEN_Msk                         (0x1UL<<PWR_CR2_FLTEN_Pos)                        /*!< 0x00000100 */
#define PWR_CR2_FLTEN                             PWR_CR2_FLTEN_Msk                                 
#define PWR_CR2_FLT_TIME_Pos                      (9U)
#define PWR_CR2_FLT_TIME_Msk                      (0x7UL<<PWR_CR2_FLT_TIME_Pos)                     /*!< 0x00000E00 */
#define PWR_CR2_FLT_TIME                          PWR_CR2_FLT_TIME_Msk
#define PWR_CR2_FLT_TIME_0                        (0x1UL<<PWR_CR2_FLT_TIME_Pos)                     /*!< 0x00000200 */
#define PWR_CR2_FLT_TIME_1                        (0x2UL<<PWR_CR2_FLT_TIME_Pos)                     /*!< 0x00000400 */
#define PWR_CR2_FLT_TIME_2                        (0x4UL<<PWR_CR2_FLT_TIME_Pos)                     /*!< 0x00000800 */

/********************************* Bit definition for PWR_SR register ***********************************************/
#define PWR_SR_PVDO_Pos                           (11U)
#define PWR_SR_PVDO_Msk                           (0x1UL<<PWR_SR_PVDO_Pos)                          /*!< 0x00000800 */
#define PWR_SR_PVDO                               PWR_SR_PVDO_Msk                                   

/******************************************************************************/
/*                                                                            */
/*                           Reset and Clock Control (RCC)                    */
/*                                                                            */
/******************************************************************************/
/*
* @brief Specific device feature definitions
*/
#define RCC_LSE_SUPPORT
#define RCC_HSE_SUPPORT

/********************  Bit definition for RCC_CR register  *****************/
#define RCC_CR_HSION_Pos                (8U)
#define RCC_CR_HSION_Msk                (0x1UL << RCC_CR_HSION_Pos)                 /*!< 0x00000100 */
#define RCC_CR_HSION                    RCC_CR_HSION_Msk                            /*!< HSI clock enable bit */
#define RCC_CR_HSIRDY_Pos               (10U)
#define RCC_CR_HSIRDY_Msk               (0x1UL << RCC_CR_HSIRDY_Pos)                /*!< 0x00000400 */
#define RCC_CR_HSIRDY                   RCC_CR_HSIRDY_Msk                           /*!< HSI clock ready logo */
#define RCC_CR_HSIDIV_Pos               (11U)
#define RCC_CR_HSIDIV_Msk               (0x7UL << RCC_CR_HSIDIV_Pos)                /*!< 0x00003800 */
#define RCC_CR_HSIDIV                   RCC_CR_HSIDIV_Msk                           /*!< HSI generates the crossover factor when HSISYS clocks */
#define RCC_CR_HSIDIV_0                 (0x1UL << RCC_CR_HSIDIV_Pos)                /*!< 0x00000800 */
#define RCC_CR_HSIDIV_1                 (0x2UL << RCC_CR_HSIDIV_Pos)                /*!< 0x00001000 */
#define RCC_CR_HSIDIV_2                 (0x4UL << RCC_CR_HSIDIV_Pos)                /*!< 0x00002000 */
#define RCC_CR_HSEON_Pos                (18U)
#define RCC_CR_HSEON_Msk                (0x1UL << RCC_CR_HSEON_Pos)                 /*!< 0x00040000 */
#define RCC_CR_HSEON                    RCC_CR_HSEON_Msk

/********************  Bit definition for RCC_ICSCR register  ***************/
#define RCC_ICSCR_HSI_ABS_TRIMCR_Pos    (0U)
#define RCC_ICSCR_HSI_ABS_TRIMCR_Msk    (0xFFFUL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)   /*!< 0x00000FFF */
#define RCC_ICSCR_HSI_ABS_TRIMCR        RCC_ICSCR_HSI_ABS_TRIMCR_Msk                /*!< HSITRIM[11:0] bits */
#define RCC_ICSCR_HSI_ABS_TRIMCR_0      (0x01UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)    /*!< 0x00000001 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_1      (0x02UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)    /*!< 0x00000002 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_2      (0x04UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)    /*!< 0x00000004 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_3      (0x08UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)    /*!< 0x00000008 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_4      (0x10UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)    /*!< 0x00000010 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_5      (0x20UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)    /*!< 0x00000020 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_6      (0x40UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)    /*!< 0x00000040 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_7      (0x80UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)    /*!< 0x00000080 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_8      (0x100UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)   /*!< 0x00000100 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_9      (0x200UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)   /*!< 0x00000200 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_10     (0x400UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)   /*!< 0x00000400 */
#define RCC_ICSCR_HSI_ABS_TRIMCR_11     (0x800UL << RCC_ICSCR_HSI_ABS_TRIMCR_Pos)   /*!< 0x00000800 */
#define RCC_ICSCR_HSI_TC_TRIMCR_Pos     (12U)                                     
#define RCC_ICSCR_HSI_TC_TRIMCR_Msk     (0xFUL << RCC_ICSCR_HSI_TC_TRIMCR_Pos)      /*!< 0x0000F000 */
#define RCC_ICSCR_HSI_TC_TRIMCR         RCC_ICSCR_HSI_TC_TRIMCR_Msk                 /*!< HSIFS[15:12] bits */
#define RCC_ICSCR_HSI_TC_TRIMCR_0       (0x01UL << RCC_ICSCR_HSI_TC_TRIMCR_Pos)     /*!< 0x00001000 */
#define RCC_ICSCR_HSI_TC_TRIMCR_1       (0x02UL << RCC_ICSCR_HSI_TC_TRIMCR_Pos)     /*!< 0x00002000 */
#define RCC_ICSCR_HSI_TC_TRIMCR_2       (0x04UL << RCC_ICSCR_HSI_TC_TRIMCR_Pos)     /*!< 0x00004000 */
#define RCC_ICSCR_HSI_TC_TRIMCR_3       (0x04UL << RCC_ICSCR_HSI_TC_TRIMCR_Pos)     /*!< 0x00008000 */
#define RCC_ICSCR_HSI_FS_CR_Pos         (16U)
#define RCC_ICSCR_HSI_FS_CR_Msk         (0x3UL << RCC_ICSCR_HSI_FS_CR_Pos)
#define RCC_ICSCR_HSI_FS_CR             RCC_ICSCR_HSI_FS_CR_Msk
#define RCC_ICSCR_HSI_FS_CR_0           (0x01UL << RCC_ICSCR_HSI_FS_CR_Pos)
#define RCC_ICSCR_HSI_FS_CR_1           (0x02UL << RCC_ICSCR_HSI_FS_CR_Pos)
#define RCC_ICSCR_LSI_TRIM_Pos          (19U)
#define RCC_ICSCR_LSI_TRIM_Msk          (0x1FFUL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM              RCC_ICSCR_LSI_TRIM_Msk
#define RCC_ICSCR_LSI_TRIM_0            (0x01UL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM_1            (0x02UL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM_2            (0x04UL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM_3            (0x08UL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM_4            (0x10UL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM_5            (0x20UL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM_6            (0x40UL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM_7            (0x80UL << RCC_ICSCR_LSI_TRIM_Pos)
#define RCC_ICSCR_LSI_TRIM_8            (0x100UL << RCC_ICSCR_LSI_TRIM_Pos)

/********************  Bit definition for RCC_CFGR register  ***************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos                 (0U)
#define RCC_CFGR_SW_Msk                 (0x7UL << RCC_CFGR_SW_Pos)             /*!< 0x00000007 */
#define RCC_CFGR_SW                     RCC_CFGR_SW_Msk                        /*!< SW[2:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0                   (0x1UL << RCC_CFGR_SW_Pos)             /*!< 0x00000001 */
#define RCC_CFGR_SW_1                   (0x2UL << RCC_CFGR_SW_Pos)             /*!< 0x00000002 */
#define RCC_CFGR_SW_2                   (0x4UL << RCC_CFGR_SW_Pos)             /*!< 0x00000004 */

#define RCC_CFGR_SW_HSISYS              (0UL)                                  /*!< HSISYS used as system clock */
#define RCC_CFGR_SW_HSE                 (0x00000001UL)                         /*!< HSE used as system clock */
#define RCC_CFGR_SW_LSI                 (0x00000003UL)                         /*!< LSI used as system clock */
#define RCC_CFGR_SW_LSE                 (0x00000004UL)                         /*!< LSE used as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos                (3U)
#define RCC_CFGR_SWS_Msk                (0x7UL << RCC_CFGR_SWS_Pos)            /*!< 0x00000038 */
#define RCC_CFGR_SWS                    RCC_CFGR_SWS_Msk                       /*!< SWS[2:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0                  (0x1UL << RCC_CFGR_SWS_Pos)            /*!< 0x00000008 */
#define RCC_CFGR_SWS_1                  (0x2UL << RCC_CFGR_SWS_Pos)            /*!< 0x00000010 */
#define RCC_CFGR_SWS_2                  (0x4UL << RCC_CFGR_SWS_Pos)            /*!< 0x00000020 */

#define RCC_CFGR_SWS_HSISYS             (0UL)                                  /*!< HSISYS used as system clock */
#define RCC_CFGR_SWS_HSE                (0x00000008UL)                         /*!< HSE used as system clock */
#define RCC_CFGR_SWS_LSI                (0x00000018UL)                         /*!< LSI used as system clock */
#define RCC_CFGR_SWS_LSE                (0x00000020UL)                         /*!< LSE used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos               (8U)
#define RCC_CFGR_HPRE_Msk               (0xFUL << RCC_CFGR_HPRE_Pos)           /*!< 0x00000F00 */
#define RCC_CFGR_HPRE                   RCC_CFGR_HPRE_Msk                      /*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0                 (0x1UL << RCC_CFGR_HPRE_Pos)           /*!< 0x00000100 */
#define RCC_CFGR_HPRE_1                 (0x2UL << RCC_CFGR_HPRE_Pos)           /*!< 0x00000200 */
#define RCC_CFGR_HPRE_2                 (0x4UL << RCC_CFGR_HPRE_Pos)           /*!< 0x00000400 */
#define RCC_CFGR_HPRE_3                 (0x8UL << RCC_CFGR_HPRE_Pos)           /*!< 0x00000800 */

/*!< PPRE configuration */
#define RCC_CFGR_PPRE_Pos               (12U)
#define RCC_CFGR_PPRE_Msk               (0x7UL << RCC_CFGR_PPRE_Pos)           /*!< 0x00007000 */
#define RCC_CFGR_PPRE                   RCC_CFGR_PPRE_Msk                      /*!< PRE1[2:0] bits (APB prescaler) */
#define RCC_CFGR_PPRE_0                 (0x1UL << RCC_CFGR_PPRE_Pos)           /*!< 0x00001000 */
#define RCC_CFGR_PPRE_1                 (0x2UL << RCC_CFGR_PPRE_Pos)           /*!< 0x00002000 */
#define RCC_CFGR_PPRE_2                 (0x4UL << RCC_CFGR_PPRE_Pos)           /*!< 0x00004000 */

/*!< MCOSEL configuration */
#define RCC_CFGR_MCOSEL_Pos             (24U)
#define RCC_CFGR_MCOSEL_Msk             (0x7UL << RCC_CFGR_MCOSEL_Pos)         /*!< 0x0F000000 */
#define RCC_CFGR_MCOSEL                 RCC_CFGR_MCOSEL_Msk                    /*!< MCOSEL [2:0] bits (Clock output selection) */
#define RCC_CFGR_MCOSEL_0               (0x1UL << RCC_CFGR_MCOSEL_Pos)         /*!< 0x01000000 */
#define RCC_CFGR_MCOSEL_1               (0x2UL << RCC_CFGR_MCOSEL_Pos)         /*!< 0x02000000 */
#define RCC_CFGR_MCOSEL_2               (0x4UL << RCC_CFGR_MCOSEL_Pos)         /*!< 0x04000000 */

/*!< MCO Prescaler configuration */
#define RCC_CFGR_MCOPRE_Pos             (28U)
#define RCC_CFGR_MCOPRE_Msk             (0x7UL << RCC_CFGR_MCOPRE_Pos)         /*!< 0x70000000 */
#define RCC_CFGR_MCOPRE                 RCC_CFGR_MCOPRE_Msk                    /*!< MCO prescaler [2:0] */
#define RCC_CFGR_MCOPRE_0               (0x1UL << RCC_CFGR_MCOPRE_Pos)         /*!< 0x10000000 */
#define RCC_CFGR_MCOPRE_1               (0x2UL << RCC_CFGR_MCOPRE_Pos)         /*!< 0x20000000 */
#define RCC_CFGR_MCOPRE_2               (0x4UL << RCC_CFGR_MCOPRE_Pos)         /*!< 0x40000000 */

/********************  Bit definition for RCC_ECSCR register  ***************/
/*!< LSE FREQ configuration */
#define RCC_ECSCR_HSE_DRV_Pos           (0U)
#define RCC_ECSCR_HSE_DRV_Msk           (0x1UL << RCC_ECSCR_HSE_DRV_Pos)       /*!< 0x00000001 */
#define RCC_ECSCR_HSE_DRV               RCC_ECSCR_HSE_DRV_Msk                
#define RCC_ECSCR_HSE_RDYSEL_Pos        (2U)                                 
#define RCC_ECSCR_HSE_RDYSEL_Msk        (0x3UL << RCC_ECSCR_HSE_RDYSEL_Pos)    /*!< 0x0000000C */
#define RCC_ECSCR_HSE_RDYSEL            RCC_ECSCR_HSE_RDYSEL_Msk             
#define RCC_ECSCR_HSE_RDYSEL_0          (0x1UL << RCC_ECSCR_HSE_RDYSEL_Pos)    /*!< 0x00000004 */
#define RCC_ECSCR_HSE_RDYSEL_1          (0x2UL << RCC_ECSCR_HSE_RDYSEL_Pos)    /*!< 0x00000008 */
#define RCC_ECSCR_HSE_FILT_ENB_Pos      (4U)                                 
#define RCC_ECSCR_HSE_FILT_ENB_Msk      (0x1UL << RCC_ECSCR_HSE_FILT_ENB_Pos)  /*!< 0x00000010 */
#define RCC_ECSCR_HSE_FILT_ENB          RCC_ECSCR_HSE_FILT_ENB_Msk        
#define RCC_ECSCR_LSE_DRIVER_Pos        (16U)
#define RCC_ECSCR_LSE_DRIVER_Msk        (3UL << RCC_ECSCR_LSE_DRIVER_Pos)      /*!< 0x00030000 */
#define RCC_ECSCR_LSE_DRIVER            RCC_ECSCR_LSE_DRIVER_Msk
#define RCC_ECSCR_LSE_DRIVER_0          (0x1UL << RCC_ECSCR_LSE_DRIVER_Pos)    /*!< 0x00010000 */
#define RCC_ECSCR_LSE_DRIVER_1          (0x2UL << RCC_ECSCR_LSE_DRIVER_Pos)    /*!< 0x00020000 */
#define RCC_ECSCR_LSE_STARTUP_Pos       (20U)
#define RCC_ECSCR_LSE_STARTUP_Msk       (3UL << RCC_ECSCR_LSE_STARTUP_Pos)     /*!< 0x00300000 */
#define RCC_ECSCR_LSE_STARTUP           RCC_ECSCR_LSE_STARTUP_Msk
#define RCC_ECSCR_LSE_STARTUP_0         (0x1UL << RCC_ECSCR_LSE_STARTUP_Pos)   /*!< 0x00100000 */
#define RCC_ECSCR_LSE_STARTUP_1         (0x2UL << RCC_ECSCR_LSE_STARTUP_Pos)   /*!< 0x00200000 */

/********************  Bit definition for RCC_CIER register  ******************/
#define RCC_CIER_LSIRDYIE_Pos           (0U)
#define RCC_CIER_LSIRDYIE_Msk           (0x1UL << RCC_CIER_LSIRDYIE_Pos)       /*!< 0x00000001 */
#define RCC_CIER_LSIRDYIE               RCC_CIER_LSIRDYIE_Msk
#define RCC_CIER_LSERDYIE_Pos           (1U)
#define RCC_CIER_LSERDYIE_Msk           (0x1UL << RCC_CIER_LSERDYIE_Pos)       /*!< 0x00000002 */
#define RCC_CIER_LSERDYIE               RCC_CIER_LSERDYIE_Msk
#define RCC_CIER_HSIRDYIE_Pos           (3U)
#define RCC_CIER_HSIRDYIE_Msk           (0x1UL << RCC_CIER_HSIRDYIE_Pos)       /*!< 0x00000008 */
#define RCC_CIER_HSIRDYIE               RCC_CIER_HSIRDYIE_Msk
#define RCC_CIER_HSERDYIE_Pos           (4U)
#define RCC_CIER_HSERDYIE_Msk           (0x1UL << RCC_CIER_HSERDYIE_Pos)       /*!< 0x00000010 */
#define RCC_CIER_HSERDYIE               RCC_CIER_HSERDYIE_Msk

/********************  Bit definition for RCC_CIFR register  ******************/
#define RCC_CIFR_LSIRDYF_Pos            (0U)
#define RCC_CIFR_LSIRDYF_Msk            (0x1UL << RCC_CIFR_LSIRDYF_Pos)        /*!< 0x00000001 */
#define RCC_CIFR_LSIRDYF                RCC_CIFR_LSIRDYF_Msk
#define RCC_CIFR_LSERDYF_Pos            (1U)
#define RCC_CIFR_LSERDYF_Msk            (0x1UL << RCC_CIFR_LSERDYF_Pos)        /*!< 0x00000002 */
#define RCC_CIFR_LSERDYF                RCC_CIFR_LSERDYF_Msk
#define RCC_CIFR_HSIRDYF_Pos            (3U)
#define RCC_CIFR_HSIRDYF_Msk            (0x1UL << RCC_CIFR_HSIRDYF_Pos)        /*!< 0x00000008 */
#define RCC_CIFR_HSIRDYF                RCC_CIFR_HSIRDYF_Msk
#define RCC_CIFR_HSERDYF_Pos            (4U)
#define RCC_CIFR_HSERDYF_Msk            (0x1UL<<RCC_CIFR_HSERDYF_Pos)          /*!< 0x00000010 */
#define RCC_CIFR_HSERDYF                RCC_CIFR_HSERDYF_Msk
#define RCC_CIFR_CSSF_Pos               (8U)
#define RCC_CIFR_CSSF_Msk               (0x1UL<<RCC_CIFR_CSSF_Pos)             /*!< 0x00000100 */
#define RCC_CIFR_CSSF                   RCC_CIFR_CSSF_Msk
#define RCC_CIFR_LSECSSF_Pos            (9U)
#define RCC_CIFR_LSECSSF_Msk            (0x1UL << RCC_CIFR_LSECSSF_Pos)        /*!< 0x00000200 */
#define RCC_CIFR_LSECSSF                RCC_CIFR_LSECSSF_Msk

/********************  Bit definition for RCC_CICR register  ******************/
#define RCC_CICR_LSIRDYC_Pos            (0U)
#define RCC_CICR_LSIRDYC_Msk            (0x1UL << RCC_CICR_LSIRDYC_Pos)        /*!< 0x00000001 */
#define RCC_CICR_LSIRDYC                RCC_CICR_LSIRDYC_Msk
#define RCC_CICR_LSERDYC_Pos            (1U)
#define RCC_CICR_LSERDYC_Msk            (0x1UL << RCC_CICR_LSERDYC_Pos)        /*!< 0x00000002 */
#define RCC_CICR_LSERDYC                RCC_CICR_LSERDYC_Msk
#define RCC_CICR_HSIRDYC_Pos            (3U)
#define RCC_CICR_HSIRDYC_Msk            (0x1UL << RCC_CICR_HSIRDYC_Pos)        /*!< 0x00000008 */
#define RCC_CICR_HSIRDYC                RCC_CICR_HSIRDYC_Msk
#define RCC_CICR_HSERDYC_Pos            (4U)
#define RCC_CICR_HSERDYC_Msk            (0x1UL<<RCC_CICR_HSERDYC_Pos)          /*!< 0x00000010 */
#define RCC_CICR_HSERDYC                RCC_CICR_HSERDYC_Msk
#define RCC_CICR_CSSC_Pos               (8U)
#define RCC_CICR_CSSC_Msk               (0x1UL<<RCC_CICR_CSSC_Pos)             /*!< 0x00000100 */
#define RCC_CICR_CSSC                   RCC_CICR_CSSC_Msk
#define RCC_CICR_LSECSSC_Pos            (9U)
#define RCC_CICR_LSECSSC_Msk            (0x1UL << RCC_CICR_LSECSSC_Pos)        /*!< 0x00000200 */
#define RCC_CICR_LSECSSC                RCC_CICR_LSECSSC_Msk

/********************  Bit definition for RCC_IOPRSTR register  ****************/
#define RCC_IOPRSTR_GPIOARST_Pos        (0U)
#define RCC_IOPRSTR_GPIOARST_Msk        (0x1UL << RCC_IOPRSTR_GPIOARST_Pos)    /*!< 0x00000001 */
#define RCC_IOPRSTR_GPIOARST            RCC_IOPRSTR_GPIOARST_Msk
#define RCC_IOPRSTR_GPIOBRST_Pos        (1U)
#define RCC_IOPRSTR_GPIOBRST_Msk        (0x1UL << RCC_IOPRSTR_GPIOBRST_Pos)    /*!< 0x00000002 */
#define RCC_IOPRSTR_GPIOBRST            RCC_IOPRSTR_GPIOBRST_Msk
#define RCC_IOPRSTR_GPIOCRST_Pos        (2U)
#define RCC_IOPRSTR_GPIOCRST_Msk        (0x1UL << RCC_IOPRSTR_GPIOCRST_Pos)    /*!< 0x00000004 */
#define RCC_IOPRSTR_GPIOCRST            RCC_IOPRSTR_GPIOCRST_Msk
#define RCC_IOPRSTR_GPIODRST_Pos        (3U)
#define RCC_IOPRSTR_GPIODRST_Msk        (0x1UL << RCC_IOPRSTR_GPIODRST_Pos)    /*!< 0x00000008 */
#define RCC_IOPRSTR_GPIODRST            RCC_IOPRSTR_GPIODRST_Msk

/********************  Bit definition for RCC_AHBRSTR register  ***************/
#define RCC_AHBRSTR_CRCRST_Pos          (12U)
#define RCC_AHBRSTR_CRCRST_Msk          (0x1UL << RCC_AHBRSTR_CRCRST_Pos)      /*!< 0x00001000 */
#define RCC_AHBRSTR_CRCRST              RCC_AHBRSTR_CRCRST_Msk

/********************  Bit definition for RCC_APBRSTR1 register  **************/
#define RCC_APBRSTR1_UART1RST_Pos       (18U)
#define RCC_APBRSTR1_UART1RST_Msk       (0x1UL << RCC_APBRSTR1_UART1RST_Pos)    /*!< 0x00040000 */
#define RCC_APBRSTR1_UART1RST           RCC_APBRSTR1_UART1RST_Msk
#define RCC_APBRSTR1_I2C1RST_Pos        (21U)
#define RCC_APBRSTR1_I2C1RST_Msk        (0x1UL << RCC_APBRSTR1_I2C1RST_Pos)     /*!< 0x00200000 */
#define RCC_APBRSTR1_I2C1RST             RCC_APBRSTR1_I2C1RST_Msk
#define RCC_APBRSTR1_OPA1RST_Pos        (23U)
#define RCC_APBRSTR1_OPA1RST_Msk        (0x1UL << RCC_APBRSTR1_OPA1RST_Pos)     /*!< 0x00800000 */
#define RCC_APBRSTR1_OPA1RST            RCC_APBRSTR1_OPA1RST_Msk
#define RCC_APBRSTR1_DBGRST_Pos         (27U)
#define RCC_APBRSTR1_DBGRST_Msk         (0x1UL << RCC_APBRSTR1_DBGRST_Pos)     /*!< 0x08000000 */
#define RCC_APBRSTR1_DBGRST             RCC_APBRSTR1_DBGRST_Msk
#define RCC_APBRSTR1_PWRRST_Pos         (28U)
#define RCC_APBRSTR1_PWRRST_Msk         (0x1UL << RCC_APBRSTR1_PWRRST_Pos)     /*!< 0x10000000 */
#define RCC_APBRSTR1_PWRRST             RCC_APBRSTR1_PWRRST_Msk
#define RCC_APBRSTR1_LPTIM1RST_Pos      (31U)
#define RCC_APBRSTR1_LPTIM1RST_Msk      (0x1UL << RCC_APBRSTR1_LPTIM1RST_Pos)   /*!< 0x80000000 */
#define RCC_APBRSTR1_LPTIM1RST          RCC_APBRSTR1_LPTIM1RST_Msk

/********************  Bit definition for RCC_APBRSTR2 register  **************/
#define RCC_APBRSTR2_SYSCFGRST_Pos      (0U)
#define RCC_APBRSTR2_SYSCFGRST_Msk      (0x1UL << RCC_APBRSTR2_SYSCFGRST_Pos)  /*!< 0x00000001 */
#define RCC_APBRSTR2_SYSCFGRST          RCC_APBRSTR2_SYSCFGRST_Msk
#define RCC_APBRSTR2_PWMRST_Pos         (9U)
#define RCC_APBRSTR2_PWMRST_Msk         (0x1UL << RCC_APBRSTR2_PWMRST_Pos)     /*!< 0x00000200 */
#define RCC_APBRSTR2_PWMRST             RCC_APBRSTR2_PWMRST_Msk
#define RCC_APBRSTR2_TIM13RST_Pos       (10U)
#define RCC_APBRSTR2_TIM13RST_Msk       (0x1UL << RCC_APBRSTR2_TIM13RST_Pos)   /*!< 0x00000400 */
#define RCC_APBRSTR2_TIM13RST           RCC_APBRSTR2_TIM13RST_Msk
#define RCC_APBRSTR2_TIM1RST_Pos        (11U)
#define RCC_APBRSTR2_TIM1RST_Msk        (0x1UL << RCC_APBRSTR2_TIM1RST_Pos)    /*!< 0x00000800 */
#define RCC_APBRSTR2_TIM1RST            RCC_APBRSTR2_TIM1RST_Msk
#define RCC_APBRSTR2_SPI1RST_Pos        (12U)
#define RCC_APBRSTR2_SPI1RST_Msk        (0x1UL << RCC_APBRSTR2_SPI1RST_Pos)    /*!< 0x00001000 */
#define RCC_APBRSTR2_SPI1RST            RCC_APBRSTR2_SPI1RST_Msk
#define RCC_APBRSTR2_USART1RST_Pos      (14U)
#define RCC_APBRSTR2_USART1RST_Msk      (0x1UL << RCC_APBRSTR2_USART1RST_Pos)  /*!< 0x00004000 */
#define RCC_APBRSTR2_USART1RST          RCC_APBRSTR2_USART1RST_Msk
#define RCC_APBRSTR2_TIM14RST_Pos       (15U)
#define RCC_APBRSTR2_TIM14RST_Msk       (0x1UL << RCC_APBRSTR2_TIM14RST_Pos)   /*!< 0x00008000 */
#define RCC_APBRSTR2_TIM14RST           RCC_APBRSTR2_TIM14RST_Msk
#define RCC_APBRSTR2_ADC1RST_Pos        (20U)
#define RCC_APBRSTR2_ADC1RST_Msk        (0x1UL << RCC_APBRSTR2_ADC1RST_Pos)     /*!< 0x00100000 */
#define RCC_APBRSTR2_ADC1RST             RCC_APBRSTR2_ADC1RST_Msk
#define RCC_APBRSTR2_COMP1RST_Pos       (21U)
#define RCC_APBRSTR2_COMP1RST_Msk       (0x1UL << RCC_APBRSTR2_COMP1RST_Pos)   /*!< 0x00200000 */
#define RCC_APBRSTR2_COMP1RST           RCC_APBRSTR2_COMP1RST_Msk
#define RCC_APBRSTR2_COMP2RST_Pos       (22U)
#define RCC_APBRSTR2_COMP2RST_Msk       (0x1UL << RCC_APBRSTR2_COMP2RST_Pos)   /*!< 0x00400000 */
#define RCC_APBRSTR2_COMP2RST           RCC_APBRSTR2_COMP2RST_Msk
#define RCC_APBRSTR2_VREFBUFRST_Pos     (26U)
#define RCC_APBRSTR2_VREFBUFRST_Msk     (0x1UL << RCC_APBRSTR2_VREFBUFRST_Pos) /*!< 0x04000000 */
#define RCC_APBRSTR2_VREFBUFRST         RCC_APBRSTR2_VREFBUFRST_Msk

/********************  Bit definition for RCC_IOPENR register  ****************/
#define RCC_IOPENR_GPIOAEN_Pos          (0U)
#define RCC_IOPENR_GPIOAEN_Msk          (0x1UL << RCC_IOPENR_GPIOAEN_Pos)      /*!< 0x00000001 */
#define RCC_IOPENR_GPIOAEN              RCC_IOPENR_GPIOAEN_Msk
#define RCC_IOPENR_GPIOBEN_Pos          (1U)
#define RCC_IOPENR_GPIOBEN_Msk          (0x1UL << RCC_IOPENR_GPIOBEN_Pos)      /*!< 0x00000002 */
#define RCC_IOPENR_GPIOBEN              RCC_IOPENR_GPIOBEN_Msk
#define RCC_IOPENR_GPIOCEN_Pos          (2U)
#define RCC_IOPENR_GPIOCEN_Msk          (0x1UL << RCC_IOPENR_GPIOCEN_Pos)      /*!< 0x00000004 */
#define RCC_IOPENR_GPIOCEN              RCC_IOPENR_GPIOCEN_Msk
#define RCC_IOPENR_GPIODEN_Pos          (3U)
#define RCC_IOPENR_GPIODEN_Msk          (0x1UL << RCC_IOPENR_GPIODEN_Pos)      /*!< 0x00000008 */
#define RCC_IOPENR_GPIODEN              RCC_IOPENR_GPIODEN_Msk

/********************  Bit definition for RCC_AHBENR register  ****************/
#define RCC_AHBENR_FLASHEN_Pos          (8U)
#define RCC_AHBENR_FLASHEN_Msk          (0x1UL << RCC_AHBENR_FLASHEN_Pos)      /*!< 0x00000100 */
#define RCC_AHBENR_FLASHEN              RCC_AHBENR_FLASHEN_Msk
#define RCC_AHBENR_SRAMEN_Pos           (9U)
#define RCC_AHBENR_SRAMEN_Msk           (0x1UL << RCC_AHBENR_SRAMEN_Pos)       /*!< 0x00000100 */
#define RCC_AHBENR_SRAMEN               RCC_AHBENR_SRAMEN_Msk
#define RCC_AHBENR_CRCEN_Pos            (12U)
#define RCC_AHBENR_CRCEN_Msk            (0x1UL << RCC_AHBENR_CRCEN_Pos)        /*!< 0x00001000 */
#define RCC_AHBENR_CRCEN                RCC_AHBENR_CRCEN_Msk

/********************  Bit definition for RCC_APBENR1 register  ***************/
#define RCC_APBENR1_UART1EN_Pos         (18U)
#define RCC_APBENR1_UART1EN_Msk         (0x1UL << RCC_APBENR1_UART1EN_Pos)      /*!< 0x00040000 */
#define RCC_APBENR1_UART1EN             RCC_APBENR1_UART1EN_Msk
#define RCC_APBENR1_I2C1EN_Pos          (21U)
#define RCC_APBENR1_I2C1EN_Msk          (0x1UL << RCC_APBENR1_I2C1EN_Pos)       /*!< 0x00200000 */
#define RCC_APBENR1_I2C1EN              RCC_APBENR1_I2C1EN_Msk
#define RCC_APBENR1_OPA1EN_Pos          (23U)
#define RCC_APBENR1_OPA1EN_Msk          (0x1UL << RCC_APBENR1_OPA1EN_Pos)       /*!< 0x00800000 */
#define RCC_APBENR1_OPA1EN              RCC_APBENR1_OPA1EN_Msk
#define RCC_APBENR1_DBGEN_Pos           (27U)
#define RCC_APBENR1_DBGEN_Msk           (0x1UL << RCC_APBENR1_DBGEN_Pos)       /*!< 0x08000000 */
#define RCC_APBENR1_DBGEN               RCC_APBENR1_DBGEN_Msk
#define RCC_APBENR1_PWREN_Pos           (28U)
#define RCC_APBENR1_PWREN_Msk           (0x1UL << RCC_APBENR1_PWREN_Pos)       /*!< 0x10000000 */
#define RCC_APBENR1_PWREN               RCC_APBENR1_PWREN_Msk
#define RCC_APBENR1_LPTIM1EN_Pos        (31U)
#define RCC_APBENR1_LPTIM1EN_Msk        (0x1UL << RCC_APBENR1_LPTIM1EN_Pos)     /*!< 0x80000000 */
#define RCC_APBENR1_LPTIM1EN            RCC_APBENR1_LPTIM1EN_Msk

/********************  Bit definition for RCC_APBENR2 register  **************/
#define RCC_APBENR2_SYSCFGEN_Pos        (0U)
#define RCC_APBENR2_SYSCFGEN_Msk        (0x1UL << RCC_APBENR2_SYSCFGEN_Pos)    /*!< 0x00000001 */
#define RCC_APBENR2_SYSCFGEN            RCC_APBENR2_SYSCFGEN_Msk
#define RCC_APBENR2_PWM1EN_Pos          (9U)
#define RCC_APBENR2_PWM1EN_Msk          (0x1UL << RCC_APBENR2_PWM1EN_Pos)       /*!< 0x00000200 */
#define RCC_APBENR2_PWM1EN              RCC_APBENR2_PWM1EN_Msk
#define RCC_APBENR2_TIM13EN_Pos         (10U)
#define RCC_APBENR2_TIM13EN_Msk         (0x1UL << RCC_APBENR2_TIM13EN_Pos)     /*!< 0x00004000 */
#define RCC_APBENR2_TIM13EN             RCC_APBENR2_TIM13EN_Msk
#define RCC_APBENR2_TIM1EN_Pos          (11U)
#define RCC_APBENR2_TIM1EN_Msk          (0x1UL << RCC_APBENR2_TIM1EN_Pos)      /*!< 0x00000800 */
#define RCC_APBENR2_TIM1EN              RCC_APBENR2_TIM1EN_Msk
#define RCC_APBENR2_SPI1EN_Pos          (12U)
#define RCC_APBENR2_SPI1EN_Msk          (0x1UL << RCC_APBENR2_SPI1EN_Pos)      /*!< 0x00001000 */
#define RCC_APBENR2_SPI1EN              RCC_APBENR2_SPI1EN_Msk
#define RCC_APBENR2_USART1EN_Pos        (14U)
#define RCC_APBENR2_USART1EN_Msk        (0x1UL << RCC_APBENR2_USART1EN_Pos)    /*!< 0x00004000 */
#define RCC_APBENR2_USART1EN            RCC_APBENR2_USART1EN_Msk
#define RCC_APBENR2_TIM14EN_Pos         (15U)
#define RCC_APBENR2_TIM14EN_Msk         (0x1UL << RCC_APBENR2_TIM14EN_Pos)     /*!< 0x00008000 */
#define RCC_APBENR2_TIM14EN             RCC_APBENR2_TIM14EN_Msk
#define RCC_APBENR2_ADC1EN_Pos          (20U)
#define RCC_APBENR2_ADC1EN_Msk          (0x1UL << RCC_APBENR2_ADC1EN_Pos)       /*!< 0x00100000 */
#define RCC_APBENR2_ADC1EN              RCC_APBENR2_ADC1EN_Msk
#define RCC_APBENR2_COMP1EN_Pos         (21U)
#define RCC_APBENR2_COMP1EN_Msk         (0x1UL << RCC_APBENR2_COMP1EN_Pos)     /*!< 0x00200000 */
#define RCC_APBENR2_COMP1EN             RCC_APBENR2_COMP1EN_Msk
#define RCC_APBENR2_COMP2EN_Pos         (22U)
#define RCC_APBENR2_COMP2EN_Msk         (0x1UL << RCC_APBENR2_COMP2EN_Pos)     /*!< 0x00400000 */
#define RCC_APBENR2_COMP2EN             RCC_APBENR2_COMP2EN_Msk
#define RCC_APBENR2_VREFBUFEN_Pos       (26U)
#define RCC_APBENR2_VREFBUFEN_Msk       (0x1UL << RCC_APBENR2_VREFBUFEN_Pos)   /*!< 0x04000000 */
#define RCC_APBENR2_VREFBUFEN           RCC_APBENR2_VREFBUFEN_Msk

/********************  Bit definition for RCC_CCIPR register  ******************/
#define RCC_CCIPR_PVDSEL_Pos            (7U)
#define RCC_CCIPR_PVDSEL_Msk            (0x1UL<<RCC_CCIPR_PVDSEL_Pos)          /*!< 0x00000080 */
#define RCC_CCIPR_PVDSEL                RCC_CCIPR_PVDSEL_Msk
#define RCC_CCIPR_COMP1SEL_Pos          (8U)
#define RCC_CCIPR_COMP1SEL_Msk          (0x1UL << RCC_CCIPR_COMP1SEL_Pos)      /*!< 0x00000100 */
#define RCC_CCIPR_COMP1SEL              RCC_CCIPR_COMP1SEL_Msk
#define RCC_CCIPR_COMP2SEL_Pos          (9U)
#define RCC_CCIPR_COMP2SEL_Msk          (0x1UL << RCC_CCIPR_COMP2SEL_Pos)      /*!< 0x00000200 */
#define RCC_CCIPR_COMP2SEL              RCC_CCIPR_COMP2SEL_Msk
#define RCC_CCIPR_LPTIM1SEL_Pos          (18U)
#define RCC_CCIPR_LPTIM1SEL_Msk          (0x3UL << RCC_CCIPR_LPTIM1SEL_Pos)      /*!< 0x000C0000 */
#define RCC_CCIPR_LPTIM1SEL              RCC_CCIPR_LPTIM1SEL_Msk
#define RCC_CCIPR_LPTIM1SEL_0            (0x1UL << RCC_CCIPR_LPTIM1SEL_Pos)      /*!< 0x00040000 */
#define RCC_CCIPR_LPTIM1SEL_1            (0x2UL << RCC_CCIPR_LPTIM1SEL_Pos)      /*!< 0x00080000 */

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos              (0U)
#define RCC_BDCR_LSEON_Msk              (0x1UL << RCC_BDCR_LSEON_Pos)          /*!< 0x00000001 */
#define RCC_BDCR_LSEON                  RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos             (1U)
#define RCC_BDCR_LSERDY_Msk             (0x1UL << RCC_BDCR_LSERDY_Pos)         /*!< 0x00000002 */
#define RCC_BDCR_LSERDY                 RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos             (2U)
#define RCC_BDCR_LSEBYP_Msk             (0x1UL << RCC_BDCR_LSEBYP_Pos)         /*!< 0x00000004 */
#define RCC_BDCR_LSEBYP                 RCC_BDCR_LSEBYP_Msk
#define RCC_BDCR_LSECSSON_Pos           (5U)
#define RCC_BDCR_LSECSSON_Msk           (0x1UL << RCC_BDCR_LSECSSON_Pos)       /*!< 0x00000020 */
#define RCC_BDCR_LSECSSON               RCC_BDCR_LSECSSON_Msk
#define RCC_BDCR_LSECSSD_Pos            (6U)
#define RCC_BDCR_LSECSSD_Msk            (0x1UL << RCC_BDCR_LSECSSD_Pos)        /*!< 0x00000040 */
#define RCC_BDCR_LSECSSD                RCC_BDCR_LSECSSD_Msk
#define RCC_BDCR_LSCOSEL_Pos            (25U)
#define RCC_BDCR_LSCOSEL_Msk            (0x1UL << RCC_BDCR_LSCOSEL_Pos)        /*!< 0x02000000 */
#define RCC_BDCR_LSCOSEL                RCC_BDCR_LSCOSEL_Msk

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos               (0U)
#define RCC_CSR_LSION_Msk               (0x1UL << RCC_CSR_LSION_Pos)           /*!< 0x00000001 */
#define RCC_CSR_LSION                   RCC_CSR_LSION_Msk
#define RCC_CSR_LSIRDY_Pos              (1U)
#define RCC_CSR_LSIRDY_Msk              (0x1UL << RCC_CSR_LSIRDY_Pos)          /*!< 0x00000002 */
#define RCC_CSR_LSIRDY                  RCC_CSR_LSIRDY_Msk
#define RCC_CSR_NRST_FLTDIS_Pos         (8U)
#define RCC_CSR_NRST_FLTDIS_Msk         (0x1UL << RCC_CSR_NRST_FLTDIS_Pos)     /*!< 0x00000100 */
#define RCC_CSR_NRST_FLTDIS             RCC_CSR_NRST_FLTDIS_Msk
#define RCC_CSR_RMVF_Pos                (23U)
#define RCC_CSR_RMVF_Msk                (0x1UL << RCC_CSR_RMVF_Pos)            /*!< 0x00800000 */
#define RCC_CSR_RMVF                    RCC_CSR_RMVF_Msk
#define RCC_CSR_OBLRSTF_Pos             (25U)
#define RCC_CSR_OBLRSTF_Msk             (0x1UL << RCC_CSR_OBLRSTF_Pos)         /*!< 0x02000000 */
#define RCC_CSR_OBLRSTF                 RCC_CSR_OBLRSTF_Msk
#define RCC_CSR_PINRSTF_Pos             (26U)
#define RCC_CSR_PINRSTF_Msk             (0x1UL << RCC_CSR_PINRSTF_Pos)         /*!< 0x04000000 */
#define RCC_CSR_PINRSTF                 RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PWRRSTF_Pos             (27U)
#define RCC_CSR_PWRRSTF_Msk             (0x1UL << RCC_CSR_PWRRSTF_Pos)         /*!< 0x08000000 */
#define RCC_CSR_PWRRSTF                 RCC_CSR_PWRRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos             (28U)
#define RCC_CSR_SFTRSTF_Msk             (0x1UL << RCC_CSR_SFTRSTF_Pos)         /*!< 0x10000000 */
#define RCC_CSR_SFTRSTF                 RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos            (29U)
#define RCC_CSR_IWDGRSTF_Msk            (0x1UL << RCC_CSR_IWDGRSTF_Pos)        /*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF                RCC_CSR_IWDGRSTF_Msk

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface (SPI)                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CR1 register  ********************/
#define SPI_CR1_CPHA_Pos                (0U)
#define SPI_CR1_CPHA_Msk                (0x1UL << SPI_CR1_CPHA_Pos)            /*!< 0x00000001 */
#define SPI_CR1_CPHA                    SPI_CR1_CPHA_Msk                       /*!< Clock Phase */
#define SPI_CR1_CPOL_Pos                (1U)
#define SPI_CR1_CPOL_Msk                (0x1UL << SPI_CR1_CPOL_Pos)            /*!< 0x00000002 */
#define SPI_CR1_CPOL                    SPI_CR1_CPOL_Msk                       /*!< Clock Polarity */
#define SPI_CR1_MSTR_Pos                (2U)
#define SPI_CR1_MSTR_Msk                (0x1UL << SPI_CR1_MSTR_Pos)            /*!< 0x00000004 */
#define SPI_CR1_MSTR                    SPI_CR1_MSTR_Msk                       /*!< Master Selection */
#define SPI_CR1_BR_Pos                  (3U)
#define SPI_CR1_BR_Msk                  (0x7UL << SPI_CR1_BR_Pos)              /*!< 0x00000038 */
#define SPI_CR1_BR                      SPI_CR1_BR_Msk                         /*!< BR[2:0] bits (Baud Rate Control) */
#define SPI_CR1_BR_0                    (0x1UL << SPI_CR1_BR_Pos)              /*!< 0x00000008 */
#define SPI_CR1_BR_1                    (0x2UL << SPI_CR1_BR_Pos)              /*!< 0x00000010 */
#define SPI_CR1_BR_2                    (0x4UL << SPI_CR1_BR_Pos)              /*!< 0x00000020 */
#define SPI_CR1_SPE_Pos                 (6U)
#define SPI_CR1_SPE_Msk                 (0x1UL << SPI_CR1_SPE_Pos)             /*!< 0x00000040 */
#define SPI_CR1_SPE                     SPI_CR1_SPE_Msk                        /*!< SPI Enable */
#define SPI_CR1_LSBFIRST_Pos            (7U)
#define SPI_CR1_LSBFIRST_Msk            (0x1UL << SPI_CR1_LSBFIRST_Pos)        /*!< 0x00000080 */
#define SPI_CR1_LSBFIRST                SPI_CR1_LSBFIRST_Msk                   /*!< Frame Format */
#define SPI_CR1_SSI_Pos                 (8U)
#define SPI_CR1_SSI_Msk                 (0x1UL << SPI_CR1_SSI_Pos)             /*!< 0x00000100 */
#define SPI_CR1_SSI                     SPI_CR1_SSI_Msk                        /*!< Internal slave select */
#define SPI_CR1_SSM_Pos                 (9U)
#define SPI_CR1_SSM_Msk                 (0x1UL << SPI_CR1_SSM_Pos)             /*!< 0x00000200 */
#define SPI_CR1_SSM                     SPI_CR1_SSM_Msk                        /*!< Software slave management */
#define SPI_CR1_RXONLY_Pos              (10U)
#define SPI_CR1_RXONLY_Msk              (0x1UL << SPI_CR1_RXONLY_Pos)          /*!< 0x00000400 */
#define SPI_CR1_RXONLY                  SPI_CR1_RXONLY_Msk                     /*!< Receive only */
#define SPI_CR1_DFF_Pos                 (11U)
#define SPI_CR1_DFF_Msk                 (0x1UL << SPI_CR1_DFF_Pos)             /*!< 0x00000800 */
#define SPI_CR1_DFF                     SPI_CR1_DFF_Msk                        /*!< Data frame format */
#define SPI_CR1_BIDIOE_Pos              (14U)
#define SPI_CR1_BIDIOE_Msk              (0x1UL << SPI_CR1_BIDIOE_Pos)          /*!< 0x00004000 */
#define SPI_CR1_BIDIOE                  SPI_CR1_BIDIOE_Msk                     /*!< Output enable in bidirectional mode */
#define SPI_CR1_BIDIMODE_Pos            (15U)
#define SPI_CR1_BIDIMODE_Msk            (0x1UL << SPI_CR1_BIDIMODE_Pos)        /*!< 0x00008000 */
#define SPI_CR1_BIDIMODE                SPI_CR1_BIDIMODE_Msk                   /*!< Bidirectional data mode enable */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define SPI_CR2_SSOE_Pos                (2U)
#define SPI_CR2_SSOE_Msk                (0x1UL << SPI_CR2_SSOE_Pos)             /*!< 0x00000004 */
#define SPI_CR2_SSOE                    SPI_CR2_SSOE_Msk                       /*!< SS Output Enable */
#define SPI_CR2_CLRTXFIFO_Pos           (4U)
#define SPI_CR2_CLRTXFIFO_Msk           (0x1UL << SPI_CR2_CLRTXFIFO_Pos)       /*!< 0x00000010 */
#define SPI_CR2_CLRTXFIFO               SPI_CR2_CLRTXFIFO_Msk
#define SPI_CR2_ERRIE_Pos               (5U)
#define SPI_CR2_ERRIE_Msk               (0x1UL << SPI_CR2_ERRIE_Pos)           /*!< 0x00000020 */
#define SPI_CR2_ERRIE                   SPI_CR2_ERRIE_Msk                      /*!< Error Interrupt Enable */
#define SPI_CR2_RXNEIE_Pos              (6U)
#define SPI_CR2_RXNEIE_Msk              (0x1UL << SPI_CR2_RXNEIE_Pos)          /*!< 0x00000040 */
#define SPI_CR2_RXNEIE                  SPI_CR2_RXNEIE_Msk                     /*!< RX buffer Not Empty Interrupt Enable */
#define SPI_CR2_TXEIE_Pos               (7U)
#define SPI_CR2_TXEIE_Msk               (0x1UL << SPI_CR2_TXEIE_Pos)           /*!< 0x00000080 */
#define SPI_CR2_TXEIE                   SPI_CR2_TXEIE_Msk                      /*!< Tx buffer Empty Interrupt Enable */

/********************  Bit definition for SPI_SR register  ********************/
#define SPI_SR_RXNE_Pos                 (0U)
#define SPI_SR_RXNE_Msk                 (0x1UL << SPI_SR_RXNE_Pos)             /*!< 0x00000001 */
#define SPI_SR_RXNE                     SPI_SR_RXNE_Msk                        /*!< Receive buffer Not Empty */
#define SPI_SR_TXE_Pos                  (1U)
#define SPI_SR_TXE_Msk                  (0x1UL << SPI_SR_TXE_Pos)              /*!< 0x00000002 */
#define SPI_SR_TXE                      SPI_SR_TXE_Msk                         /*!< Transmit buffer Empty */
#define SPI_SR_MODF_Pos                 (5U)
#define SPI_SR_MODF_Msk                 (0x1UL << SPI_SR_MODF_Pos)             /*!< 0x00000020 */
#define SPI_SR_MODF                     SPI_SR_MODF_Msk                        /*!< Mode fault */
#define SPI_SR_OVR_Pos                  (6U)
#define SPI_SR_OVR_Msk                  (0x1UL << SPI_SR_OVR_Pos)              /*!< 0x00000040 */
#define SPI_SR_OVR                      SPI_SR_OVR_Msk                         /*!< Overrun flag */
#define SPI_SR_BSY_Pos                  (7U)
#define SPI_SR_BSY_Msk                  (0x1UL << SPI_SR_BSY_Pos)              /*!< 0x00000080 */
#define SPI_SR_BSY                      SPI_SR_BSY_Msk                         /*!< Busy flag */
#define SPI_SR_FRLVL_Pos                (9U)
#define SPI_SR_FRLVL_Msk                (0x1UL << SPI_SR_FRLVL_Pos)            /*!< 0x00000200 */
#define SPI_SR_FRLVL                    SPI_SR_FRLVL_Msk                       /*!< FIFO Reception Level */
#define SPI_SR_FTLVL_Pos                (11U)
#define SPI_SR_FTLVL_Msk                (0x1UL << SPI_SR_FTLVL_Pos)            /*!< 0x00000800 */
#define SPI_SR_FTLVL                    SPI_SR_FTLVL_Msk                       /*!< FIFO Transmission Level */

/********************  Bit definition for SPI_DR register  ********************/
#define SPI_DR_DR_Pos                   (0U)
#define SPI_DR_DR_Msk                   (0xFFFFUL << SPI_DR_DR_Pos)            /*!< 0x0000FFFF */
#define SPI_DR_DR                       SPI_DR_DR_Msk                          /*!< Data Register */



/******************************************************************************/
/*                                                                            */
/*                       System Configuration (SYSCFG)                        */
/*                                                                            */
/******************************************************************************/

/********************************* Bit definition for SYSCFG_CFGR1 register *****************************************/
#define SYSCFG_CFGR1_MEM_MODE_Pos                 (0U)
#define SYSCFG_CFGR1_MEM_MODE_Msk                 (0x1UL<<SYSCFG_CFGR1_MEM_MODE_Pos)                /*!< 0x00000001 */
#define SYSCFG_CFGR1_MEM_MODE                     SYSCFG_CFGR1_MEM_MODE_Msk                         /*!< memory mapping mode */
#define SYSCFG_CFGR1_I2C_FLTEN_Pos                (4U)
#define SYSCFG_CFGR1_I2C_FLTEN_Msk                (0x1UL<<SYSCFG_CFGR1_I2C_FLTEN_Pos)               /*!< 0x00000010 */
#define SYSCFG_CFGR1_I2C_FLTEN                    SYSCFG_CFGR1_I2C_FLTEN_Msk                        /*!< I2C1 filter enable */

/********************************* Bit definition for SYSCFG_CFGR2 register *****************************************/
#define SYSCFG_CFGR2_LOCKUP_LOCK_Pos              (0U)
#define SYSCFG_CFGR2_LOCKUP_LOCK_Msk              (0x1UL<<SYSCFG_CFGR2_LOCKUP_LOCK_Pos)             /*!< 0x00000001 */
#define SYSCFG_CFGR2_LOCKUP_LOCK                  SYSCFG_CFGR2_LOCKUP_LOCK_Msk                      /*!< core lockup enable */
#define SYSCFG_CFGR2_PVD_LOCK_Pos                 (2U)
#define SYSCFG_CFGR2_PVD_LOCK_Msk                 (0x1UL<<SYSCFG_CFGR2_PVD_LOCK_Pos)                /*!< 0x00000004 */
#define SYSCFG_CFGR2_PVD_LOCK                     SYSCFG_CFGR2_PVD_LOCK_Msk                         /*!< pvd lock enable */

/********************************* Bit definition for GPIO_ENS register *********************************************/
#define GPIO_ENS_PA_ENS_Pos                       (0U)
#define GPIO_ENS_PA_ENS_Msk                       (0xFFUL<<GPIO_ENS_PA_ENS_Pos)                     /*!< 0x000000FF */
#define GPIO_ENS_PA_ENS                           GPIO_ENS_PA_ENS_Msk                               /*!< GPIOA noise filter enable */
#define GPIO_ENS_PB_ENS_Pos                       (8U)
#define GPIO_ENS_PB_ENS_Msk                       (0xFFUL<<GPIO_ENS_PB_ENS_Pos)                     /*!< 0x0000FF00 */
#define GPIO_ENS_PB_ENS                           GPIO_ENS_PB_ENS_Msk                               /*!< GPIOB noise filter enable */
#define GPIO_ENS_PC_ENS_Pos                       (16U)
#define GPIO_ENS_PC_ENS_Msk                       (0xFFUL<<GPIO_ENS_PC_ENS_Pos)                     /*!< 0x00FF0000 */
#define GPIO_ENS_PC_ENS                           GPIO_ENS_PC_ENS_Msk                               /*!< GPIOC noise filter enable */
#define GPIO_ENS_PD_ENS_Pos                       (24U)
#define GPIO_ENS_PD_ENS_Msk                       (0x3UL<<GPIO_ENS_PD_ENS_Pos)                      /*!< 0x03000000 */
#define GPIO_ENS_PD_ENS                           GPIO_ENS_PD_ENS_Msk                               /*!< GPIOD noise filter enable */

/*****************************************************************************/
/*                                                                           */
/*                               Timers (TIM)                                */
/*                                                                           */
/*****************************************************************************/
/*******************  Bit definition for TIM_CR1 register  *******************/
#define TIM_CR1_CEN_Pos           (0U)
#define TIM_CR1_CEN_Msk           (0x1UL << TIM_CR1_CEN_Pos)                    /*!< 0x00000001 */
#define TIM_CR1_CEN               TIM_CR1_CEN_Msk                               /*!<Counter enable */
#define TIM_CR1_UDIS_Pos          (1U)
#define TIM_CR1_UDIS_Msk          (0x1UL << TIM_CR1_UDIS_Pos)                   /*!< 0x00000002 */
#define TIM_CR1_UDIS              TIM_CR1_UDIS_Msk                              /*!<Update disable */
#define TIM_CR1_URS_Pos           (2U)
#define TIM_CR1_URS_Msk           (0x1UL << TIM_CR1_URS_Pos)                    /*!< 0x00000004 */
#define TIM_CR1_URS               TIM_CR1_URS_Msk                               /*!<Update request source */
#define TIM_CR1_OPM_Pos           (3U)
#define TIM_CR1_OPM_Msk           (0x1UL << TIM_CR1_OPM_Pos)                    /*!< 0x00000008 */
#define TIM_CR1_OPM               TIM_CR1_OPM_Msk                               /*!<One Pulse */
#define TIM_CR1_DIR_Pos           (4U)
#define TIM_CR1_DIR_Msk           (0x1UL << TIM_CR1_DIR_Pos)                    /*!< 0x00000010 */
#define TIM_CR1_DIR               TIM_CR1_DIR_Msk                               /*!<Direction */
#define TIM_CR1_CMS_Pos           (5U)
#define TIM_CR1_CMS_Msk           (0x3UL << TIM_CR1_CMS_Pos)                    /*!< 0x00000060 */
#define TIM_CR1_CMS               TIM_CR1_CMS_Msk                               /*!<CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_0             (0x1UL << TIM_CR1_CMS_Pos)                    /*!< 0x00000020 */
#define TIM_CR1_CMS_1             (0x2UL << TIM_CR1_CMS_Pos)                    /*!< 0x00000040 */
#define TIM_CR1_ARPE_Pos          (7U)
#define TIM_CR1_ARPE_Msk          (0x1UL << TIM_CR1_ARPE_Pos)                   /*!< 0x00000080 */
#define TIM_CR1_ARPE              TIM_CR1_ARPE_Msk                              /*!<Auto-reload preload enable */
#define TIM_CR1_CKD_Pos           (8U)
#define TIM_CR1_CKD_Msk           (0x3UL << TIM_CR1_CKD_Pos)                    /*!< 0x00000300 */
#define TIM_CR1_CKD               TIM_CR1_CKD_Msk                               /*!<CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_0             (0x1UL << TIM_CR1_CKD_Pos)                    /*!< 0x00000100 */
#define TIM_CR1_CKD_1             (0x2UL << TIM_CR1_CKD_Pos)                    /*!< 0x00000200 */

/*******************  Bit definition for TIM_CR2 register  *******************/
#define TIM_CR2_CCPC_Pos          (0U)
#define TIM_CR2_CCPC_Msk          (0x1UL << TIM_CR2_CCPC_Pos)                   /*!< 0x00000001 */
#define TIM_CR2_CCPC              TIM_CR2_CCPC_Msk                              /*!<Capture/Compare Preloaded Control */
#define TIM_CR2_CCUS_Pos          (2U)
#define TIM_CR2_CCUS_Msk          (0x1UL << TIM_CR2_CCUS_Pos)                   /*!< 0x00000004 */
#define TIM_CR2_CCUS              TIM_CR2_CCUS_Msk                              /*!<Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos          (3U)
#define TIM_CR2_CCDS_Msk          (0x1UL<<TIM_CR2_CCDS_Pos)                     /*!< 0x00000008 */
#define TIM_CR2_MMS_Pos           (4U)
#define TIM_CR2_MMS_Msk           (0x200007UL << TIM_CR2_MMS_Pos)               /*!< 0x02000070 */
#define TIM_CR2_MMS               TIM_CR2_MMS_Msk                               /*!<MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS_0             (0x1UL << TIM_CR2_MMS_Pos)                    /*!< 0x00000010 */
#define TIM_CR2_MMS_1             (0x2UL << TIM_CR2_MMS_Pos)                    /*!< 0x00000020 */
#define TIM_CR2_MMS_2             (0x4UL << TIM_CR2_MMS_Pos)                    /*!< 0x00000040 */
#define TIM_CR2_MMS_3             (0x200000UL << TIM_CR2_MMS_Pos)               /*!< 0x02000000 */
#define TIM_CR2_TI1S_Pos          (7U)
#define TIM_CR2_TI1S_Msk          (0x1UL << TIM_CR2_TI1S_Pos)                   /*!< 0x00000080 */
#define TIM_CR2_TI1S              TIM_CR2_TI1S_Msk                              /*!<TI1 Selection */
#define TIM_CR2_OIS1_Pos          (8U)
#define TIM_CR2_OIS1_Msk          (0x1UL << TIM_CR2_OIS1_Pos)                   /*!< 0x00000100 */
#define TIM_CR2_OIS1              TIM_CR2_OIS1_Msk                              /*!<Output Idle state 1 (OC1 output) */
#define TIM_CR2_OIS1N_Pos         (9U)
#define TIM_CR2_OIS1N_Msk         (0x1UL << TIM_CR2_OIS1N_Pos)                  /*!< 0x00000200 */
#define TIM_CR2_OIS1N             TIM_CR2_OIS1N_Msk                             /*!<Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos          (10U)
#define TIM_CR2_OIS2_Msk          (0x1UL << TIM_CR2_OIS2_Pos)                   /*!< 0x00000400 */
#define TIM_CR2_OIS2              TIM_CR2_OIS2_Msk                              /*!<Output Idle state 2 (OC2 output) */
#define TIM_CR2_OIS2N_Pos         (11U)
#define TIM_CR2_OIS2N_Msk         (0x1UL << TIM_CR2_OIS2N_Pos)                  /*!< 0x00000800 */
#define TIM_CR2_OIS2N             TIM_CR2_OIS2N_Msk                             /*!<Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos          (12U)
#define TIM_CR2_OIS3_Msk          (0x1UL << TIM_CR2_OIS3_Pos)                   /*!< 0x00001000 */
#define TIM_CR2_OIS3              TIM_CR2_OIS3_Msk                              /*!<Output Idle state 3 (OC3 output) */
#define TIM_CR2_OIS3N_Pos         (13U)
#define TIM_CR2_OIS3N_Msk         (0x1UL << TIM_CR2_OIS3N_Pos)                  /*!< 0x00002000 */
#define TIM_CR2_OIS3N             TIM_CR2_OIS3N_Msk                             /*!<Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos          (14U)
#define TIM_CR2_OIS4_Msk          (0x1UL << TIM_CR2_OIS4_Pos)                   /*!< 0x00004000 */
#define TIM_CR2_OIS4              TIM_CR2_OIS4_Msk                              /*!<Output Idle state 4 (OC4 output) */
#define TIM_CR2_OIS5_Pos          (16U)
#define TIM_CR2_OIS5_Msk          (0x1UL<<TIM_CR2_OIS5_Pos)                        /*!< 0x00010000 */
#define TIM_CR2_OIS5              TIM_CR2_OIS5_Msk                                 
#define TIM_CR2_OIS6_Pos          (18U)
#define TIM_CR2_OIS6_Msk          (0x1UL<<TIM_CR2_OIS6_Pos)                        /*!< 0x00040000 */
#define TIM_CR2_OIS6              TIM_CR2_OIS6_Msk

/*******************  Bit definition for TIM_SMCR register  ******************/
#define TIM_SMCR_SMS_Pos          (0U)
#define TIM_SMCR_SMS_Msk          (0x00010007UL << TIM_SMCR_SMS_Pos)            /*!< 0x00010007UL */
#define TIM_SMCR_SMS              TIM_SMCR_SMS_Msk                              /*!<SMS[2:0] bits (Slave mode selection) */
#define TIM_SMCR_SMS_0            (0x1UL << TIM_SMCR_SMS_Pos)                   /*!< 0x00000001 */
#define TIM_SMCR_SMS_1            (0x2UL << TIM_SMCR_SMS_Pos)                   /*!< 0x00000002 */
#define TIM_SMCR_SMS_2            (0x4UL << TIM_SMCR_SMS_Pos)                   /*!< 0x00000004 */
#define TIM_SMCR_SMS_3            (0x10000UL << TIM_SMCR_SMS_Pos)               /*!< 0x00010000 */
#define TIM_SMCR_OCCS_Pos         (3U)
#define TIM_SMCR_OCCS_Msk         (0x1UL << TIM_SMCR_OCCS_Pos)                  /*!< 0x00000008 */
#define TIM_SMCR_OCCS             TIM_SMCR_OCCS_Msk                             /*!< OCREF clear selection */
#define TIM_SMCR_TS_Pos           (4U)
#define TIM_SMCR_TS_Msk           (0x30007UL << TIM_SMCR_TS_Pos)                /*!< 0x30007UL */
#define TIM_SMCR_TS               TIM_SMCR_TS_Msk                               /*!<TS[2:0] bits (Trigger selection) */
#define TIM_SMCR_TS_0             (0x1UL << TIM_SMCR_TS_Pos)                    /*!< 0x00000010 */
#define TIM_SMCR_TS_1             (0x2UL << TIM_SMCR_TS_Pos)                    /*!< 0x00000020 */
#define TIM_SMCR_TS_2             (0x4UL << TIM_SMCR_TS_Pos)                    /*!< 0x00000040 */
#define TIM_SMCR_TS_3             (0x10000UL << TIM_SMCR_TS_Pos)                /*!< 0x00100000 */
#define TIM_SMCR_TS_4             (0x20000UL << TIM_SMCR_TS_Pos)                /*!< 0x00200000 */
#define TIM_SMCR_MSM_Pos          (7U)
#define TIM_SMCR_MSM_Msk          (0x1UL << TIM_SMCR_MSM_Pos)                   /*!< 0x00000080 */
#define TIM_SMCR_MSM              TIM_SMCR_MSM_Msk                              /*!<Master/slave mode */
#define TIM_SMCR_ETF_Pos          (8U)
#define TIM_SMCR_ETF_Msk          (0xFUL << TIM_SMCR_ETF_Pos)                   /*!< 0x00000F00 */
#define TIM_SMCR_ETF              TIM_SMCR_ETF_Msk                              /*!<ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0            (0x1UL << TIM_SMCR_ETF_Pos)                   /*!< 0x00000100 */
#define TIM_SMCR_ETF_1            (0x2UL << TIM_SMCR_ETF_Pos)                   /*!< 0x00000200 */
#define TIM_SMCR_ETF_2            (0x4UL << TIM_SMCR_ETF_Pos)                   /*!< 0x00000400 */
#define TIM_SMCR_ETF_3            (0x8UL << TIM_SMCR_ETF_Pos)                   /*!< 0x00000800 */
#define TIM_SMCR_ETPS_Pos         (12U)
#define TIM_SMCR_ETPS_Msk         (0x3UL << TIM_SMCR_ETPS_Pos)                  /*!< 0x00003000 */
#define TIM_SMCR_ETPS             TIM_SMCR_ETPS_Msk                             /*!<ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_0           (0x1UL << TIM_SMCR_ETPS_Pos)                  /*!< 0x00001000 */
#define TIM_SMCR_ETPS_1           (0x2UL << TIM_SMCR_ETPS_Pos)                  /*!< 0x00002000 */
#define TIM_SMCR_ECE_Pos          (14U)
#define TIM_SMCR_ECE_Msk          (0x1UL << TIM_SMCR_ECE_Pos)                   /*!< 0x00004000 */
#define TIM_SMCR_ECE              TIM_SMCR_ECE_Msk                              /*!<External clock enable */
#define TIM_SMCR_ETP_Pos          (15U)
#define TIM_SMCR_ETP_Msk          (0x1UL << TIM_SMCR_ETP_Pos)                   /*!< 0x00008000 */
#define TIM_SMCR_ETP              TIM_SMCR_ETP_Msk                              /*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  ******************/
#define TIM_DIER_UIE_Pos          (0U)
#define TIM_DIER_UIE_Msk          (0x1UL << TIM_DIER_UIE_Pos)                   /*!< 0x00000001 */
#define TIM_DIER_UIE              TIM_DIER_UIE_Msk                              /*!<Update interrupt enable */
#define TIM_DIER_CC1IE_Pos        (1U)
#define TIM_DIER_CC1IE_Msk        (0x1UL << TIM_DIER_CC1IE_Pos)                 /*!< 0x00000002 */
#define TIM_DIER_CC1IE            TIM_DIER_CC1IE_Msk                            /*!<Capture/Compare 1 interrupt enable */
#define TIM_DIER_CC2IE_Pos        (2U)
#define TIM_DIER_CC2IE_Msk        (0x1UL << TIM_DIER_CC2IE_Pos)                 /*!< 0x00000004 */
#define TIM_DIER_CC2IE            TIM_DIER_CC2IE_Msk                            /*!<Capture/Compare 2 interrupt enable */
#define TIM_DIER_CC3IE_Pos        (3U)
#define TIM_DIER_CC3IE_Msk        (0x1UL << TIM_DIER_CC3IE_Pos)                 /*!< 0x00000008 */
#define TIM_DIER_CC3IE            TIM_DIER_CC3IE_Msk                            /*!<Capture/Compare 3 interrupt enable */
#define TIM_DIER_CC4IE_Pos        (4U)
#define TIM_DIER_CC4IE_Msk        (0x1UL << TIM_DIER_CC4IE_Pos)                 /*!< 0x00000010 */
#define TIM_DIER_CC4IE            TIM_DIER_CC4IE_Msk                            /*!<Capture/Compare 4 interrupt enable */
#define TIM_DIER_COMIE_Pos        (5U)
#define TIM_DIER_COMIE_Msk        (0x1UL << TIM_DIER_COMIE_Pos)                 /*!< 0x00000020 */
#define TIM_DIER_COMIE            TIM_DIER_COMIE_Msk                            /*!<COM interrupt enable */
#define TIM_DIER_TIE_Pos          (6U)
#define TIM_DIER_TIE_Msk          (0x1UL << TIM_DIER_TIE_Pos)                   /*!< 0x00000040 */
#define TIM_DIER_TIE              TIM_DIER_TIE_Msk                              /*!<Trigger interrupt enable */
#define TIM_DIER_BIE_Pos          (7U)
#define TIM_DIER_BIE_Msk          (0x1UL << TIM_DIER_BIE_Pos)                   /*!< 0x00000080 */
#define TIM_DIER_BIE              TIM_DIER_BIE_Msk                              /*!<Break interrupt enable */
#define TIM_DIER_UDE_Pos          (8U)
#define TIM_DIER_UDE_Msk          (0x1UL<<TIM_DIER_UDE_Pos)                        /*!< 0x00000100 */
#define TIM_DIER_UDE              TIM_DIER_UDE_Msk                                 
#define TIM_DIER_CC1DE_Pos        (9U)
#define TIM_DIER_CC1DE_Msk        (0x1UL<<TIM_DIER_CC1DE_Pos)                      /*!< 0x00000200 */
#define TIM_DIER_CC1DE            TIM_DIER_CC1DE_Msk                               
#define TIM_DIER_CC2DE_Pos        (10U)
#define TIM_DIER_CC2DE_Msk        (0x1UL<<TIM_DIER_CC2DE_Pos)                      /*!< 0x00000400 */
#define TIM_DIER_CC2DE            TIM_DIER_CC2DE_Msk                               
#define TIM_DIER_CC3DE_Pos        (11U)
#define TIM_DIER_CC3DE_Msk        (0x1UL<<TIM_DIER_CC3DE_Pos)                      /*!< 0x00000800 */
#define TIM_DIER_CC3DE            TIM_DIER_CC3DE_Msk                               
#define TIM_DIER_CC4DE_Pos        (12U)
#define TIM_DIER_CC4DE_Msk        (0x1UL<<TIM_DIER_CC4DE_Pos)                      /*!< 0x00001000 */
#define TIM_DIER_CC4DE            TIM_DIER_CC4DE_Msk                               
#define TIM_DIER_COMDE_Pos        (13U)
#define TIM_DIER_COMDE_Msk        (0x1UL<<TIM_DIER_COMDE_Pos)                      /*!< 0x00002000 */
#define TIM_DIER_COMDE            TIM_DIER_COMDE_Msk                               
#define TIM_DIER_TDE_Pos          (14U)
#define TIM_DIER_TDE_Msk          (0x1UL<<TIM_DIER_TDE_Pos)                        /*!< 0x00004000 */
#define TIM_DIER_TDE              TIM_DIER_TDE_Msk

/********************  Bit definition for TIM_SR register  *******************/
#define TIM_SR_UIF_Pos            (0U)
#define TIM_SR_UIF_Msk            (0x1UL << TIM_SR_UIF_Pos)                     /*!< 0x00000001 */
#define TIM_SR_UIF                TIM_SR_UIF_Msk                                /*!<Update interrupt Flag */
#define TIM_SR_CC1IF_Pos          (1U)
#define TIM_SR_CC1IF_Msk          (0x1UL << TIM_SR_CC1IF_Pos)                   /*!< 0x00000002 */
#define TIM_SR_CC1IF              TIM_SR_CC1IF_Msk                              /*!<Capture/Compare 1 interrupt Flag */
#define TIM_SR_CC2IF_Pos          (2U)
#define TIM_SR_CC2IF_Msk          (0x1UL << TIM_SR_CC2IF_Pos)                   /*!< 0x00000004 */
#define TIM_SR_CC2IF              TIM_SR_CC2IF_Msk                              /*!<Capture/Compare 2 interrupt Flag */
#define TIM_SR_CC3IF_Pos          (3U)
#define TIM_SR_CC3IF_Msk          (0x1UL << TIM_SR_CC3IF_Pos)                   /*!< 0x00000008 */
#define TIM_SR_CC3IF              TIM_SR_CC3IF_Msk                              /*!<Capture/Compare 3 interrupt Flag */
#define TIM_SR_CC4IF_Pos          (4U)
#define TIM_SR_CC4IF_Msk          (0x1UL << TIM_SR_CC4IF_Pos)                   /*!< 0x00000010 */
#define TIM_SR_CC4IF              TIM_SR_CC4IF_Msk                              /*!<Capture/Compare 4 interrupt Flag */
#define TIM_SR_COMIF_Pos          (5U)
#define TIM_SR_COMIF_Msk          (0x1UL << TIM_SR_COMIF_Pos)                   /*!< 0x00000020 */
#define TIM_SR_COMIF              TIM_SR_COMIF_Msk                              /*!<COM interrupt Flag */
#define TIM_SR_TIF_Pos            (6U)
#define TIM_SR_TIF_Msk            (0x1UL << TIM_SR_TIF_Pos)                     /*!< 0x00000040 */
#define TIM_SR_TIF                TIM_SR_TIF_Msk                                /*!<Trigger interrupt Flag */
#define TIM_SR_BIF_Pos            (7U)
#define TIM_SR_BIF_Msk            (0x1UL << TIM_SR_BIF_Pos)                     /*!< 0x00000080 */
#define TIM_SR_BIF                TIM_SR_BIF_Msk                                /*!<Break interrupt Flag */
#define TIM_SR_B2IF_Pos           (8U)
#define TIM_SR_B2IF_Msk           (0x1UL<<TIM_SR_B2IF_Pos)                         /*!< 0x00000100 */
#define TIM_SR_B2IF               TIM_SR_B2IF_Msk                        
#define TIM_SR_CC1OF_Pos          (9U)
#define TIM_SR_CC1OF_Msk          (0x1UL << TIM_SR_CC1OF_Pos)                   /*!< 0x00000200 */
#define TIM_SR_CC1OF              TIM_SR_CC1OF_Msk                              /*!<Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos          (10U)
#define TIM_SR_CC2OF_Msk          (0x1UL << TIM_SR_CC2OF_Pos)                   /*!< 0x00000400 */
#define TIM_SR_CC2OF              TIM_SR_CC2OF_Msk                              /*!<Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos          (11U)
#define TIM_SR_CC3OF_Msk          (0x1UL << TIM_SR_CC3OF_Pos)                   /*!< 0x00000800 */
#define TIM_SR_CC3OF              TIM_SR_CC3OF_Msk                              /*!<Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos          (12U)
#define TIM_SR_CC4OF_Msk          (0x1UL << TIM_SR_CC4OF_Pos)                   /*!< 0x00001000 */
#define TIM_SR_CC4OF              TIM_SR_CC4OF_Msk                              /*!<Capture/Compare 4 Overcapture Flag */
#define TIM_SR_SBIF_Pos           (13U)
#define TIM_SR_SBIF_Msk           (0x1UL<<TIM_SR_SBIF_Pos)                         /*!< 0x00002000 */
#define TIM_SR_SBIF               TIM_SR_SBIF_Msk
#define TIM_SR_CC5IF_Pos          (16U)
#define TIM_SR_CC5IF_Msk          (0x1UL<<TIM_SR_CC5IF_Pos)                        /*!< 0x00010000 */
#define TIM_SR_CC5IF              TIM_SR_CC5IF_Msk                                 
#define TIM_SR_CC6IF_Pos          (17U)
#define TIM_SR_CC6IF_Msk          (0x1UL<<TIM_SR_CC6IF_Pos)                        /*!< 0x00020000 */
#define TIM_SR_CC6IF              TIM_SR_CC6IF_Msk                                 
#define TIM_SR_IC1IR_Pos          (18U)
#define TIM_SR_IC1IR_Msk          (0x1UL<<TIM_SR_IC1IR_Pos)                        /*!< 0x00040000 */
#define TIM_SR_IC1IR              TIM_SR_IC1IR_Msk                                 
#define TIM_SR_IC2IR_Pos          (19U)
#define TIM_SR_IC2IR_Msk          (0x1UL<<TIM_SR_IC2IR_Pos)                        /*!< 0x00080000 */
#define TIM_SR_IC2IR              TIM_SR_IC2IR_Msk                                 
#define TIM_SR_IC3IR_Pos          (24U)
#define TIM_SR_IC3IR_Msk          (0x1UL<<TIM_SR_IC3IR_Pos)                        /*!< 0x01000000 */
#define TIM_SR_IC3IR              TIM_SR_IC3IR_Msk                                 
#define TIM_SR_IC4IR_Pos          (25U)
#define TIM_SR_IC4IR_Msk          (0x1UL<<TIM_SR_IC4IR_Pos)                        /*!< 0x02000000 */
#define TIM_SR_IC4IR              TIM_SR_IC4IR_Msk                                 
#define TIM_SR_IC1IF_Pos          (26U)
#define TIM_SR_IC1IF_Msk          (0x1UL<<TIM_SR_IC1IF_Pos)                        /*!< 0x04000000 */
#define TIM_SR_IC1IF              TIM_SR_IC1IF_Msk                                 
#define TIM_SR_IC2IF_Pos          (27U)
#define TIM_SR_IC2IF_Msk          (0x1UL<<TIM_SR_IC2IF_Pos)                        /*!< 0x08000000 */
#define TIM_SR_IC2IF              TIM_SR_IC2IF_Msk                                 
#define TIM_SR_IC3IF_Pos          (28U)
#define TIM_SR_IC3IF_Msk          (0x1UL<<TIM_SR_IC3IF_Pos)                        /*!< 0x10000000 */
#define TIM_SR_IC3IF              TIM_SR_IC3IF_Msk                                 
#define TIM_SR_IC4IF_Pos          (29U)
#define TIM_SR_IC4IF_Msk          (0x1UL<<TIM_SR_IC4IF_Pos)                        /*!< 0x20000000 */
#define TIM_SR_IC4IF              TIM_SR_IC4IF_Msk                                 

/*******************  Bit definition for TIM_EGR register  *******************/
#define TIM_EGR_UG_Pos            (0U)
#define TIM_EGR_UG_Msk            (0x1UL << TIM_EGR_UG_Pos)                     /*!< 0x00000001 */
#define TIM_EGR_UG                TIM_EGR_UG_Msk                                /*!<Update Generation */
#define TIM_EGR_CC1G_Pos          (1U)
#define TIM_EGR_CC1G_Msk          (0x1UL << TIM_EGR_CC1G_Pos)                   /*!< 0x00000002 */
#define TIM_EGR_CC1G              TIM_EGR_CC1G_Msk                              /*!<Capture/Compare 1 Generation */
#define TIM_EGR_CC2G_Pos          (2U)
#define TIM_EGR_CC2G_Msk          (0x1UL << TIM_EGR_CC2G_Pos)                   /*!< 0x00000004 */
#define TIM_EGR_CC2G              TIM_EGR_CC2G_Msk                              /*!<Capture/Compare 2 Generation */
#define TIM_EGR_CC3G_Pos          (3U)
#define TIM_EGR_CC3G_Msk          (0x1UL << TIM_EGR_CC3G_Pos)                   /*!< 0x00000008 */
#define TIM_EGR_CC3G              TIM_EGR_CC3G_Msk                              /*!<Capture/Compare 3 Generation */
#define TIM_EGR_CC4G_Pos          (4U)
#define TIM_EGR_CC4G_Msk          (0x1UL << TIM_EGR_CC4G_Pos)                   /*!< 0x00000010 */
#define TIM_EGR_CC4G              TIM_EGR_CC4G_Msk                              /*!<Capture/Compare 4 Generation */
#define TIM_EGR_COMG_Pos          (5U)
#define TIM_EGR_COMG_Msk          (0x1UL << TIM_EGR_COMG_Pos)                   /*!< 0x00000020 */
#define TIM_EGR_COMG              TIM_EGR_COMG_Msk                              /*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos            (6U)
#define TIM_EGR_TG_Msk            (0x1UL << TIM_EGR_TG_Pos)                     /*!< 0x00000040 */
#define TIM_EGR_TG                TIM_EGR_TG_Msk                                /*!<Trigger Generation */
#define TIM_EGR_BG_Pos            (7U)
#define TIM_EGR_BG_Msk            (0x1UL << TIM_EGR_BG_Pos)                     /*!< 0x00000080 */
#define TIM_EGR_BG                TIM_EGR_BG_Msk                                /*!<Break Generation */

/******************  Bit definition for TIM_CCMR1 register  ******************/
#define TIM_CCMR1_CC1S_Pos        (0U)
#define TIM_CCMR1_CC1S_Msk        (0x3UL << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000003 */
#define TIM_CCMR1_CC1S            TIM_CCMR1_CC1S_Msk                            /*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_0          (0x1UL << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1          (0x2UL << TIM_CCMR1_CC1S_Pos)                 /*!< 0x00000002 */

#define TIM_CCMR1_OC1FE_Pos       (2U)
#define TIM_CCMR1_OC1FE_Msk       (0x1UL << TIM_CCMR1_OC1FE_Pos)                /*!< 0x00000004 */
#define TIM_CCMR1_OC1FE           TIM_CCMR1_OC1FE_Msk                           /*!<Output Compare 1 Fast enable */
#define TIM_CCMR1_OC1PE_Pos       (3U)
#define TIM_CCMR1_OC1PE_Msk       (0x1UL << TIM_CCMR1_OC1PE_Pos)                /*!< 0x00000008 */
#define TIM_CCMR1_OC1PE           TIM_CCMR1_OC1PE_Msk                           /*!<Output Compare 1 Preload enable */

#define TIM_CCMR1_OC1M_Pos        (4U)
#define TIM_CCMR1_OC1M_Msk        (0x1007UL << TIM_CCMR1_OC1M_Pos)              /*!< 0x1007UL */
#define TIM_CCMR1_OC1M            TIM_CCMR1_OC1M_Msk                            /*!<OC1M[2:0] bits (Output Compare 1 Mode) */
#define TIM_CCMR1_OC1M_0          (0x1UL << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1          (0x2UL << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2          (0x4UL << TIM_CCMR1_OC1M_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR1_OC1M_3          (0x1000UL << TIM_CCMR1_OC1M_Pos)              /*!< 0x00010000 */

#define TIM_CCMR1_OC1CE_Pos       (7U)
#define TIM_CCMR1_OC1CE_Msk       (0x1UL << TIM_CCMR1_OC1CE_Pos)                /*!< 0x00000080 */
#define TIM_CCMR1_OC1CE           TIM_CCMR1_OC1CE_Msk                           /*!<Output Compare 1Clear Enable */

#define TIM_CCMR1_CC2S_Pos        (8U)
#define TIM_CCMR1_CC2S_Msk        (0x3UL << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000300 */
#define TIM_CCMR1_CC2S            TIM_CCMR1_CC2S_Msk                            /*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_0          (0x1UL << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1          (0x2UL << TIM_CCMR1_CC2S_Pos)                 /*!< 0x00000200 */

#define TIM_CCMR1_OC2FE_Pos       (10U)
#define TIM_CCMR1_OC2FE_Msk       (0x1UL << TIM_CCMR1_OC2FE_Pos)                /*!< 0x00000400 */
#define TIM_CCMR1_OC2FE           TIM_CCMR1_OC2FE_Msk                           /*!<Output Compare 2 Fast enable */

#define TIM_CCMR1_OC2PE_Pos       (11U)
#define TIM_CCMR1_OC2PE_Msk       (0x1UL << TIM_CCMR1_OC2PE_Pos)                /*!< 0x00000800 */
#define TIM_CCMR1_OC2PE           TIM_CCMR1_OC2PE_Msk                           /*!<Output Compare 2 Preload enable */

#define TIM_CCMR1_OC2M_Pos        (12U)
#define TIM_CCMR1_OC2M_Msk        (0x1007UL << TIM_CCMR1_OC2M_Pos)              /*!< 0x1007UL */
#define TIM_CCMR1_OC2M            TIM_CCMR1_OC2M_Msk                            /*!<OC2M[2:0] bits (Output Compare 2 Mode) */
#define TIM_CCMR1_OC2M_0          (0x1UL << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1          (0x2UL << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2          (0x4UL << TIM_CCMR1_OC2M_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR1_OC2M_3          (0x1000UL << TIM_CCMR1_OC2M_Pos)              /*!< 0x01000000 */
#define TIM_CCMR1_OC2CE_Pos       (15U)
#define TIM_CCMR1_OC2CE_Msk       (0x1UL << TIM_CCMR1_OC2CE_Pos)                /*!< 0x00008000 */
#define TIM_CCMR1_OC2CE           TIM_CCMR1_OC2CE_Msk                           /*!<Output Compare 2 Clear Enable */

/*---------------------------------------------------------------------------*/

/********************************* Bit definition for TIM_CCMR1 register ***********************************/
#define TIM_CCMR1_IC1PSC_Pos             (2U)
#define TIM_CCMR1_IC1PSC_Msk             (0x3UL<<TIM_CCMR1_IC1PSC_Pos)            /*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC                 TIM_CCMR1_IC1PSC_Msk
#define TIM_CCMR1_IC1PSC_0               (0x1UL<<TIM_CCMR1_IC1PSC_Pos)            /*!< 0x00000004 */
#define TIM_CCMR1_IC1PSC_1               (0x2UL<<TIM_CCMR1_IC1PSC_Pos)            /*!< 0x00000008 */
#define TIM_CCMR1_IC1F_Pos               (4U)
#define TIM_CCMR1_IC1F_Msk               (0xFUL<<TIM_CCMR1_IC1F_Pos)              /*!< 0x000000F0 */
#define TIM_CCMR1_IC1F                   TIM_CCMR1_IC1F_Msk
#define TIM_CCMR1_IC1F_0                 (0x1UL<<TIM_CCMR1_IC1F_Pos)              /*!< 0x00000010 */
#define TIM_CCMR1_IC1F_1                 (0x2UL<<TIM_CCMR1_IC1F_Pos)              /*!< 0x00000020 */
#define TIM_CCMR1_IC1F_2                 (0x4UL<<TIM_CCMR1_IC1F_Pos)              /*!< 0x00000040 */
#define TIM_CCMR1_IC1F_3                 (0x8UL<<TIM_CCMR1_IC1F_Pos)              /*!< 0x00000080 */
#define TIM_CCMR1_IC2PSC_Pos             (10U)
#define TIM_CCMR1_IC2PSC_Msk             (0x3UL<<TIM_CCMR1_IC2PSC_Pos)            /*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC                 TIM_CCMR1_IC2PSC_Msk
#define TIM_CCMR1_IC2PSC_0               (0x1UL<<TIM_CCMR1_IC2PSC_Pos)            /*!< 0x00000400 */
#define TIM_CCMR1_IC2PSC_1               (0x2UL<<TIM_CCMR1_IC2PSC_Pos)            /*!< 0x00000800 */
#define TIM_CCMR1_IC2F_Pos               (12U)
#define TIM_CCMR1_IC2F_Msk               (0xFUL<<TIM_CCMR1_IC2F_Pos)              /*!< 0x0000F000 */
#define TIM_CCMR1_IC2F                   TIM_CCMR1_IC2F_Msk
#define TIM_CCMR1_IC2F_0                 (0x1UL<<TIM_CCMR1_IC2F_Pos)              /*!< 0x00001000 */
#define TIM_CCMR1_IC2F_1                 (0x2UL<<TIM_CCMR1_IC2F_Pos)              /*!< 0x00002000 */
#define TIM_CCMR1_IC2F_2                 (0x4UL<<TIM_CCMR1_IC2F_Pos)              /*!< 0x00004000 */
#define TIM_CCMR1_IC2F_3                 (0x8UL<<TIM_CCMR1_IC2F_Pos)              /*!< 0x00008000 */

/******************  Bit definition for TIM_CCMR2 register  ******************/
#define TIM_CCMR2_CC3S_Pos        (0U)
#define TIM_CCMR2_CC3S_Msk        (0x3UL << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000003 */
#define TIM_CCMR2_CC3S            TIM_CCMR2_CC3S_Msk                            /*!<CC3S[1:0] bits (Capture/Compare 3 Selection) */
#define TIM_CCMR2_CC3S_0          (0x1UL << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000001 */
#define TIM_CCMR2_CC3S_1          (0x2UL << TIM_CCMR2_CC3S_Pos)                 /*!< 0x00000002 */

#define TIM_CCMR2_OC3FE_Pos       (2U)
#define TIM_CCMR2_OC3FE_Msk       (0x1UL << TIM_CCMR2_OC3FE_Pos)                /*!< 0x00000004 */
#define TIM_CCMR2_OC3FE           TIM_CCMR2_OC3FE_Msk                           /*!<Output Compare 3 Fast enable */
#define TIM_CCMR2_OC3PE_Pos       (3U)
#define TIM_CCMR2_OC3PE_Msk       (0x1UL << TIM_CCMR2_OC3PE_Pos)                /*!< 0x00000008 */
#define TIM_CCMR2_OC3PE           TIM_CCMR2_OC3PE_Msk                           /*!<Output Compare 3 Preload enable */

#define TIM_CCMR2_OC3M_Pos        (4U)
#define TIM_CCMR2_OC3M_Msk        (0x00010070 << TIM_CCMR2_OC3M_Pos)            /*!< 0x00010070 */
#define TIM_CCMR2_OC3M            TIM_CCMR2_OC3M_Msk                            /*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_0          (0x1UL << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR2_OC3M_1          (0x2UL << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR2_OC3M_2          (0x4UL << TIM_CCMR2_OC3M_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR2_OC3M_3          (0x1000UL << TIM_CCMR2_OC3M_Pos)              /*!< 0x00010000 */

#define TIM_CCMR2_OC3CE_Pos       (7U)
#define TIM_CCMR2_OC3CE_Msk       (0x1UL << TIM_CCMR2_OC3CE_Pos)                /*!< 0x00000080 */
#define TIM_CCMR2_OC3CE           TIM_CCMR2_OC3CE_Msk                           /*!<Output Compare 3 Clear Enable */

#define TIM_CCMR2_CC4S_Pos        (8U)
#define TIM_CCMR2_CC4S_Msk        (0x3UL << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000300 */
#define TIM_CCMR2_CC4S            TIM_CCMR2_CC4S_Msk                            /*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_0          (0x1UL << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000100 */
#define TIM_CCMR2_CC4S_1          (0x2UL << TIM_CCMR2_CC4S_Pos)                 /*!< 0x00000200 */

#define TIM_CCMR2_OC4FE_Pos       (10U)
#define TIM_CCMR2_OC4FE_Msk       (0x1UL << TIM_CCMR2_OC4FE_Pos)                /*!< 0x00000400 */
#define TIM_CCMR2_OC4FE           TIM_CCMR2_OC4FE_Msk                           /*!<Output Compare 4 Fast enable */
#define TIM_CCMR2_OC4PE_Pos       (11U)
#define TIM_CCMR2_OC4PE_Msk       (0x1UL << TIM_CCMR2_OC4PE_Pos)                /*!< 0x00000800 */
#define TIM_CCMR2_OC4PE           TIM_CCMR2_OC4PE_Msk                           /*!<Output Compare 4 Preload enable */

#define TIM_CCMR2_OC4M_Pos        (12U)
#define TIM_CCMR2_OC4M_Msk        (0x1007UL << TIM_CCMR2_OC4M_Pos)              /*!< 0x1007UL */
#define TIM_CCMR2_OC4M            TIM_CCMR2_OC4M_Msk                            /*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_0          (0x1UL << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR2_OC4M_1          (0x2UL << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR2_OC4M_2          (0x4UL << TIM_CCMR2_OC4M_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR2_OC4M_3          (0x1000UL << TIM_CCMR2_OC4M_Pos)              /*!< 0x01000000 */

#define TIM_CCMR2_OC4CE_Pos       (15U)
#define TIM_CCMR2_OC4CE_Msk       (0x1UL << TIM_CCMR2_OC4CE_Pos)                /*!< 0x00008000 */
#define TIM_CCMR2_OC4CE           TIM_CCMR2_OC4CE_Msk                           /*!<Output Compare 4 Clear Enable */

/*---------------------------------------------------------------------------*/
#define TIM_CCMR2_IC3PSC_Pos      (2U)
#define TIM_CCMR2_IC3PSC_Msk      (0x3UL << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC          TIM_CCMR2_IC3PSC_Msk                          /*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_0        (0x1UL << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x00000004 */
#define TIM_CCMR2_IC3PSC_1        (0x2UL << TIM_CCMR2_IC3PSC_Pos)               /*!< 0x00000008 */

#define TIM_CCMR2_IC3F_Pos        (4U)
#define TIM_CCMR2_IC3F_Msk        (0xFUL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x000000F0 */
#define TIM_CCMR2_IC3F            TIM_CCMR2_IC3F_Msk                            /*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0          (0x1UL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000010 */
#define TIM_CCMR2_IC3F_1          (0x2UL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000020 */
#define TIM_CCMR2_IC3F_2          (0x4UL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000040 */
#define TIM_CCMR2_IC3F_3          (0x8UL << TIM_CCMR2_IC3F_Pos)                 /*!< 0x00000080 */

#define TIM_CCMR2_IC4PSC_Pos      (10U)
#define TIM_CCMR2_IC4PSC_Msk      (0x3UL << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC          TIM_CCMR2_IC4PSC_Msk                          /*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_0        (0x1UL << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000400 */
#define TIM_CCMR2_IC4PSC_1        (0x2UL << TIM_CCMR2_IC4PSC_Pos)               /*!< 0x00000800 */

#define TIM_CCMR2_IC4F_Pos        (12U)
#define TIM_CCMR2_IC4F_Msk        (0xFUL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x0000F000 */
#define TIM_CCMR2_IC4F            TIM_CCMR2_IC4F_Msk                            /*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0          (0x1UL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00001000 */
#define TIM_CCMR2_IC4F_1          (0x2UL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00002000 */
#define TIM_CCMR2_IC4F_2          (0x4UL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00004000 */
#define TIM_CCMR2_IC4F_3          (0x8UL << TIM_CCMR2_IC4F_Pos)                 /*!< 0x00008000 */

/*******************  Bit definition for TIM_CCER register  ******************/
#define TIM_CCER_CC1E_Pos         (0U)
#define TIM_CCER_CC1E_Msk         (0x1UL << TIM_CCER_CC1E_Pos)                  /*!< 0x00000001 */
#define TIM_CCER_CC1E             TIM_CCER_CC1E_Msk                             /*!<Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos         (1U)
#define TIM_CCER_CC1P_Msk         (0x1UL << TIM_CCER_CC1P_Pos)                  /*!< 0x00000002 */
#define TIM_CCER_CC1P             TIM_CCER_CC1P_Msk                             /*!<Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos        (2U)
#define TIM_CCER_CC1NE_Msk        (0x1UL << TIM_CCER_CC1NE_Pos)                 /*!< 0x00000004 */
#define TIM_CCER_CC1NE            TIM_CCER_CC1NE_Msk                            /*!<Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos        (3U)
#define TIM_CCER_CC1NP_Msk        (0x1UL << TIM_CCER_CC1NP_Pos)                 /*!< 0x00000008 */
#define TIM_CCER_CC1NP            TIM_CCER_CC1NP_Msk                            /*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos         (4U)
#define TIM_CCER_CC2E_Msk         (0x1UL << TIM_CCER_CC2E_Pos)                  /*!< 0x00000010 */
#define TIM_CCER_CC2E             TIM_CCER_CC2E_Msk                             /*!<Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos         (5U)
#define TIM_CCER_CC2P_Msk         (0x1UL << TIM_CCER_CC2P_Pos)                  /*!< 0x00000020 */
#define TIM_CCER_CC2P             TIM_CCER_CC2P_Msk                             /*!<Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos        (6U)
#define TIM_CCER_CC2NE_Msk        (0x1UL << TIM_CCER_CC2NE_Pos)                 /*!< 0x00000040 */
#define TIM_CCER_CC2NE            TIM_CCER_CC2NE_Msk                            /*!<Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos        (7U)
#define TIM_CCER_CC2NP_Msk        (0x1UL << TIM_CCER_CC2NP_Pos)                 /*!< 0x00000080 */
#define TIM_CCER_CC2NP            TIM_CCER_CC2NP_Msk                            /*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos         (8U)
#define TIM_CCER_CC3E_Msk         (0x1UL << TIM_CCER_CC3E_Pos)                  /*!< 0x00000100 */
#define TIM_CCER_CC3E             TIM_CCER_CC3E_Msk                             /*!<Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos         (9U)
#define TIM_CCER_CC3P_Msk         (0x1UL << TIM_CCER_CC3P_Pos)                  /*!< 0x00000200 */
#define TIM_CCER_CC3P             TIM_CCER_CC3P_Msk                             /*!<Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos        (10U)
#define TIM_CCER_CC3NE_Msk        (0x1UL << TIM_CCER_CC3NE_Pos)                 /*!< 0x00000400 */
#define TIM_CCER_CC3NE            TIM_CCER_CC3NE_Msk                            /*!<Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos        (11U)
#define TIM_CCER_CC3NP_Msk        (0x1UL << TIM_CCER_CC3NP_Pos)                 /*!< 0x00000800 */
#define TIM_CCER_CC3NP            TIM_CCER_CC3NP_Msk                            /*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos         (12U)
#define TIM_CCER_CC4E_Msk         (0x1UL << TIM_CCER_CC4E_Pos)                  /*!< 0x00001000 */
#define TIM_CCER_CC4E             TIM_CCER_CC4E_Msk                             /*!<Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos         (13U)
#define TIM_CCER_CC4P_Msk         (0x1UL << TIM_CCER_CC4P_Pos)                  /*!< 0x00002000 */
#define TIM_CCER_CC4P             TIM_CCER_CC4P_Msk                             /*!<Capture/Compare 4 output Polarity */
#define TIM_CCER_CC4NP_Pos        (15U)
#define TIM_CCER_CC4NP_Msk        (0x1UL<<TIM_CCER_CC4NP_Pos)                      /*!< 0x00008000 */
#define TIM_CCER_CC4NP            TIM_CCER_CC4NP_Msk                               
#define TIM_CCER_CC5E_Pos         (16U)
#define TIM_CCER_CC5E_Msk         (0x1UL<<TIM_CCER_CC5E_Pos)                       /*!< 0x00010000 */
#define TIM_CCER_CC5E             TIM_CCER_CC5E_Msk                                
#define TIM_CCER_CC5P_Pos         (17U)
#define TIM_CCER_CC5P_Msk         (0x1UL<<TIM_CCER_CC5P_Pos)                       /*!< 0x00020000 */
#define TIM_CCER_CC5P             TIM_CCER_CC5P_Msk                                
#define TIM_CCER_CC6E_Pos         (20U)
#define TIM_CCER_CC6E_Msk         (0x1UL<<TIM_CCER_CC6E_Pos)                       /*!< 0x00100000 */
#define TIM_CCER_CC6E             TIM_CCER_CC6E_Msk                                
#define TIM_CCER_CC6P_Pos         (21U)
#define TIM_CCER_CC6P_Msk         (0x1UL<<TIM_CCER_CC6P_Pos)                       /*!< 0x00200000 */
#define TIM_CCER_CC6P             TIM_CCER_CC6P_Msk                                

/*******************  Bit definition for TIM_CNT register  *******************/
#define TIM_CNT_CNT_Pos           (0U)
#define TIM_CNT_CNT_Msk           (0xFFFFUL << TIM_CNT_CNT_Pos)                /*!< 0x0000FFFF */
#define TIM_CNT_CNT               TIM_CNT_CNT_Msk                              /*!<Counter Value */

/*******************  Bit definition for TIM_PSC register  *******************/
#define TIM_PSC_PSC_Pos           (0U)
#define TIM_PSC_PSC_Msk           (0xFFFFUL << TIM_PSC_PSC_Pos)                /*!< 0x0000FFFF */
#define TIM_PSC_PSC               TIM_PSC_PSC_Msk                              /*!<Prescaler Value */

/*******************  Bit definition for TIM_ARR register  *******************/
#define TIM_ARR_ARR_Pos           (0U)
#define TIM_ARR_ARR_Msk           (0xFFFFUL << TIM_ARR_ARR_Pos)                /*!< 0x0000FFFF */
#define TIM_ARR_ARR               TIM_ARR_ARR_Msk                              /*!<actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  *******************/
#define TIM_RCR_REP_Pos           (0U)
#define TIM_RCR_REP_Msk           (0xFFUL << TIM_RCR_REP_Pos)                  /*!< 0x000000FF */
#define TIM_RCR_REP               TIM_RCR_REP_Msk                              /*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  ******************/
#define TIM_CCR1_CCR1_Pos         (0U)
#define TIM_CCR1_CCR1_Msk         (0xFFFFUL << TIM_CCR1_CCR1_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR1_CCR1             TIM_CCR1_CCR1_Msk                            /*!<Capture/Compare 1 Value */
#define TIM_CCR1_CCR1_H_Pos       (16U)
#define TIM_CCR1_CCR1_H_Msk       (0xFFFFUL << TIM_CCR1_CCR1_H_Pos)            /*!< 0xFFFF0000 */
#define TIM_CCR1_CCR1_H           TIM_CCR1_CCR1_H_Msk                          /*!<Capture/Compare 1 Value */

/*******************  Bit definition for TIM_CCR2 register  ******************/
#define TIM_CCR2_CCR2_Pos         (0U)
#define TIM_CCR2_CCR2_Msk         (0xFFFFUL << TIM_CCR2_CCR2_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR2_CCR2             TIM_CCR2_CCR2_Msk                            /*!<Capture/Compare 2 Value */
#define TIM_CCR2_CCR2_H_Pos       (16U)
#define TIM_CCR2_CCR2_H_Msk       (0xFFFFUL << TIM_CCR2_CCR2_H_Pos)            /*!< 0xFFFF0000 */
#define TIM_CCR2_CCR2_H           TIM_CCR2_CCR2_H_Msk                          /*!<Capture/Compare 2 Value */

/*******************  Bit definition for TIM_CCR3 register  ******************/
#define TIM_CCR3_CCR3_Pos         (0U)
#define TIM_CCR3_CCR3_Msk         (0xFFFFUL << TIM_CCR3_CCR3_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR3_CCR3             TIM_CCR3_CCR3_Msk                            /*!<Capture/Compare 3 Value */
#define TIM_CCR3_CCR3_H_Pos       (16U)
#define TIM_CCR3_CCR3_H_Msk       (0xFFFFUL << TIM_CCR3_CCR3_H_Pos)            /*!< 0xFFFF0000 */
#define TIM_CCR3_CCR3_H            TIM_CCR3_CCR3_H_Msk                         /*!<Capture/Compare 3 Value */

/*******************  Bit definition for TIM_CCR4 register  ******************/
#define TIM_CCR4_CCR4_Pos         (0U)
#define TIM_CCR4_CCR4_Msk         (0xFFFFUL << TIM_CCR4_CCR4_Pos)              /*!< 0x0000FFFF */
#define TIM_CCR4_CCR4             TIM_CCR4_CCR4_Msk                            /*!<Capture/Compare 4 Value */

/*******************  Bit definition for TIM_BDTR register  ******************/
#define TIM_BDTR_DTG_Pos          (0U)
#define TIM_BDTR_DTG_Msk          (0xFFUL << TIM_BDTR_DTG_Pos)                  /*!< 0x000000FF */
#define TIM_BDTR_DTG              TIM_BDTR_DTG_Msk                              /*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0            (0x01UL << TIM_BDTR_DTG_Pos)                  /*!< 0x00000001 */
#define TIM_BDTR_DTG_1            (0x02UL << TIM_BDTR_DTG_Pos)                  /*!< 0x00000002 */
#define TIM_BDTR_DTG_2            (0x04UL << TIM_BDTR_DTG_Pos)                  /*!< 0x00000004 */
#define TIM_BDTR_DTG_3            (0x08UL << TIM_BDTR_DTG_Pos)                  /*!< 0x00000008 */
#define TIM_BDTR_DTG_4            (0x10UL << TIM_BDTR_DTG_Pos)                  /*!< 0x00000010 */
#define TIM_BDTR_DTG_5            (0x20UL << TIM_BDTR_DTG_Pos)                  /*!< 0x00000020 */
#define TIM_BDTR_DTG_6            (0x40UL << TIM_BDTR_DTG_Pos)                  /*!< 0x00000040 */
#define TIM_BDTR_DTG_7            (0x80UL << TIM_BDTR_DTG_Pos)                  /*!< 0x00000080 */

#define TIM_BDTR_LOCK_Pos         (8U)
#define TIM_BDTR_LOCK_Msk         (0x3UL << TIM_BDTR_LOCK_Pos)                  /*!< 0x00000300 */
#define TIM_BDTR_LOCK             TIM_BDTR_LOCK_Msk                             /*!<LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_0           (0x1UL << TIM_BDTR_LOCK_Pos)                  /*!< 0x00000100 */
#define TIM_BDTR_LOCK_1           (0x2UL << TIM_BDTR_LOCK_Pos)                  /*!< 0x00000200 */

#define TIM_BDTR_OSSI_Pos         (10U)
#define TIM_BDTR_OSSI_Msk         (0x1UL << TIM_BDTR_OSSI_Pos)                  /*!< 0x00000400 */
#define TIM_BDTR_OSSI             TIM_BDTR_OSSI_Msk                             /*!<Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos         (11U)
#define TIM_BDTR_OSSR_Msk         (0x1UL << TIM_BDTR_OSSR_Pos)                  /*!< 0x00000800 */
#define TIM_BDTR_OSSR             TIM_BDTR_OSSR_Msk                             /*!<Off-State Selection for Run mode */
#define TIM_BDTR_BKE_Pos          (12U)
#define TIM_BDTR_BKE_Msk          (0x1UL << TIM_BDTR_BKE_Pos)                   /*!< 0x00001000 */
#define TIM_BDTR_BKE              TIM_BDTR_BKE_Msk                              /*!<Break enable */
#define TIM_BDTR_BKP_Pos          (13U)
#define TIM_BDTR_BKP_Msk          (0x1UL << TIM_BDTR_BKP_Pos)                   /*!< 0x00002000 */
#define TIM_BDTR_BKP              TIM_BDTR_BKP_Msk                              /*!<Break Polarity */
#define TIM_BDTR_AOE_Pos          (14U)
#define TIM_BDTR_AOE_Msk          (0x1UL << TIM_BDTR_AOE_Pos)                   /*!< 0x00004000 */
#define TIM_BDTR_AOE              TIM_BDTR_AOE_Msk                              /*!<Automatic Output enable */
#define TIM_BDTR_MOE_Pos          (15U)
#define TIM_BDTR_MOE_Msk          (0x1UL << TIM_BDTR_MOE_Pos)                   /*!< 0x00008000 */
#define TIM_BDTR_MOE              TIM_BDTR_MOE_Msk                              /*!<Main Output enable */
                            
/********************************* Bit definition for TIM_TISEL register *******************************************/
#define TIM_TISEL_TI1SEL_Pos      (0U)
#define TIM_TISEL_TI1SEL_Msk      (0xFUL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x0000000F */
#define TIM_TISEL_TI1SEL          TIM_TISEL_TI1SEL_Msk
#define TIM_TISEL_TI1SEL_0        (0x1UL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x00000001 */
#define TIM_TISEL_TI1SEL_1        (0x2UL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x00000002 */
#define TIM_TISEL_TI1SEL_2        (0x4UL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x00000004 */
#define TIM_TISEL_TI1SEL_3        (0x8UL<<TIM_TISEL_TI1SEL_Pos)                    /*!< 0x00000008 */
#define TIM_TISEL_TI2SEL_Pos      (8U)
#define TIM_TISEL_TI2SEL_Msk      (0xFUL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000F00 */
#define TIM_TISEL_TI2SEL          TIM_TISEL_TI2SEL_Msk
#define TIM_TISEL_TI2SEL_0        (0x1UL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000100 */
#define TIM_TISEL_TI2SEL_1        (0x2UL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000200 */
#define TIM_TISEL_TI2SEL_2        (0x4UL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000400 */
#define TIM_TISEL_TI2SEL_3        (0x8UL<<TIM_TISEL_TI2SEL_Pos)                    /*!< 0x00000800 */
#define TIM_TISEL_TI3SEL_Pos      (16U)
#define TIM_TISEL_TI3SEL_Msk      (0xFUL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x000F0000 */
#define TIM_TISEL_TI3SEL          TIM_TISEL_TI3SEL_Msk
#define TIM_TISEL_TI3SEL_0        (0x1UL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x00010000 */
#define TIM_TISEL_TI3SEL_1        (0x2UL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x00020000 */
#define TIM_TISEL_TI3SEL_2        (0x4UL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x00040000 */
#define TIM_TISEL_TI3SEL_3        (0x8UL<<TIM_TISEL_TI3SEL_Pos)                    /*!< 0x00080000 */
#define TIM_TISEL_TI4SEL_Pos      (24U)
#define TIM_TISEL_TI4SEL_Msk      (0xFUL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x0F000000 */
#define TIM_TISEL_TI4SEL          TIM_TISEL_TI4SEL_Msk
#define TIM_TISEL_TI4SEL_0        (0x1UL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x01000000 */
#define TIM_TISEL_TI4SEL_1        (0x2UL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x02000000 */
#define TIM_TISEL_TI4SEL_2        (0x4UL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x04000000 */
#define TIM_TISEL_TI4SEL_3        (0x8UL<<TIM_TISEL_TI4SEL_Pos)                    /*!< 0x08000000 */

/********************************* Bit definition for TIM_AF1 register *********************************************/
#define TIM_AF1_BKINE_Pos                        (0U)
#define TIM_AF1_BKINE_Msk                        (0x1UL<<TIM_AF1_BKINE_Pos)                       /*!< 0x00000001 */
#define TIM_AF1_BKINE                            TIM_AF1_BKINE_Msk                                
#define TIM_AF1_BKCMP1E_Pos                      (1U)
#define TIM_AF1_BKCMP1E_Msk                      (0x1UL<<TIM_AF1_BKCMP1E_Pos)                     /*!< 0x00000002 */
#define TIM_AF1_BKCMP1E                          TIM_AF1_BKCMP1E_Msk                              
#define TIM_AF1_BKCMP2E_Pos                      (2U)
#define TIM_AF1_BKCMP2E_Msk                      (0x1UL<<TIM_AF1_BKCMP2E_Pos)                     /*!< 0x00000004 */
#define TIM_AF1_BKCMP2E                          TIM_AF1_BKCMP2E_Msk                              
#define TIM_AF1_BKINP_Pos                        (9U)
#define TIM_AF1_BKINP_Msk                        (0x1UL<<TIM_AF1_BKINP_Pos)                       /*!< 0x00000200 */
#define TIM_AF1_BKINP                            TIM_AF1_BKINP_Msk                                
#define TIM_AF1_BKCMP1P_Pos                      (10U)
#define TIM_AF1_BKCMP1P_Msk                      (0x1UL<<TIM_AF1_BKCMP1P_Pos)                     /*!< 0x00000400 */
#define TIM_AF1_BKCMP1P                          TIM_AF1_BKCMP1P_Msk                              
#define TIM_AF1_BKCMP2P_Pos                      (11U)
#define TIM_AF1_BKCMP2P_Msk                      (0x1UL<<TIM_AF1_BKCMP2P_Pos)                     /*!< 0x00000800 */
#define TIM_AF1_BKCMP2P                          TIM_AF1_BKCMP2P_Msk                              
#define TIM_AF1_ETRSEL_Pos                       (14U)
#define TIM_AF1_ETRSEL_Msk                       (0xFUL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x0003C000 */
#define TIM_AF1_ETRSEL                           TIM_AF1_ETRSEL_Msk
#define TIM_AF1_ETRSEL_0                         (0x1UL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x00004000 */
#define TIM_AF1_ETRSEL_1                         (0x2UL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x00008000 */
#define TIM_AF1_ETRSEL_2                         (0x4UL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x00010000 */
#define TIM_AF1_ETRSEL_3                         (0x8UL<<TIM_AF1_ETRSEL_Pos)                      /*!< 0x00020000 */
#define TIM_AF1_INTR_SEL_Pos                     (18U)
#define TIM_AF1_INTR_SEL_Msk                     (0x3UL<<TIM_AF1_INTR_SEL_Pos)                    /*!< 0x000C0000 */
#define TIM_AF1_INTR_SEL                         TIM_AF1_INTR_SEL_Msk
#define TIM_AF1_INTR_SEL_0                       (0x1UL<<TIM_AF1_INTR_SEL_Pos)                    /*!< 0x00040000 */
#define TIM_AF1_INTR_SEL_1                       (0x2UL<<TIM_AF1_INTR_SEL_Pos)                    /*!< 0x00080000 */
#define TIM_AF1_PWM_PHS_EN_Pos                   (20U)
#define TIM_AF1_PWM_PHS_EN_Msk                   (0x1UL<<TIM_AF1_PWM_PHS_EN_Pos)                  /*!< 0x00100000 */
#define TIM_AF1_PWM_PHS_EN                       TIM_AF1_PWM_PHS_EN_Msk                           

/********************************* Bit definition for TIM_AF2 register *********************************************/
#define TIM_AF2_OCRSEL_Pos                       (16U)
#define TIM_AF2_OCRSEL_Msk                       (0x7UL<<TIM_AF2_OCRSEL_Pos)                      /*!< 0x00070000 */
#define TIM_AF2_OCRSEL                           TIM_AF2_OCRSEL_Msk
#define TIM_AF2_OCRSEL_0                         (0x1UL<<TIM_AF2_OCRSEL_Pos)                      /*!< 0x00010000 */
#define TIM_AF2_OCRSEL_1                         (0x2UL<<TIM_AF2_OCRSEL_Pos)                      /*!< 0x00020000 */
#define TIM_AF2_OCRSEL_2                         (0x4UL<<TIM_AF2_OCRSEL_Pos)                      /*!< 0x00040000 */

/******************************************************************************/
/*                                                                            */
/*                         Low Power Timer (LPTIM)                            */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for LPTIM_ISR register  *******************/
#define LPTIM_ISR_ARRM_Pos          (1U)
#define LPTIM_ISR_ARRM_Msk          (0x1UL << LPTIM_ISR_ARRM_Pos)              /*!< 0x00000002 */
#define LPTIM_ISR_ARRM              LPTIM_ISR_ARRM_Msk                         /*!< Autoreload match */
#define LPTIM_ISR_ARROK_Pos         (4U)
#define LPTIM_ISR_ARROK_Msk         (0x1UL << LPTIM_ISR_ARROK_Pos)             /*!< 0x00000010 */
#define LPTIM_ISR_ARROK             LPTIM_ISR_ARROK_Msk                        /*!< Automatic overload register update OK */

/******************  Bit definition for LPTIM_ICR register  *******************/
#define LPTIM_ICR_ARRMCF_Pos        (1U)
#define LPTIM_ICR_ARRMCF_Msk        (0x1UL << LPTIM_ICR_ARRMCF_Pos)            /*!< 0x00000002 */
#define LPTIM_ICR_ARRMCF            LPTIM_ICR_ARRMCF_Msk                       /*!< Autoreload match Clear Flag */
#define LPTIM_ICR_ARROKCF_Pos       (4U)
#define LPTIM_ICR_ARROKCF_Msk       (0x1UL << LPTIM_ICR_ARROKCF_Pos)           /*!< 0x00000010 */
#define LPTIM_ICR_ARROKCF           LPTIM_ICR_ARROKCF_Msk                      /*!< Auto overload register update OK clear flag */

/******************  Bit definition for LPTIM_IER register ********************/
#define LPTIM_IER_ARRMIE_Pos        (1U)
#define LPTIM_IER_ARRMIE_Msk        (0x1UL << LPTIM_IER_ARRMIE_Pos)            /*!< 0x00000002 */
#define LPTIM_IER_ARRMIE            LPTIM_IER_ARRMIE_Msk                       /*!< Autoreload match Interrupt Enable */
#define LPTIM_IER_ARROKIE_Pos       (4U)
#define LPTIM_IER_ARROKIE_Msk       (0x1UL << LPTIM_IER_ARROKIE_Pos)            /*!< 0x00000010 */
#define LPTIM_IER_ARROKIE           LPTIM_IER_ARROKIE_Msk                       /*!< Auto overload register update OK interrupt enabled */

/******************  Bit definition for LPTIM_CFGR register *******************/
#define LPTIM_CFGR_PRESC_Pos        (9U)
#define LPTIM_CFGR_PRESC_Msk        (0x7UL << LPTIM_CFGR_PRESC_Pos)            /*!< 0x00000E00 */
#define LPTIM_CFGR_PRESC            LPTIM_CFGR_PRESC_Msk                       /*!< PRESC[2:0] bits (Clock prescaler) */
#define LPTIM_CFGR_PRESC_0          (0x1UL << LPTIM_CFGR_PRESC_Pos)            /*!< 0x00000200 */
#define LPTIM_CFGR_PRESC_1          (0x2UL << LPTIM_CFGR_PRESC_Pos)            /*!< 0x00000400 */
#define LPTIM_CFGR_PRESC_2          (0x4UL << LPTIM_CFGR_PRESC_Pos)            /*!< 0x00000800 */

#define LPTIM_CFGR_PRELOAD_Pos      (22U)
#define LPTIM_CFGR_PRELOAD_Msk      (0x1UL << LPTIM_CFGR_PRELOAD_Pos)          /*!< 0x00400000 */
#define LPTIM_CFGR_PRELOAD          LPTIM_CFGR_PRELOAD_Msk                     /*!< Reg update mode */

/******************  Bit definition for LPTIM_CR register  ********************/
#define LPTIM_CR_ENABLE_Pos         (0U)
#define LPTIM_CR_ENABLE_Msk         (0x1UL << LPTIM_CR_ENABLE_Pos)             /*!< 0x00000001 */
#define LPTIM_CR_ENABLE             LPTIM_CR_ENABLE_Msk                        /*!< LPTIMer enable */
#define LPTIM_CR_SNGSTRT_Pos        (1U)
#define LPTIM_CR_SNGSTRT_Msk        (0x1UL << LPTIM_CR_SNGSTRT_Pos)            /*!< 0x00000002 */
#define LPTIM_CR_SNGSTRT            LPTIM_CR_SNGSTRT_Msk                       /*!< Timer start in single mode */
#define LPTIM_CR_CNTSTRT_Pos        (2U)
#define LPTIM_CR_CNTSTRT_Msk        (0x1UL << LPTIM_CR_CNTSTRT_Pos)            /*!< 0x00000004 */
#define LPTIM_CR_CNTSTRT            LPTIM_CR_CNTSTRT_Msk                       /*!< Timer start in continue mode */
#define LPTIM_CR_COUNTRST_Pos       (3U)
#define LPTIM_CR_COUNTRST_Msk       (0x1UL << LPTIM_CR_COUNTRST_Pos)           /*!< 0x0000008 */
#define LPTIM_CR_COUNTRST           LPTIM_CR_COUNTRST_Msk                      /*!< The counter resets */
#define LPTIM_CR_RSTARE_Pos         (4U)
#define LPTIM_CR_RSTARE_Msk         (0x1UL << LPTIM_CR_RSTARE_Pos)             /*!< 0x00000010 */
#define LPTIM_CR_RSTARE             LPTIM_CR_RSTARE_Msk                        /*!< Reset after read enable */

/******************  Bit definition for LPTIM_ARR register  *******************/
#define LPTIM_ARR_ARR_Pos           (0U)
#define LPTIM_ARR_ARR_Msk           (0xFFFFUL << LPTIM_ARR_ARR_Pos)            /*!< 0x0000FFFF */
#define LPTIM_ARR_ARR               LPTIM_ARR_ARR_Msk                          /*!< Auto reload register */

/******************  Bit definition for LPTIM_CNT register  *******************/
#define LPTIM_CNT_CNT_Pos           (0U)
#define LPTIM_CNT_CNT_Msk           (0xFFFFUL << LPTIM_CNT_CNT_Pos)            /*!< 0x0000FFFF */
#define LPTIM_CNT_CNT               LPTIM_CNT_CNT_Msk                          /*!< Counter register */

/********************************************************************************************************************/
/********************************* PWM ******************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for PWM_CR1 register **********************************************/
#define PWM_CR1_CEN_Pos                           (0U)
#define PWM_CR1_CEN_Msk                           (0x1UL<<PWM_CR1_CEN_Pos)                          /*!< 0x00000001 */
#define PWM_CR1_CEN                               PWM_CR1_CEN_Msk                                   
#define PWM_CR1_UDIS_Pos                          (1U)
#define PWM_CR1_UDIS_Msk                          (0x1UL<<PWM_CR1_UDIS_Pos)                         /*!< 0x00000002 */
#define PWM_CR1_UDIS                              PWM_CR1_UDIS_Msk                                  
#define PWM_CR1_URS_Pos                           (2U)
#define PWM_CR1_URS_Msk                           (0x1UL<<PWM_CR1_URS_Pos)                          /*!< 0x00000004 */
#define PWM_CR1_URS                               PWM_CR1_URS_Msk                                   
#define PWM_CR1_DIR_Pos                           (4U)
#define PWM_CR1_DIR_Msk                           (0x1UL<<PWM_CR1_DIR_Pos)                          /*!< 0x00000010 */
#define PWM_CR1_DIR                               PWM_CR1_DIR_Msk                                   
#define PWM_CR1_CMS_Pos                           (5U)
#define PWM_CR1_CMS_Msk                           (0x3UL<<PWM_CR1_CMS_Pos)                          /*!< 0x00000060 */
#define PWM_CR1_CMS                               PWM_CR1_CMS_Msk
#define PWM_CR1_CMS_0                             (0x1UL<<PWM_CR1_CMS_Pos)                          /*!< 0x00000020 */
#define PWM_CR1_CMS_1                             (0x2UL<<PWM_CR1_CMS_Pos)                          /*!< 0x00000040 */
#define PWM_CR1_ARPE_Pos                          (7U)
#define PWM_CR1_ARPE_Msk                          (0x1UL<<PWM_CR1_ARPE_Pos)                         /*!< 0x00000080 */
#define PWM_CR1_ARPE                              PWM_CR1_ARPE_Msk                                  

/********************************* Bit definition for PWM_DIER register *********************************************/
#define PWM_DIER_UIE_Pos                          (0U)
#define PWM_DIER_UIE_Msk                          (0x1UL<<PWM_DIER_UIE_Pos)                         /*!< 0x00000001 */
#define PWM_DIER_UIE                              PWM_DIER_UIE_Msk                                  
#define PWM_DIER_OC1IE_Pos                        (1U)
#define PWM_DIER_OC1IE_Msk                        (0x1UL<<PWM_DIER_OC1IE_Pos)                       /*!< 0x00000002 */
#define PWM_DIER_OC1IE                            PWM_DIER_OC1IE_Msk                                                               

/********************************* Bit definition for PWM_SR register ***********************************************/
#define PWM_SR_UIF_Pos                            (0U)
#define PWM_SR_UIF_Msk                            (0x1UL<<PWM_SR_UIF_Pos)                           /*!< 0x00000001 */
#define PWM_SR_UIF                                PWM_SR_UIF_Msk                                    
#define PWM_SR_OC1IF_Pos                          (1U)
#define PWM_SR_OC1IF_Msk                          (0x1UL<<PWM_SR_OC1IF_Pos)                         /*!< 0x00000002 */
#define PWM_SR_OC1IF                              PWM_SR_OC1IF_Msk                                  

/********************************* Bit definition for PWM_EGR register **********************************************/
#define PWM_EGR_UG_Pos                            (0U)
#define PWM_EGR_UG_Msk                            (0x1UL<<PWM_EGR_UG_Pos)                           /*!< 0x00000001 */
#define PWM_EGR_UG                                PWM_EGR_UG_Msk                                    

/********************************* Bit definition for PWM_CMR register **********************************************/
#define PWM_CMR_OC1M_Pos                          (0U)
#define PWM_CMR_OC1M_Msk                          (0x3UL<<PWM_CMR_OC1M_Pos)                         /*!< 0x00000003 */
#define PWM_CMR_OC1M                              PWM_CMR_OC1M_Msk
#define PWM_CMR_OC1M_0                            (0x1UL<<PWM_CMR_OC1M_Pos)                         /*!< 0x00000001 */
#define PWM_CMR_OC1M_1                            (0x2UL<<PWM_CMR_OC1M_Pos)                         /*!< 0x00000002 */
#define PWM_CMR_OC1PE_Pos                         (8U)
#define PWM_CMR_OC1PE_Msk                         (0x1UL<<PWM_CMR_OC1PE_Pos)                        /*!< 0x00000100 */
#define PWM_CMR_OC1PE                             PWM_CMR_OC1PE_Msk                                 

/********************************* Bit definition for PWM_CER register **********************************************/
#define PWM_CER_C1E_Pos                           (0U)
#define PWM_CER_C1E_Msk                           (0x1UL<<PWM_CER_C1E_Pos)                          /*!< 0x00000001 */
#define PWM_CER_C1E                               PWM_CER_C1E_Msk                                   
#define PWM_CER_C1P_Pos                           (1U)
#define PWM_CER_C1P_Msk                           (0x1UL<<PWM_CER_C1P_Pos)                          /*!< 0x00000002 */
#define PWM_CER_C1P                               PWM_CER_C1P_Msk                                   

/********************************* Bit definition for PWM_CNT register **********************************************/
#define PWM_CNT_CNT_Pos                           (0U)
#define PWM_CNT_CNT_Msk                           (0xFFFFUL<<PWM_CNT_CNT_Pos)                       /*!< 0x0000FFFF */
#define PWM_CNT_CNT                               PWM_CNT_CNT_Msk

/********************************* Bit definition for PWM_PSC register **********************************************/
#define PWM_PSC_PSC_Pos                           (0U)
#define PWM_PSC_PSC_Msk                           (0xFFFFUL<<PWM_PSC_PSC_Pos)                       /*!< 0x0000FFFF */
#define PWM_PSC_PSC                               PWM_PSC_PSC_Msk

/********************************* Bit definition for PWM_ARR register **********************************************/
#define PWM_ARR_ARR_Pos                           (0U)
#define PWM_ARR_ARR_Msk                           (0xFFFFUL<<PWM_ARR_ARR_Pos)                       /*!< 0x0000FFFF */
#define PWM_ARR_ARR                               PWM_ARR_ARR_Msk

/********************************* Bit definition for PWM_CCR1 register *********************************************/
#define PWM_CCR1_CCR1_Pos                         (0U)
#define PWM_CCR1_CCR1_Msk                         (0xFFFFUL<<PWM_CCR1_CCR1_Pos)                     /*!< 0x0000FFFF */
#define PWM_CCR1_CCR1                             PWM_CCR1_CCR1_Msk

/******************************************************************************/
/*                                                                            */
/*                      Analog Comparators (COMP)                             */
/*                                                                            */
/******************************************************************************/
/**********************  Bit definition for COMP_CSR register  ****************/
#define COMP_CSR_EN_Pos                 (0U)
#define COMP_CSR_EN_Msk                 (0x1UL << COMP_CSR_EN_Pos)                  /*!< 0x00000001 */
#define COMP_CSR_EN                     COMP_CSR_EN_Msk                             /*!< Comparator enable */
#define COMP_CSR_INNSEL_Pos             (5U)
#define COMP_CSR_INNSEL_Msk             (0x1UL << COMP_CSR_INNSEL_Pos)              /*!< 0x00000020 */
#define COMP_CSR_INNSEL                 COMP_CSR_INNSEL_Msk                         /*!< COMP negative input select */
#define COMP_CSR_INPSEL_Pos             (9U)
#define COMP_CSR_INPSEL_Msk             (0x3UL << COMP_CSR_INPSEL_Pos)              /*!< 0x00000200 */
#define COMP_CSR_INPSEL                 COMP_CSR_INPSEL_Msk                         /*!< COMP negative input select */
#define COMP_CSR_INPSEL_0               (0x1UL << COMP_CSR_INPSEL_Pos)              /*!< 0x00000200 */
#define COMP_CSR_INPSEL_1               (0x2UL << COMP_CSR_INPSEL_Pos)              /*!< 0x00000200 */
#define COMP_CSR_WINMODE_Pos            (11U)
#define COMP_CSR_WINMODE_Msk            (0x1UL << COMP_CSR_WINMODE_Pos)             /*!< 0x00000800 */
#define COMP_CSR_WINMODE                COMP_CSR_WINMODE_Msk                        /*!< Pair of comparators window mode. Bit intended to be used with COMP common instance (COMP_Common_TypeDef) */
#define COMP_CSR_POLARITY_Pos           (15U)
#define COMP_CSR_POLARITY_Msk           (0x1UL << COMP_CSR_POLARITY_Pos)            /*!< 0x00008000 */
#define COMP_CSR_POLARITY               COMP_CSR_POLARITY_Msk                       /*!< Comparator output polarity */
#define COMP_CSR_HYST_Pos               (16U)
#define COMP_CSR_HYST_Msk               (0x1UL << COMP_CSR_HYST_Pos)                /*!< 0x00008000 */
#define COMP_CSR_HYST                   COMP_CSR_HYST_Msk                           /*!< Comparator output polarity */
#define COMP_CSR_COMP_VCDIV_Pos         (22U)
#define COMP_CSR_COMP_VCDIV_Msk         (0xFUL << COMP_CSR_COMP_VCDIV_Pos)          /*!< 0x03C00000 */
#define COMP_CSR_COMP_VCDIV             COMP_CSR_COMP_VCDIV_Msk                     /*!< VREFCMP voltage divider configuration, VREFCMP is divided from reference source */
#define COMP_CSR_COMP_VCDIV_0           (0x1UL << COMP_CSR_COMP_VCDIV_Pos)          /*!< 0x00400000 */
#define COMP_CSR_COMP_VCDIV_1           (0x2UL << COMP_CSR_COMP_VCDIV_Pos)          /*!< 0x00800000 */
#define COMP_CSR_COMP_VCDIV_2           (0x4UL << COMP_CSR_COMP_VCDIV_Pos)          /*!< 0x01000000 */
#define COMP_CSR_COMP_VCDIV_3           (0x8UL << COMP_CSR_COMP_VCDIV_Pos)          /*!< 0x02000000 */
#define COMP_CSR_COMP_VCDIV_EN_Pos      (26U)
#define COMP_CSR_COMP_VCDIV_EN_Msk      (0x1UL << COMP_CSR_COMP_VCDIV_EN_Pos)       /*!< 0x04000000 */
#define COMP_CSR_COMP_VCDIV_EN          COMP_CSR_COMP_VCDIV_EN_Msk                  /*!< VREFCMP enable, active high. */
#define COMP_CSR_COMP_VCSEL_Pos         (27U)
#define COMP_CSR_COMP_VCSEL_Msk         (0x1UL << COMP_CSR_COMP_VCSEL_Pos)          /*!< 0x08000000 */
#define COMP_CSR_COMP_VCSEL             COMP_CSR_COMP_VCSEL_Msk                     /*!< VREFCMP reference source selection */
#define COMP_CSR_COMP_OUT_Pos           (30U)
#define COMP_CSR_COMP_OUT_Msk           (0x1UL << COMP_CSR_COMP_OUT_Pos)            /*!< 0x40000000 */
#define COMP_CSR_COMP_OUT               COMP_CSR_COMP_OUT_Msk

/**********************  Bit definition for COMP_FR register  ****************/
#define COMP_FR_FLTEN_Pos          (0U)
#define COMP_FR_FLTEN_Msk          (0x1UL << COMP_FR_FLTEN_Pos)                /*!< 0x00000001 */
#define COMP_FR_FLTEN              COMP_FR_FLTEN_Msk                           /*!< Comparator filter enable */
#define COMP_FR_FLTCNT_Pos         (16U)
#define COMP_FR_FLTCNT_Msk         (0xFFFFUL << COMP_FR_FLTCNT_Pos)            /*!< 0xFFFF0000 */
#define COMP_FR_FLTCNT             COMP_FR_FLTCNT_Msk                          /*!< Comparator filter counter */

/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for USART_SR register  *******************/
#define USART_SR_PE_Pos                     (0U)
#define USART_SR_PE_Msk                     (0x1UL << USART_SR_PE_Pos)         /*!< 0x00000001 */
#define USART_SR_PE                         USART_SR_PE_Msk                    /*!< Parity Error */
#define USART_SR_FE_Pos                     (1U)
#define USART_SR_FE_Msk                     (0x1UL << USART_SR_FE_Pos)         /*!< 0x00000002 */
#define USART_SR_FE                         USART_SR_FE_Msk                    /*!< Framing Error */
#define USART_SR_NE_Pos                     (2U)
#define USART_SR_NE_Msk                     (0x1UL << USART_SR_NE_Pos)         /*!< 0x00000004 */
#define USART_SR_NE                         USART_SR_NE_Msk                    /*!< Noise Error Flag */
#define USART_SR_ORE_Pos                    (3U)
#define USART_SR_ORE_Msk                    (0x1UL << USART_SR_ORE_Pos)        /*!< 0x00000008 */
#define USART_SR_ORE                        USART_SR_ORE_Msk                   /*!< OverRun Error */
#define USART_SR_IDLE_Pos                   (4U)
#define USART_SR_IDLE_Msk                   (0x1UL << USART_SR_IDLE_Pos)       /*!< 0x00000010 */
#define USART_SR_IDLE                       USART_SR_IDLE_Msk                  /*!< IDLE line detected */
#define USART_SR_RXNE_Pos                   (5U)
#define USART_SR_RXNE_Msk                   (0x1UL << USART_SR_RXNE_Pos)       /*!< 0x00000020 */
#define USART_SR_RXNE                       USART_SR_RXNE_Msk                  /*!< Read Data Register Not Empty */
#define USART_SR_TC_Pos                     (6U)
#define USART_SR_TC_Msk                     (0x1UL << USART_SR_TC_Pos)         /*!< 0x00000040 */
#define USART_SR_TC                         USART_SR_TC_Msk                    /*!< Transmission Complete */
#define USART_SR_TXE_Pos                    (7U)
#define USART_SR_TXE_Msk                    (0x1UL << USART_SR_TXE_Pos)        /*!< 0x00000080 */
#define USART_SR_TXE                        USART_SR_TXE_Msk                   /*!< Transmit Data Register Empty */
#define USART_SR_CTS_Pos                    (9U)
#define USART_SR_CTS_Msk                    (0x1UL << USART_SR_CTS_Pos)        /*!< 0x00000200 */
#define USART_SR_CTS                        USART_SR_CTS_Msk                   /*!< CTS Flag */
#define USART_SR_ABRF_Pos                   (10U)
#define USART_SR_ABRF_Msk                   (0x1UL << USART_SR_ABRF_Pos)       /*!< 0x00000400 */
#define USART_SR_ABRF                       USART_SR_ABRF_Msk                  /*!< Auto brr detection Flag */
#define USART_SR_ABRE_Pos                   (11U)
#define USART_SR_ABRE_Msk                   (0x1UL << USART_SR_ABRE_Pos)       /*!< 0x00000800 */
#define USART_SR_ABRE                       USART_SR_ABRE_Msk                  /*!< Auto brr detection err Flag */
#define USART_SR_ABRRQ_Pos                  (12U)
#define USART_SR_ABRRQ_Msk                  (0x1UL << USART_SR_ABRRQ_Pos)      /*!< 0x00001000 */
#define USART_SR_ABRRQ                      USART_SR_ABRRQ_Msk                 /*!< Auto brr detection err Flag */

/*******************  Bit definition for USART_DR register  *******************/
#define USART_DR_DR_Pos                     (0U)
#define USART_DR_DR_Msk                     (0x1FFUL << USART_DR_DR_Pos)       /*!< 0x000001FF */
#define USART_DR_DR                         USART_DR_DR_Msk                    /*!< Data value */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_DIV_Fraction_Pos          (0U)
#define USART_BRR_DIV_Fraction_Msk          (0xFUL << USART_BRR_DIV_Fraction_Pos) /*!< 0x0000000F */
#define USART_BRR_DIV_Fraction              USART_BRR_DIV_Fraction_Msk            /*!< Fraction of USARTDIV */
#define USART_BRR_DIV_Mantissa_Pos          (4U)
#define USART_BRR_DIV_Mantissa_Msk          (0xFFFUL << USART_BRR_DIV_Mantissa_Pos) /*!< 0x0000FFF0 */
#define USART_BRR_DIV_Mantissa              USART_BRR_DIV_Mantissa_Msk              /*!< Mantissa of USARTDIV */

/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_RWU_Pos                   (1U)
#define USART_CR1_RWU_Msk                   (0x1UL << USART_CR1_RWU_Pos)       /*!< 0x00000002 */
#define USART_CR1_RWU                       USART_CR1_RWU_Msk                  /*!< Receiver wakeup */
#define USART_CR1_RE_Pos                    (2U)
#define USART_CR1_RE_Msk                    (0x1UL << USART_CR1_RE_Pos)        /*!< 0x00000004 */
#define USART_CR1_RE                        USART_CR1_RE_Msk                   /*!< Receiver Enable */
#define USART_CR1_TE_Pos                    (3U)
#define USART_CR1_TE_Msk                    (0x1UL << USART_CR1_TE_Pos)        /*!< 0x00000008 */
#define USART_CR1_TE                        USART_CR1_TE_Msk                   /*!< Transmitter Enable */
#define USART_CR1_IDLEIE_Pos                (4U)
#define USART_CR1_IDLEIE_Msk                (0x1UL << USART_CR1_IDLEIE_Pos)    /*!< 0x00000010 */
#define USART_CR1_IDLEIE                    USART_CR1_IDLEIE_Msk               /*!< IDLE Interrupt Enable */
#define USART_CR1_RXNEIE_Pos                (5U)
#define USART_CR1_RXNEIE_Msk                (0x1UL << USART_CR1_RXNEIE_Pos)    /*!< 0x00000020 */
#define USART_CR1_RXNEIE                    USART_CR1_RXNEIE_Msk               /*!< RXNE Interrupt Enable */
#define USART_CR1_TCIE_Pos                  (6U)
#define USART_CR1_TCIE_Msk                  (0x1UL << USART_CR1_TCIE_Pos)      /*!< 0x00000040 */
#define USART_CR1_TCIE                      USART_CR1_TCIE_Msk                 /*!< Transmission Complete Interrupt Enable */
#define USART_CR1_TXEIE_Pos                 (7U)
#define USART_CR1_TXEIE_Msk                 (0x1UL << USART_CR1_TXEIE_Pos)     /*!< 0x00000080 */
#define USART_CR1_TXEIE                     USART_CR1_TXEIE_Msk                /*!< des TXEIE  */
#define USART_CR1_PEIE_Pos                  (8U)
#define USART_CR1_PEIE_Msk                  (0x1UL << USART_CR1_PEIE_Pos)      /*!< 0x00000100 */
#define USART_CR1_PEIE                      USART_CR1_PEIE_Msk                 /*!< des PEIE */
#define USART_CR1_PS_Pos                    (9U)
#define USART_CR1_PS_Msk                    (0x1UL << USART_CR1_PS_Pos)        /*!< 0x00000200 */
#define USART_CR1_PS                        USART_CR1_PS_Msk                   /*!< Parity Selection */
#define USART_CR1_PCE_Pos                   (10U)
#define USART_CR1_PCE_Msk                   (0x1UL << USART_CR1_PCE_Pos)       /*!< 0x00000400 */
#define USART_CR1_PCE                       USART_CR1_PCE_Msk                  /*!< Parity Control Enable */
#define USART_CR1_WAKE_Pos                  (11U)
#define USART_CR1_WAKE_Msk                  (0x1UL << USART_CR1_WAKE_Pos)      /*!< 0x00000800 */
#define USART_CR1_WAKE                      USART_CR1_WAKE_Msk                 /*!< Wakeup method */
#define USART_CR1_M_Pos                     (12U)
#define USART_CR1_M_Msk                     (0x1UL << USART_CR1_M_Pos)         /*!< 0x00001000 */
#define USART_CR1_M                         USART_CR1_M_Msk                    /*!< Word length */
#define USART_CR1_UE_Pos                    (13U)
#define USART_CR1_UE_Msk                    (0x1UL << USART_CR1_UE_Pos)        /*!< 0x00002000 */
#define USART_CR1_UE                        USART_CR1_UE_Msk                   /*!< USART Enable */

/******************  Bit definition for USART_CR2 register  *******************/
#define USART_CR2_ADD_Pos                   (0U)
#define USART_CR2_ADD_Msk                   (0xFUL << USART_CR2_ADD_Pos)       /*!< 0x0000000F */
#define USART_CR2_ADD                       USART_CR2_ADD_Msk                  /*!< Address of the USART node */
#define USART_CR2_LBCL_Pos                  (8U)
#define USART_CR2_LBCL_Msk                  (0x1UL << USART_CR2_LBCL_Pos)      /*!< 0x00000100 */
#define USART_CR2_LBCL                      USART_CR2_LBCL_Msk                 /*!< Last Bit Clock pulse */
#define USART_CR2_CPHA_Pos                  (9U)
#define USART_CR2_CPHA_Msk                  (0x1UL << USART_CR2_CPHA_Pos)      /*!< 0x00000200 */
#define USART_CR2_CPHA                      USART_CR2_CPHA_Msk                 /*!< Clock Phase */
#define USART_CR2_CPOL_Pos                  (10U)
#define USART_CR2_CPOL_Msk                  (0x1UL << USART_CR2_CPOL_Pos)      /*!< 0x00000400 */
#define USART_CR2_CPOL                      USART_CR2_CPOL_Msk                 /*!< Clock Polarity */
#define USART_CR2_CLKEN_Pos                 (11U)
#define USART_CR2_CLKEN_Msk                 (0x1UL << USART_CR2_CLKEN_Pos)     /*!< 0x00000800 */
#define USART_CR2_CLKEN                     USART_CR2_CLKEN_Msk                /*!< Clock Enable */
#define USART_CR2_STOP_Pos                  (13U)
#define USART_CR2_STOP_Msk                  (0x1UL << USART_CR2_STOP_Pos)      /*!< 0x00002000 */
#define USART_CR2_STOP                      USART_CR2_STOP_Msk                 /*!< STOP bits*/

/******************  Bit definition for USART_CR3 register  *******************/
#define USART_CR3_EIE_Pos                   (0U)
#define USART_CR3_EIE_Msk                   (0x1UL << USART_CR3_EIE_Pos)       /*!< 0x00000001 */
#define USART_CR3_EIE                       USART_CR3_EIE_Msk                  /*!< Error Interrupt Enable */
#define USART_CR3_HDSEL_Pos                 (3U)
#define USART_CR3_HDSEL_Msk                 (0x1UL << USART_CR3_HDSEL_Pos)     /*!< 0x00000008 */
#define USART_CR3_HDSEL                     USART_CR3_HDSEL_Msk                /*!< Half-Duplex Selection */
#define USART_CR3_RTSE_Pos                  (8U)
#define USART_CR3_RTSE_Msk                  (0x1UL << USART_CR3_RTSE_Pos)      /*!< 0x00000100 */
#define USART_CR3_RTSE                      USART_CR3_RTSE_Msk                 /*!< RTS Enable */
#define USART_CR3_CTSE_Pos                  (9U)
#define USART_CR3_CTSE_Msk                  (0x1UL << USART_CR3_CTSE_Pos)      /*!< 0x00000200 */
#define USART_CR3_CTSE                      USART_CR3_CTSE_Msk                 /*!< CTS Enable */
#define USART_CR3_CTSIE_Pos                 (10U)
#define USART_CR3_CTSIE_Msk                 (0x1UL << USART_CR3_CTSIE_Pos)     /*!< 0x00000400 */
#define USART_CR3_CTSIE                     USART_CR3_CTSIE_Msk                /*!< CTS Interrupt Enable */
#define USART_CR3_OVER8_Pos                 (11U)
#define USART_CR3_OVER8_Msk                 (0x1UL <<USART_CR3_OVER8_Pos)
#define USART_CR3_OVER8                     USART_CR3_OVER8_Msk
#define USART_CR3_ABREN_Pos                 (12U)
#define USART_CR3_ABREN_Msk                 (0x1UL <<USART_CR3_ABREN_Pos)
#define USART_CR3_ABREN                     USART_CR3_ABREN_Msk
#define USART_CR3_ABRMODE_Pos               (13U)
#define USART_CR3_ABRMODE_Msk               (0x3UL <<USART_CR3_ABRMODE_Pos)
#define USART_CR3_ABRMODE                   USART_CR3_ABRMODE_Msk
#define USART_CR3_ABRMODE_0                 (0x1UL <<USART_CR3_ABRMODE_Pos)
#define USART_CR3_ABRMODE_1                 (0x2UL <<USART_CR3_ABRMODE_Pos)

/********************************************************************************************************************/
/********************************* UART *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for UART_DR register **********************************************/
#define UART_DR_DR_Pos                            (0U)
#define UART_DR_DR_Msk                            (0x1FFUL<<UART_DR_DR_Pos)                         /*!< 0x000001FF */
#define UART_DR_DR                                UART_DR_DR_Msk

/********************************* Bit definition for UART_BRR register *********************************************/
#define UART_BRR_BRR_Pos                          (0U)
#define UART_BRR_BRR_Msk                          (0xFFFFUL<<UART_BRR_BRR_Pos)                      /*!< 0x0000FFFF */
#define UART_BRR_BRR                              UART_BRR_BRR_Msk

/********************************* Bit definition for UART_SR register **********************************************/
#define UART_SR_RXNE_Pos                          (0U)
#define UART_SR_RXNE_Msk                          (0x1UL<<UART_SR_RXNE_Pos)                         /*!< 0x00000001 */
#define UART_SR_RXNE                              UART_SR_RXNE_Msk                                  
#define UART_SR_ORE_Pos                           (1U)
#define UART_SR_ORE_Msk                           (0x1UL<<UART_SR_ORE_Pos)                          /*!< 0x00000002 */
#define UART_SR_ORE                               UART_SR_ORE_Msk                                   
#define UART_SR_PE_Pos                            (2U)
#define UART_SR_PE_Msk                            (0x1UL<<UART_SR_PE_Pos)                           /*!< 0x00000004 */
#define UART_SR_PE                                UART_SR_PE_Msk                                    
#define UART_SR_FE_Pos                            (3U)
#define UART_SR_FE_Msk                            (0x1UL<<UART_SR_FE_Pos)                           /*!< 0x00000008 */
#define UART_SR_FE                                UART_SR_FE_Msk                                    
#define UART_SR_BRI_Pos                           (4U)
#define UART_SR_BRI_Msk                           (0x1UL<<UART_SR_BRI_Pos)                          /*!< 0x00000010 */
#define UART_SR_BRI                               UART_SR_BRI_Msk                                   
#define UART_SR_TDRE_Pos                          (5U)
#define UART_SR_TDRE_Msk                          (0x1UL<<UART_SR_TDRE_Pos)                         /*!< 0x00000020 */
#define UART_SR_TDRE                              UART_SR_TDRE_Msk                                  
#define UART_SR_TXE_Pos                           (6U)
#define UART_SR_TXE_Msk                           (0x1UL<<UART_SR_TXE_Pos)                          /*!< 0x00000040 */
#define UART_SR_TXE                               UART_SR_TXE_Msk                                   
#define UART_SR_ADDR_RCVD_Pos                     (8U)
#define UART_SR_ADDR_RCVD_Msk                     (0x1UL<<UART_SR_ADDR_RCVD_Pos)                    /*!< 0x00000100 */
#define UART_SR_ADDR_RCVD                         UART_SR_ADDR_RCVD_Msk                             
#define UART_SR_BUSY_Pos                          (9U)
#define UART_SR_BUSY_Msk                          (0x1UL<<UART_SR_BUSY_Pos)                         /*!< 0x00000200 */
#define UART_SR_BUSY                              UART_SR_BUSY_Msk                                  
#define UART_SR_BUSY_ERR_Pos                      (10U)
#define UART_SR_BUSY_ERR_Msk                      (0x1UL<<UART_SR_BUSY_ERR_Pos)                     /*!< 0x00000400 */
#define UART_SR_BUSY_ERR                          UART_SR_BUSY_ERR_Msk                              

/********************************* Bit definition for UART_CR1 register *********************************************/
#define UART_CR1_M_Pos                            (0U)
#define UART_CR1_M_Msk                            (0x3UL<<UART_CR1_M_Pos)                           /*!< 0x00000003 */
#define UART_CR1_M                                UART_CR1_M_Msk
#define UART_CR1_M_0                              (0x1UL<<UART_CR1_M_Pos)                           /*!< 0x00000001 */
#define UART_CR1_M_1                              (0x2UL<<UART_CR1_M_Pos)                           /*!< 0x00000002 */
#define UART_CR1_STOP_Pos                         (2U)
#define UART_CR1_STOP_Msk                         (0x1UL<<UART_CR1_STOP_Pos)                        /*!< 0x00000004 */
#define UART_CR1_STOP                             UART_CR1_STOP_Msk                                 
#define UART_CR1_PCE_Pos                          (3U)
#define UART_CR1_PCE_Msk                          (0x1UL<<UART_CR1_PCE_Pos)                         /*!< 0x00000008 */
#define UART_CR1_PCE                              UART_CR1_PCE_Msk                                  
#define UART_CR1_PS_Pos                           (4U)
#define UART_CR1_PS_Msk                           (0x1UL<<UART_CR1_PS_Pos)                          /*!< 0x00000010 */
#define UART_CR1_PS                               UART_CR1_PS_Msk                                   
#define UART_CR1_SP_Pos                           (5U)
#define UART_CR1_SP_Msk                           (0x1UL<<UART_CR1_SP_Pos)                          /*!< 0x00000020 */
#define UART_CR1_SP                               UART_CR1_SP_Msk                                   
#define UART_CR1_SBK_Pos                          (6U)
#define UART_CR1_SBK_Msk                          (0x1UL<<UART_CR1_SBK_Pos)                         /*!< 0x00000040 */
#define UART_CR1_SBK                              UART_CR1_SBK_Msk                                  
#define UART_CR1_SWAP_Pos                         (8U)
#define UART_CR1_SWAP_Msk                         (0x1UL<<UART_CR1_SWAP_Pos)                        /*!< 0x00000100 */
#define UART_CR1_SWAP                             UART_CR1_SWAP_Msk                                 
#define UART_CR1_MSBFIRST_Pos                     (9U)
#define UART_CR1_MSBFIRST_Msk                     (0x1UL<<UART_CR1_MSBFIRST_Pos)                    /*!< 0x00000200 */
#define UART_CR1_MSBFIRST                         UART_CR1_MSBFIRST_Msk                             

/********************************* Bit definition for UART_CR2 register *********************************************/
#define UART_CR2_RXNEIE_Pos                       (0U)
#define UART_CR2_RXNEIE_Msk                       (0x1UL<<UART_CR2_RXNEIE_Pos)                      /*!< 0x00000001 */
#define UART_CR2_RXNEIE                           UART_CR2_RXNEIE_Msk                               
#define UART_CR2_TDREIE_Pos                       (1U)
#define UART_CR2_TDREIE_Msk                       (0x1UL<<UART_CR2_TDREIE_Pos)                      /*!< 0x00000002 */
#define UART_CR2_TDREIE                           UART_CR2_TDREIE_Msk                               
#define UART_CR2_LSIE_Pos                         (2U)
#define UART_CR2_LSIE_Msk                         (0x1UL<<UART_CR2_LSIE_Pos)                        /*!< 0x00000004 */
#define UART_CR2_LSIE                             UART_CR2_LSIE_Msk                                 
#define UART_CR2_BUSYERRIE_Pos                    (3U)
#define UART_CR2_BUSYERRIE_Msk                    (0x1UL<<UART_CR2_BUSYERRIE_Pos)                   /*!< 0x00000008 */
#define UART_CR2_BUSYERRIE                        UART_CR2_BUSYERRIE_Msk                            
#define UART_CR2_TXEIE_Pos                        (4U)
#define UART_CR2_TXEIE_Msk                        (0x1UL<<UART_CR2_TXEIE_Pos)                       /*!< 0x00000010 */
#define UART_CR2_TXEIE                            UART_CR2_TXEIE_Msk                                

/********************************* Bit definition for UART_CR3 register *********************************************/
#define UART_CR3_M_E_Pos                          (0U)
#define UART_CR3_M_E_Msk                          (0x1UL<<UART_CR3_M_E_Pos)                         /*!< 0x00000001 */
#define UART_CR3_M_E                              UART_CR3_M_E_Msk                                  
#define UART_CR3_ADDR_MATCH_Pos                   (1U)
#define UART_CR3_ADDR_MATCH_Msk                   (0x1UL<<UART_CR3_ADDR_MATCH_Pos)                  /*!< 0x00000002 */
#define UART_CR3_ADDR_MATCH                       UART_CR3_ADDR_MATCH_Msk                           
#define UART_CR3_SEND_ADDR_Pos                    (2U)
#define UART_CR3_SEND_ADDR_Msk                    (0x1UL<<UART_CR3_SEND_ADDR_Pos)                   /*!< 0x00000004 */
#define UART_CR3_SEND_ADDR                        UART_CR3_SEND_ADDR_Msk                            
#define UART_CR3_TX_MODE_Pos                      (3U)
#define UART_CR3_TX_MODE_Msk                      (0x1UL<<UART_CR3_TX_MODE_Pos)                     /*!< 0x00000008 */
#define UART_CR3_TX_MODE                          UART_CR3_TX_MODE_Msk                              

/********************************* Bit definition for UART_RAR register *********************************************/
#define UART_RAR_RAR_Pos                          (0U)
#define UART_RAR_RAR_Msk                          (0xFFUL<<UART_RAR_RAR_Pos)                        /*!< 0x000000FF */
#define UART_RAR_RAR                              UART_RAR_RAR_Msk

/********************************* Bit definition for UART_TAR register *********************************************/
#define UART_TAR_TAR_Pos                          (0U)
#define UART_TAR_TAR_Msk                          (0xFFUL<<UART_TAR_TAR_Pos)                        /*!< 0x000000FF */
#define UART_TAR_TAR                              UART_TAR_TAR_Msk

/********************************* Bit definition for UART_BRRF register ********************************************/
#define UART_BRRF_BRRF_Pos                        (0U)
#define UART_BRRF_BRRF_Msk                        (0xFUL<<UART_BRRF_BRRF_Pos)                       /*!< 0x0000000F */
#define UART_BRRF_BRRF                            UART_BRRF_BRRF_Msk
#define UART_BRRF_BRRF_0                          (0x1UL<<UART_BRRF_BRRF_Pos)                       /*!< 0x00000001 */
#define UART_BRRF_BRRF_1                          (0x2UL<<UART_BRRF_BRRF_Pos)                       /*!< 0x00000002 */
#define UART_BRRF_BRRF_2                          (0x4UL<<UART_BRRF_BRRF_Pos)                       /*!< 0x00000004 */
#define UART_BRRF_BRRF_3                          (0x8UL<<UART_BRRF_BRRF_Pos)                       /*!< 0x00000008 */

/********************************************************************************************************************/
/********************************* VREF *****************************************************************************/
/********************************************************************************************************************/

/********************************* Bit definition for VREFBUF_CR register *******************************************/
#define VREFBUF_CR_VREFBUF_OUT_SEL_Pos            (0U)
#define VREFBUF_CR_VREFBUF_OUT_SEL_Msk            (0x3UL<<VREFBUF_CR_VREFBUF_OUT_SEL_Pos)           /*!< 0x00000003 */
#define VREFBUF_CR_VREFBUF_OUT_SEL                VREFBUF_CR_VREFBUF_OUT_SEL_Msk
#define VREFBUF_CR_VREFBUF_OUT_SEL_0              (0x1UL<<VREFBUF_CR_VREFBUF_OUT_SEL_Pos)           /*!< 0x00000001 */
#define VREFBUF_CR_VREFBUF_OUT_SEL_1              (0x2UL<<VREFBUF_CR_VREFBUF_OUT_SEL_Pos)           /*!< 0x00000002 */
#define VREFBUF_CR_VREFBUF_EN_Pos                 (3U)
#define VREFBUF_CR_VREFBUF_EN_Msk                 (0x1UL<<VREFBUF_CR_VREFBUF_EN_Pos)                /*!< 0x00000008 */
#define VREFBUF_CR_VREFBUF_EN                     VREFBUF_CR_VREFBUF_EN_Msk                         

/** @addtogroup Exported_macros
  * @{
  */

/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == ADC1)

#define IS_ADC_COMMON_INSTANCE(INSTANCE) ((INSTANCE) == ADC)

/****************************** COMP Instances ********************************/
#define IS_COMP_ALL_INSTANCE(INSTANCE) (((INSTANCE) == COMP1) || \
                                        ((INSTANCE) == COMP2))

/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC))

/********************** GPIO Alternate Function Instances *********************/
#define IS_GPIO_AF_INSTANCE(INSTANCE)   IS_GPIO_ALL_INSTANCE(INSTANCE)

/**************************** GPIO Lock Instances *****************************/
#define IS_GPIO_LOCK_INSTANCE(INSTANCE) IS_GPIO_ALL_INSTANCE(INSTANCE)

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) ((INSTANCE) == I2C1)

/************************ I2C WAKEUP FROMSTOP Instances ***********************/
#define IS_I2C_WAKEUP_FROMSTOP_INSTANCE(INSTANCE) (((INSTANCE) == I2C1))

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == IWDG)

/****************** LPTIM Instances : All supported instances *****************/
#define IS_LPTIM_INSTANCE(INSTANCE)     ((INSTANCE) == LPTIM)

/****************** LPTIM Instances : All supported instances *****************/
#define IS_LPTIM_ENCODER_INTERFACE_INSTANCE(INSTANCE) ((INSTANCE) == LPTIM)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SPI1)

/****************** TIM Instances : All supported instances *******************/
#define IS_TIM_INSTANCE(INSTANCE)       (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM14))

/****************** TIM Instances : supporting the break function *************/
#define IS_TIM_BREAK_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1)    || \
                                            ((INSTANCE) == TIM14))

/************** TIM Instances : supporting Break source selection *************/
#define IS_TIM_BREAKSOURCE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)   || \
                                               ((INSTANCE) == TIM14))

/****************** TIM Instances : supporting 2 break inputs *****************/
#define IS_TIM_BKIN2_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1)

/************* TIM Instances : at least 1 capture/compare channel *************/
#define IS_TIM_CC1_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM14))

/************ TIM Instances : at least 2 capture/compare channels *************/
#define IS_TIM_CC2_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1)

/************ TIM Instances : at least 3 capture/compare channels *************/
#define IS_TIM_CC3_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1)

/************ TIM Instances : at least 4 capture/compare channels *************/
#define IS_TIM_CC4_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1)

/****************** TIM Instances : at least 5 capture/compare channels *******/
#define IS_TIM_CC5_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1)

/****************** TIM Instances : at least 6 capture/compare channels *******/
#define IS_TIM_CC6_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1)

/******************* TIM Instances : output(s) available **********************/
#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
    ((((INSTANCE) == TIM1) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4)))           \
     ||                                        \
     (((INSTANCE) == TIM14) &&                 \
     (((CHANNEL) == TIM_CHANNEL_1))))

/****************** TIM Instances : supporting complementary output(s) ********/
#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
   ((((INSTANCE) == TIM1) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))            \
    ||                                          \
    (((INSTANCE) == TIM14) &&                   \
     ((CHANNEL) == TIM_CHANNEL_1)))

/****************** TIM Instances : supporting clock division *****************/
#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)    || \
                                                    ((INSTANCE) == TIM13)    || \
                                                    ((INSTANCE) == TIM14))

/****** TIM Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) ((INSTANCE) == TIM1)

/****** TIM Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting external clock mode 1 for TIX inputs*/
#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)      ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting internal trigger inputs(ITRX) *******/
#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)     ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting commutation event generation ***/
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)   || \
                                                     ((INSTANCE) == TIM14))

/****************** TIM Instances : supporting counting mode selection ********/
#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting encoder interface **************/
#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)  ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting Hall sensor interface **********/
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE) ((INSTANCE) == TIM1)

/**************** TIM Instances : external trigger input available ************/
#define IS_TIM_ETR_INSTANCE(INSTANCE)      ((INSTANCE) == TIM1)

/************* TIM Instances : supporting ETR source selection ***************/
#define IS_TIM_ETRSEL_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1)

/****** TIM Instances : Master mode available (TIM_CR2.MMS available )********/
#define IS_TIM_MASTER_INSTANCE(INSTANCE)   ((INSTANCE) == TIM1)

/*********** TIM Instances : Slave mode available (TIM_SMCR available )*******/
#define IS_TIM_SLAVE_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting OCxREF clear *******************/
#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)        ((INSTANCE) == TIM1)

/****************** TIM Instances : remapping capability **********************/
#define IS_TIM_REMAP_INSTANCE(INSTANCE)    ((INSTANCE) == TIM1)

/****************** TIM Instances : supporting repetition counter *************/
#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1))

/****************** TIM Instances : supporting synchronization ****************/
#define IS_TIM_SYNCHRO_INSTANCE(INSTANCE)  IS_TIM_MASTER_INSTANCE(INSTANCE)

/******************* TIM Instances : Timer input XOR function *****************/
#define IS_TIM_XOR_INSTANCE(INSTANCE)      ((INSTANCE) == TIM1)

/******************* TIM Instances : Timer input selection ********************/
#define IS_TIM_TISEL_INSTANCE(INSTANCE) (((INSTANCE) == TIM1)   || \
                                         ((INSTANCE) == TIM14))

/************ TIM Instances : Advanced timers  ********************************/
#define IS_TIM_ADVANCED_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1))

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE) ((INSTANCE) == UART1)

/******************** USART Instances : Synchronous mode **********************/
#define IS_USART_INSTANCE(INSTANCE) ((INSTANCE) == USART1)
/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/********************* USART Instances : Smard card mode ***********************/
#define IS_SMARTCARD_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/****************** UART Instances : Auto Baud Rate detection ****************/
#define IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(INSTANCE)   ((INSTANCE) == USART1)

/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(INSTANCE)   ((INSTANCE) == USART1)
/******************** UART Instances : Wake-up from Stop mode **********************/
#define IS_UART_WAKEUP_FROMSTOP_INSTANCE(INSTANCE)   ((INSTANCE) == USART1)

/****************** UART Instances : Driver Enable *****************/
#define IS_UART_DRIVER_ENABLE_INSTANCE(INSTANCE)     ((INSTANCE) == USART1)

/****************** UART Instances : SPI Slave selection mode ***************/
#define IS_UART_SPI_SLAVE_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/****************** UART Instances : Driver Enable *****************/
#define IS_UART_FIFO_INSTANCE(INSTANCE)     ((INSTANCE) == USART1)

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) ((INSTANCE) == USART1)

/******************* PWM Instances : output(s) available **********************/
#define IS_PWM_OC_INSTANCE(INSTANCE, CHANNEL) \
    (((INSTANCE) == PWM1) &&                  \
     (((CHANNEL) == PWM_CHANNEL_1)))

/****** PWM Instances : supporting external clock mode *******/
#define IS_PWM_CLOCKSOURCE_ETRMODE_INSTANCE(INSTANCE) ((INSTANCE) == PWM1)

/****************** PWM Instances : supporting counting mode selection ********/
#define IS_PWM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  ((INSTANCE) == PWM1)

/****************** PWM Instances : remapping capability **********************/
#define IS_PWM_REMAP_INSTANCE(INSTANCE)      ((INSTANCE) == PWM1)

/**
  * @}
  */

/**
 * @}
 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PY32F005X6_H */

/**
  * @}
  */

/**
* @}
*/

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/

