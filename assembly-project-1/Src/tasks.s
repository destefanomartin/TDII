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

    tasks.s (Released 2020-01)

--------------------------------------------------------------------

    tasks file for Assembly Programming - Project for LPC1769.

    See readme.txt for project information.

-*--------------------------------------------------------------------*/


// Project header
#include "main.h"


// Task header
#include "tasks.h"


/*------------------------------------------------------------------*/
		.syntax		unified
	    .arch       armv7-m
		.cpu		cortex-m0
		.thumb

		.section	.text
		.align		2


#if (TEST == TEST_1)	/* Test original two tasks without arguments */
/*------------------------------------------------------------------*/
		.global	task1Init
		.type	task1Init, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task1Init:
		PUSH	{LR}					// Save PC

		BL		ledInit					// ledInit();

		MOVS	R0, #LEDoN
		BL		led						// led(LEDoN);

task1InitEnd:

		POP		{PC}					// Return

		.size	task1Init, . - task1Init


/*------------------------------------------------------------------*/
		.global	task1Update
		.type	task1Update, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task1Update:
		PUSH	{LR}					// Save PC

		MOVS	R0, #LEDoN
		BL		led						// led(LEDoN);

        LDR		R0, =LEDoNdELAY
		BL		delay					// delay(LEDoNdELAY);

task1UpdateEnd:

		POP		{PC}					// Return

		.size	task1Update, . - task1Update


/*------------------------------------------------------------------*/
		.global	task2Init
		.type	task2Init, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task2Init:
		PUSH	{LR}					// Save PC

		BL		ledInit					// ledInit();

		MOVS	R0, #LEDoFF
		BL		led						// led(LEDoFF);

task2InitEnd:

		POP		{PC}					// Return

		.size	task2Init, . - task2Init


/*------------------------------------------------------------------*/
		.global	task2Update
		.type	task2Update, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task2Update:
		PUSH	{LR}					// Save PC

		MOVS	R0, #LEDoFF
		BL		led						// led(LEDoFF);

        LDR		R0, =LEDoFFdELAY
		BL		delay					// delay(LEDoFFdELAY);

task2UpdateEnd:

		POP		{PC}					// Return

		.size	task2Update, . - task2Update

#endif

#if (TEST == TEST_2)	/* est only one task with several
arguments – pass by value */
/*------------------------------------------------------------------*/
		.global	task1Init
		.type	task1Init, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task1Init:
		PUSH	{LR}					// Save PC

		BL		ledInit					// ledInit();

		MOVS	R0, #LEDoN
		BL		led						// led(LEDoN);

task1InitEnd:

		POP		{PC}					// Return

		.size	task1Init, . - task1Init


/*------------------------------------------------------------------*/
		.global	task1Update
		.type	task1Update, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task1Update:
		PUSH	{LR}					// Save PC

		MOVS	R0, #LEDoN
		BL		led						// led(LEDoN);

        LDR		R0, =LEDoNdELAY
		BL		delay					// delay(LEDoNdELAY);

task1UpdateEnd:

		POP		{PC}					// Return

		.size	task1Update, . - task1Update


/*------------------------------------------------------------------*/
		.global	task2Init
		.type	task2Init, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task2Init:
		PUSH	{LR}					// Save PC

		BL		ledInit					// ledInit();

		MOVS	R0, #LEDoFF
		BL		led						// led(LEDoFF);

task2InitEnd:

		POP		{PC}					// Return

		.size	task2Init, . - task2Init


/*------------------------------------------------------------------*/
		.global	task2Update
		.type	task2Update, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task2Update:
		PUSH	{LR}					// Save PC

		MOVS	R0, #LEDoFF
		BL		led						// led(LEDoFF);

        LDR		R0, =LEDoFFdELAY
		BL		delay					// delay(LEDoFFdELAY);

task2UpdateEnd:

		POP		{PC}					// Return

		.size	task2Update, . - task2Update

/*------------------------------------------------------------------*/
		.global task
		.type task, %function
		// R0 (LEDoN o LEDoFF, LEDdELAYoN o LEDdELAYoFF): argument
		// R2, R3: Argumento que envia el main
		// Codigo agregado
task:
		PUSH	{LR, R1}					// Save R1 for Delay

		BL		led							// Turn or off led

		POP		{R1}						// Pop R1 for delay task

		MOVS	R0, R1
		BL		delay

		POP		{PC}

#endif
		// Fin de codigo agregado
