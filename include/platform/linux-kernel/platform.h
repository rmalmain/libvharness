#ifndef PLATFORM_COMMON_H
#define PLATFORM_COMMON_H

#include "arch.h"

#include <linux/sprintf.h>
#include <linux/stdarg.h>
#include <linux/types.h>

// typedef __builtin_va_list va_list;
// #define va_start(v, l)	__builtin_va_start(v, l)
// #define va_end(v)	__builtin_va_end(v)
// #define va_arg(v, T)	__builtin_va_arg(v, T)
// #define va_copy(d, s)	__builtin_va_copy(d, s)

typedef __u64 uint64_t;

#if VHARNESS_WORD_SIZE == 64
typedef uint64_t vword;
#elif VHARNESS_WORD_SIZE == 32
typedef uint32_t vword;
#else
#error "VHARNESS_WORD_SIZE is undefined."
#endif

#define LQEMU_CALLING_CONVENTION

#define LQEMU_SUPPORT_STDIO

#endif
