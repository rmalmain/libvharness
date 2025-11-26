#include <string.h>
#include <stdarg.h>
#include "compiler_common.h"

#define MIN(a,b) ((a)<(b) ? (a) : (b))

int vsnprintf(char *restrict s, size_t n, const char *restrict fmt, va_list ap) {
    // TODO: return the fmt string for now...
    UNUSED(ap);

    size_t slen = strlen(fmt);
    size_t written = MIN(slen, n);
    memcpy(s, fmt, written);

    if (written < n) {
        s[written] = '\0';
    }

    return written;
}
