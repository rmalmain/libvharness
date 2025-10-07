#include "std.h"

void *memcpy(void *__restrict dest, const void *__restrict src, size_t n) {
  char *csrc = (char *)src;
  char *cdest = (char *)dest;

  for (size_t i = 0; i < n; i++) {
    cdest[i] = csrc[i];
  }

  return 0;
}
