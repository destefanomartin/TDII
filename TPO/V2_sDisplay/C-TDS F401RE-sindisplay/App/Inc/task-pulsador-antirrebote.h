/*
 * task-pulsador-antirrebote.h
 *
 *  Created on: 3 nov. 2022
 *      Author: Flia König
 */

#ifndef INC_TASK_PULSADOR_ANTIRREBOTE_H_
#define INC_TASK_PULSADOR_ANTIRREBOTE_H_

#include "main.h"

#define ANTIRREBOTE_Pin B1_Pin
#define ANTIRREBOTE_Port B1_GPIO_Port

void ANTIRREBOTE_Init(void);
void ANTIRREBOTE_Update(void);

#endif /* INC_TASK_PULSADOR_ANTIRREBOTE_H_ */
