/*
 * task-display.h
 *
 *  Created on: 2 dic. 2022
 *      Author: Flia König
 */

#ifndef INC_TASK_DISPLAY_H_
#define INC_TASK_DISPLAY_H_

#include "main.h"


void DISPLAY_Init(uint8_t rows);
void DISPLAY_Update();


/* Function Set */
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

#endif /* INC_TASK_DISPLAY_H_ */
