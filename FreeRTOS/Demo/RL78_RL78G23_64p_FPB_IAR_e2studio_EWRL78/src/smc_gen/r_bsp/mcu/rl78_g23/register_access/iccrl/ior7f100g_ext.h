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
* File Name    : ior7f100g_ext.h
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release

***********************************************************************************************************************/
/*-------------------------------------------------------------------------
 *      Declarations of extended SFR registers for RL78 microcontroller R7F100G.
 *
 *      This file can be used by both the RL78,
 *      Assembler, ARL78, and the C/C++ compiler, ICCRL78.
 *-------------------------------------------------------------------------*/

#ifndef __IOR7F100G_EXT_H__
#define __IOR7F100G_EXT_H__

#if !defined(__IASMRL78__) && !defined(__ICCRL78__)
  #error "IOR7F100G_EXT.H file for use with RL78 Assembler or Compiler only"
#endif

#if defined(__IASMRL78__)
  #if __CORE__ != __S3__
    #error "IOR7F100G_EXT.H file for use with IASMRL78 option --core S3 only"
  #endif
#endif
#if defined(__ICCRL78__)
  #if __CORE__ != __S3__
    #error "IOR7F100G_EXT.H file for use with ICCRL78 option --core S3 only"
  #endif
#endif

#ifdef __IAR_SYSTEMS_ICC__

#ifndef _SYSTEM_BUILD
#pragma system_include
#endif

#pragma language=save
#pragma language=extended

/*----------------------------------------------
 * SFR bits (default names)
 *--------------------------------------------*/

#ifndef __RL78_BIT_STRUCTURE__
  #define __RL78_BIT_STRUCTURE__
  typedef struct
  {
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
  } __BITS8;
#endif

#ifndef __RL78_BIT_STRUCTURE2__
  #define __RL78_BIT_STRUCTURE2__
  typedef struct
  {
    unsigned short no0:1;
    unsigned short no1:1;
    unsigned short no2:1;
    unsigned short no3:1;
    unsigned short no4:1;
    unsigned short no5:1;
    unsigned short no6:1;
    unsigned short no7:1;
    unsigned short no8:1;
    unsigned short no9:1;
    unsigned short no10:1;
    unsigned short no11:1;
    unsigned short no12:1;
    unsigned short no13:1;
    unsigned short no14:1;
    unsigned short no15:1;
  } __BITS16;
#endif

/*----------------------------------------------
 *       Extended SFR declarations
 *--------------------------------------------*/

__near __no_init volatile union
{
  unsigned char ADM2;
  __BITS8       ADM2_bit;
  struct
  {
    unsigned char  ADTYP0:1;
    unsigned char  ADTYP1:1;
    unsigned char  AWC:1;
    unsigned char  ADRCK:1;
    unsigned char  :4;
  };
} @ 0xF0010;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADUL;
  __BITS8       ADUL_bit;
} @ 0xF0011;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADLL;
  __BITS8       ADLL_bit;
} @ 0xF0012;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADTES;
  __BITS8       ADTES_bit;
} @ 0xF0013;

__near __no_bit_access __no_init volatile const union
{
  unsigned short ADCR0;
  __BITS16       ADCR0_bit;
  struct
  {
    unsigned char :8;
    union
    {
      unsigned char ADCR0H;
      __BITS8       ADCR0H_bit;
    };
  };
} @ 0xF0020;

__near __no_bit_access __no_init volatile const union
{
  unsigned short ADCR1;
  __BITS16       ADCR1_bit;
  struct
  {
    unsigned char :8;
    union
    {
      unsigned char ADCR1H;
      __BITS8       ADCR1H_bit;
    };
  };
} @ 0xF0022;

__near __no_bit_access __no_init volatile const union
{
  unsigned short ADCR2;
  __BITS16       ADCR2_bit;
  struct
  {
    unsigned char :8;
    union
    {
      unsigned char ADCR2H;
      __BITS8       ADCR2H_bit;
    };
  };
} @ 0xF0024;

__near __no_bit_access __no_init volatile const union
{
  unsigned short ADCR3;
  __BITS16       ADCR3_bit;
  struct
  {
    unsigned char :8;
    union
    {
      unsigned char ADCR3H;
      __BITS8       ADCR3H_bit;
    };
  };
} @ 0xF0026;

__near __no_init volatile union
{
  unsigned char PU0;
  __BITS8       PU0_bit;
} @ 0xF0030;

__near __no_init volatile union
{
  unsigned char PU1;
  __BITS8       PU1_bit;
} @ 0xF0031;

__near __no_init volatile union
{
  unsigned char PU3;
  __BITS8       PU3_bit;
} @ 0xF0033;

__near __no_init volatile union
{
  unsigned char PU4;
  __BITS8       PU4_bit;
} @ 0xF0034;

__near __no_init volatile union
{
  unsigned char PU5;
  __BITS8       PU5_bit;
} @ 0xF0035;

__near __no_init volatile union
{
  unsigned char PU6;
  __BITS8       PU6_bit;
} @ 0xF0036;

__near __no_init volatile union
{
  unsigned char PU7;
  __BITS8       PU7_bit;
} @ 0xF0037;

__near __no_init volatile union
{
  unsigned char PU8;
  __BITS8       PU8_bit;
} @ 0xF0038;

__near __no_init volatile union
{
  unsigned char PU9;
  __BITS8       PU9_bit;
} @ 0xF0039;

__near __no_init volatile union
{
  unsigned char PU10;
  __BITS8       PU10_bit;
} @ 0xF003A;

__near __no_init volatile union
{
  unsigned char PU11;
  __BITS8       PU11_bit;
} @ 0xF003B;

__near __no_init volatile union
{
  unsigned char PU12;
  __BITS8       PU12_bit;
} @ 0xF003C;

__near __no_init volatile union
{
  unsigned char PU14;
  __BITS8       PU14_bit;
} @ 0xF003E;

__near __no_init volatile union
{
  unsigned char PIM0;
  __BITS8       PIM0_bit;
} @ 0xF0040;

__near __no_init volatile union
{
  unsigned char PIM1;
  __BITS8       PIM1_bit;
} @ 0xF0041;

__near __no_init volatile union
{
  unsigned char PIM3;
  __BITS8       PIM3_bit;
} @ 0xF0043;

__near __no_init volatile union
{
  unsigned char PIM4;
  __BITS8       PIM4_bit;
} @ 0xF0044;

__near __no_init volatile union
{
  unsigned char PIM5;
  __BITS8       PIM5_bit;
} @ 0xF0045;

__near __no_init volatile union
{
  unsigned char PIM7;
  __BITS8       PIM7_bit;
} @ 0xF0047;

__near __no_init volatile union
{
  unsigned char PIM8;
  __BITS8       PIM8_bit;
} @ 0xF0048;

__near __no_init volatile union
{
  unsigned char PIM14;
  __BITS8       PIM14_bit;
} @ 0xF004E;

__near __no_init volatile union
{
  unsigned char POM0;
  __BITS8       POM0_bit;
} @ 0xF0050;

__near __no_init volatile union
{
  unsigned char POM1;
  __BITS8       POM1_bit;
} @ 0xF0051;

__near __no_init volatile union
{
  unsigned char POM3;
  __BITS8       POM3_bit;
} @ 0xF0053;

__near __no_init volatile union
{
  unsigned char POM4;
  __BITS8       POM4_bit;
} @ 0xF0054;

__near __no_init volatile union
{
  unsigned char POM5;
  __BITS8       POM5_bit;
} @ 0xF0055;

__near __no_init volatile union
{
  unsigned char POM7;
  __BITS8       POM7_bit;
} @ 0xF0057;

__near __no_init volatile union
{
  unsigned char POM8;
  __BITS8       POM8_bit;
} @ 0xF0058;

__near __no_init volatile union
{
  unsigned char POM9;
  __BITS8       POM9_bit;
} @ 0xF0059;

__near __no_init volatile union
{
  unsigned char POM12;
  __BITS8       POM12_bit;
} @ 0xF005C;

__near __no_init volatile union
{
  unsigned char POM14;
  __BITS8       POM14_bit;
} @ 0xF005E;

__near __no_init volatile union
{
  unsigned char PMCA0;
  __BITS8       PMCA0_bit;
} @ 0xF0060;

__near __no_init volatile union
{
  unsigned char PMCA1;
  __BITS8       PMCA1_bit;
} @ 0xF0061;

__near __no_init volatile union
{
  unsigned char PMCA2;
  __BITS8       PMCA2_bit;
} @ 0xF0062;

__near __no_init volatile union
{
  unsigned char PMCA3;
  __BITS8       PMCA3_bit;
} @ 0xF0063;

__near __no_init volatile union
{
  unsigned char PMCA10;
  __BITS8       PMCA10_bit;
} @ 0xF006A;

__near __no_init volatile union
{
  unsigned char PMCA11;
  __BITS8       PMCA11_bit;
} @ 0xF006B;

__near __no_init volatile union
{
  unsigned char PMCA12;
  __BITS8       PMCA12_bit;
} @ 0xF006C;

__near __no_init volatile union
{
  unsigned char PMCA14;
  __BITS8       PMCA14_bit;
} @ 0xF006E;

__near __no_init volatile union
{
  unsigned char PMCA15;
  __BITS8       PMCA15_bit;
} @ 0xF006F;

__near __no_init volatile union
{
  unsigned char NFEN0;
  __BITS8       NFEN0_bit;
} @ 0xF0070;

__near __no_init volatile union
{
  unsigned char NFEN1;
  __BITS8       NFEN1_bit;
} @ 0xF0071;

__near __no_init volatile union
{
  unsigned char NFEN2;
  __BITS8       NFEN2_bit;
} @ 0xF0072;

__near __no_init volatile union
{
  unsigned char ISC;
  __BITS8       ISC_bit;
} @ 0xF0073;

__near __no_bit_access __no_init volatile union
{
  unsigned char TIS0;
  __BITS8       TIS0_bit;
} @ 0xF0074;

__near __no_bit_access __no_init volatile union
{
  unsigned char TIS1;
  __BITS8       TIS1_bit;
} @ 0xF0075;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR;
  __BITS8       PIOR_bit;
} @ 0xF0077;

__near __no_bit_access __no_init volatile union
{
  unsigned char IAWCTL;
  __BITS8       IAWCTL_bit;
} @ 0xF0078;

__near __no_init volatile union
{
  unsigned char ULBS;
  __BITS8       ULBS_bit;
  struct
  {
    unsigned char  ULBS0:1;
    unsigned char  ULBS1:1;
    unsigned char  ULBS2:1;
    unsigned char  ULBS3:1;
    unsigned char  ULBS4:1;
    unsigned char  ULBS5:1;
    unsigned char  :2;
  };
} @ 0xF0079;

__near __no_init volatile union
{
  unsigned char PMS;
  __BITS8       PMS_bit;
} @ 0xF007B;

__near __no_init volatile union
{
  unsigned char GDIDIS;
  __BITS8       GDIDIS_bit;
} @ 0xF007D;

__near __no_init volatile union
{
  unsigned char DFLCTL;
  __BITS8       DFLCTL_bit;
  struct
  {
    unsigned char  DFLEN:1;
    unsigned char  :7;
  };
} @ 0xF0090;

__near __no_bit_access __no_init volatile union
{
  unsigned char HIOTRM;
  __BITS8       HIOTRM_bit;
} @ 0xF00A0;

__near __no_bit_access __no_init volatile union
{
  unsigned char HOCODIV;
  __BITS8       HOCODIV_bit;
} @ 0xF00A8;

__near __no_init volatile union
{
  unsigned char FLMODE;
  __BITS8       FLMODE_bit;
  struct
  {
    unsigned char  :6;
    unsigned char  MODE0:1;
    unsigned char  MODE1:1;
  };
} @ 0xF00AA;

__near __no_init volatile union
{
  unsigned char FLMWRP;
  __BITS8       FLMWRP_bit;
  struct
  {
    unsigned char  FLMWEN:1;
    unsigned char  :7;
  };
} @ 0xF00AB;

__near __no_bit_access __no_init volatile const union
{
  unsigned short FLSEC;
  __BITS16       FLSEC_bit;
} @ 0xF00B0;

__near __no_bit_access __no_init volatile const union
{
  unsigned short FLFSWS;
  __BITS16       FLFSWS_bit;
} @ 0xF00B2;

__near __no_bit_access __no_init volatile const union
{
  unsigned short FLFSWE;
  __BITS16       FLFSWE_bit;
} @ 0xF00B4;

__near __no_bit_access __no_init volatile union
{
  unsigned char FSSET;
  __BITS8       FSSET_bit;
} @ 0xF00B6;

__near __no_init volatile union
{
  unsigned char FSSE;
  __BITS8       FSSE_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  ESQST:1;
  };
} @ 0xF00B7;

