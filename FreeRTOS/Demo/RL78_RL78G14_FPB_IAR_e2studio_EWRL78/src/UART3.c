/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
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
* Copyright (C) 2011, 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/*******************************************************************************
* File Name    : UART0.c
* Device(s)    : R5F100LE
* Tool-Chain   : CCRL
* Description  : �����O�o�b�t�@�̃T�|�[�g�֐��ł�
* Creation Date: 2016/08/11
*******************************************************************************/

/*******************************************************************************
Includes
*******************************************************************************/
#include "r_cg_macrodriver.h"
#include "UART3.h"
#include "r_cg_userdefine.h"

#define init_bf u_uart3_init_bf
#define chk_status u_uart3_chk_status
#define get_data u_uart3_get_data
#define get_blk u_uart3_get_blk
#define g_rx_buff g_uart3_rx_buff
#define g_rx_rdpt g_uart3_rx_rdpt
#define g_rx_dtno g_uart3_rx_dtno
#define g_rx_status g_uart3_rx_status
#define uartx_callback_receivedata u_uart3_callback_receivedata
#define RX_BUFF_SIZE UART3_RX_BUFF_SIZE
#define RX_DTPT_MASK (UART3_RX_BUFF_SIZE - 1)

#if 0    /* Non-OS */
#define SRMKx(mask) do{ SRMK3 = mask; }while (0)
#define SRENx()     do{ SRMK3 = 0; }while (0)
#elif 1    /* FreeRTOS */
#define SRMKx(mask) do{ if (mask != 0) { taskENTER_CRITICAL(); } else { taskEXIT_CRITICAL(); } }while (0)
#define SRENx()     do{ SRMK3 = 0; }while (0)
#elif 0    /* SEGGER embOS */
#elif 0    /* Micrium MicroC/OS */
#elif 0    /* Renesas RI600V4 & RI600PX */
#endif

/*******************************************************************************
Pragma directive
*******************************************************************************/

/*******************************************************************************
Global variables and functions
*******************************************************************************/
volatile uint8_t g_rx_buff[RX_BUFF_SIZE];       /* ��M�p�����O�o�b�t�@     */
volatile uint8_t g_rx_rdpt;                     /* �f�[�^�̓ǂݏo���|�C���^ */
volatile uint8_t g_rx_dtno;                     /* �i�[����Ă���f�[�^��   */
volatile uint8_t g_rx_status;                   /* ��M�X�e�[�^�X�t���O     
        bit7 : �I�[�o�t���[�E�t���O                                         */                                                                                                                          
/*******************************************************************************
* Function Name: init_bf
* Description  : �����O�o�b�t�@�̃|�C���^��������
* Arguments    : None
* Return Value : None
*******************************************************************************/
void init_bf(void)
{

    SRMKx(1);                                   /* INTSRx�Ƃ̔r������       */
    g_rx_rdpt = 0x00;                           /* �ǂݏo���|�C���^������   */
    g_rx_dtno = 0x00;                           /* �f�[�^�����N���A         */
    g_rx_status = 0x00;                         /* �X�e�[�^�X���N���A       */
    SRENx();                                    /* INTSRx�̍ŏ��̋���       */
    SRMKx(0);                                   /* �r�����䊮��             */

}

/*******************************************************************************
* Function Name: chk_status
* Description  : �����O�o�b�t�@�̏�Ԋm�F
* Arguments    : None
* Return Value : ��M�f�[�^��+�X�e�[�^�X
*               bit7 : �I�[�o�t���[�E�t���O
*               bit6,5 : 0,0
*               bit4-0 : �f�[�^��
*******************************************************************************/
uint8_t chk_status(void)
{
    uint8_t work;

    SRMKx(1);                                   /* INTSRx�Ƃ̔r������       */
    work = g_rx_status;                         /* �X�e�[�^�X�ǂݏo��       */
    g_rx_status = 0x00;                         /* �X�e�[�^�X���N���A       */
    work |= g_rx_dtno;                          /* �f�[�^���ǂݏo��         */
    SRMKx(0);                                   /* �r�����䊮��             */
    return ( work );

}

