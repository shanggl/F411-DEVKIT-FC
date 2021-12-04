
#include "lcd.h"



/**************延时函数*****************/

void Delay_5us()
{
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
	_nop_();_nop_();_nop_();_nop_();
}
void Delay_ms(u16 t)	
{						
	u16 i,j;				
	for(i=t;i>0;i--)
	for(j=121;j>0;j--);						
}




/***************等待LCD使能****************/
void Wait_For_Enable(void)	
{					
	Data_Port=0xff;		
	LCD_RS=0;
	LCD_RW=1;
	_nop_();
	LCD_EN=1;
	_nop_();
	_nop_();
	while(Data_Port&0x80);	
	LCD_EN=0;				
}					
/**************写LCD命令函数*****************/
void Write_Command_LCD(u8 CMD,u8 Attribc)
{					
	if(Attribc)Wait_For_Enable();	
	LCD_RS=0;
	LCD_RW=0;
	_nop_();
	Data_Port=CMD;
	_nop_();	
	LCD_EN=1;
	_nop_();
	_nop_();
	LCD_EN=0;
}					
/**************写LCD数据寄存器*****************/
void Write_Data_LCD(u8 dataW)
{					
	Wait_For_Enable();		
	LCD_RS=1;
	LCD_RW=0;
	_nop_();
	Data_Port=dataW;
	_nop_();	
	LCD_EN=1;
	_nop_();
	_nop_();
	LCD_EN=0;
}		
/****************初始化LCD*******************/
void Init_Lcd()				
{			
	Write_Command_LCD(0x38,1);	
	Write_Command_LCD(0x08,1);	
	Write_Command_LCD(0x01,1);	
	Write_Command_LCD(0x06,1);	
	Write_Command_LCD(0x0c,1);
}			
/****************显示一个字符*******************/
void Display_One_Char(u8 X,u8 Y,u8 DData)
{						
	Y&=1;						
	X&=15;						
	if(Y)X|=0x40;					
	X|=0x80;			
	Write_Command_LCD(X,0);		
	Write_Data_LCD(DData);		
}						
















