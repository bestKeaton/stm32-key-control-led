#include "stm32f10x.h"   // Device header
#include "Delay.h"
#include "led.h"
#include "key.h"
uint16_t keynum;
uint8_t led_state = 0;
int main()
{
	Init_led();
	Init_key();
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	while(1)
	{
		keynum=key_scan();
		if(keynum==1)
		{
		led_state = !led_state;
		if(led_state){LED_ON();}
		else{LED_OFF();}
		}
	}
}
	
