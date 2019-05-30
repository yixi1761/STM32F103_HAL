#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f1xx.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_iwdg.h"
#include "iwdg.h"

#include "string.h"



void LED_Test(void);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif

