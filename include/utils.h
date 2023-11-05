#include <stdlib.h>

#if CHILLBUFF_PLATFORM_MALLOC_ALT
#pragma message("need override for malloc")
extern void *(*chillbuff_malloc) (size_t size);
#else
#pragma message("using default for malloc")
#define chillbuff_malloc malloc
#endif

#if CHILLBUFF_PLATFORM_CALLOC_ALT
#pragma message("need override for calloc")
extern void *(*chillbuff_calloc) (size_t nmemb, size_t size);
#else
#pragma message("using default for calloc")
#define chillbuff_calloc calloc
#endif

#if CHILLBUFF_PLATFORM_REALLOC_ALT
#pragma message("need override for realloc")
extern void *(*chillbuff_realloc) (void *ptr, size_t size);
#else 
#pragma message("using default for realloc")
#define chillbuff_realloc realloc
#endif
