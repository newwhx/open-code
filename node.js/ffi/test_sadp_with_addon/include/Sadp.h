#ifndef _SADP_H_
#define _SADP_H_


#if defined _WIN32 || defined _WIN64
#define CSADP_API  extern "C"__declspec(dllimport)
#elif defined __linux__ || defined __APPLE__
#define CSADP_API  extern "C"
#endif

#if defined _WIN32 || defined _WIN64
#define CALLBACK __stdcall
#elif defined __linux__ || defined __APPLE__
#define CALLBACK  
#endif

#define BOOL int

//��Ϣ����������
#define SADP_ADD		  1			//����һ�豸
#define SADP_UPDATE		  2			//�����豸
#define SADP_DEC		  3			//�豸����
#define SADP_RESTART	  4			//�豸��������
#define SADP_UPDATEFAIL	  5			//�豸����ʧ��

//�ⲿ������
#define SADP_GET_DEVICE_CODE   1			//��ȡ�豸�룬��Ӧ�ṹ��SADP_SAFE_CODE

#define MAX_DEVICE_CODE     128  //�豸�����볤�ȣ��ݶ����128
#define MAX_EXCHANGE_CODE   256  //�����볤��
#define MAX_PASS_LEN           16  //�豸������볤��
#define MAX_FILE_PATH_LEN      260 //�ļ����·������
#define MAX_ENCRYPT_CODE     256  //�豸��������ܺ󳤶�

// ������
#define SADP_ERROR_BASE					2000
#define SADP_NOERROR 					0					  // û�д���
#define SADP_ALLOC_RESOURCE_ERROR		(SADP_ERROR_BASE+1)   // ��Դ�������
#define SADP_NOT_START_ERROR			(SADP_ERROR_BASE+2)   // SADPδ����
#define SADP_NO_ADAPTER_ERROR			(SADP_ERROR_BASE+3)   // ������
#define SADP_GET_ADAPTER_FAIL_ERROR		(SADP_ERROR_BASE+4)   // ��ȡ������Ϣʧ��
#define SADP_PARAMETER_ERROR			(SADP_ERROR_BASE+5)   // ��������
#define SADP_OPEN_ADAPTER_FAIL_ERROR	(SADP_ERROR_BASE+6)   // ������ʧ��
#define SADP_SEND_PACKET_FAIL_ERROR		(SADP_ERROR_BASE+7)   // ��������ʧ��
#define SADP_SYSTEM_CALL_ERROR			(SADP_ERROR_BASE+8)   // ϵͳ�ӿڵ���ʧ��
#define SADP_DEVICE_DENY		        (SADP_ERROR_BASE+9)   // �豸�ܾ�����
#define SADP_NPF_INSTALL_ERROR			(SADP_ERROR_BASE+10)  // ��װNPF����ʧ��
#define SADP_TIMEOUT					(SADP_ERROR_BASE+11)  // �豸��ʱ
#define SADP_CREATE_SOCKET_ERROR		(SADP_ERROR_BASE+12)  // ����socketʧ��
#define SADP_BIND_SOCKET_ERROR			(SADP_ERROR_BASE+13)  // ��socketʧ��
#define SADP_JOIN_MULTI_CAST_ERROR		(SADP_ERROR_BASE+14)  // ����ಥ��ʧ��
#define SADP_NETWORK_SEND_ERROR			(SADP_ERROR_BASE+15)  // ���ͳ���
#define SADP_NETWORK_RECV_ERROR			(SADP_ERROR_BASE+16)  // ���ճ���
#define SADP_XML_PARSE_ERROR			(SADP_ERROR_BASE+17)  // �ಥXML��������
#define SADP_LOCKED						(SADP_ERROR_BASE+18)  // �豸����
#define SADP_NOT_ACTIVATED              (SADP_ERROR_BASE+19)  // �豸δ����
#define SADP_RISK_PASSWORD              (SADP_ERROR_BASE+20)  // ���ոߵ�����
#define SADP_HAS_ACTIVATED              (SADP_ERROR_BASE+21)  // �豸�Ѽ���

// �ṹ��
typedef struct tagSADP_DEVICE_INFO
{
	char			szSeries[12];
	char			szSerialNO[48];
	char			szMAC[20];
	char			szIPv4Address[16];
	char			szIPv4SubnetMask[16];
	unsigned int	dwDeviceType;
	unsigned int	dwPort;
	unsigned int	dwNumberOfEncoders; 
	unsigned int	dwNumberOfHardDisk;
	char			szDeviceSoftwareVersion[48];
	char			szDSPVersion[48]; 
	char			szBootTime[48];
	int				iResult;
	char			szDevDesc[24];       //�豸��������
	char			szOEMinfo[24];       //OEM������Ϣ
	char			szIPv4Gateway[16];   //IPv4����
	char			szIPv6Address[46];	 //IPv6��ַ
	char			szIPv6Gateway[46];   //IPv6����
	unsigned char   byIPv6MaskLen;       //IPv6����ǰ׺����
	unsigned char   bySupport;           //��λ��ʾ,��ӦΪΪ1��ʾ֧��,0x01:�Ƿ�֧��Ipv6,0x02:�Ƿ�֧���޸�Ipv6����,0x04:�Ƿ�֧��Dhcp	0x08: �Ƿ�֧��udp�ಥ 0x10:�Ƿ񺬼��ܽڵ�,0x20:�Ƿ�֧�ָֻ�����,0x40:�Ƿ�֧����������			 
	unsigned char   byDhcpEnabled;       //Dhcp״̬, 0 ������ 1 ����
	unsigned char   byDeviceAbility;	//0���豸��֧�֡����豸���������� 'OEM����' 'IPv4����' ��IPv6��ַ�� 'IPv6����' ��IPv6����ǰ׺����DHCP����  1��֧�����߹���
	unsigned short	wHttpPort;			// Http �˿�
	unsigned short	wDigitalChannelNum;
	char			szCmsIPv4[16];
	unsigned short	wCmsPort;
	unsigned char	byOEMCode;  //0-�����豸 1-OEM�豸
	unsigned char   byActivated; //�豸�Ƿ񼤻�;0-���1-δ����ϵ��豸�����Ѽ���״̬��
	char			szBaseDesc[24];	//���߶��ͺţ����涨�ƶ��޸ĵ��ͺţ�����өʯƽ̨�����ͺŶԱ�
	unsigned char   byRes[16];   
}SADP_DEVICE_INFO, *LPSADP_DEVICE_INFO;

