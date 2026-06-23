#include "brake.h"
#include "tim.h"

void brake_Update(bool actuated) {
    if (actuated) {
        // Duty cycle 100%: CCR >= ARR (ARR = 100-1)
        __HAL_TIM_SET_COMPARE(&htim14, TIM_CHANNEL_1, 100);
    } else {
        // Duty cycle 0%: CCR = 0
        __HAL_TIM_SET_COMPARE(&htim14, TIM_CHANNEL_1, 0); //this function is void idk how to check if everything went correctly
    }
}

bool brake_init() {
    HAL_StatusTypeDef status = HAL_TIM_PWM_Start(&htim14, TIM_CHANNEL_1);
    if (status != HAL_OK) {
        return false;
    }
    return true;
}
