#ifndef POST_H
#define POST_H

#include <stdint.h>

/*!
 * \brief Possible return codes for POST functions
 */
enum PostReturnCode {
    POST_RC_OK,            /*!< All tests passed*/
    POST_RC_UNINITIALIZED, /*!< A module is uninitialized*/
    POST_RC_NULL_POINTER   /*!< A null pointer is provided*/
};

struct PostInitData {
    void (*brake_hw_update)(bool);
    bool (*brake_hw_start)(void);
};

/*!
 * \brief Run power-on self tests.
 * \param Init Pointer to PostInitData struct containing initialization data.
 *
 * \retval POST_RC_OK if all tests pass
 * \retval POST_RC_UNINITIALIZED if a module is uninitialized
 * \retval POST_RC_NULL_POINTER if a null pointer is provided
 */
enum PostReturnCode post_init(struct PostInitData *Init);

#endif /* ifndef POST_H */
