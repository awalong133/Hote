#ifndef _PINFUN_
#define _PINFUN_
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h> 
#include <stdlib.h>
#include <string.h>

#ifndef bool
	#define bool _Bool
#endif
#ifndef false
	#define false 0
#endif
#ifndef true
	#define true 1
#endif

	
//========================================================================================================================
//SPI中：RES=RST, DC命令/数据, CS片选, MOSI主输出, MISO主输入 （CS=IO_PIN_NON是硬件接地始终选中）

#define PY32F0
#ifdef AT32F4
	//引脚选择 并 转换成通用io编号
	#define IO_TX	PortPin2IO(IO_PORT_A,IO_PIN_9)
	#define IO_RX	PortPin2IO(IO_PORT_A,IO_PIN_10)
	#define IO_TX2	PortPin2IO(IO_PORT_A,IO_PIN_2)
	#define IO_RX2	PortPin2IO(IO_PORT_A,IO_PIN_3)
	#define IO_TX3	PortPin2IO(IO_PORT_B,IO_PIN_10)
	#define IO_RX3	PortPin2IO(IO_PORT_B,IO_PIN_11)

	#define IO_KEY1			PortPin2IO(IO_PORT_A,IO_PIN_0)
	#define IO_KEY1_PULL	IO_PULLDOWN	//初始化配置上下拉
	#define IO_KEY2			PortPin2IO(IO_PORT_A,IO_PIN_7)
	#define IO_KEY2_PULL	IO_PULLDOWN	//初始化配置上下拉
	#define IO_LED			PortPin2IO(IO_PORT_D,IO_PIN_13) //D13 D14 D15
	#define IO_LED_PULL		IO_PULLUP	//初始化配置上下拉
	
	#define IO_PWM1	PortPin2IO(IO_PORT_D,IO_PIN_14)	//TIM4 CH3
	#define PWM1_IDX _IDX4		//PWM1 /PWM2 / PWM3...
	#define PWM1_CHANNEL _CHANNEL3
	#define IO_PWM2	PortPin2IO(IO_PORT_C,IO_PIN_9)	//TIM3 CH4
	#define PWM2_IDX _IDX3
	#define PWM2_CHANNEL _CHANNEL4

	//注：ADC1和ADC2是合并采集 不能单独用ADC2，ADC3是独立采集的，所以ADC2在平台不可用
	#define IO_ADC1			PortPin2IO(IO_PORT_A,IO_PIN_4)	//ADC1 CH4
	#define ADC1_IDX 		_IDX1		// ADC1
	#define ADC1_CHANNEL 	_CHANNEL4
	#define IO_ADC2			PortPin2IO(IO_PORT_C,IO_PIN_0)	//ADC3 CH10
	#define ADC2_IDX 		_IDX3		// ADC3
	#define ADC2_CHANNEL 	_CHANNEL10
	
	#define TIMER1_IDX _IDX1
	#define TIMER2_IDX _IDX2
	
	#define IO_I2C_SCL			PortPin2IO(IO_PORT_B,IO_PIN_6)
	#define IO_I2C_SDA			PortPin2IO(IO_PORT_B,IO_PIN_7)
	#define I2C_SCL_CHANNEL 	DMA1_STREAM4
	#define I2C_SDA_CHANNEL 	DMA1_STREAM5
	#define IO_I2C_SCL2			PortPin2IO(IO_PORT_B,IO_PIN_10)
	#define IO_I2C_SDA2			PortPin2IO(IO_PORT_B,IO_PIN_11)
	#define I2C_SCL2_CHANNEL 	DMA1_STREAM2
	#define I2C_SDA2_CHANNEL 	DMA1_STREAM3
	
	#define LCD_SPI_IDX	_IDX2
	#define IO_SPI_SCK	PortPin2IO(IO_PORT_B,IO_PIN_13)
	#define IO_SPI_MOSI	PortPin2IO(IO_PORT_B,IO_PIN_15)
	#define IO_SPI_MISO	PortPin2IO(IO_PORT_B,IO_PIN_14)
	#define IO_SPI_CS	PortPin2IO(IO_PORT_B,IO_PIN_12)//NSS 片选
	#define IO_SPI_DC	PortPin2IO(IO_PORT_C,IO_PIN_4) //命令/数据
	#define IO_SPI_RST	PortPin2IO(IO_PORT_C,IO_PIN_5) //复位
	#define IO_LCD_BLK  PortPin2IO(IO_PORT_A,IO_PIN_8) //
	#define IO_FONT_CS	PortPin2IO(IO_PORT_B,IO_PIN_1)

	
	#define IO_I2S_CK_MCLK	0      // 主时钟 通常不用 不输出
	#define IO_I2S_CK_BCLK	PortPin2IO(IO_PORT_B,IO_PIN_3)      // 位时钟 BCLK
	#define IO_I2S_WS_LRCK	PortPin2IO(IO_PORT_A,IO_PIN_15)     // 帧时钟 LRCK
	#define IO_I2S_SD_DOUT	PortPin2IO(IO_PORT_B,IO_PIN_5)      // 数据输出 DOUT
	#define IO_I2S_EXT_DIN	PortPin2IO(IO_PORT_B,IO_PIN_4)      // 数据输入 DIN

	#define IO_SDCARD_CLK	PortPin2IO(IO_PORT_C,IO_PIN_12) //SdCard  SDIO接口
	#define IO_SDCARD_D0	PortPin2IO(IO_PORT_C,IO_PIN_8)
	#define IO_SDCARD_D1	PortPin2IO(IO_PORT_C,IO_PIN_9)
	#define IO_SDCARD_D2	PortPin2IO(IO_PORT_C,IO_PIN_10)
	#define IO_SDCARD_D3	PortPin2IO(IO_PORT_C,IO_PIN_11)
	#define IO_SDCARD_CMD	PortPin2IO(IO_PORT_D,IO_PIN_2)

	#define FLASH_SIZE	0x100000

