/* Generated configuration header file - do not edit */
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_bsp_config_reference.h
* Device(s)    : RX231
* Description  : The file r_bsp_config.h is used to configure your BSP. r_bsp_config.h should be included
*                somewhere in your package so that the r_bsp code has access to it. This file (r_bsp_config_reference.h)
*                is just a reference file that the user can use to make their own r_bsp_config.h file.
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*         : 06.01.2014 1.00    First Release
*         : 15.05.2017 1.10    Added Character(s) of the following macro definition.
*                              - BSP_CFG_MCU_PART_PACKAGE - LF = 0x1 = WFLGA/64/0.50
*                              - BSP_CFG_MCU_PART_VERSION - C = 0xC = Chip version C
*                                                             = Security function not included,
*                                                               SDHI module not included, CAN module not included.
*                              Deleted Character(s) of the following macro definition.
*                              - BSP_CFG_MCU_PART_PACKAGE - FK = 0x3 = LQFP/64/0.80
*                                                         - LJ = 0xA = TFLGA/100/0.65
*                              - BSP_CFG_MCU_PART_MEMORY_SIZE - 3 = 0x3 = 64KB/12KB/8KB
*                              Changed the value of the following macro definition.
*                              - BSP_CFG_MCU_PART_MEMORY_SIZE - Changed the value from "5 = 0x5 = 128KB/20KB/8KB"
*                                                               to "5 = 0x5 = 128KB/32KB/8KB".
*         : 01.11.2017 2.00    Added the following macro definition.
*                              - BSP_CFG_STARTUP_DISABLE
*                              Added definition not selecting clock to BSP_CFG_LPT_CLOCK_SOURCE.
*                              Changed The default value to 2 for BSP_CFG_LPT_CLOCK_SOURCE.
*         : 01.07.2018 2.01    Added the following macro definition.
*                              - BSP_CFG_CONFIGURATOR_SELECT
*                              Deleted the following macro definition.
*                              - BSP_CFG_USER_BOOT_ENABLE
*         : 27.07.2018 2.02    Added the following macro definition.
*                              - BSP_CFG_FIT_IPL_MAX
*         : 28.02.2019 3.00    Added the following macro definition.
*                              - BSP_CFG_MAIN_CLOCK_SOURCE
*                              - BSP_CFG_MOSC_WAIT_TIME
*                              - BSP_CFG_RTC_ENABLE
*                              - BSP_CFG_SOSC_DRV_CAP
*                              - BSP_CFG_SOSC_WAIT_TIME
*                              Modified comments of the following macro definition.
*                              - BSP_CFG_RTOS_USED
*                              Added support for GNUC and ICCRX.
*                              Fixed coding style.
*                              Modified comments of the following macro definition.
*                              - BSP_CFG_USB_CLOCK_SOURCE
*                              Modified USB Clock Source from System Clock to USB PLL Circuit.
*         : 23.07.2019 3.01    Modified comments of the following macro definition.
*                               - BSP_CFG_RTOS_USED : The value '1'(FreeRTOS is used.) is available.
*                              Added the following macro definition.
*                               - BSP_CFG_RTOS_SYSTEM_TIMER
*         : 26.07.2019 3.02    Added the following macro definition.
*                               - BSP_CFG_VBATT_ENABLE
*         : 08.10.2019 3.03    Added the following macro definition.
*                               - BSP_CFG_SWINT_UNIT1_ENABLE
*                               - BSP_CFG_SWINT_TASK_BUFFER_NUMBER
*                               - BSP_CFG_SWINT_IPR_INITIAL_VALUE
*                              Modified comment for added support of Renesas RTOS (RI600V4 or RI600PX).
*                              Added the following macro definition.
*                               - BSP_CFG_RENESAS_RTOS_USED
***********************************************************************************************************************/

#ifndef R_BSP_CONFIG_REF_HEADER_FILE
#define R_BSP_CONFIG_REF_HEADER_FILE

/***********************************************************************************************************************
Configuration Options
***********************************************************************************************************************/

/* Include for various workarounds. */
#include "smc_workaround.h"

