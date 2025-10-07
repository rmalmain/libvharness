#ifndef VHARNESS_STD_H
#define VHARNESS_STD_H

#include "arch.h"

#define USE_STD

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#if VHARNESS_WORD_SIZE == 64
typedef uint64_t vword;
#elif VHARNESS_WORD_SIZE == 32
typedef uint32_t vword;
#endif

#endif
