#include "bsp_sd.h"

#define testADDR 0x00000000
uint8_t recvData[512];
uint8_t sendData[512];
uint8_t buf[512];

void SDCard_Test()
{
	HAL_SD_CardCIDTypeDef SD_CID;
	HAL_SD_CardStateTypeDef SD_state;
	HAL_SD_CardInfoTypeDef SD_info;
	HAL_StatusTypeDef writeStatus;
	//读取SD卡基本信息
	SD_state = HAL_SD_GetCardState(&hsd);
	HAL_SD_GetCardCID(&hsd, &SD_CID);
	HAL_SD_GetCardInfo(&hsd, &SD_info);
	HAL_Delay(100);
	printf("SD state : %d\r\n" , SD_state);
	printf("SD ID    : %d  SN:%d \r\n",SD_CID.ManufacturerID, SD_CID.ProdSN);
	printf("SD TYPE  : %d\r\nclass: %d\r\nBLOCKNO: %d\r\nBLOCK_SIZE: %d\r\n", 
				SD_info.CardType, SD_info.Class, SD_info.BlockNbr, SD_info.BlockSize);
	//擦除一个block
	HAL_SD_Erase(&hsd, testADDR, testADDR);
	HAL_Delay(100);
	//read block	
	HAL_SD_ReadBlocks(&hsd, recvData, testADDR, 1, 1000);
	for(int i=0; i < 512; i++){
		printf("%x ", recvData[i]);
	}
	HAL_Delay(100);
	memset(sendData, 0x15, 512);
	//write block
	writeStatus = HAL_SD_WriteBlocks(&hsd, sendData, testADDR, 1, 1000);
	HAL_Delay(200);
	printf("\r\nwrite status is: %x\r\n", writeStatus);
	HAL_SD_ReadBlocks(&hsd, buf, testADDR, 1, 1000);
	for(int i=0; i < 512; i++){
		printf("%x ", buf[i]);
	}
}

