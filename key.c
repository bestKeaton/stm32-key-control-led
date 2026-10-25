#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Init_key()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入，未按下：PB0 = 1；按下：PB0=0；
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

uint16_t key_scan()
{
	uint16_t keynum=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0);
		Delay_ms(20);
		keynum=1;
	}
	return keynum;
}
