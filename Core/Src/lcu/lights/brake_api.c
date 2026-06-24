#include "brake_api.h"
#include "eagletrt.h"
#include <stddef.h>
EAGLETRT_STATIC struct brake_api_data api_data;

//TODO: use return codes

bool brake_api_init(const struct brake_api_data *init_data) {
    if (init_data == NULL) {
        return false;
    }
    api_data.brake_status = init_data->brake_status;
    api_data.brake_hw_update = init_data->brake_hw_update;
    return true;
}

bool brake_api_get_status() {
    return api_data.brake_status;
}

void brake_api_set_status(bool status) {
    api_data.brake_status = status;
    api_data.brake_hw_update(status);
}
