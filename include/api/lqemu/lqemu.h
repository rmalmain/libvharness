/**
 * LibAFL QEMU header file.
 *
 * This file is the header file used to build target harnesses more
 * conveniently. Its main purpose is to generate ready-to-use calls to
 * communicate with the fuzzer.
 */

#ifndef LIBAFL_QEMU_H
#define LIBAFL_QEMU_H

#include "common.h"
#include "defs.h"
#include "hypercalls.h"

#define LIBAFL_STRINGIFY(s) #s
#define XSTRINGIFY(s) LIBAFL_STRINGIFY(s)

#define LQEMU_VERSION_MAJOR 0
#define LQEMU_VERSION_MINOR 1

vword libafl_qemu_start_virt(volatile void *buf_vaddr, vword max_len);

vword libafl_qemu_start_phys(volatile void *buf_paddr, vword max_len);

vword libafl_qemu_input_virt(void *buf_vaddr, vword max_len);

vword libafl_qemu_input_phys(void *buf_paddr, vword max_len);

void libafl_qemu_end(enum LibaflQemuEndStatus status);

void libafl_qemu_save(void);

void libafl_qemu_load(void);

vword libafl_qemu_version(void);

void libafl_qemu_page_current_allow(void);

void libafl_qemu_internal_error(void);

void libafl_qemu_test(void);

void libafl_qemu_trace_vaddr_range(vword start, vword end);

void libafl_qemu_trace_vaddr_size(vword start, vword size);

void libafl_qemu_set_covmap_virt(volatile char *vaddr, vword len,
                                 bool is_physically_contiguous);

void libafl_qemu_set_covmap_phys(volatile char *paddr, vword len);

#ifdef LQEMU_SUPPORT_STDIO
void vlqprintf(const char *fmt, va_list ap);
#endif

// if stdio is not supported, simply prints the fmt string.
void fmtarg lqprintf(const char *fmt, ...);

#endif
