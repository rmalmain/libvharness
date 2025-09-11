#ifndef LQEMU_HYPERCALLS_H
#define LQEMU_HYPERCALLS_H

#include "defs.h"
#include "platform.h"

#ifdef __cplusplus
extern "C" {
#endif

vword LQEMU_CALLING_CONVENTION _lqemu_custom_insn_call0(vword cmd);
vword LQEMU_CALLING_CONVENTION _lqemu_custom_insn_call1(vword cmd,
                                                         vword arg1);
vword LQEMU_CALLING_CONVENTION _lqemu_custom_insn_call2(vword cmd,
                                                         vword arg1,
                                                         vword arg2);

vword LQEMU_CALLING_CONVENTION _lqemu_backdoor_call0(vword cmd);
vword LQEMU_CALLING_CONVENTION _lqemu_backdoor_call1(vword cmd, vword arg1);
vword LQEMU_CALLING_CONVENTION _lqemu_backdoor_call2(vword cmd, vword arg1,
                                                      vword arg2);

#ifdef __cplusplus
}
#endif

#endif