#if (TEST == TEST_3)	/* Test only one task with only one
argument – pass by reference */
/*------------------------------------------------------------------*/
		.global	task1Init
		.type	task1Init, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task1Init:
		PUSH	{LR}					// Save PC

		BL		ledInit					// ledInit();

		MOVS	R0, #LEDoN
		BL		led						// led(LEDoN);

task1InitEnd:

		POP		{PC}					// Return

		.size	task1Init, . - task1Init


/*------------------------------------------------------------------*/
		.global	task1Update
		.type	task1Update, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task1Update:
		PUSH	{LR}					// Save PC

		MOVS	R0, #LEDoN
		BL		led						// led(LEDoN);

        LDR		R0, =LEDoNdELAY
		BL		delay					// delay(LEDoNdELAY);

task1UpdateEnd:

		POP		{PC}					// Return

		.size	task1Update, . - task1Update


/*------------------------------------------------------------------*/
		.global	task2Init
		.type	task2Init, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task2Init:
		PUSH	{LR}					// Save PC

		BL		ledInit					// ledInit();

		MOVS	R0, #LEDoFF
		BL		led						// led(LEDoFF);

task2InitEnd:

		POP		{PC}					// Return

		.size	task2Init, . - task2Init


/*------------------------------------------------------------------*/
		.global	task2Update
		.type	task2Update, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: variable register
task2Update:
		PUSH	{LR}					// Save PC

		MOVS	R0, #LEDoFF
		BL		led						// led(LEDoFF);

        LDR		R0, =LEDoFFdELAY
		BL		delay					// delay(LEDoFFdELAY);

task2UpdateEnd:

		POP		{PC}					// Return

		.size	task2Update, . - task2Update

/*------------------------------------------------------------------*/
		.global task
		.type task, %function
		// R0 (LEDoN o LEDoFF, LEDdELAYoN o LEDdELAYoFF): argument
		// R2, R3: Argumento que envia el main
		// Codigo agregado
task:

		PUSH	{LR}
		PUSH 	{R1}

		LDRH		R0, [R1]

		PUSH	{R1}
		BL		led
		POP		{R1}

		ADDS 	R1,R1,#2

		LDRH	R0, [R1]			// Turn or off led
									// Envio el delay que quiero
		BL 		delay

#endif
		// Fin de codigo agregado

#if (TEST == TEST_4)	/* Test only one task with only one
argument – pass by reference */
/*------------------------------------------------------------------*/
		.global	task1Init
		.type	task1Init, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task1Init:
		PUSH	{LR}					// Save PC

		BL		ledInit					// ledInit();

		MOVS	R0, #LEDoN
		BL		led						// led(LEDoN);

task1InitEnd:

		POP		{PC}					// Return

		.size	task1Init, . - task1Init


/*------------------------------------------------------------------*/
		.global	task1Update
		.type	task1Update, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task1Update:
		PUSH	{LR}					// Save PC

		MOVS	R0, #LEDoN
		BL		led						// led(LEDoN);

        LDR		R0, =LEDoNdELAY
		BL		delay					// delay(LEDoNdELAY);

task1UpdateEnd:

		POP		{PC}					// Return

		.size	task1Update, . - task1Update


/*------------------------------------------------------------------*/
		.global	task2Init
		.type	task2Init, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task2Init:
		PUSH	{LR}					// Save PC

		BL		ledInit					// ledInit();

		MOVS	R0, #LEDoFF
		BL		led						// led(LEDoFF);

task2InitEnd:

		POP		{PC}					// Return

		.size	task2Init, . - task2Init


/*------------------------------------------------------------------*/
		.global	task2Update
		.type	task2Update, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
task2Update:
		PUSH	{LR}					// Save PC

		MOVS	R0, #LEDoFF
		BL		led						// led(LEDoFF);

        LDR		R0, =LEDoFFdELAY
		BL		delay					// delay(LEDoFFdELAY);

task2UpdateEnd:

		POP		{PC}					// Return

		.size	task2Update, . - task2Update


/*------------------------------------------------------------------*/
		.global task
		.type task, %function