/* NOTE:
 The default settings are the same as when using RSKRX231.
 Change to the settings for the user board.
*/

/* Start up select
   0 = Enable BSP startup program.
   1 = Disable BSP startup program. (e.g. Using user startup program.)
   NOTE: This setting is available only when using CCRX. */
#define BSP_CFG_STARTUP_DISABLE (0)

/* Enter the product part number for your MCU. This information will be used to obtain information about your MCU such 
   as package and memory size.
   To help parse this information, the part number will be defined using multiple macros.
   R 5 F 52 31 8 A D FP
   | | | |  |  | | | |  Macro Name                      Description
   | | | |  |  | | | |__BSP_CFG_MCU_PART_PACKAGE      = Package type, number of pins, and pin pitch
   | | | |  |  | | |____not used                      = Products with wide temperature range (D:-40-85C G:-40-105C)
   | | | |  |  | |______BSP_CFG_MCU_PART_VERSION      = Version of chip (A or B or C)
   | | | |  |  |________BSP_CFG_MCU_PART_MEMORY_SIZE  = ROM, RAM, and Data Flash Capacity
   | | | |  |___________BSP_CFG_MCU_PART_GROUP        = Group name
   | | | |______________BSP_CFG_MCU_PART_SERIES       = Series name
   | | |________________BSP_CFG_MCU_PART_MEMORY_TYPE  = Type of memory (Flash)
   | |__________________not used                      = Renesas MCU
   |____________________not used                      = Renesas semiconductor product.
*/

/* Package type. Set the macro definition based on values below:
   Character(s) = Value for macro = Package Type/Number of Pins/Pin Pitch
   FP           = 0x0             = LFQFP/100/0.50
   LF           = 0x1             = WFLGA/64/0.50
   FM           = 0x2             = LFQFP/64/0.50
   ND           = 0x5             = HWQFN/64/0.50
   FL           = 0x6             = LFQFP/48/0.50
   NE           = 0x7             = HWQFN/48/0.50
   LA           = 0x9             = TFLGA/100/0.50
*/

#define BSP_CFG_MCU_PART_PACKAGE        (0x0) /* Generated value. Do not edit this manually */

/* Chip version.
   Character(s) = Value for macro =
   A            = 0xA             = Chip version A
                                  = Security function not included, SDHI module not included, CAN module included.
   B            = 0xB             = Chip version B
                                  = Security function included, SDHI module included, CAN module included.
   C            = 0xC             = Chip version C
                                  = Security function not included, SDHI module not included, CAN module not included.
*/
#define BSP_CFG_MCU_PART_VERSION        (0xA) /* Generated value. Do not edit this manually */

/* ROM, RAM, and Data Flash Capacity.
   Character(s) = Value for macro = ROM Size/Ram Size/Data Flash Size
   8            = 0x8             = 512KB/64KB/8KB
   7            = 0x7             = 384KB/64KB/8KB
   6            = 0x6             = 256KB/32KB/8KB
   5            = 0x5             = 128KB/32KB/8KB
*/
#define BSP_CFG_MCU_PART_MEMORY_SIZE    (0x8)

/* Group name.
   Character(s) = Value for macro = Description
   31           = 0x0             = RX231 Group
*/
#define BSP_CFG_MCU_PART_GROUP          (0x0) /* Generated value. Do not edit this manually */

/* Series name.
   Character(s) = Value for macro = Description
   52           = 0x0             = RX200 Series
*/
#define BSP_CFG_MCU_PART_SERIES         (0x0) /* Generated value. Do not edit this manually */

/* Memory type.
   Character(s) = Value for macro = Description
   F            = 0x0             = Flash memory version
*/
#define BSP_CFG_MCU_PART_MEMORY_TYPE    (0x0) /* Generated value. Do not edit this manually */

/* Whether to use 1 stack or 2. RX MCUs have the ability to use 2 stacks: an interrupt stack and a user stack.
 * When using 2 stacks the user stack will be used during normal user code. When an interrupt occurs the CPU
 * will automatically shift to using the interrupt stack. Having 2 stacks can make it easier to figure out how
 * much stack space to allocate since the user does not have to worry about always having enough room on the
 * user stack for if-and-when an interrupt occurs. Some users will not want 2 stacks though because it is not
 * needed in all applications and can lead to wasted RAM (i.e. space in between stacks that is not used).
 * If only 1 stack is used then the interrupt stack is the one that will be used. If 1 stack is chosen then
 * the user may want to remove the 'SU' section from the linker sections to remove any linker warnings.
 *
 * 0 = Use 1 stack. Disable user stack. User stack size set below will be ignored.
 * 1 = Use 2 stacks. User stack and interrupt stack will both be used.
 * NOTE: This setting is available only when using CCRX and GNUC.
 *       This is invalid when using Renesas RTOS with CCRX.
 */
#define BSP_CFG_USER_STACK_ENABLE       (0)

/* If only 1 stack is chosen using BSP_CFG_USER_STACK_ENABLE then no RAM will be allocated for the user stack. */
#if BSP_CFG_USER_STACK_ENABLE == 1
/* User Stack size in bytes. 
 * NOTE: This setting is available only when using CCRX and GNUC.
 *       This is invalid when using Renesas RTOS with CCRX. */
#define BSP_CFG_USTACK_BYTES            (0x0)
#endif

/* Interrupt Stack size in bytes.
   NOTE: This setting is available only when using CCRX and GNUC. */
#define BSP_CFG_ISTACK_BYTES            (0x400)

/* Heap size in bytes.
   To disable the heap you must follow these steps:
   1) Set this macro (BSP_CFG_HEAP_BYTES) to 0.
   2) Set the macro BSP_CFG_IO_LIB_ENABLE to 0.
   3) Disable stdio from being built into the project library. This is done by going into the Renesas RX Toolchain 
      settings and choosing the Standard Library section. After that choose 'Contents' in e2 studio.
      This will present a list of modules that can be included. Uncheck the box for stdio.h.
   NOTE: This setting is available only when using CCRX and GNUC. */
#define BSP_CFG_HEAP_BYTES              (0x0)

/* Initializes C input & output library functions.
   0 = Disable I/O library initialization in resetprg.c. If you are not using stdio then use this value.
   1 = Enable I/O library initialization in resetprg.c. This is default and needed if you are using stdio.
   NOTE: This setting is available only when using CCRX. */
#define BSP_CFG_IO_LIB_ENABLE           (1)

/* If desired the user may redirect the stdio charget() and/or charput() functions to their own respective functions
   by enabling below and providing and replacing the my_sw_... function names with the names of their own functions. */
#define BSP_CFG_USER_CHARGET_ENABLED    (0)
#define BSP_CFG_USER_CHARGET_FUNCTION     my_sw_charget_function

#define BSP_CFG_USER_CHARPUT_ENABLED    (0)
#define BSP_CFG_USER_CHARPUT_FUNCTION     my_sw_charput_function

/* After reset MCU will operate in Supervisor mode. To switch to User mode, set this macro to '1'. For more information
   on the differences between these 2 modes see the CPU >> Processor Mode section of your MCU's hardware manual.
   0 = Stay in Supervisor mode.
   1 = Switch to User mode.
   NOTE: This is invalid when using Renesas RTOS with CCRX.
*/
#define BSP_CFG_RUN_IN_USER_MODE        (0)

/* Set your desired ID code. NOTE, leave at the default (all 0xFF's) if you do not wish to use an ID code. If you set 
   this value and program it into the MCU then you will need to remember the ID code because the debugger will ask for 
   it when trying to connect. Note that the E1/E20 will ignore the ID code when programming the MCU during debugging.
   If you set this value and then forget it then you can clear the ID code by connecting up in serial boot mode using 
   FDT. The ID Code is 16 bytes long. The macro below define the ID Code in 4-byte sections. */
