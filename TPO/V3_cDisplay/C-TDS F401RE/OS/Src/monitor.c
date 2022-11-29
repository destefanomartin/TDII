#include "monitor.h"

extern TIM_HandleTypeDef htim11;

static uint32_t Task_ID_G;
static uint32_t Task_BCET_G;
static uint32_t Task_t_variation_G;

static uint8_t TimerInitFlag = 0;

void MONITOR_I_Start(const uint32_t TASK_ID,
					  const uint32_t TASK_WCET_us,
					  const uint32_t TASK_BCET_us,
					  const uint32_t ALLOWED_TIMING_VARIATION_us)
{
	Task_ID_G = TASK_ID;
	Task_BCET_G = TASK_BCET_us;
	Task_t_variation_G = ALLOWED_TIMING_VARIATION_us;

	TimerInitFlag = 1;
	HAL_TIM_Base_DeInit(&htim11);
	htim11.Init.Period = TASK_WCET_us + ALLOWED_TIMING_VARIATION_us;
	HAL_TIM_Base_Init(&htim11);

	HAL_TIM_Base_Start_IT(&htim11);
}

uint32_t MONITOR_I_Stop(void)
{
	uint32_t Execution_time_us;
	sTask *actual;

	// Check BCET (read timer value)
	// This value is in microseconds
	Execution_time_us = __HAL_TIM_GET_COUNTER(&htim11);

	// Stop the timer
	HAL_TIM_Base_Stop_IT(&htim11);

	if ((Execution_time_us + Task_t_variation_G) < Task_BCET_G)
	{
		// Task has completed too quickly
		// => Change mode
		SYSTEM_Change_Mode_Fault(FAULT_TASK_TIMING);

		// Not storing task ID here
		// Not distinguishing BCET / WCET faults
		// => either / both this can be done here, if required
		actual = SCH_Get_Current_Task_Pointer();
		actual->Debug.BCET = Execution_time_us;
		actual->Debug.LET = Execution_time_us;
		actual->Debug.State |= SCH_DEBUG_TASK_UNDERRUN;
	}

	return Execution_time_us;
}

void MONITOR_I_Disable(void)
{
	HAL_TIM_Base_Stop_IT(&htim11);
}

void MONITOR_IRQHandler(void)
{
	if(TimerInitFlag)
	{
		TimerInitFlag = 0;
		return;
	}
	sTask *actual;
	// Task has completed too slowly
	// => Change mode
	SYSTEM_Change_Mode_Fault(FAULT_TASK_TIMING);

	// Not storing task ID here
	// Not distinguishing BCET / WCET faults
	// => either / both this can be done here, if required
	actual = SCH_Get_Current_Task_Pointer();
	actual->Debug.LET = actual->WCET;
	actual->Debug.WCET = actual->WCET;
	actual->Debug.State |= SCH_DEBUG_TASK_OVERRUN;
}
