#ifndef _SCHEDULER_H
#define _SCHEDULER_H 1

#include "main.h"

#define SCH_MAX_TASKS (20)

#define SCH_DEBUG_TASK_RUN_OK		(1<<0)
#define SCH_DEBUG_TASK_UNDERRUN		(1<<1)
#define SCH_DEBUG_TASK_OVERRUN		(1<<2)

typedef struct
{
    int WCET;
    int BCET;
    int LET;
    int RunTimes;
    int State;
} debugInfo;

typedef struct
{
	// Pointer to the task (must be a 'void (void)' function)
	void (*pTask) (void);
	// Delay (ticks) until the task will (next) be run
	// - see SCH_Add_Task() for further details
	uint32_t Delay;
	// Interval (ticks) between subsequent runs.
	// - see SCH_Add_Task() for further details
	uint32_t Period;
	// Worst-case execution time (microseconds)
	uint32_t WCET;
	// Best-case execution time (microseconds)
	uint32_t BCET;
	//Debug Info.
	debugInfo Debug;
} sTask;

void SCH_Start(void);
void SCH_Dispatch_Tasks(void);
void SCH_Init(const uint32_t TICKms);
uint32_t SCH_Add_Task(void (* pTask)(),
                      const uint32_t DELAY,		// Offset (in ticks)
                      const uint32_t PERIOD,	// Ticks
                      const uint32_t WCET,		// Microseconds
                      const uint32_t BCET		// Microseconds
);
void SCH_SysTick_Handler(void);
sTask* SCH_Get_Current_Task_Pointer(void);

static inline void DWT_Init(void)
{
	DWT->CTRL |=DWT_CTRL_CYCCNTENA_Msk;
	DWT->CYCCNT=0;
}

static inline uint32_t DWT_GetTime(void)
{
	return (10 * DWT->CYCCNT);		// (10E9 / SystemCoreClock) => nS
}

static inline void DWT_Clear(void)
{
	DWT->CYCCNT=0;
}

#endif

