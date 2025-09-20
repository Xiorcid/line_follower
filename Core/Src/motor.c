#include "motor.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

void M_Init(void){
    HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, GPIO_PIN_RESET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, GPIO_PIN_SET);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

    TIM1->CCR1 = 0;
    TIM1->CCR2 = 0;
    TIM2->CCR1 = 0;
    TIM2->CCR2 = 0;
}

void M_Disable(void){
    HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, GPIO_PIN_RESET);
}

void M_Enable(void){
    HAL_GPIO_WritePin(nSleep_GPIO_Port, nSleep_Pin, GPIO_PIN_SET);
}

void M_SetSpeed(uint16_t spd_a, uint16_t spd_b, bool dir_a, bool dir_b){
    TIM1->CCR1 = spd_a;
    TIM1->CCR2 = spd_a;
    TIM2->CCR1 = spd_b;
    TIM2->CCR2 = spd_b;

    if(dir_a == BACKWARD){
        TIM1->CCR1 = 799;
    }else{
        TIM1->CCR2 = 799;
    }
    
    if(dir_b == BACKWARD){
        TIM2->CCR1 = 799;
    }else{
        TIM2->CCR2 = 799;
    }
}