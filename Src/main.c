#include "Hote.h"
#include "Mpu6050.h"
#include "LCD_St7789.h"
//不要引入STM32/PY32/GD32/HK32...之类的头文件


struct UDATA{ //需要断电保存到flash/eprom的数据
	uint8_t __start__; // dat ok is 99，数据校验
	uint8_t show;
	uint8_t channel;
	uint8_t bar_type;
	uint8_t bep_type;
	float   cok_val[6];
	uint8_t run_type;
	uint8_t u_type;
	uint8_t c_type;
	uint8_t __end__; // dat ok is 99，数据校验
};
static struct UDATA mData;
bool DataInit()
{
	float v[6]={0,0.9,2.2,7.8,18.1,20.0};
	//初始化flash; 参数：iROM起始地址(通常0x8000000)，iROM大小(512K=0x80000)，数据大小(存在后部)  返回：false/true
	FlashInit(0x8000000, FLASH_SIZE, 128);
	memset(mData.cok_val,0,sizeof(mData.cok_val));
	FlashRead((uint32_t*)&mData, sizeof(struct UDATA)/4);
	if(mData.__start__!=99 || mData.__end__!=99)
	{
		mData.__start__=mData.__end__=99;
		mData.show=1;
		mData.bar_type=6;
		mData.bep_type=3;
		mData.run_type=2;
		memcpy(mData.cok_val,v,sizeof(v));
		FlashErase();
		FlashSave((uint32_t*)&mData, sizeof(struct UDATA)/4);
		Log("data reset  %d size=%d %d\n",mData.show,sizeof(struct UDATA),sizeof(v));
	}
	else Log("data Inited  (%0.2f  %0.2f  %0.2f  %0.2f  %0.2f  %0.2f)\n",
		mData.cok_val[0],mData.cok_val[1],mData.cok_val[2],mData.cok_val[3],mData.cok_val[4],mData.cok_val[5]);
	return true;
}


void OnTimer(uint32_t idx, int t) //计时器回调函数，参数:tim序号,计数
{
	if(idx==TIMER1_IDX){
		GpioToggle(IO_LED);//翻转引脚电平
		//Log("callback timer1000ms  %d\n",t);
	}else if(idx==TIMER2_IDX){
		//Log("callback timer1ms  %d\n",t);//多个中断都输出log 可能会冲突打断
	}
}

void OnKey(uint32_t idx, int io) //按键中断回调；参数：0，通用io编号
{
	Log("OnKey idx=%d io=0x%-5x pin=0x%-4x LowHigh=%d %dms\n",idx, io, IO2Pin(io), GpioRead(io,true), Hote_GetTick());
	if(!GpioRead(io,true)) GotoSleep(0);
}

void OnUartRecv(uint32_t idx, int byte) //串口回调函数； 参数：Uart序号，byte实际类型为uint8_t 这里为了匹配函数定义写为int
{
	Log("OnUartRecv idx=%d  byte=0x%-5x  %dms\n",idx, byte, Hote_GetTick());
}