/* Lowest 4-byte section, address 0xFFFFFFA0. From MSB to LSB: Control Code, ID code 1, ID code 2, ID code 3. */
#define BSP_CFG_ID_CODE_LONG_1          (0xFFFFFFFF)
/* 2nd ID Code section, address 0xFFFFFFA4. From MSB to LSB: ID code 4, ID code 5, ID code 6, ID code 7. */
#define BSP_CFG_ID_CODE_LONG_2          (0xFFFFFFFF)
/* 3rd ID Code section, address 0xFFFFFFA8. From MSB to LSB: ID code 8, ID code 9, ID code 10, ID code 11. */
#define BSP_CFG_ID_CODE_LONG_3          (0xFFFFFFFF)
/* 4th ID Code section, address 0xFFFFFFAC. From MSB to LSB: ID code 12, ID code 13, ID code 14, ID code 15. */
#define BSP_CFG_ID_CODE_LONG_4          (0xFFFFFFFF)

/* Clock source select (CKSEL).
   0 = Low Speed On-Chip Oscillator  (LOCO)
   1 = High Speed On-Chip Oscillator (HOCO)
   2 = Main Clock Oscillator
   3 = Sub-Clock Oscillator
   4 = PLL Circuit
*/
#define BSP_CFG_CLOCK_SOURCE            (1) /* Generated value. Do not edit this manually */

/* USB Clock source select (UPLLCR.UCKUPLLSEL).
   0 = System Clock (PLL Circuit/No division)
   1 = USB PLL Circuit (default)
*/ 
#define BSP_CFG_USB_CLOCK_SOURCE        (0) /* Generated value. Do not edit this manually */

/* LPT (Low Power Timer) Clock source select (LPTCR1.LPCNTCKSEL)
   0 = Sub-clock
   1 = IWDT
   2 = LPT non use
*/
#define BSP_CFG_LPT_CLOCK_SOURCE        (2) /* Generated value. Do not edit this manually */

/* Main clock Oscillator Switching (MOSEL).
   0 = Resonator
   1 = External clock input
*/
#define BSP_CFG_MAIN_CLOCK_SOURCE       (0) /* Generated value. Do not edit this manually */

/* The sub-clock oscillation control for using the RTC.
   When '1' is selected, the registers related to RTC are initialized and the sub-clock oscillator is operated.
   0 = The RTC is not to be used.
   1 = The RTC is to be used.
*/
#define BSP_CFG_RTC_ENABLE              (0) /* Generated value. Do not edit this manually */

/* Sub-Clock Oscillator Drive Capacity Control (RTCDV).
   0 = Drive capacity for standard CL. (default)
   1 = Drive capacity for low CL.
*/
#define BSP_CFG_SOSC_DRV_CAP            (0) /* Generated value. Do not edit this manually */

/* The input clock frequency is specified and then the system clocks are set by specifying the multipliers used. The
   multiplier settings are used to set the clock registers in resetprg.c. If a 20MHz clock is used and the 
   ICLK is 50MHz, PCLKB is 25MHz, FCLK is 50MHz, PCLKD is 50MHz, and BCLK is 25MHz then the 
   settings would be:

   BSP_CFG_XTAL_HZ  = 8000000
   BSP_CFG_PLL_DIV  = 2        (divide by 2)
   BSP_CFG_PLL_MUL  = 13.5     (4MHz x 13.5 = 54MHz)
   BSP_CFG_UPLL_DIV = 2        (divide by 2)
   BSP_CFG_UPLL_MUL = 12       (4MHz x 12 = 48MHz)
   BSP_CFG_ICK_DIV  = 1      : System Clock (ICLK)        = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_ICK_DIV)  = 54MHz
   BSP_CFG_PCKA_DIV = 1      : Peripheral Clock B (PCLKA) = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_PCKA_DIV) = 54MHz
   BSP_CFG_PCKB_DIV = 2      : Peripheral Clock B (PCLKB) = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_PCKB_DIV) = 27MHz
   BSP_CFG_PCKD_DIV = 2      : Peripheral Clock D (PCLKD) = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_PCKB_DIV) = 27MHz
   BSP_CFG_FCK_DIV  = 2      : Flash IF Clock (FCLK)      = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_FCK_DIV)  = 27MHz
   BSP_CFG_BCK_DIV  = 2      : External Bus Clock (BCK)   = 
                               (((BSP_CFG_XTAL_HZ/BSP_CFG_PLL_DIV) * BSP_CFG_PLL_MUL) / BSP_CFG_BCK_DIV)  = 27MHz
*/
/* Input clock frequency in Hz (XTAL or EXTAL). */
#define BSP_CFG_XTAL_HZ                 (8000000) /* Generated value. Do not edit this manually */

