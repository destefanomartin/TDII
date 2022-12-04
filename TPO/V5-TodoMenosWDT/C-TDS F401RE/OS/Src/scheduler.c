#include "scheduler.h"
#include <string.h>

uint32_t Fault_code_G;
sTask SCH_tasks_G[SCH_MAX_TASKS];

#define	ALLOWED_TIMING_VARIATION_us (20)

static volatile uint32_t Tick_count_G = 0;

static volatile uint32_t ITask;

static void SCH_Go_To_Sleep(void);

void SysTick_Handler(void);

void SCH_Dispatch_Tasks(void) {
	uint32_t Index;
	uint32_t Update_required = 0;
	uint32_t time_SCH;

	__disable_irq(); // Protect shared resource (Tick_count_G)
	if (Tick_count_G > 0)
		{
		Tick_count_G--;
		Update_required = 1;
	}
	__enable_irq();

	while (Update_required)
		{
		// Go through the task array
		for (Index = 0; Index < SCH_MAX_TASKS; Index++)
			{
			// Check if there is a task at this location
			if (SCH_tasks_G[Index].pTask)
				{
				if (--SCH_tasks_G[Index].Delay == 0)
					{
						// Start of Task Dispatch Time Measurement
						DWT_Clear();

						ITask = Index;
						SCH_tasks_G[Index].Debug.State = 0;

						MONITOR_I_Start((uint32_t)SCH_tasks_G[Index].pTask,
								SCH_tasks_G[Index].WCET,
								SCH_tasks_G[Index].BCET,
								ALLOWED_TIMING_VARIATION_us);

						(*SCH_tasks_G[Index].pTask)(); // Run the task

						// All tasks are periodic in this design
						// - schedule task to run again

						SCH_tasks_G[Index].Debug.LET = MONITOR_I_Stop();
						SCH_tasks_G[Index].Debug.State |= SCH_DEBUG_TASK_RUN_OK;
						SCH_tasks_G[Index].Debug.RunTimes++;

						if(SCH_tasks_G[Index].Debug.LET < SCH_tasks_G[Index].Debug.BCET)
							SCH_tasks_G[Index].Debug.BCET = SCH_tasks_G[Index].Debug.LET;

						if(SCH_tasks_G[Index].Debug.LET > SCH_tasks_G[Index].Debug.WCET)
							SCH_tasks_G[Index].Debug.WCET = SCH_tasks_G[Index].Debug.LET;

						SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;

						// Stop of Task Dispatch Time Measurement
						time_SCH = DWT_GetTime()/1000 - SCH_tasks_G[Index].Debug.LET;
					}
				}
			}
		__disable_irq();
		if (Tick_count_G > 0)
			{
			Tick_count_G--;
			Update_required = 1;
			}
		else
			{
			Update_required = 0;
			}
		__enable_irq();
		}

		if(SYSTEM_Get_Mode() == FAIL_SILENT)
		{
			MONITOR_I_Disable();
			SYSTEM_Perform_Safe_Shutdown();
		}
	SCH_Go_To_Sleep();
}

void SCH_Init(const uint32_t TICKms)
{
    int i;
    // Reset the global fault variable
    Fault_code_G = 0;

    for (i = 0; i < SCH_MAX_TASKS; i++)
    {
    	SCH_tasks_G[i].pTask = 0;
    	memset(&(SCH_tasks_G[i].Debug),0,sizeof(debugInfo));
    }


    // Must check board oscillator frequency, etc
    //
    // *If* these values have been set correctly for your hardware
    // SystemCoreClock gives the system operating frequency (in Hz)
    if (SystemCoreClock != Required_SystemCoreClock)
    {
    	// Fatal fault
    	SYSTEM_Perform_Safe_Shutdown();
    }

    // Now to set up SysTick timer for "ticks" at interval TICKms
    if (SysTick_Config(TICKms * SystemCoreClock / SysTick_RateHz))
    {
    	// Fatal fault
    	SYSTEM_Perform_Safe_Shutdown();
    }

    NVIC_SetPriority(SysTick_IRQn, 0x0);

    // Timer is started by SysTick_Config():
    // we need to disable SysTick timer and SysTick interrupt until
    // all tasks have been added to the schedule.
    SysTick->CTRL &= 0xFFFFFFFC;

    // Inicialize Data Watchpoint and Trace System Clock Counter
    DWT_Init();
}

void SCH_Start(void)
{
    // Enable SysTick timer
    SysTick->CTRL |= 0x01;

    // Enable SysTick interrupt
    SysTick->CTRL |= 0x02;
}

void SCH_Go_To_Sleep()
{
	// Enter sleep mode = "Wait For Interrupt"
	__WFI();
}

uint32_t SCH_Add_Task(void (* pTask)(),
					  const uint32_t DELAY,
					  const uint32_t PERIOD,
					  const uint32_t WCET,
					  const uint32_t BCET
					  )

	{
	uint32_t Return_value = 0;
	uint32_t Index = 0;

	// First find a gap in the array (if there is one)
	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
		{
		Index++;
	}

	// Have we reached the end of the list?
	if (Index == SCH_MAX_TASKS)
		{
		// Task list is full
		//
		// Set the global fault variable
		Fault_code_G = FAULT_SCH_TOO_MANY_TASKS;

		// Also return a fault code
		Return_value = SCH_MAX_TASKS;
		}

	// Check for "one shot" tasks
	// - not permitted in this design
	if (PERIOD == 0)
		{
		// Set the global fault variable
		Fault_code_G = FAULT_SCH_ONE_SHOT_TASK;

		// Also return a fault code
		Return_value = SCH_MAX_TASKS;
		}

	if (Return_value != SCH_MAX_TASKS)
		{

		// If we're here, there is a space in the task array
		// and the task to be added is periodic
		SCH_tasks_G[Index].pTask = pTask;

		SCH_tasks_G[Index].Delay = DELAY + 1;
		SCH_tasks_G[Index].Period = PERIOD;
		SCH_tasks_G[Index].WCET = WCET;
		SCH_tasks_G[Index].BCET = BCET;

		SCH_tasks_G[Index].Debug.LET = 0;
		SCH_tasks_G[Index].Debug.WCET = 0;
		SCH_tasks_G[Index].Debug.BCET = 0xFFFFFFFF;
		SCH_tasks_G[Index].Debug.State = 0;
		SCH_tasks_G[Index].Debug.RunTimes = 0;

		Return_value = Index;
		}

	return Return_value;
}

void SCH_SysTick_Handler(void)
{
    // Increment tick count (only)
    Tick_count_G++;
}

sTask* SCH_Get_Current_Task_Pointer(void)
{
	return &SCH_tasks_G[ITask];
}
