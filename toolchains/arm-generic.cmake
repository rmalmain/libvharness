set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# vharness options -- must be defined
set(VHARNESS_PLATFORM generic)
set(VHARNESS_FEMTOLIBC OFF) # we rely on the libc provided by the ARM toolchain

set(triple arm-none-eabi)

set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_C_COMPILER ${triple}-gcc)
set(CMAKE_C_COMPILER_WORKS 1)

set(CMAKE_CXX_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER ${triple}-g++)
set(CMAKE_CXX_COMPILER_WORKS 1)