/* PLL Input Frequency Divider Select (PLIDIV).
   Available divisors = /1 (no division), /2, /4
*/
#define BSP_CFG_PLL_DIV                 (2) /* Generated value. Do not edit this manually */

/* PLL Frequency Multiplication Factor Select (STC).
   Available multipliers = x4, x4.5, x5, x5.5, x6, x6.5, x7, x7.5, x8, x8.5, x9, x9.5,
                           x10, x10.5, x11, x11.5, x12, x12.5, x13, x13.5
*/
#define BSP_CFG_PLL_MUL                 (13.5) /* Generated value. Do not edit this manually */

/* USB PLL Input Frequency Divider Select (UPLIDIV).
   Available divisors = /1 (no division), /2, /4
*/
#define BSP_CFG_UPLL_DIV                (2) /* Generated value. Do not edit this manually */

/* USB PLL Frequency Multiplication Factor Select (USTC).
   Available multipliers = x4, x6, x8, x12
*/
#define BSP_CFG_UPLL_MUL                (12) /* Generated value. Do not edit this manually */

/* System Clock Divider (ICK).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_ICK_DIV                 (1) /* Generated value. Do not edit this manually */

/* Peripheral Module Clock A Divider (PCKA).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_PCKA_DIV                (1) /* Generated value. Do not edit this manually */

/* Peripheral Module Clock B Divider (PCKB).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_PCKB_DIV                (2) /* Generated value. Do not edit this manually */

/* Peripheral Module Clock D Divider (PCKD).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_PCKD_DIV                (1) /* Generated value. Do not edit this manually */

/* External Bus Clock Divider (BCK).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_BCK_DIV                 (2) /* Generated value. Do not edit this manually */

/* Flash IF Clock Divider (FCK).
   Available divisors = /1 (no division), /2, /4, /8, /16, /32, /64
*/
#define BSP_CFG_FCK_DIV                 (2) /* Generated value. Do not edit this manually */

/* Configure BCLK output pin (only effective when external bus enabled)
   Values 0=no output, 1 = BCK frequency, 2= BCK/2 frequency */
#define BSP_CFG_BCLK_OUTPUT             (0) /* Generated value. Do not edit this manually */

/* Main Clock Oscillator Wait Time (MOSCWTCR).
   Set these bits to select the oscillation stabilization wait time of the main clock oscillator.
   Set the main clock oscillation stabilization time to longer than or equal to the stabilization 
   time recommended by the oscillator manufacturer. When the main clock is externally input, 
   set these bits to 00000b because the oscillation stabilization time is not required.

   00000b: Wait time = 2 cycles (0.5 us)
   00001b: Wait time = 1024 cycles (256 us)
   00010b: Wait time = 2048 cycles (512 us)
   00011b: Wait time = 4096 cycles (1.024 ms)
   00100b: Wait time = 8192 cycles (2.048 ms)
   00101b: Wait time = 16384 cycles (4.096 ms)
   00110b: Wait time = 32768 cycles (8.192 ms)
   00111b: Wait time = 65536 cycles (16.384 ms)
   Settings other than above are prohibited.
   Wait time when LOCO = 4.0 MHz (0.25 us, TYP.)
*/
#define BSP_CFG_MOSC_WAIT_TIME          (0x04) /* Generated value. Do not edit this manually */

/* Sub-Clock Oscillator Wait Time (Use R_BSP_SoftwareDelay).
   Setting delay init is in milliseconds.
*/
#define BSP_CFG_SOSC_WAIT_TIME          (1482)

/* The HOCO can operate at several different frequencies. Choose which one using the macro below.
   Available frequency settings:
   0 = 32MHz     (default)
   3 = 54MHz
*/
#define BSP_CFG_HOCO_FREQUENCY          (3) /* Generated value. Do not edit this manually */

