#include "bsp_led.h"

// #define testADDR 0x00000000
uint16_t timer_count;
uint8_t duty_cycle[] = {1,1,2,2,3,4,6,8,10,14,19,25,33,44,59,80,107,143,191,255,
					255,191,143,107,80,59,44,33,25,19,14,10,8,6,4,3,2,2,1,1};

void LED_Test()
{
	//定时器计数500次翻转
	if(timer_count == 500){
			timer_count = 0;
			HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);
			HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);
			//HAL_IWDG_Refresh(&hiwdg);			
		}
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);HAL_Delay(100);
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);HAL_Delay(100);
	
	HAL_GPIO_TogglePin(LED1_GPIO_Port,LED1_Pin);HAL_Delay(100);
	HAL_GPIO_TogglePin(LED2_GPIO_Port,LED2_Pin);HAL_Delay(100);
	HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);HAL_Delay(100);
	HAL_GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);HAL_Delay(100);
	HAL_GPIO_TogglePin(LED5_GPIO_Port,LED5_Pin);HAL_Delay(100);
	HAL_GPIO_TogglePin(LED6_GPIO_Port,LED6_Pin);HAL_Delay(100);
	HAL_GPIO_TogglePin(LED7_GPIO_Port,LED1_Pin);HAL_Delay(100);
}

//定时器中断callback函数,内部判断是哪个定时器实例
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM6){
		timer_count++;	//定时器6进行计数
	}
	else if(htim->Instance == TIM3){
		static uint8_t duty_cycle_index = 0;  /* 用于 PWM 查表 */
		static uint8_t period_cnt = 0;		/* 用于计算周期数 */
		//每20次中断计数修改一次占空比
		if(period_cnt++ >=20){
			period_cnt = 0;			
			TIM3->CCR3 = duty_cycle[duty_cycle_index];	
			if(duty_cycle_index++ >= 40){
				duty_cycle_index = 0;	
			}
		}		
	}	
}
/* 按键中断回调函数,在中断中喂狗,独立看门狗 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_PIN_2 == GPIO_Pin){
		HAL_IWDG_Refresh(&hiwdg);
	}
	HAL_GPIO_TogglePin(LED4_GPIO_Port,LED4_Pin);
}