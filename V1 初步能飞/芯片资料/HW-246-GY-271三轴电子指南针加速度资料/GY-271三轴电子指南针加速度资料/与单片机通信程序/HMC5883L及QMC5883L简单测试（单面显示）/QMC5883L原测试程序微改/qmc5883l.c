#include "reg52.h"
#include "intrins.h"
#include "math.h"
#include "iic.h"
#include "lcd.h"
#include "stdio.h"



u8 ge=0,shi=0,bai=0,qian=0,wan=0;          //显示变量             
u8 BUF[8]=0; 						 //数据缓冲区

//******************************显示在LCD的数据取位********************************//
void Conversion(u16 temp_data)  
{  
    wan=temp_data/10000+0x30 ;
    temp_data=temp_data%10000;   //取余运算
	qian=temp_data/1000+0x30 ;
    temp_data=temp_data%1000;    //取余运算
    bai=temp_data/100+0x30   ;
    temp_data=temp_data%100;     //取余运算
    shi=temp_data/10+0x30    ;
    temp_data=temp_data%10;      //取余运算
    ge=temp_data+0x30; 	
}


void main()
{
//	u16 i;
	int x=0,y=0,z=0;
	double angle=0;	
    Delay_ms(200);
	Init_Lcd();
	Init_QMC5883();
	Delay_ms(300);
	while(1)            
	{ 
		Multiple_Read_QMC5883();      				//连续读取三轴角度数据，存储在BUF中
		//---------显示XY轴
		x=BUF[1] << 8 | BUF[0]; //Combine MSB and LSB of X Data output register  最高有效位
		y=BUF[3] << 8 | BUF[2]; //Combine MSB and LSB of Y Data output register
		z=BUF[5] << 8 | BUF[4]; //Combine MSB and LSB of Z Data output register

		angle= atan2((double)y,(double)x) * (180 / 3.14159265) + 180; //计算角度
		angle*=10;
		Conversion(angle);       //计算角度数据和显示
		Display_One_Char(2,0,'A'); 
		Display_One_Char(3,0,':'); 
		Display_One_Char(4,0,qian); 
		Display_One_Char(5,0,bai); 
		Display_One_Char(6,0,shi); 
		Display_One_Char(7,0,'.'); 
		Display_One_Char(8,0,ge); 
	

		Delay_ms(100);   //延时                     
  }



}




























