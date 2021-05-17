/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : intrinsics.h
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release

***********************************************************************************************************************/
/*-------------------------------------------------------------------------
 *      Declarations of intrinsic functions.
 *
 *      This header file can be used with the
 *      IAR RL78 C/C++ compilers, ICCRL78.
 *
 *      Copyright 2011 IAR Systems AB.
 *
 *      $Revision: 4525 $
 *
 *-----------------------------------------------------------------------*/

#ifndef __INTRINSICS_INCLUDED
#define __INTRINSICS_INCLUDED

#ifndef __ICCRL78__
  #error "INTRINSICS.H file for use with ICCRL78 only"
#endif

#ifndef _SYSTEM_BUILD
#pragma system_include
#endif

#pragma language=save
#pragma language=extended

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char __istate_t;
typedef unsigned char __ilevel_t;

__intrinsic void __disable_interrupt(void);
__intrinsic void __enable_interrupt(void);
__intrinsic __istate_t __get_interrupt_state(void);
__intrinsic void __set_interrupt_state(__istate_t);

__intrinsic __ilevel_t __get_interrupt_level(void);
__intrinsic void __set_interrupt_level(__ilevel_t);

__intrinsic void __no_operation(void);
__intrinsic void __halt(void);
__intrinsic void __stop(void);
__intrinsic void __break(void);

__intrinsic __root int __low_level_init(void);

#if __CORE__ == __S3__
__intrinsic void __mach(signed short, signed short);
__intrinsic void __machu(unsigned short, unsigned short);
#endif

__intrinsic unsigned char __ror1b( unsigned char );
__intrinsic unsigned char __rol1b( unsigned char );

__intrinsic unsigned short __ror1w( unsigned short );
__intrinsic unsigned short __rol1w( unsigned short );



#pragma language=restore

#ifdef __cplusplus
}
#endif

#endif  /* __INTRINSICS_INCLUDED */