/* Configure WDT and IWDT settings.
   OFS0 - Option Function Select Register 0
   b31:b29 Reserved (set to 1)
   b28     WDTRSTIRQS - WDT Reset Interrupt Request - What to do on underflow (0=take interrupt, 1=reset MCU)
   b27:b26 WDTRPSS - WDT Window Start Position Select - (0=25%, 1=50%, 2=75%, 3=100%,don't use)
   b25:b24 WDTRPES - WDT Window End Position Select - (0=75%, 1=50%, 2=25%, 3=0%,don't use)
   b23:b20 WDTCKS - WDT Clock Frequency Division Ratio - (1=/4, 4=/64, 0xF=/128, 6=/512, 7=/2048, 8=/8192)
   b19:b18 WDTTOPS - WDT Timeout Period Select - (0=1024 cycles, 1=4096, 2=8192, 3=16384)
   b17     WDTSTRT - WDT Start Mode Select - (0=auto-start after reset, halt after reset)
   b16:b15 Reserved (set to 1)
   b14     IWDTSLCSTP - IWDT Sleep Mode Count Stop Control - (0=can't stop count, 1=stop w/some low power modes)
   b13     Reserved (set to 1)
   b12     IWDTRSTIRQS - IWDT Reset Interrupt Request - What to do on underflow (0=take interrupt, 1=reset MCU)
   b11:b10 IWDTRPSS - IWDT Window Start Position Select - (0=25%, 1=50%, 2=75%, 3=100%,don't use)
   b9:b8   IWDTRPES - IWDT Window End Position Select - (0=75%, 1=50%, 2=25%, 3=0%,don't use)
   b7:b4   IWDTCKS - IWDT Clock Frequency Division Ratio - (0=none, 2=/16, 3 = /32, 4=/64, 0xF=/128, 5=/256)
   b3:b2   IWDTTOPS - IWDT Timeout Period Select - (0=128 cycles, 1=512, 2=1024, 3=2048)
   b1      IWDTSTRT - IWDT Start Mode Select - (0=auto-start after reset, halt after reset)
   b0      Reserved (set to 1)
   Default value is 0xFFFFFFFF.
*/
#define BSP_CFG_OFS0_REG_VALUE  (0xFFFFFFFF) /* Generated value. Do not edit this manually */

/* Configure whether voltage detection 0 circuit and HOCO are enabled after reset.
   OFS1 - Option Function Select Register 1
   b31:b9 Reserved (set to 1)
   b8     HOCOEN - Enable/disable HOCO oscillation after a reset (0=enable, 1=disable)
   b7:b4  Reserved (set to 1)
   b3     FASTSTUP - PowerOn fast startup time (0=fast, 1=normal)
   b2     LVDAS - Choose to enable/disable Voltage Detection 0 Circuit after a reset (0=enable, 1=disable)
   b1:b0  VDSEL - Voltage Detection 0 Level Select (0=3.84V, 1=2.82V, 2=2.51V, 3=1.90V)
   NOTE: If HOCO oscillation is enabled by OFS1.HOCOEN, HOCO frequency is 32MHz.
         BSP_CFG_HOCO_FREQUENCY should be default value.
   Default value is 0xFFFFFFFF.
*/
#define BSP_CFG_OFS1_REG_VALUE  (0xFFFFFFFF) /* Generated value. Do not edit this manually */

/* ROM Code Protection is a feature that can prohibit PROM programmers from reading or writing flash memory.
   There are 3 different options that can be chosen:
   0    = ROM code protection 1 = Both reading and writing to the user area and user boot area are prohibited.
   1    = ROM code protection 2 = Reading from the user area and user boot area are prohibited.
   Else = Protection disabled   = Reading and writing are allowed.
*/
#define BSP_CFG_ROM_CODE_PROTECT_VALUE  (0xFFFFFFFF)

/* This macro lets other modules no if a RTOS is being used.
   0 = RTOS is not used.
   1 = FreeRTOS is used.
   2 = embOS is used.(This is not available.)
   3 = MicroC_OS is used.(This is not available.)
   4 = Renesas ITRON OS (RI600V4 or RI600PX) is used.
*/
#if !defined(BSP_CFG_RTOS_USED) || (BSP_CFG_RTOS_USED == 0)
#if defined(BSP_CFG_RTOS_USED)
#undef BSP_CFG_RTOS_USED
#endif
#define BSP_CFG_RTOS_USED               (1) /* Generated value. Do not edit this manually */
#endif

