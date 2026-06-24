#ifndef BRAKE_API_H
#define BRAKE_API_H

//TODO: implement return codes

struct brake_api_data {
    bool brake_status;
    void (*brake_hw_update)(bool status);
};
bool brake_api_init(const struct brake_api_data *init_data);
void brake_api_set_status(bool status);
bool brake_api_get_status();
#endif // !BRAKE_API_H
