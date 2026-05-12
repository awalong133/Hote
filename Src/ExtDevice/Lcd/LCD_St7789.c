#include "Hote.h"
#include "LCD_St7789.h"
#include "fonts.h"   // 字库文件
#if USE_LCD_ST7789




void LCD_WriteCmd(uint8_t cmd)
{
    GpioWrite(IO_SPI_DC,LOW);
    GpioWrite(IO_SPI_CS,LOW);
	SpiSend8(LCD_SPI_IDX, cmd,5000);
	//SpiSend(LCD_SPI_IDX, &cmd, 1, DMA2_STREAM3);
    GpioWrite(IO_SPI_CS,HIGH);
}

void LCD_WriteData(uint8_t dat)
{
    GpioWrite(IO_SPI_DC,HIGH);
    GpioWrite(IO_SPI_CS,LOW);
	SpiSend8(LCD_SPI_IDX, dat,5000);
	//SpiSend(LCD_SPI_IDX, &dat, 1, DMA2_STREAM3);
    GpioWrite(IO_SPI_CS,HIGH);
}

void LCD_WriteData16(uint16_t dat)
{
	LCD_WriteData(dat>>8);
	LCD_WriteData(dat);
}
void LCD_WriteMultiData(uint8_t *dat, uint16_t len)
{
    GpioWrite(IO_SPI_DC,HIGH);
    GpioWrite(IO_SPI_CS,LOW);
	for(uint16_t i=0; i<len; i++) SpiSend8(LCD_SPI_IDX, dat[i],5000);
	//SpiSend(LCD_SPI_IDX, dat, len, DMA2_STREAM3,5000);
    GpioWrite(IO_SPI_CS,HIGH);
}

// -------------------------- 窗口设置 --------------------------
void LCD_SetWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
    /*uint8_t buf[4];
    // CASET
    buf[0] = x1>>8; buf[1] = x1&0xFF;
    buf[2] = x2>>8; buf[3] = x2&0xFF;
    LCD_WriteCmd(0x2A);
    LCD_WriteMultiData(buf,4);
    // RASET
    buf[0] = y1>>8; buf[1] = y1&0xFF;
    buf[2] = y2>>8; buf[3] = y2&0xFF;
    LCD_WriteCmd(0x2B);
    LCD_WriteMultiData(buf,4);
    LCD_WriteCmd(0x2C); // 写数据*/
	
	LCD_WriteCmd(0x2a);//列地址设置
	LCD_WriteData16(x1);
	LCD_WriteData16(x2);
	LCD_WriteCmd(0x2b);//行地址设置
	LCD_WriteData16(y1);
	LCD_WriteData16(y2);
	LCD_WriteCmd(0x2c);//储存器写
}

