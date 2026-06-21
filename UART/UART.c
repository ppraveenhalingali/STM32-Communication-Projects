#define STM32F10X_MD
#include "stm32f10x.h"


void UART_Send(char c)
{
    while(!(USART1->SR & (1<<7)));

    USART1->DR = c;
}



char UART_Receive()
{
    while(!(USART1->SR & (1<<5)));

    return USART1->DR;
}



int main()
{

    // Enable GPIOA + USART1 clock

    RCC->APB2ENR |= (1<<2);
    RCC->APB2ENR |= (1<<14);



    // PA9 TX

    GPIOA->CRH &= ~(0xF<<4);
    GPIOA->CRH |= (0xB<<4);



    // PA10 RX

    GPIOA->CRH &= ~(0xF<<8);
    GPIOA->CRH |= (0x4<<8);



    // Baud rate 9600

    USART1->BRR = 0x341;



    // Enable USART

    USART1->CR1 |= (1<<13);



    // Enable TX

    USART1->CR1 |= (1<<3);



    // Enable RX

    USART1->CR1 |= (1<<2);



    while(1)
    {

        char data;


        data = UART_Receive();


        UART_Send(data);

    }

}
