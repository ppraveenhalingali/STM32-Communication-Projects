#include "stm32f10x.h"


//================ DELAY =================

void delay()
{
    int i;

    for(i=0;i<5000;i++);
}



//================ LCD ===================

#define RS (1<<10)
#define EN (1<<11)



void LCD_Command(unsigned char cmd)
{

    GPIOA->ODR &= ~RS;


    GPIOA->ODR &=0xFFFFFF00;

    GPIOA->ODR |=cmd;


    GPIOA->BSRR=EN;

    delay();

    GPIOA->BRR=EN;

}



void LCD_Data(unsigned char data)
{

    GPIOA->ODR |=RS;


    GPIOA->ODR &=0xFFFFFF00;

    GPIOA->ODR |=data;


    GPIOA->BSRR=EN;

    delay();

    GPIOA->BRR=EN;

}



void LCD_String(char *s)
{

    while(*s)
    {
        LCD_Data(*s++);
    }

}



void LCD_Init()
{

    RCC->APB2ENR |= (1<<2);


    // PA0-PA7

    GPIOA->CRL=0x33333333;


    // PA10 PA11

    GPIOA->CRH &= ~(0xFF00);

    GPIOA->CRH |=0x3300;



    delay();


    LCD_Command(0x38);

    LCD_Command(0x0C);

    LCD_Command(0x01);

}



//================ SOFTWARE I2C =================


#define SDA_HIGH GPIOB->BSRR=(1<<7)

#define SDA_LOW  GPIOB->BRR=(1<<7)


#define SCL_HIGH GPIOB->BSRR=(1<<6)

#define SCL_LOW  GPIOB->BRR=(1<<6)



void I2C_Init()
{

    RCC->APB2ENR |= (1<<3);


    // PB6 PB7 output

    GPIOB->CRL &=0x00FFFFFF;


    GPIOB->CRL |=0x33000000;



    SDA_HIGH;

    SCL_HIGH;

}




void I2C_Start()
{

    SDA_HIGH;

    SCL_HIGH;

    delay();


    SDA_LOW;

    delay();


    SCL_LOW;

}



void I2C_Stop()
{

    SDA_LOW;

    SCL_HIGH;

    delay();


    SDA_HIGH;

}



void I2C_Write(unsigned char data)
{

    int i;


    for(i=0;i<8;i++)
    {

        if(data&0x80)

            SDA_HIGH;

        else

            SDA_LOW;



        SCL_HIGH;

        delay();


        SCL_LOW;



        data<<=1;

    }



    // ACK clock

    SDA_HIGH;


    SCL_HIGH;

    delay();


    SCL_LOW;

}




unsigned char I2C_Read()
{

    unsigned char data=0;

    int i;


    SDA_HIGH;



    for(i=0;i<8;i++)
    {

        SCL_HIGH;

        delay();


        data<<=1;


        if(GPIOB->IDR&(1<<7))

            data|=1;


        SCL_LOW;

    }



    return data;

}




//================ BMP180 =================



unsigned int AC5;

unsigned int AC6;

int MC;

int MD;




int BMP180_Read16(unsigned char reg)
{

    unsigned char msb;

    unsigned char lsb;



    I2C_Start();


    I2C_Write(0xEE);


    I2C_Write(reg);



    I2C_Start();


    I2C_Write(0xEF);



    msb=I2C_Read();

    lsb=I2C_Read();



    I2C_Stop();



    return((msb<<8)|lsb);

}





void BMP180_Init()
{

    AC5=BMP180_Read16(0xB2);


    AC6=BMP180_Read16(0xB4);


    MC=(int)BMP180_Read16(0xBC);


    MD=(int)BMP180_Read16(0xBE);

}




int BMP180_Temperature()
{

    int UT;


    long X1;

    long X2;

    long B5;



    // start temperature conversion


    I2C_Start();


    I2C_Write(0xEE);


    I2C_Write(0xF4);


    I2C_Write(0x2E);



    I2C_Stop();



    delay();



    UT=BMP180_Read16(0xF6);



    X1=(((long)UT-AC6)*AC5)>>15;



    X2=((long)MC<<11)/(X1+MD);



    B5=X1+X2;



    return((B5+8)>>4);

}




//================ MAIN =================



int main()
{

    int temp;



    SystemInit();



    LCD_Init();


    I2C_Init();



    BMP180_Init();



    LCD_String("BMP180 TEMP");



    while(1)

    {


        temp=BMP180_Temperature();



        LCD_Command(0xC0);



        LCD_Data((temp/100)+'0');


        LCD_Data(((temp/10)%10)+'0');


        LCD_Data((temp%10)+'0');



        LCD_String(" C");



        delay();


    }

}
