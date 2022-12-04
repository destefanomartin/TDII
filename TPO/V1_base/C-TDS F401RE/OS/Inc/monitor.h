/*
 * monitor.h
 *
 *  Created on: Oct 16, 2022
 *      Author: mpere
 */

#ifndef SRC_OS_MONITOR_H_
#define SRC_OS_MONITOR_H_

#include "main.h"
#include "stm32f4xx_hal_tim.h"
void MONITOR_I_Start(const uint32_t TASK_ID,
	    			  // Task Identier
					  const uint32_t TASK_WCET_us,
					  // Worst-case execution time (microseconds)
					  const uint32_t TASK_BCET_us,
					  // Best-case execution time (microseconds)
					  const uint32_t ALLOWED_TIMING_VARIATION_us);

uint32_t MONITOR_I_Stop(void);

void MONITOR_I_Disable(void);

void MONITOR_IRQHandler(void);

#endif /* SRC_OS_MONITOR_H_ */
