#include <stdio.h>
#include <iostream>
#include <node.h>
#include "../include/Sadp.h"

using namespace std;
#define MAX_DEVICE_CNT 100


int g_iDeviceCnt = 0;
void CALLBACK SadpDataCallBack(const SADP_DEVICE_INFO *lpDeviceInfo, void* pUserData)
{
		printf("new message ~~~~~~~~~~\n");
		printf("SerialNO	%s\n", lpDeviceInfo->szSerialNO);
		printf("hwaddr		%s\n", lpDeviceInfo->szMAC);
		printf("praddr		%s\n", lpDeviceInfo->szIPv4Address);	
		printf("subnetmask	%s\n", lpDeviceInfo->szIPv4SubnetMask);
		printf("dev_type	%d\n", lpDeviceInfo->dwDeviceType);
		printf("port		%d\n", lpDeviceInfo->dwPort);
		printf("result		%d\n", lpDeviceInfo->iResult);
		printf("deviceCnt   %d\n", g_iDeviceCnt);
		printf("new message ~~~~~~~~~~\n\t");
}

int inquiry(SADP_DEVICE_INFO astDevices[], int iMaxDeviceCnt)
{
		int iRet = 0;
		g_iDeviceCnt = 0;

		iRet = SADP_Start_V30(SadpDataCallBack, 0, (void *)&astDevices);	
		if (iRet == 1)
		{
				printf("SADP_Start Succeed!\n");
		}
		else
		{
				printf("SADP_Start Failed!\n");
		}

		iRet = SADP_SendInquiry();
		if (iRet == 1)
		{
				printf("SADP_SendInquiry Succeed!\n");
		}
		else
		{
				printf("SADP_SendInquiry Failed!\n");
		}

		return g_iDeviceCnt;
}

int main(int argc, char *argv[])
{
		SADP_DEVICE_INFO astDevices[MAX_DEVICE_CNT] = {0};
		printf("get %d devices on line\n", inquiry(astDevices, MAX_DEVICE_CNT));
		return 0;
}
