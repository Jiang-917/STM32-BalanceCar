#include "stm32f10x.h"                  // Device header"
#include "OLED.h"
#include "Delay.h"
#include "inv_mpu.h"
#include "Motor.h"
#include "Encoder.h"
#include "TIM.h"


float Pitch,Roll,Yaw;

int main(void)
{
	delay_init();
	OLED_Init();
	MPU6050_DMP_Init();
	
	Motor_Init();
	L_Encoder_Init();
	R_Encoder_Init();
	TIM4_Init();

	L_Motor_SetSpeed(50);
	R_Motor_SetSpeed(51);

	
	while(1)
	{
		MPU6050_DMP_Get_Data(&Pitch,&Roll,&Yaw);
		OLED_ShowSignedNum(1,1,Pitch,3);
		OLED_ShowSignedNum(1,6,Roll,3);
		OLED_ShowSignedNum(1,11,Yaw,3);
		
		OLED_ShowSignedNum(2, 1,L_Speed, 3);
		OLED_ShowSignedNum(2, 8,R_Speed, 3);

	}
}
