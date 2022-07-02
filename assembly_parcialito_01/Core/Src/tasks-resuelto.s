/* Copyright 2020, Juan Manuel Cruz.
 * All rights reserved.
 *
 * This file is part of Project => parcial-assembly-project.
 *    https://gitlab.frba.utn.edu.ar/R-TDII/parcial-assembly-project
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

    tasks.s (Released 2022-06)

--------------------------------------------------------------------

    tasks file for Assembly Programming - Project for STM32F401RE.

    See readme.txt for project information.

-*--------------------------------------------------------------------*/


// Task header
#include "..\Inc\tasks.h"


/*------------------------------------------------------------------*/
		.syntax		unified
	    .arch       armv7-m
		.cpu		cortex-m0
		.thumb

		.section	.text
		.align		2


#if (TEST_X == TEST_1)	/* getLowerSigned => Signed Elements */
/*------------------------------------------------------------------*/
		.global getLowerSigned
		.type getLowerSigned, %function
		// R0, R1: argument / result / scratch register
		// R2, R4: argument / scratch register
		// R5 - R7: varaible register

		// R0 <- adress of array
		// R1 <- size of elements
		// R2 <- number of elemnts

getLowerSigned:

		PUSH	{R4, R5, R6}					// Save R4

        LDR 	R7, [R0]


		CMP     R1, #SIZE_OF_WORD
        BEQ     getElement

		LDRSH 	R7, [R0]

        CMP     R1, #SIZE_OF_HALF_WORD
        BEQ     getElement

		LDRSB 	R7,[R0]

        CMP     R1, #SIZE_OF_BYTE
        BEQ     getElement


getElement:


        LDR     R6, [R0]

        CMP     R1, #SIZE_OF_WORD
        BEQ     getElementEnd

        LDRSH   R6, [R0]

        CMP     R1, #SIZE_OF_HALF_WORD
        BEQ     getElementEnd

        LDRSB   R6, [R0]

        CMP     R1, #SIZE_OF_BYTE
        BEQ     getElementEnd

getElementEnd:

Compare:
        CMP     R6, R7
        BLT     LowerDetected

		B		Increment

LowerDetected:

        MOVS    R7, R6

Increment:

        ADDS R0, R0, R1
        SUBS R2, R2, #1
        BNE  getElement


getLowerSignedEnd:
		MOVS		R0, R7		// R0 <- 0x80000000 = Lower

		POP	 	{R5, R6, R7}					// Restore R4

		BX 		LR						// Retun

		.size	getLowerSigned, . - getLowerSigned

#endif


#if (TEST_X == TEST_2)	/* getLowerUnsigned => Unsigned Elements */
/*------------------------------------------------------------------*/
		.global getLowerUnsigned
		.type getLowerUnsigned, %function
		// R0, R1: argument / result / scratch register
		// R2, R4: argument / scratch register
		// R5 - R7: varaible register

		// R0 <- adress of array
		// R1 <- size of elements
		// R2 <- number of elemnts

getLowerUnsigned:

		PUSH	{R4}					// Save R4

		MOVS	R4, #1					// R4 <- 1


getLowerUnsignedEnd:
		LDR		R0, =0x00000000			// R0 <- 0x00000000 = Lower

		POP	 	{R4}					// Restore R4

		BX 		LR						// Retun

		.size	getLowerUnsigned, . - getLowerUnsigned

#endif


		.end
// .end marks the end of the assembly file. as does not process anything in
// the file past the .end directive.

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
