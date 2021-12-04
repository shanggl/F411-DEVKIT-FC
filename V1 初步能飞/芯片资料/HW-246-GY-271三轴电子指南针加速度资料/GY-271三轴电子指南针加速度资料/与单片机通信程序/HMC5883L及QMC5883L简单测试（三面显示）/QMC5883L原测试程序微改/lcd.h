#ifndef __LCD_H_
#define __LCD_H_
#include "reg52.h"
#include "intrins.h"

typedef   unsigned char u8;
typedef   unsigned int  u16;

//����˿ڽ��߲�һ����������
#define  Data_Port P2	//LCD1602���ݶ˿�

sbit    LCD_RS=P0^7;   //LCD1602����˿�		
sbit    LCD_RW=P0^6;   //LCD1602����˿�		
sbit    LCD_EN=P0^5;   //LCD1602ʹ�ܶ˿� 




void Delay_5us();
void Delay_ms(u16 t);
//void Conversion(u8 temp_data);
void Wait_For_Enable(void);
void Write_Command_LCD(u8 CMD,u8 Attribc);
void Write_Data_LCD(u8 dataW);
void Init_Lcd();
void Display_One_Char(u8 X,u8 Y,u8 DData);









#endif























