#include "lqemu.h"
#include "consts.h"

#ifdef STATIC_CHECKS
STATIC_CHECKS
#endif

#ifdef LQEMU_SUPPORT_STDIO
static char lqprintf_buffer[LQEMU_PRINTF_MAX_SIZE] = {0};
#endif

vnoinline vword libafl_qemu_start_virt(volatile void *buf_vaddr, vword max_len) {
    return _lqemu_custom_insn_call2(LIBAFL_QEMU_COMMAND_START_VIRT,
                                    (vword)buf_vaddr, max_len);
}

vnoinline vword libafl_qemu_start_phys(volatile void *buf_paddr, vword max_len) {
    return _lqemu_custom_insn_call2(LIBAFL_QEMU_COMMAND_START_PHYS,
                                    (vword)buf_paddr, max_len);
}

vnoinline void libafl_qemu_end(enum LibaflQemuEndStatus status) {
    _lqemu_custom_insn_call1(LIBAFL_QEMU_COMMAND_END, status);
}

vnoinline void libafl_qemu_save(void) {
    _lqemu_custom_insn_call0(LIBAFL_QEMU_COMMAND_SAVE);
}

vnoinline void libafl_qemu_load(void) {
    _lqemu_custom_insn_call0(LIBAFL_QEMU_COMMAND_LOAD);
}

vnoinline vword libafl_qemu_version(void) {
    return _lqemu_custom_insn_call2(LIBAFL_QEMU_COMMAND_VERSION,
                                    LQEMU_VERSION_MAJOR, LQEMU_VERSION_MINOR);
}

vnoinline void libafl_qemu_internal_error(void) {
    _lqemu_custom_insn_call0(LIBAFL_QEMU_COMMAND_INTERNAL_ERROR);
}

#ifdef LQEMU_SUPPORT_STDIO
vnoinline void vlqprintf(const char *fmt, va_list ap) {
    int res = vsnprintf(lqprintf_buffer, LQEMU_PRINTF_MAX_SIZE, fmt, ap);

    if (res >= LQEMU_PRINTF_MAX_SIZE) {
        // buffer is not big enough, either recompile the target with more
        // space or print less things
        libafl_qemu_internal_error();
    }

    _lqemu_custom_insn_call2(LIBAFL_QEMU_COMMAND_LQPRINTF,
                             (vword)lqprintf_buffer, res);
}
#else
size_t strlen(const char* s) {
    int i = 0;
    while (*s != '\0') {
        s++;
        i++;
    }

    return i;
}

vnoinline void vlqprintf(const char *fmt, va_list ap) {
    UNUSED(ap);
    _lqemu_custom_insn_call2(LIBAFL_QEMU_COMMAND_LQPRINTF, (vword) fmt, strlen(fmt));
}
#endif

vnoinline void lqprintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vlqprintf(fmt, args);
    va_end(args);
}

vnoinline void libafl_qemu_test(void) {
    _lqemu_custom_insn_call1(LIBAFL_QEMU_COMMAND_TEST, LIBAFL_QEMU_TEST_VALUE);
}

vnoinline void libafl_qemu_trace_vaddr_range(vword start, vword end) {
    _lqemu_custom_insn_call2(LIBAFL_QEMU_COMMAND_VADDR_FILTER_ALLOW, start,
                             end);
}

vnoinline void libafl_qemu_trace_vaddr_size(vword start, vword size) {
    libafl_qemu_trace_vaddr_range(start, start + size);
}

vnoinline void libafl_qemu_set_covmap_virt(volatile char *vaddr, vword len,
                                          bool is_physically_contiguous) {
    struct lqemu_map map = {
        .map_kind = LQEMU_MAP_COV,
        .addr_kind = LQEMU_ADDR_VIRT,
        .addr = (vword)vaddr,
        .len = len,
        .is_physically_contiguous = is_physically_contiguous,
    };

    _lqemu_custom_insn_call1(LIBAFL_QEMU_COMMAND_SET_MAP, (vword)&map);
}

vnoinline void libafl_qemu_set_covmap_phys(volatile char *paddr, vword len) {
    struct lqemu_map map = {
        .map_kind = LQEMU_MAP_COV,
        .addr_kind = LQEMU_ADDR_PHYS,
        .addr = (vword)paddr,
        .len = len,
        .is_physically_contiguous = true,
    };

    _lqemu_custom_insn_call1(LIBAFL_QEMU_COMMAND_SET_MAP, (vword)&map);
}
