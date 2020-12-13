/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
* Copyright (C) 2018 Renesas Electronics Corporation. All rights reserved.    
*******************************************************************************/
/*******************************************************************************
* File Name    : freertos_start.c
* Version      : 1.0
* Description  : Contains FreeRTOS user-defined functions.
******************************************************************************/
/*****************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 30.06.2016 1.00     First Release
******************************************************************************/

/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "freertos_start.h"
#include "demo_main.h"
#include "demo_specific_io.h"

/******************************************************************************
Macro definitions
******************************************************************************/

/******************************************************************************
Typedef definitions
******************************************************************************/

/******************************************************************************
Private global variables and functions
******************************************************************************/

/************* semaphore initialization *****************/

/******************************************************************************
Exported global variables (to be accessed by other files)
******************************************************************************/

/******************************************************************************
Exported global functions (to be accessed by other files)
******************************************************************************/

/* FreeRTOS's system timer. */
void vApplicationSetupTimerInterrupt(void);

/* Hook functions used by FreeRTOS. */
void vAssertCalled(void);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationMallocFailedHook(void);
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName);

/* FreeRTOS's processing before start the kernel. */
void Processing_Before_Start_Kernel(void);

/* Main task. */
extern void main_task(void *pvParameters);

/******************************************************************************
* Function Name: vAssertCalled
* Description  : This function is used to validate the input parameters.
* Arguments    : None.
* Return Value : None.
******************************************************************************/
void vAssertCalled(void)
{
    volatile unsigned long ul = 0;

    taskENTER_CRITICAL();
    {
        vPrintString( "\r\n" );
        vPrintString( "Assertion failed!\n" );

        /* Use the debugger to set ul to a non-zero value in order to step out
        of this function to determine why it was called. */
        while( 0 == ul )
        {
            portNOP();
        }
    }
    taskEXIT_CRITICAL();

} /* End of function vAssertCalled() */

/******************************************************************************
* Function Name: vApplicationIdleHook
* Description  : This function will be called on each cycle of the idle task.
*                NOTE: vApplicationIdleHook() MUST NOT CALL A FUNCTION
*                      THAT MIGHT BLOCK UNDER ANY CIRCUMSTANCES.
* Arguments    : None.
* Return Value : None.
******************************************************************************/
void vApplicationIdleHook(void)
{
    /* Implement user-code for user own purpose. */

} /* End of function vApplicationIdleHook() */

/******************************************************************************
* Function Name: vApplicationTickHook
* Description  : This function will be called every tick interrupt.
*                NOTE: vApplicationTickHook() EXECUTES FROM WITHIN AN ISR,
*                      SO MUST BE VERY SHORT AND NOT USE MUCH STACK.
*                      IN ADDITION, NOT CALL ANY APIs WITHOUT "FromISR" OR
*                      "FROM_ISR" AT THE END.
* Arguments    : None.
* Return Value : None.
******************************************************************************/
void vApplicationTickHook(void)
{
    /* Implement user-code for user own purpose. */

} /* End of function vApplicationTickHook() */

/******************************************************************************
* Function Name: vApplicationMallocFailedHook
* Description  : This function is to capture the failure while
*                memory allocation.
* Arguments    : None.
* Return Value : None.
******************************************************************************/
void vApplicationMallocFailedHook(void)
{
    /* Called if a call to pvPortMalloc() fails because there is insufficient
    free memory available in the FreeRTOS heap.  pvPortMalloc() is called
    internally by FreeRTOS API functions that create tasks, queues, software
    timers, and semaphores.  The size of the FreeRTOS heap is set by the
    configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */

    taskENTER_CRITICAL();
    vPrintString( "\r\n" );
    vPrintString( "Insufficient heap memory!\n" );

    /* Force an assert. */
    configASSERT( ( volatile void * ) NULL );

#if 0
    taskDISABLE_INTERRUPTS();
    for( ; ; )
    {
        /* Loop here */
    };
#endif

} /* End of function vApplicationMallocFailedHook() */

