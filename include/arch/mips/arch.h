#ifndef VHARNESS_ARCH_H
#define VHARNESS_ARCH_H

#include "arch_common.h"

#define _Addr int
#define _Int64 long long
#define _Reg int

#define VHARNESS_WORD_SIZE 64

#if _MIPSEL || __MIPSEL || __MIPSEL__
#define __BYTE_ORDER __LITTLE_ENDIAN
#else
#define __BYTE_ORDER __BIG_ENDIAN
#endif

#define __LONG_MAX 0x7fffffffL

#endif
