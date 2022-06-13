/* Copyright 2020, Juan Manuel Cruz.
 * All rights reserved.
 *
 * This file is part of Project => assembly-project-1.
 *    https://gitlab.frba.utn.edu.ar/R-TDII/assembly-project-1
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*--------------------------------------------------------------------*-

    main.s (Released 2020-01)

--------------------------------------------------------------------

    main file for Assembly Programming - Project for LPC1769.

    See readme.txt for project information.

-*--------------------------------------------------------------------*/


// Project header
#include "main.h"


// ------ Public functions -----------------------------------------
		.extern		task1Init, task1Update
		.extern		task2Init, task2Update


/*------------------------------------------------------------------*/
		.section	.bss

		.comm	mainLoopCnt,4	// static volatile uint32_t mainLoopCnt;
		.comm	taskCnt,4		// static volatile uint32_t taskCnt;

		.comm	tick_ct, 4		// static volatile uint32_t taskCnt;


/*------------------------------------------------------------------*/
		.syntax		unified
	    .arch       armv7-m
		.cpu		cortex-m0
		.thumb

		.section	.text
		.align		2


#if (TEST == TEST_1)	/* Test original two tasks without arguments */
/*------------------------------------------------------------------*/
 		.global		main
		.type		main, %function

main:
		PUSH	{LR}					// Save PC

    	BL		systemInit				// systemInit();

		LDR		R1, =mainLoopCnt		// R1 <- address of mainLoopCnt
		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => mainLoopCnt = 0;

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => taskCnt = 0;

mainLoop:

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		CMP		R0, #tasksTableParts
		BHI		taskCntError			// Jump if (R0 > tasksTableParts)


		MOVS	R2, #tasksTablePartSize	// R2 <- tasksTablePartSize
		MULS	R0, R0, R2				// R0 <- R0 * R2
										// R0 <- taskCnt * tasksTablePartSize
		LDR		R1, =tasksTable			// R1 <- address of tasksTable
		LDR		R2, [R1, R0]			// R2 <- mem[R1 + R0]
		BLX		R2						// Branch to taskX

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		ADDS	R0, R0, #1				// R0 <- R0 + 1
		STR		R0, [R1]    			// mem[R1] <- R0 => taskCnt++;
		CMP		R0, #tasksTableParts
		BLT		mainLoopContinue		// Jump if (R0 < tasksTableParts)

		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => taskCnt = 0;

mainLoopContinue:

		LDR		R1, =mainLoopCnt		// R1 <- address of mainLoopCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		ADDS	R0, R0, #1				// R0 <- R0 + 1
		STR		R0, [R1]      			// mem[R1] <- R0 => mainLoopCnt++;

		B		mainLoop				// Continue forever

mainLoopEnd:							// We should never reach here

		POP		{PC}					// Return

taskCntError:							// We should never reach here
		B		taskCntError

		.size	main, . - main


/*------------------------------------------------------------------*/
		.global	systemInit
		.type	systemInit, %function
systemInit:
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		PUSH	{LR}					// Save PC
										// HW & SW initialization here
		BL		task1Init				// task1Init();
		BL		task2Init				// task2Init();

		POP		{PC}					// Retun

		.size	systemInit, . - systemInit


/*------------------------------------------------------------------*/
		.global	tasksTable
		.type	tasksTable, %object
		// Table of tasks
tasksTable:
		.word	task1Update				// task1Update();
tasksTable1:

		.word	task2Update				// task2Update();

tasksTableEnd:

		.size	tasksTable, . - tasksTable

		.equ	tasksTableSize, (tasksTableEnd - tasksTable)
		.equ	tasksTablePartSize, (tasksTable1 - tasksTable)
		.equ	tasksTableParts, (tasksTableSize/tasksTablePartSize)


#endif

#if (TEST == TEST_2)	/*est only one task with several
arguments – pass by value*/
/*------------------------------------------------------------------*/
 		.global		main
		.type		main, %function

main:
		PUSH	{LR}					// Save PC

    	BL		systemInit				// systemInit();

 // Codigo agregado

		MOVS	R0, #1					// On / Off LED
		MOVS	R1, #15					// Set DELAY with R1 value
		BLX		task					// Function TASK

// Fin de codigo agregado

		LDR		R1, =mainLoopCnt		// R1 <- address of mainLoopCnt
		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => mainLoopCnt = 0;

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => taskCnt = 0;

mainLoop:

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		CMP		R0, #tasksTableParts
		BHI		taskCntError			// Jump if (R0 > tasksTableParts)


		MOVS	R2, #tasksTablePartSize	// R2 <- tasksTablePartSize
		MULS	R0, R0, R2				// R0 <- R0 * R2
										// R0 <- taskCnt * tasksTablePartSize
		LDR		R1, =tasksTable			// R1 <- address of tasksTable
		LDR		R2, [R1, R0]			// R2 <- mem[R1 + R0]
		BLX		R2						// Branch to taskX

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		ADDS	R0, R0, #1				// R0 <- R0 + 1
		STR		R0, [R1]    			// mem[R1] <- R0 => taskCnt++;
		CMP		R0, #tasksTableParts
		BLT		mainLoopContinue		// Jump if (R0 < tasksTableParts)

		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => taskCnt = 0;

