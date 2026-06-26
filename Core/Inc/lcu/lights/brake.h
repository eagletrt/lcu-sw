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
 * \brief           A structure that encapsulates data and functions required to
 *                  handle brake management.
 */
struct BrakeApiHandler {
    bool brake_status;                    /*!< brake status false= off true= on. */
    void (*brake_hw_update)(bool status); /*!< Function pointer to brake hardware implementation. */
};

/*!
 * \brief           Enumeration with all possible return codes of the library.
 */
enum BrakeReturnCode {
    BRAKE_RC_OK,               /*!< Everything is fine. */
    BRAKE_RC_INVALID_ARGUMENT, /*!< Invalid parameter data. */
    BRAKE_RC_NULL_POINTER      /*!< Unexpected NULL pointer. */
};
#endif // !BRAKE_H
