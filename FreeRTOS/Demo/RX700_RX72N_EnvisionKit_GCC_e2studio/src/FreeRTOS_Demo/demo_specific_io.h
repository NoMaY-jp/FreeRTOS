/*
 * FreeRTOS Kernel V10.3.0
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef LED_IO_H
#define LED_IO_H

/* Select one of the following defines. Note that you must change the target device
by using e2 studio's menu: 'Project' --> 'Change Device'. */

	//#define RSKRX72N
	#define EnvisionRX72N

/* Moreover, in case of GNURX project, you must exclude 'Change Device for RTOSDemo'
--> 'Project Files' --> 'src/linker_script.ld' to prevent loosing the following three
KEEP() statements int the src/linker_script.ld file. */

/*
	.text 0xFFC00000: AT(0xFFC00000)
	{
		*(.text)
		KEEP(*(.text.*ISR))
		KEEP(*(.text.*_isr))
		KEEP(*(.text.*_interrupt))
		*(.text.*)
		*(P)
		etext = .;
	} > ROM
*/

/* Board support settings. */

	#ifdef RSKRX72N

		/* R5F572NNDDBD (or R5F572NNHDBD) 224pin LFBGA */

		/* General Values */
		#define LED_ON					(0)
		#define LED_OFF 				(1)
		#define SW_PUSH 				(0)
		#define SW_RELEASE				(1)

		/* Switches */
		#define SW1 					(PORT1.PIDR.BIT.B5)
		#define SW2 					(PORT1.PIDR.BIT.B2)
		#define SW3 					(PORT0.PIDR.BIT.B7)
		#define U_GPIO_PIN_SW1			(GPIO_PORT_1_PIN_5)
		#define U_GPIO_PIN_SW2			(GPIO_PORT_1_PIN_2)
		#define U_GPIO_PIN_SW3			(GPIO_PORT_0_PIN_7)

		/* LED port settings */
		#define LED0					(PORT0.PODR.BIT.B3)
		#define LED1					(PORT0.PODR.BIT.B5)
		#define LED2					(PORT2.PODR.BIT.B6)
		#define LED3					(PORT2.PODR.BIT.B7)
		#define U_GPIO_PIN_LED0 		(GPIO_PORT_0_PIN_3)
		#define U_GPIO_PIN_LED1 		(GPIO_PORT_0_PIN_5)
		#define U_GPIO_PIN_LED2 		(GPIO_PORT_2_PIN_6)
		#define U_GPIO_PIN_LED3 		(GPIO_PORT_2_PIN_7)

		/* FreeRTOS CLI Command Console */
		#define U_SCI_UART_CLI_PINSET()	R_SCI_PinSet_SCI9()
		#define U_SCI_UART_CLI_SCI_CH	(SCI_CH9)
		#define U_DTC_UART_CLI_TX_ACT	((dtc_activation_source_t)VECT(SCI9,TXI9))
		#define U_DTC_UART_CLI_TX_DR	(SCI9.TDR)

	#endif /* RSKRX72N */

	#ifdef EnvisionRX72N

		/* R5F572NDHDFB 144pin LQFP */

		/* General Values */
		#define LED_ON					(0)
		#define LED_OFF 				(1)
		#define SW_PUSH 				(0)
		#define SW_RELEASE				(1)

		/* Switches (and its notation in the User's Manual) */
		#define SW1/*(SW2)*/				(PORT0.PIDR.BIT.B7)
		#define U_GPIO_PIN_SW1/*(SW2)*/ 	(GPIO_PORT_0_PIN_7)

		/* LED port settings (and its notation in the User's Manual) */
		#define LED0/*(LED2)*/				(PORT4.PODR.BIT.B0)
		#define U_GPIO_PIN_LED0/*(LED2)*/	(GPIO_PORT_4_PIN_0)

		/* FreeRTOS CLI Command Console */
		#define U_SCI_UART_CLI_PINSET()	R_SCI_PinSet_SCI2()
		#define U_SCI_UART_CLI_SCI_CH	(SCI_CH2)
		#define U_DTC_UART_CLI_TX_ACT	((dtc_activation_source_t)VECT(SCI2,TXI2))
		#define U_DTC_UART_CLI_TX_DR	(SCI2.TDR)

	#endif /* EnvisionRX72N */

	#ifndef LED0
		#error The hardware platform is not defined
	#endif

/* Board Support Data Structures. */

#include "r_sci_rx_if.h"
#include "r_dtc_rx_if.h"

extern sci_hdl_t xSerialSciHandle;
extern dtc_transfer_data_t xSerialTxDtcInfo;

/* Board Support Callback Functions. */

extern void vSerialSciCallback( void *pvArgs );

#endif /* LED_IO_H */

