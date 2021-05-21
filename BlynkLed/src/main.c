#include "stm32f407xx.h"

void delay(void)
{
	int i = 0;
	for (i = 0; i < 5000000; i++);
}
void GPIO_Config(void)
{
	RCC->AHB1ENR |= 0x00000008; //enable clock for GPIOD
	 
	GPIOD->MODER |= 0x55000000;	//pin PD12,13,14,15 as output
	GPIOD->OTYPER &= ~(0x00001000);	//push-pull mode
	GPIOD->OSPEEDR |= 0xFF000000;	//very high speed
	GPIOA->PUPDR &= ~(0xFF000000);	//no pull
}
void Blynk_All(void)
{
	GPIOD->ODR |= 0x0000F000;
	delay();
	GPIOD->ODR &= ~(0x0000F000);
	delay();
}
int main(void)
{
	GPIO_Config();
	while(1)
	{
		Blynk_All();
	}
}