/* This macro is used to select which Renesas ITRON OS.
   0 = RI600V4 is used.
   1 = RI600PX is used.
*/
#define BSP_CFG_RENESAS_RTOS_USED       (0)

/* This macro is used to select which CMT channel used for system timer of RTOS.
 * The setting of this macro is only valid if the macro BSP_CFG_RTOS_USED is set to a value other than 0. */
#if BSP_CFG_RTOS_USED != 0
/* Setting value.
 * 0      = CMT channel 0 used for system timer of RTOS (recommended to be used for RTOS).
 * 1      = CMT channel 1 used for system timer of RTOS.
 * 2      = CMT channel 2 used for system timer of RTOS.
 * 3      = CMT channel 3 used for system timer of RTOS.
 * Others = Invalid.
 * NOTE: This is invalid when using Renesas RTOS with CCRX.
 */
#define BSP_CFG_RTOS_SYSTEM_TIMER       (0)
#endif

/* By default modules will use global locks found in mcu_locks.c. If the user is using a RTOS and would rather use its
   locking mechanisms then they can change this macro.
   NOTE: If '1' is chosen for this macro then the user must also change the next macro 'BSP_CFG_USER_LOCKING_TYPE'.
   0 = Use default locking (non-RTOS)
   1 = Use user defined locking mechanism.
*/
#define BSP_CFG_USER_LOCKING_ENABLED    (0)

/* If the user decides to use their own locking mechanism with FIT modules then they will need to redefine the typedef
   that is used for the locks. If the user is using a RTOS then they would likely redefine the typedef to be 
   a semaphore/mutex type of their RTOS. Use the macro below to set the type that will be used for the locks.
   NOTE: If BSP_CFG_USER_LOCKING_ENABLED == 0 then this typedef is ignored.
   NOTE: Do not surround the type with parentheses '(' ')'.
*/
#define BSP_CFG_USER_LOCKING_TYPE       bsp_lock_t

/* If the user decides to use their own locking mechanism with FIT modules then they will need to define the functions
   that will handle the locking and unlocking. These functions should be defined below.
   If BSP_CFG_USER_LOCKING_ENABLED is != 0:
   R_BSP_HardwareLock(mcu_lock_t hw_index) will call BSP_CFG_USER_LOCKING_HW_LOCK_FUNCTION(mcu_lock_t hw_index)
   R_BSP_HardwareUnlock(mcu_lock_t hw_index) will call BSP_CFG_USER_LOCKING_HW_UNLOCK_FUNCTION(mcu_lock_t hw_index)
       NOTE:With these functions the index into the array holding the global hardware locks is passed as the parameter.
   R_BSP_SoftwareLock(BSP_CFG_USER_LOCKING_TYPE * plock) will call 
   BSP_CFG_USER_LOCKING_SW_LOCK_FUNCTION(BSP_CFG_USER_LOCKING_TYPE * plock)
   R_BSP_SoftwareUnlock(BSP_CFG_USER_LOCKING_TYPE * plock) will call 
   BSP_CFG_USER_LOCKING_SW_UNLOCK_FUNCTION(BSP_CFG_USER_LOCKING_TYPE * plock)
       NOTE:With these functions the actual address of the lock to use is passed as the parameter.
   NOTE: These functions must return a boolean. If lock was obtained or released successfully then return true. Else, 
         return false.
   NOTE: If BSP_CFG_USER_LOCKING_ENABLED == 0 then this typedef is ignored.
   NOTE: Do not surround the type with parentheses '(' ')'.
*/
#define BSP_CFG_USER_LOCKING_HW_LOCK_FUNCTION      my_hw_locking_function
#define BSP_CFG_USER_LOCKING_HW_UNLOCK_FUNCTION    my_hw_unlocking_function
#define BSP_CFG_USER_LOCKING_SW_LOCK_FUNCTION      my_sw_locking_function
#define BSP_CFG_USER_LOCKING_SW_UNLOCK_FUNCTION    my_sw_unlocking_function

