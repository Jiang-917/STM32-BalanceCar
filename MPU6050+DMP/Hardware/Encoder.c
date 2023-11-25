#include "stm32f10x.h"                  // Device header
#include "TIM.h"  

void L_Encoder_Init(void)
{
	TIM2_Init();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void R_Encoder_Init(void)
{
	TIM3_Init();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int16_t L_Encoder_Get(void)
{
	int16_t Temp;
	Temp = TIM_GetCounter(TIM2);
	TIM_SetCounter(TIM2, 0);
	return Temp;
}

int16_t R_Encoder_Get(void)
{
	int16_t Temp;
	Temp = TIM_GetCounter(TIM3);
	TIM_SetCounter(TIM3, 0);
	return Temp;
}

//int Read_L_Encoder()
//{
//    	int Encoder_TIM;
//        Encoder_TIM= (short)TIM2 -> CNT;         //Encoder_TIM= (int)((int16_t)(TIM4->CNT));;
//        TIM2 -> CNT=0;
//   	    return Encoder_TIM;
//}

//int Read_R_Encoder()
//{
//    	int Encoder_TIM;
//        Encoder_TIM= (short)TIM3 -> CNT;         //Encoder_TIM= (int)((int16_t)(TIM4->CNT));;
//        TIM3 -> CNT=0;
//   	    return Encoder_TIM;
//}

//void L_speed(void)
//{
//    int encoderNum = 0;
//    float rotateSpeed = 0;

//    encoderNum = Read_L_Encoder();
//    rotateSpeed = (float)encoderNum / (1560 * 0.01); // 这个周期要根据定时器定的时间的改变而改变  目前是10ms读取一次

//}

//void R_speed(void)
//{
//    int encoderNum = 0;
//    float rotateSpeed = 0;

//    encoderNum = Read_R_Encoder();
//    rotateSpeed = (float)encoderNum / (1560 * 0.01); // 这个周期要根据定时器定的时间的改变而改变  目前是10ms读取一次

//}

//void TIM2_IRQHandler(void) 
//{
//    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET) 
//    {
//		L_speed();
//        TIM_ClearITPendingBit(TIM2,TIM_IT_Update);

//    }
//    TIM_ClearITPendingBit(TIM2, TIM_IT_Update); 
//}

//void TIM3_IRQHandler(void) 
//{
//    if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET) 
//    {
//		R_speed();
//        TIM_ClearITPendingBit(TIM3,TIM_IT_Update);

//    }
//    TIM_ClearITPendingBit(TIM3, TIM_IT_Update); 
//}
