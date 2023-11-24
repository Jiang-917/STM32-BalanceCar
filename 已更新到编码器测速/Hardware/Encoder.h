#ifndef __ENCODER_H
#define __ENCODER_H

void L_Encoder_Init(void);
void R_Encoder_Init(void);
//int Read_L_Encoder();
//int Read_R_Encoder();

int16_t L_Encoder_Get(void);

int16_t R_Encoder_Get(void);


#endif
