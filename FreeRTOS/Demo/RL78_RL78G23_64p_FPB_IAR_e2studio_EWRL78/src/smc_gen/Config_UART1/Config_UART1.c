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
* File Name    : Config_UART1.c
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_UART1.
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
#include "r_cg_userdefine.h"
#include "Config_UART1.h"
/* Start user code for include. Do not edit comment generated here */

#include "Config_DTC.h"
#include "UART1.h"

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t * gp_uart1_tx_address;    /* uart1 transmit buffer address */
volatile uint16_t g_uart1_tx_count;        /* uart1 transmit data number */
volatile uint8_t * gp_uart1_rx_address;    /* uart1 receive buffer address */
volatile uint16_t g_uart1_rx_count;        /* uart1 receive data number */
volatile uint16_t g_uart1_rx_length;       /* uart1 receive data length */
/* Start user code for global. Do not edit comment generated here */

TaskHandle_t       g_uart1_tx_task;        /* uart1 send task */
volatile bool      g_uart1_tx_ready_flag;  /* uart1 send end flag */
TaskHandle_t       g_uart1_rx_task;        /* uart1 receive task */
volatile uint8_t   g_uart1_rx_abort_events;/* uart1 receive error flags (not including timeout error) */

void U_Config_UART1_Receive_Stop(void);    /* for internal use */
void U_Config_UART1_Send_Stop(void);       /* for internal use */

