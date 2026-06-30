/*!
 * \file brake_api.c
 * \date 2026-06-25
 * \authors Mario Mazzara [mario.mazzara@eagletrt.it] 
 *
 * \brief A simple api to turn the brake on and off.
 *
 * \details This library provides a way to controll the brake status in an hardware agnostic way
 *
 */
#include "brake-api.h"
#include "eagletrt.h"
#include <stddef.h>
EAGLETRT_STATIC struct BrakeApiHandler brake_handler;

enum BrakeReturnCode brake_api_init(void (*brake_hw_update)(bool)) {
    if (brake_hw_update == NULL) {
        return BRAKE_RC_NULL_POINTER;
    }
    brake_handler.brake_status = false;
    brake_handler.brake_hw_update = brake_hw_update;
    return BRAKE_RC_OK;
}

bool brake_api_get_status() {
    return brake_handler.brake_status;
}

void brake_api_set_status(bool status) {
    brake_handler.brake_status = status;
    brake_handler.brake_hw_update(status);
}