#elif defined(STM32F4)
	//引脚选择 并 转换成通用io编号
	#define _UARTx	1
	#if (_UARTx==1)
		#define IO_TX	PortPin2IO(IO_PORT_A,IO_PIN_9)//uart1
		#define IO_RX	PortPin2IO(IO_PORT_A,IO_PIN_10)
	#elif (_UARTx==2)
		#define IO_TX	PortPin2IO(IO_PORT_A,IO_PIN_2)//uart2
		#define IO_RX	PortPin2IO(IO_PORT_A,IO_PIN_3)
	#elif (_UARTx==6)
		#define IO_TX	PortPin2IO(IO_PORT_C,IO_PIN_6)//uart6
		#define IO_RX	PortPin2IO(IO_PORT_C,IO_PIN_7)
	#endif

	#define IO_KEY1			PortPin2IO(IO_PORT_C,IO_PIN_6)
	#define IO_KEY1_PULL	IO_PULLUP	//初始化配置上下拉
	#define IO_KEY2			PortPin2IO(IO_PORT_A,IO_PIN_7)
	#define IO_KEY2_PULL	IO_PULLUP	//初始化配置上下拉
	#define IO_LED			PortPin2IO(IO_PORT_C,IO_PIN_8)
	#define IO_LED_PULL		IO_PULLUP	//初始化配置上下拉
	
	#define IO_PWM1	PortPin2IO(IO_PORT_C,IO_PIN_7)	//TIM3 CH2
	#define PWM1_IDX _IDX3		//PWM1 /PWM2 / PWM3...
	#define PWM1_CHANNEL _CHANNEL2
	#define IO_PWM2	PortPin2IO(IO_PORT_C,IO_PIN_9)	//TIM3 CH4
	#define PWM2_IDX _IDX3
	#define PWM2_CHANNEL _CHANNEL4

	#define IO_ADC1	PortPin2IO(IO_PORT_A,IO_PIN_3)	//ADC1 CH3
	#define ADC1_IDX _IDX1		// ADC1 / ADC2 / ADC3...
	#define ADC1_CHANNEL _CHANNEL3
	#define IO_ADC2	PortPin2IO(IO_PORT_A,IO_PIN_5)	//ADC1 CH5
	#define ADC2_IDX _IDX1
	#define ADC2_CHANNEL _CHANNEL5
	
	#define TIMER1_IDX _IDX2
	#define TIMER2_IDX _IDX4
	
	#define IO_I2C_SCL	PortPin2IO(IO_PORT_B,IO_PIN_6)
	#define IO_I2C_SDA	PortPin2IO(IO_PORT_B,IO_PIN_7)
	#define I2C_SCL_CHANNEL 	DMA_STREAM_NON
	#define I2C_SDA_CHANNEL 	DMA_STREAM_NON
	#define IO_I2C_SCL2			PortPin2IO(IO_PORT_B,IO_PIN_10)
	#define IO_I2C_SDA2			PortPin2IO(IO_PORT_B,IO_PIN_11)
	#define I2C_SCL2_CHANNEL 	DMA1_STREAM2
	#define I2C_SDA2_CHANNEL 	DMA1_STREAM3
	
	#define LCD_SPI_IDX	_IDX1
	#define IO_SPI_SCK	PortPin2IO(IO_PORT_A,IO_PIN_5)
	#define IO_SPI_MOSI	PortPin2IO(IO_PORT_A,IO_PIN_7)
	#define IO_SPI_MISO	IO_PIN_NON
	#define IO_SPI_CS	PortPin2IO(IO_PORT_A,IO_PIN_4) //NSS 片选
	#define IO_SPI_DC	PortPin2IO(IO_PORT_B,IO_PIN_3) //命令/数据
	#define IO_SPI_RST	PortPin2IO(IO_PORT_B,IO_PIN_2) //复位
	#define IO_LCD_BLK  PortPin2IO(IO_PORT_B,IO_PIN_1) //
	#define IO_FONT_CS	IO_PIN_NON
	
	#define IO_I2S_CK_MCLK	0      // 主时钟 通常不用 不输出
	#define IO_I2S_CK_BCLK	PortPin2IO(IO_PORT_B,IO_PIN_13)      // 位时钟 BCLK
	#define IO_I2S_WS_LRCK	PortPin2IO(IO_PORT_B,IO_PIN_12)      // 帧时钟 LRCK
	#define IO_I2S_SD_DOUT	PortPin2IO(IO_PORT_B,IO_PIN_15)      // 数据输出 DOUT
	#define IO_I2S_EXT_DIN	PortPin2IO(IO_PORT_B,IO_PIN_14)      // 数据输入 DIN

	#define IO_SDCARD_CLK	PortPin2IO(IO_PORT_C,IO_PIN_12) //SdCard  SDIO接口
	#define IO_SDCARD_D0	PortPin2IO(IO_PORT_C,IO_PIN_8)
	#define IO_SDCARD_D1	PortPin2IO(IO_PORT_C,IO_PIN_9)
	#define IO_SDCARD_D2	PortPin2IO(IO_PORT_C,IO_PIN_10)
	#define IO_SDCARD_D3	PortPin2IO(IO_PORT_C,IO_PIN_11)
	#define IO_SDCARD_CMD	PortPin2IO(IO_PORT_D,IO_PIN_2)

	#define FLASH_SIZE	0x80000

