/*
 * config_stm32f401.h
 *
 *  Created on: Oct 19, 2022
 *      Author: Flia König
 */


#ifndef INC_PIN_FUNCTIONS_STM32F401_H_
#define INC_PIN_FUNCTIONS_STM32F401_H_


#include "main.h"


void Pin_Config(GPIO_TypeDef *port, uint32_t pin, uint32_t mode, uint32_t pull, uint32_t speed);
void Pin_Write(GPIO_TypeDef *port, uint32_t pin, uint32_t state);
void Pin_Toggle(GPIO_TypeDef *port, uint32_t pin);
GPIO_PinState Pin_Read(GPIO_TypeDef *port, uint32_t pin);



#endif /* INC_PIN_FUNCTIONS_STM32F401_H_ */
