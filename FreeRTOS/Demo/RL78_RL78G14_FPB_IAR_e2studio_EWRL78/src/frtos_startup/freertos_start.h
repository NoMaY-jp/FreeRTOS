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
* File Name    : freertos_start.h
* Version      : 1.0
* Description  : FreeRTOS's user-defined functions header file.
******************************************************************************/
/*****************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 30.06.2016 1.00     First Release
******************************************************************************/

#ifndef FREERTOS_START_H_
#define FREERTOS_START_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#if defined(__CCRL__) && !defined(_STDINT_H)
#define _STDINT_H
#endif
#if defined(__ICCRL78__) && !defined(_STDINT)
#define _STDINT
#endif
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "croutine.h"
#include "timers.h"
#include "event_groups.h"

/******************************************************************************
Macro definitions
******************************************************************************/

#define IdleTask_STACK_BUFF_DEPTH   pdBYTES_TO_STACK_DEPTH( STACK_BUFF_BYTES(  10, 86, 32 ) )
#define main_task_STACK_BUFF_DEPTH  pdBYTES_TO_STACK_DEPTH( STACK_BUFF_BYTES(   6, 86, 32 ) )
#define task_LED0_STACK_BUFF_DEPTH  pdBYTES_TO_STACK_DEPTH( STACK_BUFF_BYTES(  66, 86, 32 ) )
#define task_LED1_STACK_BUFF_DEPTH  pdBYTES_TO_STACK_DEPTH( STACK_BUFF_BYTES(  76, 86, 32 ) )
#define task_CONIO_STACK_BUFF_DEPTH pdBYTES_TO_STACK_DEPTH( STACK_BUFF_BYTES( 150, 86, 32 ) )

/******************************************************************************
Typedef definitions
******************************************************************************/

/******************************************************************************
Exported global variables
******************************************************************************/
/************* semaphore handler *****************/



/************* mutex handler *********************/


/************** queues handler *******************/


/************** event groups handler *************/


/************** mailbox handler ******************/


/************** memory pool handler **************/


/************** task handler *********************/


/******************************************************************************
Exported global functions (to be accessed by other files)
******************************************************************************/
extern void Processing_Before_Start_Kernel(void);
extern void Kernel_Object_init(void);
extern void vPrintString(const char *pcMessage);
extern void vTaskNotifyGiveFromISR_R_Helper(TaskHandle_t *pxTask);
extern void xTaskNotifyFromISR_R_Helper(TaskHandle_t *pxTask, uint32_t ulValue);
extern uint32_t ulTaskNotifyTake_R_Helper(TickType_t xTicksToWait);
extern TaskHandle_t xTaskGetCurrentTaskHandle_R_Helper(void);

#define xTaskCreateStatic_R_Helper(pxTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask) \
do{ \
    static StaticTask_t pxTaskCode##_xTCBBuffer; \
    static StackType_t  pxTaskCode##_xStackBuffer[usStackDepth]; \
    TaskHandle_t xCreatedTask; \
    xCreatedTask = xTaskCreateStatic( pxTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxTaskCode##_xStackBuffer, &pxTaskCode##_xTCBBuffer ); \
    if (NULL != (TaskHandle_t *)pxCreatedTask) \
    { \
        *(TaskHandle_t *)pxCreatedTask = xCreatedTask; \
    } \
}while (0)

#define STACK_BUFF_BYTES(ustack, istack, mergin) ((ustack)+(istack)+(mergin))

#ifdef __cplusplus
}
#endif

#endif /* FREERTOS_START_H_ */