#elif defined(PY32F0)
	//引脚选择 并 转换成通用io编号
	#define IO_TX	PortPin2IO(IO_PORT_B,IO_PIN_4)
	#define IO_RX	PortPin2IO(IO_PORT_B,IO_PIN_5)

	#define IO_KEY1			PortPin2IO(IO_PORT_A,IO_PIN_3)
	#define IO_KEY1_PULL	IO_PULLUP	//初始化配置上下拉
	#define IO_KEY2			PortPin2IO(IO_PORT_A,IO_PIN_0)
	#define IO_KEY2_PULL	IO_PULLUP	//初始化配置上下拉
	#define IO_LED			PortPin2IO(IO_PORT_A,IO_PIN_1)
	#define IO_LED_PULL		IO_PULLUP	//初始化配置上下拉
	
	#define IO_PWM1	PortPin2IO(IO_PORT_A,IO_PIN_5) //A5=TIM1_CH1,B0=TIM1_CH2
	#define PWM1_IDX _IDX1		//PWM1 /PWM2 / PWM3...
	#define PWM1_CHANNEL _CHANNEL1
	#define IO_PWM2	PortPin2IO(IO_PORT_A,IO_PIN_4) //A4=TIM1_CH3, B1/A2=TIM1_CH4
	#define PWM2_IDX _IDX1
	#define PWM2_CHANNEL _CHANNEL3

	#define IO_ADC1	PortPin2IO(IO_PORT_A,IO_PIN_7) //A7=ADC1_IN4
	#define ADC1_IDX _IDX1		// ADC1 / ADC2 / ADC3...
	#define ADC1_CHANNEL _CHANNEL4
	#define IO_ADC2	PortPin2IO(IO_PORT_C,IO_PIN_0) //C0=ADC1_IN5
	#define ADC2_IDX _IDX1
	#define ADC2_CHANNEL _CHANNEL5
	
	#define TIMER1_IDX _IDX14
	#define TIMER2_IDX _IDX2

	#define IO_I2C_SCL	PortPin2IO(IO_PORT_B,IO_PIN_3) //B3 A2
	#define IO_I2C_SDA	PortPin2IO(IO_PORT_B,IO_PIN_6) //B6 B4
	#define I2C_SCL_CHANNEL 	DMA_STREAM_NON
	#define I2C_SDA_CHANNEL 	DMA_STREAM_NON
	#define IO_I2C_SCL2			IO_PIN_NON //no I2C2
	#define IO_I2C_SDA2			IO_PIN_NON //no I2C2
	#define I2C_SCL2_CHANNEL 	DMA1_STREAM2
	#define I2C_SDA2_CHANNEL 	DMA1_STREAM3
	
	#define LCD_SPI_IDX	_IDX1
	#define IO_SPI_SCK	PortPin2IO(IO_PORT_B,IO_PIN_2) //B2 B0
	#define IO_SPI_MOSI	PortPin2IO(IO_PORT_B,IO_PIN_7) //A7 B7 A0
	#define IO_SPI_MISO	IO_PIN_NON	//C1 B6 A1
	#define IO_SPI_CS	PortPin2IO(IO_PORT_A,IO_PIN_6) //NSS 片选 A6 B5
	#define IO_SPI_DC	PortPin2IO(IO_PORT_A,IO_PIN_2) //命令/数据
	#define IO_SPI_RST	PortPin2IO(IO_PORT_B,IO_PIN_0) //复位
	#define IO_LCD_BLK  PortPin2IO(IO_PORT_B,IO_PIN_1) //
	#define IO_FONT_CS	IO_PIN_NON
	
	#define IO_I2S_CK_MCLK	0      // 主时钟 通常不用 不输出
	#define IO_I2S_CK_BCLK	PortPin2IO(IO_PORT_B,IO_PIN_10)      // 位时钟 BCLK
	#define IO_I2S_WS_LRCK	PortPin2IO(IO_PORT_B,IO_PIN_12)      // 帧时钟 LRCK
	#define IO_I2S_SD_DOUT	PortPin2IO(IO_PORT_B,IO_PIN_15)      // 数据输出 DOUT
	#define IO_I2S_EXT_DIN	PortPin2IO(IO_PORT_B,IO_PIN_14)      // 数据输入 DIN

	// GND A6 A7 A5 C1 B7 B6 B3 B4 B5 3V3  QFN20
	// GND C0 A4 A3 A2 A1 A0 B0 B1 B2 5V0  (未用A2 B0 B1)
	#define FLASH_SIZE 0x6000
#endif


//========================================================================================================================
//模块开关，Flash ROM不足的话 只能关闭一些模块
#define USE_MPU6050			0
#define USE_LCD_ST7789		1


//==============================Funs======================================================================================

/**
 * @brief  用于快速单行int转字符串, 未用MicroLIB可能奇怪卡住或没有串口log输出等
 * @param  n: input value
 * @retval str
 */
static char _fbuf[10]="";
static char* Int2Str(int n)
{
	//sprintf(_fbuf,"%d",n);
	snprintf(_fbuf, sizeof(_fbuf), "%d", n); // 安全转换
	return _fbuf;
}

/**
 * @brief  get pow(x,y)
 * @param  none
 * @retval value
 */
static int mypow(int x, int y)
{  
    if (y == 1) return x;  
    int result = 0;  
    int tmp = mypow(x, y/2);  
    if((y&1) != 0) //奇数  
        result = x * tmp * tmp;  
    else  
        result = tmp * tmp;  
    return result;  
}

/**
 * @brief  Split string
 * @param  src: string
 * @param  separator: 分隔符
 * @param  dest: 输出到数组
 * @param  num: 数组元素个数
 * @retval none
        use it as follow:
        char src[128]="";
        char* p[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; int num=0;
        Split(src,",",p,&num);
 */
static void Split(char *src,const char *separator,char **dest,int *num)
{
     char *pNext;
     //记录分隔符数量 
     int count = 0;
     //原字符串为空 
     if (src == NULL || strlen(src) == 0)
        return;
    //未输入分隔符
     if (separator == NULL || strlen(separator) == 0)
     {
        return;   
     }
	/*
		c语言string库中函数，
		声明： 
		char *strtok(char *str, const char *delim)
		参数： 
	    str -- 要被分解成一组小字符串的字符串。
    	delim -- 包含分隔符的 C 字符串。
    	返回值：
		该函数返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针。 

	*/
	//char *strtok(char *str, const char *delim); 
	 //获得第一个由分隔符分割的字符串 
    pNext = strtok(src,separator);
    while(pNext != NULL) {
     	//存入到目的字符串数组中 
        *dest++ = pNext; 
        ++count;
        /*
			strtok()用来将字符串分割成一个个片段。参数s指向欲分割的字符串，参数delim则为分割字符串中包含的所有字符。
			当strtok()在参数s的字符串中发现参数delim中包涵的分割字符时,则会将该字符改为\0 字符。
			在第一次调用时，strtok()必需给予参数s字符串，往后的调用则将参数s设置成NULL。
			每次调用成功则返回指向被分割出片段的指针。

		*/  
        pNext = strtok(NULL,separator);  
    }  
    *num = count;
}    

/**
 * @brief  get __DATE__ string change 2024-02-12
 * @param  st: out buf
 * @retval st
 */
