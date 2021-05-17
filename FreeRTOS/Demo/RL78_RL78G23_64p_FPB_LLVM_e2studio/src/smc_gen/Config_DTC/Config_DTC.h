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
* File Name    : Config_DTC.h
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_DTC.
* Creation Date: 
***********************************************************************************************************************/

#ifndef CFG_Config_DTC_H
#define CFG_Config_DTC_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_dtc.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _01_DTCD0_TRANSFER_BLOCKSIZE       (0x01U)    /* transfer block size */
#define _01_DTCD0_TRANSFER_BYTE            (0x01U)    /* number of transfers */
#define _FEDF_DTCD0_SRC_ADDRESS            (0xFEDFU)
#define _FFFF_DTCD0_DEST_ADDRESS           (0xFFFFU)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef struct
{
    uint8_t  dtccr;
    uint8_t  dtbls;
    uint8_t  dtcct;
    uint8_t  dtrld;
    uint16_t dtsar;
    uint16_t dtdar;
}st_dtc_data_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_DTC_Create(void);
void R_DTCD0_Start(void);
void R_DTCD0_Stop(void);
void R_Config_DTC_Create_UserInit(void);
/* Start user code for function. Do not edit comment generated here */

void U_DTCD0_UserInit(volatile uint8_t * tx_buf, uint16_t tx_num);

/* End user code. Do not edit comment generated here */
#endif