task:
		PUSH 	{LR}
		PUSH 	{R1, R2, R3, R4,R5, R7}

		LDR		R1, [R0,#4]

		LDR 	R2, [R0,#8]

		LDR 	R3, [R0, #12]

		LDR		R4, [R0, #16]

		LDR		R0, [R0]

		CMP		R1, #8
		BEQ		taskB

		CMP		R1, #16
		BEQ 	task2B

		CMP		R1, #32
		BEQ		task4B

/*------------------------------------------------------------------*/
		.global taskB
		.type task, %function
		// R0 (LEDoN o LEDoFF, LEDdELAYoN o LEDdELAYoFF): argument
		// R2, R3: Argumento que envia el main
taskB:

		MOVS 	R4, R0
		LDRB 	R6, [R4,R5]
		CMP		R6, R3
		BEQ		taskBadd
		CMP		R5, R2
		BHS 	taskEnd
taskBloop:

		ADDS	R5, #1
		B		taskB

taskBadd:

		ADDS 	R7, #1
		B		taskBloop




/*------------------------------------------------------------------*/
		.global task2B
		.type task, %function
		// R0 (LEDoN o LEDoFF, LEDdELAYoN o LEDdELAYoFF): argument
		// R2, R3: Argumento que envia el main
task2B:
		MOVS 	R4, R0
		LDRB 	R6, [R4,R5]
		CMP		R6, R3
		BEQ		task2Badd
		CMP		R5, R2
		BHS 	taskEnd

task2Bloop:
		ADDS	R5, #2
		B		task2B


task2Badd:

		ADDS 	R7, #1
		B		task2Bloop



/*------------------------------------------------------------------*/
		.global task4B
		.type task, %function
		// R0 (LEDoN o LEDoFF, LEDdELAYoN o LEDdELAYoFF): argument
		// R2, R3: Argumento que envia el main
task4B:
		MOVS 	R4, R0
		LDRB 	R6, [R4,R5]
		CMP		R6, R3
		BEQ		task4Badd
		CMP		R5, R2
		BHS 	taskEnd

task4Bloop:
		ADDS	R5, #2
		B		task4B
task4Badd:
		ADDS 	R7, #1
		B		task4Bloop



taskEnd:
		STR 	R7, [R4]
		MOVS 	R0, R7

		POP {R7,R5, R4, R3, R2, R1}
		POP {PC}


#endif


/*------------------------------------------------------------------*/
		.type	ledInit, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
ledInit:
		PUSH	{R0, R1, R3, LR}	// Mando a la pila los registros que modifico y LR
		LDR		R0,	=#RCC_AHB1ENR		// Dirección de memoria para habilitar clk en GPIO
		LDR		R3, [R0]				// Leo el registro
		LDR		R1, =#GPIOAEN			//
		ORRS	R3, R1					// Habilito el bit en cuestión
		STR		R3, [R0]				// Escribo el registro.
		LDR		R0, =#PORTA_MODER
		LDR		R3, [R0]
		MOVS	R1, #0x01
		LSLS	R1, R1, #10
		ORRS	R3, R1
		STR		R3, [R0]				//Leo la configuración de GPIOA y pongo A5 como salida
		POP		{R0, R1, R3, PC}

ledInitEnd:

		POP		{PC}					// Retun

		.size	ledInit, . - ledInit


/*------------------------------------------------------------------*/
		.type	led, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
		// R0: LEDoN or LEDoFF
led:
		PUSH	{LR}					// Save PC

		CMP		R0, #LEDoN
		BNE		ledOff					// Jump if (R0 != LEDoN)

ledOn:
		MOVS	R0,#1				// R1   = 0x01
		LSLS	R0,R0,#5			// R0 <<= 5
		ldr 	R1, =#PORTA_BSRR   	// Escribo la dirección de memoria para setear GPIOA
		STR 	R0, [R1]          	// Escribo el puerto de salida
									// LED ON
		B		ledEnd

ledOff:
        MOVS	R0,#1				// R1   = 0x01
		LSLS	R0,R0,#21			// R0 <<= 21
		LDR 	R1, =#PORTA_BSRR   	// Escribo la dirección de memoria para setear GPIOA
		STR 	R0, [R1]          	// Escribo el puerto de salida
										// LED OFF

ledEnd:
		POP		{PC}					// Return

		.size	led, . - led


/*------------------------------------------------------------------*/
		.type	delay, %function
		// R0, R1: argument / result / scratch register
		// R2, R3: argument / scratch register
		// R4 - R7: varaible register
		// R0: LEDdELAY
delay:
		PUSH	{LR}					// Save PC

delay0:
        SUBS	R0, 1					// R0 <- R0 - 1
        BNE		delay0					// Jump if (R0 != 0)

		POP		{PC}					// Return

delayEnd:

		.size	delay, . - delay


		.end
// .end marks the end of the assembly file. as does not process anything in
// the file past the .end directive.

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
