#include "vharness_api.h"
#include "lqemu.h"

void vharness_api_vprintf(const char *fmt, va_list ap) {
    vlqprintf(fmt, ap);
}

void vharness_api_trace_vaddr(void* addr, size_t len)
{
    libafl_qemu_trace_vaddr_size((vword) addr, len);
}
