#ifndef _LCD_ST7789_
#define _LCD_ST7789_
#include <stdint.h>
#include "PinFun.h"
#if USE_LCD_ST7789

#define LCD_W 240
#define LCD_H 240


//初始化LCD
void LCD_Init();
//设置窗口区域大小; 参数：起点x1,y1, 对角点x2,y2
void LCD_SetWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
//清屏; 参数：颜色RGB565
void LCD_Clear(uint16_t color);
//画点; 参数：x,y,颜色RGB565
void LCD_DrawPoint(uint16_t x, uint16_t y, uint16_t color);
//填充颜色; 参数：起点x1,y1, 对角点x2,y2，颜色RGB565
void LCD_Fill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
//指定区域填充颜色，X轴渐变色
void LCD_Fill_X(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color1,uint16_t color2);
//指定区域填充颜色，Y轴渐变色
void LCD_Fill_Y(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color1,uint16_t color2);

//画点
void LCD_DrawPoint(uint16_t x, uint16_t y, uint16_t color);
//画线
void LCD_DrawLine(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t color);
//画矩形
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color);
//画圆形
void LCD_DrawCircle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color);

//显示字符串；参数：x,y显示坐标，*p 要显示的字符串，fc 字的颜色，bc 字的背景色，sizey 字号，mode:  0非叠加模式  1叠加模式
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p,uint16_t fc,uint16_t bc,uint8_t sizey,uint8_t mode);



#endif
#endif