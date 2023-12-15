

#include "stm32f10x.h"                  // Device header
#include <Delay.h>


#include<absacc.h>
#include<intrins.h>
#include<string.h>
#include<font.h>



//#define USE_LANDSCAPE//���Գ���������л��������뿪���˺꣬����������



//---------------------------Һ��������˵��-------------------------------------//
//����ǰ��ο�Һ����˵�����10ҳ���Ŷ���
sbit bl        =P3^5;//��ģ��BL���ţ�������Բ���IO���ƻ���PWM���ƣ�Ҳ����ֱ�ӽӵ��ߵ�ƽ����
sbit scl       =P3^0;//��ģ��CLK����,������Pin9_SCL
sbit sda       =P3^1;//��ģ��DIN/MOSI���ţ�������Pin8_SDA
sbit rs        =P3^3;//��ģ��D/C���ţ�������Pin7_A0
sbit cs        =P3^4;//��ģ��CE���ţ�������Pin12_CS
sbit reset     =P3^2;//��ģ��RST���ţ�������Pin6_RES
//---------------------------End ofҺ��������---------------------------------//

//���峣����ɫ
#define RED  		0xf800
#define GREEN		0x07e0
#define BLUE 		0x001f
#define WHITE		0xffff
#define BLACK		0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   
#define GRAY1   0x8410      	
#define GRAY2   0x4208 
  


code  typFNT_GBK16 hz16[];

//��SPI���ߴ���һ��8λ����
void  SPI_WriteData(uint8_t Data)
{
	unsigned char i=0;
	for(i=8;i>0;i--)
	{
		if(Data&0x80)	
		sda=1; //�������
		else sda=0;
		scl=0;
		scl=1;
		Data<<=1;
	}
}
//��Һ����дһ��8λָ��
void  Lcd_WriteIndex(uint8_t Data)
{
		
		cs=0;
		rs=0;
		SPI_WriteData(Data); 		
		cs=1;
}
//��Һ����дһ��8λ����
void  Lcd_WriteData(uint8_t Data)
{	
		unsigned char i=0;
		cs=0;
		rs=1;
		SPI_WriteData(Data); 	
		cs=1;
}
//��Һ����дһ��16λ����
void  LCD_WriteData_16Bit(unsigned int Data)
{
	unsigned char i=0;
	cs=0;
	rs=1;
	SPI_WriteData(Data>>8); 	//д���8λ����
	SPI_WriteData(Data); 			//д���8λ����
	cs=1;

}

void Reset()
{
    reset=0;
    Delay_ms(100);
    reset=1;
    Delay_ms(100);
}
//////////////////////////////////////////////////////////////////////////////////////////////
//Һ������ʼ��
void lcd_initial()
{	Reset();//Reset before LCD Init.
	Lcd_WriteIndex(0x11);//Sleep exit 
	Delay_ms (120);
	Lcd_WriteIndex(0x21); 
Lcd_WriteIndex(0x21); 

Lcd_WriteIndex(0xB1); 
Lcd_WriteData(0x05);
Lcd_WriteData(0x3A);
Lcd_WriteData(0x3A);

Lcd_WriteIndex(0xB2);
Lcd_WriteData(0x05);
Lcd_WriteData(0x3A);
Lcd_WriteData(0x3A);

Lcd_WriteIndex(0xB3); 
Lcd_WriteData(0x05);  
Lcd_WriteData(0x3A);
Lcd_WriteData(0x3A);
Lcd_WriteData(0x05);
Lcd_WriteData(0x3A);
Lcd_WriteData(0x3A);

Lcd_WriteIndex(0xB4);
Lcd_WriteData(0x03);

Lcd_WriteIndex(0xC0);
Lcd_WriteData(0x62);
Lcd_WriteData(0x02);
Lcd_WriteData(0x04);

Lcd_WriteIndex(0xC1);
Lcd_WriteData(0xC0);

Lcd_WriteIndex(0xC2);
Lcd_WriteData(0x0D);
Lcd_WriteData(0x00);

Lcd_WriteIndex(0xC3);
Lcd_WriteData(0x8D);
Lcd_WriteData(0x6A);   

Lcd_WriteIndex(0xC4);
Lcd_WriteData(0x8D); 
Lcd_WriteData(0xEE); 

Lcd_WriteIndex(0xC5);  /*VCOM*/
Lcd_WriteData(0x0E);    

Lcd_WriteIndex(0xE0);
Lcd_WriteData(0x10);
Lcd_WriteData(0x0E);
Lcd_WriteData(0x02);
Lcd_WriteData(0x03);
Lcd_WriteData(0x0E);
Lcd_WriteData(0x07);
Lcd_WriteData(0x02);
Lcd_WriteData(0x07);
Lcd_WriteData(0x0A);
Lcd_WriteData(0x12);
Lcd_WriteData(0x27);
Lcd_WriteData(0x37);
Lcd_WriteData(0x00);
Lcd_WriteData(0x0D);
Lcd_WriteData(0x0E);
Lcd_WriteData(0x10);

Lcd_WriteIndex(0xE1);
Lcd_WriteData(0x10);
Lcd_WriteData(0x0E);
Lcd_WriteData(0x03);
Lcd_WriteData(0x03);
Lcd_WriteData(0x0F);
Lcd_WriteData(0x06);
Lcd_WriteData(0x02);
Lcd_WriteData(0x08);
Lcd_WriteData(0x0A);
Lcd_WriteData(0x13);
Lcd_WriteData(0x26);
Lcd_WriteData(0x36);
Lcd_WriteData(0x00);
Lcd_WriteData(0x0D);
Lcd_WriteData(0x0E);
Lcd_WriteData(0x10);

Lcd_WriteIndex(0x3A); 
Lcd_WriteData(0x05);

Lcd_WriteIndex(0x36);
Lcd_WriteData(0xC8);

Lcd_WriteIndex(0x29); 


}


