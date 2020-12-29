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
* Copyright (C) 2011, 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_serial.c
* Version      : CodeGenerator for RL78/G14 V2.05.04.02 [20 Nov 2019]
* Device(s)    : R5F104ML
* Tool-Chain   : CCRL
* Description  : This file implements device driver for Serial module.
* Creation Date: 
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_dtc.h"
#include "freertos_start.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t * gp_uart3_tx_address;        /* uart3 transmit buffer address */
volatile uint16_t  g_uart3_tx_count;           /* uart3 transmit data number */
volatile uint8_t * gp_uart3_rx_address;        /* uart3 receive buffer address */
volatile uint16_t  g_uart3_rx_count;           /* uart3 receive data number */
volatile uint16_t  g_uart3_rx_length;          /* uart3 receive data length */
/* Start user code for global. Do not edit comment generated here */
TaskHandle_t       g_uart3_tx_task;            /* uart3 send task */
TaskHandle_t       g_uart3_rx_task;            /* uart3 receive task */
volatile bool      g_uart3_rx_error_flag;      /* uart3 receive error flag */

void U_UART3_Receive_Stop(void);               /* for internal use */
void U_UART3_Send_Stop(void);                  /* for internal use */

static void U_UART3_Receive(volatile uint8_t * rx_buf, uint16_t rx_num);
static void U_UART3_Send(uint8_t * tx_buf, uint16_t tx_num);

//#define R_UART3_Start R_UART3_Start_INERNAL_USE_ONLY
//void R_UART3_Start(void);
#define R_UART3_Receive R_UART3_Receive_INERNAL_USE_ONLY
MD_STATUS R_UART3_Receive(uint8_t * const rx_buf, uint16_t rx_num);
//#define R_UART3_Send R_UART3_Send_INERNAL_USE_ONLY
//MD_STATUS R_UART3_Send(uint8_t * const tx_buf, uint16_t tx_num);
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU1_Create
* Description  : This function initializes the SAU1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU1_Create(void)
{
    SAU1EN = 1U;    /* supply SAU1 clock */
    NOP();
    NOP();
    NOP();
    NOP();
    SPS1 = _0001_SAU_CK00_FCLK_1 | _0010_SAU_CK01_FCLK_1;
    R_UART3_Create();
}

/***********************************************************************************************************************
* Function Name: R_UART3_Create
* Description  : This function initializes the UART3 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART3_Create(void)
{
    ST1 |= _0008_SAU_CH3_STOP_TRG_ON | _0004_SAU_CH2_STOP_TRG_ON;    /* disable UART3 receive and transmit */
    STMK3 = 1U;    /* disable INTST3 interrupt */
    STIF3 = 0U;    /* clear INTST3 interrupt flag */
    SRMK3 = 1U;    /* disable INTSR3 interrupt */
    SRIF3 = 0U;    /* clear INTSR3 interrupt flag */
    SREMK3 = 1U;   /* disable INTSRE3 interrupt */
    SREIF3 = 0U;   /* clear INTSRE3 interrupt flag */
    /* Set INTST3 low priority */
    STPR13 = 1U;
    STPR03 = 1U;
    /* Set INTSR3 level2 priority */
    SRPR13 = 1U;
    SRPR03 = 0U;
    SMR12 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_TRIGGER_SOFTWARE |
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR12 = _8000_SAU_TRANSMISSION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            _0007_SAU_LENGTH_8;
    SDR12 = _8800_UART3_TRANSMIT_DIVISOR;
    NFEN0 |= _40_SAU_RXD3_FILTER_ON;
    SIR13 = _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR13 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0100_SAU_TRIGGER_RXD | _0000_SAU_EDGE_FALL |
            _0002_SAU_MODE_UART | _0000_SAU_TRANSFER_END;
    SCR13 = _4000_SAU_RECEPTION | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | _0080_SAU_LSB | _0010_SAU_STOP_1 |
            _0007_SAU_LENGTH_8;
    SDR13 = _8800_UART3_RECEIVE_DIVISOR;
    SO1 |= _0004_SAU_CH2_DATA_OUTPUT_1;
    SOL1 |= _0000_SAU_CHANNEL2_NORMAL;    /* output level normal */
    SOE1 |= _0004_SAU_CH2_OUTPUT_ENABLE;    /* enable UART3 output */
    /* Set RxD3 pin */
    PM14 |= 0x08U;
    /* Set TxD3 pin */
    P14 |= 0x10U;
    PM14 &= 0xEFU;
}

/***********************************************************************************************************************
* Function Name: R_UART3_Start
* Description  : This function starts the UART3 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART3_Start(void)
{
    SO1 |= _0004_SAU_CH2_DATA_OUTPUT_1;    /* output level normal */
    SOE1 |= _0004_SAU_CH2_OUTPUT_ENABLE;    /* enable UART3 output */
    SS1 |= _0008_SAU_CH3_START_TRG_ON | _0004_SAU_CH2_START_TRG_ON;    /* enable UART3 receive and transmit */
    STIF3 = 0U;    /* clear INTST3 interrupt flag */
    SRIF3 = 0U;    /* clear INTSR3 interrupt flag */
    STMK3 = 0U;    /* enable INTST3 interrupt */
    SRMK3 = 0U;    /* enable INTSR3 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_UART3_Stop
* Description  : This function stops the UART3 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UART3_Stop(void)
{
    STMK3 = 1U;    /* disable INTST3 interrupt */
    SRMK3 = 1U;    /* disable INTSR3 interrupt */
    ST1 |= _0008_SAU_CH3_STOP_TRG_ON | _0004_SAU_CH2_STOP_TRG_ON;    /* disable UART3 receive and transmit */
    SOE1 &= ~_0004_SAU_CH2_OUTPUT_ENABLE;    /* disable UART3 output */
    STIF3 = 0U;    /* clear INTST3 interrupt flag */
    SRIF3 = 0U;    /* clear INTSR3 interrupt flag */
   
}