/* If the user would like to determine if a warm start reset has occurred, then they may enable one or more of the
   following callback definitions AND provide a call back function name for the respective callback
   function (to be defined by the user). Setting BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED = 1 will result
   in a callback to the user defined my_sw_warmstart_prec_function just prior to the initialization of the C
   runtime environment by resetprg.
   Setting BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED = 1 will result in a callback to the user defined
   my_sw_warmstart_postc_function just after the initialization of the C runtime environment by resetprg.
*/
#define BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_PRE_C_FUNCTION     my_sw_warmstart_prec_function

#define BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_POST_C_FUNCTION    my_sw_warmstart_postc_function

/* By default FIT modules will check input parameters to be valid. This is helpful during development but some users
   will want to disable this for production code. The reason for this would be to save execution time and code space.
   This macro is a global setting for enabling or disabling parameter checking. Each FIT module will also have its
   own local macro for this same purpose. By default the local macros will take the global value from here though
   they can be overridden. Therefore, the local setting has priority over this global setting. Disabling parameter
   checking should only used when inputs are known to be good and the increase in speed or decrease in code space is 
   needed.
   0 = Global setting for parameter checking is disabled.
   1 = Global setting for parameter checking is enabled (Default).
*/
#define BSP_CFG_PARAM_CHECKING_ENABLE               (1)

/* This macro is used to define the voltage that is supplied to the MCU (Vcc). This macro is defined in millivolts. This
   macro does not actually change anything on the MCU. Some FIT modules need this information so it is defined here. */
#define BSP_CFG_MCU_VCC_MV                          (3300) /* Generated value. Do not edit this manually */

/* Allow initialization of auto-generated peripheral initialization code by Smart Configurator tool.
   When not using the Smart Configurator, set the value of BSP_CFG_CONFIGURATOR_SELECT to 0.
   0 = Disabled (default)
   1 = Smart Configurator initialization code used
*/
#define BSP_CFG_CONFIGURATOR_SELECT                 (1) /* Generated value. Do not edit this manually */

/* For some BSP functions, it is necessary to ensure that, while these functions are executing, interrupts from other 
   FIT modules do not occur. By controlling the IPL, these functions disable interrupts that are at or below the 
   specified interrupt priority level.
   This macro sets the IPL. Range is 0x0 - 0xF.
   Please set this macro more than IPR for other FIT module interrupts.
   The default value is 0xF (maximum value).
   Don't change if there is no special processing with higher priority than all fit modules.
*/
#define BSP_CFG_FIT_IPL_MAX                         (0xF)

/* Defines if the battery backup function is enabled in the current application.
   0 = battery backup function is disabled.
   1 = battery backup function is enabled.
*/
#define BSP_CFG_VBATT_ENABLE                        (0)

/* Software Interrupt (SWINT).
   0 = Software interrupt is not used.
   1 = Software interrupt is used.
   NOTE: When this macro is set to 1, the software interrupt is initialized in bsp startup routine. 
*/
#define BSP_CFG_SWINT_UNIT1_ENABLE    (0)

/* Software Interrupt Task Buffer Number.
   For software interrupt, this value is number of buffering user tasks.
   So user can increase this value if user system would have many software interrupt tasks
   and user system has enough buffer. This value requires 9 byte per task.
   NOTE: This setting is common to all units. It can not be set individually. 
         The maximum value is 254.
*/
#define BSP_CFG_SWINT_TASK_BUFFER_NUMBER     (8)

/* Initial value of the software interrupt priority.
   For software interrupt, this value is interrupt priority. Range is 0x0 - 0xF.
   NOTE: This setting is common to all units. It can not be set individually. 
         Please be careful that this setting is the initial value of the interrupt priority register(IPR).
         It is possible to dynamically change the IPR.
*/
#define BSP_CFG_SWINT_IPR_INITIAL_VALUE     (0x1)

#endif /* R_BSP_CONFIG_REF_HEADER_FILE */

