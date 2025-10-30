#ifndef  _FEMTOLIBC_STDARG_H
#define  _FEMTOLIBC_STDARG_H

#include "alltypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#define va_start(v,l)   __builtin_va_start(v,l)
#define va_end(v)       __builtin_va_end(v)
#define va_arg(v,l)     __builtin_va_arg(v,l)
#define va_copy(d,s)    __builtin_va_copy(d,s)

#ifdef __cplusplus
}
#endif

#endif