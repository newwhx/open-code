#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/Sadp.h"
extern "C" {
#define TRUE  (1)
#define FALSE (0)
#define MAX_DEVICE_CNT 2
		PDEVICE_FIND_CALLBACK pDeviceFindCallBack = NULL;
		void *pUserData = NULL;
		BOOL CALLBACK SADP_Start_V30(PDEVICE_FIND_CALLBACK pCallBack, int bInstallNPF , void *pData)
		{
				printf("In the SADP_start_V30 func\n");
				pDeviceFindCallBack = pCallBack;
				pUserData = pData;
				return 2;
		}


		BOOL  CALLBACK SADP_SendInquiry(void)
		{
				int i = 0;
				SADP_DEVICE_INFO *pDeviceInfo = NULL;

				printf("In the SADP_SendInquiry func\n");
				pDeviceInfo = (SADP_DEVICE_INFO *) malloc(sizeof(SADP_DEVICE_INFO));
				if (NULL == pDeviceInfo) {
						return FALSE;
				}
				memset(pDeviceInfo, 0, sizeof(SADP_DEVICE_INFO));

				for (i = 0; i < MAX_DEVICE_CNT; ++i) {
						memcpy(pDeviceInfo->szSeries, "1234567", sizeof(pDeviceInfo->szSeries));
						pDeviceInfo->dwDeviceType = i+10;
						memcpy(pDeviceInfo->szIPv4Address, "192.168.8.199", sizeof(pDeviceInfo->szIPv4Address));
						pDeviceInfo->dwPort = i;
						memcpy(pDeviceInfo->szIPv4SubnetMask, "255.255.255.0", sizeof(pDeviceInfo->szIPv4SubnetMask));
						memcpy(pDeviceInfo->szIPv4Gateway, "192.168.8.1", sizeof(pDeviceInfo->szIPv4Gateway));
						pDeviceFindCallBack(pDeviceInfo, pUserData);	
						printf("if pUserData is null: %d, and the address: %x\n", (pUserData ==  NULL), pUserData);
				}

				free(pDeviceInfo);
				pDeviceInfo = NULL;

				return TRUE;

		}
}
