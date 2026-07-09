#include <stddef.h>
#include "post.h"
#include "brake-api.h"

enum PostReturnCode post_init(struct PostInitData *init) {
    if (init == NULL) {
        return POST_RC_NULL_POINTER;
    }
    if (brake_api_init(init->brake_hw_update, init->brake_hw_start) != BRAKE_RC_OK) {
        return POST_RC_UNINITIALIZED;
    }
    return POST_RC_OK;
}
