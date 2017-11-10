const ffi        = require('ffi');
const ref        = require('ref');
const StructType = require('ref-struct');
const ArrayType  = require('ref-array');
stDeviceInfo= StructType({
		szSeries               : ArrayType(ref.types.char, 12), //设备系列
		szSerialNO             : ArrayType(ref.types.char, 48), //设备序列号                              
		szMAC                  : ArrayType(ref.types.char, 20),                          
		szIPv4Address          : ArrayType(ref.types.char, 16),                                  
		szIPv4SubnetMask       : ArrayType(ref.types.char, 16),                                     
		dwDeviceType           : ref.types.uint, 
		dwPort                 : ref.types.uint, 
		dwNumberOfEncoders     : ref.types.uint, 
		dwNumberOfHardDisk     : ref.types.uint, 
		szDeviceSoftwareVersion: ArrayType(ref.types.char, 48),                                           
		szDSPVersion           : ArrayType(ref.types.char, 48),                                
		szBootTime             : ArrayType(ref.types.char, 48),                              
		iResult                : ref.types.int,           
		szDevDesc              : ArrayType(ref.types.char, 24),                                     
		szOEMinfo              : ArrayType(ref.types.char, 24),                                   
		szIPv4Gateway          : ArrayType(ref.types.char, 16),                                   
		szIPv6Address          : ArrayType(ref.types.char, 46),                                   
		szIPv6Gateway          : ArrayType(ref.types.char, 46),                                   
		byIPv6MaskLen          : ref.types.uchar,
		bySupport              : ref.types.uchar,
		byDhcpEnabled          : ref.types.uchar,
		byDeviceAbility        : ref.types.uchar,
		wHttpPort              : ref.types.ushort,
		wDigitalChannelNum     : ref.types.ushort,
		szCmsIPv4              : ArrayType(ref.types.char, 16),
		wCmsPort               : ref.types.ushort,
		byOEMCode              : ref.types.uchar,
		byActivated            : ref.types.uchar,
		szBaseDesc             : ArrayType(ref.types.char, 24),                                 
		byRes                  : ArrayType(ref.types.uchar, 16)                   
});

console.log("beging to load lib...")
debugger
var libsadp = ffi.Library('../lib/libsadp.so', {
		'SADP_Start_V30' : ['bool', ['pointer', 'int', 'pointer']],
		'SADP_SendInquiry' : ['bool', []]
});
console.log("end to load lib...")

var devicesCnt = 0;
console.log("======== start var definit ===========")
console.log("the stDeviceInfo.size is " + stDeviceInfo.size);
var stDeviceInfoArr = ArrayType(stDeviceInfo); // stDeviceInfoArr : stDeviceInfoArr[]
console.log("the stDeviceInfoArr.size is " + stDeviceInfoArr.size);
var astDeviceInfo = new stDeviceInfoArr(5);   // stDeviceInfoArr astDeviceInfoArr[100] = {0}:  
console.log("the astDeviceInfo's length is: " + astDeviceInfo.length);
console.log("the astDeviceInfo's content is: " + astDeviceInfo);
console.log("======== end var definit ===========")

deviceFindCallBack = ffi.Callback('void', [ref.refType(stDeviceInfo), 'pointer'],
		function(pDeviceInfo, pUserData){
				console.log("==========>In the call back function, current deviceCnt: " + devicesCnt + "<===============");
				astDeviceInfo[devicesCnt].szSeries = pDeviceInfo.deref().szSeries;
				astDeviceInfo[devicesCnt].dwPort   = pDeviceInfo.deref().dwPort;

				//read device info  and save
				console.log("###### Is the user data null? : " + (pUserData == ref.NULL) + ", and the address is: " + pUserData.hexAddress());
				console.log("the szSeries is: " + pDeviceInfo.deref().szSeries[0] + " len : " + pDeviceInfo.deref().szSeries.length);
				console.log("the dwPort is :" + pDeviceInfo.deref().dwPort);
				console.log("the astDeviceInfo's length is: " + astDeviceInfo.length);
				console.log("the astDeviceInfo's content is:" + astDeviceInfo);

				console.log("the global deviceInfo(" + devicesCnt + ") szSeries is: " + astDeviceInfo[devicesCnt].szSeries);
				console.log("the global deviceInfo(" + devicesCnt + ") dwport is: " + astDeviceInfo[devicesCnt].dwPort);
				devicesCnt++;
		}
);

console.log("registering the callback");
console.log("astDeviceInfo.buffer: " + astDeviceInfo.buffer + ", and the adderss is: " + astDeviceInfo.buffer.hexAddress());
ret = libsadp.SADP_Start_V30(deviceFindCallBack, 0, astDeviceInfo.buffer);
console.log("call back register result:" + ret);

console.log("to send inquiry");
ret = libsadp.SADP_SendInquiry();
console.log("inquire result " + ret);

