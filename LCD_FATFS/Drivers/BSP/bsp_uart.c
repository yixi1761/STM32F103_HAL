#include "ls.h"

// #define testADDR 0x00000000
uint8_t uartRecvData[512];
uint8_t uartSendData[512];
uint8_t dmaData[512];

void UART_Test()
{
	
	HAL_UART_Receive_IT(&huart1, (uint8_t *)uartRecvData, 1);
	memset(uartSendData, 0x0a, 512);
	memset(dmaData, 0xda, 512);
	printf("UART TEST CODE 1-\n");
	HAL_UART_Transmit(&huart1, (uint8_t *)uartSendData, sizeof(sendData), 50);
  	HAL_UART_Transmit_DMA(&huart1, dmaData, sizeof(dmaData));
}

//串口回调函数， 判断接收内容控制相应的LED状态
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	HAL_UART_Transmit(&huart1, (uint8_t *)recdBuf, 1, 50);
	//再次开启接受中断
	ch = getchar();
	switch((int)ch){
		case '1':
			printf("接收到字符: %cOK\n",ch);
			HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
			break;
		case '2':
			printf("接收到字符: %cOK\n",ch);
			HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
			break;
		default:
			HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
			break;
	}
	HAL_UART_Receive_IT(&huart1, (uint8_t *)recdBuf, 1);
}