__near __no_bit_access __no_init volatile const union
{
  unsigned short FLFADL;
  __BITS16       FLFADL_bit;
} @ 0xF00B8;

__near __no_bit_access __no_init volatile const union
{
  unsigned char FLFADH;
  __BITS8       FLFADH_bit;
} @ 0xF00BA;

__near __no_bit_access __no_init volatile union
{
  unsigned char PFCMD;
  __BITS8       PFCMD_bit;
} @ 0xF00C0;

__near __no_init volatile const union
{
  unsigned char PFS;
  __BITS8       PFS_bit;
} @ 0xF00C1;

__near __no_bit_access __no_init volatile union
{
  unsigned char FLWE;
  __BITS8       FLWE_bit;
} @ 0xF00C6;

__near __no_init volatile union
{
  unsigned char PER0;
  __BITS8       PER0_bit;
  struct
  {
    unsigned char  TAU0EN:1;
    unsigned char  TAU1EN:1;
    unsigned char  SAU0EN:1;
    unsigned char  SAU1EN:1;
    unsigned char  IICA0EN:1;
    unsigned char  ADCEN:1;
    unsigned char  IICA1EN:1;
    unsigned char  RTCWEN:1;
  };
} @ 0xF00F0;

__near __no_init volatile union
{
  unsigned char PRR0;
  __BITS8       PRR0_bit;
  struct
  {
    unsigned char  TAU0RES:1;
    unsigned char  TAU1RES:1;
    unsigned char  SAU0RES:1;
    unsigned char  SAU1RES:1;
    unsigned char  IICA0RES:1;
    unsigned char  ADCRES:1;
    unsigned char  IICA1RES:1;
    unsigned char  :1;
  };
} @ 0xF00F1;

__near __no_bit_access __no_init volatile union
{
  unsigned char MOCODIV;
  __BITS8       MOCODIV_bit;
} @ 0xF00F2;

__near __no_init volatile union
{
  unsigned char OSMC;
  __BITS8       OSMC_bit;
  struct
  {
    unsigned char  HIPREC:1;
    unsigned char  :3;
    unsigned char  WUTMMCK0:1;
    unsigned char  :2;
    unsigned char  RTCLPC:1;
  };
} @ 0xF00F3;

__near __no_init volatile union
{
  unsigned char RPECTL;
  __BITS8       RPECTL_bit;
  struct
  {
    unsigned char  RPEF:1;
    unsigned char  :6;
    unsigned char  RPERDIS:1;
  };
} @ 0xF00F5;

__near __no_init volatile union
{
  unsigned char PORSR;
  __BITS8       PORSR_bit;
  struct
  {
    unsigned char  PORF:1;
    unsigned char  :7;
  };
} @ 0xF00F9;

__near __no_init volatile union
{
  unsigned char PER1;
  __BITS8       PER1_bit;
  struct
  {
    unsigned char  CTSUEN:1;
    unsigned char  REMCEN:1;
    unsigned char  UTAEN:1;
    unsigned char  DTCEN:1;
    unsigned char  TML32EN:1;
    unsigned char  CMPEN:1;
    unsigned char  SMSEN:1;
    unsigned char  DACEN:1;
  };
} @ 0xF00FA;

__near __no_init volatile union
{
  unsigned char PRR1;
  __BITS8       PRR1_bit;
  struct
  {
    unsigned char  CTSURES:1;
    unsigned char  REMCRES:1;
    unsigned char  :2;
    unsigned char  TML32RES:1;
    unsigned char  CMPRES:1;
    unsigned char  SMSRES:1;
    unsigned char  DACRES:1;
  };
} @ 0xF00FB;

__near __no_bit_access __no_init volatile const union
{
  unsigned char BCDADJ;
  __BITS8       BCDADJ_bit;
} @ 0xF00FE;

__near __no_bit_access __no_init volatile union
{
  unsigned char VECTCTRL;
  __BITS8       VECTCTRL_bit;
} @ 0xF00FF;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SSR00;
  __BITS16       SSR00_bit;
  struct
  {
    union
    {
      unsigned char SSR00L;
      __BITS8       SSR00L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0100;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SSR01;
  __BITS16       SSR01_bit;
  struct
  {
    union
    {
      unsigned char SSR01L;
      __BITS8       SSR01L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0102;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SSR02;
  __BITS16       SSR02_bit;
  struct
  {
    union
    {
      unsigned char SSR02L;
      __BITS8       SSR02L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0104;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SSR03;
  __BITS16       SSR03_bit;
  struct
  {
    union
    {
      unsigned char SSR03L;
      __BITS8       SSR03L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0106;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR00;
  __BITS16       SIR00_bit;
  struct
  {
    union
    {
      unsigned char SIR00L;
      __BITS8       SIR00L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0108;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR01;
  __BITS16       SIR01_bit;
  struct
  {
    union
    {
      unsigned char SIR01L;
      __BITS8       SIR01L_bit;
    };
    unsigned char :8;
  };
} @ 0xF010A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR02;
  __BITS16       SIR02_bit;
  struct
  {
    union
    {
      unsigned char SIR02L;
      __BITS8       SIR02L_bit;
    };
    unsigned char :8;
  };
} @ 0xF010C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR03;
  __BITS16       SIR03_bit;
  struct
  {
    union
    {
      unsigned char SIR03L;
      __BITS8       SIR03L_bit;
    };
    unsigned char :8;
  };
} @ 0xF010E;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR00;
  __BITS16       SMR00_bit;
} @ 0xF0110;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR01;
  __BITS16       SMR01_bit;
} @ 0xF0112;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR02;
  __BITS16       SMR02_bit;
} @ 0xF0114;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR03;
  __BITS16       SMR03_bit;
} @ 0xF0116;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR00;
  __BITS16       SCR00_bit;
} @ 0xF0118;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR01;
  __BITS16       SCR01_bit;
} @ 0xF011A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR02;
  __BITS16       SCR02_bit;
} @ 0xF011C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR03;
  __BITS16       SCR03_bit;
} @ 0xF011E;

