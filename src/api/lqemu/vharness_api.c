#include "vharness_api.h"
#include "lqemu.h"

void fmtarg vharness_api_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vlqprintf(fmt, args);
    va_end(args);
}

void vharness_api_trace_vaddr(void* addr, size_t len)
{
    libafl_qemu_trace_vaddr_size((vword) addr, len);
}
