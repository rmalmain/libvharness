#ifndef VHARNESS_ARCH_H
#define VHARNESS_ARCH_H

#include "arch_common.h"

#define _Addr long
#define _Int64 long
#define _Reg long

#define VHARNESS_WORD_SIZE 64

#if __AARCH64EB__
#define __BYTE_ORDER __BIG_ENDIAN
#else
#define __BYTE_ORDER __LITTLE_ENDIAN
#endif

#define __LONG_MAX 0x7fffffffffffffffL

#ifndef __cplusplus
typedef unsigned wchar_t;
#endif
typedef unsigned wint_t;

typedef int blksize_t;
typedef unsigned int nlink_t;

typedef float float_t;
typedef double double_t;

typedef struct { long long __ll; long double __ld; } max_align_t;

#endif