__near __no_init volatile const union
{
  unsigned short SE0;
  __BITS16       SE0_bit;
  struct
  {
    union
    {
      unsigned char SE0L;
      __BITS8       SE0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0120;

__near __no_init volatile union
{
  unsigned short SS0;
  __BITS16       SS0_bit;
  struct
  {
    union
    {
      unsigned char SS0L;
      __BITS8       SS0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0122;

__near __no_init volatile union
{
  unsigned short ST0;
  __BITS16       ST0_bit;
  struct
  {
    union
    {
      unsigned char ST0L;
      __BITS8       ST0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0124;

__near __no_bit_access __no_init volatile union
{
  unsigned short SPS0;
  __BITS16       SPS0_bit;
  struct
  {
    union
    {
      unsigned char SPS0L;
      __BITS8       SPS0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0126;

__near __no_bit_access __no_init volatile union
{
  unsigned short SO0;
  __BITS16       SO0_bit;
} @ 0xF0128;

__near __no_init volatile union
{
  unsigned short SOE0;
  __BITS16       SOE0_bit;
  struct
  {
    union
    {
      unsigned char SOE0L;
      __BITS8       SOE0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF012A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SOL0;
  __BITS16       SOL0_bit;
  struct
  {
    union
    {
      unsigned char SOL0L;
      __BITS8       SOL0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0134;

__near __no_bit_access __no_init volatile union
{
  unsigned short SSC0;
  __BITS16       SSC0_bit;
  struct
  {
    union
    {
      unsigned char SSC0L;
      __BITS8       SSC0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0138;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SSR10;
  __BITS16       SSR10_bit;
  struct
  {
    union
    {
      unsigned char SSR10L;
      __BITS8       SSR10L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0140;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SSR11;
  __BITS16       SSR11_bit;
  struct
  {
    union
    {
      unsigned char SSR11L;
      __BITS8       SSR11L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0142;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SSR12;
  __BITS16       SSR12_bit;
  struct
  {
    union
    {
      unsigned char SSR12L;
      __BITS8       SSR12L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0144;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SSR13;
  __BITS16       SSR13_bit;
  struct
  {
    union
    {
      unsigned char SSR13L;
      __BITS8       SSR13L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0146;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR10;
  __BITS16       SIR10_bit;
  struct
  {
    union
    {
      unsigned char SIR10L;
      __BITS8       SIR10L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0148;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR11;
  __BITS16       SIR11_bit;
  struct
  {
    union
    {
      unsigned char SIR11L;
      __BITS8       SIR11L_bit;
    };
    unsigned char :8;
  };
} @ 0xF014A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR12;
  __BITS16       SIR12_bit;
  struct
  {
    union
    {
      unsigned char SIR12L;
      __BITS8       SIR12L_bit;
    };
    unsigned char :8;
  };
} @ 0xF014C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR13;
  __BITS16       SIR13_bit;
  struct
  {
    union
    {
      unsigned char SIR13L;
      __BITS8       SIR13L_bit;
    };
    unsigned char :8;
  };
} @ 0xF014E;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR10;
  __BITS16       SMR10_bit;
} @ 0xF0150;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR11;
  __BITS16       SMR11_bit;
} @ 0xF0152;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR12;
  __BITS16       SMR12_bit;
} @ 0xF0154;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR13;
  __BITS16       SMR13_bit;
} @ 0xF0156;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR10;
  __BITS16       SCR10_bit;
} @ 0xF0158;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR11;
  __BITS16       SCR11_bit;
} @ 0xF015A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR12;
  __BITS16       SCR12_bit;
} @ 0xF015C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR13;
  __BITS16       SCR13_bit;
} @ 0xF015E;

__near __no_init volatile const union
{
  unsigned short SE1;
  __BITS16       SE1_bit;
  struct
  {
    union
    {
      unsigned char SE1L;
      __BITS8       SE1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0160;

__near __no_init volatile union
{
  unsigned short SS1;
  __BITS16       SS1_bit;
  struct
  {
    union
    {
      unsigned char SS1L;
      __BITS8       SS1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0162;

__near __no_init volatile union
{
  unsigned short ST1;
  __BITS16       ST1_bit;
  struct
  {
    union
    {
      unsigned char ST1L;
      __BITS8       ST1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0164;

__near __no_bit_access __no_init volatile union
{
  unsigned short SPS1;
  __BITS16       SPS1_bit;
  struct
  {
    union
    {
      unsigned char SPS1L;
      __BITS8       SPS1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0166;

__near __no_bit_access __no_init volatile union
{
  unsigned short SO1;
  __BITS16       SO1_bit;
} @ 0xF0168;

__near __no_init volatile union
{
  unsigned short SOE1;
  __BITS16       SOE1_bit;
  struct
  {
    union
    {
      unsigned char SOE1L;
      __BITS8       SOE1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF016A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SOL1;
  __BITS16       SOL1_bit;
  struct
  {
    union
    {
      unsigned char SOL1L;
      __BITS8       SOL1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0174;

__near __no_bit_access __no_init volatile union
{
  unsigned short SSC1;
  __BITS16       SSC1_bit;
  struct
  {
    union
    {
      unsigned char SSC1L;
      __BITS8       SSC1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0178;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR00;
  __BITS16       TCR00_bit;
} @ 0xF0180;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR01;
  __BITS16       TCR01_bit;
} @ 0xF0182;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR02;
  __BITS16       TCR02_bit;
} @ 0xF0184;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR03;
  __BITS16       TCR03_bit;
} @ 0xF0186;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR04;
  __BITS16       TCR04_bit;
} @ 0xF0188;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR05;
  __BITS16       TCR05_bit;
} @ 0xF018A;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR06;
  __BITS16       TCR06_bit;
} @ 0xF018C;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR07;
  __BITS16       TCR07_bit;
} @ 0xF018E;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR00;
  __BITS16       TMR00_bit;
} @ 0xF0190;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR01;
  __BITS16       TMR01_bit;
} @ 0xF0192;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR02;
  __BITS16       TMR02_bit;
} @ 0xF0194;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR03;
  __BITS16       TMR03_bit;
} @ 0xF0196;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR04;
  __BITS16       TMR04_bit;
} @ 0xF0198;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR05;
  __BITS16       TMR05_bit;
} @ 0xF019A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR06;
  __BITS16       TMR06_bit;
} @ 0xF019C;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR07;
  __BITS16       TMR07_bit;
} @ 0xF019E;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR00;
  __BITS16       TSR00_bit;
  struct
  {
    union
    {
      unsigned char TSR00L;
      __BITS8       TSR00L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A0;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR01;
  __BITS16       TSR01_bit;
  struct
  {
    union
    {
      unsigned char TSR01L;
      __BITS8       TSR01L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A2;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR02;
  __BITS16       TSR02_bit;
  struct
  {
    union
    {
      unsigned char TSR02L;
      __BITS8       TSR02L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A4;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR03;
  __BITS16       TSR03_bit;
  struct
  {
    union
    {
      unsigned char TSR03L;
      __BITS8       TSR03L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A6;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR04;
  __BITS16       TSR04_bit;
  struct
  {
    union
    {
      unsigned char TSR04L;
      __BITS8       TSR04L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A8;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR05;
  __BITS16       TSR05_bit;
  struct
  {
    union
    {
      unsigned char TSR05L;
      __BITS8       TSR05L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01AA;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR06;
  __BITS16       TSR06_bit;
  struct
  {
    union
    {
      unsigned char TSR06L;
      __BITS8       TSR06L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01AC;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR07;
  __BITS16       TSR07_bit;
  struct
  {
    union
    {
      unsigned char TSR07L;
      __BITS8       TSR07L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01AE;

__near __no_init volatile const union
{
  unsigned short TE0;
  __BITS16       TE0_bit;
  struct
  {
    union
    {
      unsigned char TE0L;
      __BITS8       TE0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01B0;

__near __no_init volatile union
{
  unsigned short TS0;
  __BITS16       TS0_bit;
  struct
  {
    union
    {
      unsigned char TS0L;
      __BITS8       TS0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01B2;

__near __no_init volatile union
{
  unsigned short TT0;
  __BITS16       TT0_bit;
  struct
  {
    union
    {
      unsigned char TT0L;
      __BITS8       TT0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01B4;

__near __no_bit_access __no_init volatile union
{
  unsigned short TPS0;
  __BITS16       TPS0_bit;
} @ 0xF01B6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TO0;
  __BITS16       TO0_bit;
  struct
  {
    union
    {
      unsigned char TO0L;
      __BITS8       TO0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01B8;

__near __no_init volatile union
{
  unsigned short TOE0;
  __BITS16       TOE0_bit;
  struct
  {
    union
    {
      unsigned char TOE0L;
      __BITS8       TOE0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01BA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TOL0;
  __BITS16       TOL0_bit;
  struct
  {
    union
    {
      unsigned char TOL0L;
      __BITS8       TOL0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01BC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TOM0;
  __BITS16       TOM0_bit;
  struct
  {
    union
    {
      unsigned char TOM0L;
      __BITS8       TOM0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01BE;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR10;
  __BITS16       TCR10_bit;
} @ 0xF01C0;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR11;
  __BITS16       TCR11_bit;
} @ 0xF01C2;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR12;
  __BITS16       TCR12_bit;
} @ 0xF01C4;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR13;
  __BITS16       TCR13_bit;
} @ 0xF01C6;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR14;
  __BITS16       TCR14_bit;
} @ 0xF01C8;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR15;
  __BITS16       TCR15_bit;
} @ 0xF01CA;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR16;
  __BITS16       TCR16_bit;
} @ 0xF01CC;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TCR17;
  __BITS16       TCR17_bit;
} @ 0xF01CE;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR10;
  __BITS16       TMR10_bit;
} @ 0xF01D0;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR11;
  __BITS16       TMR11_bit;
} @ 0xF01D2;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR12;
  __BITS16       TMR12_bit;
} @ 0xF01D4;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR13;
  __BITS16       TMR13_bit;
} @ 0xF01D6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR14;
  __BITS16       TMR14_bit;
} @ 0xF01D8;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR15;
  __BITS16       TMR15_bit;
} @ 0xF01DA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR16;
  __BITS16       TMR16_bit;
} @ 0xF01DC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR17;
  __BITS16       TMR17_bit;
} @ 0xF01DE;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR10;
  __BITS16       TSR10_bit;
  struct
  {
    union
    {
      unsigned char TSR10L;
      __BITS8       TSR10L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01E0;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR11;
  __BITS16       TSR11_bit;
  struct
  {
    union
    {
      unsigned char TSR11L;
      __BITS8       TSR11L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01E2;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR12;
  __BITS16       TSR12_bit;
  struct
  {
    union
    {
      unsigned char TSR12L;
      __BITS8       TSR12L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01E4;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR13;
  __BITS16       TSR13_bit;
  struct
  {
    union
    {
      unsigned char TSR13L;
      __BITS8       TSR13L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01E6;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR14;
  __BITS16       TSR14_bit;
  struct
  {
    union
    {
      unsigned char TSR14L;
      __BITS8       TSR14L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01E8;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR15;
  __BITS16       TSR15_bit;
  struct
  {
    union
    {
      unsigned char TSR15L;
      __BITS8       TSR15L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01EA;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR16;
  __BITS16       TSR16_bit;
  struct
  {
    union
    {
      unsigned char TSR16L;
      __BITS8       TSR16L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01EC;

__near __no_bit_access __no_init volatile const union
{
  unsigned short TSR17;
  __BITS16       TSR17_bit;
  struct
  {
    union
    {
      unsigned char TSR17L;
      __BITS8       TSR17L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01EE;

__near __no_init volatile const union
{
  unsigned short TE1;
  __BITS16       TE1_bit;
  struct
  {
    union
    {
      unsigned char TE1L;
      __BITS8       TE1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01F0;

__near __no_init volatile union
{
  unsigned short TS1;
  __BITS16       TS1_bit;
  struct
  {
    union
    {
      unsigned char TS1L;
      __BITS8       TS1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01F2;

__near __no_init volatile union
{
  unsigned short TT1;
  __BITS16       TT1_bit;
  struct
  {
    union
    {
      unsigned char TT1L;
      __BITS8       TT1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01F4;

__near __no_bit_access __no_init volatile union
{
  unsigned short TPS1;
  __BITS16       TPS1_bit;
} @ 0xF01F6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TO1;
  __BITS16       TO1_bit;
  struct
  {
    union
    {
      unsigned char TO1L;
      __BITS8       TO1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01F8;

__near __no_init volatile union
{
  unsigned short TOE1;
  __BITS16       TOE1_bit;
  struct
  {
    union
    {
      unsigned char TOE1L;
      __BITS8       TOE1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01FA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TOL1;
  __BITS16       TOL1_bit;
  struct
  {
    union
    {
      unsigned char TOL1L;
      __BITS8       TOL1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01FC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TOM1;
  __BITS16       TOM1_bit;
  struct
  {
    union
    {
      unsigned char TOM1L;
      __BITS8       TOM1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01FE;

__near __no_bit_access __no_init volatile union
{
  unsigned char MIOTRM;
  __BITS8       MIOTRM_bit;
} @ 0xF0212;

__near __no_bit_access __no_init volatile union
{
  unsigned char LIOTRM;
  __BITS8       LIOTRM_bit;
} @ 0xF0213;

__near __no_bit_access __no_init volatile union
{
  unsigned char MOSCDIV;
  __BITS8       MOSCDIV_bit;
} @ 0xF0214;

__near __no_init volatile union
{
  unsigned char WKUPMD;
  __BITS8       WKUPMD_bit;
  struct
  {
    unsigned char  FWKUP:1;
    unsigned char  :7;
  };
} @ 0xF0215;

__near __no_init volatile union
{
  unsigned char PSMCR;
  __BITS8       PSMCR_bit;
  struct
  {
    unsigned char  RAMSDS:1;
    unsigned char  RAMSDMD:1;
    unsigned char  :6;
  };
} @ 0xF0216;

__near __no_init volatile union
{
  unsigned char LVDFCLR;
  __BITS8       LVDFCLR_bit;
  struct
  {
    unsigned char  :2;
    unsigned char  DLVD0FCLR:1;
    unsigned char  DLVD1FCLR:1;
    unsigned char  :4;
  };
} @ 0xF0218;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEC;
  __BITS8       SEC_bit;
} @ 0xF0220;

__near __no_bit_access __no_init volatile union
{
  unsigned char MIN;
  __BITS8       MIN_bit;
} @ 0xF0221;

__near __no_bit_access __no_init volatile union
{
  unsigned char HOUR;
  __BITS8       HOUR_bit;
} @ 0xF0222;

__near __no_bit_access __no_init volatile union
{
  unsigned char WEEK;
  __BITS8       WEEK_bit;
} @ 0xF0223;

__near __no_bit_access __no_init volatile union
{
  unsigned char DAY;
  __BITS8       DAY_bit;
} @ 0xF0224;

__near __no_bit_access __no_init volatile union
{
  unsigned char MONTH;
  __BITS8       MONTH_bit;
} @ 0xF0225;

__near __no_bit_access __no_init volatile union
{
  unsigned char YEAR;
  __BITS8       YEAR_bit;
} @ 0xF0226;

__near __no_bit_access __no_init volatile union
{
  unsigned char SUBCUD;
  __BITS8       SUBCUD_bit;
} @ 0xF0227;

__near __no_bit_access __no_init volatile union
{
  unsigned char ALARMWM;
  __BITS8       ALARMWM_bit;
} @ 0xF0228;

__near __no_bit_access __no_init volatile union
{
  unsigned char ALARMWH;
  __BITS8       ALARMWH_bit;
} @ 0xF0229;

__near __no_bit_access __no_init volatile union
{
  unsigned char ALARMWW;
  __BITS8       ALARMWW_bit;
} @ 0xF022A;

__near __no_init volatile union
{
  unsigned char RTCC0;
  __BITS8       RTCC0_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  RTC128EN:1;
    unsigned char  RCLOE1:1;
    unsigned char  :1;
    unsigned char  RTCE:1;
  };
} @ 0xF022B;

__near __no_init volatile union
{
  unsigned char RTCC1;
  __BITS8       RTCC1_bit;
  struct
  {
    unsigned char  RWAIT:1;
    unsigned char  RWST:1;
    unsigned char  :1;
    unsigned char  RIFG:1;
    unsigned char  WAFG:1;
    unsigned char  :1;
    unsigned char  WALIE:1;
    unsigned char  WALE:1;
  };
} @ 0xF022C;

__near __no_init volatile union
{
  unsigned char IICCTL00;
  __BITS8       IICCTL00_bit;
  struct
  {
    unsigned char  SPT0:1;
    unsigned char  STT0:1;
    unsigned char  ACKE0:1;
    unsigned char  WTIM0:1;
    unsigned char  SPIE0:1;
    unsigned char  WREL0:1;
    unsigned char  LREL0:1;
    unsigned char  IICE0:1;
  };
} @ 0xF0230;

__near __no_init volatile union
{
  unsigned char IICCTL01;
  __BITS8       IICCTL01_bit;
  struct
  {
    unsigned char  PRS0:1;
    unsigned char  :1;
    unsigned char  DFC0:1;
    unsigned char  SMC0:1;
    unsigned char  DAD0:1;
    unsigned char  CLD0:1;
    unsigned char  SVADIS0:1;
    unsigned char  WUP0:1;
  };
} @ 0xF0231;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICWL0;
  __BITS8       IICWL0_bit;
} @ 0xF0232;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICWH0;
  __BITS8       IICWH0_bit;
} @ 0xF0233;

__near __no_bit_access __no_init volatile union
{
  unsigned char SVA0;
  __BITS8       SVA0_bit;
} @ 0xF0234;

__near __no_init volatile union
{
  unsigned char IICCTL10;
  __BITS8       IICCTL10_bit;
  struct
  {
    unsigned char  SPT1:1;
    unsigned char  STT1:1;
    unsigned char  ACKE1:1;
    unsigned char  WTIM1:1;
    unsigned char  SPIE1:1;
    unsigned char  WREL1:1;
    unsigned char  LREL1:1;
    unsigned char  IICE1:1;
  };
} @ 0xF0238;

__near __no_init volatile union
{
  unsigned char IICCTL11;
  __BITS8       IICCTL11_bit;
  struct
  {
    unsigned char  PRS1:1;
    unsigned char  :1;
    unsigned char  DFC1:1;
    unsigned char  SMC1:1;
    unsigned char  DAD1:1;
    unsigned char  CLD1:1;
    unsigned char  SVADIS1:1;
    unsigned char  WUP1:1;
  };
} @ 0xF0239;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICWL1;
  __BITS8       IICWL1_bit;
} @ 0xF023A;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICWH1;
  __BITS8       IICWH1_bit;
} @ 0xF023B;

__near __no_bit_access __no_init volatile union
{
  unsigned char SVA1;
  __BITS8       SVA1_bit;
} @ 0xF023C;

__near __no_init volatile union
{
  unsigned char PMCT0;
  __BITS8       PMCT0_bit;
} @ 0xF0260;

__near __no_init volatile union
{
  unsigned char PMCT2;
  __BITS8       PMCT2_bit;
} @ 0xF0262;

__near __no_init volatile union
{
  unsigned char PMCT3;
  __BITS8       PMCT3_bit;
} @ 0xF0263;

__near __no_init volatile union
{
  unsigned char PMCT5;
  __BITS8       PMCT5_bit;
} @ 0xF0265;

__near __no_init volatile union
{
  unsigned char PMCT6;
  __BITS8       PMCT6_bit;
} @ 0xF0266;

__near __no_init volatile union
{
  unsigned char PMCT7;
  __BITS8       PMCT7_bit;
} @ 0xF0267;

__near __no_init volatile union
{
  unsigned char PMCT15;
  __BITS8       PMCT15_bit;
} @ 0xF026F;

__near __no_init volatile union
{
  unsigned char PMCE0;
  __BITS8       PMCE0_bit;
} @ 0xF0280;

__near __no_init volatile union
{
  unsigned char PMCE1;
  __BITS8       PMCE1_bit;
} @ 0xF0281;

__near __no_init volatile union
{
  unsigned char PMCE5;
  __BITS8       PMCE5_bit;
} @ 0xF0285;

__near __no_init volatile union
{
  unsigned char PMCE6;
  __BITS8       PMCE6_bit;
} @ 0xF0286;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS0;
  __BITS8       CCS0_bit;
} @ 0xF02A0;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS4;
  __BITS8       CCS4_bit;
} @ 0xF02A4;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS5;
  __BITS8       CCS5_bit;
} @ 0xF02A5;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS6;
  __BITS8       CCS6_bit;
} @ 0xF02A6;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS7;
  __BITS8       CCS7_bit;
} @ 0xF02A7;

__near __no_init volatile union
{
  unsigned char CCDE;
  __BITS8       CCDE_bit;
} @ 0xF02A8;

__near __no_init volatile union
{
  unsigned char PTDC;
  __BITS8       PTDC_bit;
} @ 0xF02A9;

__near __no_init volatile union
{
  unsigned char PFOE0;
  __BITS8       PFOE0_bit;
} @ 0xF02AA;

__near __no_init volatile union
{
  unsigned char PFOE1;
  __BITS8       PFOE1_bit;
} @ 0xF02AB;

__near __no_init volatile union
{
  unsigned char PDIDIS0;
  __BITS8       PDIDIS0_bit;
} @ 0xF02B0;

__near __no_init volatile union
{
  unsigned char PDIDIS1;
  __BITS8       PDIDIS1_bit;
} @ 0xF02B1;

__near __no_init volatile union
{
  unsigned char PDIDIS3;
  __BITS8       PDIDIS3_bit;
} @ 0xF02B3;

__near __no_init volatile union
{
  unsigned char PDIDIS4;
  __BITS8       PDIDIS4_bit;
} @ 0xF02B4;

__near __no_init volatile union
{
  unsigned char PDIDIS5;
  __BITS8       PDIDIS5_bit;
} @ 0xF02B5;

__near __no_init volatile union
{
  unsigned char PDIDIS7;
  __BITS8       PDIDIS7_bit;
} @ 0xF02B7;

__near __no_init volatile union
{
  unsigned char PDIDIS8;
  __BITS8       PDIDIS8_bit;
} @ 0xF02B8;

__near __no_init volatile union
{
  unsigned char PDIDIS9;
  __BITS8       PDIDIS9_bit;
} @ 0xF02B9;

__near __no_init volatile union
{
  unsigned char PDIDIS12;
  __BITS8       PDIDIS12_bit;
} @ 0xF02BC;

__near __no_init volatile union
{
  unsigned char PDIDIS13;
  __BITS8       PDIDIS13_bit;
} @ 0xF02BD;

__near __no_init volatile union
{
  unsigned char PDIDIS14;
  __BITS8       PDIDIS14_bit;
} @ 0xF02BE;

__near __no_bit_access __no_init volatile union
{
  unsigned char FLPMC;
  __BITS8       FLPMC_bit;
} @ 0xF02C0;

__near __no_init volatile union
{
  unsigned char FLARS;
  __BITS8       FLARS_bit;
} @ 0xF02C1;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLAPL;
  __BITS16       FLAPL_bit;
} @ 0xF02C2;

__near __no_bit_access __no_init volatile union
{
  unsigned char FLAPH;
  __BITS8       FLAPH_bit;
} @ 0xF02C4;

__near __no_init volatile union
{
  unsigned char FSSQ;
  __BITS8       FSSQ_bit;
  struct
  {
    unsigned char  :6;
    unsigned char  FSSTP:1;
    unsigned char  SQST:1;
  };
} @ 0xF02C5;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLSEDL;
  __BITS16       FLSEDL_bit;
} @ 0xF02C6;

__near __no_bit_access __no_init volatile union
{
  unsigned char FLSEDH;
  __BITS8       FLSEDH_bit;
} @ 0xF02C8;

__near __no_init volatile union
{
  unsigned char FLRST;
  __BITS8       FLRST_bit;
} @ 0xF02C9;

__near __no_init volatile const union
{
  unsigned char FSASTL;
  __BITS8       FSASTL_bit;
} @ 0xF02CA;

__near __no_init volatile const union
{
  unsigned char FSASTH;
  __BITS8       FSASTH_bit;
} @ 0xF02CB;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLWL;
  __BITS16       FLWL_bit;
} @ 0xF02CC;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLWH;
  __BITS16       FLWH_bit;
} @ 0xF02CE;

__near __no_bit_access __no_init volatile union
{
  unsigned char DTCBAR;
  __BITS8       DTCBAR_bit;
} @ 0xF02E0;

__near __no_init volatile union
{
  unsigned char DTCEN0;
  __BITS8       DTCEN0_bit;
} @ 0xF02E8;

__near __no_init volatile union
{
  unsigned char DTCEN1;
  __BITS8       DTCEN1_bit;
} @ 0xF02E9;

__near __no_init volatile union
{
  unsigned char DTCEN2;
  __BITS8       DTCEN2_bit;
} @ 0xF02EA;

__near __no_init volatile union
{
  unsigned char DTCEN3;
  __BITS8       DTCEN3_bit;
} @ 0xF02EB;

__near __no_init volatile union
{
  unsigned char DTCEN4;
  __BITS8       DTCEN4_bit;
} @ 0xF02EC;

__near __no_init volatile union
{
  unsigned char CRC0CTL;
  __BITS8       CRC0CTL_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  CRC0EN:1;
  };
} @ 0xF02F0;

__near __no_bit_access __no_init volatile union
{
  unsigned short PGCRCL;
  __BITS16       PGCRCL_bit;
} @ 0xF02F2;

__near __no_bit_access __no_init volatile union
{
  unsigned short CRCD;
  __BITS16       CRCD_bit;
} @ 0xF02FA;

__near __no_bit_access __no_init volatile union
{
  unsigned char TXBA0;
  __BITS8       TXBA0_bit;
} @ 0xF0300;

__near __no_bit_access __no_init volatile const union
{
  unsigned char RXBA0;
  __BITS8       RXBA0_bit;
} @ 0xF0301;

__near __no_init volatile union
{
  unsigned char ASIMA00;
  __BITS8       ASIMA00_bit;
  struct
  {
    unsigned char  ISRMA0:1;
    unsigned char  ISSMA0:1;
    unsigned char  :3;
    unsigned char  RXEA0:1;
    unsigned char  TXEA0:1;
    unsigned char  UARTAEN0:1;
  };
} @ 0xF0302;

__near __no_init volatile union
{
  unsigned char ASIMA01;
  __BITS8       ASIMA01_bit;
} @ 0xF0303;

__near __no_bit_access __no_init volatile union
{
  unsigned char BRGCA0;
  __BITS8       BRGCA0_bit;
} @ 0xF0304;

__near __no_bit_access __no_init volatile const union
{
  unsigned char ASISA0;
  __BITS8       ASISA0_bit;
} @ 0xF0305;

__near __no_init volatile union
{
  unsigned char ASCTA0;
  __BITS8       ASCTA0_bit;
  struct
  {
    unsigned char  OVECTA0:1;
    unsigned char  FECTA0:1;
    unsigned char  PECTA0:1;
    unsigned char  :5;
  };
} @ 0xF0306;

__near __no_bit_access __no_init volatile union
{
  unsigned char TXBA1;
  __BITS8       TXBA1_bit;
} @ 0xF0308;

__near __no_bit_access __no_init volatile const union
{
  unsigned char RXBA1;
  __BITS8       RXBA1_bit;
} @ 0xF0309;

__near __no_init volatile union
{
  unsigned char ASIMA10;
  __BITS8       ASIMA10_bit;
  struct
  {
    unsigned char  ISRMA1:1;
    unsigned char  ISSMA1:1;
    unsigned char  :3;
    unsigned char  RXEA1:1;
    unsigned char  TXEA1:1;
    unsigned char  UARTAEN1:1;
  };
} @ 0xF030A;

__near __no_init volatile union
{
  unsigned char ASIMA11;
  __BITS8       ASIMA11_bit;
} @ 0xF030B;

__near __no_bit_access __no_init volatile union
{
  unsigned char BRGCA1;
  __BITS8       BRGCA1_bit;
} @ 0xF030C;

__near __no_bit_access __no_init volatile const union
{
  unsigned char ASISA1;
  __BITS8       ASISA1_bit;
} @ 0xF030D;

__near __no_init volatile union
{
  unsigned char ASCTA1;
  __BITS8       ASCTA1_bit;
  struct
  {
    unsigned char  OVECTA1:1;
    unsigned char  FECTA1:1;
    unsigned char  PECTA1:1;
    unsigned char  :5;
  };
} @ 0xF030E;

__near __no_init volatile union
{
  unsigned char UTA0CK;
  __BITS8       UTA0CK_bit;
} @ 0xF0310;

__near __no_init volatile union
{
  unsigned char UTA1CK;
  __BITS8       UTA1CK_bit;
} @ 0xF0311;

__near __no_bit_access __no_init volatile union
{
  unsigned char DACS0;
  __BITS8       DACS0_bit;
} @ 0xF0330;

__near __no_bit_access __no_init volatile union
{
  unsigned char DACS1;
  __BITS8       DACS1_bit;
} @ 0xF0331;

__near __no_init volatile union
{
  unsigned char DAM;
  __BITS8       DAM_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  DACE0:1;
    unsigned char  DACE1:1;
    unsigned char  :2;
  };
} @ 0xF0332;

__near __no_init volatile union
{
  unsigned char COMPMDR;
  __BITS8       COMPMDR_bit;
  struct
  {
    unsigned char  C0ENB:1;
    unsigned char  :3;
    unsigned char  C1ENB:1;
    unsigned char  :3;
  };
} @ 0xF0340;

__near __no_init volatile union
{
  unsigned char COMPFIR;
  __BITS8       COMPFIR_bit;
} @ 0xF0341;

__near __no_init volatile union
{
  unsigned char COMPOCR;
  __BITS8       COMPOCR_bit;
  struct
  {
    unsigned char  C0IE:1;
    unsigned char  C0OE:1;
    unsigned char  :2;
    unsigned char  C1IE:1;
    unsigned char  C1OE:1;
    unsigned char  :2;
  };
} @ 0xF0342;

__near __no_bit_access __no_init volatile union
{
  unsigned short ITLCMP00;
  __BITS16       ITLCMP00_bit;
  struct
  {
    union
    {
      unsigned char ITLCMP000;
      __BITS8       ITLCMP000_bit;
    };
    union
    {
      unsigned char ITLCMP001;
      __BITS8       ITLCMP001_bit;
    };
  };
} @ 0xF0360;

__near __no_bit_access __no_init volatile union
{
  unsigned short ITLCMP01;
  __BITS16       ITLCMP01_bit;
  struct
  {
    union
    {
      unsigned char ITLCMP012;
      __BITS8       ITLCMP012_bit;
    };
    union
    {
      unsigned char ITLCMP013;
      __BITS8       ITLCMP013_bit;
    };
  };
} @ 0xF0362;

__near __no_bit_access __no_init volatile const union
{
  unsigned short ITLCAP00;
  __BITS16       ITLCAP00_bit;
} @ 0xF0364;

__near __no_init volatile union
{
  unsigned char ITLCTL0;
  __BITS8       ITLCTL0_bit;
  struct
  {
    unsigned char  ITLEN00:1;
    unsigned char  ITLEN01:1;
    unsigned char  ITLEN02:1;
    unsigned char  ITLEN03:1;
    unsigned char  :4;
  };
} @ 0xF0366;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLCSEL0;
  __BITS8       ITLCSEL0_bit;
} @ 0xF0367;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLFDIV00;
  __BITS8       ITLFDIV00_bit;
} @ 0xF0368;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLFDIV01;
  __BITS8       ITLFDIV01_bit;
} @ 0xF0369;

__near __no_init volatile union
{
  unsigned char ITLCC0;
  __BITS8       ITLCC0_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  CAPR0:1;
    unsigned char  :1;
    unsigned char  CAPF0CR:1;
    unsigned char  :1;
  };
} @ 0xF036A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLS0;
  __BITS8       ITLS0_bit;
} @ 0xF036B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLMKF0;
  __BITS8       ITLMKF0_bit;
} @ 0xF036C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI0;
  __BITS16       SMSI0_bit;
} @ 0xF0380;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI1;
  __BITS16       SMSI1_bit;
} @ 0xF0382;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI2;
  __BITS16       SMSI2_bit;
} @ 0xF0384;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI3;
  __BITS16       SMSI3_bit;
} @ 0xF0386;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI4;
  __BITS16       SMSI4_bit;
} @ 0xF0388;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI5;
  __BITS16       SMSI5_bit;
} @ 0xF038A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI6;
  __BITS16       SMSI6_bit;
} @ 0xF038C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI7;
  __BITS16       SMSI7_bit;
} @ 0xF038E;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI8;
  __BITS16       SMSI8_bit;
} @ 0xF0390;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI9;
  __BITS16       SMSI9_bit;
} @ 0xF0392;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI10;
  __BITS16       SMSI10_bit;
} @ 0xF0394;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI11;
  __BITS16       SMSI11_bit;
} @ 0xF0396;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI12;
  __BITS16       SMSI12_bit;
} @ 0xF0398;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI13;
  __BITS16       SMSI13_bit;
} @ 0xF039A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI14;
  __BITS16       SMSI14_bit;
} @ 0xF039C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI15;
  __BITS16       SMSI15_bit;
} @ 0xF039E;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI16;
  __BITS16       SMSI16_bit;
} @ 0xF03A0;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI17;
  __BITS16       SMSI17_bit;
} @ 0xF03A2;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI18;
  __BITS16       SMSI18_bit;
} @ 0xF03A4;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI19;
  __BITS16       SMSI19_bit;
} @ 0xF03A6;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI20;
  __BITS16       SMSI20_bit;
} @ 0xF03A8;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI21;
  __BITS16       SMSI21_bit;
} @ 0xF03AA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI22;
  __BITS16       SMSI22_bit;
} @ 0xF03AC;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI23;
  __BITS16       SMSI23_bit;
} @ 0xF03AE;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI24;
  __BITS16       SMSI24_bit;
} @ 0xF03B0;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI25;
  __BITS16       SMSI25_bit;
} @ 0xF03B2;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI26;
  __BITS16       SMSI26_bit;
} @ 0xF03B4;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI27;
  __BITS16       SMSI27_bit;
} @ 0xF03B6;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI28;
  __BITS16       SMSI28_bit;
} @ 0xF03B8;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI29;
  __BITS16       SMSI29_bit;
} @ 0xF03BA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI30;
  __BITS16       SMSI30_bit;
} @ 0xF03BC;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI31;
  __BITS16       SMSI31_bit;
} @ 0xF03BE;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SMSG0;
  __BITS16       SMSG0_bit;
} @ 0xF03C0;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG1;
  __BITS16       SMSG1_bit;
} @ 0xF03C2;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG2;
  __BITS16       SMSG2_bit;
} @ 0xF03C4;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG3;
  __BITS16       SMSG3_bit;
} @ 0xF03C6;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG4;
  __BITS16       SMSG4_bit;
} @ 0xF03C8;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG5;
  __BITS16       SMSG5_bit;
} @ 0xF03CA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG6;
  __BITS16       SMSG6_bit;
} @ 0xF03CC;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG7;
  __BITS16       SMSG7_bit;
} @ 0xF03CE;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG8;
  __BITS16       SMSG8_bit;
} @ 0xF03D0;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG9;
  __BITS16       SMSG9_bit;
} @ 0xF03D2;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG10;
  __BITS16       SMSG10_bit;
} @ 0xF03D4;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG11;
  __BITS16       SMSG11_bit;
} @ 0xF03D6;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG12;
  __BITS16       SMSG12_bit;
} @ 0xF03D8;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG13;
  __BITS16       SMSG13_bit;
} @ 0xF03DA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG14;
  __BITS16       SMSG14_bit;
} @ 0xF03DC;

__near __no_bit_access __no_init volatile const union
{
  unsigned short SMSG15;
  __BITS16       SMSG15_bit;
} @ 0xF03DE;

__near __no_init volatile union
{
  unsigned char SMSC;
  __BITS8       SMSC_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  LONGWAIT:1;
    unsigned char  SMSTRGWAIT:1;
    unsigned char  SMSSTOP:1;
    unsigned char  SMSSTART:1;
  };
} @ 0xF03E0;

__near __no_init volatile const union
{
  unsigned char SMSS;
  __BITS8       SMSS_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  SMSSTAT:1;
  };
} @ 0xF03E1;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLSIVC0;
  __BITS16       FLSIVC0_bit;
} @ 0xF0480;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLSIVC1;
  __BITS16       FLSIVC1_bit;
} @ 0xF0482;

__near __no_bit_access __no_init volatile union
{
  unsigned short GFLASH0;
  __BITS16       GFLASH0_bit;
} @ 0xF0488;

__near __no_bit_access __no_init volatile union
{
  unsigned short GFLASH1;
  __BITS16       GFLASH1_bit;
} @ 0xF048A;

__near __no_bit_access __no_init volatile union
{
  unsigned short GFLASH2;
  __BITS16       GFLASH2_bit;
} @ 0xF048C;

__near __no_bit_access __no_init volatile union
{
  unsigned short GIAWCTL;
  __BITS16       GIAWCTL_bit;
} @ 0xF048E;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCRAL;
  __BITS16       CTSUCRAL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCR0;
      __BITS8       CTSUCR0_bit;
    };
    union
    {
      unsigned char CTSUCR1;
      __BITS8       CTSUCR1_bit;
    };
  };
} @ 0xF0500;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCRAH;
  __BITS16       CTSUCRAH_bit;
  struct
  {
    union
    {
      unsigned char CTSUCR2;
      __BITS8       CTSUCR2_bit;
    };
    union
    {
      unsigned char CTSUCR3;
      __BITS8       CTSUCR3_bit;
    };
  };
} @ 0xF0502;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCRBL;
  __BITS16       CTSUCRBL_bit;
  struct
  {
    union
    {
      unsigned char CTSUSDPRS;
      __BITS8       CTSUSDPRS_bit;
    };
    union
    {
      unsigned char CTSUSST;
      __BITS8       CTSUSST_bit;
    };
  };
} @ 0xF0504;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCRBH;
  __BITS16       CTSUCRBH_bit;
  struct
  {
    unsigned char :8;
    union
    {
      unsigned char CTSUDCLKC;
      __BITS8       CTSUDCLKC_bit;
    };
  };
} @ 0xF0506;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUMCHL;
  __BITS16       CTSUMCHL_bit;
  struct
  {
    union
    {
      unsigned char CTSUMCH0;
      __BITS8       CTSUMCH0_bit;
    };
    union
    {
      unsigned char CTSUMCH1;
      __BITS8       CTSUMCH1_bit;
    };
  };
} @ 0xF0508;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUMCHH;
  __BITS16       CTSUMCHH_bit;
  struct
  {
    union
    {
      unsigned char CTSUMFAF;
      __BITS8       CTSUMFAF_bit;
    };
    unsigned char :8;
  };
} @ 0xF050A;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCHACAL;
  __BITS16       CTSUCHACAL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHAC0;
      __BITS8       CTSUCHAC0_bit;
    };
    union
    {
      unsigned char CTSUCHAC1;
      __BITS8       CTSUCHAC1_bit;
    };
  };
} @ 0xF050C;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCHACAH;
  __BITS16       CTSUCHACAH_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHAC2;
      __BITS8       CTSUCHAC2_bit;
    };
    union
    {
      unsigned char CTSUCHAC3;
      __BITS8       CTSUCHAC3_bit;
    };
  };
} @ 0xF050E;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCHACBL;
  __BITS16       CTSUCHACBL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHAC4;
      __BITS8       CTSUCHAC4_bit;
    };
    union
    {
      unsigned char CTSUCHAC5;
      __BITS8       CTSUCHAC5_bit;
    };
  };
} @ 0xF0510;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCHACBH;
  __BITS16       CTSUCHACBH_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHAC6;
      __BITS8       CTSUCHAC6_bit;
    };
    union
    {
      unsigned char CTSUCHAC7;
      __BITS8       CTSUCHAC7_bit;
    };
  };
} @ 0xF0512;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCHTRCAL;
  __BITS16       CTSUCHTRCAL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHTRC0;
      __BITS8       CTSUCHTRC0_bit;
    };
    union
    {
      unsigned char CTSUCHTRC1;
      __BITS8       CTSUCHTRC1_bit;
    };
  };
} @ 0xF0514;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCHTRCAH;
  __BITS16       CTSUCHTRCAH_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHTRC2;
      __BITS8       CTSUCHTRC2_bit;
    };
    union
    {
      unsigned char CTSUCHTRC3;
      __BITS8       CTSUCHTRC3_bit;
    };
  };
} @ 0xF0516;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCHTRCBL;
  __BITS16       CTSUCHTRCBL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHTRC4;
      __BITS8       CTSUCHTRC4_bit;
    };
    union
    {
      unsigned char CTSUCHTRC5;
      __BITS8       CTSUCHTRC5_bit;
    };
  };
} @ 0xF0518;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCHTRCBH;
  __BITS16       CTSUCHTRCBH_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHTRC6;
      __BITS8       CTSUCHTRC6_bit;
    };
    union
    {
      unsigned char CTSUCHTRC7;
      __BITS8       CTSUCHTRC7_bit;
    };
  };
} @ 0xF051A;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSRL;
  __BITS16       CTSUSRL_bit;
  struct
  {
    union
    {
      unsigned char CTSUST1;
      __BITS8       CTSUST1_bit;
    };
    union
    {
      unsigned char CTSUST;
      __BITS8       CTSUST_bit;
    };
  };
} @ 0xF051C;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSRH;
  __BITS16       CTSUSRH_bit;
  struct
  {
    union
    {
      unsigned char CTSUST2;
      __BITS8       CTSUST2_bit;
    };
    unsigned char :8;
  };
} @ 0xF051E;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSO0;
  __BITS16       CTSUSO0_bit;
} @ 0xF0520;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSO1;
  __BITS16       CTSUSO1_bit;
} @ 0xF0522;