// -------------------------- ST7789 初始化 --------------------------
void LCD_Init()
{
	GpioInit(IO_SPI_CS, IO_MODE_OUTPUT_PP, IO_PULLUP, HIGH, NULL);//CS默认不选中
	GpioInit(IO_SPI_DC, IO_MODE_OUTPUT_PP, IO_PULLUP, HIGH, NULL);//DC
	GpioInit(IO_SPI_RST, IO_MODE_OUTPUT_PP, IO_PULLUP, LOW, NULL);//RST
	GpioInit(IO_LCD_BLK, IO_MODE_OUTPUT_PP, IO_PULLUP, HIGH, NULL);//BL
	Hote_DelayMs(100);
    GpioWrite(IO_SPI_RST,HIGH);//复位
	Hote_DelayMs(120);

	//SPI初始化；参数：spi序号，通用io编号sclk，通用io编号mosi，通用io编号miso，用io编号cs，
	//	主/从，DMA数据流TX(DMA_CHANNEL_NON=关闭)，DMA TX通道，DMA数据流RX，DMA RX通道;  返回：false/true
	SpiInit(LCD_SPI_IDX, IO_SPI_SCK, IO_SPI_MOSI, IO_SPI_MISO, MODE_MASTER, SPI_DMA_TX, SPI_DMA_TX_CH, SPI_DMA_RX, SPI_DMA_RX_CH, 0xff);

		
	// ----------- ST7789 240x240 初始化指令 -----------
    LCD_WriteCmd(0x11); // 唤醒
	Hote_DelayMs(120);

    LCD_WriteCmd(0x36);
    LCD_WriteData(0x00); // 方向 0x00 0x60 0xa0 0xc0

    LCD_WriteCmd(0x3A);
    LCD_WriteData(0x55); // 16位色

    LCD_WriteCmd(0xB2);
    LCD_WriteData(0x0C);
    LCD_WriteData(0x0C);
    LCD_WriteData(0x00);
    LCD_WriteData(0x33);
    LCD_WriteData(0x33);

    LCD_WriteCmd(0xB7);
    LCD_WriteData(0x35);

    LCD_WriteCmd(0xBB);
    LCD_WriteData(0x19);

    LCD_WriteCmd(0xC0);
    LCD_WriteData(0x2C);

    LCD_WriteCmd(0xC2);
    LCD_WriteData(0x01);

    LCD_WriteCmd(0xC3);
    LCD_WriteData(0x12);

    LCD_WriteCmd(0xC4);
    LCD_WriteData(0x20);

    LCD_WriteCmd(0xC6);
    LCD_WriteData(0x0F);

    LCD_WriteCmd(0xD0);
    LCD_WriteData(0xA4);
    LCD_WriteData(0xA1);

//    LCD_WriteCmd(0xE0);//泛白
//    LCD_WriteData(0xD0);
//    LCD_WriteData(0x04);
//    LCD_WriteData(0x0D);
//    LCD_WriteData(0x11);
//    LCD_WriteData(0x13);
//    LCD_WriteData(0x2B);
//    LCD_WriteData(0x3F);
//    LCD_WriteData(0x48);
//    LCD_WriteData(0x38);
//    LCD_WriteData(0x15);
//    LCD_WriteData(0x0F);
//    LCD_WriteData(0x0E);
//    LCD_WriteData(0x22);
//    LCD_WriteData(0x36);

//    LCD_WriteCmd(0xE1);//泛白
//    LCD_WriteData(0xD0);
//    LCD_WriteData(0x04);
//    LCD_WriteData(0x0C);
//    LCD_WriteData(0x11);
//    LCD_WriteData(0x13);
//    LCD_WriteData(0x2C);
//    LCD_WriteData(0x3F);
//    LCD_WriteData(0x48);
//    LCD_WriteData(0x38);
//    LCD_WriteData(0x14);
//    LCD_WriteData(0x0E);
//    LCD_WriteData(0x0E);
//    LCD_WriteData(0x22);
//    LCD_WriteData(0x36);

	LCD_WriteCmd(0xE0);
	LCD_WriteData(0xD0);
	LCD_WriteData(0x04);
	LCD_WriteData(0x0D);
	LCD_WriteData(0x11);
	LCD_WriteData(0x13);
	LCD_WriteData(0x2B);
	LCD_WriteData(0x3F);
	LCD_WriteData(0x54);
	LCD_WriteData(0x4C);
	LCD_WriteData(0x18);
	LCD_WriteData(0x0D);
	LCD_WriteData(0x0B);
	LCD_WriteData(0x1F);
	LCD_WriteData(0x23);

	LCD_WriteCmd(0xE1);
	LCD_WriteData(0xD0);
	LCD_WriteData(0x04);
	LCD_WriteData(0x0C);
	LCD_WriteData(0x11);
	LCD_WriteData(0x13);
	LCD_WriteData(0x2C);
	LCD_WriteData(0x3F);
	LCD_WriteData(0x44);
	LCD_WriteData(0x51);
	LCD_WriteData(0x2F);
	LCD_WriteData(0x1F);
	LCD_WriteData(0x1F);
	LCD_WriteData(0x20);
	LCD_WriteData(0x23);

    LCD_WriteCmd(0x21); // 反色关闭
    LCD_WriteCmd(0x29); // 显示开启
	Hote_DelayMs(10);
}

// -------------------------- 清屏 --------------------------
void LCD_Clear(uint16_t color)
{
    uint8_t buf[2] = {color>>8, color&0xFF};
    uint32_t total = (uint32_t)LCD_W * LCD_H;

    LCD_SetWindow(0,0,LCD_W-1,LCD_H-1);

    for(uint32_t i=0;i<total;i++){
        LCD_WriteMultiData(buf,2);
		//LCD_WriteData16(color);
    }
}

// -------------------------- 填充矩形 --------------------------
void LCD_Fill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
    uint8_t buf[2] = {color>>8, color&0xFF};
    uint32_t num = (uint32_t)(x2-x1+1)*(y2-y1+1);

    LCD_SetWindow(x1,y1,x2,y2);
    for(uint32_t i=0;i<num;i++){
        LCD_WriteMultiData(buf,2);
    }
}
// -------------------------- 指定区域填充颜色，X轴渐变色 -------------------------- 
void LCD_Fill_X(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color1,uint16_t color2)
{
	uint16_t i,step=x2-x1;
	for(i=x1;i<x2;i++){
		LCD_Fill(i, y1, i+1, y2, GetStepCol(color1,color2,i-x1,step));
	}
}
// -------------------------- 指定区域填充颜色，Y轴渐变色 -------------------------- 
void LCD_Fill_Y(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color1,uint16_t color2)
{
	uint16_t i,step=y2-y1;
	for(i=y1;i<y2;i++){
		LCD_Fill(x1, i, x2, i+1, GetStepCol(color1,color2,i-y1,step));
	}
}

