#include <string.h>
#include <stdarg.h>

#include "vharness.h"

volatile char input_buf[VHARNESS_MAX_INPUT_SIZE];

// placeholder, resolved during final linking
void weak vharness_platform_init(volatile char* input, size_t max_len) {
    UNUSED(input);
    UNUSED(max_len);
}

struct vharness_input vharness_init(void) {
  vharness_platform_init(input_buf, VHARNESS_MAX_INPUT_SIZE);

  return (struct vharness_input) { .input = input_buf,
      .input_size = 0,
      .input_max_size = VHARNESS_MAX_INPUT_SIZE,
      .pos = 0,
  };
}

void vharness_reset(struct vharness_input *vinput, size_t input_size) {
  vinput->pos = 0;
  vinput->input_size = input_size;
}

size_t vharness_remaining_size(struct vharness_input *vinput) {
  return vinput->input_size - vinput->pos;
}

bool vharness_get_buf(struct vharness_input *vinput, void *buf,
                      size_t buf_len) {
  if (vharness_remaining_size(vinput) < buf_len) {
    return false;
  }

  memcpy(buf, (const char *)vinput->input + vinput->pos, buf_len);
  vinput->pos += buf_len;

  return true;
}

bool vharness_get_u64(struct vharness_input *vinput, uint64_t *val) {
  return vharness_get_buf(vinput, val, sizeof(val));
}

bool vharness_get_u32(struct vharness_input *vinput, uint32_t *val) {
  return vharness_get_buf(vinput, val, sizeof(val));
}

bool vharness_get_int(struct vharness_input *vinput, int *val) {
  return vharness_get_buf(vinput, val, sizeof(val));
}

void fmtarg vharness_printf(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);
  vharness_api_vprintf(fmt, args);
  va_end(args);
}
