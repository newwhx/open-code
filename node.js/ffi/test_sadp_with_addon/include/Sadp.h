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

//消息操作的类型
#define SADP_ADD		  1			//增加一设备
#define SADP_UPDATE		  2			//更新设备
#define SADP_DEC		  3			//设备下线
#define SADP_RESTART	  4			//设备重新启动
#define SADP_UPDATEFAIL	  5			//设备更新失败

//外部命令码
#define SADP_GET_DEVICE_CODE   1			//获取设备码，对应结构体SADP_SAFE_CODE

#define MAX_DEVICE_CODE     128  //设备返回码长度，暂定最大128
#define MAX_EXCHANGE_CODE   256  //交换码长度
#define MAX_PASS_LEN           16  //设备最大密码长度
#define MAX_FILE_PATH_LEN      260 //文件最大路径长度
#define MAX_ENCRYPT_CODE     256  //设备返回码加密后长度

// 错误码
#define SADP_ERROR_BASE					2000
#define SADP_NOERROR 					0					  // 没有错误
#define SADP_ALLOC_RESOURCE_ERROR		(SADP_ERROR_BASE+1)   // 资源分配错误
#define SADP_NOT_START_ERROR			(SADP_ERROR_BASE+2)   // SADP未启动
#define SADP_NO_ADAPTER_ERROR			(SADP_ERROR_BASE+3)   // 无网卡
#define SADP_GET_ADAPTER_FAIL_ERROR		(SADP_ERROR_BASE+4)   // 获取网卡信息失败
#define SADP_PARAMETER_ERROR			(SADP_ERROR_BASE+5)   // 参数错误
#define SADP_OPEN_ADAPTER_FAIL_ERROR	(SADP_ERROR_BASE+6)   // 打开网卡失败
#define SADP_SEND_PACKET_FAIL_ERROR		(SADP_ERROR_BASE+7)   // 发送数据失败
#define SADP_SYSTEM_CALL_ERROR			(SADP_ERROR_BASE+8)   // 系统接口调用失败
#define SADP_DEVICE_DENY		        (SADP_ERROR_BASE+9)   // 设备拒绝处理
#define SADP_NPF_INSTALL_ERROR			(SADP_ERROR_BASE+10)  // 安装NPF服务失败
#define SADP_TIMEOUT					(SADP_ERROR_BASE+11)  // 设备超时
#define SADP_CREATE_SOCKET_ERROR		(SADP_ERROR_BASE+12)  // 创建socket失败
#define SADP_BIND_SOCKET_ERROR			(SADP_ERROR_BASE+13)  // 绑定socket失败
#define SADP_JOIN_MULTI_CAST_ERROR		(SADP_ERROR_BASE+14)  // 加入多播组失败
#define SADP_NETWORK_SEND_ERROR			(SADP_ERROR_BASE+15)  // 发送出错
#define SADP_NETWORK_RECV_ERROR			(SADP_ERROR_BASE+16)  // 接收出错
#define SADP_XML_PARSE_ERROR			(SADP_ERROR_BASE+17)  // 多播XML解析出错
#define SADP_LOCKED						(SADP_ERROR_BASE+18)  // 设备锁定
#define SADP_NOT_ACTIVATED              (SADP_ERROR_BASE+19)  // 设备未激活
#define SADP_RISK_PASSWORD              (SADP_ERROR_BASE+20)  // 风险高的密码
#define SADP_HAS_ACTIVATED              (SADP_ERROR_BASE+21)  // 设备已激活

// 结构体
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
	char			szDevDesc[24];       //设备类型描述
	char			szOEMinfo[24];       //OEM产商信息
	char			szIPv4Gateway[16];   //IPv4网关
	char			szIPv6Address[46];	 //IPv6地址
	char			szIPv6Gateway[46];   //IPv6网关
	unsigned char   byIPv6MaskLen;       //IPv6子网前缀长度
	unsigned char   bySupport;           //按位表示,对应为为1表示支持,0x01:是否支持Ipv6,0x02:是否支持修改Ipv6参数,0x04:是否支持Dhcp	0x08: 是否支持udp多播 0x10:是否含加密节点,0x20:是否支持恢复密码,0x40:是否支持重置密码			 
	unsigned char   byDhcpEnabled;       //Dhcp状态, 0 不启用 1 启用
	unsigned char   byDeviceAbility;	//0：设备不支持“‘设备类型描述’ 'OEM厂商' 'IPv4网关' ‘IPv6地址’ 'IPv6网关' ‘IPv6子网前缀’‘DHCP’”  1：支持上诉功能
	unsigned short	wHttpPort;			// Http 端口
	unsigned short	wDigitalChannelNum;
	char			szCmsIPv4[16];
	unsigned short	wCmsPort;
	unsigned char	byOEMCode;  //0-基线设备 1-OEM设备
	unsigned char   byActivated; //设备是否激活;0-激活，1-未激活（老的设备都是已激活状态）
	char			szBaseDesc[24];	//基线短型号，不随定制而修改的型号，用于萤石平台进行型号对比
	unsigned char   byRes[16];   
}SADP_DEVICE_INFO, *LPSADP_DEVICE_INFO;

//待修改的设备网络参数
typedef struct tagSADP_DEV_NET_PARAM
{
	char			szIPv4Address[16];		// IPv4地址
	char			szIPv4SubNetMask[16];	// IPv4子网掩码
	char			szIPv4Gateway[16];		// IPv4网关
	char			szIPv6Address[128];		// IPv6地址
	char			szIPv6Gateway[128];		// IPv6网关
	unsigned short	wPort;					// 设备监听端口
	unsigned char	byIPv6MaskLen;			// IPv6掩码长度
	unsigned char	byDhcpEnable;			// DHCP使能
	unsigned short	wHttpPort;				//HTTP端口
	unsigned char	byRes[126];
}SADP_DEV_NET_PARAM, *LPSADP_DEV_NET_PARAM;


// CMS参数
typedef struct tagSADP_CMS_PARAM
{
	char			szPUID[32];			// 预分配的PUID
	char			szPassword[16];		// 设置的登录密码
	char			szCmsIPv4[16];		// CMS服务器IPv4地址
	char			szCmsIPv6[128];		// CMS服务器IPv6地址
	unsigned short	wCmsPort;			// CMS服务器监听端口
	unsigned char	byRes[30];
}SADP_CMS_PARAM, *LPSADP_CMS_PARAM;

//设备安全码，对应配置命令SADP_GET_DEVICE_CODE，接口SADP_GetDeviceConfig
typedef struct tagSADP_SAFE_CODE
{
	unsigned int    dwCodeSize;
	char            szDeviceCode[MAX_DEVICE_CODE];
	unsigned char   byRes[128];
}SADP_SAFE_CODE, *LPSADP_SAFE_CODE;
//恢复/重置密码结构体
typedef struct tagSADP_RESET_PARAM
{
    char            szCode[MAX_ENCRYPT_CODE]; //日期转换过的特殊字符串或加密工具加密后的字符串 - 为兼容老接口
    char            szAuthFile[MAX_FILE_PATH_LEN];             //重置授权文件
    char            szPassword[MAX_PASS_LEN];  //用户密码
    unsigned char   byRes[512];
}SADP_RESET_PARAM, *LSADP_RESET_PARAM;


// 接口
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
//激活设备
CSADP_API BOOL CALLBACK SADP_ActivateDevice(const char* sDevSerialNO, const char* sCommand);

//重置密码接口，兼容之前的恢复默认密码接口
CSADP_API BOOL CALLBACK SADP_ResetPasswd(const char* sDevSerialNO, const SADP_RESET_PARAM *pResetParam);
#endif




