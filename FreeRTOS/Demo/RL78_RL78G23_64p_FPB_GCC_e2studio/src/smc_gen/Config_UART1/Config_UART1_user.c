/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_UART1_user.c
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_UART1.
* Creation Date: 
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_UART1.h"
/* Start user code for include. Do not edit comment generated here */

#include "Config_DTC.h"
#include "UART1.h"

/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t * gp_uart1_tx_address;    /* uart1 transmit buffer address */
extern volatile uint16_t g_uart1_tx_count;        /* uart1 transmit data number */
extern volatile uint8_t * gp_uart1_rx_address;    /* uart1 receive buffer address */
extern volatile uint16_t g_uart1_rx_count;        /* uart1 receive data number */
extern volatile uint16_t g_uart1_rx_length;       /* uart1 receive data length */
/* Start user code for global. Do not edit comment generated here */

extern TaskHandle_t       g_uart1_tx_task;        /* uart1 send task */
extern volatile bool      g_uart1_tx_ready_flag;  /* uart1 send end flag */
extern TaskHandle_t       g_uart1_rx_task;        /* uart1 receive task */
extern volatile uint8_t   g_uart1_rx_abort_events;/* uart1 receive error flags (not including timeout error) */

static volatile uint32_t  g_uart1_rx_notification;/* uart1 receive notification */

extern void U_Config_UART1_Receive_Stop(void);    /* for internal use */
extern void U_Config_UART1_Send_Stop(void);       /* for internal use */

static void u_uart1_rx_callback_common(uint16_t stat); /* uart1 receive common callback */
static void u_wdt_request_interrupt(void);             /* wdt interrupt (as a software intetrrupt) request */