static char* GetFormatDate(char* st)
{
	const static char MONTH[][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	char date[16] = __DATE__,i; //"Sep 11 2024"
    char* p[5]={0,0,0,0,0}; int num=0;
    Split(date," ",p,&num);
	//printf("[%s][%s][%s][%s][%s]\n",p[0],p[1],p[2],p[3],p[4]);
	for(i=0;i<12;i++){
		if(strcmp(MONTH[i],p[0])==0){
			sprintf(st,"%s-%02d-%02d",p[2],i+1,atoi(p[1])); //atoi() 可能卡死 Stack_Size=0x00000400 不足
			break;
		}
	}
	//printf("[%s][%s][%s][%s][%s] [%s]\n",p[0],p[1],p[2],p[3],p[4],st);
	return st;
}

//static int abs(int n){if(n<0)return -n; return n;}
/**
 * @brief  compare tow 8bit buffer
 * @param  st: none
 * @retval true/false
 */
static bool buffer_compare8(uint8_t* p_buffer1, uint8_t* p_buffer2, uint16_t buffer_length)
{
  while(buffer_length--)
  {
    if(*p_buffer1 != *p_buffer2)
    {
      return false;
    }
    p_buffer1++;
    p_buffer2++;
  }
  return true;
}

/**
 * @brief  compare tow 16bit buffer
 * @param  st: none
 * @retval true/false
 */
static bool buffer_compare16(uint16_t* p_buffer1, uint16_t* p_buffer2, uint16_t buffer_length)
{
  while(buffer_length--)
  {
    if(*p_buffer1 != *p_buffer2)
    {
      return false;
    }
    p_buffer1++;
    p_buffer2++;
  }
  return true;
}

/**
 * @brief  calculate verification code
 * @param  dat: string or byte array pointer
 * @param  len: 0 string, >0 byte array 
 * @param  rofe: ignore offset bytes from right
 * @retval checksum
 */
static uint8_t Add8CheckSum(const char* dat, int len, int rofe)
{
    uint8_t crc = 0;	int i;
    for (i = 0; i < (len?len:strlen(dat))-rofe; i++)
    {
        // byte b = Convert.ToByte(hexString.Substring(i, 2), 16);
        crc += dat[i];
    }
    return crc;
}

/**
 * @brief  HexString change to uint8_t/u16/u32/char/int16/int32/long long
 * @param  hexstr: hex string
 * @retval long long
 */
static long long HexStr2Int(const char* hexstr)
{
	const char* str = hexstr;
	long long ret = 0;
	int i = 0;
	int x = (int)strlen(hexstr);
	long long x1 = 0;
	while (i < x)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			x1 = (str[i] - '0');
			x1 = x1 * pow((double)16, (int)(x-i-1));
			ret += x1;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			x1 = str[i] - 'A' + 10;
			x1 = x1 * pow((double)16,(int)(x-i-1));
			ret += x1;
		}
		else if (str[i] >= 'a' && str[i] <= 'f')
		{
			x1 = str[i] - 'a' + 10;
			x1 = x1 * pow((double)16, (int)(x - i - 1));
			ret += x1;
		}
		i++;
	}
	return ret;
}

/**
 * @brief  find char index in string
 * @param  src: string
 * @param  count: length of src
 * @param  k: char
 * @param  offset: start index
 * @retval index from 0
 */
static int FindChar(const char* src, int count, char k,int offset)
{
	int i;
	for (i = offset; i < count; i++)
	{
		if (src[i]==k) return i;
	}
    // printk("find=%s  %d   %4d  re=%d\n", k,count2,offset,idx);
	return -1;
}

/**
 * @brief  find string index in another string
 * @param  src: string
 * @param  count1: length of src
 * @param  k: string
 * @param  count2: length of k
 * @param  offset: start index
 * @retval index from 0
 */
static int FindStr(const char* src, int count1, const char* k,int count2, int offset)
{
	int idx = -1,i,j;bool ck;
	for (i = offset; i < count1 - count2 + 1; i++)
	{
		ck = true;
		for (j = 0; j < count2; j++)
		{
			if (src[i+j]!=k[j]) { ck = false; break; }
		}
		if (ck) { idx = i; break; }
	}
    // printk("find=%s  %d   %4d  re=%d\n", k,count2,offset,idx);
	return idx;
}

/**
 * @brief  get sub string
 * @param  src: string
 * @param  offset: start index
 * @param  count: will get count
 * @param  out: out string buf
 * @retval out
 */
static char* SubStr(const char* src, int offset, int count, char* out)
{
	int i;
	for (i = 0; i < count; i++)
	{
		out[i] = src[i+offset];
	}
	return out;
}

/**
 * @brief  compare string,ignore case
 * @param  s: string
 * @param  o: string
 * @retval 0 or offset
 */
static char stricmp(const char* s,const char* o)
{
	int i;
    if(!s||!o) return -1;
	for (i= 0; i < strlen(s); i++)
	{
		if(s[i] != o[i])
            return 1;
	}
	return 0;
}

/**
 * @brief  calculate the average
 * @param  num: count
 * @param  ...: value 1~n
 * @retval result
 */
static double average(int num,...)
{
	va_list valist;
	double sum = 0.0; int i;
	va_start(valist, num);

	for (i = 0; i < num; i++)
	{
		sum += va_arg(valist, int);
	}
	va_end(valist);// clear valist 
	return sum/num;
} 




