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
* File Name    : Config_UART1.h
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_UART1.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_sau.h"

#ifndef CFG_Config_UART1_H
#define CFG_Config_UART1_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _0E00_SAU0_CH2_TRANSMIT_DIVISOR    (0x0E00U)
#define _0E00_SAU0_CH3_RECEIVE_DIVISOR    (0x0E00U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_UART1_Create(void);
void R_Config_UART1_Start(void);
void R_Config_UART1_Stop(void);
MD_STATUS R_Config_UART1_Send(uint8_t * const tx_buf, uint16_t tx_num);
MD_STATUS R_Config_UART1_Receive(uint8_t * const rx_buf, uint16_t rx_num);
void R_Config_UART1_Loopback_Enable(void);
void R_Config_UART1_Loopback_Disable(void);
void R_Config_UART1_Create_UserInit(void);
/* Start user code for function. Do not edit comment generated here */

#include "platform.h" /* for the TickType_t type in this header file */

void U_Config_UART1_Start(void);
MD_STATUS U_Config_UART1_Send_Wait(uint8_t * tx_buf, uint16_t tx_num);
MD_STATUS U_Config_UART1_Send_Start(uint8_t * tx_buf, uint16_t tx_num);
MD_STATUS U_Config_UART1_Receive_Wait(uint8_t * rx_buf, uint16_t rx_num, uint8_t * p_err_events, TickType_t rx_wait);
void U_Config_UART1_Receive_ClearError(void);

#define SCI_EVT_RXBUF_OVFL  0x80U
/*#define SCI_EVT_RXDTC_SWOR  0x80U*/
#define SCI_EVT_RXWAIT_TMOT 0x40U
#define SCI_EVT_OVFL_ERR    _0001_SAU_OVERRUN_ERROR /* 0x0001U */
#define SCI_EVT_FRAMING_ERR _0004_SAU_FRAM_ERROR    /* 0x0004U */
#define SCI_EVT_PARITY_ERR  _0002_SAU_PARITY_ERROR  /* 0x0002U */

#define MD_RECV_ERROR       MD_ERROR1
#define MD_RECV_TIMEOUT     MD_ERROR2
/*#define MD_SEND_ERROR       MD_ERROR3*/
/*#define MD_SEND_TIMEOUT     MD_ERROR4*/
/*#define MD_SEND_BUSY        MD_ERROR5*/

/* End user code. Do not edit comment generated here */
#endif

