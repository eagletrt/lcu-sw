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

#include <stddef.h>
#include "eagletrt.h"

EAGLETRT_STATIC struct BrakeHandler brake_handler;

enum BrakeReturnCode brake_api_init(brake_update update) {
    if (update == NULL) {
        return BRAKE_RC_NULL_POINTER;
    }
    brake_handler.status = false;
    brake_handler.update = update;
    return BRAKE_RC_OK;
}

bool brake_api_get_status() {
    return brake_handler.status;
}

void brake_api_set_status(bool status) {
    brake_handler.status = status;
    brake_handler.update(status);
}
