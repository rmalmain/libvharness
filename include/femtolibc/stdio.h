#ifndef _FEMTOLIBC_STDIO_H
#define _FEMTOLIBC_STDIO_H

#include "stddef.h"

int vsnprintf(char *__restrict, size_t, const char *__restrict, __builtin_va_list);

#endif