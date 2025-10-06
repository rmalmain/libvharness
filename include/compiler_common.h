#ifndef LQEMU_COMPILER_COMMON_H
#define LQEMU_COMPILER_COMMON_H

#include "platform.h"

#define UNUSED(x) (void)(x)

#if defined(noinline)
#define vnoinline noinline
#else
#define vnoinline __attribute__((noinline))
#endif

#define fmtarg __attribute__((format(printf, 1, 2)))

#define weak __attribute__((weak))

#if __STDC_VERSION__ >= 201112L
#define STATIC_CHECKS                                                         \
  _Static_assert(sizeof(void *) <= sizeof(vword),                             \
                 "pointer type should not be larger and libafl_word");
#endif

#endif