static void U_Config_UART1_Receive(volatile uint8_t * rx_buf, uint16_t rx_num);
static void U_Config_UART1_Send_WaitForReady(void);
static void U_Config_UART1_Send(uint8_t * tx_buf, uint16_t tx_num);

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_UART1_Create
* Description  : This function initializes the UART1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_UART1_Create(void)
{
    SPS0 &= _00F0_SAU_CK00_CLEAR;
    SPS0 |= _0000_SAU_CK00_FCLK_0;
    ST0 |= (_0008_SAU_CH3_STOP_TRG_ON | _0004_SAU_CH2_STOP_TRG_ON);
    STMK1 = 1U;    /* disable INTST1 interrupt */
    STIF1 = 0U;    /* clear INTST1 interrupt flag */
    SRMK1 = 1U;    /* disable INTSR1 interrupt */
    SRIF1 = 0U;    /* clear INTSR1 interrupt flag */
    SREMK1 = 1U;    /* disable INTSRE1 interrupt */
    SREIF1 = 0U;    /* clear INTSRE1 interrupt flag */
    /* Set INTST1 low priority */
    STPR11 = 1U;
    STPR01 = 1U;
    /* Set INTSR1 level2 priority */
    SRPR11 = 1U;
    SRPR01 = 0U;
    SMR02 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_TRIGGER_SOFTWARE | 
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR02 = _8000_SAU_TRANSMISSION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | 
            _0010_SAU_STOP_1 | _0007_SAU_LENGTH_8;
    SDR02 = _0E00_SAU0_CH2_TRANSMIT_DIVISOR;
    NFEN0 |= _04_SAU_RXD1_FILTER_ON;
    SIR03 = _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR03 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0100_SAU_TRIGGER_RXD | _0000_SAU_EDGE_FALL | 
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR03 = _4000_SAU_RECEPTION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 | 
            _0007_SAU_LENGTH_8;
    SDR03 = _0E00_SAU0_CH3_RECEIVE_DIVISOR;
    SO0 |= _0004_SAU_CH2_DATA_OUTPUT_1;
    SOL0 |= _0000_SAU_CHANNEL2_NORMAL;    /* output level normal */
    SOE0 |= _0004_SAU_CH2_OUTPUT_ENABLE;    /* enable UART1 output */
    /* Set TxD1 pin */
    PMCA0 &= 0xFBU;
    PFOE1 |= 0x02U;
    P0 |= 0x04U;
    PM0 &= 0xFBU;
    /* Set RxD1 pin */
    PMCA0 &= 0xF7U;
    PM0 |= 0x08U;

    R_Config_UART1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_UART1_Start
* Description  : This function starts UART1 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_UART1_Start(void)
{
    SO0 |= _0004_SAU_CH2_DATA_OUTPUT_1;    /* output level normal */
    SOE0 |= _0004_SAU_CH2_OUTPUT_ENABLE;    /* enable UART1 output */
    SS0 |= (_0008_SAU_CH3_START_TRG_ON | _0004_SAU_CH2_START_TRG_ON);    /* enable UART1 receive and transmit */
    STIF1 = 0U;    /* clear INTST1 interrupt flag */
    SRIF1 = 0U;    /* clear INTSR1 interrupt flag */
    STMK1 = 0U;    /* enable INTST1 interrupt */
    SRMK1 = 0U;    /* enable INTSR1 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_Config_UART1_Stop
* Description  : This function stops UART1 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_UART1_Stop(void)
{
    STMK1 = 1U;    /* disable INTST1 interrupt */
    SRMK1 = 1U;    /* disable INTSR1 interrupt */
    ST0 |= (_0008_SAU_CH3_STOP_TRG_ON | _0004_SAU_CH2_STOP_TRG_ON);
    SOE0 &= (uint16_t)~_0004_SAU_CH2_OUTPUT_ENABLE;    /* disable UART1 output */
    STIF1 = 0U;    /* clear INTST1 interrupt flag */
    SRIF1 = 0U;    /* clear INTSR1 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_UART1_Send
* Description  : This function sends UART1 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_UART1_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_uart1_tx_address = tx_buf;
        g_uart1_tx_count = tx_num;
        STMK1 = 1U;    /* disable INTST1 interrupt */
        TXD1 = *gp_uart1_tx_address;
        gp_uart1_tx_address++;
        g_uart1_tx_count--;
        STMK1 = 0U;    /* enable INTST1 interrupt */
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_Config_UART1_Receive
* Description  : This function receives UART1 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_UART1_Receive(uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_uart1_rx_count = 0U;
        g_uart1_rx_length = rx_num;
        gp_uart1_rx_address = rx_buf;
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_Config_UART1_Loopback_Enable
* Description  : This function enables the UART1 loopback function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_UART1_Loopback_Enable(void)
{
    ULBS1 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_UART1_Loopback_Disable
* Description  : This function disables the UART1 loopback function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_UART1_Loopback_Disable(void)
{
    ULBS1 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */

/******************************************************************************
* Function Name: U_Config_UART1_Start
* Description  : This function starts the UART1 module using reception Ring Buffer and transmission DTC.
* Arguments    : None
* Return Value : None
******************************************************************************/
void U_Config_UART1_Start(void)
{
    R_Config_UART1_Start();
    U_Config_UART1_Receive_Stop();
    U_Config_UART1_Receive_ClearError();
    g_uart1_tx_ready_flag = true;
}

/******************************************************************************
* Function Name: U_Config_UART1_Receive_Wait
* Description  : This function receives UART1 data using Ring Buffer.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
*                p_err_events -
*                    error type variable pointer
*                rx_wait -
*                    FreeRTOS's ticks to wait
* Return Value : status -
*                    MD_OK or MD_ARGERROR or MD_RECV_ERROR or MD_RECV_TIMEOUT
******************************************************************************/
MD_STATUS U_Config_UART1_Receive_Wait(uint8_t * rx_buf, uint16_t rx_num, uint8_t * p_err_events, TickType_t rx_wait)
{
    MD_STATUS status = MD_OK;
    uint8_t err_events = 0U;
    uint32_t value;

    if (rx_num < 1U || UART1_RX_BUFF_SIZE < rx_num)
    {
        status = MD_ARGERROR;
    }
    else
    {
        /* Forbid task switching before disabling INTSR3 interrupt, otherwise other higher
         * or same priority tasks may run keeping INTSR3 interrupt disabled for a long time.
         * Since the interrupt priority of INTSR3 is configured higher than the SYSCALL
         * interrupt priority, a critical section cannot disable INTSR3 interrupt. In this
         * case, when exclusive operation between task side and interrupt service routine
         * side is necessary, using interrupt mask register is necessary for the operation.
         */
        taskENTER_CRITICAL();
        SRMK3 = 1U; /* disable INTSR3 interrupt */

        if (rx_num <= g_uart1_rx_dtno)
        {
            /* Requested data can be obtained immediately. */

            /* Permit task switching after enabling INTSR3 interrupt when reception
             * isn't aborted.
             */
            if (0U == g_uart1_rx_abort_events)
            {
                SRMK3 = 0U; /* enable INTSR3 interrupt */
            }
            taskEXIT_CRITICAL();

            /* Both status and err_events don't need to be changed from initial value. */
        }
        else if (0U != g_uart1_rx_abort_events)
        {
            /* Requested data cannot be obtained never. */

            /* Permit task switching. Don't enable INTSR3 interrupt because reception
             * is aborted.
             */
            taskEXIT_CRITICAL();

            status = MD_RECV_ERROR;
            err_events = g_uart1_rx_abort_events;
        }
        else
        {
            /* Requested data cannot be obtained now but it will be obtained later. */

            /* Set up the interrupt/callback ready to post a notification */
            g_uart1_rx_task = xTaskGetCurrentTaskHandle_R_Helper();
            U_Config_UART1_Receive( rx_buf, rx_num );

            /* Permit task switching after enabling INTSR3 interrupt because reception
             * isn't aborted.
             */
            SRMK3 = 0U; /* enable INTSR3 interrupt */
            taskEXIT_CRITICAL();

            /* Wait for a notification from the interrupt/callback */
            value = ulTaskNotifyTake_R_Helper( rx_wait );

            if (0U != value)
            {
                /* Normal receive end or receive error */

                status = value & 0xFFU;
                err_events = (value >> 8) & 0xFFU;
            }
            else
            {
                /* Timeout */

                /* Abort the interrupt/callback posting a notification */
                U_Config_UART1_Receive_Stop();
                ulTaskNotifyTake_R_Abort_Helper( &g_uart1_rx_task );

                status = MD_RECV_TIMEOUT;
                err_events = SCI_EVT_RXWAIT_TMOT;
            }
        }

        if (MD_OK == status)
        {
            u_uart1_get_blk( (uint8_t *)rx_buf, rx_num );
        }
        *p_err_events = err_events;
    }

    return status;
}

static void U_Config_UART1_Receive(volatile uint8_t * rx_buf, uint16_t rx_num)
{
    gp_uart1_rx_address = rx_buf;
    g_uart1_rx_count = 0xFFFFU;
    g_uart1_rx_length = rx_num;
}

/******************************************************************************
* Function Name: U_Config_UART1_Receive_Stop
* Description  : This function stops the UART1 data reception using Ring Buffer.
* Arguments    : None
* Return Value : None
* Note         : This is called from others internally.
******************************************************************************/
void U_Config_UART1_Receive_Stop(void)
{
    SRMK3 = 1U;        /* disable INTSR3 interrupt */
}

/******************************************************************************
* Function Name: U_Config_UART1_Receive_ClearError
* Description  : This function clears errors and re-initializes Ring Buffer.
* Arguments    : None
* Return Value : None
******************************************************************************/
void U_Config_UART1_Receive_ClearError(void)
{
    g_uart1_rx_length = 0U;
    (void) RXD3;       /* dummy read */
    SIR13 = 0x0007U;   /* clear UART1 error flags */
    g_uart1_rx_abort_events = 0U;
    WDTIIF = 0U;       /* clear INTWDTI interrupt flag (as a software interrupt) */
    WDTIMK = 0U;       /* enable INTWDTI interrupt (as a software interrupt) */
    SRIF3 = 0U;        /* clear INTSR3 interrupt flag */
    u_uart1_init_bf(); /* also enable INTSR3 interrupt */
}

/******************************************************************************
* Function Name: U_Config_UART1_Send_Wait
* Description  : This function sends UART1 data using DTC.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
******************************************************************************/
MD_STATUS U_Config_UART1_Send_Wait(uint8_t * tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U || 256U < tx_num)
    {
        status = MD_ARGERROR;
    }
    else
    {
        U_Config_UART1_Send_WaitForReady();

        /* Wait for a notification from the interrupt/callback */
        ulTaskNotifyTake_R_Helper_Ex( &g_uart1_tx_task, U_Config_UART1_Send( tx_buf, tx_num ), portMAX_DELAY );
    }

    return status;
}

MD_STATUS U_Config_UART1_Send_Start(uint8_t * tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U || 256U < tx_num)
    {
        status = MD_ARGERROR;
    }
    else
    {
        U_Config_UART1_Send_WaitForReady();

        /* Not wait for a notification from the interrupt/callback */
        U_Config_UART1_Send( tx_buf, tx_num );
    }

    return status;
}

static void U_Config_UART1_Send_WaitForReady(void)
{
    /* Since the interrupt priority of INTST3 is configured within the SYSCALL
     * interrupt priority, a critical section can disable INTST3 interrupt.
     */
    taskENTER_CRITICAL();

    if (false == g_uart1_tx_ready_flag)
    {
        /* Transmission hasn't finished, so wait for the finish. */

       /* Set up the interrupt/callback ready to post a notification */
        g_uart1_tx_task = xTaskGetCurrentTaskHandle_R_Helper();

        taskEXIT_CRITICAL();

        /* Wait for a notification from the interrupt/callback */
        ulTaskNotifyTake_R_Helper( portMAX_DELAY );
    }
    else
    {
        /* Transmission has finished, so do nothing. */

        taskEXIT_CRITICAL();
    }
}

static void U_Config_UART1_Send(uint8_t * tx_buf, uint16_t tx_num)
{
    g_uart1_tx_ready_flag = false;
    STIF3 = 0U;        /* clear INTST3 interrupt flag */
    if (1 < tx_num)
    {
        U_DTCD0_UserInit( tx_buf + 1, tx_num - 1 );
        R_DTCD0_Start();
    }
    R_Config_UART1_Send( tx_buf, 1 );
}

/******************************************************************************
* Function Name: U_Config_UART1_Send_Stop
* Description  : This function stops the UART1 data transmission using DTC.
* Arguments    : None
* Return Value : None
* Note         : This is called from others internally.
******************************************************************************/
void U_Config_UART1_Send_Stop(void)
{
    STMK3 = 1U;        /* disable INTST3 interrupt */
    R_DTCD0_Stop();    /* forcibly stop DTCD0 (if it is operating) */
}

/* End user code. Do not edit comment generated here */

