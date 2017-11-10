#include <stdio.h>
#include <iostream>
#include "../../Include/Sadp.h"


using namespace std;

int g_iDevicecount = 0;
void CALLBACK SadpDataCallBack(const SADP_DEVICE_INFO *lpDeviceInfo, void* pUserData)
{
	g_iDevicecount++;
	printf("new message ~~~~~~~~~~\n");
	printf("SerialNO	%s\n",  lpDeviceInfo->szSerialNO);
	printf("hwaddr		%s\n", lpDeviceInfo->szMAC);
	printf("praddr		%s\n", lpDeviceInfo->szIPv4Address);	
	printf("subnetmask	%s\n", lpDeviceInfo->szIPv4SubnetMask);
	printf("dev_type	%d\n", lpDeviceInfo->dwDeviceType);
	printf("port		%d\n", lpDeviceInfo->dwPort);
	printf("result		%d\n", lpDeviceInfo->iResult);
	printf("device count is %d\n", g_iDevicecount);
	printf("new message ~~~~~~~~~~\n\t");
}


int main (void)
{	
	int iCommand = 0;
	int iRet = SADP_Start_V30(SadpDataCallBack);
	if (iRet == 1)
	{
		printf("SADP_Start Succeed!\n");
	}
	else
	{
		printf("SADP_Start Failed!\n");
	}
	while (1)
	{
		cout<<"\n";
		cout<<"1:SendInquiry, 2:ModifyDeviceNetParam, 3:Activate device, 4:Get device code, 5:Reset Password, 6:final  \n";
		cin>>iCommand;
		SADP_DEV_NET_PARAM struNetParam = {0};
        SADP_SAFE_CODE struSafeCode = {0};
        SADP_RESET_PARAM struResetParam = {0};
        FILE * pFile = NULL;
        int iErrorCode = 0;
		switch (iCommand)
		{
		case 1:
            iRet = SADP_SendInquiry();
            if (iRet == 1)
            {
                printf("SADP_SendInquiry Succeed!\n");
            }
            else
            {
                printf("SADP_SendInquiry Failed!\n");
            }
            break;

		case 2:
            memcpy(struNetParam.szIPv4Address, "10.17.132.25", 16);
            memcpy(struNetParam.szIPv4Gateway, "10.17.132.254", 16);
            memcpy(struNetParam.szIPv4SubNetMask, "255.255.255.0", 16);
            struNetParam.wHttpPort = 80;
            struNetParam.wPort = 8001;
                //struNetParam.szIPv4Address = "10.17.133.3";
                
            iRet = SADP_ModifyDeviceNetParam("8c-e7-48-d4-97-67", "hik12345",&struNetParam);
            if (iRet == 1)
            {
                printf("SADP_ModifyDeviceNetParam Succeed!\n");
            }
            else
            {
                iErrorCode = SADP_GetLastError();
                printf("SADP_ModifyDeviceNetParam Failed, ErrorCode is %d!\n", iErrorCode);
            }
            break;
            
        case 3:
            iRet = SADP_ActivateDevice("DS-2CD2712F-IS20130226CCCH417358690", "hik12345");
            if (iRet == 1)
            {
                printf("SADP_ActivateDevice Succeed!\n");
            }
            else
            {
                iErrorCode = SADP_GetLastError();
                printf("SADP_ActivateDevice Failed, ErrorCode is %d!\n", iErrorCode);
            }
            break;
        case 4:
            //get device code
            iRet = SADP_GetDeviceConfig("DS-2CD2712F-IS20130226CCCH417358690", 1, NULL, 0, &struSafeCode, sizeof(struSafeCode));
            if (!iRet)
            {
                iErrorCode = SADP_GetLastError();
                printf("SADP_GetDeviceConfig Failed, ErrorCode is %d!\n", iErrorCode);
            }
            else
            {
                printf("the safe code is %s\r\n", struSafeCode.szDeviceCode);
            }
            //write file
            pFile = fopen("./DeviceKey.xml", "wb");
            if(pFile == NULL)
            {
                printf("fopen Failed!\n");
            }
            fwrite(struSafeCode.szDeviceCode,sizeof(char), strlen(struSafeCode.szDeviceCode), pFile);
            if(NULL != pFile)
            {
                fclose(pFile);
                pFile = NULL;
            }
            
            
            break;
        case 5:
            memcpy(struResetParam.szPassword, "hik12345", 16);
            memcpy(struResetParam.szAuthFile, "./Encrypt.xml", 160);
            iRet = SADP_ResetPasswd("DS-2CD2712F-IS20130226CCCH417358690", &struResetParam);
            if (iRet == 1)
            {
                printf("SADP_ResetPasswd success!\r\n");
            }
            else
            {
                iErrorCode = SADP_GetLastError();
                printf("SADP_ResetPasswd failed, ErrorCode is %d", iErrorCode);
            }
            break;
        case 6:
            iRet = SADP_Stop();
            if (iRet == 1)
            {
                printf("SADP_Stop Succeed!\n");
            }
            else
            {
                printf("SADP_Stop Failed!\n");
            }
            return 1;
        default:
            cout<<"error command\n";
            break;			
        }				
    }	
    
    return 1;
}
