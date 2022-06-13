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

    tasks.h (Released 2020-01)

  --------------------------------------------------------------------

    - See tasks.c for details.

-*--------------------------------------------------------------------*/


#ifndef _TASKS_H_
#define _TASKS_H_ 1


// ------ Public constants -----------------------------------------
#define LED_MASK	0x00400000
#define PINSEL1		0x4002C004
#define FIO0DIR		0x2009C000
#define FIO0MASK	0x2009C010
#define FIO0PIN		0x2009C014
#define FIO0SET		0x2009C018
#define FIO0CLR		0x2009C01C


#define LEDdELAY	200000
#define LEDoNdELAY	LEDdELAY
#define LEDoFFdELAY	(LEDdELAY * 2)

#define LEDoFF	false
#define LEDoN	true

#define RCC_AHB1ENR 0x40023830
#define GPIOAEN		0x1
#define PORTA_MODER 0x40020000
#define PORTA_BSRR	0x40020018


#endif

/*------------------------------------------------------------------*-
  ---- END OF FILE -------------------------------------------------
-*------------------------------------------------------------------*/
