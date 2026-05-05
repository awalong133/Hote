

Hote是一个跨芯片的开发套件，一份写好的代码，换不同品牌型号芯片只需改引脚重新编译即可运行；
嵌入式芯片MCU有很多种品牌型号，功能、SDK驱动接口都不同，互不兼容，换芯片要重新开发。
Hote遵从极简主义、极少代码、一次开发；避免换芯片品牌型号需要从头开发一次。
让有C/C++语言基础的人(中小学生也可以)能30分钟入门，查阅清楚芯片资料和原理图引脚定义后，
一小时就能开发出对应的嵌入式软件。

套件支持的开发环境 VsCode+EIDE 或 Keil5。
目前支持: STM32F4系列、AT32F4系列、PY32F0系列；将陆续更新支持品牌型号。

套件支持功能：
	Delay and GetTick()
	Uart and Log
	GPIO Button Led
	Flash rom save data
	Sleep and Dog
	Timer
	PWM
	ADC
	I2C
	SPI
	I2S
	USB Serial
	USB Audio
	SDcard
	
功能已经实际测试过的具体型号：STM32F401 AT32F403A PY32F002B
注意：
实际功能取决于选定的芯片，其引脚定义及复用功能不同，仔细查阅规格书/芯片手册。
比如PY32F002B是没有I2S和USB及SDcard功能的 并 只有一个I2C和SPI。
如发现问题可以提交bug详情，可能需要实体板子测试；

套件如何更换芯片选定？
一、
	在PinFun.h中 直接修改为如下宏定义之一，再修改引脚，也可以删除自己不需要的部分。
	#define STM32F4  #define PY32F0  #define AT32F4
二、
	在VSCode EIDE里更换(删除原有再添加对应的库) Hote_Stm32F4xx.lib  Hote_At32F4xx.lib  Hote_Py32F0.lib ；
	在Keil里更换(删除原有再添加对应的库) Hote_Stm32F4xx.lib  Hote_At32F4xx.lib  Hote_Py32F0.lib ；

为何lib和a库未开源？
因为如果开源的话，需要安装熟悉各种芯片的开发环境和配置 调试编译问题，
非常繁琐，难度大 工作量耗时倍增，这违背了Hote遵从极简主义、极少代码、一次开发的理念。



Hote is a cross chip development kit, a written code that can be run by simply changing 
the pins and recompiling to switch to different brands and models of chips;
There are many brands and models of embedded chip MCU, with different functions and SDK driver 
interfaces, which are incompatible with each other. Changing the chip requires redevelopment.
Hote adheres to minimalism, minimal code, and one-time development; To avoid changing 
chip brands and models, it is necessary to develop them from scratch.
Enable people with a foundation in C/C++language (including primary and secondary school students) 
to get started in 30 minutes, and after thoroughly reviewing chip information and 
schematic pin definitions, It takes one hour to develop the corresponding embedded software.

The development environment supported by the suite is VsCode+EIDE or Keil5.
Currently supported: STM32F4 series, AT32F4 series, PY32F0 series; 
Will gradually update support for brand models.

Supporting functions:
	Delay and GetTick()
	Uart and Log
	GPIO Button Led
	Flash rom save data
	Sleep and Dog
	Timer
	PWM
	ADC
	I2C
	SPI
	I2S
	USB Serial
	USB Audio
	SDcard

Specific models that have been tested for functionality: STM32F401 AT32F403A PY32F002B
Note: 
The actual function depends on the selected chip, and its pin definition and reuse 
function are different. Please carefully refer to the specification book/chip manual.
For example, PY32F002B does not have I2S and USB functions abd only one I2C/SPI.
If any problems are found, you can submit bug details, which may require physical board testing;

How to replace the chip in the kit and select it?
一、
	In PinFun.h, directly modify it to one of the following macro definitions, 
	and then modify the pins to delete unnecessary parts.	
	#define STM32F4  #define PY32F0  #define AT32F4
二、
	VSCode EIDE: Replace (delete original and add corresponding library) 
		Hote_Stm32F4xx.lib  Hote_At32F4xx.lib  Hote_Py32F0.lib ;
	Keil: Replace (delete original and add corresponding library) 
		Hote_Stm32F4xx.lib  Hote_At32F4xx.lib  Hote_Py32F0.lib ;

Why are lib and a libraries not open source?
Because if it is open source, it requires installation and familiarity with various 
chip development environments, as well as configuration, debugging, and compilation issues,
Very tedious, difficult, and time-consuming, which goes against Hote's philosophy 
of minimalism, minimal code, and one-time development.





For learning only
Copyright©2020-2030 Hote All Rights Reserved.
