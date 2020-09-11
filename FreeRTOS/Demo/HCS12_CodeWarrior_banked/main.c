
/*
 * FreeRTOS Kernel V10.4.0
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


/*
 *
 * vMain() is effectively the demo application entry point.  It is called by
 * the main() function generated by the Processor Expert application.  
 *
 * vMain() creates all the demo application tasks, then starts the scheduler.
 * The WEB	documentation provides more details of the demo application tasks.
 *
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 * This file also includes the functionality implemented within the 
 * standard demo application file integer.c.  This is done to demonstrate the
 * use of an idle hook.  See the documentation within integer.c for the 
 * rationale of the integer task functionality.
 * */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Demo application includes. */
#include "flash.h"
#include "PollQ.h"
#include "dynamic.h"
#include "partest.h"
#include "comtest2.h"
#include "BlockQ.h"
#include "integer.h"
#include "death.h"


/*-----------------------------------------------------------
	Definitions.
-----------------------------------------------------------*/

/* Priorities assigned to demo application tasks. */
#define mainFLASH_PRIORITY			( tskIDLE_PRIORITY + 2 )
#define mainCHECK_TASK_PRIORITY		( tskIDLE_PRIORITY + 3 )
#define mainQUEUE_POLL_PRIORITY		( tskIDLE_PRIORITY + 1 )
#define mainCOM_TEST_PRIORITY		( tskIDLE_PRIORITY + 2 )
#define mainBLOCK_Q_PRIORITY		( tskIDLE_PRIORITY + 2 )
#define mainDEATH_PRIORITY			( tskIDLE_PRIORITY + 1 )

/* LED that is toggled by the check task.  The check task periodically checks
that all the other tasks are operating without error.  If no errors are found
the LED is toggled with mainCHECK_PERIOD frequency.  If an error is found 
then the toggle rate increases to mainERROR_CHECK_PERIOD. */
#define mainCHECK_TASK_LED			( 7 )
#define mainCHECK_PERIOD			( ( TickType_t ) 3000 / portTICK_PERIOD_MS  )
#define mainERROR_CHECK_PERIOD		( ( TickType_t ) 500 / portTICK_PERIOD_MS )

/* The constants used in the idle task calculation. */
#define intgCONST1				( ( long ) 123 )
#define intgCONST2				( ( long ) 234567 )
#define intgCONST3				( ( long ) -3 )
#define intgCONST4				( ( long ) 7 )
#define intgEXPECTED_ANSWER		( ( ( intgCONST1 + intgCONST2 ) * intgCONST3 ) / intgCONST4 )


/* Baud rate used by the serial port tasks (ComTest tasks).
IMPORTANT:  The function COM0_SetBaudRateValue() which is generated by the
Processor Expert is used to set the baud rate.  As configured in the FreeRTOS
download this value must be one of the following:

0 to configure for 38400 baud.
1 to configure for 19200 baud.
2 to configure for 9600 baud.
3 to configure for 4800 baud. */
#define mainCOM_TEST_BAUD_RATE			( ( unsigned long ) 2 )

/* LED used by the serial port tasks.  This is toggled on each character Tx,
and mainCOM_TEST_LED + 1 is toggles on each character Rx. */
#define mainCOM_TEST_LED				( 3 )

/*-----------------------------------------------------------
	Local functions prototypes.
-----------------------------------------------------------*/

/*
 * The 'Check' task function.  See the explanation at the top of the file.
 */
static void vErrorChecks( void* pvParameters );

/*
 * The idle task hook - in which the integer task is implemented.  See the
 * explanation at the top of the file.
 */
void vApplicationIdleHook( void );

/*
 * Checks the unique counts of other tasks to ensure they are still operational.
 */
static long prvCheckOtherTasksAreStillRunning( void );



/*-----------------------------------------------------------
	Local variables.
-----------------------------------------------------------*/

/* A few tasks are defined within this file.  This flag is used to indicate
their status.  If an error is detected in one of the locally defined tasks then
this flag is set to pdTRUE. */
portBASE_TYPE xLocalError = pdFALSE;


/*-----------------------------------------------------------*/

/* 
 * This is called from the main() function generated by the Processor Expert.
 */
