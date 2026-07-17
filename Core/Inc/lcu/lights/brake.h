/*!
 * \file brake.h
 * \date 2026-06-25
 * \authors Mario Mazzara [mario.mazzara@eagletrt.it]
 *
 * \brief A simple api to turn the brake on and off.
 *
 * \details This library provides a way to controll the brake status in an hardware agnostic way
 *
 */
#ifndef BRAKE_H
#define BRAKE_H

/*!
 * \brief           Type definition for the function pointer of the hardware brake update.
 *
 * \param[in]       status: status to set the brake hardware to.
 */
typedef void (*brake_update)(bool status);

/*!
 * \brief       Type definition for the function pointer of the hardware brake update.
 *
 * \retval      true: hardware started successfully.
 * \retval      false: failed to start hardware interface.
 */
typedef bool (*brake_start)(void);

/*!
 * \brief           A structure that encapsulates data and functions required to
 *                  handle brake management.
 */
struct BrakeHandler {
    bool status;         /*!< brake status false= off true= on. */
    brake_update update; /*!< Function pointer to brake hardware implementation. */
};

/*!
 * \brief           Enumeration with all possible return codes of the library.
 */
enum BrakeReturnCode {
    BRAKE_RC_OK,               /*!< Everything is fine. */
    BRAKE_RC_INVALID_ARGUMENT, /*!< Invalid parameter data. */
    BRAKE_RC_NULL_POINTER,     /*!< Unexpected NULL pointer. */
    BRAKE_RC_INIT_ERROR
};

#endif // BRAKE_H
