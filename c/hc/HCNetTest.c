#include <stdio.h>
#include "./include/HCNetSDK.h"


int main(int argc, char *argv[])
{
		char strIP[16][16];
		DWORD ulValidNum = 0;
		BOOL  bEnableBind = false;

		// initialized
		NET_DVR_Init();
		NET_DVR_SetConnectTime(2000, 1);
		net_dvr_SetReconnect(1000, true);

		if (NET_DVR_GetLocalIP(strIp, &ulValidNum, &bEnableBind)) {
			printf("get ip success: ulValidNum(%d), bEnableBind(%d)", ulValidNum, bEnableBind);	
		}else{
			printf("get ip Fail: ulValidNum(%d), bEnableBind(%d)", ulValidNum, bEnableBind);	
		}


		return 0;
}