/******************************************************************************
* Function Name: vApplicationStackOverflowHook
* Description  : Hook function is to capture the failure when the stack size
*                is insufficient for processing.
* Arguments    : pxTask -
*                    Task handler
*                pcTaskName -
*                    Pointer of where to store the task's name
* Return Value : None.
******************************************************************************/
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    ( void ) pcTaskName;
    ( void ) pxTask;

    /* Run time stack overflow checking is performed if
    configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
    function is called if a stack overflow is detected. */

    taskENTER_CRITICAL();
    vPrintString( "\r\n" );
    vPrintString( "Stack Overflow!\n" );

    /* Force an assert. */
    configASSERT( ( volatile void * ) NULL );

#if 0
    taskDISABLE_INTERRUPTS();
    for( ; ; )
    {
        /* Loop here */
    };
#endif

} /* End of function vApplicationStackOverflowHook() */

/******************************************************************************
* Function Name: vPrintString
* Description  : This function is used to write a string to a debug console.
* Arguments    : None.
* Return Value : None.
******************************************************************************/
void vPrintString(const char *pcMessage)
{
    /* Write the string to a debug console, using a critical section
    as a crude method of mutual exclusion. */

    extern void sim_debugger_console( const char *message );

    taskENTER_CRITICAL();
    {
#if 1
		( void ) pcMessage;
#else
        sim_debugger_console( pcMessage );
#endif
    }
    taskEXIT_CRITICAL();

} /* End of function vPrintString() */

/******************************************************************************
* Function Name : Processing_Before_Start_Kernel
* Description   : Create a main task, FreeRTOS's objects (e.g. mailbox, task,
*                 semaphore, mutex...) if required.
* Arguments     : None.
* Return value  : None.
******************************************************************************/
void Processing_Before_Start_Kernel(void)
{
#if 0

    BaseType_t ret;

    /************** semaphore creation ***********************/



    /************** mutex creation ***************************/


    /************** queues creation **************************/


    /************** event groups creation ********************/


    /************** mailbox creation *************************/


    /************** memory pool creation *********************/


    Kernel_Object_init();

    /************** task creation ****************************/
    /* Main task. */
    ret = xTaskCreate(main_task, "MAIN_TASK", 512, NULL, 3, NULL);
    if (pdPASS != ret)
    {
        while(1)
        {
            /* Failed! Task can not be created. */
        }
    }

#else /* Run FreeRTOS Demo */

    demo_main();

#endif

} /* End of function Processing_Before_Start_Kernel() */

/*-----------------------------------------------------------*/

/*
 * Configure the hardware as necessary to run this demo.
 */
static void prvSetupHardware( void );

/*
 * main_blinky() is used when mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 1.
 * main_full() is used when mainCREATE_SIMPLE_BLINKY_DEMO_ONLY is set to 0.
 */
#if( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 1 )
    extern void main_blinky( void );
#else
    extern void main_full( void );
#endif /* #if mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 1 */

/*-----------------------------------------------------------*/

void demo_main( void )
{
    /* Configure the hardware ready to run the demo. */
    prvSetupHardware();

    /* The mainCREATE_SIMPLE_BLINKY_DEMO_ONLY setting is described at the top
    of this file. */
    #if( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 1 )
    {
        main_blinky();
    }
    #else
    {
        main_full();
    }
    #endif

    /* Should never get reached. */
    return;
}
/*-----------------------------------------------------------*/

static void prvSetupHardware( void )
{
    /* Turn on the LED at start. (The system initialization had been done in the
    src/smc_gen/general/r_hardware_setup.c.) */
    vToggleLED();

    /* Write "\r\n" to the UART and/or the Debug Console. */
    vSendString( "\r\n" );
}
/*-----------------------------------------------------------*/

void vToggleLED( void )
{
    /* Toggle the LED */
    LED_BIT = !LED_BIT;
}
/*-----------------------------------------------------------*/

void vSendString( const char * const pcString )
{
    /* Write the string to the Debug Console. */
    vPrintString( pcString );

    /* Write the string to the UART. It is done in case of the simple blinky demo
    only but it isn't done in case of the full demo because the UART is used for
    other purpos "FreeRTOS+CLI command console" by the full demo. */
    #if( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 1 )
    {
#if 0
        R_SCI_Send( xSerialSciHandle, ( uint8_t * )pcString, strlen(pcString) );
#endif
    }
    #endif
}
/*-----------------------------------------------------------*/