/*******************************************************************************
* Function Name: get_data
* Description  : �����O�o�b�t�@����1�f�[�^��ǂݏo��
* Arguments    : None
* Return Value : �f�[�^
*******************************************************************************/
uint8_t get_data(void)
{
    uint8_t work;

    if ( 0 == g_rx_dtno )
    {
        work = 0x00;                            /* �f�[�^���Ȃ���΁C0x00   */
    }
    else
    {
        work = g_rx_buff[g_rx_rdpt];            /* �f�[�^�̓ǂݏo��         */

        SRMKx(1);                               /* INTSRx�Ƃ̔r������       */
        g_rx_dtno--;
        g_rx_rdpt++;                            /* �|�C���^�X�V             */
        g_rx_rdpt &= RX_DTPT_MASK;
        SRMKx(0);                               /* �r�����䊮��             */
    }

    return ( work );

}

/*******************************************************************************
* Function Name: get_blk
* Description  : �����O�o�b�t�@����w�肳�ꂽ�f�[�^��ǂݏo���i�]���j
* Arguments    : �i�[�|�C���^�C�f�[�^��
* Return Value : �c��f�[�^��
*******************************************************************************/
uint8_t get_blk(uint8_t * const buff, uint8_t number)
{

    uint8_t work;
    uint8_t dtno;                               /* �����O�o�b�t�@���f�[�^�� */
    uint8_t cnt;                                /* �]���p�J�E���^           */
    uint8_t * gp_buff;                          /* �]���p�|�C���^           */

    work = number;                              /* �v���f�[�^�����Z�b�g     */
    dtno = g_rx_dtno;                           /* �ϐ���volatile�Ȃ̂ŕێ� */

    if ( ( 0 != number ) && ( 0 != dtno ) )
    {                               /* �]���f�[�^������ꍇ                 */

        gp_buff = buff;                         /* �]����|�C���^��ݒ�     */

/* ---------------------------------------------------------------------------

    �]���f�[�^�����Z�o

----------------------------------------------------------------------------*/

        if ( number < dtno )
        {                           /* �v�������f�[�^�ʈȉ��̏ꍇ           */
            cnt = number;                       /* �]���f�[�^�����Z�b�g     */
            work = 0;                           /* �c��f�[�^����0�ɂ���    */
        }
        else
        {                           /* �v�������f�[�^�ʈȏ�̏ꍇ           */
            cnt = dtno;                    /* �]�����̓o�b�t�@���̑S�� */
            work = number - dtno;          /* �c��f�[�^�����Z�o       */
        }

/* ---------------------------------------------------------------------------

    �f�[�^��]��

----------------------------------------------------------------------------*/

        for (  ; cnt > 0 ; cnt-- )
        {
            *gp_buff = g_rx_buff[g_rx_rdpt];    /* �����O�o�b�t�@����]��   */
            SRMKx(1);                           /* INTSRx�Ƃ̔r������       */
            g_rx_rdpt++;                        /* �ǂݏo���|�C���^���X�V   */
            g_rx_rdpt &= RX_DTPT_MASK;
            g_rx_dtno--;                        /* �f�[�^�����|1            */
            SRMKx(0);                           /* INTSRx�Ƃ̔r������I��   */
            gp_buff++;                          /* �]���|�C���^���X�V       */

        }
    

    }

    return( work );

}

/*******************************************************************************
* Function Name: uartx_callback_receivedata
* Description  : This function is a callback function when UARTx receives a data.
* Arguments    : rx_data -
*                    receive data
* Return Value : None
*******************************************************************************/
void uartx_callback_receivedata(uint16_t rx_data)
{
    /* ��M�p�����O�o�b�t�@���� */

    uint8_t  setptr;

    if ( g_rx_dtno < RX_BUFF_SIZE )
    {                           /* �o�b�t�@�ɋ󂫂���                       */
        setptr = ((g_rx_rdpt + g_rx_dtno) & RX_DTPT_MASK);  /* �������݃|�C���^ */
        g_rx_buff[setptr] = rx_data;    /* ��M�f�[�^���o�b�t�@�Ɋi�[       */
        g_rx_dtno++;
    }
    else
    {                           /* �o�b�t�@���t�����̏���                   */
        g_rx_status = 0x80;             /* �I�[�o�t���[�E�t���O���Z�b�g     */
    }

}