//画点
void LCD_DrawPoint(uint16_t x, uint16_t y, uint16_t color)
{
    if(x>=LCD_W || y>=LCD_H) return;
    LCD_SetWindow(x,y,x,y);
    LCD_WriteData(color>>8);
    LCD_WriteData(color&0xFF);
}

//画线
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;
	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1;
	uRow=x1;//画线起点坐标
	uCol=y1;
	if(delta_x>0)incx=1; //设置单步方向 
	else if (delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if (delta_y==0)incy=0;//水平线 
	else {incy=-1;delta_y=-delta_y;}
	if(delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y;
	for(t=0;t<distance+1;t++)
	{
		LCD_DrawPoint(uRow,uCol,color);//画点
		xerr+=delta_x;
		yerr+=delta_y;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}


//画矩形
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color)
{
	LCD_DrawLine(x1,y1,x2,y1,color);
	LCD_DrawLine(x1,y1,x1,y2,color);
	LCD_DrawLine(x1,y2,x2,y2,color);
	LCD_DrawLine(x2,y1,x2,y2,color);
}
//画圆形
void LCD_DrawCircle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color)
{
	int a,b;
	a=0;b=r;	  
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a,color);             //3           
		LCD_DrawPoint(x0+b,y0-a,color);             //0           
		LCD_DrawPoint(x0-a,y0+b,color);             //1                
		LCD_DrawPoint(x0-a,y0-b,color);             //2             
		LCD_DrawPoint(x0+b,y0+a,color);             //4               
		LCD_DrawPoint(x0+a,y0-b,color);             //5
		LCD_DrawPoint(x0+a,y0+b,color);             //6 
		LCD_DrawPoint(x0-b,y0+a,color);             //7
		a++;
		if((a*a+b*b)>(r*r))//判断要画的点是否过远
		{
			b--;
		}
	}
}

//显示单个字符；参数：x,y显示坐标，num 要显示的字符，fc 字的颜色，bc 字的背景色，sizey 字号，mode:  0非叠加模式  1叠加模式
void LCD_ShowChar(uint16_t x, uint16_t y, uint8_t num, uint16_t fc,uint16_t bc, uint8_t sizey, uint8_t mode)
{
	uint8_t temp,sizex,t,m=0,ch=num;
	uint16_t i,TypefaceNum;//一个字符所占字节大小
	uint16_t x0=x;
	sizex=sizey/2;
	if(x+sizex>LCD_W || y+sizey>LCD_H) return;
	TypefaceNum=(sizex/8+((sizex%8)?1:0))*sizey;
	num=num-' ';    //得到偏移后的值
    LCD_SetWindow(x,y,x+sizex-1,y+sizey-1);
	for(i=0;i<TypefaceNum;i++)
	{
		if(sizey==16)temp=ASCII_0816[num][i];		 //调用8x16字体
		else return;
		for(t=0;t<8;t++)
		{
			if(!mode)//非叠加模式
			{
				if(temp&(0x01<<t))LCD_WriteData16(fc);
				else LCD_WriteData16(bc);
				m++;
				if(m%sizex==0)
				{
					m=0;
					break;
				}
			}
			else//叠加模式
			{
				if(temp&(0x01<<t))LCD_DrawPoint(x,y,fc);//画一个点
				x++;
				if((x-x0)==sizex)
				{
					x=x0;
					y++;
					break;
				}
			}
		}
	}
}

//显示字符串；参数：x,y显示坐标，*p 要显示的字符串，fc 字的颜色，bc 字的背景色，sizey 字号，mode:  0非叠加模式  1叠加模式
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode)
{         
	uint32_t len=0; uint16_t k; uint8_t tmp[3]="";//没显示可能是没有对应字模
	len = strlen((const char*)p);
	if(x+sizey>LCD_W || y+sizey>LCD_H) return;
	for(k=0;k<len;k++)
	{
		if(p[k]<128)//en
		{
			LCD_ShowChar(x,y,p[k],fc,bc,sizey,mode);
			x+=sizey/2;
		}
		else //cn
		{
			tmp[0]=p[k];tmp[1]=p[k+1];tmp[2]=0;
			//
			x+=sizey;
			k++;
		}
	}
}

//显示图片；参数：x,y显示坐标，宽度，高度，图片
void LCD_ShowImage(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint8_t *image)
{
	uint16_t i,j;
	uint32_t k=0;
	LCD_SetWindow(x,y,x+height-1,y+width-1);
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			LCD_WriteData(image[k*2]);
			LCD_WriteData(image[k*2+1]);
			k++;
		}
	}			
}




#endif
