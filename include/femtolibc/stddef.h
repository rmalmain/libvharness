#ifndef _FEMTOLIBC_STDDEF_H
#define _FEMTOLIBC_STDDEF_H

#ifdef __GNUC__
typedef __SIZE_TYPE__ size_t;
#else
typedef unsigned int size_t;
#endif

#endif