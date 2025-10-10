#ifndef VHARNESS_ARCH_H
#define VHARNESS_ARCH_H

#include "arch_common.h"

#define VHARNESS_WORD_SIZE 32

#if __ARMEB__
#define __BYTE_ORDER __BIG_ENDIAN
#else
#define __BYTE_ORDER __LITTLE_ENDIAN
#endif

#define __LONG_MAX 0x7fffffffL

#endif
