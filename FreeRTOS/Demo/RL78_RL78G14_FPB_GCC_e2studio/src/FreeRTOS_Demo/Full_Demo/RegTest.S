;/*
; * FreeRTOS V202104.00
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

	.global    _vRegTest1Task
	.global    _vRegTest2Task

; Functions and variables used by this file
;------------------------------------------------------------------------------
	.extern    _vRegTestError
	.extern    _usRegTest1LoopCounter
	.extern    _usRegTest2LoopCounter

;------------------------------------------------------------------------------
;   Fill all the registers with known values, then check that the registers
;   contain the expected value.  An incorrect value being indicative of an
;   error in the context switch mechanism.  NOTE: Since GNURL78 assumes that
;   CS = 0, so that CS has to be set to 0 at the start of all ISRs if CS is
;   set to values other than 0.
;
;   Input:  NONE
;
;   Call:   Created as a task.
;
;   Output: NONE
;
;------------------------------------------------------------------------------
	.text
_vRegTest1Task:

	; First fill the registers.
	SEL		RB0
	MOVW	AX, #0x1122
	MOVW	BC, #0x3344
	MOVW	DE, #0x5566
	MOVW	HL, #0x7788
	MOV		CS, #0x01
	MOV		ES, #0x02
	SEL		RB1
	MOVW	AX, #0x1111
	MOVW	BC, #0x2222
	MOVW	DE, #0x3333
	MOVW	HL, #0x4444
	SEL		RB2
	MOVW	AX, #0x5555
	MOVW	BC, #0x6666
	MOVW	DE, #0x7777
	MOVW	HL, #0x8888

	; Register bank 3 is not used outside of interrupts so is not saved as part
	; of the task context.
	SEL		RB0

.loop1:

	; Continuously check that the register values remain at their expected
	; values.  The BRK is to test the yield.  This task runs at low priority
	; so will also regularly get preempted.
	BRK

	; Compare with the expected value.
	CMPW	AX, #0x1122
	SKZ

	; Jump over the branch to vRegTestError() if the register contained the
	; expected value - otherwise flag an error by executing vRegTestError().
	CALL	!!_vRegTestError

	; Repeat for all the registers.
	MOVW	AX, BC
	CMPW	AX, #0x3344
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, DE
	CMPW	AX, #0x5566
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, HL
	CMPW	AX, #0x7788
	SKZ
	CALL	!!_vRegTestError
	MOV		A, CS
	CMP		A, #0x01
	SKZ
	CALL	!!_vRegTestError
	MOV		A, ES
	CMP		A, #0x02
	SKZ
	CALL	!!_vRegTestError

	; Set AX back to its initial value.
	MOVW	AX, #0x1122

	SEL		RB1
	CMPW	AX, #0x1111
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, BC
	CMPW	AX, #0x2222
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, DE
	CMPW	AX, #0x3333
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, HL
	CMPW	AX, #0x4444
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, #0x1111


	SEL		RB2
	CMPW	AX, #0x5555
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, BC
	CMPW	AX, #0x6666
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, DE
	CMPW	AX, #0x7777
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, HL
	CMPW	AX, #0x8888
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, #0x5555


	; Register bank 3 is not used outside of interrupts so is not saved as
	; part of the task context.

	SEL 	RB0

	; Indicate that this task is still cycling.
	INCW	!_usRegTest1LoopCounter

	BR 		!!.loop1


;------------------------------------------------------------------------------
;   Fill all the registers with known values, then check that the registers
;   contain the expected value.  An incorrect value being indicative of an
;   error in the context switch mechanism.  NOTE: Since GNURL78 assumes that
;   CS = 0, so that CS has to be set to 0 at the start of all ISRs if CS is
;   set to values other than 0.
;
;
;   Input:  NONE
;
;   Call:   Created as a task.
;
;   Output: NONE
;
;------------------------------------------------------------------------------
	.text
_vRegTest2Task:

	SEL		RB0
	MOVW	AX, #0x99aa
	MOVW	BC, #0xbbcc
	MOVW	DE, #0xddee
	MOVW	HL, #0xff12
	MOV		CS, #0x03
	MOV		ES, #0x04
	SEL		RB1
	MOVW	AX, #0x0110
	MOVW	BC, #0x0220
	MOVW	DE, #0x0330
	MOVW	HL, #0x0440
	SEL		RB2
	MOVW	AX, #0x0550
	MOVW	BC, #0x0660
	MOVW	DE, #0x0770
	MOVW	HL, #0x0880

	; Register bank 3 is not used outside of interrupts so is not saved as
	; part of the task context.
	SEL		RB0

.loop2:
	CMPW	AX, #0x99aa
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, BC
	CMPW	AX, #0xbbcc
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, DE
	CMPW	AX, #0xddee
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, HL
	CMPW	AX, #0xff12
	SKZ
	CALL	!!_vRegTestError
	MOV		A, CS
	CMP		A, #0x03
	SKZ
	CALL	!!_vRegTestError
	MOV		A, ES
	CMP		A, #0x04
	SKZ
	CALL	!!_vRegTestError

	; Set AX back to its initial value.
	MOVW	AX, #0x99aa

	SEL		RB1
	CMPW	AX, #0x0110
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, BC
	CMPW	AX, #0x0220
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, DE
	CMPW	AX, #0x0330
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, HL
	CMPW	AX, #0x0440
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, #0x0110

	SEL		RB2
	CMPW	AX, #0x0550
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, BC
	CMPW	AX, #0x0660
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, DE
	CMPW	AX, #0x0770
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, HL
	CMPW	AX, #0x0880
	SKZ
	CALL	!!_vRegTestError
	MOVW	AX, #0x0550

	; Register bank 3 is not used outside of interrupts so is not saved as
	; part of the task context.

	SEL 	RB0

	; Indicate that this task is still cycling.
	INCW	!_usRegTest2LoopCounter

	BR 		!!.loop2


	.end
