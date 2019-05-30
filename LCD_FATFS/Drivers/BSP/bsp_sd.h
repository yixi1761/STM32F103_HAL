#ifndef _BSP_SD_H
#define _BSP_SD_H

#include "stm32f1xx.h"
#include "stm32f1xx_hal_sd.h"
#include "sdio.h"
#include "string.h"


//擦除addr所在的扇区
void SDCard_Test(void);
#endif

