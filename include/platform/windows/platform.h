#ifndef PLATFORM_COMMON_H
#define PLATFORM_COMMON_H

#include "arch.h"

#if defined(__KERNEL__)
#include <linux/types.h>
#else
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#endif

#if VHARNESS_WORD_SIZE == 64
typedef uint64_t vword;
#elif VHARNESS_WORD_SIZE == 32
typedef uint32_t vword;
#else
#error "VHARNESS_WORD_SIZE is undefined."
#endif

#define LQEMU_CALLING_CONVENTION

#endif