int main()
{
	uint32_t tick=0; uint8_t duty=0,dir=1;
	Hote_SystemInit(); // 系统初始化
	//串口初始化； 参数：uart序号，波特率，TX通用io编号，RX通用io编号，回调函数(不需要填写NULL)
	UartInit(_IDX1, 115200, IO_TX, IO_RX, NULL);
	Log("\n-----------------------Start-----------------------\n");
	Log("SystemCoreClock:%dHz  FlashSize:%dKByte\n",Hote_GetSystemCoreClock(),FLASH_SIZE/1024);
	//USB虚拟串口初始化
	//UsbSerialInit(); // UsbSerial和UsbAudio不能同时启用

	//初始化GPIO； 参数：通用io编号，输入输出模式(中断有50ms消抖)，上下拉，输出时默认高低电平，输入时中断回调函数(不需要填写NULL)
	GpioInit(IO_KEY1, IO_MODE_IT_RISING_FALLING, IO_KEY1_PULL, HIGH, OnKey);	//按下松开都中断
	GpioInit(IO_KEY2, IO_MODE_IT_FALLING, IO_KEY2_PULL, HIGH, OnKey);			//按下中断
	GpioInit(IO_LED, IO_MODE_OUTPUT_PP, IO_LED_PULL, LOW, NULL);	//普通效果LED

	//初始化PWM 参数：tim/pwm序号，选择通道0~4，通用io编号，周期，时钟预分频值，占空比0~100%;  返回：false/true
	PwmInit(PWM1_IDX, PWM1_CHANNEL, IO_PWM1, 2000, Hote_GetSystemCoreClock()/(2000*10000), 0, 0xfe);//0% 呼吸效果LED 10KHz
	PwmInit(PWM2_IDX, PWM2_CHANNEL, IO_PWM2, 1000, Hote_GetSystemCoreClock()/(1000*5000), 0, 0xfe); //0% 呼吸效果LED 5KHz
	//enum CHANNEL_IDX ch[3]={_CHANNEL3,_CHANNEL4,_CHANNEL5};//三个通道
	//uint32_t ios[3]={IO_PWM1,PortPin2IO(IO_PORT_D,IO_PIN_15),PortPin2IO(IO_PORT_D,IO_PIN_12)};//三个通道对应三个引脚
	//PwmInitEx(PWM1_IDX, ch, 3, ios, 1000, Hote_GetSystemCoreClock()/(1000*5000), 0, 0xfe);//同时多个通道PWM输出，部分芯片有多通道功能

	//初始化ADC； 参数：adc序号，选择通道0~16(对应引脚查看规格书/数据手册)，通用io编号(要匹配通道);  返回：false/true
	AdcInit(ADC1_IDX, ADC1_CHANNEL, IO_ADC1);//通道对应引脚查看规格书/数据手册，不同芯片有差异
	AdcInit(ADC2_IDX, ADC2_CHANNEL, IO_ADC2);//通道对应引脚查看规格书/数据手册，不同芯片有差异
	//enum CHANNEL_IDX ch[3]={_CHANNEL4,_CHANNEL5,_CHANNEL6};//三个通道 最多9个通道
	//uint32_t ios[3]={IO_ADC1,PortPin2IO(IO_PORT_C,IO_PIN_0),PortPin2IO(IO_PORT_C,IO_PIN_6)};//三个通道对应三个引脚
	//AdcInitEx(ADC1_IDX, ch, 3, ios);//同时多通道ADC，部分芯片有多通道功能

	//初始化I2C读写寄存器； 参数：i2c序号，通用io编号scl，通用io编号sda，自身7位设备地址,速率100000/400000，
	//	主/从/mem寄存器，DMA数据流TX(DMA_CHANNEL_NON=关闭)，DMA TX通道，DMA数据流RX，DMA RX通道;  返回：false/true
	I2cInit(_IDX1, IO_I2C_SCL, IO_I2C_SDA, 0x00, 100000, MODE_MEM, I2C_SCL_CHANNEL, _CHANNEL_NON, I2C_SDA_CHANNEL, _CHANNEL_NON);
	I2cInit(_IDX2, IO_I2C_SCL2, IO_I2C_SDA2, 0x00, 100000, MODE_MEM, I2C_SCL2_CHANNEL, _CHANNEL_NON, I2C_SDA2_CHANNEL, _CHANNEL_NON);

	//初始化I2S3,16BIT 48K,NO DMA
	I2sInit(_IDX3, IO_PIN_NON, IO_I2S_CK_BCLK, IO_I2S_WS_LRCK, IO_I2S_SD_DOUT, IO_I2S_EXT_DIN, I2S_DATAFORMAT_16BIT, I2S_AUDIOFREQ_48K
			, DMA_STREAM_NON, _CHANNEL_NON,DMA_STREAM_NON, _CHANNEL_NON, 0xfe);
	//初始化UsbAudio，绑定I2S3 自动双向转发
	UsbAudioInit(_IDX3); // UsbSerial和UsbAudio不能同时启用

	//计时器初始化; 参数：使用哪个tim，配置多少毫秒ms中断，回调函数;  返回：false/true
	TimerInit(TIMER1_IDX, 1000, OnTimer);// 配置定时器 每隔1000ms中断
	TimerInit(TIMER2_IDX, 1, OnTimer);// 配置定时器 每隔1ms中断
	
	//初始化/读取flash数据 断电保存
	DataInit(); //内有演示读写方法

	#if USE_LCD_ST7789
	LCD_Init(); //初始化LCD，SPI ST7789， 彩色240x240
	LCD_Clear(Color_B16SpringGreen);//清屏
	LCD_Fill(20,50,150,80,0xf800);//填充色块
	LCD_Fill_X(20,100,150,140,Color_B16Blue,Color_B16Yellow);//横向渐变色条
	LCD_Fill_Y(180,40,210,210,Color_B16Yellow,Color_B16Blue);//垂直渐变色条
	LCD_DrawCircle(120,120,50,Color_B16Red);//画圆圈
	LCD_ShowString(20,180,(uint8_t*)"Test font",Color_B16Yellow,Color_B16Maroon,16,0);//显示英文字符
	#endif
	
	#if USE_MPU6050 //Flash ROM不足的话只能关闭一些模块
	MPU6050_t m6050;
	MPU6050_Init(); //初始化六轴传感器（加速计 陀螺仪）
	#endif
	
	//初始化看门狗； 参数：时间毫秒 最大4095=0xFFF;  返回：false/true
	DogInit(3600);

	while(true)
	{
		Hote_DelayMs(10);
		FeetDog();	//喂狗
		
		if(dir){duty++;if(duty>=100)dir=0;}
		else {duty--;if(duty<=0)dir=1;}
		SetPwmDuty(PWM1_IDX, PWM1_CHANNEL, 2000, duty);//设置占空比0~100
		SetPwmDuty(PWM2_IDX, PWM2_CHANNEL, 1000, 100-duty);//设置占空比0~100
		
		//Log("%c\n",UartRecv(_IDX1));//主动拉取接收串口数据 非中断

		if(GetTimerCount(TIMER1_IDX)-tick>3)//S
		{
			tick=GetTimerCount(TIMER1_IDX);
			
			Log("loop %6dms sec=%-4d ADC1ch4=%d ADC1ch5=%d\n",Hote_GetTick(),GetTimerCount(TIMER1_IDX)
											,GetAdcValue(ADC1_IDX, ADC1_CHANNEL),GetAdcValue(ADC2_IDX, ADC2_CHANNEL));
			//LogUSB("loop USB log  %d\n",Hote_GetTick());//USB虚拟串口发送
	
			//uint16_t value[3]={0,0,0};//最多9个通道
			//GetAdcValueEx(ADC1_IDX,value,3);//同时获取多个通道adc数值，部分芯片有多通道功能
			
			#if USE_MPU6050
			if(MPU6050_Read_All(&m6050))
				Log("M6050: %0.3f,%0.3f,%0.3fg  %0.3f,%0.3f,%0.3f  T=%0.1f KX=%0.1f KY=%0.1f\n",m6050.Ax,m6050.Ay
					,m6050.Az, m6050.Gx,m6050.Gy,m6050.Gz, m6050.Temperature, m6050.KalmanAngleX, m6050.KalmanAngleY);
			#endif
		}
	}
}

void assert_failed(uint8_t *file, uint32_t line)
{
	Log("assert_failed %6dms  Tcount=%-4d\n",Hote_GetTick(),GetTimerCount(_IDX14));
}