#define r_Config_UART1_interrupt_send R_CG_FREERTOS_INTERRUPT_EI(r_Config_UART1_interrupt_send)
#define r_Config_UART1_interrupt_receive R_CG_INTERRUPT_EI(r_Config_UART1_interrupt_receive)
#define u_wdt_interrupt R_CG_FREERTOS_INTERRUPT_EI(u_wdt_interrupt)

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_UART1_Create_UserInit
* Description  : This function adds user code after initializing UART1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_UART1_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UART1_callback_sendend
* Description  : This function is a callback function when UART1 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_UART1_callback_sendend(void)
{
    /* Start user code for r_Config_UART1_callback_sendend. Do not edit comment generated here */

    if (0U != (SSR12 & _0040_SAU_UNDER_EXECUTE))
    {
        /* DTC has finished data transfer operation. (i.e. The last data has been
         * written to UART's SDR register.) But the data stay in either UART's SDR
         * register or UART's transmission shift register. One more interrupt will
         * occur when UART will have finished data transmission operation. (i.e.
         * The last data including parity bit and stop bit(s) will have been sent
         * out from transmission shift register.)
         */
        return;
    }

    U_Config_UART1_Send_Stop();

    g_uart1_tx_ready_flag = true;

    vTaskNotifyGiveFromISR_R_Helper( &g_uart1_tx_task );

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UART1_callback_receiveend
* Description  : This function is a callback function when UART1 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_UART1_callback_receiveend(void)
{
    /* Start user code for r_Config_UART1_callback_receiveend. Do not edit comment generated here */

    /* U_Config_UART1_Receive_Stop(); Don't stop because reception ring buffer is used. */

    g_uart1_rx_length = 0U;

    u_uart1_rx_callback_common( MD_OK );

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UART1_callback_error
* Description  : This function is a callback function when UART1 reception error occurs.
* Arguments    : err_type -
*                    error type info
* Return Value : None
***********************************************************************************************************************/
static void r_Config_UART1_callback_error(uint8_t err_type)
{
    /* Start user code for r_Config_UART1_callback_error. Do not edit comment generated here */

    U_Config_UART1_Receive_Stop();

    g_uart1_rx_abort_events = err_type;

    u_uart1_rx_callback_common( (err_type << 8) | MD_RECV_ERROR );

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UART1_callback_softwareoverrun
* Description  : This function is a callback when UART1 receives an overflow data.
* Arguments    : rx_data -
*                    receive data
* Return Value : None
***********************************************************************************************************************/
static void r_Config_UART1_callback_softwareoverrun(uint16_t rx_data)
{
    /* Start user code for r_Config_UART1_callback_softwareoverrun. Do not edit comment generated here */

    if (0U == g_uart1_rx_abort_events)
    {
        u_uart1_callback_receivedata( rx_data );

        if (0U != g_uart1_rx_status)
        {
            r_Config_UART1_callback_error( SCI_EVT_RXBUF_OVFL );
        }
        else if (g_uart1_rx_length == g_uart1_rx_dtno)
        {
            r_Config_UART1_callback_receiveend();
        }
    }

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_UART1_interrupt_send
* Description  : This function is UART1 send interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_Config_UART1_interrupt_send(void)
{
    if (g_uart1_tx_count > 0U)
    {
        TXD1 = *gp_uart1_tx_address;
        gp_uart1_tx_address++;
        g_uart1_tx_count--;
    }
    else
    {
        r_Config_UART1_callback_sendend();
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_UART1_interrupt_receive
* Description  : This function is UART1 receive interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_Config_UART1_interrupt_receive(void)
{
    uint8_t rx_data;
    uint8_t err_type;
    
    err_type = (uint8_t)(SSR03 & 0x0007U);
    SIR03 = (uint16_t)err_type;

    if (0U != err_type)
    {
        r_Config_UART1_callback_error(err_type);
    }

    rx_data = RXD1;

    if (g_uart1_rx_length > g_uart1_rx_count)
    {
        *gp_uart1_rx_address = rx_data;
        gp_uart1_rx_address++;
        g_uart1_rx_count++;

        if (g_uart1_rx_length == g_uart1_rx_count)
        {
            r_Config_UART1_callback_receiveend();
        }
    }
    else
    {
        r_Config_UART1_callback_softwareoverrun(rx_data);
    }
}

/* Start user code for adding. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: u_uart1_rx_callback_common
* Description  : This function is a callback function when UART1 finishes transmission or UART1 reception error occurs.
* Arguments    : stat -
*                    status value (lower 8bits) with error type value (upper 8bits)
* Return Value : None
***********************************************************************************************************************/
static void u_uart1_rx_callback_common(uint16_t stat)
{
    /* If there are no tasks waiting for a notification or a notification was already
     * sent (or is going to be sent), i.e. 
     * when g_uart1_rx_task == NULL || g_uart1_rx_notification != 0U,
     * a notification isn't sent or is skipped.
     */
    if (NULL != g_uart1_rx_task && 0U == g_uart1_rx_notification)
    {
        /* Generate INTWDTI interrupt manually as a software intetrrupt. The interrupt
         * priority of INTSR3 is configured higher than the SYSCALL interrupt priority.
         * On the other hand, the interrupt priority of INTWDTI is configured within
         * the SYSCALL interrupt priority.
         */
        g_uart1_rx_notification = 0x10000 | stat;
        u_wdt_request_interrupt();
    }
}

/***********************************************************************************************************************
* Function Name: u_wdt_request_interrupt
* Description  : This function requests INTWDT interrupt (as a software intetrrupt).
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void u_wdt_request_interrupt(void)
{
    WDTIIF = 1U;       /* set INTWDTI interrupt flag (as a software interrupt) */
}

/***********************************************************************************************************************
* Function Name: u_wdt_interrupt
* Description  : This function is INTWDT interrupt (as a software intetrrupt) service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void u_wdt_interrupt(void)
{
    /* If the task had been already notified or isn't waiting for any notification,
     * i.e. when g_uart1_rx_task == NULL, actually the task will not be notified.
     * And g_uart1_rx_task is automatically set to NULL after posting a notification.
     * But g_uart1_rx_notification isn't automatically set to 0, so is manually set to 0.
     */
    xTaskNotifyFromISR_R_Helper( &g_uart1_rx_task, g_uart1_rx_notification );
    g_uart1_rx_notification = 0U;
}

/* End user code. Do not edit comment generated here */
