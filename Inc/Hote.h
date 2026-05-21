#ifndef _HOTE_
#define _HOTE_
#ifdef __cplusplus
extern "C" {
#endif

#include "PinFun.h"

	
typedef void (*IrqCallback)(uint32_t,int); // 定义中断回调函数类型


//============================IO define===========================
enum IO_STATE{ //电平状态
	LOW=0,	//低
	HIGH	//高
};
enum IO_PORT{ 	//通用端口定义
	IO_PORT_A=0,
	IO_PORT_B,
	IO_PORT_C,
	IO_PORT_D,
	IO_PORT_E,
	IO_PORT_F,
	IO_PORT_G,
	IO_PORT_H,
	IO_PORT_I,
	IO_PORT_J,
	IO_PORT_K,
	IO_PORT_L,
	IO_PORT_M,
	IO_PORT_N,
	IO_PORT_O,
	IO_PORT_P,
	IO_PORT_Q,
	IO_PORT_R,
	IO_PORT_S,
	IO_PORT_T,
	IO_PORT_U,
	IO_PORT_V,
	IO_PORT_W,
	IO_PORT_X,
	IO_PORT_Y,
	IO_PORT_Z,
	IO_PORT_NUM
};

enum IO_PIN{	//通用引脚定义
	IO_PIN_0	=0x0001, /*!< gpio pins number 0 */
	IO_PIN_1    =0x0002, /*!< gpio pins number 1 */
	IO_PIN_2    =0x0004, /*!< gpio pins number 2 */
	IO_PIN_3    =0x0008, /*!< gpio pins number 3 */
	IO_PIN_4    =0x0010, /*!< gpio pins number 4 */
	IO_PIN_5    =0x0020, /*!< gpio pins number 5 */
	IO_PIN_6    =0x0040, /*!< gpio pins number 6 */
	IO_PIN_7    =0x0080, /*!< gpio pins number 7 */
	IO_PIN_8    =0x0100, /*!< gpio pins number 8 */
	IO_PIN_9    =0x0200, /*!< gpio pins number 9 */
	IO_PIN_10   =0x0400, /*!< gpio pins number 10 */
	IO_PIN_11   =0x0800, /*!< gpio pins number 11 */
	IO_PIN_12   =0x1000, /*!< gpio pins number 12 */
	IO_PIN_13   =0x2000, /*!< gpio pins number 13 */
	IO_PIN_14   =0x4000, /*!< gpio pins number 14 */
	IO_PIN_15   =0x8000, /*!< gpio pins number 15 */
	IO_PIN_NON	=0x0000 /*!< gpio no pin */
};
enum IO_MODE{	//引脚模式
	IO_MODE_INPUT=0,		//对应STM32的GPIO_Mode_IN
	IO_MODE_OUTPUT_PP,		//对应STM32的GPIO_Mode_OUT
	IO_MODE_OUTPUT_OD,		//对应STM32的GPIO_Mode_OUT
	IO_MODE_AF_PP,		//引脚复用推挽	对应STM32的GPIO_Mode_AF
	IO_MODE_AF_OD,		//引脚复用开漏	对应STM32的GPIO_Mode_AF
	IO_MODE_ANALOG,		//模拟输入		对应STM32的GPIO_Mode_AN
	IO_MODE_IT_RISING,			//INPUT		对应STM32的GPIO_Mode_IN
	IO_MODE_IT_FALLING,			//INPUT		对应STM32的GPIO_Mode_IN
	IO_MODE_IT_RISING_FALLING,	//INPUT		对应STM32的GPIO_Mode_IN
	IO_MODE_EVT_RISING,
	IO_MODE_EVT_FALLING,
	IO_MODE_EVT_RISING_FALLING
};
enum IO_PULL{	//引脚上下拉
	IO_NOPULL=0,
	IO_PULLUP,
	IO_PULLDOWN
};
//根据port和pin计算出通用io编号； 参数：端口号port，引脚号pin (注：ESP32没有类似PA3、PB5的表达形式，只有io编号更便捷，其他芯片PA2表示port=A pin=2)
static uint32_t PortPin2IO(enum IO_PORT port,enum IO_PIN pin){ return (port<<16)+pin;}
//根据通用io编号计算出引脚号pin 参数：通用io编号(如PB6=0x10040)
static enum IO_PIN IO2Pin(uint32_t io){ return io&0xffff;}
//根据通用引脚序号计算出引脚号pin 参数：通用引脚序号0~15
enum IO_PIN PinIdx2Pin(uint8_t i);//{ return pow(2,i);}中断中调用pow之类的可能莫名其妙卡住无响应

//============================System===============================
//系统初始化；
void Hote_SystemInit();
//延迟函数； 参数：毫秒ms
void Hote_DelayMs(uint32_t ms);
//延迟函数； 参数：微秒us
void Hote_DelayUs(uint32_t us);
//获取系统主频，如：24MHz/72MHz/120MHz/240MHz
uint32_t Hote_GetSystemCoreClock();
//获取系统时间； 返回毫秒ms
uint32_t Hote_GetTick();


enum AdcSpiI2sTimUartPwm_IDX{	//ADC/SPI/I2S/TIM/PWM/UART序号 如I2C1、I2C2,SPI1、SPI3,TIM1、TIM14,ADC1,PWM1、PWM2、I2S1
	_IDX1=1,
	_IDX2,
	_IDX3,
	_IDX4,
	_IDX5,
	_IDX6,
	_IDX7,
	_IDX8,
	_IDX9,
	_IDX10,
	_IDX11,
	_IDX12,
	_IDX13,
	_IDX14,
	_IDX15,
	_IDX16
};
enum CHANNEL_IDX{	//通用通道序号
	_CHANNEL0=0,
	_CHANNEL1,
	_CHANNEL2,
	_CHANNEL3,
	_CHANNEL4,
	_CHANNEL5,
	_CHANNEL6,
	_CHANNEL7,
	_CHANNEL8,
	_CHANNEL9,
	_CHANNEL10,
	_CHANNEL11,
	_CHANNEL12,
	_CHANNEL13,
	_CHANNEL14,
	_CHANNEL15,
	_CHANNEL_NON=0xff
};

// STM32F4的DMA是三级 DMA1_Stream0~7，DMA2_Stream0~7，DMA_Channel_0~7，即DMA1和DMA2都有8x8=64通道，每个通道对应功能需查询DMA映射表。
//  AT32F4的DMA是两级 DMA1_CHANNEL1~7，DMA2_CHANNEL1~7，即DMA1和DMA2都有7通道，STREAM1~7=CHANNEL1~7，参数dmaTx_ch/dmaRx_ch填_CHANNEL_NON。
enum DMA_STREAM{	//DMA数据流序号
	DMA1_STREAM0=0,
	DMA1_STREAM1,
	DMA1_STREAM2,
	DMA1_STREAM3,
	DMA1_STREAM4,
	DMA1_STREAM5,
	DMA1_STREAM6,
	DMA1_STREAM7,
	DMA1_STREAM8,
	DMA1_STREAM9,
	DMA1_STREAM10,
	DMA1_STREAM11,
	DMA1_STREAM12,
	DMA1_STREAM13,
	DMA1_STREAM14,
	DMA1_STREAM15,
	
	DMA2_STREAM0,
	DMA2_STREAM1,
	DMA2_STREAM2,
	DMA2_STREAM3,
	DMA2_STREAM4,
	DMA2_STREAM5,
	DMA2_STREAM6,
	DMA2_STREAM7,
	DMA2_STREAM8,
	DMA2_STREAM9,
	DMA2_STREAM10,
	DMA2_STREAM11,
	DMA2_STREAM12,
	DMA2_STREAM13,
	DMA2_STREAM14,
	DMA2_STREAM15,
	
	DMA3_STREAM0,
	DMA3_STREAM1,
	DMA3_STREAM2,
	DMA3_STREAM3,
	DMA3_STREAM4,
	DMA3_STREAM5,
	DMA3_STREAM6,
	DMA3_STREAM7,
	DMA3_STREAM8,
	DMA3_STREAM9,
	DMA3_STREAM10,
	DMA3_STREAM11,
	DMA3_STREAM12,
	DMA3_STREAM13,
	DMA3_STREAM14,
	DMA3_STREAM15,
	
	DMA_STREAM_NON=0Xff
};

//============================Uart=============================
//串口初始化； 参数：uart序号，波特率，TX通用io编号，RX通用io编号，回调函数(不需要填写NULL)
bool UartInit(enum AdcSpiI2sTimUartPwm_IDX idx, uint32_t baudRate, uint32_t txIo, uint32_t rxIo, IrqCallback cb);
//读取单字节串口数据；参数：uart序号
uint8_t UartRecv(enum AdcSpiI2sTimUartPwm_IDX idx);
//发送串口数据； 参数：uart序号，字节串，长度
uint8_t UartSend(enum AdcSpiI2sTimUartPwm_IDX idx, const char* dat, uint8_t len);
//发送串口数据； 参数：uart序号，字符串
void UartSendString(enum AdcSpiI2sTimUartPwm_IDX idx, const char* str);
//开启关闭log输出； 参数：开/关 默认UART1开
void UartLogEnable(bool b);
//格式化发送串口数据； 参数：可变参数
void Log(const char *format, ...);
#define printf Log



//============================IO================================
//初始化GPIO； 参数：通用io编号，输入输出模式(中断有50ms消抖)，上下拉，输出时默认高低电平，输入时中断回调函数(不需要填写NULL)
void GpioInit(uint32_t io, enum IO_MODE mode, enum IO_PULL pull, enum IO_STATE defaultState, IrqCallback cb);
//设置引脚电平； 参数：通用io编号，输出时默认高低电平
void GpioWrite(uint32_t io, enum IO_STATE state);
//读取引脚电平； 参数：通用io编号，是否输入方式读取(配置为输出的应false)
uint8_t GpioRead(uint32_t io, bool input);
//翻转引脚电平； 参数：通用io编号
void GpioToggle(uint32_t io);


//============================Timer==============================
//计时器初始化; 参数：tim序号，配置多少毫秒ms中断，回调函数(不需要填写NULL);  返回：false/true
bool TimerInit(enum AdcSpiI2sTimUartPwm_IDX idx, uint32_t ms, IrqCallback cb);
//获取计时器的计数; 参数：tim序号
uint32_t GetTimerCount(enum AdcSpiI2sTimUartPwm_IDX idx);
//停止计时器的计数; 参数：tim序号
void TimerStop(enum AdcSpiI2sTimUartPwm_IDX idx);



//============================Pwm================================
//初始化PWM 参数：tim/pwm序号，选择通道0~4，通用io编号，周期，时钟预分频值，占空比0~100%，引脚重映射(0xff不映射，0xfe自动，0~N对应手册规格书定义);  返回：false/true
bool PwmInit(enum AdcSpiI2sTimUartPwm_IDX idx, enum CHANNEL_IDX channel, uint32_t pwmIo, uint32_t period, uint32_t prescaler
	, uint32_t pulse, uint8_t reMapPwmIo);//自动映射可能错误
//初始化PWM 参数：tim/pwm序号，选择通道数组，通道数量1~9，通用io编号数组(数量和通道对齐)，周期，时钟预分频值，占空比0~100%，引脚重映射(0xff不映射，0xfe自动，0~N对应手册规格书定义);  返回：false/true
bool PwmInitEx(enum AdcSpiI2sTimUartPwm_IDX idx, enum CHANNEL_IDX channel[], uint8_t ch_num, uint32_t pwmio[], uint32_t period
	, uint32_t prescaler, uint32_t pulse, uint8_t reMapPwmIo);//同时多个通道PWM输出，部分芯片有多通道功能
//设置占空比 参数：tim/pwm序号，选择通道0~4，周期，占空比0~100%
void SetPwmDuty(enum AdcSpiI2sTimUartPwm_IDX idx, enum CHANNEL_IDX channel, uint32_t period, uint8_t p);
//设置多通道占空比 参数：tim/pwm序号，选择通道数组，通道数量1~9，周期，占空比0~100%
void SetPwmDutyEx(enum AdcSpiI2sTimUartPwm_IDX idx, enum CHANNEL_IDX channel[], uint8_t ch_num, uint32_t period, uint8_t p);


//============================Adc================================
//初始化ADC； 参数：adc序号，选择通道0~16(对应引脚查看规格书/数据手册)，通用io编号(要匹配通道);  返回：false/true
bool AdcInit(enum AdcSpiI2sTimUartPwm_IDX idx, enum CHANNEL_IDX channel, uint32_t adcIo);
//初始化ADC； 参数：adc序号，选择通道数组(多个通道同时读取)，通道数量1~9，通用io编号数组(数量和通道对齐);  返回：false/true
bool AdcInitEx(enum AdcSpiI2sTimUartPwm_IDX idx, enum CHANNEL_IDX channel[], uint8_t ch_num, uint32_t adcIo[]); //同时多通道ADC，部分芯片有多通道功能
//获取ADC数值； 参数：adc序号，选择通道0~16(对应引脚查看规格书/数据手册);  返回：adc数值
uint16_t GetAdcValue(enum AdcSpiI2sTimUartPwm_IDX idx, enum CHANNEL_IDX channel);
//获取多通道ADC数值； 参数：adc序号，通道数组，通道数量1~9，通道数值数组;  返回：false/true
bool GetAdcValueEx(enum AdcSpiI2sTimUartPwm_IDX idx, enum CHANNEL_IDX channel[], uint8_t ch_num, uint16_t value[]);


//============================Pm&Dog=============================
//初始化看门狗； 参数：时间毫秒ms 最大4095=0xFFF;  返回：false/true
bool DogInit(uint16_t ms);
//喂狗
void FeetDog();
//进入系统休眠/睡眠； 参数：类型 0浅休眠 1深休眠 2其他
void GotoSleep(int type);


//============================Flash/Rom===========================
//初始化flash; 参数：iROM起始地址(通常0x08000000)，iROM大小(512K=0x80000)，数据大小(存在后部)  返回：false/true
bool FlashInit(uint32_t romStart, uint32_t romSize,uint32_t dataSize);
//擦除flash;  返回：false/true
bool FlashErase();
//保存数据到flash； 参数：数据，长度;  返回：false/true
bool FlashSave(uint32_t* dat, uint32_t size);
//从flash读取数据； 参数：数据，长度;  返回：false/true
bool FlashRead(uint32_t* dat, uint32_t size);


enum MASTER_SLAVE{
	MODE_MASTER=0,
	MODE_SLAVE,
	MODE_MEM
};
enum MEMADDR_SIZE{
	MEMADDR_SIZE_8BIT=0x01,
	MEMADDR_SIZE_16BIT=0x10
};
enum I2S_DATAFORMAT{
	I2S_DATAFORMAT_16BIT=16,
	I2S_DATAFORMAT_24BIT=24,
	I2S_DATAFORMAT_32BIT=32
};
enum I2S_AUDIOFREQ{
	I2S_AUDIOFREQ_8K		=8000,
	I2S_AUDIOFREQ_11_025K	=11025,
	I2S_AUDIOFREQ_16K		=16000,
	I2S_AUDIOFREQ_22_05K	=22050,
	I2S_AUDIOFREQ_32K		=32000,
	I2S_AUDIOFREQ_44_1K		=44100,
	I2S_AUDIOFREQ_48K		=48000,
	I2S_AUDIOFREQ_96K		=96000,
	I2S_AUDIOFREQ_192K		=192000
};

//============================I2c==================================
//初始化I2C读写寄存器； 参数：i2c序号，通用io编号scl，通用io编号sda，自身7位设备地址,速率100000/400000，
//	主/从/mem寄存器，DMA数据流TX(DMA_STREAM_NON=关闭)，DMA TX通道，DMA数据流RX，DMA RX通道;  返回：false/true
bool I2cInit(enum AdcSpiI2sTimUartPwm_IDX idx, uint32_t sclIo, uint32_t sdaIo, uint8_t selfAddr, uint32_t speed
	, enum MASTER_SLAVE masl, enum DMA_STREAM dmaTx, enum CHANNEL_IDX dmaTx_ch, enum DMA_STREAM dmaRx, enum CHANNEL_IDX dmaRx_ch);
//写1字节寄存器； 参数：i2c序号，8位设备地址, 寄存器地址，寄存器地址宽度8/16，数据，超时默认10000;  返回：false/true
bool I2cMemWrite8(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t devAddr, uint16_t regAddr, enum MEMADDR_SIZE regAddrWidth, uint8_t dat, uint32_t timeout);
//写寄存器； 参数：i2c序号，8位设备地址, 寄存器地址，寄存器地址宽度8/16，数据，长度<=16，超时默认10000;  返回：false/true
bool I2cMemWrite(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t devAddr, uint16_t regAddr, enum MEMADDR_SIZE regAddrWidth, uint8_t* dat, uint8_t len, uint32_t timeout);
//读1字节寄存器； 参数：i2c序号，8位设备地址, 寄存器地址，寄存器地址宽度8/16，超时默认10000;  返回：数据
uint8_t I2cMemRead8(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t devAddr, uint16_t regAddr, enum MEMADDR_SIZE regAddrWidth, uint32_t timeout);
//读寄存器； 参数：i2c序号，8位设备地址, 寄存器地址，寄存器地址宽度8/16，数据，长度<=16，超时默认10000;  返回：false/true
bool I2cMemRead(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t devAddr, uint16_t regAddr, enum MEMADDR_SIZE regAddrWidth, uint8_t* dat, uint8_t len, uint32_t timeout);


//============================SPI===================================
//SPI初始化；参数：spi序号，通用io编号sclk，通用io编号mosi，通用io编号miso，
//	主/从，DMA数据流TX(DMA_STREAM_NON=关闭)，DMA TX通道，DMA数据流RX，DMA RX通道，引脚重映射(0xff不映射，0xfe自动，0~N对应手册规格书定义);  返回：false/true
bool SpiInit(enum AdcSpiI2sTimUartPwm_IDX idx, uint32_t sclkIo, uint32_t mosiIo, uint32_t misoIo, enum MASTER_SLAVE masl
	, enum DMA_STREAM dmaTx, enum CHANNEL_IDX dmaTx_ch, enum DMA_STREAM dmaRx, enum CHANNEL_IDX dmaRx_ch, uint8_t reMapSpiIo);//自动映射可能错误
//SPI发送1字节数据；参数：spi序号，数据，超时默认10000
bool SpiSend8(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t dat, uint32_t timeout);
//SPI接收1字节数据；参数：spi序号，超时默认10000
uint8_t SpiRecv8(enum AdcSpiI2sTimUartPwm_IDX idx, uint32_t timeout);

//SPI发送数据；参数：spi序号，数据，长度，DMA数据流TX(DMA_STREAM_NON=关闭)，超时默认10000
bool SpiSend(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t* dat, uint8_t len, enum DMA_STREAM dmaTx, uint32_t timeout);
//SPI接收数据；参数：spi序号，数据，长度，DMA数据流RX(DMA_STREAM_NON=关闭)，超时默认10000
bool SpiRecv(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t* dat, uint8_t len, enum DMA_STREAM dmaRx, uint32_t timeout);
//SPI同时发送接收数据；参数：spi序号，TX数据，RX数据，长度，DMA数据流TX(DMA_STREAM_NON=关闭)，DMA数据流RX，超时默认10000
bool SpiSendRecv(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t *tx_buf, uint8_t *rx_buf
	, uint16_t len, enum DMA_STREAM dmaTx, enum DMA_STREAM dmaRx, uint32_t timeout);


//============================I2S=================================== MCK通常不用写0
//I2S初始化； 参数：i2s序号，通用io编号mck，通用io编号sck，通用io编号lrck，通用io编号dout，通用io编号din，
//	数据宽度，采样率，DMA数据流TX(DMA_STREAM_NON=关闭)，DMA TX通道，DMA数据流RX，DMA RX通道，引脚重映射(0xff不映射，0xfe自动，0~N对应手册规格书定义);  返回：false/true
bool I2sInit(enum AdcSpiI2sTimUartPwm_IDX idx, uint32_t mckIo, uint32_t sckIo, uint32_t lrckIo, uint32_t doutIo
	, uint32_t dinIo, enum I2S_DATAFORMAT dataFormat, enum I2S_AUDIOFREQ samplingFreq
	, enum DMA_STREAM dmaTx, enum CHANNEL_IDX dmaTx_ch, enum DMA_STREAM dmaRx, enum CHANNEL_IDX dmaRx_ch, uint8_t reMapI2sIo);
//动态调整播放速率； 参数：i2s序号，新速率;  返回：false/true
bool I2sSetClkSp(enum AdcSpiI2sTimUartPwm_IDX idx, uint32_t sp);

//I2S发送数据；参数：i2s序号, 16位数据串，长度，DMA数据流TX，超时默认10000;  返回：false/true
bool I2sSend(enum AdcSpiI2sTimUartPwm_IDX idx, uint16_t* dat, uint8_t len, enum DMA_STREAM dmaTx, uint32_t timeout);
//I2S发送数据；参数：i2s序号, 8位数据串，长度，DMA数据流TX，超时默认10000;  返回：false/true
bool I2sSendEx(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t* dat, uint8_t len, enum DMA_STREAM dmaTx, uint32_t timeout);

//I2S接收数据；参数：i2s序号, 16位数据串，长度，DMA数据流RX，超时默认10000;  返回：false/true
bool I2sRecv(enum AdcSpiI2sTimUartPwm_IDX idx, uint16_t* dat, uint8_t len, enum DMA_STREAM dmaRx, uint32_t timeout);
//I2S接收数据；参数：i2s序号, 8位数据串，长度，DMA数据流RX，超时默认10000;  返回：获取到的实际长度
int I2sRecvEx(enum AdcSpiI2sTimUartPwm_IDX idx, uint8_t* dat, uint8_t len, enum DMA_STREAM dmaRx, uint32_t timeout);



//============================Usb Audio==============================
//UsbAudio初始化； 参数：绑定I2S序号直接双向转发数据(如I2S3=3，0表示不绑定);  返回：false/true
bool UsbAudioInit(enum AdcSpiI2sTimUartPwm_IDX i2s_idx);
//UsbAudio发送数据； 参数：8位数据串，长度;  返回：false/true
bool UsbAudioSend(uint8_t* dat, uint16_t len);
//UsbAudio接收数据； 参数：8位数据串，长度;  返回：false/true
bool UsbAudioRecv(uint8_t* dat, uint16_t len);



//============================Usb Serial==============================
//Usb虚拟串口初始化； 返回：false/true
bool UsbSerialInit();
//Usb虚拟串口发送数据； 参数：8位数据串，长度;  返回：false/true
bool UsbSerialSend(uint8_t* dat, uint16_t len);
//Usb虚拟串口接收数据； 参数：8位数据串，长度;  返回：实际读取的长度
uint16_t UsbSerialRecv(uint8_t* dat, uint16_t len);
//Log到USB虚拟串口
void LogUSB( char *fmt, ...);



//============================SdCard==============================
//Sdcard初始化；参数：通用io编号clk，通用io编号d0，通用io编号d1，通用io编号d2，通用io编号d3，通用io编号cmd;  返回：false/true
bool SdCardInit(uint32_t clkIo, uint32_t d0Io, uint32_t d1Io, uint32_t d2Io, uint32_t d3Io, uint32_t cmdIo);
//Sdcard加载； 参数：根目录(如："1:");  返回：false/true  (AT32F4必须是 "1:")
bool Sdcard_Mount(const char* dir);
//Sdcard打开文件； 参数：文件名(如："1:/test1.txt");  返回：false/true
bool Sdcard_OpenFile(const char* fileName);

//Sdcard指定读写文件偏移位置； 参数：位置;  返回：false/true
bool Sdcard_SeekFile(uint32_t n);
//Sdcard指定读写文件偏移位置到最后 从而实现续写;  返回：false/true
bool Sdcard_SeekFileBack();

//Sdcard连续写入文件； 参数：数据，大小;  返回：false/true
bool Sdcard_WirteFile(const uint8_t* dat, uint16_t size);
//Sdcard连续读取文件； 参数：数据，大小;  返回：false/true
bool Sdcard_ReadFile(uint8_t* dat, uint16_t size);
//Sdcard关闭文件； 参数：;  返回：false/true
bool Sdcard_CloseFile();
//Sdcard关闭文件； 参数：指定目录;  返回：空闲空间  (大目录耗时很长)
uint32_t Sdcard_GetFree(const char* dir);
//Sdcard反加载； 参数：根目录
bool Sdcard_UnMount(const char* dir);






//============================Error==================================
static void APP_ErrorHandler(const char* fileName, int line, const char* msg, int code)
{
	//..\Src\PY32F0_Pwm.c
	int i=0,n=0; //remove path
	for(i=strlen(fileName)-3;i>0;i--){
		if(fileName[i]=='\\'){n=i;break;}
	}
    //printf("%s\n", __func__); //__func__ == __FUNCTION__
	//printf("%s\n", __DATE__); Mmm dd yyyy
	//printf("%s\n", __TIME__); hh:mm:ss
	Log("*error: %s line=%d (%s %d)\n",fileName+n+1,line,msg,code); //__FILE__, __LINE__
}



#ifdef __cplusplus
}
#endif


#endif
