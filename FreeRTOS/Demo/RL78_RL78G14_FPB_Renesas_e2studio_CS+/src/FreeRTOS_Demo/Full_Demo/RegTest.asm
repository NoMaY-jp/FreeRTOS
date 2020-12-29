;/*
; * FreeRTOS V202012.00
; * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
; *
; * Permission is hereby granted, free of charge, to any person obtaining a copy of
; * this software and associated documentation files (the "Software"), to deal in
; * the Software without restriction, including without limitation the rights to
; * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
; * the Software, and to permit persons to whom the Software is furnished to do so,
; * subject to the following conditions:
; *
; * The above copyright notice and this permission notice shall be included in all
; * copies or substantial portions of the Software.
; *
; * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
; * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
; * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
; * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
; * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
; *
; * http://www.FreeRTOS.org
; * http://aws.amazon.com/freertos
; *
; * 1 tab == 4 spaces!
; */


;
; This file defines the RegTest tasks as described at the top of main.c
;

;------------------------------------------------------------------------------


; Functions implemented in this file
;------------------------------------------------------------------------------

	.PUBLIC    _vRegTest1Task
	.PUBLIC    _vRegTest2Task

; Functions and variables used by this file
;------------------------------------------------------------------------------
	.EXTERN    _vRegTestError
	.EXTERN    _usRegTest1LoopCounter
	.EXTERN    _usRegTest2LoopCounter

;------------------------------------------------------------------------------
;   Fill all the registers with known values, then check that the registers
;   contain the expected value.  An incorrect value being indicative of an
;   error in the context switch mechanism.
;
;   Input:  NONE
;
;   Call:   Created as a task.
;
;   Output: NONE
;
;------------------------------------------------------------------------------
	.SECTION .textf,TEXTF
_vRegTest1Task:

	; First fill the registers.
	MOVW	AX, #0x1122
	MOVW	BC, #0x3344
	MOVW	DE, #0x5566
	MOVW	HL, #0x7788
	MOV		CS, #0x01
	MOV		ES, #0x02

loop1:

	; Continuously check that the register values remain at their expected
	; values.  The BRK is to test the yield.  This task runs at low priority
	; so will also regularly get preempted.
	BRK

	; Compare with the expected value.
	CMPW	AX, #0x1122
	SKZ

	; Jump over the branch to vRegTestError() if the register contained the
	; expected value - otherwise flag an error by executing vRegTestError().
	BR		!!_vRegTestError

	; Repeat for all the registers.
	MOVW	AX, BC
	CMPW	AX, #0x3344
	SKZ
	BR		!!_vRegTestError
	MOVW	AX, DE
	CMPW	AX, #0x5566
	SKZ
	BR		!!_vRegTestError
	MOVW	AX, HL
	CMPW	AX, #0x7788
	SKZ
	BR		!!_vRegTestError
	MOV		A, CS
	CMP		A, #0x01
	SKZ
	BR		!!_vRegTestError
	MOV		A, ES
	CMP		A, #0x02
	SKZ
	BR		!!_vRegTestError

	; Set AX back to its initial value.
	MOVW	AX, #0x1122

	; Indicate that this task is still cycling.
	INCW	!_usRegTest1LoopCounter

	BR 		$loop1


;------------------------------------------------------------------------------
;   Fill all the registers with known values, then check that the registers
;   contain the expected value.  An incorrect value being indicative of an
;   error in the context switch mechanism.
;
;   Input:  NONE
;
;   Call:   Created as a task.
;
;   Output: NONE
;
;------------------------------------------------------------------------------
	.SECTION .textf,TEXTF
_vRegTest2Task:

	MOVW	AX, #0x99aa
	MOVW	BC, #0xbbcc
	MOVW	DE, #0xddee
	MOVW	HL, #0xff12
	MOV		CS, #0x03
	MOV		ES, #0x04

loop2:
	CMPW	AX, #0x99aa
	SKZ
	BR		!!_vRegTestError
	MOVW	AX, BC
	CMPW	AX, #0xbbcc
	SKZ
	BR		!!_vRegTestError
	MOVW	AX, DE
	CMPW	AX, #0xddee
	SKZ
	BR		!!_vRegTestError
	MOVW	AX, HL
	CMPW	AX, #0xff12
	SKZ
	BR		!!_vRegTestError
	MOV		A, CS
	CMP		A, #0x03
	SKZ
	BR		!!_vRegTestError
	MOV		A, ES
	CMP		A, #0x04
	SKZ
	BR		!!_vRegTestError

	; Set AX back to its initial value.
	MOVW	AX, #0x99aa

	; Indicate that this task is still cycling.
	INCW	!_usRegTest2LoopCounter

	BR 		$loop2

