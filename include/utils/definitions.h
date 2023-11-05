#include <stdlib.h>

#ifndef CHILLBUFF_PLATFORM_MALLOC_ALT
/**
 * Set this pre-processor definition to \c 1 if you need to
 * provide custom implementation of malloc
 */
#define CHILLBUFF_PLATFORM_MALLOC_ALT 0
#endif

#ifndef CHILLBUFF_PLATFORM_CALLOC_ALT
/**
 * Set this pre-processor definition to \c 1 if you need to
 * provide custom implementation of calloc
 */
#define CHILLBUFF_PLATFORM_CALLOC_ALT 0
#endif

#ifndef CHILLBUFF_PLATFORM_REALLOC_ALT
/**
 * Set this pre-processor definition to \c 1 if you need to
 * provide custom implementation of realloc
 */
#define CHILLBUFF_PLATFORM_REALLOC_ALT 0
#endif

#if CHILLBUFF_PLATFORM_MALLOC_ALT
extern void *(*chillbuff_malloc) (size_t size);
#else
#define chillbuff_malloc malloc
#endif

#if CHILLBUFF_PLATFORM_CALLOC_ALT
extern void *(*chillbuff_calloc) (size_t nmemb, size_t size);
#else
#define chillbuff_calloc calloc
#endif

#if CHILLBUFF_PLATFORM_REALLOC_ALT
extern void *(*chillbuff_realloc) (void *ptr, size_t size);
#else
#define chillbuff_realloc realloc
#endif
