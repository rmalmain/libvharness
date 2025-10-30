/*
 * libvharness unified API
 *
 * the underlying functions are API-specific, and must be implemented for
 * every libvharness-compatible API.
 */

#ifndef VHARNESS_API_H
#define VHARNESS_API_H

#include <stddef.h>
#include <stdarg.h>

#include "platform.h"
#include "compiler_common.h"

void vharness_api_vprintf(const char *fmt, va_list ap);

void vharness_api_trace_vaddr(void* addr, size_t len);

#endif

