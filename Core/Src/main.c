#include "stm32f4xx.h"



//AHB1 - PG13(Green) or PG14(Red)

//set bit0 in RCC_AHB1ENR to 1 // 0b 0000 0000 0000 0000 0000 0000 0000 0001
#define GPIOA_EN (1<<0)

//set bit10 to 1 and bit11 to 0 in GPIOA_MODER
#define MODER_5_OUT (1<<10) // 0b 0000 0000 0000 0000 0000 0100 0000 0000


//write 1 to GPIOA_ODR bit 13 to set PG13 on an write zero to shut it down.
#define ODR_5_SET (1<<13)
#define ODR_5_RESET (0<<13)

#define LED_PIN (1<<13)

int main(void)
{

	RCC->AHB1ENR |= GPIOA_EN;

	GPIOA->MODER |= MODER_5_OUT;

	while(1){

		for(int i=0;i<900000;i++)
		{

		GPIO->ODR ^= ODR_5_SET;

		}

	}
}
