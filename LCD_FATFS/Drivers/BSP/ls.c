#include "ls.h"

#define testADDR 0x00000000
uint8_t recvData[512];
uint8_t sendData[512];
uint8_t buf[512];

void SDCard_Test()
{
	
	for(int i=0; i < 512; i++){
		printf("%x ", buf[i]);
	}
}

