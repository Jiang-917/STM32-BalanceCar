#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include "Motor.h"
#include "Encoder.h"
#include "TIM.h"

int16_t AX, AY, AZ, GX, GY, GZ;


int main(void)
{
	OLED_Init();
	MPU6050_Init();
	Motor_Init();
	L_Encoder_Init();
	R_Encoder_Init();
	TIM4_Init();

//	L_Motor_SetSpeed(50);
//	R_Motor_SetSpeed(50);
	
	
	while (1)
	{
//		OLED_ShowSignedNum(1, 1,L_Speed, 5);
//		OLED_ShowSignedNum(2, 1,R_Speed, 5);
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);

		OLED_ShowSignedNum(2, 1, AX, 5);
		OLED_ShowSignedNum(3, 1, AY, 5);
		OLED_ShowSignedNum(4, 1, AZ, 5);
		OLED_ShowSignedNum(2, 8, GX, 5);
		OLED_ShowSignedNum(3, 8, GY, 5);
		OLED_ShowSignedNum(4, 8, GZ, 5);

	}
	
}
