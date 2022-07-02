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

    tasks.h (Released 2022-06)

  --------------------------------------------------------------------

    - See tasks.s for details.

-*--------------------------------------------------------------------*/


#ifndef _TASKS_H_
#define _TASKS_H_ 1


// ------ Public constants -----------------------------------------

#define TEST_1 (1)	/* getLowerSigned   => Signed   Elements */
#define TEST_2 (2)	/* getLowerUnsigned => Unsigned Elements */
#define TEST_3 (3)	/* Test ................................ */
#define TEST_4 (4)	/* Test ................................ */
#define TEST_5 (5)	/* Test ................................ */
#define TEST_6 (6)	/* Test ................................ */


#define TEST_X (TEST_1)

#define NUMBoFeLEMENTSmAX	0x0000FFFF		// Lower Initial

#define SIZE_OF_WORD		0x04
#define SIZE_OF_HALF_WORD	0x02
#define SIZE_OF_BYTE		0x01


#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