/***********************************************************************************************************************
* Function Name: R_UART3_Receive
* Description  : This function receives UART3 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART3_Receive(uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_uart3_rx_count = 0U;
        g_uart3_rx_length = rx_num;
        gp_uart3_rx_address = rx_buf;
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_UART3_Send
* Description  : This function sends UART3 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UART3_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_uart3_tx_address = tx_buf;
        g_uart3_tx_count = tx_num;
        STMK3 = 1U;    /* disable INTST3 interrupt */
        TXD3 = *gp_uart3_tx_address;
        gp_uart3_tx_address++;
        g_uart3_tx_count--;
        STMK3 = 0U;    /* enable INTST3 interrupt */
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */

/******************************************************************************
* Function Name: U_UART3_Start
* Description  : This function starts the UART3 module.
* Arguments    : None
* Return Value : None
******************************************************************************/
void U_UART3_Start(void)
{
    R_UART3_Start();
    U_UART3_Receive_Stop();
    U_UART3_Receive_ClearError();
}

/******************************************************************************
* Function Name: U_UART3_Receive_Wait
* Description  : This function receives UART3 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
*                p_err_type -
*                    error type variable pointer
*                rx_wait -
*                    FreeRTOS's ticks to wait
* Return Value : status -
*                    MD_OK or MD_ARGERROR or MD_RECV_ERROR or MD_RECV_TIMEOUT
******************************************************************************/
MD_STATUS U_UART3_Receive_Wait(volatile uint8_t * rx_buf, uint16_t rx_num, volatile uint8_t * p_err_type, TickType_t rx_wait)
{
    MD_STATUS status = MD_OK;
    uint32_t value;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_uart3_rx_task = xTaskGetCurrentTaskHandle_R_Helper();
        U_UART3_Receive( rx_buf, rx_num );

        /* Wait for a notification from the interrupt/callback */
        value = ulTaskNotifyTake_R_Helper( rx_wait );

        if (0U == value)
        {
            /* Timeout */
            U_UART3_Receive_Stop();
            g_uart3_rx_task = NULL;

            /* Check an unhandled notification from timeout till stop */
            value = ulTaskNotifyTake_R_Helper( 0 );
        }

        if (0U != value)
        {
            /* Normal receive end or receive error */
            *p_err_type = (value >> 8) & 0xFFU;
            status = value & 0xFFU;
        }
        else
        {
            /* Timeout */
            *p_err_type = SCI_EVT_RXWAIT_TMOT;
            status = MD_RECV_TIMEOUT;
        }
    }

    return status;
}

static void U_UART3_Receive(volatile uint8_t * rx_buf, uint16_t rx_num)
{
    /* This function should be called in SRMK3==1 */
    R_UART3_Receive( (uint8_t *)rx_buf, rx_num );
    SRMK3 = 0U;        /* enable INTSR3 interrupt */
}

/******************************************************************************
* Function Name: U_UART3_Receive_Stop
* Description  : This function stops the UART3 data reception.
* Arguments    : None
* Return Value : None
* Note         : This is called from others internally.
******************************************************************************/
void U_UART3_Receive_Stop(void)
{
    SRMK3 = 1U;        /* disable INTSR3 interrupt */
}

/******************************************************************************
* Function Name: U_UART3_Receive_ClearError
* Description  : This function clears errors.
* Arguments    : None
* Return Value : None
******************************************************************************/
void U_UART3_Receive_ClearError(void)
{
    g_uart3_rx_error_flag = false;
    (void) RXD3;       /* dummy read */
    SIR13 = 0x0007U;   /* clear UART3 error flags */
    SRIF3 = 0U;        /* clear INTSR3 interrupt flag */
}

/******************************************************************************
* Function Name: U_UART3_Send_Wait
* Description  : This function sends UART3 data using DTCD0.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
******************************************************************************/
MD_STATUS U_UART3_Send_Wait(uint8_t * tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U || 256U < tx_num)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_uart3_tx_task = xTaskGetCurrentTaskHandle_R_Helper();
        U_UART3_Send( tx_buf, tx_num );

        /* Wait for a notification from the interrupt/callback */
        ulTaskNotifyTake_R_Helper( portMAX_DELAY );
    }

    return status;
}

static void U_UART3_Send(uint8_t * tx_buf, uint16_t tx_num)
{
    STIF3 = 0U;        /* clear INTST3 interrupt flag */
    if (1 < tx_num)
    {
        U_DTCD0_UserInit( tx_buf + 1, tx_num - 1 );
        R_DTCD0_Start();
    }
    R_UART3_Send( tx_buf, 1 );
}

/******************************************************************************
* Function Name: U_UART3_Send_Stop
* Description  : This function stops the UART3 data transmission.
* Arguments    : None
* Return Value : None
* Note         : This is called from others internally.
******************************************************************************/
void U_UART3_Send_Stop(void)
{
    STMK3 = 1U;        /* disable INTST3 interrupt */
    R_DTCD0_Stop();    /* forcibly stop DTCD0 (if it is operating) */
}

/* End user code. Do not edit comment generated here */
