/*
 * config_stm32f401.c
 *
 *  Created on: Oct 19, 2022
 *      Author: Flia König
 */

#include <pin_functions_stm32f401.h>

void Pin_Config(GPIO_TypeDef *port, uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed)
{
	GPIO_InitTypeDef  GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = pin;
	GPIO_InitStruct.Mode = mode;
	GPIO_InitStruct.Pull = pull;
	GPIO_InitStruct.Speed = speed;
	HAL_GPIO_Init(port, &GPIO_InitStruct);
}

void Pin_Write(GPIO_TypeDef *port, uint32_t pin, uint32_t state)
{
	HAL_GPIO_WritePin(port, pin, state);
}

void Pin_Toggle(GPIO_TypeDef *port, uint32_t pin)
{
	HAL_GPIO_TogglePin(port, pin);
}

GPIO_PinState Pin_Read(GPIO_TypeDef *port, uint32_t pin)
{
	return HAL_GPIO_ReadPin(port, pin);
}
