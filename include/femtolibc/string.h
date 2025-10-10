#ifndef _FEMTOLIBC_STRING_H
#define _FEMTOLIBC_STRING_H

#include <stddef.h>

size_t strlen(const char *s);

void *memcpy(void *__restrict, const void *__restrict, size_t);

#endif