void vMain( void )
{
	/* Start some of the standard demo tasks. */
	vStartLEDFlashTasks( mainFLASH_PRIORITY );
	vStartPolledQueueTasks( mainQUEUE_POLL_PRIORITY );
	vStartDynamicPriorityTasks();
	vAltStartComTestTasks( mainCOM_TEST_PRIORITY, mainCOM_TEST_BAUD_RATE, mainCOM_TEST_LED );
	vStartBlockingQueueTasks( mainBLOCK_Q_PRIORITY );
	vStartIntegerMathTasks( tskIDLE_PRIORITY );
		
	/* Start the locally defined tasks.  There is also a task implemented as
	the idle hook. */
	xTaskCreate( vErrorChecks, "Check", configMINIMAL_STACK_SIZE, NULL, mainCHECK_TASK_PRIORITY, NULL );
	
	/* Must be the last demo created. */
	vCreateSuicidalTasks( mainDEATH_PRIORITY );

	/* All the tasks have been created - start the scheduler. */
	vTaskStartScheduler();
	
	/* Should not reach here! */
	for( ;; );
}
/*-----------------------------------------------------------*/

static void vErrorChecks( void *pvParameters )
{
TickType_t xDelayPeriod = mainCHECK_PERIOD;
TickType_t xLastWakeTime;

	/* Initialise xLastWakeTime to ensure the first call to vTaskDelayUntil()
	functions correctly. */
	xLastWakeTime = xTaskGetTickCount();

	for( ;; )
	{
		/* Delay until it is time to execute again.  The delay period is 
		shorter following an error. */
		vTaskDelayUntil( &xLastWakeTime, xDelayPeriod );

		/* Check all the demo application tasks are executing without 
		error. If an error is found the delay period is shortened - this
		has the effect of increasing the flash rate of the 'check' task
		LED. */
		if( prvCheckOtherTasksAreStillRunning() == pdFAIL )
		{
			/* An error has been detected in one of the tasks - flash faster. */
			xDelayPeriod = mainERROR_CHECK_PERIOD;
		}

		/* Toggle the LED each cycle round. */
		vParTestToggleLED( mainCHECK_TASK_LED );
	}
}
/*-----------------------------------------------------------*/

static long prvCheckOtherTasksAreStillRunning( void )
{
portBASE_TYPE xAllTasksPassed = pdPASS;

	if( xArePollingQueuesStillRunning() != pdTRUE )
	{
		xAllTasksPassed = pdFAIL;
	}

	if( xAreDynamicPriorityTasksStillRunning() != pdTRUE )
	{
		xAllTasksPassed = pdFAIL;
	}

	if( xAreComTestTasksStillRunning() != pdTRUE )
	{
		xAllTasksPassed = pdFALSE;
	}

	if( xAreIntegerMathsTaskStillRunning() != pdTRUE )
	{
		xAllTasksPassed = pdFALSE;
	}
	
	if( xAreBlockingQueuesStillRunning() != pdTRUE )
	{
		xAllTasksPassed = pdFALSE;
	}	

    if( xIsCreateTaskStillRunning() != pdTRUE )
    {
    	xAllTasksPassed = pdFALSE;
    }

	/* Also check the status flag for the tasks defined within this function. */
	if( xLocalError != pdFALSE )
	{
		xAllTasksPassed = pdFAIL;
	}
	
	return xAllTasksPassed;
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
/* This variable is effectively set to a constant so it is made volatile to
ensure the compiler does not just get rid of it. */
volatile long lValue;

	/* Keep performing a calculation and checking the result against a constant. */

	/* Perform the calculation.  This will store partial value in
	registers, resulting in a good test of the context switch mechanism. */
	lValue = intgCONST1;
	lValue += intgCONST2;
	lValue *= intgCONST3;
	lValue /= intgCONST4;

	/* Did we perform the calculation correctly with no corruption? */
	if( lValue != intgEXPECTED_ANSWER )
	{
		/* Error! */
		portENTER_CRITICAL();
			xLocalError = pdTRUE;
		portEXIT_CRITICAL();
	}

	/* Yield in case cooperative scheduling is being used. */
	#if configUSE_PREEMPTION == 0
	{
		taskYIELD();
	}
	#endif		
}
/*-----------------------------------------------------------*/



