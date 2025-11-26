#ifndef _FEMTOLIBC_STDIO_H
#define _FEMTOLIBC_STDIO_H

#include "stddef.h"
#include "stdarg.h"

int vsnprintf(char *restrict s, size_t n, const char *restrict fmt, va_list ap);

#endif