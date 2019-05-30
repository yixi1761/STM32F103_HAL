#include "bsp_iic_24c02.h"

#define DevReadAddr 0XA0	//A0写 A1读
#define DevWriteAddr 0XA1	//貌似可以把读写地址设置为同一个，读写函数会自动修改末位
#define TestAddr 0X00 	//0x00 ~ 0xff
uint8_t IIC_BUF[5] = {0X00, 0X01, 0X02, 0X04, 0XAA};
uint8_t IIC_rBUF[15];

void IIC_24C02_Test()
{
	HAL_I2C_Mem_Read(&hi2c2, WriteAddr, TestAddr, 15, IIC_rBUF, 15, 100);
	printf("原始读取数据是:\r\n");
	for(int i=0;i<15;i++){
		printf("%x \r", IIC_rBUF[i]);    
	}
	printf("\r\n \r\n");
	HAL_I2C_Mem_Write(&hi2c2, ReadAddr, TestAddr, 1, IIC_BUF, 5, 100);HAL_Delay(100);
	HAL_I2C_Mem_Read(&hi2c2, WriteAddr, TestAddr, 15, IIC_rBUF, 15, 100);
	printf("写入后读取数据是:\r\n");
	for(int i=0;i<15;i++){
		printf("%x \r", IIC_rBUF[i]);
	}
	printf("\r\n \r\n");
}

