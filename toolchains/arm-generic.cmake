set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(VHARNESS_PLATFORM generic)

set(triple arm-none-eabi)

set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_C_COMPILER ${triple}-gcc)
set(CMAKE_C_COMPILER_WORKS 1)

set(CMAKE_CXX_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER ${triple}-g++)
set(CMAKE_CXX_COMPILER_WORKS 1)