/*************************************************
��������LCD_Set_Region
���ܣ�����lcd��ʾ�����ڴ�����д�������Զ�����
��ڲ�����xy�����յ�
����ֵ����
*************************************************/
void Lcd_SetRegion(unsigned int x_start,unsigned int y_start,unsigned int x_end,unsigned int y_end)
{	

	Lcd_WriteIndex(0x2a);
	Lcd_WriteData(0x00);
	Lcd_WriteData(x_start+0x1A);
	Lcd_WriteData(0x00);
	Lcd_WriteData(x_end+0x1A);

	Lcd_WriteIndex(0x2b);
	Lcd_WriteData(0x00);
	Lcd_WriteData(y_start+1);
	Lcd_WriteData(0x00);
	Lcd_WriteData(y_end+1);	
	Lcd_WriteIndex(0x2c);
}


void PutPixel(uint16_t x_start,uint16_t y_start,uint16_t color)
{
	Lcd_SetRegion(x_start,y_start,x_start+1,y_start+1);
	LCD_WriteData_16Bit(color);
	
}



void dsp_single_colour(int color)
{
 	uint8_t i,j;
	Lcd_SetRegion(0,0,80-1,160-1);
 	for (i=0;i<160;i++)
    	for (j=0;j<80;j++)
        	LCD_WriteData_16Bit(color);
}

//�������ô��ڷ�������ֿ����ݣ����Gui_DrawFont_GBK16������
void Fast_DrawFont_GBK16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s)
{
	unsigned char i,j;
	unsigned short k;
	uint16_t HZnum;
	HZnum=sizeof(hz16)/sizeof(typFNT_GBK16);
	while(*s) 
	{	
		if((*s) >= 128) 
		{		
			for (k=0;k<HZnum;k++) 
			{
			  if ((hz16[k].Index[0]==*(s))&&(hz16[k].Index[1]==*(s+1)))
			  { 	Lcd_SetRegion(x,y,x+16-1,y+16-1);
				    for(i=0;i<16*2;i++)
				    {
						for(j=0;j<8;j++)
				    	{
							if(hz16[k].Msk[i]&(0x80>>j))	LCD_WriteData_16Bit(fc);
							else 
							{
							if (fc!=bc) LCD_WriteData_16Bit(bc);
							}
						}
					}
					
					
				}
			}
		s+=2;x+=16;
		}
			
		
		else
		s+=1; 
		
	}
}
//�˷�����溺�ֽ���
void Gui_DrawFont_GBK16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s)
{
	unsigned char i,j;
	unsigned short k,x0;
	x0=x;

	while(*s) 
	{	
		if((*s) >= 128) 
		{		
			for (k=0;k<hz16_num;k++) 
			{
			  if ((hz16[k].Index[0]==*(s))&&(hz16[k].Index[1]==*(s+1)))
			  { 
				    for(i=0;i<16;i++)
				    {
						for(j=0;j<8;j++) 
							{
						    	if(hz16[k].Msk[i*2]&(0x80>>j))	PutPixel(x+j,y+i,fc);
								else {
									if (fc!=bc) PutPixel(x+j,y+i,bc);
								}
							}
						for(j=0;j<8;j++) 
							{
						    	if(hz16[k].Msk[i*2+1]&(0x80>>j))	PutPixel(x+j+8,y+i,fc);
								else 
								{
									if (fc!=bc) PutPixel(x+j+8,y+i,bc);
								}
							}
				    }
				}
			  }
			s+=2;x+=16;
		}
		else
		s+=1; 
		
	}
}

void Font_Test(void)
{//������ʾ���Խ��ݳ����ӻ�ӭ����Ϊרҵ����ע
	dsp_single_colour(WHITE);
	Fast_DrawFont_GBK16(8,10,BLUE,YELLOW,	"���Ĳ���");
	Fast_DrawFont_GBK16(0,30,RED,WHITE,	"���ݳ�����");
	Fast_DrawFont_GBK16(16,50,BLUE,WHITE,	"��ӭ��");
	Fast_DrawFont_GBK16(8,70,WHITE,BLUE, 	"��Ϊרע");
	Fast_DrawFont_GBK16(8,90,WHITE,BLUE,	"����רҵ");

	Delay_ms(1800);	
}
main()
{
	lcd_initial();
	bl=1;
  while(1)
  {
	Font_Test();
    Delay_ms(3500);	
    }
 }