mainLoopContinue:

		LDR		R1, =mainLoopCnt		// R1 <- address of mainLoopCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		ADDS	R0, R0, #1				// R0 <- R0 + 1
		STR		R0, [R1]      			// mem[R1] <- R0 => mainLoopCnt++;

		B		mainLoop				// Continue forever

mainLoopEnd:							// We should never reach here

		POP		{PC}					// Return

taskCntError:							// We should never reach here
		B		taskCntError

		.size	main, . - main


/*------------------------------------------------------------------*/
		.global	systemInit
		.type	systemInit, %function
systemInit:
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		PUSH	{LR}					// Save PC
										// HW & SW initialization here
		BL		task1Init				// task1Init();
		BL		task2Init				// task2Init();

		POP		{PC}					// Retun

		.size	systemInit, . - systemInit


/*------------------------------------------------------------------*/
		.global	tasksTable
		.type	tasksTable, %object
		// Table of tasks
tasksTable:
		.word	task1Update				// task1Update();
tasksTable1:

		.word	task2Update				// task2Update();

tasksTableEnd:

		.size	tasksTable, . - tasksTable

		.equ	tasksTableSize, (tasksTableEnd - tasksTable)
		.equ	tasksTablePartSize, (tasksTable1 - tasksTable)
		.equ	tasksTableParts, (tasksTableSize/tasksTablePartSize)


#endif

#if (TEST == TEST_3)	/*Test only one task with only one
argument – pass by reference*/
/*------------------------------------------------------------------*/

 		.global		main
		.type		main, %function

main:
		PUSH	{LR}					// Save PC

    	BL		systemInit				// systemInit();

		// Codigo agregado

		LDR		R1, =a					// Envio el dato por referencia
		BLX		task

		// Fin de codigo agregado

		LDR		R1, =mainLoopCnt		// R1 <- address of mainLoopCnt
		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => mainLoopCnt = 0;

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => taskCnt = 0;

mainLoop:

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		CMP		R0, #tasksTableParts
		BHI		taskCntError			// Jump if (R0 > tasksTableParts)


		MOVS	R2, #tasksTablePartSize	// R2 <- tasksTablePartSize
		MULS	R0, R0, R2				// R0 <- R0 * R2
										// R0 <- taskCnt * tasksTablePartSize
		LDR		R1, =tasksTable			// R1 <- address of tasksTable
		LDR		R2, [R1, R0]			// R2 <- mem[R1 + R0]
		BLX		R2						// Branch to taskX

		LDR		R1, =taskCnt			// R1 <- address of taskCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		ADDS	R0, R0, #1				// R0 <- R0 + 1
		STR		R0, [R1]    			// mem[R1] <- R0 => taskCnt++;
		CMP		R0, #tasksTableParts
		BLT		mainLoopContinue		// Jump if (R0 < tasksTableParts)

		MOVS	R0, #0					// R0 <- 0
		STR		R0, [R1]      			// mem[R1] <- R0 => taskCnt = 0;

mainLoopContinue:

		LDR		R1, =mainLoopCnt		// R1 <- address of mainLoopCnt
  		LDR		R0, [R1]				// R0 <- mem[R1]
		ADDS	R0, R0, #1				// R0 <- R0 + 1
		STR		R0, [R1]      			// mem[R1] <- R0 => mainLoopCnt++;

		B		mainLoop				// Continue forever

mainLoopEnd:							// We should never reach here

		POP		{PC}					// Return

taskCntError:							// We should never reach here
		B		taskCntError

		.size	main, . - main


/*------------------------------------------------------------------*/
		.global	systemInit
		.type	systemInit, %function
systemInit:
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		PUSH	{LR}					// Save PC
										// HW & SW initialization here
		BL		task1Init				// task1Init();
		BL		task2Init				// task2Init();

		POP		{PC}					// Retun

		.size	systemInit, . - systemInit
/*------------------------------------------------------------------*/
 		.data
a:		.word		131073
/*------------------------------------------------------------------*/
		.global	tasksTable
		.type	tasksTable, %object
		// Table of tasks
tasksTable:
		.word	task1Update				// task1Update();
tasksTable1:

		.word	task2Update				// task2Update();

tasksTableEnd:

		.size	tasksTable, . - tasksTable

		.equ	tasksTableSize, (tasksTableEnd - tasksTable)
		.equ	tasksTablePartSize, (tasksTable1 - tasksTable)
		.equ	tasksTableParts, (tasksTableSize/tasksTablePartSize)


#endif