//========================================================================================================================
// 16位RGB565颜色表								 (16位与24位对应值)
#define     Color_B16LightPink                0xFDB8     //24位0xFFB6C1        浅粉红
#define     Color_B16Pink                     0xFE19     //24位0xFFC0CB        粉红
#define     Color_B16Crimson                  0xD8A7     //24位0xDC143C        猩红
#define     Color_B16LavenderBlush            0xFF9E     //24位0xFFF0F5        脸红的淡紫色
#define     Color_B16PaleVioletRed            0xDB92     //24位0xDB7093        苍白的紫罗兰红色
#define     Color_B16HotPink                  0xFB56     //24位0xFF69B4        热情的粉红
#define     Color_B16DeepPink                 0xF8B2     //24位0xFF1493        深粉色
#define     Color_B16MediumVioletRed          0xC0B0     //24位0xC71585        适中的紫罗兰红色
#define     Color_B16Orchid                   0xDB9A     //24位0xDA70D6        兰花的紫色
#define     Color_B16Thistle                  0xDDFB     //24位0xD8BFD8        蓟
#define     Color_B16plum                     0xDD1B     //24位0xDDA0DD        李子
#define     Color_B16Violet                   0xEC1D     //24位0xEE82EE        紫罗兰
#define     Color_B16Magenta                  0xF81F     //24位0xFF00FF        洋红
#define     Color_B16Fuchsia                  0xF81F     //24位0xFF00FF        灯笼海棠(紫红色)
#define     Color_B16DarkMagenta              0x8811     //24位0x8B008B        深洋红色
#define     Color_B16Purple                   0x8010     //24位0x800080        紫色
#define     Color_B16MediumOrchid             0xBABA     //24位0xBA55D3        适中的兰花紫
#define     Color_B16DarkVoilet               0xD81C     //24位0x9400D3        深紫罗兰色
#define     Color_B16DarkOrchid               0x9999     //24位0x9932CC        深兰花紫
#define     Color_B16Indigo                   0x4810     //24位0x4B0082        靛青
#define     Color_B16BlueViolet               0x895C     //24位0x8A2BE2        深紫罗兰的蓝色
#define     Color_B16MediumPurple             0x939B     //24位0x9370DB        适中的紫色
#define     Color_B16MediumSlateBlue          0x7B5D     //24位0x7B68EE        适中的板岩暗蓝灰色
#define     Color_B16SlateBlue                0x6AD9     //24位0x6A5ACD        板岩暗蓝灰色
#define     Color_B16DarkSlateBlue            0x49F1     //24位0x483D8B        深岩暗蓝灰色
#define     Color_B16Lavender                 0xE73F     //24位0xE6E6FA        熏衣草花的淡紫色
#define     Color_B16GhostWhite               0xFFDF     //24位0xF8F8FF        幽灵的白色
#define     Color_B16Blue                     0x001F     //24位0x0000FF        纯蓝
#define     Color_B16MediumBlue               0x0019     //24位0x0000CD        适中的蓝色
#define     Color_B16MidnightBlue             0x18CE     //24位0x191970        午夜的蓝色
#define     Color_B16DarkBlue                 0x0011     //24位0x00008B        深蓝色
#define     Color_B16Navy                     0x0010     //24位0x000080        海军蓝
#define     Color_B16RoyalBlue                0x435C     //24位0x4169E1        皇军蓝
#define     Color_B16CornflowerBlue           0x64BD     //24位0x6495ED        矢车菊的蓝色
#define     Color_B16LightSteelBlue           0xB63B     //24位0xB0C4DE        淡钢蓝
#define     Color_B16LightSlateGray           0x7453     //24位0x778899        浅石板灰
#define     Color_B16SlateGray                0x7412     //24位0x708090        石板灰
#define     Color_B16DoderBlue                0xD700     //24位0x1E90FF        道奇蓝
#define     Color_B16AliceBlue                0xF7DF     //24位0xF0F8FF        爱丽丝蓝
#define     Color_B16SteelBlue                0x4416     //24位0x4682B4        钢蓝
#define     Color_B16LightSkyBlue             0x867F     //24位0x87CEFA        淡蓝色
#define     Color_B16SkyBlue                  0x867D     //24位0x87CEEB        天蓝色
#define     Color_B16DeepSkyBlue              0x05FF     //24位0x00BFFF        深天蓝
#define     Color_B16LightBLue                0xAEDC     //24位0xADD8E6        淡蓝
#define     Color_B16PowDerBlue               0xB71C     //24位0xB0E0E6        火药蓝
#define     Color_B16CadetBlue                0x5CF4     //24位0x5F9EA0        军校蓝
#define     Color_B16Azure                    0xF7FF     //24位0xF0FFFF        蔚蓝色
#define     Color_B16LightCyan                0xE7FF     //24位0xE1FFFF        淡青色
#define     Color_B16PaleTurquoise            0xAF7D     //24位0xAFEEEE        苍白的绿宝石
#define     Color_B16Cyan                     0x07FF     //24位0x00FFFF        青色
#define     Color_B16Aqua                     0x07FF     //24位0x00FFFF        水绿色
#define     Color_B16DarkTurquoise            0x067A     //24位0x00CED1        深绿宝石
#define     Color_B16DarkSlateGray            0x2A69     //24位0x2F4F4F        深石板灰
#define     Color_B16DarkCyan                 0x0451     //24位000x8B8B        深青色
#define     Color_B16Teal                     0x0410     //24位0x008080        水鸭色
#define     Color_B16MediumTurquoise          0x4E99     //24位0x48D1CC        适中的绿宝石
#define     Color_B16LightSeaGreen            0x2595     //24位0x20B2AA        浅海洋绿
#define     Color_B16Turquoise                0x471A     //24位0x40E0D0        绿宝石
#define     Color_B16Auqamarin                0xA500     //24位0x7FFFAA        绿玉\碧绿色
#define     Color_B16MediumAquamarine         0x6675     //24位0x00FA9A        适中的碧绿色
#define     Color_B16MediumSpringGreen        0x07D3     //24位0xF5FFFA        适中的春天的绿色
#define     Color_B16MintCream                0xF7FF     //24位0x00FF7F        薄荷奶油
#define     Color_B16SpringGreen              0x07EF     //24位0x3CB371        春天的绿色
#define     Color_B16SeaGreen                 0x2C4A     //24位0x2E8B57        海洋绿
#define     Color_B16Honeydew                 0xF7FE     //24位0xF0FFF0        蜂蜜
#define     Color_B16LightGreen               0x9772     //24位0x90EE90        淡绿色
#define     Color_B16PaleGreen                0x9FD3     //24位0x98FB98        苍白的绿色
#define     Color_B16DarkSeaGreen             0x8DF1     //24位0x8FBC8F        深海洋绿
#define     Color_B16LimeGreen                0x3666     //24位0x32CD32        酸橙绿
#define     Color_B16Lime                     0x07E0     //24位0x00FF00        酸橙色
#define     Color_B16ForestGreen              0x2444     //24位0x228B22        森林绿
#define     Color_B16Green                    0x0400     //24位0x008000        纯绿
#define     Color_B16DarkGreen                0x0320     //24位0x006400        深绿色
#define     Color_B16Chartreuse               0x7FE0     //24位0x7FFF00        查特酒绿
#define     Color_B16LawnGreen                0x7FE0     //24位0x7CFC00        草坪绿
#define     Color_B16GreenYellow              0xAFE5     //24位0xADFF2F        绿黄色
#define     Color_B16OliveDrab                0x6C64     //24位0x556B2F        橄榄土褐色
#define     Color_B16Beige                    0xF7BB     //24位0x6B8E23        米色(浅褐色)
#define     Color_B16LightGoldenrodYellow     0xFFDA     //24位0xFAFAD2        浅秋麒麟黄
#define     Color_B16Ivory                    0xFFFE     //24位0xFFFFF0        象牙
#define     Color_B16LightYellow              0xFFFC     //24位0xFFFFE0        浅黄色
#define     Color_B16Yellow                   0xFFE0     //24位0xFFFF00        纯黄
#define     Color_B16Olive                    0x8400     //24位0x808000        橄榄
#define     Color_B16DarkKhaki                0xBDAD     //24位0xBDB76B        深卡其布
#define     Color_B16LemonChiffon             0xFFD9     //24位0xFFFACD        柠檬薄纱
#define     Color_B16PaleGodenrod             0xA060     //24位0xEEE8AA        灰秋麒麟
#define     Color_B16Khaki                    0xF731     //24位0xF0E68C        卡其布
#define     Color_B16Gold                     0xFEA0     //24位0xFFD700        金
#define     Color_B16Cornislk                 0xC000     //24位0xFFF8DC        玉米色
#define     Color_B16GoldEnrod                0xDD24     //24位0xDAA520        秋麒麟
#define     Color_B16FloralWhite              0xFFDE     //24位0xFFFAF0        花的白色
#define     Color_B16OldLace                  0xFFBC     //24位0xFDF5E6        老饰带
#define     Color_B16Wheat                    0xF6F6     //24位0xF5DEB3        小麦色
#define     Color_B16Moccasin                 0xFF36     //24位0xFFE4B5        鹿皮鞋
#define     Color_B16Orange                   0xFD20     //24位0xFFA500        橙色
#define     Color_B16PapayaWhip               0xFF7A     //24位0xFFEFD5        番木瓜
#define     Color_B16BlanchedAlmond           0xFF59     //24位0xFFEBCD        漂白的杏仁
#define     Color_B16NavajoWhite              0xFEF5     //24位0xFFDEAD        Navajo白
#define     Color_B16AntiqueWhite             0xFF5A     //24位0xFAEBD7        古代的白色
#define     Color_B16Tan                      0xD5B1     //24位0xD2B48C        晒黑
#define     Color_B16BrulyWood                0xB000     //24位0xDEB887        结实的树
#define     Color_B16Bisque                   0xFF38     //24位0xFFE4C4        (浓汤)乳脂,番茄等
#define     Color_B16DarkOrange               0xFC60     //24位0xFF8C00        深橙色
#define     Color_B16Linen                    0xFF9C     //24位0xFAF0E6        亚麻布
#define     Color_B16Peru                     0xCC27     //24位0xCD853F        秘鲁
#define     Color_B16PeachPuff                0xFED7     //24位0xFFDAB9        桃色
#define     Color_B16SandyBrown               0xF52C     //24位0xF4A460        沙棕色
#define     Color_B16Chocolate                0xD343     //24位0xD2691E        巧克力
#define     Color_B16SaddleBrown              0x8A22     //24位0x8B4513        马鞍棕色
#define     Color_B16SeaShell                 0xFFBD     //24位0xFFF5EE        海贝壳
#define     Color_B16Sienna                   0xA285     //24位0xA0522D        黄土赭色
#define     Color_B16LightSalmon              0xFD0F     //24位0xFFA07A        浅鲜肉(鲑鱼)色
#define     Color_B16Coral                    0xFBEA     //24位0xFF7F50        珊瑚
#define     Color_B16OrangeRed                0xFA20     //24位0xFF4500        橙红色
#define     Color_B16DarkSalmon               0xECAF     //24位0xE9967A        深鲜肉(鲑鱼)色
#define     Color_B16Tomato                   0xFB08     //24位0xFF6347        番茄
#define     Color_B16MistyRose                0xFF3C     //24位0xFFE4E1        薄雾玫瑰
#define     Color_B16Salmon                   0xFC0E     //24位0xFA8072        鲜肉(鲑鱼)色
#define     Color_B16Snow                     0xFFDF     //24位0xFFFAFA        雪
#define     Color_B16LightCoral               0xF410     //24位0xF08080        淡珊瑚色
#define     Color_B16RosyBrown                0xBC71     //24位0xBC8F8F        玫瑰棕色
#define     Color_B16IndianRed                0xCAEB     //24位0xCD5C5C        印度红
#define     Color_B16Red                      0xF800     //24位0xFF0000        纯红
#define     Color_B16Brown                    0xA145     //24位0xA52A2A        棕色
#define     Color_B16FireBrick                0xB104     //24位0xB22222        耐火砖
#define     Color_B16DarkRed                  0x8800     //24位0x8B0000        深红色
#define     Color_B16Maroon                   0x8000     //24位0x800000        栗色
#define     Color_B16White                    0xFFFF     //24位0xFFFFFF        纯白
#define     Color_B16WhiteSmoke               0xF7BE     //24位0xF5F5F5        白烟
#define     Color_B16Gainsboro                0xDEFB     //24位0xDCDCDC        Gainsboro
#define     Color_B16LightGrey                0xD69A     //24位0xD3D3D3        浅灰色
#define     Color_B16Silver                   0xC618     //24位0xC0C0C0        银白色
#define     Color_B16DarkGray                 0xAD55     //24位0xA9A9A9        深灰色
#define     Color_B16Gray                     0x8410     //24位0x808080        灰色
#define     Color_B16DimGray                  0x6B4D     //24位0x696969        暗淡的灰色
#define     Color_B16Black                    0x0000     //24位0x000000        纯黑
// 24位RGB888颜色表								 (24位与16位对应值)
#define     Color_B24LightPink                0xFFB6C1       //16位0xFDB8      浅粉红
#define     Color_B24Pink                     0xFFC0CB       //16位0xFE19      粉红
#define     Color_B24Crimson                  0xDC143C       //16位0xD8A7      猩红
#define     Color_B24LavenderBlush            0xFFF0F5       //16位0xFF9E      脸红的淡紫色
#define     Color_B24PaleVioletRed            0xDB7093       //16位0xDB92      苍白的紫罗兰红色
#define     Color_B24HotPink                  0xFF69B4       //16位0xFB56      热情的粉红
#define     Color_B24DeepPink                 0xFF1493       //16位0xF8B2      深粉色
#define     Color_B24MediumVioletRed          0xC71585       //16位0xC0B0      适中的紫罗兰红色
#define     Color_B24Orchid                   0xDA70D6       //16位0xDB9A      兰花的紫色
#define     Color_B24Thistle                  0xD8BFD8       //16位0xDDFB      蓟
#define     Color_B24plum                     0xDDA0DD       //16位0xDD1B      李子
#define     Color_B24Violet                   0xEE82EE       //16位0xEC1D      紫罗兰
#define     Color_B24Magenta                  0xFF00FF       //16位0xF81F      洋红
#define     Color_B24Fuchsia                  0xFF00FF       //16位0xF81F      灯笼海棠(紫红色)
#define     Color_B24DarkMagenta              0x8B008B       //16位0x8811      深洋红色
#define     Color_B24Purple                   0x800080       //16位0x8010      紫色
#define     Color_B24MediumOrchid             0xBA55D3       //16位0xBABA      适中的兰花紫
#define     Color_B24DarkVoilet               0x9400D3       //16位0xD81C      深紫罗兰色
#define     Color_B24DarkOrchid               0x9932CC       //16位0x9999      深兰花紫
#define     Color_B24Indigo                   0x4B0082       //16位0x4810      靛青
#define     Color_B24BlueViolet               0x8A2BE2       //16位0x895C      深紫罗兰的蓝色
#define     Color_B24MediumPurple             0x9370DB       //16位0x939B      适中的紫色
#define     Color_B24MediumSlateBlue          0x7B68EE       //16位0x7B5D      适中的板岩暗蓝灰色
#define     Color_B24SlateBlue                0x6A5ACD       //16位0x6AD9      板岩暗蓝灰色
#define     Color_B24DarkSlateBlue            0x483D8B       //16位0x49F1      深岩暗蓝灰色
#define     Color_B24Lavender                 0xE6E6FA       //16位0xE73F      熏衣草花的淡紫色
#define     Color_B24GhostWhite               0xF8F8FF       //16位0xFFDF      幽灵的白色
#define     Color_B24Blue                     0x0000FF       //16位0x001F      纯蓝
#define     Color_B24MediumBlue               0x0000CD       //16位0x0019      适中的蓝色
#define     Color_B24MidnightBlue             0x191970       //16位0x18CE      午夜的蓝色
#define     Color_B24DarkBlue                 0x00008B       //16位0x0011      深蓝色
#define     Color_B24Navy                     0x000080       //16位0x0010      海军蓝
#define     Color_B24RoyalBlue                0x4169E1       //16位0x435C      皇军蓝
#define     Color_B24CornflowerBlue           0x6495ED       //16位0x64BD      矢车菊的蓝色
#define     Color_B24LightSteelBlue           0xB0C4DE       //16位0xB63B      淡钢蓝
#define     Color_B24LightSlateGray           0x778899       //16位0x7453      浅石板灰
#define     Color_B24SlateGray                0x708090       //16位0x7412      石板灰
#define     Color_B24DoderBlue                0x1E90FF       //16位0xD700      道奇蓝
#define     Color_B24AliceBlue                0xF0F8FF       //16位0xF7DF      爱丽丝蓝
#define     Color_B24SteelBlue                0x4682B4       //16位0x4416      钢蓝
#define     Color_B24LightSkyBlue             0x87CEFA       //16位0x867F      淡蓝色
#define     Color_B24SkyBlue                  0x87CEEB       //16位0x867D      天蓝色
#define     Color_B24DeepSkyBlue              0x00BFFF       //16位0x05FF      深天蓝
#define     Color_B24LightBLue                0xADD8E6       //16位0xAEDC      淡蓝
#define     Color_B24PowDerBlue               0xB0E0E6       //16位0xB71C      火药蓝
#define     Color_B24CadetBlue                0x5F9EA0       //16位0x5CF4      军校蓝
#define     Color_B24Azure                    0xF0FFFF       //16位0xF7FF      蔚蓝色
#define     Color_B24LightCyan                0xE1FFFF       //16位0xE7FF      淡青色
#define     Color_B24PaleTurquoise            0xAFEEEE       //16位0xAF7D      苍白的绿宝石
#define     Color_B24Cyan                     0x00FFFF       //16位0x07FF      青色
#define     Color_B24Aqua                     0x00FFFF       //16位0x07FF      水绿色
#define     Color_B24DarkTurquoise            0x00CED1       //16位0x067A      深绿宝石
#define     Color_B24DarkSlateGray            0x2F4F4F       //16位0x2A69      深石板灰
#define     Color_B24DarkCyan                 000x8B8B       //16位0x0451      深青色
#define     Color_B24Teal                     0x008080       //16位0x0410      水鸭色
#define     Color_B24MediumTurquoise          0x48D1CC       //16位0x4E99      适中的绿宝石
#define     Color_B24LightSeaGreen            0x20B2AA       //16位0x2595      浅海洋绿
#define     Color_B24Turquoise                0x40E0D0       //16位0x471A      绿宝石
#define     Color_B24Auqamarin                0x7FFFAA       //16位0xA500      绿玉\碧绿色
#define     Color_B24MediumAquamarine         0x00FA9A       //16位0x6675      适中的碧绿色
#define     Color_B24MediumSpringGreen        0xF5FFFA       //16位0x07D3      适中的春天的绿色
#define     Color_B24MintCream                0x00FF7F       //16位0xF7FF      薄荷奶油
#define     Color_B24SpringGreen              0x3CB371       //16位0x07EF      春天的绿色
#define     Color_B24SeaGreen                 0x2E8B57       //16位0x2C4A      海洋绿
#define     Color_B24Honeydew                 0xF0FFF0       //16位0xF7FE      蜂蜜
#define     Color_B24LightGreen               0x90EE90       //16位0x9772      淡绿色
#define     Color_B24PaleGreen                0x98FB98       //16位0x9FD3      苍白的绿色
#define     Color_B24DarkSeaGreen             0x8FBC8F       //16位0x8DF1      深海洋绿
#define     Color_B24LimeGreen                0x32CD32       //16位0x3666      酸橙绿
#define     Color_B24Lime                     0x00FF00       //16位0x07E0      酸橙色
#define     Color_B24ForestGreen              0x228B22       //16位0x2444      森林绿
#define     Color_B24Green                    0x008000       //16位0x0400      纯绿
#define     Color_B24DarkGreen                0x006400       //16位0x0320      深绿色
#define     Color_B24Chartreuse               0x7FFF00       //16位0x7FE0      查特酒绿
#define     Color_B24LawnGreen                0x7CFC00       //16位0x7FE0      草坪绿
#define     Color_B24GreenYellow              0xADFF2F       //16位0xAFE5      绿黄色
#define     Color_B24OliveDrab                0x556B2F       //16位0x6C64      橄榄土褐色
#define     Color_B24Beige                    0x6B8E23       //16位0xF7BB      米色(浅褐色)
#define     Color_B24LightGoldenrodYellow     0xFAFAD2       //16位0xFFDA      浅秋麒麟黄
#define     Color_B24Ivory                    0xFFFFF0       //16位0xFFFE      象牙
#define     Color_B24LightYellow              0xFFFFE0       //16位0xFFFC      浅黄色
#define     Color_B24Yellow                   0xFFFF00       //16位0xFFE0      纯黄
#define     Color_B24Olive                    0x808000       //16位0x8400      橄榄
#define     Color_B24DarkKhaki                0xBDB76B       //16位0xBDAD      深卡其布
#define     Color_B24LemonChiffon             0xFFFACD       //16位0xFFD9      柠檬薄纱
#define     Color_B24PaleGodenrod             0xEEE8AA       //16位0xA060      灰秋麒麟
#define     Color_B24Khaki                    0xF0E68C       //16位0xF731      卡其布
#define     Color_B24Gold                     0xFFD700       //16位0xFEA0      金
#define     Color_B24Cornislk                 0xFFF8DC       //16位0xC000      玉米色
#define     Color_B24GoldEnrod                0xDAA520       //16位0xDD24      秋麒麟
#define     Color_B24FloralWhite              0xFFFAF0       //16位0xFFDE      花的白色
#define     Color_B24OldLace                  0xFDF5E6       //16位0xFFBC      老饰带
#define     Color_B24Wheat                    0xF5DEB3       //16位0xF6F6      小麦色
#define     Color_B24Moccasin                 0xFFE4B5       //16位0xFF36      鹿皮鞋
#define     Color_B24Orange                   0xFFA500       //16位0xFD20      橙色
#define     Color_B24PapayaWhip               0xFFEFD5       //16位0xFF7A      番木瓜
#define     Color_B24BlanchedAlmond           0xFFEBCD       //16位0xFF59      漂白的杏仁
#define     Color_B24NavajoWhite              0xFFDEAD       //16位0xFEF5      Navajo白
#define     Color_B24AntiqueWhite             0xFAEBD7       //16位0xFF5A      古代的白色
#define     Color_B24Tan                      0xD2B48C       //16位0xD5B1      晒黑
#define     Color_B24BrulyWood                0xDEB887       //16位0xB000      结实的树
#define     Color_B24Bisque                   0xFFE4C4       //16位0xFF38      (浓汤)乳脂,番茄等
#define     Color_B24DarkOrange               0xFF8C00       //16位0xFC60      深橙色
#define     Color_B24Linen                    0xFAF0E6       //16位0xFF9C      亚麻布
#define     Color_B24Peru                     0xCD853F       //16位0xCC27      秘鲁
#define     Color_B24PeachPuff                0xFFDAB9       //16位0xFED7      桃色
#define     Color_B24SandyBrown               0xF4A460       //16位0xF52C      沙棕色
#define     Color_B24Chocolate                0xD2691E       //16位0xD343      巧克力
#define     Color_B24SaddleBrown              0x8B4513       //16位0x8A22      马鞍棕色
#define     Color_B24SeaShell                 0xFFF5EE       //16位0xFFBD      海贝壳
#define     Color_B24Sienna                   0xA0522D       //16位0xA285      黄土赭色
#define     Color_B24LightSalmon              0xFFA07A       //16位0xFD0F      浅鲜肉(鲑鱼)色
#define     Color_B24Coral                    0xFF7F50       //16位0xFBEA      珊瑚
#define     Color_B24OrangeRed                0xFF4500       //16位0xFA20      橙红色
#define     Color_B24DarkSalmon               0xE9967A       //16位0xECAF      深鲜肉(鲑鱼)色
#define     Color_B24Tomato                   0xFF6347       //16位0xFB08      番茄
#define     Color_B24MistyRose                0xFFE4E1       //16位0xFF3C      薄雾玫瑰
#define     Color_B24Salmon                   0xFA8072       //16位0xFC0E      鲜肉(鲑鱼)色
#define     Color_B24Snow                     0xFFFAFA       //16位0xFFDF      雪
#define     Color_B24LightCoral               0xF08080       //16位0xF410      淡珊瑚色
#define     Color_B24RosyBrown                0xBC8F8F       //16位0xBC71      玫瑰棕色
#define     Color_B24IndianRed                0xCD5C5C       //16位0xCAEB      印度红
#define     Color_B24Red                      0xFF0000       //16位0xF800      纯红
#define     Color_B24Brown                    0xA52A2A       //16位0xA145      棕色
#define     Color_B24FireBrick                0xB22222       //16位0xB104      耐火砖
#define     Color_B24DarkRed                  0x8B0000       //16位0x8800      深红色
#define     Color_B24Maroon                   0x800000       //16位0x8000      栗色
#define     Color_B24White                    0xFFFFFF       //16位0xFFFF      纯白
#define     Color_B24WhiteSmoke               0xF5F5F5       //16位0xF7BE      白烟
#define     Color_B24Gainsboro                0xDCDCDC       //16位0xDEFB      Gainsboro
#define     Color_B24LightGrey                0xD3D3D3       //16位0xD69A      浅灰色
#define     Color_B24Silver                   0xC0C0C0       //16位0xC618      银白色
#define     Color_B24DarkGray                 0xA9A9A9       //16位0xAD55      深灰色
#define     Color_B24Gray                     0x808080       //16位0x8410      灰色
#define     Color_B24DimGray                  0x696969       //16位0x6B4D      暗淡的灰色
#define     Color_B24Black                    0x000000       //16位0x0000      纯黑


