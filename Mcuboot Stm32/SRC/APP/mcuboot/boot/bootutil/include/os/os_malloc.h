#ifndef H_OS_MALLOC_
#define H_OS_MALLOC_

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void *
os_malloc(size_t size)
{
    return malloc(size);
}

static inline void
os_free(void *ptr)
{
    free(ptr);
}

#ifdef __cplusplus
}
#endif

#endif
