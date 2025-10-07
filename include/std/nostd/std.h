/// stdbool
#ifndef _STDBOOL_H
#define _STDBOOL_H

#ifndef __cplusplus

#define bool _Bool
#define true 1
#define false 0

#else /* __cplusplus */

/* Supporting <stdbool.h> in C++ is a GCC extension.  */
#define _Bool bool
#define bool bool
#define false false
#define true true

#endif /* __cplusplus */

/* Signal that all the definitions are present.  */
#define __bool_true_false_are_defined 1

#endif /* stdbool.h */

#ifndef VHARNESS_STD_H
#define VHARNESS_STD_H

#include "arch.h"

#if VHARNESS_WORD_SIZE == 64
// TODO:
#elif VHARNESS_WORD_SIZE == 32

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef uint32_t size_t;
typedef unsigned long long uint64_t;
typedef unsigned long uintptr_t;

#else
#error "VHARNESS_WORD_SIZE is undefined."
#endif

typedef __builtin_va_list va_list;
#define va_start(v, l) __builtin_va_start(v, l)
#define va_end(v) __builtin_va_end(v)
#define va_arg(v, T) __builtin_va_arg(v, T)
#define va_copy(d, s) __builtin_va_copy(d, s)

void *memcpy(void *__restrict dest, const void *__restrict src, size_t n);
#endif