//���޸ĵ��豸�������
typedef struct tagSADP_DEV_NET_PARAM
{
	char			szIPv4Address[16];		// IPv4��ַ
	char			szIPv4SubNetMask[16];	// IPv4��������
	char			szIPv4Gateway[16];		// IPv4����
	char			szIPv6Address[128];		// IPv6��ַ
	char			szIPv6Gateway[128];		// IPv6����
	unsigned short	wPort;					// �豸�����˿�
	unsigned char	byIPv6MaskLen;			// IPv6���볤��
	unsigned char	byDhcpEnable;			// DHCPʹ��
	unsigned short	wHttpPort;				//HTTP�˿�
	unsigned char	byRes[126];
}SADP_DEV_NET_PARAM, *LPSADP_DEV_NET_PARAM;


// CMS����
typedef struct tagSADP_CMS_PARAM
{
	char			szPUID[32];			// Ԥ�����PUID
	char			szPassword[16];		// ���õĵ�¼����
	char			szCmsIPv4[16];		// CMS������IPv4��ַ
	char			szCmsIPv6[128];		// CMS������IPv6��ַ
	unsigned short	wCmsPort;			// CMS�����������˿�
	unsigned char	byRes[30];
}SADP_CMS_PARAM, *LPSADP_CMS_PARAM;

//�豸��ȫ�룬��Ӧ��������SADP_GET_DEVICE_CODE���ӿ�SADP_GetDeviceConfig
typedef struct tagSADP_SAFE_CODE
{
	unsigned int    dwCodeSize;
	char            szDeviceCode[MAX_DEVICE_CODE];
	unsigned char   byRes[128];
}SADP_SAFE_CODE, *LPSADP_SAFE_CODE;
//�ָ�/��������ṹ��
typedef struct tagSADP_RESET_PARAM
{
    char            szCode[MAX_ENCRYPT_CODE]; //����ת�����������ַ�������ܹ��߼��ܺ���ַ��� - Ϊ�����Ͻӿ�
    char            szAuthFile[MAX_FILE_PATH_LEN];             //������Ȩ�ļ�
    char            szPassword[MAX_PASS_LEN];  //�û�����
    unsigned char   byRes[512];
}SADP_RESET_PARAM, *LSADP_RESET_PARAM;


// �ӿ�
typedef void (CALLBACK *PDEVICE_FIND_CALLBACK)(const SADP_DEVICE_INFO *lpDeviceInfo, void *pUserData);
CSADP_API BOOL CALLBACK SADP_Start_V30(PDEVICE_FIND_CALLBACK pDeviceFindCallBack, int bInstallNPF = 0, void* pUserData = NULL);
CSADP_API BOOL  CALLBACK SADP_SendInquiry(void);
CSADP_API BOOL  CALLBACK SADP_Stop(void);
CSADP_API BOOL CALLBACK SADP_ModifyDeviceNetParam(const char* sMAC, const char* sPassword, const SADP_DEV_NET_PARAM *lpNetParam);
CSADP_API unsigned int CALLBACK SADP_GetSadpVersion(void);
CSADP_API BOOL CALLBACK SADP_SetLogToFile(int nLogLevel=0, char const *strLogDir = NULL, int bAutoDel = 1);		
CSADP_API unsigned int CALLBACK SADP_GetLastError(void);
CSADP_API BOOL CALLBACK SADP_ResetDefaultPasswd(const char* sDevSerialNO, const char* sCommand);
CSADP_API BOOL CALLBACK SADP_SetCMSInfo(const char* sMac, const SADP_CMS_PARAM *lpCmsParam);
CSADP_API BOOL CALLBACK SADP_Clearup(void);
CSADP_API void CALLBACK SADP_SetAutoRequestInterval(unsigned int dwInterval);

CSADP_API BOOL CALLBACK SADP_GetDeviceConfig(const char* sDevSerialNO, unsigned int dwCommand,void* lpInBuffer, unsigned int  dwinBuffSize, void *lpOutBuffer, unsigned int  dwOutBuffSize);
//�����豸
CSADP_API BOOL CALLBACK SADP_ActivateDevice(const char* sDevSerialNO, const char* sCommand);

//��������ӿڣ�����֮ǰ�Ļָ�Ĭ������ӿ�
CSADP_API BOOL CALLBACK SADP_ResetPasswd(const char* sDevSerialNO, const SADP_RESET_PARAM *pResetParam);
#endif