#if (TEST == TEST_4)	/*est only one task with several
arguments – pass by value*/
/*------------------------------------------------------------------*/
 		.global		main
		.type		main, %function

main:
		PUSH	{LR}					// Save PC

    	BL		systemInit				// systemInit();

		LDR		R2, =mainLoopCnt		// R2 <- address of mainLoopCnt
		MOVS	R3, #0					// R3 <- 0
		STR		R3, [R2]      			// mem[R1] <- R => mainLoopCnt = 0;

		LDR		R2, =taskCnt			// R2 <- address of taskCnt
		MOVS	R3, #0					// R3 <- 0
		STR		R3, [R2]      			// mem[R2] <- R3 => taskCnt = 0;

mainLoop:

		LDR		R2, =taskCnt			// R2 <- address of taskCnt
  		LDR		R3, [R2]				// R3 <- mem[R1]
		//CMP		R3, #tasksTableParts
		//BHI		taskCntError			// Jump if (R0 > tasksTableParts)


		MOVS	R4, #tasksTablePartSize	// R2 <- tasksTablePartSize
		MULS	R3, R3, R4				// R0 <- R0 * R2
										// R0 <- taskCnt * tasksTablePartSize
		LDR		R2, =tasksTable			// R1 <- address of tasksTable
		LDR		R4, [R2, R3]			// R2 <- mem[R1 + R0]
		ADDS	R3, R3, taskSize
		MOVS	R0, 0
		ADDS	R0, R2, R3

		BLX		R4						// Branch to taskX

		LDR		R2, =taskCnt			// R1 <- address of taskCnt
  		LDR		R3, [R2]				// R0 <- mem[R1]			// R0 <- R0 + 1
		STR		R3, [R2]    			// mem[R1] <- R0 => taskCnt++;
		CMP		R3, #tasksTableParts
		BLS 	mainLoopContinue		// Jump if (R0 < tasksTableParts)

		MOVS	R3, #0					// R0 <- 0
		STR		R3, [R2]      			// mem[R1] <- R0 => taskCnt = 0;

mainLoopContinue:

		LDR		R4, =mainLoopCnt		// R1 <- address of mainLoopCnt
  		LDR		R3, [R2]				// R0 <- mem[R1]
		ADDS	R3, R3, #1				// R0 <- R0 + 1
		STR		R3, [R2]      			// mem[R1] <- R0 => mainLoopCnt++;

		B		mainLoop				// Continue forever

mainLoopEnd:							// We should never reach here

		POP		{PC}
taskCntError:							// We should never reach here
		B		taskCntError

		.size	main, . - main

/*------------------------------------------------------------------*/
		.global	systemInit
		.type	systemInit, %function
systemInit:
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		PUSH	{LR}					// Save PC
										// HW & SW initialization here
		BL		task1Init				// task1Init();
		BL		task2Init				// task2Init();

		POP		{PC}					// Retun

		.size	systemInit, . - systemInit

/*------------------------------------------------------------------*/
 		.data

 		// Arrays to process
array8b:		.byte		5, 4, 3, 2, 2, 1, 3, 2 	// 3 - Array 8 bits - 8 elementos
Ocurrences8B:	.word 		0						//	Ocurrences

array16b:		.2byte		1, 2, 3, 1, 1, 1, 3, 2 	// 4	- Array 16 bits - 8 elementos
Ocurrences16B:	.word		0						//	Ocurrences

array32b:		.4byte		5, 4, 3, 2, 2, 1, 3, 2 	// 1 - Array 32 bits - 8 elementos
Ocurrences32B:	.word		0						// 	Ocurrences

/*------------------------------------------------------------------*/
		.global	tasksTable
		.type	tasksTable, %object
		// Table of tasks
tasksTable:
		.word	task
taskArgument1:
		.word 	array8b
taskArgument2:
		.word 	8
taskArgument3:
		.word 	8
taskArgument4:
		.word	2
taskArgument5:
		.word	Ocurrences8B

tasksTable1:
		.word	task
task1Argument1:
		.word 	array16b
task1Argument2:
		.word 	16
task1Argument3:
		.word 	8
task1Argument4:
		.word	1
task1Argument5:
		.word	Ocurrences16B

tasksTable3:
		.word	task
task2Argument1:
		.word 	array32b
task2Argument2:
		.word 	32
task2Argument3:
		.word 	8
task2Argument4:
		.word	5
task2Argument5:
		.word	Ocurrences32B

tasksTableEnd:

		.size	tasksTable, . - tasksTable

		.equ	tasksTableSize, (tasksTableEnd - tasksTable)
		.equ	tasksTablePartSize, (tasksTable1 - tasksTable)
		.equ	tasksTableParts, (tasksTableSize/tasksTablePartSize)
		.equ	taskSize, (tasksTablePartSize/6)


#endif

		.end
// .end marks the end of the assembly file. as does not process anything in
// the file past the .end directive.

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
