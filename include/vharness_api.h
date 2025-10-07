/*
 * libvharness unified API
 *
 * the underlying functions are API-specific, and must be implemented for
 * every libvharness-compatible API.
 */

#ifndef VHARNESS_API_H
#define VHARNESS_API_H

#include "compiler_common.h"
#include "platform.h"
#include "std.h"

void fmtarg vharness_api_printf(const char *fmt, ...);
void vharness_api_trace_vaddr(void *addr, size_t len);

#endif