typedef struct 
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
}RGB888;
static RGB888 RGB565ToRGB888(uint16_t color) {
	RGB888 rgb; // 10100 011110 00101
	rgb.red = (color >> 11) & 0x001F; // 5 bits for red
	rgb.green = (color >> 5) & 0x003F; // 6 bits for green
	rgb.blue = color & 0x001F; // 5 bits for blue
	return rgb;
}
static uint16_t RGB888ToRGB565(RGB888 rgb) {
	uint16_t high = rgb.red << 11;
	high |= rgb.green << 5;
	high |= rgb.blue;
	return high;
}
static uint16_t RGB888ToRGB565Ex(uint8_t red, uint8_t green, uint8_t blue) {
	uint16_t high = red << 11;
	high |= green << 5;
	high |= blue;
	return high;
}
static uint16_t GetStepCol(uint16_t color1,uint16_t color2,uint16_t stepIdx,uint16_t stepCount)
{
	uint8_t R=0,G=0,B=0;uint16_t c;
    RGB888 rgb1 = RGB565ToRGB888(color1);
    RGB888 rgb2 = RGB565ToRGB888(color2);
		R = rgb1.red+(rgb2.red-rgb1.red)*stepIdx/stepCount;
		G = rgb1.green+(rgb2.green-rgb1.green)*stepIdx/stepCount;
		B = rgb1.blue+(rgb2.blue-rgb1.blue)*stepIdx/stepCount;

	c=RGB888ToRGB565Ex(R,G,B);
	return c;
	//公式：Gradient = colorA + (colorB-colorA) * stepIdx / stepCount
	//Gradient表示第stepIdx步的R/G/B的值，colorA、colorB、stepCount表示从颜色A分stepCount步渐变为颜色B。
	//	//红--->绿
	//	//(255,0,0)-->(0,255,0)
	//	uint8_t R,G,B,stepCount=90;
	//	for(float stepIdx=1;stepIdx<stepCount;stepIdx++){
	//		R = 255+(0-255)*stepIdx/stepCount;
	//		G = 0+(255-0)*stepIdx/stepCount;
	//		B = 255+(0-255)*stepIdx/stepCount;
	//	}
}


	

#endif
