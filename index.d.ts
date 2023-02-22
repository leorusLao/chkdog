



export interface Feature {
	// feature id
	id:number	// featureId
	
	// perpetual: 永久有效
	// expiration:
	//     expDate: 有效期的时间戳
	// trial:
	//     timeStart: 开始时间的时间戳 [如果为零，则还未开始使用]
	//     totalTime: 授权天数的秒数 ==> 剩余的秒
	// executions：
	//     counterFix： 总次数
	//     counterVar： 已执行次数
	licenseType:string 
	
	// 有效期的时间戳
	expDate:number

	//开始时间的时间戳 [如果为零，则还未开始使用]	
	timeStart:number 
	//授权天数的秒数 ==> 剩余的秒
	totalTime:number 

	//总次数
	counterFix:number
	//已执行次数
	counterVar:number
	
}



declare let chkdog: {

	/*
	 * featureId :特征id  默认为1
	 * 输出：true -- 检查超级狗成功  ；false -- 检查超级狗失败
	*/
	checkUSBKey: (
		featureId: number,
	) =>boolean

	/*
	 * 特征列表
	*/
	getExpDate: () =>Array<Feature> 

	/*
	* 输出: 0 -- 不限制功能； 1 -- 限制功能； 2 -- 错误
	*/
	isLimit: () => number

	/*
	* 输出: true -- 硬件信息检测一致； false -- 硬件信息检测不一致；
	*/
	checkMacInfo:()=>boolean

	/*
	* 输出: 超级狗指纹信息；
	*/
	getFingerprint:()=>string

	/*
	* 升级超级狗
	*/
	updateFingerprint:(
		v2cpath:string
	)=>boolean

	/*
	* 输出: 硬件信息；
	*/
	getHardwareInfo:()=>string

	/*
	* fileId: 文件id，默认: 1  ----  硬件信息 ; 2  ----   超级狗编号
	* 输出：文件内容
	*/
	getDogMemoryInfo:(
		fileId:number
	)=>string

}

export default chkdog;