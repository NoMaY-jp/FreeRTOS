#ifndef DEMO_MAIN_H
#define DEMO_MAIN_H

/* Set mainCREATE_NON_STANDARD_RTOS_DEMO to one to run the following non standard
RTOS Demo, or 0 to run the standard RTOS Demo which is the simple blinky demo or
the more comprehensive test and demo application.

The non standard RTOS Demo:

(1)   Toggle LED0 every 500ms.
(2)   Toggle LED1 when SW_USER is pushed.
(3-1) Echo every three charcters through the UART3 using the following sockets.
        RxD3 : J7-D0
        TxD3 : J7-D1
        GND  : J8-G
(3-2) Blink LED1 faster if parity error, framing error, overrun error or timeout
occurs. The error state is cleared when when SW_USER is pushed. */
#define mainCREATE_NON_STANDARD_RTOS_DEMO	0

/* Set mainCREATE_SIMPLE_BLINKY_DEMO_ONLY to one to run the simple blinky demo,
or 0 to run the more comprehensive test and demo application. */
#define mainCREATE_SIMPLE_BLINKY_DEMO_ONLY	0

/* The following demo_main() is placed in the src/frtos_startup/freertos_start.c
and it calls main_blinky() or main_full() according to the macro setting. */
extern void demo_main( void );

/* The following functions are placed in the src/frtos_startup/freertos_start.c
and these are called from the src/FreeRTOS_Demo/Blinky_Demo/main_blinky.c or the
src/FreeRTOS_Demo/Full_Demo/main_full.c according to the macro setting. */
extern void vToggleLED( void );
extern void vSendString( const char * const pcString );

#endif