__near __no_bit_access __no_init volatile const union
{
  unsigned short CTSUSC;
  __BITS16       CTSUSC_bit;
} @ 0xF0524;

__near __no_bit_access __no_init volatile const union
{
  unsigned short CTSUUC;
  __BITS16       CTSUUC_bit;
} @ 0xF0526;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUDBGR0;
  __BITS16       CTSUDBGR0_bit;
} @ 0xF0528;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUDBGR1;
  __BITS16       CTSUDBGR1_bit;
} @ 0xF052A;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSUCLK0;
  __BITS16       CTSUSUCLK0_bit;
} @ 0xF052C;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSUCLK1;
  __BITS16       CTSUSUCLK1_bit;
} @ 0xF052E;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSUCLK2;
  __BITS16       CTSUSUCLK2_bit;
} @ 0xF0530;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSUCLK3;
  __BITS16       CTSUSUCLK3_bit;
} @ 0xF0532;

__near __no_bit_access __no_init volatile const union
{
  unsigned char TRNGSDR;
  __BITS8       TRNGSDR_bit;
} @ 0xF0540;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRNGSCR0;
  __BITS8       TRNGSCR0_bit;
} @ 0xF0542;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUTRIM0;
  __BITS16       CTSUTRIM0_bit;
  struct
  {
    union
    {
      unsigned char RTRIM;
      __BITS8       RTRIM_bit;
    };
    union
    {
      unsigned char DACTRIM;
      __BITS8       DACTRIM_bit;
    };
  };
} @ 0xF0600;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUTRIM1;
  __BITS16       CTSUTRIM1_bit;
  struct
  {
    union
    {
      unsigned char SUADJD;
      __BITS8       SUADJD_bit;
    };
    union
    {
      unsigned char TRESULT4;
      __BITS8       TRESULT4_bit;
    };
  };
} @ 0xF0602;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUTRIM2;
  __BITS16       CTSUTRIM2_bit;
  struct
  {
    union
    {
      unsigned char TRESULT0;
      __BITS8       TRESULT0_bit;
    };
    union
    {
      unsigned char TRESULT1;
      __BITS8       TRESULT1_bit;
    };
  };
} @ 0xF0604;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUTRIM3;
  __BITS16       CTSUTRIM3_bit;
  struct
  {
    union
    {
      unsigned char TRESULT2;
      __BITS8       TRESULT2_bit;
    };
    union
    {
      unsigned char TRESULT3;
      __BITS8       TRESULT3_bit;
    };
  };
} @ 0xF0606;

