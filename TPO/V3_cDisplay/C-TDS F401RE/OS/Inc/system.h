#ifndef _SYSTEM_H
#define _SYSTEM_H 1

#include "main.h"
#include "task-heartbeat.h"
#include "task-watchdog.h"
#include "task-pulsador-falla.h"
#include "task-audio-processing.h"
#include "task-display.h"
#include "task-mediciones.h"

#define RETURN_NORMAL 0
#define RETURN_FAULT 1

typedef enum {FAIL_SILENT, NORMAL, FAULT_TASK_TIMING} eSystem_mode;

void SYSTEM_Init(void);
void SYSTEM_Perform_Safe_Shutdown(void);
eSystem_mode SYSTEM_Get_Mode(void);
void SYSTEM_Change_Mode_Fault(eSystem_mode mode);

#define FAULT_SCH_TOO_MANY_TASKS (1)
#define FAULT_SCH_ONE_SHOT_TASK (2)

#define SysTick_RateHz	(1000)
#define Required_SystemCoreClock (84000000)

#endif
