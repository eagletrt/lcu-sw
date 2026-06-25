/*!
 * \file brake_api.h
 * \date 2026-06-25
 * \authors Mario Mazzara [mario.mazzara@eagletrt.it] 
 *
 * \brief A simple api to turn the brake on and off.
 *
 * \details This library provides a way to controll the brake status in an hardware agnostic way
 *
 */
#ifndef BRAKE_API_H
#define BRAKE_API_H

/*!
 * \brief           A structure that encapsulates data and functions required to
 *                  handle brake management.
 */
struct brake_api_data {
    bool brake_status;                    /*!< brake status false= off true= on. */
    void (*brake_hw_update)(bool status); /*!< Function pointer to brake hardware implementation. */
};

/*!
 * \brief           Enumeration with all possible return codes of the library.
 */
enum BrakeReturnCode {
    BRAKE_RC_OK,               /*!< Everything is fine. */
    BRAKE_RC_INVALID_ARGUMENT, /*!< Invalid parameter data. */
    BRAKE_RC_NULL_POINTER,     /*!< Unexpected NULL pointer. */
};

/*!
 * \brief           Initialize the brake_data.
 *
 * \param[in]       init_data: pointer to initialization data.
 *
 * \retval          PAL_RC_OK on success, an error otherwise:
 * \retval          PAL_RC_NULL_POINTER if any of the pointer parameters are NULL.
 */
enum BrakeReturnCode brake_api_init(const struct brake_api_data *init_data);

/*!
 * \brief           set brake status.
 *
 * \param[in]       status: false = off true = on.
 *
 */
void brake_api_set_status(bool status);

/*!
 * \brief           get brake status.
 *
 * \retval          false = off 
 * \retval          true = on.
 *
 */
bool brake_api_get_status();
#endif // !BRAKE_API_H