__near __no_init volatile union
{
  unsigned char REMCON0;
  __BITS8       REMCON0_bit;
  struct
  {
    unsigned char  ENFLG:1;
    unsigned char  :2;
    unsigned char  INFLG:1;
    unsigned char  :4;
  };
} @ 0xF0640;

__near __no_init volatile union
{
  unsigned char REMCON1;
  __BITS8       REMCON1_bit;
  struct
  {
    unsigned char  :2;
    unsigned char  EN:1;
    unsigned char  INTMD:1;
    unsigned char  :4;
  };
} @ 0xF0641;

__near __no_init volatile union
{
  unsigned char REMSTS;
  __BITS8       REMSTS_bit;
  struct
  {
    unsigned char  CPFLG:1;
    unsigned char  REFLG:1;
    unsigned char  DRFLG:1;
    unsigned char  BFULFLG:1;
    unsigned char  HDFLG:1;
    unsigned char  D0FLG:1;
    unsigned char  D1FLG:1;
    unsigned char  SDFLG:1;
  };
} @ 0xF0642;

__near __no_init volatile union
{
  unsigned char REMINT;
  __BITS8       REMINT_bit;
  struct
  {
    unsigned char  CPINT:1;
    unsigned char  REINT:1;
    unsigned char  DRINT:1;
    unsigned char  BFULINT:1;
    unsigned char  HDINT:1;
    unsigned char  DINT:1;
    unsigned char  :1;
    unsigned char  SDINT:1;
  };
} @ 0xF0643;

