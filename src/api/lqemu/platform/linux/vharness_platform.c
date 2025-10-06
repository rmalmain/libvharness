#include <stddef.h>
#include <unistd.h>

void vharness_platform_init(volatile char* input, size_t max_len) {
    // make sure the input is really allocated
    for (size_t i = 0; i < max_len; i += getpagesize()) {
        input[i] = 0;
    }
}
