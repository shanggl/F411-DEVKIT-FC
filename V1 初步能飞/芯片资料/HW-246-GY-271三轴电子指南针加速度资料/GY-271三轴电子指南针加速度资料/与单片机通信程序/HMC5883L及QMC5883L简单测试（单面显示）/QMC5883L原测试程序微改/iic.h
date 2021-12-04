#ifndef __IIC_H_
#define __IIC_H_

#include "lcd.h"


#define	Slave_Address   0x1a	 //����������IIC�����еĴӵ�ַ  read
                	
sbit	SCL=P1^0;      //IICʱ����
sbit	SDA=P1^1;      //IIC������

void QMC5883_Start();
void QMC5883_Stop();
void QMC5883_SendACK(bit ack);
bit QMC5883_RecvACK();
void QMC5883_SendByte(u8 dat);
u8 QMC5883_RecvByte();
void Single_Write_QMC5883(u8 REG_Address,u8 REG_data);
//u8 Single_Read_QMC5883(u8 REG_Address);
void Multiple_Read_QMC5883(void);
void Init_QMC5883();














#endif

