__near __no_bit_access __no_init volatile union
{
  unsigned char REMCPC;
  __BITS8       REMCPC_bit;
} @ 0xF0645;

__near __no_bit_access __no_init volatile union
{
  unsigned short REMCPD;
  __BITS16       REMCPD_bit;
} @ 0xF0646;

__near __no_bit_access __no_init volatile union
{
  unsigned short HDPMIN;
  __BITS16       HDPMIN_bit;
} @ 0xF0648;

__near __no_bit_access __no_init volatile union
{
  unsigned short HDPMAX;
  __BITS16       HDPMAX_bit;
} @ 0xF064A;

__near __no_bit_access __no_init volatile union
{
  unsigned char D0PMIN;
  __BITS8       D0PMIN_bit;
} @ 0xF064C;

__near __no_bit_access __no_init volatile union
{
  unsigned char D0PMAX;
  __BITS8       D0PMAX_bit;
} @ 0xF064D;

__near __no_bit_access __no_init volatile union
{
  unsigned char D1PMIN;
  __BITS8       D1PMIN_bit;
} @ 0xF064E;

__near __no_bit_access __no_init volatile union
{
  unsigned char D1PMAX;
  __BITS8       D1PMAX_bit;
} @ 0xF064F;

__near __no_bit_access __no_init volatile union
{
  unsigned short SDPMIN;
  __BITS16       SDPMIN_bit;
} @ 0xF0650;

__near __no_bit_access __no_init volatile union
{
  unsigned short SDPMAX;
  __BITS16       SDPMAX_bit;
} @ 0xF0652;

__near __no_bit_access __no_init volatile union
{
  unsigned short REMPE;
  __BITS16       REMPE_bit;
} @ 0xF0654;

__near __no_init volatile union
{
  unsigned char REMSTC;
  __BITS8       REMSTC_bit;
  struct
  {
    unsigned char  SNZON:1;
    unsigned char  :7;
  };
} @ 0xF0656;

__near __no_init volatile union
{
  unsigned char REMRBIT;
  __BITS8       REMRBIT_bit;
  struct
  {
    unsigned char  RBIT0:1;
    unsigned char  :7;
  };
} @ 0xF0657;

__near __no_init volatile union
{
  unsigned char REMDAT0;
  __BITS8       REMDAT0_bit;
  struct
  {
    unsigned char  DAT00:1;
    unsigned char  :7;
  };
} @ 0xF0658;

__near __no_bit_access __no_init volatile const union
{
  unsigned char REMDAT1;
  __BITS8       REMDAT1_bit;
} @ 0xF0659;

__near __no_bit_access __no_init volatile const union
{
  unsigned char REMDAT2;
  __BITS8       REMDAT2_bit;
} @ 0xF065A;

__near __no_bit_access __no_init volatile const union
{
  unsigned char REMDAT3;
  __BITS8       REMDAT3_bit;
} @ 0xF065B;

__near __no_bit_access __no_init volatile const union
{
  unsigned char REMDAT4;
  __BITS8       REMDAT4_bit;
} @ 0xF065C;

__near __no_bit_access __no_init volatile const union
{
  unsigned char REMDAT5;
  __BITS8       REMDAT5_bit;
} @ 0xF065D;

__near __no_bit_access __no_init volatile const union
{
  unsigned char REMDAT6;
  __BITS8       REMDAT6_bit;
} @ 0xF065E;

__near __no_bit_access __no_init volatile const union
{
  unsigned char REMDAT7;
  __BITS8       REMDAT7_bit;
} @ 0xF065F;

__near __no_bit_access __no_init volatile const union
{
  unsigned short REMTIM;
  __BITS16       REMTIM_bit;
} @ 0xF0660;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL0;
  __BITS8       ELISEL0_bit;
} @ 0xF0680;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL1;
  __BITS8       ELISEL1_bit;
} @ 0xF0681;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL2;
  __BITS8       ELISEL2_bit;
} @ 0xF0682;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL3;
  __BITS8       ELISEL3_bit;
} @ 0xF0683;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL4;
  __BITS8       ELISEL4_bit;
} @ 0xF0684;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL5;
  __BITS8       ELISEL5_bit;
} @ 0xF0685;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL6;
  __BITS8       ELISEL6_bit;
} @ 0xF0686;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL7;
  __BITS8       ELISEL7_bit;
} @ 0xF0687;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL8;
  __BITS8       ELISEL8_bit;
} @ 0xF0688;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL9;
  __BITS8       ELISEL9_bit;
} @ 0xF0689;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL10;
  __BITS8       ELISEL10_bit;
} @ 0xF068A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL11;
  __BITS8       ELISEL11_bit;
} @ 0xF068B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL0;
  __BITS8       ELL1SEL0_bit;
} @ 0xF0690;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL1;
  __BITS8       ELL1SEL1_bit;
} @ 0xF0691;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL2;
  __BITS8       ELL1SEL2_bit;
} @ 0xF0692;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL3;
  __BITS8       ELL1SEL3_bit;
} @ 0xF0693;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL4;
  __BITS8       ELL1SEL4_bit;
} @ 0xF0694;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL5;
  __BITS8       ELL1SEL5_bit;
} @ 0xF0695;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL6;
  __BITS8       ELL1SEL6_bit;
} @ 0xF0696;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1CTL;
  __BITS8       ELL1CTL_bit;
} @ 0xF0697;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK0;
  __BITS8       ELL1LNK0_bit;
} @ 0xF0698;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK1;
  __BITS8       ELL1LNK1_bit;
} @ 0xF0699;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK2;
  __BITS8       ELL1LNK2_bit;
} @ 0xF069A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK3;
  __BITS8       ELL1LNK3_bit;
} @ 0xF069B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK4;
  __BITS8       ELL1LNK4_bit;
} @ 0xF069C;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK5;
  __BITS8       ELL1LNK5_bit;
} @ 0xF069D;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK6;
  __BITS8       ELL1LNK6_bit;
} @ 0xF069E;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL0;
  __BITS8       ELL2SEL0_bit;
} @ 0xF06A0;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL1;
  __BITS8       ELL2SEL1_bit;
} @ 0xF06A1;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL2;
  __BITS8       ELL2SEL2_bit;
} @ 0xF06A2;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL3;
  __BITS8       ELL2SEL3_bit;
} @ 0xF06A3;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL4;
  __BITS8       ELL2SEL4_bit;
} @ 0xF06A4;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL5;
  __BITS8       ELL2SEL5_bit;
} @ 0xF06A5;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL6;
  __BITS8       ELL2SEL6_bit;
} @ 0xF06A6;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2CTL;
  __BITS8       ELL2CTL_bit;
} @ 0xF06A7;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK0;
  __BITS8       ELL2LNK0_bit;
} @ 0xF06A8;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK1;
  __BITS8       ELL2LNK1_bit;
} @ 0xF06A9;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK2;
  __BITS8       ELL2LNK2_bit;
} @ 0xF06AA;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK3;
  __BITS8       ELL2LNK3_bit;
} @ 0xF06AB;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK4;
  __BITS8       ELL2LNK4_bit;
} @ 0xF06AC;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK5;
  __BITS8       ELL2LNK5_bit;
} @ 0xF06AD;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK6;
  __BITS8       ELL2LNK6_bit;
} @ 0xF06AE;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL0;
  __BITS8       ELL3SEL0_bit;
} @ 0xF06B0;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL1;
  __BITS8       ELL3SEL1_bit;
} @ 0xF06B1;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL2;
  __BITS8       ELL3SEL2_bit;
} @ 0xF06B2;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL3;
  __BITS8       ELL3SEL3_bit;
} @ 0xF06B3;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL4;
  __BITS8       ELL3SEL4_bit;
} @ 0xF06B4;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL5;
  __BITS8       ELL3SEL5_bit;
} @ 0xF06B5;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL6;
  __BITS8       ELL3SEL6_bit;
} @ 0xF06B6;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3CTL;
  __BITS8       ELL3CTL_bit;
} @ 0xF06B7;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK0;
  __BITS8       ELL3LNK0_bit;
} @ 0xF06B8;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK1;
  __BITS8       ELL3LNK1_bit;
} @ 0xF06B9;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK2;
  __BITS8       ELL3LNK2_bit;
} @ 0xF06BA;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK3;
  __BITS8       ELL3LNK3_bit;
} @ 0xF06BB;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK4;
  __BITS8       ELL3LNK4_bit;
} @ 0xF06BC;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK5;
  __BITS8       ELL3LNK5_bit;
} @ 0xF06BD;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK6;
  __BITS8       ELL3LNK6_bit;
} @ 0xF06BE;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL0;
  __BITS8       ELOSEL0_bit;
} @ 0xF06C0;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL1;
  __BITS8       ELOSEL1_bit;
} @ 0xF06C1;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL2;
  __BITS8       ELOSEL2_bit;
} @ 0xF06C2;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL3;
  __BITS8       ELOSEL3_bit;
} @ 0xF06C3;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL4;
  __BITS8       ELOSEL4_bit;
} @ 0xF06C4;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL5;
  __BITS8       ELOSEL5_bit;
} @ 0xF06C5;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL6;
  __BITS8       ELOSEL6_bit;
} @ 0xF06C6;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL7;
  __BITS8       ELOSEL7_bit;
} @ 0xF06C7;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOENCTL;
  __BITS8       ELOENCTL_bit;
} @ 0xF06C8;

__near __no_bit_access __no_init volatile const union
{
  unsigned char ELOMONI;
  __BITS8       ELOMONI_bit;
} @ 0xF06C9;


#pragma language=restore

#endif /* __IAR_SYSTEMS_ICC__ */

#ifdef __IAR_SYSTEMS_ASM__

/*----------------------------------------------
 *       Extended SFR declarations
 *--------------------------------------------*/

ADM2       DEFINE  0xF0010
ADUL       DEFINE  0xF0011
ADLL       DEFINE  0xF0012
ADTES      DEFINE  0xF0013
ADCR0      DEFINE  0xF0020
ADCR0H     DEFINE  0xF0021
ADCR1      DEFINE  0xF0022
ADCR1H     DEFINE  0xF0023
ADCR2      DEFINE  0xF0024
ADCR2H     DEFINE  0xF0025
ADCR3      DEFINE  0xF0026
ADCR3H     DEFINE  0xF0027
PU0        DEFINE  0xF0030
PU1        DEFINE  0xF0031
PU3        DEFINE  0xF0033
PU4        DEFINE  0xF0034
PU5        DEFINE  0xF0035
PU6        DEFINE  0xF0036
PU7        DEFINE  0xF0037
PU8        DEFINE  0xF0038
PU9        DEFINE  0xF0039
PU10       DEFINE  0xF003A
PU11       DEFINE  0xF003B
PU12       DEFINE  0xF003C
PU14       DEFINE  0xF003E
PIM0       DEFINE  0xF0040
PIM1       DEFINE  0xF0041
PIM3       DEFINE  0xF0043
PIM4       DEFINE  0xF0044
PIM5       DEFINE  0xF0045
PIM7       DEFINE  0xF0047
PIM8       DEFINE  0xF0048
PIM14      DEFINE  0xF004E
POM0       DEFINE  0xF0050
POM1       DEFINE  0xF0051
POM3       DEFINE  0xF0053
POM4       DEFINE  0xF0054
POM5       DEFINE  0xF0055
POM7       DEFINE  0xF0057
POM8       DEFINE  0xF0058
POM9       DEFINE  0xF0059
POM12      DEFINE  0xF005C
POM14      DEFINE  0xF005E
PMCA0      DEFINE  0xF0060
PMCA1      DEFINE  0xF0061
PMCA2      DEFINE  0xF0062
PMCA3      DEFINE  0xF0063
PMCA10     DEFINE  0xF006A
PMCA11     DEFINE  0xF006B
PMCA12     DEFINE  0xF006C
PMCA14     DEFINE  0xF006E
PMCA15     DEFINE  0xF006F
NFEN0      DEFINE  0xF0070
NFEN1      DEFINE  0xF0071
NFEN2      DEFINE  0xF0072
ISC        DEFINE  0xF0073
TIS0       DEFINE  0xF0074
TIS1       DEFINE  0xF0075
PIOR       DEFINE  0xF0077
IAWCTL     DEFINE  0xF0078
ULBS       DEFINE  0xF0079
PMS        DEFINE  0xF007B
GDIDIS     DEFINE  0xF007D
DFLCTL     DEFINE  0xF0090
HIOTRM     DEFINE  0xF00A0
HOCODIV    DEFINE  0xF00A8
FLMODE     DEFINE  0xF00AA
FLMWRP     DEFINE  0xF00AB
FLSEC      DEFINE  0xF00B0
FLFSWS     DEFINE  0xF00B2
FLFSWE     DEFINE  0xF00B4
FSSET      DEFINE  0xF00B6
FSSE       DEFINE  0xF00B7
FLFADL     DEFINE  0xF00B8
FLFADH     DEFINE  0xF00BA
PFCMD      DEFINE  0xF00C0
PFS        DEFINE  0xF00C1
FLWE       DEFINE  0xF00C6
PER0       DEFINE  0xF00F0
PRR0       DEFINE  0xF00F1
MOCODIV    DEFINE  0xF00F2
OSMC       DEFINE  0xF00F3
RPECTL     DEFINE  0xF00F5
PORSR      DEFINE  0xF00F9
PER1       DEFINE  0xF00FA
PRR1       DEFINE  0xF00FB
BCDADJ     DEFINE  0xF00FE
VECTCTRL   DEFINE  0xF00FF
SSR00      DEFINE  0xF0100
SSR00L     DEFINE  0xF0100
SSR01      DEFINE  0xF0102
SSR01L     DEFINE  0xF0102
SSR02      DEFINE  0xF0104
SSR02L     DEFINE  0xF0104
SSR03      DEFINE  0xF0106
SSR03L     DEFINE  0xF0106
SIR00      DEFINE  0xF0108
SIR00L     DEFINE  0xF0108
SIR01      DEFINE  0xF010A
SIR01L     DEFINE  0xF010A
SIR02      DEFINE  0xF010C
SIR02L     DEFINE  0xF010C
SIR03      DEFINE  0xF010E
SIR03L     DEFINE  0xF010E
SMR00      DEFINE  0xF0110
SMR01      DEFINE  0xF0112
SMR02      DEFINE  0xF0114
SMR03      DEFINE  0xF0116
SCR00      DEFINE  0xF0118
SCR01      DEFINE  0xF011A
SCR02      DEFINE  0xF011C
SCR03      DEFINE  0xF011E
SE0        DEFINE  0xF0120
SE0L       DEFINE  0xF0120
SS0        DEFINE  0xF0122
SS0L       DEFINE  0xF0122
ST0        DEFINE  0xF0124
ST0L       DEFINE  0xF0124
SPS0       DEFINE  0xF0126
SPS0L      DEFINE  0xF0126
SO0        DEFINE  0xF0128
SOE0       DEFINE  0xF012A
SOE0L      DEFINE  0xF012A
SOL0       DEFINE  0xF0134
SOL0L      DEFINE  0xF0134
SSC0       DEFINE  0xF0138
SSC0L      DEFINE  0xF0138
SSR10      DEFINE  0xF0140
SSR10L     DEFINE  0xF0140
SSR11      DEFINE  0xF0142
SSR11L     DEFINE  0xF0142
SSR12      DEFINE  0xF0144
SSR12L     DEFINE  0xF0144
SSR13      DEFINE  0xF0146
SSR13L     DEFINE  0xF0146
SIR10      DEFINE  0xF0148
SIR10L     DEFINE  0xF0148
SIR11      DEFINE  0xF014A
SIR11L     DEFINE  0xF014A
SIR12      DEFINE  0xF014C
SIR12L     DEFINE  0xF014C
SIR13      DEFINE  0xF014E
SIR13L     DEFINE  0xF014E
SMR10      DEFINE  0xF0150
SMR11      DEFINE  0xF0152
SMR12      DEFINE  0xF0154
SMR13      DEFINE  0xF0156
SCR10      DEFINE  0xF0158
SCR11      DEFINE  0xF015A
SCR12      DEFINE  0xF015C
SCR13      DEFINE  0xF015E
SE1        DEFINE  0xF0160
SE1L       DEFINE  0xF0160
SS1        DEFINE  0xF0162
SS1L       DEFINE  0xF0162
ST1        DEFINE  0xF0164
ST1L       DEFINE  0xF0164
SPS1       DEFINE  0xF0166
SPS1L      DEFINE  0xF0166
SO1        DEFINE  0xF0168
SOE1       DEFINE  0xF016A
SOE1L      DEFINE  0xF016A
SOL1       DEFINE  0xF0174
SOL1L      DEFINE  0xF0174
SSC1       DEFINE  0xF0178
SSC1L      DEFINE  0xF0178
TCR00      DEFINE  0xF0180
TCR01      DEFINE  0xF0182
TCR02      DEFINE  0xF0184
TCR03      DEFINE  0xF0186
TCR04      DEFINE  0xF0188
TCR05      DEFINE  0xF018A
TCR06      DEFINE  0xF018C
TCR07      DEFINE  0xF018E
TMR00      DEFINE  0xF0190
TMR01      DEFINE  0xF0192
TMR02      DEFINE  0xF0194
TMR03      DEFINE  0xF0196
TMR04      DEFINE  0xF0198
TMR05      DEFINE  0xF019A
TMR06      DEFINE  0xF019C
TMR07      DEFINE  0xF019E
TSR00      DEFINE  0xF01A0
TSR00L     DEFINE  0xF01A0
TSR01      DEFINE  0xF01A2
TSR01L     DEFINE  0xF01A2
TSR02      DEFINE  0xF01A4
TSR02L     DEFINE  0xF01A4
TSR03      DEFINE  0xF01A6
TSR03L     DEFINE  0xF01A6
TSR04      DEFINE  0xF01A8
TSR04L     DEFINE  0xF01A8
TSR05      DEFINE  0xF01AA
TSR05L     DEFINE  0xF01AA
TSR06      DEFINE  0xF01AC
TSR06L     DEFINE  0xF01AC
TSR07      DEFINE  0xF01AE
TSR07L     DEFINE  0xF01AE
TE0        DEFINE  0xF01B0
TE0L       DEFINE  0xF01B0
TS0        DEFINE  0xF01B2
TS0L       DEFINE  0xF01B2
TT0        DEFINE  0xF01B4
TT0L       DEFINE  0xF01B4
TPS0       DEFINE  0xF01B6
TO0        DEFINE  0xF01B8
TO0L       DEFINE  0xF01B8
TOE0       DEFINE  0xF01BA
TOE0L      DEFINE  0xF01BA
TOL0       DEFINE  0xF01BC
TOL0L      DEFINE  0xF01BC
TOM0       DEFINE  0xF01BE
TOM0L      DEFINE  0xF01BE
TCR10      DEFINE  0xF01C0
TCR11      DEFINE  0xF01C2
TCR12      DEFINE  0xF01C4
TCR13      DEFINE  0xF01C6
TCR14      DEFINE  0xF01C8
TCR15      DEFINE  0xF01CA
TCR16      DEFINE  0xF01CC
TCR17      DEFINE  0xF01CE
TMR10      DEFINE  0xF01D0
TMR11      DEFINE  0xF01D2
TMR12      DEFINE  0xF01D4
TMR13      DEFINE  0xF01D6
TMR14      DEFINE  0xF01D8
TMR15      DEFINE  0xF01DA
TMR16      DEFINE  0xF01DC
TMR17      DEFINE  0xF01DE
TSR10      DEFINE  0xF01E0
TSR10L     DEFINE  0xF01E0
TSR11      DEFINE  0xF01E2
TSR11L     DEFINE  0xF01E2
TSR12      DEFINE  0xF01E4
TSR12L     DEFINE  0xF01E4
TSR13      DEFINE  0xF01E6
TSR13L     DEFINE  0xF01E6
TSR14      DEFINE  0xF01E8
TSR14L     DEFINE  0xF01E8
TSR15      DEFINE  0xF01EA
TSR15L     DEFINE  0xF01EA
TSR16      DEFINE  0xF01EC
TSR16L     DEFINE  0xF01EC
TSR17      DEFINE  0xF01EE
TSR17L     DEFINE  0xF01EE
TE1        DEFINE  0xF01F0
TE1L       DEFINE  0xF01F0
TS1        DEFINE  0xF01F2
TS1L       DEFINE  0xF01F2
TT1        DEFINE  0xF01F4
TT1L       DEFINE  0xF01F4
TPS1       DEFINE  0xF01F6
TO1        DEFINE  0xF01F8
TO1L       DEFINE  0xF01F8
TOE1       DEFINE  0xF01FA
TOE1L      DEFINE  0xF01FA
TOL1       DEFINE  0xF01FC
TOL1L      DEFINE  0xF01FC
TOM1       DEFINE  0xF01FE
TOM1L      DEFINE  0xF01FE
MIOTRM     DEFINE  0xF0212
LIOTRM     DEFINE  0xF0213
MOSCDIV    DEFINE  0xF0214
WKUPMD     DEFINE  0xF0215
PSMCR      DEFINE  0xF0216
LVDFCLR    DEFINE  0xF0218
SEC        DEFINE  0xF0220
MIN        DEFINE  0xF0221
HOUR       DEFINE  0xF0222
WEEK       DEFINE  0xF0223
DAY        DEFINE  0xF0224
MONTH      DEFINE  0xF0225
YEAR       DEFINE  0xF0226
SUBCUD     DEFINE  0xF0227
ALARMWM    DEFINE  0xF0228
ALARMWH    DEFINE  0xF0229
ALARMWW    DEFINE  0xF022A
RTCC0      DEFINE  0xF022B
RTCC1      DEFINE  0xF022C
IICCTL00   DEFINE  0xF0230
IICCTL01   DEFINE  0xF0231
IICWL0     DEFINE  0xF0232
IICWH0     DEFINE  0xF0233
SVA0       DEFINE  0xF0234
IICCTL10   DEFINE  0xF0238
IICCTL11   DEFINE  0xF0239
IICWL1     DEFINE  0xF023A
IICWH1     DEFINE  0xF023B
SVA1       DEFINE  0xF023C
PMCT0      DEFINE  0xF0260
PMCT2      DEFINE  0xF0262
PMCT3      DEFINE  0xF0263
PMCT5      DEFINE  0xF0265
PMCT6      DEFINE  0xF0266
PMCT7      DEFINE  0xF0267
PMCT15     DEFINE  0xF026F
PMCE0      DEFINE  0xF0280
PMCE1      DEFINE  0xF0281
PMCE5      DEFINE  0xF0285
PMCE6      DEFINE  0xF0286
CCS0       DEFINE  0xF02A0
CCS4       DEFINE  0xF02A4
CCS5       DEFINE  0xF02A5
CCS6       DEFINE  0xF02A6
CCS7       DEFINE  0xF02A7
CCDE       DEFINE  0xF02A8
PTDC       DEFINE  0xF02A9
PFOE0      DEFINE  0xF02AA
PFOE1      DEFINE  0xF02AB
PDIDIS0    DEFINE  0xF02B0
PDIDIS1    DEFINE  0xF02B1
PDIDIS3    DEFINE  0xF02B3
PDIDIS4    DEFINE  0xF02B4
PDIDIS5    DEFINE  0xF02B5
PDIDIS7    DEFINE  0xF02B7
PDIDIS8    DEFINE  0xF02B8
PDIDIS9    DEFINE  0xF02B9
PDIDIS12   DEFINE  0xF02BC
PDIDIS13   DEFINE  0xF02BD
PDIDIS14   DEFINE  0xF02BE
FLPMC      DEFINE  0xF02C0
FLARS      DEFINE  0xF02C1
FLAPL      DEFINE  0xF02C2
FLAPH      DEFINE  0xF02C4
FSSQ       DEFINE  0xF02C5
FLSEDL     DEFINE  0xF02C6
FLSEDH     DEFINE  0xF02C8
FLRST      DEFINE  0xF02C9
FSASTL     DEFINE  0xF02CA
FSASTH     DEFINE  0xF02CB
FLWL       DEFINE  0xF02CC
FLWH       DEFINE  0xF02CE
DTCBAR     DEFINE  0xF02E0
DTCEN0     DEFINE  0xF02E8
DTCEN1     DEFINE  0xF02E9
DTCEN2     DEFINE  0xF02EA
DTCEN3     DEFINE  0xF02EB
DTCEN4     DEFINE  0xF02EC
CRC0CTL    DEFINE  0xF02F0
PGCRCL     DEFINE  0xF02F2
CRCD       DEFINE  0xF02FA
TXBA0      DEFINE  0xF0300
RXBA0      DEFINE  0xF0301
ASIMA00    DEFINE  0xF0302
ASIMA01    DEFINE  0xF0303
BRGCA0     DEFINE  0xF0304
ASISA0     DEFINE  0xF0305
ASCTA0     DEFINE  0xF0306
TXBA1      DEFINE  0xF0308
RXBA1      DEFINE  0xF0309
ASIMA10    DEFINE  0xF030A
ASIMA11    DEFINE  0xF030B
BRGCA1     DEFINE  0xF030C
ASISA1     DEFINE  0xF030D
ASCTA1     DEFINE  0xF030E
UTA0CK     DEFINE  0xF0310
UTA1CK     DEFINE  0xF0311
DACS0      DEFINE  0xF0330
DACS1      DEFINE  0xF0331
DAM        DEFINE  0xF0332
COMPMDR    DEFINE  0xF0340
COMPFIR    DEFINE  0xF0341
COMPOCR    DEFINE  0xF0342
ITLCMP00   DEFINE  0xF0360
ITLCMP000  DEFINE  0xF0360
ITLCMP001  DEFINE  0xF0361
ITLCMP01   DEFINE  0xF0362
ITLCMP012  DEFINE  0xF0362
ITLCMP013  DEFINE  0xF0363
ITLCAP00   DEFINE  0xF0364
ITLCTL0    DEFINE  0xF0366
ITLCSEL0   DEFINE  0xF0367
ITLFDIV00  DEFINE  0xF0368
ITLFDIV01  DEFINE  0xF0369
ITLCC0     DEFINE  0xF036A
ITLS0      DEFINE  0xF036B
ITLMKF0    DEFINE  0xF036C
SMSI0      DEFINE  0xF0380
SMSI1      DEFINE  0xF0382
SMSI2      DEFINE  0xF0384
SMSI3      DEFINE  0xF0386
SMSI4      DEFINE  0xF0388
SMSI5      DEFINE  0xF038A
SMSI6      DEFINE  0xF038C
SMSI7      DEFINE  0xF038E
SMSI8      DEFINE  0xF0390
SMSI9      DEFINE  0xF0392
SMSI10     DEFINE  0xF0394
SMSI11     DEFINE  0xF0396
SMSI12     DEFINE  0xF0398
SMSI13     DEFINE  0xF039A
SMSI14     DEFINE  0xF039C
SMSI15     DEFINE  0xF039E
SMSI16     DEFINE  0xF03A0
SMSI17     DEFINE  0xF03A2
SMSI18     DEFINE  0xF03A4
SMSI19     DEFINE  0xF03A6
SMSI20     DEFINE  0xF03A8
SMSI21     DEFINE  0xF03AA
SMSI22     DEFINE  0xF03AC
SMSI23     DEFINE  0xF03AE
SMSI24     DEFINE  0xF03B0
SMSI25     DEFINE  0xF03B2
SMSI26     DEFINE  0xF03B4
SMSI27     DEFINE  0xF03B6
SMSI28     DEFINE  0xF03B8
SMSI29     DEFINE  0xF03BA
SMSI30     DEFINE  0xF03BC
SMSI31     DEFINE  0xF03BE
SMSG0      DEFINE  0xF03C0
SMSG1      DEFINE  0xF03C2
SMSG2      DEFINE  0xF03C4
SMSG3      DEFINE  0xF03C6
SMSG4      DEFINE  0xF03C8
SMSG5      DEFINE  0xF03CA
SMSG6      DEFINE  0xF03CC
SMSG7      DEFINE  0xF03CE
SMSG8      DEFINE  0xF03D0
SMSG9      DEFINE  0xF03D2
SMSG10     DEFINE  0xF03D4
SMSG11     DEFINE  0xF03D6
SMSG12     DEFINE  0xF03D8
SMSG13     DEFINE  0xF03DA
SMSG14     DEFINE  0xF03DC
SMSG15     DEFINE  0xF03DE
SMSC       DEFINE  0xF03E0
SMSS       DEFINE  0xF03E1
FLSIVC0    DEFINE  0xF0480
FLSIVC1    DEFINE  0xF0482
GFLASH0    DEFINE  0xF0488
GFLASH1    DEFINE  0xF048A
GFLASH2    DEFINE  0xF048C
GIAWCTL    DEFINE  0xF048E
CTSUCRAL   DEFINE  0xF0500
CTSUCR0    DEFINE  0xF0500
CTSUCR1    DEFINE  0xF0501
CTSUCRAH   DEFINE  0xF0502
CTSUCR2    DEFINE  0xF0502
CTSUCR3    DEFINE  0xF0503
CTSUCRBL   DEFINE  0xF0504
CTSUSDPRS  DEFINE  0xF0504
CTSUSST    DEFINE  0xF0505
CTSUCRBH   DEFINE  0xF0506
CTSUDCLKC  DEFINE  0xF0507
CTSUMCHL   DEFINE  0xF0508
CTSUMCH0   DEFINE  0xF0508
CTSUMCH1   DEFINE  0xF0509
CTSUMCHH   DEFINE  0xF050A
CTSUMFAF   DEFINE  0xF050A
CTSUCHACAL DEFINE  0xF050C
CTSUCHAC0  DEFINE  0xF050C
CTSUCHAC1  DEFINE  0xF050D
CTSUCHACAH DEFINE  0xF050E
CTSUCHAC2  DEFINE  0xF050E
CTSUCHAC3  DEFINE  0xF050F
CTSUCHACBL DEFINE  0xF0510
CTSUCHAC4  DEFINE  0xF0510
CTSUCHAC5  DEFINE  0xF0511
CTSUCHACBH DEFINE  0xF0512
CTSUCHAC6  DEFINE  0xF0512
CTSUCHAC7  DEFINE  0xF0513
CTSUCHTRCAL DEFINE  0xF0514
CTSUCHTRC0 DEFINE  0xF0514
CTSUCHTRC1 DEFINE  0xF0515
CTSUCHTRCAH DEFINE  0xF0516
CTSUCHTRC2 DEFINE  0xF0516
CTSUCHTRC3 DEFINE  0xF0517
CTSUCHTRCBL DEFINE  0xF0518
CTSUCHTRC4 DEFINE  0xF0518
CTSUCHTRC5 DEFINE  0xF0519
CTSUCHTRCBH DEFINE  0xF051A
CTSUCHTRC6 DEFINE  0xF051A
CTSUCHTRC7 DEFINE  0xF051B
CTSUSRL    DEFINE  0xF051C
CTSUST1    DEFINE  0xF051C
CTSUST     DEFINE  0xF051D
CTSUSRH    DEFINE  0xF051E
CTSUST2    DEFINE  0xF051E
CTSUSO0    DEFINE  0xF0520
CTSUSO1    DEFINE  0xF0522
CTSUSC     DEFINE  0xF0524
CTSUUC     DEFINE  0xF0526
CTSUDBGR0  DEFINE  0xF0528
CTSUDBGR1  DEFINE  0xF052A
CTSUSUCLK0 DEFINE  0xF052C
CTSUSUCLK1 DEFINE  0xF052E
CTSUSUCLK2 DEFINE  0xF0530
CTSUSUCLK3 DEFINE  0xF0532
TRNGSDR    DEFINE  0xF0540
TRNGSCR0   DEFINE  0xF0542
CTSUTRIM0  DEFINE  0xF0600
RTRIM      DEFINE  0xF0600
DACTRIM    DEFINE  0xF0601
CTSUTRIM1  DEFINE  0xF0602
SUADJD     DEFINE  0xF0602
SUADJTRIM  DEFINE  0xF0603
CTSUTRIM2  DEFINE  0xF0604
TRESULT0   DEFINE  0xF0604
TRESULT1   DEFINE  0xF0605
CTSUTRIM3  DEFINE  0xF0606
TRESULT2   DEFINE  0xF0606
TRESULT3   DEFINE  0xF0607
REMCON0    DEFINE  0xF0640
REMCON1    DEFINE  0xF0641
REMSTS     DEFINE  0xF0642
REMINT     DEFINE  0xF0643
REMCPC     DEFINE  0xF0645
REMCPD     DEFINE  0xF0646
HDPMIN     DEFINE  0xF0648
HDPMAX     DEFINE  0xF064A
D0PMIN     DEFINE  0xF064C
D0PMAX     DEFINE  0xF064D
D1PMIN     DEFINE  0xF064E
D1PMAX     DEFINE  0xF064F
SDPMIN     DEFINE  0xF0650
SDPMAX     DEFINE  0xF0652
REMPE      DEFINE  0xF0654
REMSTC     DEFINE  0xF0656
REMRBIT    DEFINE  0xF0657
REMDAT0    DEFINE  0xF0658
REMDAT1    DEFINE  0xF0659
REMDAT2    DEFINE  0xF065A
REMDAT3    DEFINE  0xF065B
REMDAT4    DEFINE  0xF065C
REMDAT5    DEFINE  0xF065D
REMDAT6    DEFINE  0xF065E
REMDAT7    DEFINE  0xF065F
REMTIM     DEFINE  0xF0660
ELISEL0    DEFINE  0xF0680
ELISEL1    DEFINE  0xF0681
ELISEL2    DEFINE  0xF0682
ELISEL3    DEFINE  0xF0683
ELISEL4    DEFINE  0xF0684
ELISEL5    DEFINE  0xF0685
ELISEL6    DEFINE  0xF0686
ELISEL7    DEFINE  0xF0687
ELISEL8    DEFINE  0xF0688
ELISEL9    DEFINE  0xF0689
ELISEL10   DEFINE  0xF068A
ELISEL11   DEFINE  0xF068B
ELL1SEL0   DEFINE  0xF0690
ELL1SEL1   DEFINE  0xF0691
ELL1SEL2   DEFINE  0xF0692
ELL1SEL3   DEFINE  0xF0693
ELL1SEL4   DEFINE  0xF0694
ELL1SEL5   DEFINE  0xF0695
ELL1SEL6   DEFINE  0xF0696
ELL1CTL    DEFINE  0xF0697
ELL1LNK0   DEFINE  0xF0698
ELL1LNK1   DEFINE  0xF0699
ELL1LNK2   DEFINE  0xF069A
ELL1LNK3   DEFINE  0xF069B
ELL1LNK4   DEFINE  0xF069C
ELL1LNK5   DEFINE  0xF069D
ELL1LNK6   DEFINE  0xF069E
ELL2SEL0   DEFINE  0xF06A0
ELL2SEL1   DEFINE  0xF06A1
ELL2SEL2   DEFINE  0xF06A2
ELL2SEL3   DEFINE  0xF06A3
ELL2SEL4   DEFINE  0xF06A4
ELL2SEL5   DEFINE  0xF06A5
ELL2SEL6   DEFINE  0xF06A6
ELL2CTL    DEFINE  0xF06A7
ELL2LNK0   DEFINE  0xF06A8
ELL2LNK1   DEFINE  0xF06A9
ELL2LNK2   DEFINE  0xF06AA
ELL2LNK3   DEFINE  0xF06AB
ELL2LNK4   DEFINE  0xF06AC
ELL2LNK5   DEFINE  0xF06AD
ELL2LNK6   DEFINE  0xF06AE
ELL3SEL0   DEFINE  0xF06B0
ELL3SEL1   DEFINE  0xF06B1
ELL3SEL2   DEFINE  0xF06B2
ELL3SEL3   DEFINE  0xF06B3
ELL3SEL4   DEFINE  0xF06B4
ELL3SEL5   DEFINE  0xF06B5
ELL3SEL6   DEFINE  0xF06B6
ELL3CTL    DEFINE  0xF06B7
ELL3LNK0   DEFINE  0xF06B8
ELL3LNK1   DEFINE  0xF06B9
ELL3LNK2   DEFINE  0xF06BA
ELL3LNK3   DEFINE  0xF06BB
ELL3LNK4   DEFINE  0xF06BC
ELL3LNK5   DEFINE  0xF06BD
ELL3LNK6   DEFINE  0xF06BE
ELOSEL0    DEFINE  0xF06C0
ELOSEL1    DEFINE  0xF06C1
ELOSEL2    DEFINE  0xF06C2
ELOSEL3    DEFINE  0xF06C3
ELOSEL4    DEFINE  0xF06C4
ELOSEL5    DEFINE  0xF06C5
ELOSEL6    DEFINE  0xF06C6
ELOSEL7    DEFINE  0xF06C7
ELOENCTL   DEFINE  0xF06C8
ELOMONI    DEFINE  0xF06C9

#endif /* __IAR_SYSTEMS_ASM__ */

#endif /* __IOR7F100G_EXT_H__ */
